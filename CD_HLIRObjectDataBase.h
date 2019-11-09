/* *********************************************************************************** */
/* Title :							      */
/* File :CD_HLIRObjectDataBase.h																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* CoAuthor: Christakis Lezos																  */
/* Creation Date: 12/3/2012		*/
/* *********************************************************************************** */
#ifndef DLHLIROBJDATABASE_
#define DLHLIROBJDATABASE_
#include <iostream>
#include <string>
#include "CD_HLIRDefines.h"

class CDHLIRSyntaxElement;
class CDHLIRDescriptor{
public:
	CDHLIRDescriptor();
	CDHLIRDescriptor(CDHLIRSyntaxElement *host,DLLOCATION_HLIR *location=NULL);
	CDHLIRDescriptor(const CDHLIRDescriptor &Init);
	~CDHLIRDescriptor();	
	virtual void HLIR2CGeneration(CDHLIRSyntaxElement *&parent){}
	void SetObjectIdentifier(string id);
	void SetObjectIdentifier(char *id);
	string GetObjectIdentifier(){ return m_HLIRObjectDbsID; }
	void SetobjectSerialNumber(unsigned int sln){ m_HLIRObjectSerialNumber = sln;}
	unsigned int GetObjectSerialNumber(){ return m_HLIRObjectSerialNumber;}
	virtual char *InitHLIRObjectGraphVizID();
	void SetHLIRObjectGraphVizID(char *id);
public:
	// Initialization by base classes
	int m_HLIRObjectSerialNumber;		
	DLLOCATION_HLIR *m_location;

	// Actual Initialization by derived classes
	string m_HLIRObjectDbsID; // the name for the code database
	char *m_strHLIRObjectDbsID; // the name for the code database
	char *m_HLIRGraphvizID;	// the name appearing on the Graphviz output
	DLHLIR_ELEMENT_TYPE m_HLIRSyntaxElementType;
	DLHLIR_ELEMENT_CATEGORY m_HLIRSyntaxElementCategory;
	CDHLIRSyntaxElement *m_handle;
	DLOBJECT_CATEGORY m_category;
public:
	static unsigned int m_HLIRObjectSerialCounter;
};
class CDHLIR_GPDescriptor: public CDHLIRDescriptor{
public:
	CDHLIR_GPDescriptor(DLHLIR_ELEMENT_TYPE tp, DLHLIR_ELEMENT_CATEGORY cat=DLCAT_NOTINITIALIZED);
	CDHLIR_GPDescriptor(const CDHLIR_GPDescriptor &Init);
	~CDHLIR_GPDescriptor();	
private:
	virtual char *InitHLIRObjectGraphVizID();
};
class CDHLIR_IDENTIFIERDescriptor: public CDHLIRDescriptor{
public:
	CDHLIR_IDENTIFIERDescriptor(CDHLIRSyntaxElement *host,string idstr,
		DLLOCATION_HLIR *location=NULL);
	CDHLIR_IDENTIFIERDescriptor(const CDHLIR_IDENTIFIERDescriptor &Init);
	~CDHLIR_IDENTIFIERDescriptor();		
public:
	string m_IdentifierString;
	bool m_IsTypeName;
private:
	virtual char *InitHLIRObjectGraphVizID();
};
class CDHLIR_CONSTANTDescriptor: public CDHLIRDescriptor{
public:
	CDHLIR_CONSTANTDescriptor(CDHLIRSyntaxElement *host,string idstr,
		DLLOCATION_HLIR *location=NULL);
	CDHLIR_CONSTANTDescriptor(const CDHLIR_CONSTANTDescriptor &Init);
	~CDHLIR_CONSTANTDescriptor();		
public:
	string m_ConstantString;
private:
	virtual char *InitHLIRObjectGraphVizID();
};

class CDHLIR_FunDefDescriptor :public CDHLIRDescriptor{
public:
	CDHLIR_FunDefDescriptor(CDHLIRSyntaxElement *host);
	CDHLIR_FunDefDescriptor(const CDHLIR_FunDefDescriptor &Init);
	~CDHLIR_FunDefDescriptor();	
	
	void SetFunctionName(string fname);
public:	
	string m_FunctionName;
	char * m_sFunctionName;
private:
	virtual char *InitHLIRObjectGraphVizID();
};

#endif