/* *********************************************************************************** */
/* Title :							      */
/* File :CD_HLIRSyntaxElements.h																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* CoAuthor: Christakis Lezos																  */
/* Creation Date: 12/3/2012		*/
/* *********************************************************************************** */
#ifndef DHLIR_
#define DHLIR_
#include <iostream>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include "CD_HLIRTemplates.h"
#include "CD_HLIRObjectDataBase.h"
#include "CD_Defines.h"
#include "CD_HLIRTypeDefines.h"
#include "CD_HLIRDefines.h"

class CDHLIR_ROOT;
class CD_HLIRFunctionDefinition;
class CS_HLIRCompoundStatement;
class CDE_HLIRIDENTIFIER ;
class CT_HLIRFunctionType;

class CT_HLIRBasicType;
class CT_HLIRDerivedType;

class CDHLIRSyntaxElement : public  DLTHLIRContainer<CDHLIRSyntaxElement,CDHLIRSyntaxElement>{
public:
	// CONSTRUCTION / DESTRUCTION	
	CDHLIRSyntaxElement(unsigned int num_contexts);
	CDHLIRSyntaxElement(CDHLIRSyntaxElement *generator,
					   CDHLIRSyntaxElement *parent=NULL);
	CDHLIRSyntaxElement(const CDHLIRSyntaxElement &init);
	~CDHLIRSyntaxElement();

	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false){return -1;}
	virtual char * InitHLIRElementTypeString();
	virtual void SetHLIRElementType(DLHLIR_ELEMENT_TYPE etp){ m_Descriptor->m_HLIRSyntaxElementType = etp; }
	
	// ACCESSORS
	virtual DLHLIR_CONTEXT MapIndextoContext(int){return DLE_NotApplicable;}
	virtual int MapContext(DLHLIR_CONTEXT ctx){return -1;}
	virtual int GetNumberofContexts(){ return m_Context.size(); }
	virtual char * GetHLIRElementGraphvizString(){return m_Descriptor->m_HLIRGraphvizID;}
	DLHLIR_ELEMENT_CATEGORY GetHLIRElementCategory() const{ return m_Descriptor->m_HLIRSyntaxElementCategory; }
	DLHLIR_ELEMENT_TYPE GetHLIRElementType(){ return m_Descriptor->m_HLIRSyntaxElementType; }
	virtual void SeekDeclarator(CDHLIRSyntaxElement *&ident);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 ){
		return NULL;
	}
			
	// OUTPUT
	void DEBUG_TraceOnTraversal();
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	void HLIRGraphContextEmmiter();
	static void SetOutputFile(string outputFile);
	
	virtual void InstallPropertyMessage(MESSAGE_TYPE msg){};
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	void CDeclTraversal();
protected:
	CDHLIRDescriptor *m_Descriptor;
	static ofstream *ms_outfile;
protected:
	int state;
};

class CDHLIR_Expression : public CDHLIRSyntaxElement{
public:
	// CONSTRUCTION / DESTRUCTION
	CDHLIR_Expression(unsigned int num_contexts);
	CDHLIR_Expression(const CDHLIR_Expression &init);
	~CDHLIR_Expression();
	
	// MODIFIERS
	virtual void UpdateAnsestorAssociativity(DLEXPRESSION_RESULT_TYPE);	
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false){return -1;}
		
	// ACCESSORS	
	virtual int MapContext(DLHLIR_CONTEXT ctx){return -1;}	
	virtual DLHLIR_CONTEXT MapIndextoContext(int){return DLE_NotApplicable;}
	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
public:
	DLEXPRESSION_ASSOCIATIVITY m_Associativity;
	DLEXPRESSION_RESULT_TYPE   m_Result_Type;
	unsigned int m_ExpressionPriorityLevel;
};

class CDHLIR_Statement : public CDHLIRSyntaxElement{
public:
	// CONSTRUCTION / DESTRUCTION
	CDHLIR_Statement(unsigned int num_contexts);
	CDHLIR_Statement(const CDHLIR_Statement &init);
	~CDHLIR_Statement();	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false){return -1;}	
	// ACCESSORS
	virtual int MapContext(DLHLIR_CONTEXT ctx){return -1;}	
	virtual DLHLIR_CONTEXT MapIndextoContext(int){return DLE_NotApplicable;}
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
};
class CDHLIR_ROOT : public CDHLIRSyntaxElement{
public:
	// CONSTRUCTION / DESTRUCTION
	CDHLIR_ROOT();
	CDHLIR_ROOT(const CDHLIR_ROOT &init);
	~CDHLIR_ROOT();
	
	// ACCESSORS
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement* GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index=0);
	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
protected:	
};
// ========================================================================
// ========================================================================
// ========================================================================
class CDE_HLIRIDENTIFIER : public CDHLIR_Expression{
public:
	// CONSTRUCTION / DESTRUCTION
	CDE_HLIRIDENTIFIER(string idstr, DLLOCATION_HLIR *loc=NULL);
	CDE_HLIRIDENTIFIER(const CDE_HLIRIDENTIFIER &init);
	~CDE_HLIRIDENTIFIER();
	// ACCESSORS
	virtual string GetIdentifierString(){ return m_Descriptor->m_IdentifierString;}
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false){return -1;}	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	void SeekDeclarator(CDHLIRSyntaxElement *&ident);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
protected:
	CDHLIR_IDENTIFIERDescriptor *&m_Descriptor;
};
class CDE_HLIRCONSTANT : public CDHLIR_Expression{
public:
	// CONSTRUCTION / DESTRUCTION
	CDE_HLIRCONSTANT(string idstr, DLLOCATION_HLIR *loc=NULL);
	CDE_HLIRCONSTANT(const CDE_HLIRCONSTANT &init);
	~CDE_HLIRCONSTANT();
	// ACCESSORS
	virtual string GetConstantString(){ return m_Descriptor->m_ConstantString;}
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false){return -1;}	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
protected:
	CDHLIR_CONSTANTDescriptor *&m_Descriptor;
};

// ========================================================================
// ========================================================================
// ========================================================================
class CD_HLIRTranslationUnit : public CDHLIRSyntaxElement{
public:
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRTranslationUnit();
	CD_HLIRTranslationUnit(const CD_HLIRTranslationUnit &init);
	~CD_HLIRTranslationUnit();

	// ACCESSORS
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	

	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
};
class CD_HLIRFunctionDefinition : public CDHLIRSyntaxElement{
public:
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRFunctionDefinition();
	CD_HLIRFunctionDefinition(const CD_HLIRFunctionDefinition &init);
	~CD_HLIRFunctionDefinition();

	// ACCESSORS
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
	void SetFunctionName(string fname ){ m_Descriptor->SetFunctionName(fname);}

	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
protected:
	CS_HLIRCompoundStatement *m_CompoundStatement;
	CT_HLIRFunctionType *m_FunctionDeclarator;

	CDHLIR_FunDefDescriptor *&m_Descriptor;
};
class CDS_HLIRExressionStatement : public CDHLIR_Statement{
public:
	// CONSTRUCTION / DESTRUCTION
	CDS_HLIRExressionStatement();
	CDS_HLIRExressionStatement(const CDS_HLIRExressionStatement &init);
	~CDS_HLIRExressionStatement();

	// ACCESSORS
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	

	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
};
class CS_HLIRCompoundStatement : public CDHLIR_Statement{
public:
	// CONSTRUCTION / DESTRUCTION
	CS_HLIRCompoundStatement();
	CS_HLIRCompoundStatement(const CS_HLIRCompoundStatement &Init);
	~CS_HLIRCompoundStatement();
	
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
		
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);	
};
class CD_HLIRDeclaration : public CDHLIRSyntaxElement{
public:
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRDeclaration();
	CD_HLIRDeclaration(const CD_HLIRDeclaration &Init);
	~CD_HLIRDeclaration();
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);	
	
	virtual void SetHLIRElementType(DLHLIR_ELEMENT_TYPE tp);
	virtual void InstallPropertyMessage(MESSAGE_TYPE msg);
	DLSTORAGE_CLASS GetStorageClass(){ return m_StorageClass;}
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	void SeekNestedDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
protected:	
	DLSTORAGE_CLASS m_StorageClass;	
	DLFUNCTION_SPECIFIER m_FunctionSpecifier;
};
class CD_HLIRTypeQualifier : public CDHLIRSyntaxElement{
public: 
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRTypeQualifier(DLTYPE_QUALIFIER tq);
	CD_HLIRTypeQualifier(const CD_HLIRTypeQualifier &Init);
	~CD_HLIRTypeQualifier();
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el,
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	
	virtual char *InitHLIRElementTypeString();
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
protected:
	DLTYPE_QUALIFIER m_TypeQualifier;
};
class CD_HLIRTypeSpecifiers : public CDHLIRSyntaxElement{
public: 
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRTypeSpecifiers();
	CD_HLIRTypeSpecifiers(const CD_HLIRTypeSpecifiers &Init);
	~CD_HLIRTypeSpecifiers();
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);

	virtual char *InitHLIRElementTypeString();
	virtual void InstallPropertyMessage(MESSAGE_TYPE msg);
	CDHLIRSyntaxElement *DeduceCreateTypeSpecification();
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
protected:
	list<DLTYPE_SPECIFIERS> m_TypeSpecifiers;
};
class CD_HLIRDeclarator : public CDHLIRSyntaxElement{
public: 
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRDeclarator();
	CD_HLIRDeclarator(const CD_HLIRDeclarator &Init);
	~CD_HLIRDeclarator();
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	
	void SeekDeclarator(CDHLIRSyntaxElement *&ident);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
};
class CD_HLIRTypename : public CDHLIRSyntaxElement{
public: 
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRTypename();
	CD_HLIRTypename(const CD_HLIRTypename &Init);
	~CD_HLIRTypename();
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
};
class CD_HLIREnumerator : public CDHLIRSyntaxElement{
public: 
	// CONSTRUCTION / DESTRUCTION
	CD_HLIREnumerator();
	CD_HLIREnumerator(const CD_HLIREnumerator &Init);
	~CD_HLIREnumerator();
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
};
class CD_HLIRInitializer : public CDHLIRSyntaxElement{
public: 
	// CONSTRUCTION / DESTRUCTION
	CD_HLIRInitializer();
	CD_HLIRInitializer(const CD_HLIRInitializer &Init);
	~CD_HLIRInitializer();
	// ACCESSORS
	virtual int  MapContext(DLHLIR_CONTEXT ctx);	
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );	
	// MODIFIERS
	virtual int InstallContextElement(CDHLIRSyntaxElement *el, 
		DLHLIR_CONTEXT ctx=DLE_NotApplicable, bool placebefore=false);	
	// OUTPUT
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
};
// ========================================================================
// ========================================================================
// ========================================================================
// ========================================================================
// 

///////////////////////////// 1st type level //////////////////////////////
// CType carries the whole type specification information which consists of
// a basic type referring to a type specifier and a derived type. A type 
// specifier in the case of the basic types characterizes the type whereas
// in derived type is part of the type that both the type specifier and 
// declarator denote. A derived type needs both the type specifier and 
// declarator to be determined. A basic type needs none of the two. The 
// object class type in this case characterizes the type.
class CT_HLIRType :public CDHLIRSyntaxElement {
public:
	explicit CT_HLIRType(); // No argument constructor represents the basic types
	CT_HLIRType(unsigned int num_contexts);
	CT_HLIRType(CT_HLIRBasicType *TypeSpecifier,
		CT_HLIRDerivedType *Declarator);	// This constructor represents the 
	CT_HLIRType(const CT_HLIRType &Init);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}
	string GetTypeString(){ return m_Typestring;}     // derived types.	
	~CT_HLIRType();
	unsigned int GetTypeSpecificationIndex(){return m_type_specification_index;}
protected:
	string m_Typestring;		
	unsigned int m_type_specification_index; // Index to the data structure
	// containing information about 
	// the type. Applicable only to 
	// Basic Types.	
};
//////////////  2nd type level ///////////////////////////////////////////
class CT_HLIRBasicType : public CT_HLIRType{
public:
	CT_HLIRBasicType(unsigned int num_contexts =0);
	CT_HLIRBasicType(const CT_HLIRBasicType &Init);
	~CT_HLIRBasicType();
	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}
protected:	
};
class CT_HLIRDerivedType : public CT_HLIRType{
public:
	CT_HLIRDerivedType(unsigned int num_contexts);
	CT_HLIRDerivedType(const CT_HLIRDerivedType &Init);
	~CT_HLIRDerivedType();		
	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}
};
////////////// 3rd type level ////////////////////////////////////////////
class CT_HLIRVoidType : public CT_HLIRBasicType{
public:
	CT_HLIRVoidType();
	CT_HLIRVoidType(const CT_HLIRVoidType &Init);
	~CT_HLIRVoidType();
	virtual char *GetHLIRElementTypeString();
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
}; 
class CT_HLIRIntegerCategoryType :public CT_HLIRBasicType{
public:
	CT_HLIRIntegerCategoryType(DLINTEGER_SIGNNESS, DLINTEGER_PRECISION,
		unsigned int num_contexts=0);
	CT_HLIRIntegerCategoryType(const CT_HLIRIntegerCategoryType &Init);
	~CT_HLIRIntegerCategoryType();	
	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}
	DLINTEGER_SIGNNESS GetSignness(){return m_signness;}
	DLINTEGER_PRECISION GetPrecision(){return m_precision;}
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
protected:
	DLINTEGER_SIGNNESS m_signness;
	DLINTEGER_PRECISION m_precision;	 
};
class CT_HLIRFloatingType :public CT_HLIRBasicType{
public:
	CT_HLIRFloatingType(DLFLOATING_PRECISION,unsigned int);
	CT_HLIRFloatingType(const CT_HLIRFloatingType &Init);
	~CT_HLIRFloatingType();	

	virtual char *GetHLIRElementTypeString();
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);

	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}	
	DLFLOATING_PRECISION GetPrecision(){return m_precision;}
protected:
	DLFLOATING_PRECISION m_precision;
};
class CT_HLIRIntegerType :public CT_HLIRIntegerCategoryType{
public:
	CT_HLIRIntegerType(DLINTEGER_SIGNNESS, DLINTEGER_PRECISION,unsigned int);
	CT_HLIRIntegerType(const CT_HLIRIntegerType &Init);
	~CT_HLIRIntegerType();
	virtual char *GetHLIRElementTypeString();
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);


	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}	
};
class CT_HLIRCharacterType :public CT_HLIRIntegerCategoryType{
public:
	CT_HLIRCharacterType(DLINTEGER_SIGNNESS,unsigned int);
	CT_HLIRCharacterType(const CT_HLIRCharacterType &Init);
	virtual char *GetHLIRElementTypeString();
	~CT_HLIRCharacterType();	

	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false){return -1;}
};
class CT_HLIREnumeratedType :public CT_HLIRIntegerCategoryType{
public:
	CT_HLIREnumeratedType(DLHLIR_ELEMENT_TYPE);
	CT_HLIREnumeratedType(CDHLIRSyntaxElement *tagid,
		list<CDHLIRSyntaxElement *> *enumlst);
	CT_HLIREnumeratedType(const CT_HLIREnumeratedType &Init);
	~CT_HLIREnumeratedType();
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *,
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false);
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);	
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
};
class CT_HLIRArrayType: public CT_HLIRDerivedType{
public:
	CT_HLIRArrayType();
	CT_HLIRArrayType(CDHLIRSyntaxElement *arrtp, CDHLIRSyntaxElement *arrsz);
	CT_HLIRArrayType(const CT_HLIRArrayType &Init);
	~CT_HLIRArrayType();
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);

	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *,
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
protected: // API Functions
	virtual void SeekDeclarator(CDHLIRSyntaxElement *&);
};
class CT_HLIRStructureType : public CT_HLIRDerivedType{
public:
	CT_HLIRStructureType(DLHLIR_ELEMENT_TYPE);
	CT_HLIRStructureType(list<CDHLIRSyntaxElement *> *decls,
		CDHLIRSyntaxElement *tag);
	CT_HLIRStructureType(const CT_HLIRStructureType &Init);
	~CT_HLIRStructureType();
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);

	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *,
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
protected:	
};
class CT_HLIRUnionType : public CT_HLIRDerivedType{
public:
	CT_HLIRUnionType(DLHLIR_ELEMENT_TYPE);
	CT_HLIRUnionType(list<CDHLIRSyntaxElement *> *decls,
		CDHLIRSyntaxElement *tag);
	CT_HLIRUnionType(const CT_HLIRUnionType &Init);
	~CT_HLIRUnionType();
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);

	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *,
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
};
class CT_HLIRFunctionType: public CT_HLIRDerivedType{
public:
	CT_HLIRFunctionType();
	CT_HLIRFunctionType(CDHLIRSyntaxElement *fref, 
		list<CDHLIRSyntaxElement *> *decls);
	CT_HLIRFunctionType(const CT_HLIRFunctionType &Init);
	~CT_HLIRFunctionType();
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *,
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false);
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
protected: // API Functions
	virtual void SeekDeclarator(CDHLIRSyntaxElement *&);
};
class CT_HLIRPointerType: public CT_HLIRDerivedType{
public:
	CT_HLIRPointerType();
	CT_HLIRPointerType(CDHLIRSyntaxElement *tp);
	CT_HLIRPointerType(const CT_HLIRPointerType &Init);
	~CT_HLIRPointerType();
	virtual int MapContext(DLHLIR_CONTEXT ctx);
	virtual DLHLIR_CONTEXT MapIndextoContext(int);
	virtual int  InstallContextElement(CDHLIRSyntaxElement *, 
		DLHLIR_CONTEXT ctx= DLE_NotApplicable, bool placebefore=false);
	virtual void HLIRGraphEmmiter(CDHLIRSyntaxElement *parent);
	virtual void SeekDeclaratorType(class type_info_ *&tpinfo, CDHLIRSyntaxElement *child);
	virtual CDHLIRSyntaxElement *GetContextElement(DLHLIR_CONTEXT ctx,unsigned int index =0 );
protected: // API Functions
	virtual void SeekDeclarator(CDHLIRSyntaxElement *&);
};
#endif