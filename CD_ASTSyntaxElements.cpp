/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\CD_ASTSyntaxElements.cpp																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
#include "CD_ASTSyntaxElements.h"
vector<ofstream *> CDASTSyntaxElement::m_OutputFiles(vector<ofstream *>(DLAST_OUTPUTFILES,NULL));
unsigned int CDASTSyntaxElement::m_ObjectSerialNumberCounter = 0;
CDASTSyntaxElement::CDASTSyntaxElement()
:m_Descendants(12),m_ObjectSerialNumber(m_ObjectSerialNumberCounter++){
	m_NumberOfDescendants =0;
	m_NonTerminal_ProductionCode = DLUNITIALIZED;
	m_location = new decipher::location;
	m_location->begin.column = -1;
	m_location->begin.line = -1;
	m_location->end.column = -1;
	m_location->end.line = -1;
	m_HLIRlocation = NULL;
}
CDASTTOKEN::CDASTTOKEN(DLTERMINAL_CODE token,decipher::location *loc,
			DLNONTERMINAL_PRODUCTION_RULE pr,
			char *tokenstr)
:CDASTSyntaxElement(pr,loc){
	m_TerminalCode = token;
	m_NonTerminalCode = DLNT_TERMINAL;
m_tokenstring = strdup(tokenstr);
}
CDASTSyntaxElement::CDASTSyntaxElement(DLNONTERMINAL_PRODUCTION_RULE pr,
decipher::location *loc)
:m_Descendants(12),m_ObjectSerialNumber(m_ObjectSerialNumberCounter++){
	m_NumberOfDescendants =0;
	m_NonTerminal_ProductionCode =  pr;
	m_location = new decipher::location(*loc);
	m_HLIRlocation = new DLLOCATION_HLIR(m_location);
}
ofstream *CDASTSyntaxElement::SetOutputFilename(DLAST_EMMITERS emmiter,string filename){
	m_OutputFiles[emmiter] = new ofstream(filename.c_str());
	return m_OutputFiles[emmiter];
}
CDASTscdeclaration_unit::CDASTscdeclaration_unit(CDASTscdeclarations* scde0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_scdeclaration_unit;
	m_Descendants[0] = scde0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTscdeclaration_unit::~CDASTscdeclaration_unit(){}
CDASTscdeclarations::CDASTscdeclarations(CDASTscdeclaration* scde0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_scdeclarations;
	m_Descendants[0] = scde0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTscdeclarations::CDASTscdeclarations(CDASTTOKEN* TOKE0, CDASTtype_name* type1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_scdeclarations;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = type1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTscdeclarations::CDASTscdeclarations(CDASTscdeclaration* scde0, CDASTscdeclarations* scde1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_scdeclarations;
	m_Descendants[0] = scde0;
	m_Descendants[1] = scde1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTscdeclarations::CDASTscdeclarations(CDASTTOKEN* TOKE0, CDASTtype_name* type1, CDASTscdeclarations* scde2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_scdeclarations;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = type1;
	m_Descendants[2] = scde2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTscdeclarations::~CDASTscdeclarations(){}
CDASTscdeclaration::CDASTscdeclaration(CDASTdeclaration_specifiers* decl0, CDASTTOKEN* TOKE1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_scdeclaration;
	m_Descendants[0] = decl0;
	m_Descendants[1] = TOKE1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTscdeclaration::CDASTscdeclaration(CDASTdeclaration_specifiers* decl0, CDASTinit_declarator_list* init1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_scdeclaration;
	m_Descendants[0] = decl0;
	m_Descendants[1] = init1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTscdeclaration::~CDASTscdeclaration(){}
CDASTdeclaration_specifiers::CDASTdeclaration_specifiers(CDASTstorage_class_specifier* stor0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declaration_specifiers;
	m_Descendants[0] = stor0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclaration_specifiers::CDASTdeclaration_specifiers(CDASTstorage_class_specifier* stor0, CDASTdeclaration_specifiers* decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declaration_specifiers;
	m_Descendants[0] = stor0;
	m_Descendants[1] = decl1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclaration_specifiers::CDASTdeclaration_specifiers(CDASTtype_specifier* type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declaration_specifiers;
	m_Descendants[0] = type0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclaration_specifiers::CDASTdeclaration_specifiers(CDASTtype_specifier* type0, CDASTdeclaration_specifiers* decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declaration_specifiers;
	m_Descendants[0] = type0;
	m_Descendants[1] = decl1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclaration_specifiers::CDASTdeclaration_specifiers(CDASTtype_qualifier* type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declaration_specifiers;
	m_Descendants[0] = type0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclaration_specifiers::CDASTdeclaration_specifiers(CDASTtype_qualifier* type0, CDASTdeclaration_specifiers* decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declaration_specifiers;
	m_Descendants[0] = type0;
	m_Descendants[1] = decl1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclaration_specifiers::~CDASTdeclaration_specifiers(){}
CDASTinit_declarator_list::CDASTinit_declarator_list(CDASTinit_declarator* init0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_init_declarator_list;
	m_Descendants[0] = init0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTinit_declarator_list::CDASTinit_declarator_list(CDASTinit_declarator_list* init0, CDASTTOKEN* TOKE1, CDASTinit_declarator* init2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_init_declarator_list;
	m_Descendants[0] = init0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = init2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTinit_declarator_list::~CDASTinit_declarator_list(){}
CDASTinit_declarator::CDASTinit_declarator(CDASTdeclarator* decl0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_init_declarator;
	m_Descendants[0] = decl0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTinit_declarator::CDASTinit_declarator(CDASTdeclarator* decl0, CDASTTOKEN* TOKE1, CDASTinitializer* init2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_init_declarator;
	m_Descendants[0] = decl0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = init2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTinit_declarator::~CDASTinit_declarator(){}
CDASTstorage_class_specifier::CDASTstorage_class_specifier(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_storage_class_specifier;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTstorage_class_specifier::~CDASTstorage_class_specifier(){}
CDASTtype_specifier::CDASTtype_specifier(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_type_specifier;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTtype_specifier::CDASTtype_specifier(CDASTstruct_or_union_specifier* stru0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_type_specifier;
	m_Descendants[0] = stru0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTtype_specifier::CDASTtype_specifier(CDASTenum_specifier* enum0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_type_specifier;
	m_Descendants[0] = enum0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTtype_specifier::~CDASTtype_specifier(){}
CDASTstruct_or_union_specifier::CDASTstruct_or_union_specifier(CDASTstruct_or_union* stru0, CDASTqualified_id* qual1, CDASTTOKEN* TOKE2, CDASTstruct_declaration_list* stru3, CDASTTOKEN* TOKE4, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_or_union_specifier;
	m_Descendants[0] = stru0;
	m_Descendants[1] = qual1;
	m_Descendants[2] = TOKE2;
	m_Descendants[3] = stru3;
	m_Descendants[4] = TOKE4;
	m_NumberOfDescendants =5;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_or_union_specifier::CDASTstruct_or_union_specifier(CDASTstruct_or_union* stru0, CDASTTOKEN* TOKE1, CDASTstruct_declaration_list* stru2, CDASTTOKEN* TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_or_union_specifier;
	m_Descendants[0] = stru0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = stru2;
	m_Descendants[3] = TOKE3;
	m_NumberOfDescendants =4;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_or_union_specifier::CDASTstruct_or_union_specifier(CDASTstruct_or_union* stru0, CDASTqualified_id* qual1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_or_union_specifier;
	m_Descendants[0] = stru0;
	m_Descendants[1] = qual1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_or_union_specifier::~CDASTstruct_or_union_specifier(){}
CDASTstruct_or_union::CDASTstruct_or_union(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_or_union;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_or_union::~CDASTstruct_or_union(){}
CDASTstruct_declaration_list::CDASTstruct_declaration_list(CDASTstruct_declaration* stru0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declaration_list;
	m_Descendants[0] = stru0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declaration_list::CDASTstruct_declaration_list(CDASTstruct_declaration_list* stru0, CDASTstruct_declaration* stru1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declaration_list;
	m_Descendants[0] = stru0;
	m_Descendants[1] = stru1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declaration_list::~CDASTstruct_declaration_list(){}
CDASTstruct_declaration::CDASTstruct_declaration(CDASTspecifier_qualifier_list* spec0, CDASTstruct_declarator_list* stru1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declaration;
	m_Descendants[0] = spec0;
	m_Descendants[1] = stru1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declaration::~CDASTstruct_declaration(){}
CDASTspecifier_qualifier_list::CDASTspecifier_qualifier_list(CDASTtype_specifier* type0, CDASTspecifier_qualifier_list* spec1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_specifier_qualifier_list;
	m_Descendants[0] = type0;
	m_Descendants[1] = spec1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTspecifier_qualifier_list::CDASTspecifier_qualifier_list(CDASTtype_specifier* type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_specifier_qualifier_list;
	m_Descendants[0] = type0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTspecifier_qualifier_list::CDASTspecifier_qualifier_list(CDASTtype_qualifier* type0, CDASTspecifier_qualifier_list* spec1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_specifier_qualifier_list;
	m_Descendants[0] = type0;
	m_Descendants[1] = spec1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTspecifier_qualifier_list::CDASTspecifier_qualifier_list(CDASTtype_qualifier* type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_specifier_qualifier_list;
	m_Descendants[0] = type0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTspecifier_qualifier_list::~CDASTspecifier_qualifier_list(){}
CDASTstruct_declarator_list::CDASTstruct_declarator_list(CDASTstruct_declarator* stru0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declarator_list;
	m_Descendants[0] = stru0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declarator_list::CDASTstruct_declarator_list(CDASTstruct_declarator_list* stru0, CDASTTOKEN* TOKE1, CDASTstruct_declarator* stru2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declarator_list;
	m_Descendants[0] = stru0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = stru2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declarator_list::~CDASTstruct_declarator_list(){}
CDASTstruct_declarator::CDASTstruct_declarator(CDASTdeclarator* decl0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declarator;
	m_Descendants[0] = decl0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declarator::CDASTstruct_declarator(CDASTTOKEN* TOKE0, CDASTconstant_expression* cons1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declarator;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = cons1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declarator::CDASTstruct_declarator(CDASTdeclarator* decl0, CDASTTOKEN* TOKE1, CDASTconstant_expression* cons2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_struct_declarator;
	m_Descendants[0] = decl0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = cons2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTstruct_declarator::~CDASTstruct_declarator(){}
CDASTenum_specifier::CDASTenum_specifier(CDASTTOKEN* TOKE0, CDASTTOKEN* TOKE1, CDASTenumerator_list* enum2, CDASTTOKEN* TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_enum_specifier;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = enum2;
	m_Descendants[3] = TOKE3;
	m_NumberOfDescendants =4;
	//DEBUG_TraceOnASTCreation();
}
CDASTenum_specifier::CDASTenum_specifier(CDASTTOKEN* TOKE0, CDASTqualified_id* qual1, CDASTTOKEN* TOKE2, CDASTenumerator_list* enum3, CDASTTOKEN* TOKE4, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_enum_specifier;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = qual1;
	m_Descendants[2] = TOKE2;
	m_Descendants[3] = enum3;
	m_Descendants[4] = TOKE4;
	m_NumberOfDescendants =5;
	//DEBUG_TraceOnASTCreation();
}
CDASTenum_specifier::CDASTenum_specifier(CDASTTOKEN* TOKE0, CDASTqualified_id* qual1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_enum_specifier;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = qual1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTenum_specifier::~CDASTenum_specifier(){}
CDASTenumerator_list::CDASTenumerator_list(CDASTenumerator* enum0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_enumerator_list;
	m_Descendants[0] = enum0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTenumerator_list::CDASTenumerator_list(CDASTenumerator_list* enum0, CDASTTOKEN* TOKE1, CDASTenumerator* enum2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_enumerator_list;
	m_Descendants[0] = enum0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = enum2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTenumerator_list::~CDASTenumerator_list(){}
CDASTenumerator::CDASTenumerator(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_enumerator;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTenumerator::CDASTenumerator(CDASTTOKEN* TOKE0, CDASTTOKEN* TOKE1, CDASTconstant_expression* cons2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_enumerator;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = cons2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTenumerator::~CDASTenumerator(){}
CDASTtype_qualifier::CDASTtype_qualifier(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_type_qualifier;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTtype_qualifier::~CDASTtype_qualifier(){}
CDASTdeclarator::CDASTdeclarator(CDASTpointer* poin0, CDASTdirect_declarator* dire1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declarator;
	m_Descendants[0] = poin0;
	m_Descendants[1] = dire1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclarator::CDASTdeclarator(CDASTdirect_declarator* dire0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_declarator;
	m_Descendants[0] = dire0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTdeclarator::~CDASTdeclarator(){}
CDASTdirect_declarator::CDASTdirect_declarator(CDASTqualified_id* qual0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_declarator;
	m_Descendants[0] = qual0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_declarator::CDASTdirect_declarator(CDASTTOKEN* TOKE0, CDASTdeclarator* decl1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_declarator;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = decl1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_declarator::CDASTdirect_declarator(CDASTdirect_declarator* dire0, CDASTTOKEN* TOKE1, CDASTconstant_expression* cons2, CDASTTOKEN* TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_declarator;
	m_Descendants[0] = dire0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = cons2;
	m_Descendants[3] = TOKE3;
	m_NumberOfDescendants =4;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_declarator::CDASTdirect_declarator(CDASTdirect_declarator* dire0, CDASTTOKEN* TOKE1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_declarator;
	m_Descendants[0] = dire0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_declarator::CDASTdirect_declarator(CDASTdirect_declarator* dire0, CDASTTOKEN* TOKE1, CDASTparameter_type_list* para2, CDASTTOKEN* TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_declarator;
	m_Descendants[0] = dire0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = para2;
	m_Descendants[3] = TOKE3;
	m_NumberOfDescendants =4;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_declarator::~CDASTdirect_declarator(){}
CDASTpointer::CDASTpointer(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_pointer;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTpointer::CDASTpointer(CDASTTOKEN* TOKE0, CDASTtype_qualifier_list* type1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_pointer;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = type1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTpointer::CDASTpointer(CDASTTOKEN* TOKE0, CDASTpointer* poin1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_pointer;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = poin1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTpointer::CDASTpointer(CDASTTOKEN* TOKE0, CDASTtype_qualifier_list* type1, CDASTpointer* poin2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_pointer;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = type1;
	m_Descendants[2] = poin2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTpointer::~CDASTpointer(){}
CDASTtype_qualifier_list::CDASTtype_qualifier_list(CDASTtype_qualifier* type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_type_qualifier_list;
	m_Descendants[0] = type0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTtype_qualifier_list::CDASTtype_qualifier_list(CDASTtype_qualifier_list* type0, CDASTtype_qualifier* type1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_type_qualifier_list;
	m_Descendants[0] = type0;
	m_Descendants[1] = type1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTtype_qualifier_list::~CDASTtype_qualifier_list(){}
CDASTparameter_type_list::CDASTparameter_type_list(CDASTparameter_list* para0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_parameter_type_list;
	m_Descendants[0] = para0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTparameter_type_list::CDASTparameter_type_list(CDASTparameter_list* para0, CDASTTOKEN* TOKE1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_parameter_type_list;
	m_Descendants[0] = para0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTparameter_type_list::~CDASTparameter_type_list(){}
CDASTparameter_list::CDASTparameter_list(CDASTparameter_declaration* para0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_parameter_list;
	m_Descendants[0] = para0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTparameter_list::CDASTparameter_list(CDASTparameter_list* para0, CDASTTOKEN* TOKE1, CDASTparameter_declaration* para2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_parameter_list;
	m_Descendants[0] = para0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = para2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTparameter_list::~CDASTparameter_list(){}
CDASTparameter_declaration::CDASTparameter_declaration(CDASTdeclaration_specifiers* decl0, CDASTdeclarator* decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_parameter_declaration;
	m_Descendants[0] = decl0;
	m_Descendants[1] = decl1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTparameter_declaration::CDASTparameter_declaration(CDASTdeclaration_specifiers* decl0, CDASTabstract_declarator* abst1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_parameter_declaration;
	m_Descendants[0] = decl0;
	m_Descendants[1] = abst1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTparameter_declaration::CDASTparameter_declaration(CDASTdeclaration_specifiers* decl0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_parameter_declaration;
	m_Descendants[0] = decl0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTparameter_declaration::~CDASTparameter_declaration(){}
CDASTtype_name::CDASTtype_name(CDASTspecifier_qualifier_list* spec0, CDASTabstract_declarator* abst1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_type_name;
	m_Descendants[0] = spec0;
	m_Descendants[1] = abst1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTtype_name::~CDASTtype_name(){}
CDASTabstract_declarator::CDASTabstract_declarator(CDASTpointer* poin0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_abstract_declarator;
	m_Descendants[0] = poin0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTabstract_declarator::CDASTabstract_declarator(CDASTdirect_abstract_declarator* dire0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_abstract_declarator;
	m_Descendants[0] = dire0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTabstract_declarator::CDASTabstract_declarator(CDASTpointer* poin0, CDASTdirect_abstract_declarator* dire1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_abstract_declarator;
	m_Descendants[0] = poin0;
	m_Descendants[1] = dire1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTabstract_declarator::~CDASTabstract_declarator(){}
CDASTdirect_abstract_declarator::CDASTdirect_abstract_declarator(CDASTTOKEN* TOKE0, CDASTabstract_declarator* abst1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_abstract_declarator;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = abst1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_abstract_declarator::CDASTdirect_abstract_declarator(CDASTTOKEN* TOKE0, CDASTTOKEN* TOKE1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_abstract_declarator;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = TOKE1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_abstract_declarator::CDASTdirect_abstract_declarator(CDASTTOKEN* TOKE0, CDASTconstant_expression* cons1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_abstract_declarator;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = cons1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_abstract_declarator::CDASTdirect_abstract_declarator(CDASTdirect_abstract_declarator* dire0, CDASTTOKEN* TOKE1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_abstract_declarator;
	m_Descendants[0] = dire0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_abstract_declarator::CDASTdirect_abstract_declarator(CDASTdirect_abstract_declarator* dire0, CDASTTOKEN* TOKE1, CDASTconstant_expression* cons2, CDASTTOKEN* TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_abstract_declarator;
	m_Descendants[0] = dire0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = cons2;
	m_Descendants[3] = TOKE3;
	m_NumberOfDescendants =4;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_abstract_declarator::CDASTdirect_abstract_declarator(CDASTTOKEN* TOKE0, CDASTparameter_type_list* para1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_abstract_declarator;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = para1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_abstract_declarator::CDASTdirect_abstract_declarator(CDASTdirect_abstract_declarator* dire0, CDASTTOKEN* TOKE1, CDASTparameter_type_list* para2, CDASTTOKEN* TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_direct_abstract_declarator;
	m_Descendants[0] = dire0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = para2;
	m_Descendants[3] = TOKE3;
	m_NumberOfDescendants =4;
	//DEBUG_TraceOnASTCreation();
}
CDASTdirect_abstract_declarator::~CDASTdirect_abstract_declarator(){}
CDASTinitializer::CDASTinitializer(CDASTassignment_expression* assi0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_initializer;
	m_Descendants[0] = assi0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTinitializer::CDASTinitializer(CDASTTOKEN* TOKE0, CDASTinitializer_list* init1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_initializer;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = init1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTinitializer::CDASTinitializer(CDASTTOKEN* TOKE0, CDASTinitializer_list* init1, CDASTTOKEN* TOKE2, CDASTTOKEN* TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_initializer;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = init1;
	m_Descendants[2] = TOKE2;
	m_Descendants[3] = TOKE3;
	m_NumberOfDescendants =4;
	//DEBUG_TraceOnASTCreation();
}
CDASTinitializer::~CDASTinitializer(){}
CDASTinitializer_list::CDASTinitializer_list(CDASTinitializer* init0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_initializer_list;
	m_Descendants[0] = init0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTinitializer_list::CDASTinitializer_list(CDASTinitializer_list* init0, CDASTTOKEN* TOKE1, CDASTinitializer* init2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_initializer_list;
	m_Descendants[0] = init0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = init2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTinitializer_list::~CDASTinitializer_list(){}
CDASTqualified_id::CDASTqualified_id(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_qualified_id;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTqualified_id::CDASTqualified_id(CDASTTOKEN* TOKE0, CDASTTOKEN* TOKE1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_qualified_id;
	m_Descendants[0] = TOKE0;
	m_Descendants[1] = TOKE1;
	m_NumberOfDescendants =2;
	//DEBUG_TraceOnASTCreation();
}
CDASTqualified_id::CDASTqualified_id(CDASTqualified_id* qual0, CDASTTOKEN* TOKE1, CDASTTOKEN* TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_qualified_id;
	m_Descendants[0] = qual0;
	m_Descendants[1] = TOKE1;
	m_Descendants[2] = TOKE2;
	m_NumberOfDescendants =3;
	//DEBUG_TraceOnASTCreation();
}
CDASTqualified_id::~CDASTqualified_id(){}
CDASTassignment_expression::CDASTassignment_expression(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_assignment_expression;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTassignment_expression::~CDASTassignment_expression(){}
CDASTconstant_expression::CDASTconstant_expression(CDASTTOKEN* TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr)
:CDASTSyntaxElement(pr,loc){
	m_NonTerminalCode = DLNT_constant_expression;
	m_Descendants[0] = TOKE0;
	m_NumberOfDescendants =1;
	//DEBUG_TraceOnASTCreation();
}
CDASTconstant_expression::~CDASTconstant_expression(){}