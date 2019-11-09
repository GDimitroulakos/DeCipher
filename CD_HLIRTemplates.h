/* *********************************************************************************** */
/* Title :							      */
/* File :CD_HLIRTemplates.h																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* CoAuthor: Christakis Lezos																  */
/* Creation Date: 12/3/2012		*/
/* *********************************************************************************** */
#ifndef DLHLIR_TEMPLATES_
#define DLHLIR_TEMPLATES_
#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

template <typename T,typename G>
class DLTHLIRContainer{
public:
	// CONSTRUCTION / DESTRUCTION
	DLTHLIRContainer(T* parent, G* generator, unsigned int contexts);
	DLTHLIRContainer(unsigned int contexts);
public:
	typedef T* item;
public:
	// ACCESSORS
	item tbegin(unsigned int);
	bool ttend(unsigned int);
	item tnext(unsigned int);
	T *GetContextElement(int ctx,unsigned int index =0 );
			
	// MODIFIERS
	void push_back(int,T*);
	void SetParent(T* p);
	void SetGenerator(G *g);	
public:
	vector<list<T* > *> m_Context;
	T *m_parent;    // The predecessor in the tree structure
	G *m_generator; // The object that stimulates this object's construction  
protected:
	struct iteration_state{
		bool m_proper_traversal;
		bool m_endof_list;
		typename list<T *>::iterator m_it; 	
	} *m_current_iteration_state;
	stack<struct iteration_state *> m_Iteration_State_Stack;	
};

template <typename T,typename G>
DLTHLIRContainer<T,G>::DLTHLIRContainer(unsigned int contexts)
:m_Context(contexts,NULL){
unsigned int i;
    m_current_iteration_state = new struct iteration_state;
    m_Iteration_State_Stack.push(m_current_iteration_state);
	m_current_iteration_state->m_proper_traversal = false;
	m_current_iteration_state->m_endof_list = false;
	m_parent = NULL;
	m_generator = NULL;	
	
	for ( i= 0; i<contexts ;i++){
		m_Context[i] = new list<T *>;
	}
}
template <typename T,typename G>
DLTHLIRContainer<T,G>::DLTHLIRContainer(T* parent, G* generator, unsigned int contexts)
: m_Context(contexts,NULL) {
	G *curnode;
	T *newemmiter;
	unsigned int i;
	m_proper_traversal = false;
	m_endof_list = false;
	m_parent = parent;
	m_generator = generator;	

	// The following loop expects to instantiate the contents of a mirror object
	// 
	for ( i= 0; i<contexts ;i++){
		m_Context[i] = new list<T *>;
		for ( curnode = m_generator->tbegin(i);
			!m_generator->ttend(i) ;
			curnode = m_generator->tnext(i) ){
				newemmiter = new T(curnode,(T *)this);
				m_Context[i]->push_back(newemmiter);	  	 
		}
	}	
}
template <typename T,typename G>
void DLTHLIRContainer<T,G>::SetParent(T* p){
	if ( m_parent != NULL ){
		cout << endl << "Warning !!!! Parent already defined.";
	}
	m_parent = p;
}
template <typename T,typename G>
void DLTHLIRContainer<T,G>::push_back(int c, T *obj){
	m_Context[c].push_back(obj);
}
template <typename T,typename G>
typename DLTHLIRContainer<T,G>::item DLTHLIRContainer<T,G>::tbegin(unsigned int c){
	if ( c < m_Context.size() ){
		if ( m_Context[c]->empty() ){
			m_current_iteration_state = new struct iteration_state;			
			m_Iteration_State_Stack.push(m_current_iteration_state);	
			m_current_iteration_state->m_proper_traversal = false;
			m_current_iteration_state->m_endof_list = true;
			return NULL;
		}
		else{
			m_current_iteration_state = new struct iteration_state;			
			m_Iteration_State_Stack.push(m_current_iteration_state);			
			m_current_iteration_state->m_proper_traversal = true;
			m_current_iteration_state->m_endof_list = false;
			m_current_iteration_state->m_it = m_Context[c]->begin();
			return *m_current_iteration_state->m_it;
		}	
	}
	else{
		cout << endl << "Error!!! Out of bounds context";
		exit(1);
	}
}
template <typename T,typename G>
typename DLTHLIRContainer<T,G>::item DLTHLIRContainer<T,G>::tnext(unsigned int c){
	if ( c < m_Context.size() ){
		if ( m_Context[c]->empty() ){
			return NULL;
		}
		else{
			if ( ++m_current_iteration_state->m_it != m_Context[c]->end() &&
				 m_current_iteration_state->m_proper_traversal){
				return *m_current_iteration_state->m_it;
			}
			else if ( m_current_iteration_state->m_it == m_Context[c]->end() &&
					  m_current_iteration_state->m_proper_traversal){
				m_current_iteration_state->m_endof_list = true;
				m_current_iteration_state->m_proper_traversal = false;
				return NULL;
			}
			else{				
				m_current_iteration_state->m_endof_list = false;
				m_current_iteration_state->m_proper_traversal = false;				
				return NULL;
			}
		}	
	}
	else{
		cout << endl << "Error!!! Out of bounds context";
		exit(1);
	}
}
template <typename T,typename G>
bool DLTHLIRContainer<T,G>::ttend(unsigned int c){
struct iteration_state *decoying_state;
	decoying_state =  m_Iteration_State_Stack.top();
	if ( decoying_state->m_endof_list ){		
		m_Iteration_State_Stack.pop();
		m_current_iteration_state = m_Iteration_State_Stack.top();
	}
	return decoying_state->m_endof_list;
}
template <typename T,typename G>
T *DLTHLIRContainer<T,G>::GetContextElement(int ctx, 
										  unsigned int index/* =0 */){
list<T *> *arglst;												
list<T *>::iterator it;
unsigned int i;	
	
	if ( ctx == -1 ){
		return NULL;
	}
	if ( m_Context[ctx]->empty() ){
		return NULL;
	}
	else{		
		arglst = m_Context[ctx];
		for ( i=0, it =arglst->begin(); 
			 it !=arglst->end() && i<index; i++,it++){		 
		}
		return (*it);	
	}
}
#endif