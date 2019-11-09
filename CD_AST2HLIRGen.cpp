/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\CD_AST2HLIRGen.cpp																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
#include "CD_ASTSyntaxElements.h"
#include "CD_HLIRSyntaxElements.h"
//#define  DEBUG_ONTRAVERSAL

// Global variables for transmitting events from a descendant to a higher 
// in the hierarchy object.
DLHLIR_ELEMENT_TYPE g_InstanciatedElementType; // informs about the last instantiated element
CDHLIRSyntaxElement *g_InstanciatedElement;

extern DLTYPE_SPECIFIERS g_type_specifier; // Informs the declaration object about the 
						    // most recent type_specifier discovered by
						    // the ASTtoHLIRGeneration function
extern DLSTORAGE_CLASS g_storage_class; // Informs the declaration object about the 
						 // most recent storage class specifier discovered by
						 // the ASTtoHLIRGeneration function
extern DLTYPE_QUALIFIER g_type_qualifier; 	// Informs the declaration object about the 
							// most recent type qualifier discovered by
							// the ASTtoHLIRGeneration function
extern DLFUNCTION_SPECIFIER g_Function_Specifier; // Informs the declaration object about the 
								 // most recent function specifier discovered by
								 // the ASTtoHLIRGeneration function

void CDASTSyntaxElement::DEBUG_TraceOnTraversal(){
#ifdef DEBUG_ONTRAVERSAL
	cout << endl << DLnonterminal_strings[m_NonTerminalCode] 
	<< m_ObjectSerialNumber;
#endif
}

CDHLIRSyntaxElement * CDASTSyntaxElement::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
unsigned int i;
	for(i=0; i<m_NumberOfDescendants; i++ ){
		m_Descendants[i]->ASTToHLIRGenerationPass(parent,child);
	}	
	return NULL;
}
CDHLIRSyntaxElement * CDASTTOKEN::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *newobject=NULL,*parent_old;
	if(m_TerminalCode == DLT_IDENTIFIER || 
	   m_TerminalCode == DLT_TYPE_NAME){
		DLHLIR_CONTEXT context=DLE_NotApplicable;
		DEBUG_TraceOnTraversal();
		newobject = new CDE_HLIRIDENTIFIER(this->GetTokenString());
		parent->InstallContextElement(newobject,context);
		CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	}
	else if(m_TerminalCode == DLT_CONSTANT_EXPRESSION){
		DLHLIR_CONTEXT context=DLE_NotApplicable;
		DEBUG_TraceOnTraversal();
		newobject = new CDE_HLIRCONSTANT(this->GetTokenString());
		parent->InstallContextElement(newobject,context);
		CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	}
	else{
		DEBUG_TraceOnTraversal();
		parent_old = parent;
		CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
		parent = parent_old;
	}
return NULL;
}
CDHLIRSyntaxElement * CDASTscdeclaration_unit::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *newobject,*parent_old;
	DEBUG_TraceOnTraversal(); 
	parent_old = parent;
	newobject = new CD_HLIRTranslationUnit();
	parent->InstallContextElement(newobject); 
	parent = newobject;
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,newobject);
	parent = parent_old;
return newobject;
}
CDHLIRSyntaxElement * CDASTscdeclarations::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTscdeclaration::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL, *_parent=NULL, *parent_old;
CDHLIRSyntaxElement *tp, *tpscont;
unsigned int i;
	DEBUG_TraceOnTraversal();
	parent_old = parent;	
	new_object = new CD_HLIRDeclaration();
	parent->InstallContextElement(new_object);
	
	for(i=0; i<m_NumberOfDescendants; i++ ){
		parent = new_object;
		m_Descendants[i]->ASTToHLIRGenerationPass(parent,child);
		
		// Deduce type specification from type specifiers when
		// all type specifiers are collected
		if ( i == 0 ){ 
			if ( ((CD_HLIRDeclaration *)new_object)->GetStorageClass() == DLSCT_TYPEDEF ){
				new_object->SetHLIRElementType(DL_TypeDeclaration);				
			}
			tpscont = new_object->GetContextElement(DL_Declaration_TypeSpecifiers);
			tp = ((CD_HLIRTypeSpecifiers *)tpscont)->DeduceCreateTypeSpecification();
			if ( tp != NULL ){
				tpscont->InstallContextElement(tp);			
			}
		}
		
	}	
	parent = parent_old;	
return new_object;
}
CDHLIRSyntaxElement * CDASTdeclaration_specifiers::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	CDHLIRSyntaxElement *parent_old;
	DEBUG_TraceOnTraversal();
	parent_old = parent;
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	parent = parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTinit_declarator_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTinit_declarator::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL, *parent_old;
CD_HLIRDeclaration *declaration;
CDE_HLIRIDENTIFIER *id;
	DEBUG_TraceOnTraversal();
	parent_old=  parent;
	new_object = new CD_HLIRDeclarator();
	parent->InstallContextElement(new_object);	
	parent = new_object;
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
// 	if  ( parent_old->GetHLIRElementType() == _TypeDeclaration ){
// 		declaration = (CD_HLIRDeclaration *)parent;
// 		new_object->SeekDeclarator(id);
// 		g_TypesSymbolTable.push_back(id->GetIdentifierString());
// 	}
	parent = parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTstorage_class_specifier::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();	
	if ( !(parent->GetHLIRElementType() != DL_Declaration ||
		parent->GetHLIRElementType() != DL_FunctionDefinition )){
			cout << endl << "Storage Specifiers could only be applied to declarations"
				<< endl;	
			exit(0);
	}	
	switch(m_NonTerminal_ProductionCode){
		case DLAST_Storage_class_specifier__AUTO_:
			g_storage_class = DLSCT_AUTO; 
			parent->InstallPropertyMessage(MSG_STORAGE_CLASS);			
		break;
		case DLAST_Storage_class_specifier__EXTERN_:
			g_storage_class = DLSCT_EXTERN;
			parent->InstallPropertyMessage(MSG_STORAGE_CLASS);			
		break;
		case DLAST_Storage_class_specifier__REGISTER_:
			g_storage_class = DLSCT_REGISTER;
			parent->InstallPropertyMessage(MSG_STORAGE_CLASS);			
		break;
		case DLAST_Storage_class_specifier__STATIC_:
			g_storage_class = DLSCT_STATIC;
			parent->InstallPropertyMessage(MSG_STORAGE_CLASS);			
		break;	
		case DLAST_Storage_class_specifier__TYPEDEF_:
			g_storage_class = DLSCT_TYPEDEF;
			parent->InstallPropertyMessage(MSG_STORAGE_CLASS);			
		break;	
		default:;
	}	
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTtype_specifier::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL, *parent_old;
	DEBUG_TraceOnTraversal();
	if ( !(parent->GetHLIRElementType() != DL_Declaration ||
		 parent->GetHLIRElementType() != DL_FunctionDefinition )){
		cout << endl << "Type specifiers could only be applied to declarations"
			 << endl;	
		exit(0);
	}
	if ( parent->GetHLIRElementType() != DL_TypeSpecifier ){
		new_object = new CD_HLIRTypeSpecifiers();
		parent->InstallContextElement(new_object);	
		parent = new_object;
	}
	switch(m_NonTerminal_ProductionCode){
		case DLAST_Type_specifier__VOID_:
			g_type_specifier = DLTSP_VOID;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__CHAR_:
			g_type_specifier = DLTSP_CHAR;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__INT_:	
			g_type_specifier = DLTSP_INT;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;					
		case DLAST_Type_specifier__FLOAT_:
			g_type_specifier = DLTSP_FLOAT;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;					
		case DLAST_Type_specifier__SHORT_:			
			g_type_specifier = DLTSP_SHORT;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__LONG_:					
			g_type_specifier = DLTSP_LONG;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__DOUBLE_:
			g_type_specifier = DLTSP_DOUBLE;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__SIGNED_:			
			g_type_specifier = DLTSP_SIGNED;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__UNSIGNED_:			
			g_type_specifier = DLTSP_UNSIGNED;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__TYPE_NAME_:
			g_type_specifier = DLTSP_TYPENAME;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
		break;
		case DLAST_Type_specifier__Struct_or_union_specifier_:
		case DLAST_Type_specifier__Enum_specifier_:
		default:;
	}	
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTstruct_or_union_specifier::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object = NULL, *parent_old;	
	DEBUG_TraceOnTraversal();
	parent_old = parent;
	
	switch(m_Descendants[0]->m_NonTerminal_ProductionCode){
		case DLAST_Struct_or_union__STRUCT_:
			if ( m_NonTerminal_ProductionCode == DLAST_Struct_or_union_specifier__Struct_or_union_Qualified_id_){		
				new_object = new CT_HLIRStructureType(DLT_StructureType_Decl);
			}
			else {
				new_object = new CT_HLIRStructureType(DLT_StructureType_Def);
			}
			g_type_specifier = DLTSP_TYPENAME;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
			parent->InstallContextElement(new_object);
			parent = new_object;
		break;
		case DLAST_Struct_or_union__UNION_:
			if ( m_NonTerminal_ProductionCode == DLAST_Struct_or_union_specifier__Struct_or_union_Qualified_id_){		
				new_object = new CT_HLIRUnionType(DLT_UnionType_Decl);
			}
			else {
				new_object = new CT_HLIRUnionType(DLT_UnionType_Def);
			}	
			g_type_specifier = DLTSP_TYPENAME;
			parent->InstallPropertyMessage(MSG_TYPE_SPECIFIER);
			parent->InstallContextElement(new_object);
			parent = new_object;			
		break;
		default:;
	}
	
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	parent = parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTstruct_or_union::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTstruct_declaration_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTstruct_declaration::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL, *_parent=NULL, *parent_old;
CDHLIRSyntaxElement *tp, *tpscont;
unsigned int i;
	DEBUG_TraceOnTraversal();
	parent_old = parent;	
	new_object = new CD_HLIRDeclaration();
	parent->InstallContextElement(new_object);
	
	for(i=0; i<m_NumberOfDescendants; i++ ){
		parent = new_object;
		m_Descendants[i]->ASTToHLIRGenerationPass(parent,child);
		
		// Deduce type specification from type specifiers when
		// all type specifiers are collected
		if ( i == 0 ){ 
			if ( ((CD_HLIRDeclaration *)new_object)->GetStorageClass() == DLSCT_TYPEDEF ){
				new_object->SetHLIRElementType(DL_TypeDeclaration);
			}
			tpscont = new_object->GetContextElement(DL_Declaration_TypeSpecifiers);
			tp = ((CD_HLIRTypeSpecifiers *)tpscont)->DeduceCreateTypeSpecification();
			if ( tp != NULL ){
				tpscont->InstallContextElement(tp);	
			}			
		}
	}	
	parent = parent_old;	
return new_object;
}
CDHLIRSyntaxElement * CDASTspecifier_qualifier_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *parent_old;
	DEBUG_TraceOnTraversal();
	parent_old = parent;
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	parent = parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTstruct_declarator_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTstruct_declarator::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTenum_specifier::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL, *parent_old;
	DEBUG_TraceOnTraversal();
	parent_old = parent;
	if ( m_NonTerminal_ProductionCode == DLAST_Enum_specifier__ENUM_Qualified_id_ ){
		new_object = new CT_HLIREnumeratedType(DLT_EnumeratedType_Decl);
	}
	else{
		new_object = new CT_HLIREnumeratedType(DLT_EnumeratedType_Def);
	}	
	parent->InstallContextElement(new_object);
	parent =new_object;
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	parent = parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTenumerator_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTenumerator::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object= NULL, *parent_old;
	DEBUG_TraceOnTraversal();
	parent_old =parent;
	new_object = new CD_HLIREnumerator();
	parent->InstallContextElement(new_object);
	parent =new_object;
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	parent = parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTtype_qualifier::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object= NULL, *parent_old;
	DEBUG_TraceOnTraversal();	
	parent_old = parent;
	switch(m_NonTerminal_ProductionCode){
		case DLAST_Type_qualifier__CONST_:
			new_object=  new CD_HLIRTypeQualifier(DLTQL_CONST);
			parent->InstallContextElement(new_object);			
			parent = new_object;
		break;
		case DLAST_Type_qualifier__VOLATILE_:
			new_object=  new CD_HLIRTypeQualifier(DLTQL_VOLATILE);
			parent->InstallContextElement(new_object);			
			parent = new_object;
		break;
		case DLAST_Type_qualifier__IN_:
			new_object=  new CD_HLIRTypeQualifier(DLTQL_IN);
			parent->InstallContextElement(new_object);			
			parent = new_object;
		break;
		case DLAST_Type_qualifier__OUT_:
			new_object=  new CD_HLIRTypeQualifier(DLTQL_OUT);
			parent->InstallContextElement(new_object);			
			parent = new_object;
		break;
		default:;
	}
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	if ( parent_old->GetHLIRElementType() == DL_Declaration ||
		 parent_old->GetHLIRElementType() == DL_Typename ||
		 parent_old->GetHLIRElementType() == DL_TypeDeclaration ){
		parent = parent_old;
	}
return NULL;
}
CDHLIRSyntaxElement * CDASTdeclarator::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTdirect_declarator::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_type=NULL, *parent_old;
unsigned int i;
// CONTEXTS
// _Declarator_identifier
// _Declarator_TypeExpression
// _Declarator_Initializer
	parent_old= parent;
	DEBUG_TraceOnTraversal();
	switch(m_NonTerminal_ProductionCode){			
		case DLAST_Direct_declarator__Direct_declarator_LBRACKET_Constant_expression_RBRACKET_:
			new_type = new CT_HLIRArrayType();			
			parent->InstallContextElement(new_type);
			parent = new_type;					
			break;
		case DLAST_Direct_declarator__Direct_declarator_LBRACKET_RBRACKET_:
			new_type = new CT_HLIRArrayType();			
			parent->InstallContextElement(new_type);
			parent =new_type;
			break;
		case DLAST_Direct_declarator__Direct_declarator_LPARENTHESIS_RPARENTHESIS_:
			new_type = new CT_HLIRFunctionType();
			parent->InstallContextElement(new_type);
			parent = new_type;
			break;
		case DLAST_Direct_declarator__Direct_declarator_LPARENTHESIS_Parameter_type_list_RPARENTHESIS_:
			new_type = new CT_HLIRFunctionType();
			parent->InstallContextElement(new_type);
			parent = new_type;
			break;
		case DLAST_Direct_declarator__LPARENTHESIS_Declarator_RPARENTHESIS_:			
			break;
		case DLAST_Direct_declarator__Qualified_id_:
		default:;			
	}
	for(i=0; i<m_NumberOfDescendants; i++ ){
		switch(m_NonTerminal_ProductionCode){
			case DLAST_Direct_declarator__Direct_declarator_LBRACKET_Constant_expression_RBRACKET_:
			case DLAST_Direct_declarator__Direct_declarator_LBRACKET_RBRACKET_:				
				parent = child = new_type;				
				break;
			default:;			
		}	
		m_Descendants[i]->ASTToHLIRGenerationPass(parent,child);
	}	
	parent=parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTpointer::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL;		
	DEBUG_TraceOnTraversal();
	new_object = new CT_HLIRPointerType();	
	parent->InstallContextElement(new_object);		
	parent= new_object;
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTtype_qualifier_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTparameter_type_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTparameter_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTparameter_declaration::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL, *_parent=NULL, *parent_old;
CDHLIRSyntaxElement *tp ,*tpscont;
DLHLIR_CONTEXT context = DLT_FunctionType_Parameters;
unsigned int i;
	DEBUG_TraceOnTraversal();
	parent_old = parent;
	new_object = new CD_HLIRDeclaration();
	parent->InstallContextElement(new_object,DLT_FunctionType_Parameters);
	
	for(i=0; i<m_NumberOfDescendants; i++ ){
		parent = new_object;
		m_Descendants[i]->ASTToHLIRGenerationPass(parent,child);
		
		// Deduce type specification from type specifiers when
		// all type specifiers are collected
		if ( i == 0 ){ 
			if ( ((CD_HLIRDeclaration *)new_object)->GetStorageClass() == DLSCT_TYPEDEF ){
				new_object->SetHLIRElementType(DL_TypeDeclaration);
			}
			tpscont = new_object->GetContextElement(DL_Declaration_TypeSpecifiers);
			tp = ((CD_HLIRTypeSpecifiers *)tpscont)->DeduceCreateTypeSpecification();
			if ( tp != NULL ){
				tpscont->InstallContextElement(tp);			
			}	
		}
	}	
	parent = parent_old;	
return new_object;
}
CDHLIRSyntaxElement * CDASTtype_name::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTabstract_declarator::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTdirect_abstract_declarator::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_type=NULL, *parent_old;
unsigned int i;
// CONTEXTS
// _Declarator_identifier
// _Declarator_TypeExpression
// _Declarator_Initializer
	DEBUG_TraceOnTraversal();
	parent_old = parent;
	
	switch(m_NonTerminal_ProductionCode){			
		case DLAST_Direct_abstract_declarator__LPARENTHESIS_Abstract_declarator_RPARENTHESIS_:			
		break; 		
		case DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LBRACKET_Constant_expression_RBRACKET_:
			new_type = new CT_HLIRArrayType();			
			if ( parent != NULL ){
				parent->InstallContextElement(new_type);
			}											
			break;
		case DLAST_Direct_abstract_declarator__LBRACKET_Constant_expression_RBRACKET_: // only the pure array type can be directly attached to the parent
			new_type = new CT_HLIRArrayType();			
			if ( parent != NULL ){
				parent->InstallContextElement(new_type);
			}				
			break;
		case DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LBRACKET_RBRACKET_:
		case DLAST_Direct_abstract_declarator__LBRACKET_RBRACKET_:
			new_type = new CT_HLIRArrayType();			
			if ( parent != NULL ){
				parent->InstallContextElement(new_type);
			}		
			parent = new_type;
			child = new_type;	
			break;
		case DLAST_Direct_abstract_declarator__LPARENTHESIS_RPARENTHESIS_:
			new_type = new CT_HLIRFunctionType();			
			parent->InstallContextElement(new_type);
			parent = new_type;
			break;
		case DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LPARENTHESIS_Parameter_type_list_RPARENTHESIS_:
			new_type = new CT_HLIRFunctionType();			
			parent->InstallContextElement(new_type);
			parent = new_type;
			break;
		case DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LPARENTHESIS_RPARENTHESIS_:
			new_type = new CT_HLIRFunctionType();			
			parent->InstallContextElement(new_type);
			parent = new_type;
			break;					
		default:	;		
	}		
	for(i=0; i<m_NumberOfDescendants; i++ ){
		switch(m_NonTerminal_ProductionCode){
			case DLAST_Direct_abstract_declarator__LBRACKET_Constant_expression_RBRACKET_:
			case DLAST_Direct_abstract_declarator__LBRACKET_RBRACKET_:
			case DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LBRACKET_Constant_expression_RBRACKET_:				
					parent = child = new_type;				
			break;
			default:;
		}	
		m_Descendants[i]->ASTToHLIRGenerationPass(parent,child);
	}
	
	parent = parent_old;			
return NULL;
}
CDHLIRSyntaxElement * CDASTinitializer::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
CDHLIRSyntaxElement *new_object=NULL, *parent_old;
	DEBUG_TraceOnTraversal();
	parent_old = parent;
//	if ( m_NonTerminal_ProductionCode != Initializer__AssignmentExpression){
		new_object = new CD_HLIRInitializer();
		parent->InstallContextElement(new_object);	
		parent =new_object;
//	}	
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
	parent = parent_old;
return NULL;
}
CDHLIRSyntaxElement * CDASTinitializer_list::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTqualified_id::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTassignment_expression::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}
CDHLIRSyntaxElement * CDASTconstant_expression::ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent, CDHLIRSyntaxElement *&child){
	DEBUG_TraceOnTraversal();  
	CDASTSyntaxElement::ASTToHLIRGenerationPass(parent,child);
return NULL;
}