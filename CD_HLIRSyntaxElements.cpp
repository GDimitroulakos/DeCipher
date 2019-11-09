#include "CD_HLIRSyntaxElements.h"

DLTYPE_SPECIFIERS g_type_specifier; // Informs the declaration object about the 
						    // most recent type_specifier discovered by
						    // the ASTtoHLIRGeneration function
DLSTORAGE_CLASS g_storage_class; // Informs the declaration object about the 
						 // most recent storage class specifier discovered by
						 // the ASTtoHLIRGeneration function
DLTYPE_QUALIFIER g_type_qualifier; 	// Informs the declaration object about the 
							// most recent type qualifier discovered by
							// the ASTtoHLIRGeneration function
DLFUNCTION_SPECIFIER g_Function_Specifier; // Informs the declaration object about the 
								 // most recent function specifier discovered by
								 // the ASTtoHLIRGeneration function
								 // 

extern CDHLIRSyntaxElement *Helper_Instanciate_Type(int pos);

ofstream *CDHLIRSyntaxElement::ms_outfile = NULL;

bool Helper_ExceptionIfNotInHLIRCategory(DLHLIR_ELEMENT_CATEGORY category,
								 DLERRACT OnErrorAction,
								 string ErrorMessage,
								 unsigned int num,...){
va_list arg_lst;
unsigned int i;
CDHLIRSyntaxElement *arg;
	va_start(arg_lst,num);
	for ( i = 0;i<num; i++ ){
		arg = va_arg(arg_lst,CDHLIRSyntaxElement *);
		if ( arg->GetHLIRElementCategory() != category ){
			if ( OnErrorAction== DLERR_INFORM || OnErrorAction ==DLERR_EXIT ){
				cout << ErrorMessage.data();		
				if ( OnErrorAction ==DLERR_EXIT ){
					exit(0);
				}
			}				
			if ( OnErrorAction==DLERR_FLAG ){
				return false;
			}
		}
	}
	va_end(arg_lst);
return true;
}

CDHLIRSyntaxElement::CDHLIRSyntaxElement(unsigned int num_contexts)
:DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>(num_contexts){
	m_Descriptor = NULL;
	state =0;
}
CDHLIRSyntaxElement::CDHLIRSyntaxElement(CDHLIRSyntaxElement *generator, CDHLIRSyntaxElement *parent/* =NULL */)
:DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>(generator->GetNumberofContexts()){
	m_Descriptor = NULL;
}
CDHLIRSyntaxElement::CDHLIRSyntaxElement(const CDHLIRSyntaxElement &init)
:DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>(init.m_Context.size()){
}
CDHLIRSyntaxElement::~CDHLIRSyntaxElement(){}
void CDHLIRSyntaxElement::SeekDeclarator(CDHLIRSyntaxElement *&ident){
	cout << endl << "SeekDeclarator Function could only be applied to"
		<< endl << "the following objects: 1)CE_HLIRIDENTIFIER, 2)T_ArrayType,"
		<< endl << "3)T_FunctionType and 4)T_PointerType"
		<< endl << "returning...";
}
void CDHLIRSyntaxElement::SetOutputFile(string outputFile){
	if(ms_outfile != NULL){
		ms_outfile->close();
		delete ms_outfile;
	}
	ms_outfile = new ofstream(outputFile.c_str());
}
char *CDHLIRSyntaxElement::InitHLIRElementTypeString(){
	string s,s1;
	char *buffer;
	buffer = new char[10];
	_itoa_s(m_Descriptor->m_HLIRObjectSerialCounter,buffer,10,10);
	s1= (string)buffer;
	s= (string)(g_DLHLIRtypeidentifier[m_Descriptor->m_HLIRSyntaxElementType]) + s1;
	delete [] buffer;
	return DLStrDup_cpp(s.c_str());
}
void CDHLIRSyntaxElement::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){

}
void CDHLIRSyntaxElement::CDeclTraversal(){
int num_contexts = m_Context.size();
int i;
CDHLIRSyntaxElement *obj,*declobj;
CDHLIRSyntaxElement *ident;
DLHLIR_ELEMENT_TYPE tp;
class type_info_ *tpinfo;
unsigned int cont;

	for(i=0;i<num_contexts;i++){
		for(obj=tbegin(i);!ttend(i);obj=tnext(i)){
			tp =  obj->GetHLIRElementType();
			if(tp==  DL_Declaration || tp == DL_TypeDeclaration){
				cont = obj->MapContext(DL_Declaration_Declarators);
				for ( declobj = obj->tbegin(cont) ;
					  !obj->ttend(cont); declobj = obj->tnext(cont)	){
					if ( declobj ->GetHLIRElementType() == DL_Declarator ){
						declobj->SeekDeclarator(ident);
						tpinfo  = new class type_info_;
						if (tp == DL_TypeDeclaration){
							tpinfo->m_DeclaratorUnscrambledType = "TYPENAME ";
						}
						ident->SeekDeclaratorType(tpinfo,NULL);
						cout << endl << tpinfo->m_DeclaratorUnscrambledType;
					}	  
				}				
			}
			else{
				obj->CDeclTraversal();
			}
		}
	}
}
// ========================================================================
CDHLIR_Expression::CDHLIR_Expression(unsigned int num_contexts)
:CDHLIRSyntaxElement(num_contexts){
}
CDHLIR_Expression::CDHLIR_Expression(const CDHLIR_Expression &init)
:CDHLIRSyntaxElement(init){
}
CDHLIR_Expression::~CDHLIR_Expression(){
}
void CDHLIR_Expression::UpdateAnsestorAssociativity(DLEXPRESSION_RESULT_TYPE rtp){
	if ( m_Result_Type != DLNOT_APPLICABLE){
		if ( m_Result_Type != rtp ){
			cout << endl << "Error in syntax element " << g_DLHLIRtypeidentifier[m_Descriptor->m_HLIRSyntaxElementType]
				<< m_Descriptor->m_HLIRObjectSerialNumber
				<< endl << "Expression Type Clash"
				<< endl;			
			exit(0);
		}
	}
	else{
		m_Result_Type = rtp;
		if ( m_parent->GetHLIRElementCategory() == DLCAT_EXPRESSION ){
			((CDHLIR_Expression *)m_parent)->UpdateAnsestorAssociativity(rtp);
		}
	}
}
// ========================================================================
CDHLIR_Statement::CDHLIR_Statement(unsigned int num_contexts)
:CDHLIRSyntaxElement(num_contexts){
}
CDHLIR_Statement::CDHLIR_Statement(const CDHLIR_Statement &init)
:CDHLIRSyntaxElement(init){
}
CDHLIR_Statement::~CDHLIR_Statement(){
}
// ========================================================================
CDHLIR_ROOT::CDHLIR_ROOT()
:CDHLIRSyntaxElement(1){
	m_Descriptor = new CDHLIRDescriptor();	
	m_Descriptor->m_handle = this;	
	m_Descriptor->m_HLIRSyntaxElementType = DL_ROOT;
	m_Descriptor->m_HLIRGraphvizID = m_Descriptor->InitHLIRObjectGraphVizID();	
}
CDHLIR_ROOT::CDHLIR_ROOT(const CDHLIR_ROOT &init)
:CDHLIRSyntaxElement(init){
}
CDHLIR_ROOT::~CDHLIR_ROOT(){
}
int CDHLIR_ROOT::InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx, bool placebefore){
	m_Context[0]->push_back(el);
return 0;
}
int CDHLIR_ROOT::MapContext(DLHLIR_CONTEXT ctx){
	switch(ctx){
		case DL_Root_RootSingleContext:
			return 0;
			break;
		default:
			return -1;
	}
}
DLHLIR_CONTEXT CDHLIR_ROOT::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_Root_RootSingleContext;
		break;
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CDHLIR_ROOT::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CDE_HLIRIDENTIFIER::CDE_HLIRIDENTIFIER(string idstr, DLLOCATION_HLIR *loc/*=NULL*/)
:CDHLIR_Expression(0),m_Descriptor((CDHLIR_IDENTIFIERDescriptor *&)(CDHLIRSyntaxElement::m_Descriptor)){
	m_Associativity = DLASS_NOT_APPLICABLE;
	m_Result_Type = DLL_VALUE;	
	m_Descriptor = new CDHLIR_IDENTIFIERDescriptor(this,idstr,loc);
}
CDE_HLIRIDENTIFIER::CDE_HLIRIDENTIFIER(const CDE_HLIRIDENTIFIER &init)
:CDHLIR_Expression(init),m_Descriptor((CDHLIR_IDENTIFIERDescriptor *&)(CDHLIRSyntaxElement::m_Descriptor)){
}
CDE_HLIRIDENTIFIER::~CDE_HLIRIDENTIFIER(){
}
void CDE_HLIRIDENTIFIER::SeekDeclarator(CDHLIRSyntaxElement *&ident){
	ident=this;
}
void CDE_HLIRIDENTIFIER::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	//tpinfo = id_type_info = new class type_info_(0);
	tpinfo->m_DeclaratorName=m_Descriptor->m_IdentifierString;
	tpinfo->m_DeclaratorUnscrambledType += m_Descriptor->m_IdentifierString + " is ";
	tpinfo->m_TypeTree.push_back(this);	
	m_parent->SeekDeclaratorType(tpinfo, this);
}
// ========================================================================
CDE_HLIRCONSTANT::CDE_HLIRCONSTANT(string idstr, DLLOCATION_HLIR *loc/*=NULL*/)
:CDHLIR_Expression(0),m_Descriptor((CDHLIR_CONSTANTDescriptor *&)(CDHLIRSyntaxElement::m_Descriptor)){
	m_Associativity = DLASS_NOT_APPLICABLE;
	m_Result_Type = DLR_VALUE;	
	m_Descriptor = new CDHLIR_CONSTANTDescriptor(this,idstr,loc);
}
CDE_HLIRCONSTANT::CDE_HLIRCONSTANT(const CDE_HLIRCONSTANT &init)
:CDHLIR_Expression(init),m_Descriptor((CDHLIR_CONSTANTDescriptor *&)(CDHLIRSyntaxElement::m_Descriptor)){
}
CDE_HLIRCONSTANT::~CDE_HLIRCONSTANT(){
}
void CDE_HLIRCONSTANT::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	tpinfo->m_DeclaratorUnscrambledType += m_Descriptor->m_ConstantString + " ";
}
// ========================================================================
CD_HLIRTranslationUnit::CD_HLIRTranslationUnit()
:CDHLIRSyntaxElement(2){
	m_Descriptor = new CDHLIR_GPDescriptor(DL_TranslationUnit);
}
CD_HLIRTranslationUnit::CD_HLIRTranslationUnit(const CD_HLIRTranslationUnit &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIRTranslationUnit::~CD_HLIRTranslationUnit(){
}
int CD_HLIRTranslationUnit::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
DLHLIR_ELEMENT_TYPE etp = el->GetHLIRElementType();
DLHLIR_ELEMENT_CATEGORY ect = el->GetHLIRElementCategory();
	if ( ctx == DLE_NotApplicable ){
		switch(etp){
			case DL_Declaration:
			case DL_TypeDeclaration:
				context = 0;
				break;
			case DL_FunctionDefinition:
				context = 1;
				break;
			default:	;
		}
	}
	else{
		context = MapContext(ctx);
	}
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIRTranslationUnit::MapContext(DLHLIR_CONTEXT ctx){
	switch(ctx){
		case DL_TranslationUnit_Declaration:
			return 0;
		break;
		case DL_TranslationUnit_FunctionDefinition:
			return 1;
		break;
		default: ; 
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRTranslationUnit::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_TranslationUnit_Declaration;
			break;	
		case 1:
			return DL_TranslationUnit_FunctionDefinition;
			break;		
		default:
			return DL_TranslationUnit_Declaration; //?XX?
	}
}
CDHLIRSyntaxElement *CD_HLIRTranslationUnit::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CD_HLIRFunctionDefinition::CD_HLIRFunctionDefinition()
:CDHLIRSyntaxElement(4),m_Descriptor((CDHLIR_FunDefDescriptor *&)(CDHLIRSyntaxElement::m_Descriptor)){
	m_Descriptor = new CDHLIR_FunDefDescriptor(this);
	m_CompoundStatement = new CS_HLIRCompoundStatement;
	m_FunctionDeclarator = new CT_HLIRFunctionType;
	InstallContextElement(m_FunctionDeclarator);
	InstallContextElement(m_CompoundStatement);
}
CD_HLIRFunctionDefinition::CD_HLIRFunctionDefinition(const CD_HLIRFunctionDefinition &init)
:CDHLIRSyntaxElement(init),m_Descriptor((CDHLIR_FunDefDescriptor *&)(CDHLIRSyntaxElement::m_Descriptor)){
}
CD_HLIRFunctionDefinition::~CD_HLIRFunctionDefinition(){
}
int CD_HLIRFunctionDefinition::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
DLHLIR_ELEMENT_TYPE etp = el->GetHLIRElementType();
DLHLIR_ELEMENT_CATEGORY ect = el->GetHLIRElementCategory();

 	if ( ctx == DLE_NotApplicable ){
 		if ( etp  == DLT_FunctionType ){
 			context = MapContext(DL_FunctionDefinition_Declarator);
 		}
 		else if ( etp  == DLE_IDENTIFIER ){
 			m_FunctionDeclarator->InstallContextElement(el);
 			el->SetParent(m_FunctionDeclarator);
 			return -1;
 		}
 		else if ( ect == DLCAT_STATEMENT && !(etp == DLS_Compound )){
 			m_CompoundStatement->InstallContextElement(el);
 			el->SetParent(m_CompoundStatement);
 			return -1;
 		}
		else if ( ect == DLCAT_STATEMENT && etp == DLS_Compound ){
			context = MapContext(DL_FunctionDefinition_CompoundStatement);			
		}
 		else{
			cout << endl << "Error!!! Cannot install a " << g_DLHLIRtypeidentifier[el->GetHLIRElementType()]
			<< " to a " << g_DLHLIRtypeidentifier[GetHLIRElementType()];
 		}
 	}	
 	else {	
 		context= MapContext(ctx);
 	 }
 	if ( !placebefore ){
 		m_Context[context]->push_back(el);
 	}
 	else{
 		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIRFunctionDefinition::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){		
		case DL_FunctionDefinition_TypeSpecifiers:
			return 0;
			break;
		case DL_FunctionDefinition_Declarator:
			return 1;
			break;
		case DL_FunctionDefinition_CompoundStatement:
			return 2;
			break;
		case DL_FunctionDefinition_TypeQualifiers:
			return 3;
			break;
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRFunctionDefinition::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_FunctionDefinition_TypeSpecifiers;
			break;				
		case 1: 
			return DL_FunctionDefinition_Declarator;
			break;
		case 2:
			return DL_FunctionDefinition_CompoundStatement;
			break;
		case 3:
			return DL_FunctionDefinition_TypeQualifiers;
			break;
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIRFunctionDefinition::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CDS_HLIRExressionStatement::CDS_HLIRExressionStatement()
:CDHLIR_Statement(1){
	m_Descriptor = new CDHLIR_GPDescriptor(DLS_ExpressionStatement,DLCAT_STATEMENT);
}
CDS_HLIRExressionStatement::CDS_HLIRExressionStatement(const CDS_HLIRExressionStatement &init)
:CDHLIR_Statement(init){
}
CDS_HLIRExressionStatement::~CDS_HLIRExressionStatement(){
}
int CDS_HLIRExressionStatement::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx != DLE_NotApplicable){
		context = MapContext(ctx);
		if ( context == 0 ){ //LHS
			Helper_ExceptionIfNotInHLIRCategory(DLCAT_EXPRESSION,DLERR_EXIT,
			"\nError in CS_HLIRExressionStatement::InstallContextElement",1,el);			
		}
		else{
			cout << endl << "Error!!! Cannot install a " << g_DLHLIRtypeidentifier[el->GetHLIRElementType()]
				 << " to a " << g_DLHLIRtypeidentifier[el->GetHLIRElementType()];
		}			
	}
	else{
		Helper_ExceptionIfNotInHLIRCategory(DLCAT_EXPRESSION,DLERR_EXIT,
		"\nError in CS_HLIRExressionStatement::InstallContextElement",1,el);			
		context = MapContext(DLS_ExpressionStatement_Expression);		
	}
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CDS_HLIRExressionStatement::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){		
		case DLS_ExpressionStatement_Expression:
			return 0;
		break;		
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CDS_HLIRExressionStatement::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DLS_ExpressionStatement_Expression;
			break;					
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CDS_HLIRExressionStatement::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CS_HLIRCompoundStatement::CS_HLIRCompoundStatement()
:CDHLIR_Statement(2){
	m_Descriptor = new CDHLIR_GPDescriptor(DLS_Compound,DLCAT_STATEMENT);
}
CS_HLIRCompoundStatement::CS_HLIRCompoundStatement(const CS_HLIRCompoundStatement &init)
:CDHLIR_Statement(init){
}
CS_HLIRCompoundStatement::~CS_HLIRCompoundStatement(){
}
int CS_HLIRCompoundStatement::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx != DLE_NotApplicable){
		context = MapContext(ctx);	
	}
	else{
		if ( el->GetHLIRElementType() == DL_Declaration){
			context = MapContext(DLS_CompoundStatement_Declarations);				
		}
		else if ( el->GetHLIRElementCategory() == DLCAT_STATEMENT ){
			context = MapContext(DLS_CompoundStatement_Statements);				
		}
	}	
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CS_HLIRCompoundStatement::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){
		case DLS_CompoundStatement_Declarations:
			return 0;
			break;	
		case DLS_CompoundStatement_Statements:
			return 1;
			break;
		default:
			return -1;
	}
}
DLHLIR_CONTEXT CS_HLIRCompoundStatement::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DLS_CompoundStatement_Declarations;
			break;	
		case 1:
			return DLS_CompoundStatement_Statements;	
			break;		
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CS_HLIRCompoundStatement::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}

// ========================================================================
CD_HLIRDeclaration::CD_HLIRDeclaration()
:CDHLIRSyntaxElement(3){
	m_Descriptor = new CDHLIR_GPDescriptor(DL_Declaration /*,CAT_NOTINITIALIZED*/);
	m_StorageClass = DLSCT_UNITIALIZED;
	m_FunctionSpecifier = DLFSP_UNITIALIZED;
}
CD_HLIRDeclaration::CD_HLIRDeclaration(const CD_HLIRDeclaration &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIRDeclaration::~CD_HLIRDeclaration(){
}
int CD_HLIRDeclaration::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	// CONTEXTS
	// _Declaration_Declarators,
	// _Declaration_TypeSpecifiers
	if ( ctx == DLE_NotApplicable ){
	  switch(el->GetHLIRElementType()){
			case DL_Declarator:
			case DLT_ArrayType:
			case DLT_PointerType:
			case DLT_FunctionType:			
			case DLE_IDENTIFIER:			
				context = MapContext(DL_Declaration_Declarators );
				break;			
			case DL_TypeSpecifier:
				context = MapContext(DL_Declaration_TypeSpecifiers);
				break;
			case DL_TypeQualifier:
				context = MapContext(DL_Declaration_TypeQualifiers);
				break;
			default:
				context = -1;
	  }		
	}
	else {	
	  context= MapContext(ctx);
	}
	if ( !placebefore ){
	  m_Context[context]->push_back(el);
	}
	else{
	  m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIRDeclaration::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){
		case DL_Declaration_Declarators:
			return 1;
		case DL_Declaration_TypeSpecifiers:
			return 0;
		case DL_Declaration_TypeQualifiers:
			return 2;
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRDeclaration::MapIndextoContext(int ix){
	switch(ix){
		case 1:
			return DL_Declaration_Declarators;
			break;				
		case 0:
			return DL_Declaration_TypeSpecifiers;
			break;
		case 2:
			return DL_Declaration_TypeQualifiers;
			break;
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIRDeclaration::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
void CD_HLIRDeclaration::SetHLIRElementType(DLHLIR_ELEMENT_TYPE tp){

	if ( tp == DL_TypeDeclaration || tp == DL_Declaration ){
		m_Descriptor->m_HLIRSyntaxElementType = tp;
		if ( m_Descriptor->m_HLIRGraphvizID != NULL ){
			delete [] m_Descriptor->m_HLIRGraphvizID;			
		}
		m_Descriptor->m_HLIRGraphvizID = InitHLIRElementTypeString();
	}
	else{
		cout << endl << "Warning attempt to give a false code to a declaration object"
			<< endl << "Error Location :CD_HLIRDeclaration::SetDeclarationType";
	}
}
void CD_HLIRDeclaration::InstallPropertyMessage(MESSAGE_TYPE msg){
	switch(msg){
		case MSG_STORAGE_CLASS:
			if ( m_StorageClass != DLSCT_UNITIALIZED ){
				cout << endl << "One storage class specifier is allowed"
					<< endl << "Error in function CD_HLIRDeclaration::InstallPropertyMessage";				
				exit(0);
			}
			m_StorageClass = g_storage_class;
		break;
		case MSG_FUNCTION_SPECIFIER:
			m_FunctionSpecifier =  DLFSP_INLINE;
		break;
		default:;		
	}
}
void CD_HLIRDeclaration::SeekNestedDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
CDHLIRSyntaxElement *ident, *desc;
	desc = GetContextElement(DL_Declaration_Declarators);
	if ( desc != NULL ){
		desc->SeekDeclarator(ident);	
		ident->SeekDeclaratorType(tpinfo,NULL);
	}
	else{
		SeekDeclaratorType(tpinfo,NULL);
	}	
}
void CD_HLIRDeclaration::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
CDHLIRSyntaxElement *obj;
CDE_HLIRIDENTIFIER *ident;
class type_info_ *type_info_ = NULL;
class type_info_ *current_type_info;
unsigned int contts = MapContext(DL_Declaration_TypeSpecifiers);
unsigned int contdc = MapContext(DL_Declaration_Declarators);
//DL_Declaration_Declarators
	
	
	
	
// 	obj = GetContextElement(DL_Declaration_Declarators,0);
// 	if ( obj && obj->GetHLIRElementType() == DL_Declarator){
// 		obj->SeekDeclaratorIdentifier(ident);
// 		ident->SeekDeclaratorType(tpinfo,this);		
// 	}
// 	else{
// 		
// 	}
// 
	for ( obj = tbegin(contts);
		        !ttend(contts); obj = tnext(contts)  ){
		obj->SeekDeclaratorType(tpinfo, this);	        
 	}
	
}
// ========================================================================
CD_HLIRTypeQualifier::CD_HLIRTypeQualifier(DLTYPE_QUALIFIER tq)
:CDHLIRSyntaxElement(1){
	m_TypeQualifier = tq;
	m_Descriptor = new CDHLIR_GPDescriptor(DL_TypeQualifier /*,CAT_NOTINITIALIZED*/);
	m_Descriptor->SetHLIRObjectGraphVizID(InitHLIRElementTypeString());
}
CD_HLIRTypeQualifier::CD_HLIRTypeQualifier(const CD_HLIRTypeQualifier &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIRTypeQualifier::~CD_HLIRTypeQualifier(){
}
int CD_HLIRTypeQualifier::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx != DLE_NotApplicable){
		context = MapContext(ctx);
	}
	else{
		switch(el->GetHLIRElementType()){	
			case DLE_IDENTIFIER:		
			case DLT_PointerType: // pointer to pointer
			case DLT_ArrayType:   // array of pointers
			case DLT_FunctionType:// function returning pointer to ...
				context = MapContext(DL_TypeQualifier_TypeExpression);
			break;
			default:;
		}
	} 
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIRTypeQualifier::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){		
		case DL_TypeQualifier_TypeExpression:
			return 0;
		break;
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRTypeQualifier::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_TypeQualifier_TypeExpression;
			break;			
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIRTypeQualifier::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
char *CD_HLIRTypeQualifier::InitHLIRElementTypeString(){
string s,s1;
char *buffer;
	buffer = new char[10];
	_itoa_s(m_Descriptor->GetObjectSerialNumber(),buffer,10,10);
	s1= (string)buffer;
	s= (string)g_DLHLIRtypeidentifier[GetHLIRElementType()] + "_" +
	   (string)g_DLtype_qualifier_string[m_TypeQualifier]+ "_" +s1;
return DLStrDup_cpp(s.c_str());
}
void CD_HLIRTypeQualifier::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	class type_info_ *id_type_info;	
}
// ========================================================================
CD_HLIRTypeSpecifiers::CD_HLIRTypeSpecifiers()
:CDHLIRSyntaxElement(1){
	m_Descriptor = new CDHLIR_GPDescriptor(DL_TypeSpecifier /*,CAT_NOTINITIALIZED*/);
	m_Descriptor->SetHLIRObjectGraphVizID(InitHLIRElementTypeString());
}
CD_HLIRTypeSpecifiers::CD_HLIRTypeSpecifiers(const CD_HLIRTypeSpecifiers &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIRTypeSpecifiers::~CD_HLIRTypeSpecifiers(){
}
int CD_HLIRTypeSpecifiers::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx != DLE_NotApplicable){
		context = MapContext(ctx);
	}
	else{
		switch(el->GetHLIRElementType()){	
			case DLT_VoidType:
			case DLT_IntegerType:
			case DLT_FloatingPointType:
			case DLT_CharacterType:	
			case DLT_StructureType_Def:
			case DLT_StructureType_Decl:
			case DLT_UnionType_Def:	
			case DLT_UnionType_Decl:
			case DLT_EnumeratedType_Decl:	
			case DLT_EnumeratedType_Def:	
			case DLE_IDENTIFIER:					
				context = MapContext(DL_TypeSpecifier_TypeName);
				break;
			default:;
		}
	} 
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIRTypeSpecifiers::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){		
		case DL_TypeSpecifier_TypeName:
			return 0;
			break;
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRTypeSpecifiers::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_TypeSpecifier_TypeName;
			break;			
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIRTypeSpecifiers::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
char *CD_HLIRTypeSpecifiers::InitHLIRElementTypeString(){
string s,s1;
char *buffer;
	buffer = new char[10];
	_itoa_s(m_Descriptor->m_HLIRObjectSerialNumber,buffer,10,10);
	s1= (string)buffer;
	s= (string)g_DLHLIRtypeidentifier[m_Descriptor->m_HLIRSyntaxElementType] + "_" +s1;	
return DLStrDup_cpp(s.c_str());
}
void CD_HLIRTypeSpecifiers::InstallPropertyMessage(MESSAGE_TYPE msg){
	switch(msg){
		case MSG_TYPE_SPECIFIER:
			m_TypeSpecifiers.push_back(g_type_specifier);	
			break;		
		default:;		
	}
}
CDHLIRSyntaxElement * CD_HLIRTypeSpecifiers::DeduceCreateTypeSpecification(){
list<DLTYPE_SPECIFIERS>::iterator it;
CDHLIRSyntaxElement *new_object;
unsigned int i,j,pos;
bool match = false;

	if ( m_TypeSpecifiers.empty() ){
		return NULL;
	}
	else if ( m_TypeSpecifiers.front() == DLTSP_TYPENAME){
		return NULL;
	}
	else{
	i = 0;
		while( !match && DLg_type_specs[i].m_bitwidth != -1 ){
			match = true; pos = i;		
			for ( j=0,it = m_TypeSpecifiers.begin(); 
				j<5,it != m_TypeSpecifiers.end();j++, it++){
					if ( (*it) != DLg_type_specs[i].m_typespecifier[j]){
						match = false;
						pos =-1; // Indicates that a match is not found causing a 
						// subsequent syntax error
						break;
					}					
			}
			i++;
		}	
		new_object = Helper_Instanciate_Type(pos);
	}
return new_object;
}
void CD_HLIRTypeSpecifiers::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
list<DLTYPE_SPECIFIERS>::iterator it;
CDHLIRSyntaxElement *desc;
int i;
string s;
	for (i=0, it = m_TypeSpecifiers.begin(); it != m_TypeSpecifiers.end();i++, it ++){
		if ( i == 0 ){
			switch ( *it ){
				case DLTSP_VOID:				
				case DLTSP_CHAR:
				case DLTSP_SHORT:
				case DLTSP_LONG:
				case DLTSP_SIGNED:
				case DLTSP_FLOAT:
				case DLTSP_DOUBLE:				
					s = "a ";
				break;
				case DLTSP_INT:				
				case DLTSP_UNSIGNED:
					s = "an ";
				break;
				case DLTSP_TYPENAME:
					s = "a ";
					desc = GetContextElement(DL_TypeSpecifier_TypeName);
					desc->SeekDeclaratorType(tpinfo,this);
					return;
				break;
				default:
					s = "a ";				
			}
			tpinfo->m_DeclaratorUnscrambledType += s + (string)g_DLType_Specifier_Strings[*it] + " ";
		}
		else{
			tpinfo->m_DeclaratorUnscrambledType += (string)g_DLType_Specifier_Strings[*it] + " ";
		}
	}		
}
// ========================================================================
CD_HLIRDeclarator::CD_HLIRDeclarator()
:CDHLIRSyntaxElement(2){
	m_Descriptor = new CDHLIR_GPDescriptor(DL_Declarator /*,CAT_NOTINITIALIZED*/);
}
CD_HLIRDeclarator::CD_HLIRDeclarator(const CD_HLIRDeclarator &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIRDeclarator::~CD_HLIRDeclarator(){
}
int CD_HLIRDeclarator::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx != DLE_NotApplicable){
		context = MapContext(ctx);		
	}
	else{
		switch(el->GetHLIRElementType()){
			case DLT_ArrayType:
			case DLT_PointerType:
			case DLT_FunctionType:			
			case DLE_IDENTIFIER:
				context = MapContext(DL_Declarator_TypeExpression);
			break;
			case DL_Initializer:
			case DLE_CONSTANT:
				context = MapContext(DL_Declarator_Initializer);
			break;
			default:;
		}
		el->SetParent(this);
	} 
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
return context;
}
int CD_HLIRDeclarator::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){		
		case DL_Declarator_TypeExpression:
			return 0;
		break;
		case DL_Declarator_Initializer:
			return 1;
		break;
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRDeclarator::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_Declarator_TypeExpression;
			break;	
		case 1:
			return DL_Declarator_Initializer;
			break;		
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIRDeclarator::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
void CD_HLIRDeclarator::SeekDeclarator(CDHLIRSyntaxElement *&ident){
CDHLIRSyntaxElement *desc;
	desc=GetContextElement(DL_Declarator_TypeExpression);
	desc->SeekDeclarator(ident);
}
void CD_HLIRDeclarator::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	m_parent->SeekDeclaratorType(tpinfo, this);
}
// ========================================================================
CD_HLIRTypename::CD_HLIRTypename()
:CDHLIRSyntaxElement(3){
	m_Descriptor = new CDHLIR_GPDescriptor(DL_Typename ,DLCAT_TYPEEXPRESSION);
}
CD_HLIRTypename::CD_HLIRTypename(const CD_HLIRTypename &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIRTypename::~CD_HLIRTypename(){
}
int CD_HLIRTypename::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx == DLE_NotApplicable ){
		switch(el->GetHLIRElementType()){			
			case DLT_PointerType:
			case DLT_ArrayType:
			case DLT_FunctionType:			
				context = MapContext(DL_Typename_TypeExpression );
				break;
			/*case T_VoidType:
			case T_IntegerType:
			case T_FloatingPointType:
			case T_CharacterType:
			case T_EnumeratedType_Decl:	
			case T_StructureType_Decl:			
			case T_UnionType_Decl:	*/
			case DL_TypeSpecifier:
				context = MapContext(DL_Typename_TypeSpecifiers);
				break;
			case DL_TypeQualifier:
				context = MapContext(DL_Typename_TypeQualifiers);
				//context = MapContext(_Typename_TypeExpression);
				break;
			default:
				context = -1;
		}		
	}
	else {	
		context= MapContext(ctx);
	 }
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIRTypename::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){
		case DL_Typename_TypeSpecifiers:
			return 0;
			break;
		case DL_Typename_TypeExpression:
			return 1;
			break;		
		case DL_Typename_TypeQualifiers:
			return 2;
			break;
		default:;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRTypename::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_Typename_TypeSpecifiers;
			break;	
		case 1:
			return DL_Typename_TypeExpression;
			break;
		case 2:
			return DL_Typename_TypeQualifiers;
			break;			
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIRTypename::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
void CD_HLIRTypename::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	class type_info_ *id_type_info;	
}
// ========================================================================
CD_HLIREnumerator::CD_HLIREnumerator()
:CDHLIRSyntaxElement(2){
	m_Descriptor = new CDHLIR_GPDescriptor(DL_Enumerator /*,CAT_TYPEEXPRESSION*/);
}
CD_HLIREnumerator::CD_HLIREnumerator(const CD_HLIREnumerator &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIREnumerator::~CD_HLIREnumerator(){
}
int CD_HLIREnumerator::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx == DLE_NotApplicable ){
		if ( el->GetHLIRElementType() == DLE_IDENTIFIER ){
			context = MapContext(DL_Enumerator_Identifier); 
		}			
		else if ( el->GetHLIRElementCategory() == DLCAT_EXPRESSION ){
			switch( el->GetHLIRElementType() ){
				case DLE_Assignment:
				case	DLE_AssignmentAddTo:
				case	DLE_AssignmentSubtractFrom:
				case	DLE_AssignmentMultiplyBy:
				case	DLE_AssignmentDivideBy:
				case	DLE_AssignmentModuloBy:
				case	DLE_AssignmentShiftLeftBy:
				case	DLE_AssignmentShiftRightBy:
				case	DLE_AssignmentANDWith:
				case	DLE_AssignmentExclusiveORWith:
				case	DLE_AssignmentInclusiveORWith:
				case	DLE_CommaExpression:
				case DLE_STRINGLITERAL:
					context =-1;
				break;
				default:
					context = MapContext(DL_Enumerator_IntegerInitializer);
			}
		}
	}
	else {	
		context= MapContext(ctx);
	 }
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIREnumerator::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){		
		case DL_Enumerator_Identifier:				
			return 0;
			break;		
		case DL_Enumerator_IntegerInitializer:
			return 1;
			break;
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIREnumerator::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_Enumerator_Identifier;
			break;	
		case 1:
			return DL_Enumerator_IntegerInitializer;
			break;					
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIREnumerator::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
void CD_HLIREnumerator::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
class type_info_ *id_type_info;	
}
// ========================================================================
CD_HLIRInitializer::CD_HLIRInitializer()
:CDHLIRSyntaxElement(1){
	m_Descriptor = new CDHLIR_GPDescriptor(DL_Initializer /*,CAT_TYPEEXPRESSION*/);
}
CD_HLIRInitializer::CD_HLIRInitializer(const CD_HLIRInitializer &init)
:CDHLIRSyntaxElement(init){
}
CD_HLIRInitializer::~CD_HLIRInitializer(){
}
int CD_HLIRInitializer::InstallContextElement( CDHLIRSyntaxElement *el, 
	DLHLIR_CONTEXT ctx/*=E_NotApplicable*/, bool placebefore/*=false*/ ){
int context=-1;
	if ( ctx == DLE_NotApplicable ){
		if ( el->GetHLIRElementType() == DL_Initializer || 
		(el->GetHLIRElementCategory() == DLCAT_EXPRESSION && 
		 el->GetHLIRElementType() != DLE_CommaExpression )){
			context = MapContext(DL_Initializer_Initializers); 
		}			
	}
	else {	
		context= MapContext(ctx);
	 }
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CD_HLIRInitializer::MapContext(DLHLIR_CONTEXT ctx){	
	switch(ctx){		
		case DL_Initializer_Initializers:				
			return 0;
			break;		
		default: ;
	}
return -1;
}
DLHLIR_CONTEXT CD_HLIRInitializer::MapIndextoContext(int ix){
	switch(ix){
		case 0:
			return DL_Initializer_Initializers;
			break;						
		default:
			return DLE_NotApplicable;
	}
}
CDHLIRSyntaxElement *CD_HLIRInitializer::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index/* =0 */){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
void CD_HLIRInitializer::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	class type_info_ *id_type_info;	
}






























// ========================================================================
// ========================================================================
// ========================================================================
// ========================================================================
// 

CDHLIRSyntaxElement *Helper_Instanciate_Type(int pos){
CDHLIRSyntaxElement *new_object;
	switch(pos){
		case 0: // void
			new_object = new CT_HLIRVoidType();
			break;
		case 1: // char
		case 2: // signed char
			new_object = new CT_HLIRCharacterType(DLSGN_SIGNED,pos);
			break;
		case 3: // unsigned char
			new_object = new CT_HLIRCharacterType(DLSGN_UNSIGNED,pos);
			break;
		case 4:  // short
		case 5:  // signed short
		case 6:  // short int
		case 7: // signed short int
			new_object = new CT_HLIRIntegerType(DLSGN_SIGNED,DLPRC_SHORT,pos);
			break;
		case 8: //unsigned short
		case 9: //unsigned short int
			new_object = new CT_HLIRIntegerType(DLSGN_UNSIGNED,DLPRC_SHORT,pos);
			break;
		case 10: // int 
		case 11: // signed
		case 12: // signed int		
			new_object = new CT_HLIRIntegerType(DLSGN_SIGNED,DLPRC_REGULAR,pos);
			break;
		case 15: // long
		case 16: // signed long
		case 17: // long int
		case 18: // signed long int
			new_object = new CT_HLIRIntegerType(DLSGN_SIGNED,DLPRC_LONG,pos);
			break;
		case 13: //unsigned
		case 14: //unsigned int		
			new_object = new CT_HLIRIntegerType(DLSGN_UNSIGNED,DLPRC_REGULAR,pos);
			break;
		case 19: // unsigned long
		case 20: // unsigned long int
			new_object = new CT_HLIRIntegerType(DLSGN_UNSIGNED,DLPRC_LONG,pos);
			break;
		case 21: // long long
		case 22: // signed long long
		case 23: // long long int
		case 24: // signed long long int
			new_object = new CT_HLIRIntegerType(DLSGN_SIGNED,DLPRC_LONGLONG,pos);
			break;
		case 25: // unsigned long long
		case 26: // unsigned long long int
			new_object = new CT_HLIRIntegerType(DLSGN_UNSIGNED,DLPRC_LONGLONG,pos);
			break;
		case 27: //float
			new_object = new CT_HLIRFloatingType(DLFPRC_FLOAT,pos);
			break;
		case 28: //double
			new_object = new CT_HLIRFloatingType(DLFPRC_DOUBLE,pos);
			break;
		case 29: // long double
			new_object = new CT_HLIRFloatingType(DLFPRC_LONGDOUBLE,pos);
			break;
		default:
			new_object = NULL;			
	}
return new_object;
}

CT_HLIRType::CT_HLIRType()
:CDHLIRSyntaxElement((unsigned int)0){
	m_type_specification_index = -1;
}
CT_HLIRType::CT_HLIRType(unsigned int num_contexts)
:CDHLIRSyntaxElement(num_contexts){	
	m_type_specification_index = -1;
}
CT_HLIRType::CT_HLIRType(CT_HLIRBasicType *TypeSpecifier, CT_HLIRDerivedType *Declarator)
:CDHLIRSyntaxElement(2){	
	m_type_specification_index = -1;
}
CT_HLIRType::CT_HLIRType(const CT_HLIRType &Init)
:CDHLIRSyntaxElement(Init){	
	m_type_specification_index = Init.m_type_specification_index;
}
CT_HLIRType::~CT_HLIRType(){}

CT_HLIRBasicType::CT_HLIRBasicType(unsigned int num_contexts /*=0*/)
:CT_HLIRType(num_contexts){}
CT_HLIRBasicType::CT_HLIRBasicType(const CT_HLIRBasicType &Init)
:CT_HLIRType(Init){}
CT_HLIRBasicType::~CT_HLIRBasicType(){}

CT_HLIRDerivedType::CT_HLIRDerivedType(unsigned int num_contexts)
:CT_HLIRType(num_contexts){}
CT_HLIRDerivedType::CT_HLIRDerivedType(const CT_HLIRDerivedType &Init)
:CT_HLIRType(Init){
}
CT_HLIRDerivedType::~CT_HLIRDerivedType(){}

CT_HLIRIntegerCategoryType::CT_HLIRIntegerCategoryType(DLINTEGER_SIGNNESS sgn,
											DLINTEGER_PRECISION prec,
											unsigned int num_contexts/*=0*/)
:CT_HLIRBasicType(num_contexts){
	m_precision = prec;	
	m_signness = sgn;
}
CT_HLIRIntegerCategoryType::CT_HLIRIntegerCategoryType(const CT_HLIRIntegerCategoryType &Init)
:CT_HLIRBasicType(Init){
	m_signness = Init.m_signness;
	m_precision = Init.m_precision;
}
CT_HLIRIntegerCategoryType::~CT_HLIRIntegerCategoryType(){}
void CT_HLIRIntegerCategoryType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
class type_info_ *id_type_info;	
}

CT_HLIRVoidType::CT_HLIRVoidType()
:CT_HLIRBasicType(){
	m_type_specification_index = 0;	
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_VoidType,DLCAT_TYPEEXPRESSION);		
}
CT_HLIRVoidType::CT_HLIRVoidType(const CT_HLIRVoidType &Init)
:CT_HLIRBasicType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 	
}
CT_HLIRVoidType::~CT_HLIRVoidType(){}
char *CT_HLIRVoidType::GetHLIRElementTypeString(){
string s,s1;
char *buffer;
	buffer = new char[10];
	_itoa_s(m_Descriptor->m_HLIRObjectSerialNumber,buffer,10,10);
	s1 = (string)buffer;
	s =  (string)(DLg_type_specs[m_type_specification_index].m_GraphvizFrientlyString) + s1;
	delete [] buffer;
return _strdup(s.c_str());
}
void CT_HLIRVoidType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
class type_info_ *id_type_info;	
}
// ========================================================================
CT_HLIRIntegerType::CT_HLIRIntegerType(DLINTEGER_SIGNNESS sgn,
								DLINTEGER_PRECISION prec,
								unsigned int idx)
:CT_HLIRIntegerCategoryType(sgn,prec){
	m_type_specification_index = idx;
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_IntegerType,DLCAT_TYPEEXPRESSION);	
}
CT_HLIRIntegerType::CT_HLIRIntegerType(const CT_HLIRIntegerType &Init)
:CT_HLIRIntegerCategoryType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 	
}
char *CT_HLIRIntegerType::GetHLIRElementTypeString(){
string s,s1;
char *buffer;
	buffer = new char[10];
	_itoa_s(m_Descriptor->m_HLIRObjectSerialNumber,buffer,10,10);
	s1 = (string)buffer;
	s =  (string)(DLg_type_specs[m_type_specification_index].m_GraphvizFrientlyString) + s1;
	delete [] buffer;
return _strdup(s.c_str());
}
CT_HLIRIntegerType::~CT_HLIRIntegerType(){}
// ========================================================================
CT_HLIRFloatingType::CT_HLIRFloatingType(DLFLOATING_PRECISION prec,
								 unsigned int idx)
:CT_HLIRBasicType(){
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_FloatingPointType,DLCAT_TYPEEXPRESSION);		
	m_precision = prec;
	m_type_specification_index = idx;		
}
CT_HLIRFloatingType::CT_HLIRFloatingType(const CT_HLIRFloatingType &Init)
:CT_HLIRBasicType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 
}
CT_HLIRFloatingType::~CT_HLIRFloatingType(){}
void CT_HLIRFloatingType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	class type_info_ *id_type_info;	
}
char *CT_HLIRFloatingType::GetHLIRElementTypeString(){
string s,s1;
char *buffer;
	buffer = new char[10];
	_itoa_s(m_Descriptor->m_HLIRObjectSerialNumber,buffer,10,10);
	s1 = (string)buffer;
	s =  (string)(DLg_type_specs[m_type_specification_index].m_GraphvizFrientlyString) + s1;
	delete [] buffer;
return _strdup(s.c_str());
}
// ========================================================================
CT_HLIRCharacterType::CT_HLIRCharacterType(DLINTEGER_SIGNNESS sgn,
								   unsigned int idx)
:CT_HLIRIntegerCategoryType(sgn,DLPRC_CHAR){
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_CharacterType,DLCAT_TYPEEXPRESSION);	
	m_type_specification_index = idx;		
	
}
CT_HLIRCharacterType::CT_HLIRCharacterType(const CT_HLIRCharacterType &Init)
:CT_HLIRIntegerCategoryType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor));
}
CT_HLIRCharacterType::~CT_HLIRCharacterType(){}
char *CT_HLIRCharacterType::GetHLIRElementTypeString(){
string s,s1;
char *buffer;
	buffer = new char[10];
	_itoa_s(m_Descriptor->m_HLIRObjectSerialNumber,buffer,10,10);
	s1 = (string)buffer;
	s =  (string)(DLg_type_specs[m_type_specification_index].m_GraphvizFrientlyString) + s1;
	delete [] buffer;
return _strdup(s.c_str());
}
void CT_HLIRCharacterType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	class type_info_ *id_type_info;	
}
// ========================================================================
CT_HLIREnumeratedType::CT_HLIREnumeratedType(DLHLIR_ELEMENT_TYPE tp)
:CT_HLIRIntegerCategoryType(DLSGN_SIGNED,DLPRC_REGULAR,2){
	m_Descriptor = new CDHLIR_GPDescriptor(tp,DLCAT_TYPEEXPRESSION);		
}
CT_HLIREnumeratedType::CT_HLIREnumeratedType(CDHLIRSyntaxElement *tagid,
											 list<CDHLIRSyntaxElement *> *enumlst)
:CT_HLIRIntegerCategoryType(DLSGN_SIGNED,DLPRC_REGULAR,2){
list<CDHLIRSyntaxElement *>::iterator it;
	
	if ( enumlst != NULL ){
		m_Descriptor = new CDHLIR_GPDescriptor(DLT_EnumeratedType_Def,DLCAT_TYPEEXPRESSION);		
		for ( it = enumlst->begin(); it != enumlst->end(); it ++ ){
			InstallContextElement(*it,DLT_EnumeratedType_Enumerators);
			(*it)->SetParent(this);
		}
		if ( tagid != NULL ){
			InstallContextElement(tagid,DLT_EnumeratedType_Identifier);
			tagid->SetParent(this);
		}
	}
	else{
		m_Descriptor = new CDHLIR_GPDescriptor(DLT_EnumeratedType_Decl,DLCAT_TYPEEXPRESSION);	
		m_Descriptor->m_HLIRSyntaxElementType = DLT_EnumeratedType_Decl;
		InstallContextElement(tagid,DLT_EnumeratedType_Identifier);
		tagid->SetParent(this);
	}	
}
CT_HLIREnumeratedType::~CT_HLIREnumeratedType(){}
CT_HLIREnumeratedType::CT_HLIREnumeratedType(const CT_HLIREnumeratedType &Init)
:CT_HLIRIntegerCategoryType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 
}
int CT_HLIREnumeratedType::MapContext(DLHLIR_CONTEXT ctx){
	switch (ctx){
		case DLT_EnumeratedType_Identifier:
			return 0;
		case DLT_EnumeratedType_Enumerators:
			return 1;
		default:
			return -1;
	}
return -1;
}
DLHLIR_CONTEXT CT_HLIREnumeratedType::MapIndextoContext(int ctx){
	switch (ctx){
		case 0:
			return DLT_EnumeratedType_Identifier;
		case 1:
			return DLT_EnumeratedType_Enumerators;
		default:;			
	}
	return DLE_NotApplicable;
}
int CT_HLIREnumeratedType::InstallContextElement(CDHLIRSyntaxElement *el, 
									    DLHLIR_CONTEXT ctx/* = E_NotApplicable */, bool placebefore){
int context=-1;
	switch(el->GetHLIRElementType()){		
		case DLE_IDENTIFIER:
			context = MapContext(DLT_EnumeratedType_Identifier);
		break;
		case DL_Enumerator:
			context = MapContext(DLT_EnumeratedType_Enumerators);
		break;
		default:;
	}
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
void CT_HLIREnumeratedType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
	class type_info_ *id_type_info;	
}
CDHLIRSyntaxElement *CT_HLIREnumeratedType::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index /* =0 */ ){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CT_HLIRArrayType::CT_HLIRArrayType()
:CT_HLIRDerivedType(2){
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_ArrayType,DLCAT_TYPEEXPRESSION);	
}
CT_HLIRArrayType::CT_HLIRArrayType(CDHLIRSyntaxElement *arrtp, CDHLIRSyntaxElement *arrsz)
:CT_HLIRDerivedType(2){
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_ArrayType,DLCAT_TYPEEXPRESSION);		
	InstallContextElement(arrtp,DLT_ArrayType_ElementType);
	arrtp->SetParent(this);
	InstallContextElement(arrsz,DLT_ArrayType_ArraySize);
	arrsz->SetParent(this);
}
CT_HLIRArrayType::CT_HLIRArrayType(const CT_HLIRArrayType &Init)
:CT_HLIRDerivedType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 
}
CT_HLIRArrayType::~CT_HLIRArrayType(){}
int CT_HLIRArrayType::MapContext(DLHLIR_CONTEXT ctx){
	switch (ctx){
		case DLT_ArrayType_ElementType:
			return 0;
		case DLT_ArrayType_ArraySize:
			return 1;
		default:
			return -1;
	}
}
DLHLIR_CONTEXT CT_HLIRArrayType::MapIndextoContext(int ctx){
	switch (ctx){
		case 0:
			return DLT_ArrayType_ElementType;
		case 1:
			return DLT_ArrayType_ArraySize;
		default:
			return DLE_NotApplicable;
	}
}
int CT_HLIRArrayType::InstallContextElement(CDHLIRSyntaxElement *el, 
											DLHLIR_CONTEXT ctx/* = E_NotApplicable */, bool placebefore){
int context=-1;
	switch(el->GetHLIRElementType()){
		case DLT_ArrayType:
		case DLT_FunctionType:
		case DLT_PointerType:		
			context = MapContext(DLT_ArrayType_ElementType);
			state++;
		break;
		case DLE_CONSTANT:
			context = MapContext(DLT_ArrayType_ArraySize);
		break;
		case DLE_IDENTIFIER:
			if ( state == 0 ){
				context = MapContext(DLT_ArrayType_ElementType);
				state++;
			}
			else{
				context = MapContext(DLT_ArrayType_ArraySize);
			}
		break;
		default:
			if ( el->GetHLIRElementCategory() == DLCAT_EXPRESSION){
				context = MapContext(DLT_ArrayType_ArraySize);
			}
	}
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
void CT_HLIRArrayType::SeekDeclarator(CDHLIRSyntaxElement *&ident){
CDHLIRSyntaxElement *desc;
	desc = GetContextElement(DLT_ArrayType_ElementType);
	if ( desc == NULL ){
		ident = this;
	}
	else{
		desc->SeekDeclarator(ident);	
	}
}
void CT_HLIRArrayType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
CDHLIRSyntaxElement *arrsize;
	if( child && child->GetHLIRElementType() == DLT_ArrayType ){
		tpinfo->m_DeclaratorUnscrambledType += "arrays ";
	}
	else{
		tpinfo->m_DeclaratorUnscrambledType += "an array ";
	}
	arrsize = GetContextElement(DLT_ArrayType_ArraySize); 
	if ( arrsize != NULL ){
		tpinfo->m_DeclaratorUnscrambledType += "of ";
		arrsize->SeekDeclaratorType(tpinfo, this);
	}
	m_parent->SeekDeclaratorType(tpinfo, this);
	
}
CDHLIRSyntaxElement *CT_HLIRArrayType::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index /* =0 */ ){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CT_HLIRStructureType::CT_HLIRStructureType(DLHLIR_ELEMENT_TYPE tp)
:CT_HLIRDerivedType(2){
	m_Descriptor = new CDHLIR_GPDescriptor(tp,DLCAT_TYPEEXPRESSION);	
}
CT_HLIRStructureType::CT_HLIRStructureType(list<CDHLIRSyntaxElement *> *decls,
										   CDHLIRSyntaxElement *tag)
:CT_HLIRDerivedType(2){
list<CDHLIRSyntaxElement *>::iterator it;

	
	if ( decls == NULL || decls->empty() ){
		m_Descriptor = new CDHLIR_GPDescriptor(DLT_StructureType_Decl,DLCAT_TYPEEXPRESSION);		
		if ( tag != NULL ){
			InstallContextElement(tag,DLT_StructureType_StructureTag);
			tag->SetParent(this);
		}
		else{
			cout << endl << "Wrong Structure Type declaration";
			exit(0);
		}
	}
	else{
		m_Descriptor = new CDHLIR_GPDescriptor(DLT_StructureType_Def,DLCAT_TYPEEXPRESSION);		
		for ( it = decls->begin(); it!= decls->end(); it ++ ){
			InstallContextElement(*it,DLT_StructureType_Declarations);
			(*it)->SetParent(this);
		}
		if ( tag != NULL ){
			InstallContextElement(tag,DLT_StructureType_StructureTag);
			tag->SetParent(this);
		}
	}		
}
CT_HLIRStructureType::CT_HLIRStructureType(const CT_HLIRStructureType &Init)
:CT_HLIRDerivedType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 
}
int CT_HLIRStructureType::InstallContextElement(CDHLIRSyntaxElement *el,
									    DLHLIR_CONTEXT ctx/* = E_NotApplicable */, bool placebefore){
int context=-1;
	if ( ctx == DLE_NotApplicable ){
		switch(el->GetHLIRElementType()){
			case DL_Declaration:
				context = MapContext(DLT_StructureType_Declarations);
			break;
			case DLE_IDENTIFIER:
				context = MapContext(DLT_StructureType_StructureTag);
			break;
			default:;
		}
	}
	else{
		context = MapContext(ctx);
	}
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
CT_HLIRStructureType::~CT_HLIRStructureType(){}
int CT_HLIRStructureType::MapContext(DLHLIR_CONTEXT ctx){
	switch(ctx){
		case DLT_StructureType_StructureTag:
			return 0;
		break;
		case DLT_StructureType_Declarations:
			return 1;
		break;
		default:;
	}
return -1;
}
DLHLIR_CONTEXT CT_HLIRStructureType::MapIndextoContext(int ctx){
	switch(ctx){
		case 0:
			return DLT_StructureType_StructureTag;
			break;
		case 1:
			return DLT_StructureType_Declarations;
			break;
		default:;
	}	
return DLE_NotApplicable;
}
void CT_HLIRStructureType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
CDHLIRSyntaxElement *tag, *declaration;
string tagname;
unsigned int cont, i;
	tpinfo->m_DeclaratorUnscrambledType += "struct ";
	tag = GetContextElement(DLT_StructureType_StructureTag);
	if ( tag != NULL ){
		tpinfo->m_DeclaratorUnscrambledType += "with tag ";
		if ( tag->GetHLIRElementType() == DLE_IDENTIFIER ){
			tagname = ((CDE_HLIRIDENTIFIER *)tag)->GetIdentifierString();
			tpinfo->m_DeclaratorUnscrambledType += tagname + " ";
		}
	}
	
	declaration = GetContextElement(DLT_StructureType_Declarations);
	if( declaration != NULL && declaration->GetHLIRElementType() == DL_Declaration ){
		tpinfo->m_DeclaratorUnscrambledType += "{";
		cont = MapContext(DLT_StructureType_Declarations);
		for (i=0, declaration = tbegin(cont); !ttend(cont);i++, declaration = tnext(cont)){
			if ( i > 0){
				tpinfo->m_DeclaratorUnscrambledType += ", ";
			}
			((CD_HLIRDeclaration *)declaration)->SeekNestedDeclaratorType(tpinfo,this);	
		}
		tpinfo->m_DeclaratorUnscrambledType += "}";
	}
}
CDHLIRSyntaxElement *CT_HLIRStructureType::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index /* =0 */ ){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CT_HLIRUnionType::CT_HLIRUnionType(DLHLIR_ELEMENT_TYPE tp)
:CT_HLIRDerivedType(2){	
	m_Descriptor = new CDHLIR_GPDescriptor(tp,DLCAT_TYPEEXPRESSION);		
}
CT_HLIRUnionType::CT_HLIRUnionType(list<CDHLIRSyntaxElement *> *decls,
										   CDHLIRSyntaxElement *tag)
:CT_HLIRDerivedType(2){
list<CDHLIRSyntaxElement *>::iterator it;

	if ( decls == NULL || decls->empty() ){
		m_Descriptor = new CDHLIR_GPDescriptor(DLT_UnionType_Decl,DLCAT_TYPEEXPRESSION);		
		if ( tag != NULL ){
			InstallContextElement(tag,DLT_UnionType_UnionTag);
			tag->SetParent(this);
		}
		else{
			cout << endl << "Wrong Union Type declaration";
			exit(0);
		}
	}
	else{
		m_Descriptor = new CDHLIR_GPDescriptor(DLT_UnionType_Def,DLCAT_TYPEEXPRESSION);		
		for ( it = decls->begin(); it!= decls->end(); it ++ ){
			InstallContextElement(*it,DLT_UnionType_Declarations);
			(*it)->SetParent(this);
		}
		if ( tag != NULL ){
			InstallContextElement(tag,DLT_UnionType_UnionTag);
			tag->SetParent(this);
		}
	}		
}
CT_HLIRUnionType::CT_HLIRUnionType(const CT_HLIRUnionType &Init)
:CT_HLIRDerivedType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 
}
int CT_HLIRUnionType::InstallContextElement(CDHLIRSyntaxElement *el,
									    DLHLIR_CONTEXT ctx/* = E_NotApplicable */, bool placebefore){
int context=-1;
	if ( ctx == DLE_NotApplicable ){
		switch(el->GetHLIRElementType()){
			case DL_Declaration:
				context = MapContext(DLT_UnionType_Declarations);
			break;
			case DLE_IDENTIFIER:
				context = MapContext(DLT_UnionType_UnionTag);
			break;
			default:;
		}
	}
	else{
		context = MapContext(ctx);
	}
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
int CT_HLIRUnionType::MapContext(DLHLIR_CONTEXT ctx){
	switch(ctx){
		case DLT_UnionType_UnionTag:
			return 0;
			break;
		case DLT_UnionType_Declarations:
			return 1;
			break;
		default:;
	}
return -1;
}
DLHLIR_CONTEXT CT_HLIRUnionType::MapIndextoContext(int ctx){
	switch(ctx){
		case 0:
			return DLT_UnionType_UnionTag;
			break;
		case 1:
			return DLT_UnionType_Declarations;
			break;
		default:;
	}	
return DLE_NotApplicable;
}
CT_HLIRUnionType::~CT_HLIRUnionType(){}
void CT_HLIRUnionType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){
CDHLIRSyntaxElement *tag, *declaration;
string tagname;
unsigned int cont, i;
	tpinfo->m_DeclaratorUnscrambledType += "a union ";
	tag = GetContextElement(DLT_UnionType_UnionTag);
	if ( tag != NULL ){
		tpinfo->m_DeclaratorUnscrambledType += "with tag ";
		if ( tag->GetHLIRElementType() == DLE_IDENTIFIER ){
			tagname = ((CDE_HLIRIDENTIFIER *)tag)->GetIdentifierString();
			tpinfo->m_DeclaratorUnscrambledType += tagname + " ";
		}
	}
	
	declaration = GetContextElement(DLT_UnionType_Declarations);
	if( declaration != NULL && declaration->GetHLIRElementType() == DL_Declaration ){
		tpinfo->m_DeclaratorUnscrambledType += "{";
		cont = MapContext(DLT_UnionType_Declarations);
		for (i=0, declaration = tbegin(cont); !ttend(cont);i++, declaration = tnext(cont)){
			if ( i > 0){
				tpinfo->m_DeclaratorUnscrambledType += ", ";
			}
			((CD_HLIRDeclaration *)declaration)->SeekNestedDeclaratorType(tpinfo,this);	
		}
		tpinfo->m_DeclaratorUnscrambledType += "}";
	}
}
CDHLIRSyntaxElement *CT_HLIRUnionType::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index /* =0 */ ){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CT_HLIRFunctionType::CT_HLIRFunctionType()
:CT_HLIRDerivedType(2){
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_FunctionType,DLCAT_TYPEEXPRESSION);	
}
CT_HLIRFunctionType::CT_HLIRFunctionType(CDHLIRSyntaxElement *fref,
										 list<CDHLIRSyntaxElement *> *decls)
:CT_HLIRDerivedType(2){
list<CDHLIRSyntaxElement *>::iterator it;
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_FunctionType,DLCAT_TYPEEXPRESSION);
	for ( it = decls->begin(); it!= decls->end(); it++ ){
		InstallContextElement(*it,DLT_FunctionType_Parameters);
		(*it)->SetParent(this);
	}
	InstallContextElement(fref,DLT_FunctionType_FunctionReferenceType);
	fref->SetParent(this);
}
CT_HLIRFunctionType::CT_HLIRFunctionType(const CT_HLIRFunctionType &Init)
:CT_HLIRDerivedType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 
}
CT_HLIRFunctionType::~CT_HLIRFunctionType(){}
int CT_HLIRFunctionType::MapContext(DLHLIR_CONTEXT ctx){
	switch(ctx){
		case DLT_FunctionType_FunctionReferenceType:
		return 0;		
		case DLT_FunctionType_Parameters:
		return 1;
		default:;	
	}
return -1;
}
DLHLIR_CONTEXT CT_HLIRFunctionType::MapIndextoContext(int ctx){
	switch(ctx){
		case 0:
			return DLT_FunctionType_FunctionReferenceType;		
		case 1:
			return DLT_FunctionType_Parameters;
		default:;	
	}
return DLE_NotApplicable;
}
int CT_HLIRFunctionType::InstallContextElement(CDHLIRSyntaxElement *el, 
		  									DLHLIR_CONTEXT ctx/* = E_NotApplicable */, bool placebefore){
int context=-1;
	switch(el->GetHLIRElementType()){
		case DLE_IDENTIFIER:
			if ( ctx == DLT_FunctionType_Parameters ){
				context = MapContext(DLT_FunctionType_Parameters); // old style function definition 
			}
			else{
				// identifier play the role of a declarator
				context = MapContext(DLT_FunctionType_FunctionReferenceType);
				m_Typestring = ((CDE_HLIRIDENTIFIER *)el)->GetIdentifierString();
			}			
		break;
		case DLT_ArrayType:		
		case DLT_PointerType:		
			context = MapContext(DLT_FunctionType_FunctionReferenceType);
		break;
		case DL_Declaration:
			context = MapContext(DLT_FunctionType_Parameters);
		break;
		default:;
	}	
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
void CT_HLIRFunctionType::SeekDeclarator(CDHLIRSyntaxElement *&ident){
CDHLIRSyntaxElement *desc;
	desc = GetContextElement(DLT_FunctionType_FunctionReferenceType);
	if ( desc == NULL ){
		ident = this;
	}
	else{
		desc->SeekDeclarator(ident);	
	}
}
void CT_HLIRFunctionType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){ 
CDHLIRSyntaxElement *obj;
unsigned int cont;
int i;
	tpinfo->m_DeclaratorUnscrambledType += "a function ";
	tpinfo->m_TypeTree.push_back(this);
	cont = MapContext(DLT_FunctionType_Parameters);
	tpinfo->m_DeclaratorUnscrambledType += "( ";
	for (i=0, obj = tbegin(cont); !ttend(cont);i++, obj = tnext(cont)){
		if ( i > 0){
			tpinfo->m_DeclaratorUnscrambledType += ", ";
		}
		if ( obj->GetHLIRElementType() == DL_Declaration ){
			((CD_HLIRDeclaration *)obj)->SeekNestedDeclaratorType(tpinfo,this);	
		}		
	}
	tpinfo->m_DeclaratorUnscrambledType += " ) ";
	tpinfo->m_DeclaratorUnscrambledType += "returning ";
	m_parent->SeekDeclaratorType(tpinfo, this);
}
CDHLIRSyntaxElement *CT_HLIRFunctionType::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index /* =0 */ ){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
// ========================================================================
CT_HLIRPointerType::CT_HLIRPointerType()
:CT_HLIRDerivedType(1){
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_PointerType,DLCAT_TYPEEXPRESSION);		
}
CT_HLIRPointerType::CT_HLIRPointerType(CDHLIRSyntaxElement *tp)
:CT_HLIRDerivedType(1){
	m_Descriptor = new CDHLIR_GPDescriptor(DLT_PointerType,DLCAT_TYPEEXPRESSION);	
	InstallContextElement(tp,DLT_PointerType_PointerType);
	tp->SetParent(this);
}
CT_HLIRPointerType::CT_HLIRPointerType(const CT_HLIRPointerType &Init)
:CT_HLIRDerivedType(Init){
	m_Descriptor  =  new CDHLIR_GPDescriptor(*((CDHLIR_GPDescriptor *)Init.m_Descriptor)); 
}
CT_HLIRPointerType::~CT_HLIRPointerType(){}
int CT_HLIRPointerType::MapContext(DLHLIR_CONTEXT ctx){
	switch(ctx){
		case DLT_PointerType_PointerType:
			return 0;
		default:;
	}
return -1;
}
DLHLIR_CONTEXT CT_HLIRPointerType::MapIndextoContext(int ctx){
	switch(ctx){
		case 0:
			return DLT_PointerType_PointerType;
		default:;
	}
return DLE_NotApplicable;
}
int CT_HLIRPointerType::InstallContextElement(CDHLIRSyntaxElement * el, 
									DLHLIR_CONTEXT ctx/* = E_NotApplicable */, bool placebefore){
int context=-1;
	if ( ctx != DLE_NotApplicable){
		context = MapContext(ctx);
	}
	else{
		switch(el->GetHLIRElementType()){	
			case DLE_IDENTIFIER:		
			case DLT_PointerType: // pointer to pointer
			case DLT_ArrayType: // array of pointers
			case DLT_FunctionType: // function returning pointer to ...
			case DL_TypeQualifier:
				context = MapContext(DLT_PointerType_PointerType);
			break;
			default:;
		}
	} 
	if ( !placebefore ){
		m_Context[context]->push_back(el);
	}
	else{
		m_Context[context]->push_front(el);
	}
	el->SetParent(this);
return context;
}
void CT_HLIRPointerType::SeekDeclarator(CDHLIRSyntaxElement *&ident){
CDHLIRSyntaxElement *desc;
	desc = GetContextElement(DLT_PointerType_PointerType);
	if ( desc == NULL ){
		ident = this;
	}
	else{
		desc->SeekDeclarator(ident);	
	}	
}
void CT_HLIRPointerType::SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child){ 
	if( child && child->GetHLIRElementType() == DLT_ArrayType ){
		tpinfo->m_DeclaratorUnscrambledType += "pointers to ";
	}
	else{
		tpinfo->m_DeclaratorUnscrambledType += "a pointer to ";
	}
	tpinfo->m_TypeTree.push_back(this);	
	m_parent->SeekDeclaratorType(tpinfo, this);	
}
CDHLIRSyntaxElement *CT_HLIRPointerType::GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index /* =0 */ ){
	return DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>::GetContextElement(MapContext(ctx));
}
