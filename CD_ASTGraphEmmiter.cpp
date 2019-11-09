/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\CD_ASTGraphEmmiter.cpp																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
#include "CD_ASTSyntaxElements.h"
void CDASTSyntaxElement::DEBUG_TraceOnGraphizEmmition1(){
#ifdef DEBUG_AST_GRAPHIVIZ_EMMITION
const CTOKEN *tk;
	if ( m_NonTerminalCode == token_ ){
		tk = (CTOKEN *)this;
		if ( tk->m_TerminalCode > TERNARY_CONDITIONAL_ ){
			cout << endl << "Visiting :" << tk->m_tokenstring;
		}
		else{
			cout << endl << "Visiting :" << tokenstringsGraphVizFriently[tk->m_TerminalCode];
		}
	}
	else{
		cout << endl << "Visiting :" << nonterminalstrings[m_NonTerminalCode];
	}
#endif
}
void CDASTSyntaxElement::DEBUG_TraceOnGraphizEmmition2(){
#ifdef DEBUG_AST_GRAPHIVIZ_EMMITION
const CTOKEN *tk;
	if ( m_NonTerminalCode == token_ ){
		tk = (CTOKEN *)this;
		if ( tk->m_TerminalCode > TERNARY_CONDITIONAL_ ){
			cout << endl << "Leaving :" << tk->m_tokenstring;
		}
		else{
			cout << endl << "Leaving :" << tokenstringsGraphVizFriently[tk->m_TerminalCode];
		}
	}
	else{
		cout << endl << "Leaving :" << nonterminalstrings[m_NonTerminalCode];
	}
#endif
}
ostream &operator<<(ostream &ostr, const CDASTSyntaxElement &OBJ){
	ostr << DLnonterminal_strings[OBJ.m_NonTerminalCode] << "_" << OBJ.m_ObjectSerialNumber;
return ostr;
}
ostream &operator<<(ostream &ostr, const CDASTTOKEN &OBJ){
string present_token;
	ostr << "TOKEN_"<< DLterminal_strings[OBJ.m_TerminalCode]<< "_" << OBJ.m_ObjectSerialNumber;
return ostr;
}
void CDASTSyntaxElement::ASTGraphEmmiter(CDASTSyntaxElement *parent){
vector<CDASTSyntaxElement *>::iterator it;
unsigned int i;
	if ( parent != NULL ){
		*m_OutputFiles[DLASTO_ASTDOT] << "   " << *parent << "->" << *this << ";\n";
	}
	for ( i=0; i<m_NumberOfDescendants; i++ ){
		m_Descendants[i]->ASTGraphEmmiter(this);
	}
}

void CDASTTOKEN::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	if ( parent != NULL ){
		*m_OutputFiles[DLASTO_ASTDOT] << "   " << *parent << "->" << *this << ";\n";
	}
	//CDASTSyntaxElement::ASTGraphEmmiter(parent);
}

void CDASTscdeclaration_unit::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTscdeclarations::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTscdeclaration::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTdeclaration_specifiers::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTinit_declarator_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTinit_declarator::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTstorage_class_specifier::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTtype_specifier::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTstruct_or_union_specifier::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTstruct_or_union::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTstruct_declaration_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTstruct_declaration::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTspecifier_qualifier_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTstruct_declarator_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTstruct_declarator::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTenum_specifier::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTenumerator_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTenumerator::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTtype_qualifier::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTdeclarator::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTdirect_declarator::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTpointer::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTtype_qualifier_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTparameter_type_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTparameter_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTparameter_declaration::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTtype_name::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTabstract_declarator::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTdirect_abstract_declarator::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTinitializer::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTinitializer_list::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTqualified_id::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTassignment_expression::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}
void CDASTconstant_expression::ASTGraphEmmiter(CDASTSyntaxElement *parent){
	DEBUG_TraceOnGraphizEmmition1();
	CDASTSyntaxElement::ASTGraphEmmiter(parent);
	DEBUG_TraceOnGraphizEmmition2();
}