#include "CD_HLIRObjectDataBase.h"

unsigned int CDHLIRDescriptor::m_HLIRObjectSerialCounter = 0;
CDHLIRDescriptor::CDHLIRDescriptor(){
	m_HLIRObjectSerialNumber = m_HLIRObjectSerialCounter++;	
	m_handle = NULL;
	m_location = NULL;	
	m_HLIRObjectDbsID = "N/A";
	m_strHLIRObjectDbsID = NULL;
	m_HLIRSyntaxElementType = DL_Unitialized;
	m_HLIRSyntaxElementCategory = DLCAT_NOTINITIALIZED; 
	m_category = DLOC_GENERAL;
	m_HLIRGraphvizID = NULL;			
}
CDHLIRDescriptor::CDHLIRDescriptor(CDHLIRSyntaxElement *host,DLLOCATION_HLIR *location/*=NULL*/){

	m_HLIRObjectSerialNumber = m_HLIRObjectSerialCounter++;	
	m_handle = host;
	m_location = NULL;
	if ( location != NULL ){
		m_location = new DLLOCATION_HLIR(*location);
	}	

	m_HLIRObjectDbsID = "N/A";
	m_strHLIRObjectDbsID = NULL;
	m_HLIRSyntaxElementType = DL_Unitialized;
	m_HLIRSyntaxElementCategory = DLCAT_NOTINITIALIZED; 
	m_category = DLOC_GENERAL;
	m_HLIRGraphvizID = NULL;		
}
CDHLIRDescriptor::CDHLIRDescriptor(const CDHLIRDescriptor &Init){
	size_t len = strlen(Init.m_strHLIRObjectDbsID)+1;
	size_t lenx = strlen(Init.m_HLIRGraphvizID)+1;

	m_HLIRObjectSerialNumber = m_HLIRObjectSerialCounter++;
	m_location = NULL;
	m_handle = NULL;  // This must be set by user	

	m_HLIRGraphvizID =  NULL;
	m_HLIRObjectDbsID = "";
	m_strHLIRObjectDbsID = NULL;
	m_HLIRSyntaxElementType = Init.m_HLIRSyntaxElementType;
	m_HLIRSyntaxElementCategory = Init.m_HLIRSyntaxElementCategory;
	m_category = Init.m_category;
}
CDHLIRDescriptor::~CDHLIRDescriptor(){}
void CDHLIRDescriptor::SetObjectIdentifier(string id){
size_t len;

	m_HLIRObjectDbsID = id;
	len = strlen(id.c_str())+1;
	if ( m_strHLIRObjectDbsID != NULL ){
		delete [] m_strHLIRObjectDbsID;
		m_strHLIRObjectDbsID = new char[len];
		strncpy_s(m_strHLIRObjectDbsID,len,id.c_str(),len);
	}
	else{
		m_strHLIRObjectDbsID = new char[len];
		strncpy_s(m_strHLIRObjectDbsID,len,id.c_str(),len);
	}
}
void CDHLIRDescriptor::SetObjectIdentifier(char *id){
	size_t len;
	m_HLIRObjectDbsID = (string)id;
	len = strlen(id)+1;
	if ( m_strHLIRObjectDbsID != NULL ){
		delete [] m_strHLIRObjectDbsID;
		m_strHLIRObjectDbsID = new char[len];
		strncpy_s(m_strHLIRObjectDbsID,len,id,len);
	}
	else{
		m_strHLIRObjectDbsID = new char[len];
		strncpy_s(m_strHLIRObjectDbsID,len,id,len);
	}
}
char *CDHLIRDescriptor::InitHLIRObjectGraphVizID(){
string s,s1;
char *buffer;
	buffer = new char[10];
	_itoa_s(m_HLIRObjectSerialNumber,buffer,10,10);
	s1= (string)buffer;
	s= (string)(g_DLHLIRtypeidentifier[m_HLIRSyntaxElementType]) + s1;
	delete [] buffer;
	m_HLIRGraphvizID = DLStrDup_cpp(s);
	return m_HLIRGraphvizID;
}
void CDHLIRDescriptor::SetHLIRObjectGraphVizID(char *id){
	m_HLIRGraphvizID = id;
}
// ========================================================================
CDHLIR_GPDescriptor::CDHLIR_GPDescriptor(DLHLIR_ELEMENT_TYPE tp, DLHLIR_ELEMENT_CATEGORY cat)
:CDHLIRDescriptor(){		
	m_HLIRSyntaxElementType = tp;
	m_HLIRSyntaxElementCategory = cat; 
	m_category = DLOC_GENERAL;
	m_HLIRGraphvizID = InitHLIRObjectGraphVizID();			
}
CDHLIR_GPDescriptor::CDHLIR_GPDescriptor(const CDHLIR_GPDescriptor &Init)
:CDHLIRDescriptor(Init){
	m_HLIRGraphvizID = InitHLIRObjectGraphVizID();			
}
CDHLIR_GPDescriptor::~CDHLIR_GPDescriptor(){
}
char *CDHLIR_GPDescriptor::InitHLIRObjectGraphVizID(){
string s,s1;
char *buffer;

	buffer = new char[10];
	_itoa_s(m_HLIRObjectSerialNumber,buffer,10,10);
	s1= (string)buffer;
	s= (string)(g_DLHLIRtypeidentifier[m_HLIRSyntaxElementType]) + s1;
	delete [] buffer;
	m_HLIRGraphvizID = DLStrDup_cpp(s);
return m_HLIRGraphvizID;
};
// ========================================================================
CDHLIR_IDENTIFIERDescriptor::CDHLIR_IDENTIFIERDescriptor(CDHLIRSyntaxElement *host,
									string idstr,DLLOCATION_HLIR *location/* =NULL */)
:CDHLIRDescriptor(host,location){
	m_IsTypeName = false;
	m_IdentifierString = idstr;	
	m_HLIRSyntaxElementType = DLE_IDENTIFIER;
	m_HLIRSyntaxElementCategory = DLCAT_EXPRESSION; 
	m_category = DLOC_GENERAL;
	m_HLIRObjectDbsID = idstr;
	m_strHLIRObjectDbsID = DLStrDup_cpp(idstr);			
	InitHLIRObjectGraphVizID();	
}
CDHLIR_IDENTIFIERDescriptor::CDHLIR_IDENTIFIERDescriptor(const CDHLIR_IDENTIFIERDescriptor &Init)
:CDHLIRDescriptor(Init){
	m_IsTypeName = Init.m_IsTypeName;
	m_IdentifierString = Init.m_IdentifierString;
	m_HLIRSyntaxElementType =  Init.m_HLIRSyntaxElementType;
	m_HLIRSyntaxElementCategory = Init.m_HLIRSyntaxElementCategory;
	m_category = Init.m_category;
	m_HLIRObjectDbsID = "";
	m_strHLIRObjectDbsID = NULL;	
	InitHLIRObjectGraphVizID();	
}
CDHLIR_IDENTIFIERDescriptor::~CDHLIR_IDENTIFIERDescriptor(){}
char *CDHLIR_IDENTIFIERDescriptor::InitHLIRObjectGraphVizID(){
string s,s1;
char buffer[10];
	_itoa_s(m_HLIRObjectSerialNumber,buffer,10);
	s1= (string)buffer;
	s= (string)g_DLHLIRtypeidentifier[m_HLIRSyntaxElementType] + "_" +
		m_IdentifierString + "_" +s1;
	m_HLIRGraphvizID = DLStrDup_cpp(s);
return m_HLIRGraphvizID;
}
// ========================================================================
CDHLIR_CONSTANTDescriptor::CDHLIR_CONSTANTDescriptor(CDHLIRSyntaxElement *host,
									string idstr,DLLOCATION_HLIR *location/* =NULL */)
:CDHLIRDescriptor(host,location){
int i;
	m_ConstantString = idstr;	
	m_HLIRSyntaxElementType = DLE_CONSTANT;
	m_HLIRSyntaxElementCategory = DLCAT_EXPRESSION;
	InitHLIRObjectGraphVizID();
}
CDHLIR_CONSTANTDescriptor::CDHLIR_CONSTANTDescriptor(const CDHLIR_CONSTANTDescriptor &Init)
:CDHLIRDescriptor(Init){
	m_ConstantString = Init.m_ConstantString;
	m_HLIRSyntaxElementType =  Init.m_HLIRSyntaxElementType;
	m_HLIRSyntaxElementCategory = Init.m_HLIRSyntaxElementCategory;
	m_category = Init.m_category;
	m_HLIRObjectDbsID = "";
	m_strHLIRObjectDbsID = NULL;
	InitHLIRObjectGraphVizID();
}
CDHLIR_CONSTANTDescriptor::~CDHLIR_CONSTANTDescriptor(){}
char *CDHLIR_CONSTANTDescriptor::InitHLIRObjectGraphVizID(){
string s,s1;
char buffer[10];
	_itoa_s(m_HLIRObjectSerialNumber,buffer,10);
	s1= (string)buffer;
	s= (string)g_DLHLIRtypeidentifier[m_HLIRSyntaxElementType] + "_" +
		m_ConstantString + "_" +s1;
	m_HLIRGraphvizID = DLStrDup_cpp(s);
return m_HLIRGraphvizID;
}
// ========================================================================
CDHLIR_FunDefDescriptor::CDHLIR_FunDefDescriptor(CDHLIRSyntaxElement *host)
:CDHLIRDescriptor(host){
	m_FunctionName = "";	
	m_sFunctionName = NULL;
	m_HLIRSyntaxElementType = DL_FunctionDefinition;
	m_HLIRSyntaxElementCategory = DLCAT_NOTINITIALIZED; 
	m_category = DLOC_FUNDEF;
	m_HLIRObjectDbsID = "";
	m_strHLIRObjectDbsID = NULL;			
	InitHLIRObjectGraphVizID();	
}
CDHLIR_FunDefDescriptor::CDHLIR_FunDefDescriptor(const CDHLIR_FunDefDescriptor &Init)
:CDHLIRDescriptor(Init){
	m_FunctionName = Init.m_FunctionName;
	if ( Init.m_sFunctionName == NULL  ){
		m_sFunctionName = NULL;
	}else{
		m_sFunctionName = DLStrDup_cpp(Init.m_FunctionName.c_str());
	}	
	m_HLIRSyntaxElementType =  Init.m_HLIRSyntaxElementType;
	m_HLIRSyntaxElementCategory = Init.m_HLIRSyntaxElementCategory;
	m_category = Init.m_category;
	m_HLIRObjectDbsID = "";
	m_strHLIRObjectDbsID = NULL;
	InitHLIRObjectGraphVizID();
}
char *CDHLIR_FunDefDescriptor::InitHLIRObjectGraphVizID(){
string s,s1;
char buffer[10];
	_itoa_s(m_HLIRObjectSerialNumber,buffer,10);
	s1= (string)buffer;
	s= (string)g_DLHLIRtypeidentifier[m_HLIRSyntaxElementType] + "_" +
		m_FunctionName + "_" +s1;
	m_HLIRGraphvizID = DLStrDup_cpp(s);
return m_HLIRGraphvizID;
}
CDHLIR_FunDefDescriptor::~CDHLIR_FunDefDescriptor(){}
void CDHLIR_FunDefDescriptor::SetFunctionName(string fname){
	if(m_sFunctionName != NULL){
		cout << endl << "Warning: function already has a name!";
		delete [] m_sFunctionName;
	}
	m_sFunctionName = DLStrDup_cpp(fname.c_str());
	m_FunctionName = fname;
}