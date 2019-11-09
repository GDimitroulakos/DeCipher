#include "CD_HLIRSyntaxElements.h"
static int graphviz_cluster_counter=0;


void CDHLIRSyntaxElement::DEBUG_TraceOnTraversal(){
#ifdef DEBUG_HLIR 
	cout << endl << g_DLHLIRtypeidentifier[m_Descriptor->m_HLIRSyntaxElementType]
	<< m_Descriptor->m_HLIRObjectSerialNumber;
#endif	
}
void CDHLIRSyntaxElement::HLIRGraphContextEmmiter(){
int i,sz= m_Context.size();
int graviz_cluster;
list<CDHLIRSyntaxElement *>::iterator it;

	// Iterate over the HLIR object contexts
	for ( i =0; i<sz; i++ ){
		if ( !m_Context[i]->empty() ){
			graviz_cluster =graphviz_cluster_counter++;
			*ms_outfile << endl << "subgraph cluster" << graviz_cluster << " {"
				<< endl << "node [style=filled,color=white];"
				<< endl << "style=filled;"
				<< endl << "color=lightgrey;"
				// subgraph header ( same as this element ) 
				<< endl << "label = \"" << g_DLHLIRcontextidentifier[MapIndextoContext(i)] << "\";"; 
			for ( it = m_Context[i]->begin(); it != m_Context[i]->end(); it ++){
				// subgraph nodes ( descendants of this elements )
				*ms_outfile << endl << ((*it)->GetHLIRElementGraphvizString())
					<<";";		
			}				
			*ms_outfile << endl <<"}";		
		}
	}	
#ifdef DEBUG_HLIRGRAPH_EMMITER
	for ( i =0; i<sz; i++ ){
		if ( !m_Context[i]->empty() ){			
			cout << endl << "subgraph cluster" << graviz_cluster << " {"
				<< endl << "node [style=filled,color=white];"
				<< endl << "style=filled;"
				<< endl << "color=lightgrey;"
				<< endl << "label = \"" << g_DLHLIRcontextidentifier[MapIndextoContext(i)] << "\";";
			for ( it = m_Context[i]->begin(); it != m_Context[i]->end(); it ++){
				cout << endl << (*it)->GetHLIRElementGraphvizString()
					<<";";		
			}				
			cout << endl <<"}";		
		}
	}
#endif	
}
void CDHLIRSyntaxElement::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
int i, sz=m_Context.size();
list<CDHLIRSyntaxElement *>::iterator it;
const char *strparent;
const char *strchild;
#ifdef DEBUG_HLIR
	DEBUG_TraceOnTraversal();
#endif	
	HLIRGraphContextEmmiter();	
	if ( parent != NULL ){
		strparent= parent->GetHLIRElementGraphvizString();
		strchild = GetHLIRElementGraphvizString();
		*ms_outfile << endl << strparent
			<< " -> " 
			<< strchild
			<< ";";
	}	
#ifdef DEBUG_HLIRGRAPH_EMMITER
	if ( parent != NULL ){
		cout << endl << parent->GetHLIRElementGraphvizString()
			<< " -> " 
			<< GetHLIRElementGraphvizString()
			<< ";";
	}
#endif

	for ( i = 0; i< sz; i++ ){		
		for ( it = m_Context[i]->begin(); it != m_Context[i]->end(); it ++){
			(*it)->HLIRGraphEmmiter(this);
		}
	}
}
void CDHLIR_Expression::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CDHLIR_Statement::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CDHLIR_ROOT::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	*ms_outfile << "digraph G {\n";
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
	*ms_outfile << endl <<"}";
}
void CDE_HLIRIDENTIFIER::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CDE_HLIRCONSTANT::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIRTranslationUnit::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIRFunctionDefinition::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CDS_HLIRExressionStatement::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CS_HLIRCompoundStatement::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}


// ========================================================================
// ========================================================================
// ========================================================================
void CD_HLIRDeclaration::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIRTypeQualifier::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIRTypeSpecifiers::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIRDeclarator::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIRTypename::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIREnumerator::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CD_HLIRInitializer::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}

// ========================================================================
// ========================================================================
// ========================================================================
void CT_HLIRVoidType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRIntegerType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRFloatingType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRCharacterType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIREnumeratedType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRArrayType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRStructureType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRUnionType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRFunctionType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}
void CT_HLIRPointerType::HLIRGraphEmmiter(CDHLIRSyntaxElement *parent){
	CDHLIRSyntaxElement::HLIRGraphEmmiter(parent);
}