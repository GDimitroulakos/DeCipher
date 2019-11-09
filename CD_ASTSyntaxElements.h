/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :CD_ASTSyntaxElements.h																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */

#ifndef DASTSYNTAXELEMENTS_
#define DASTSYNTAXELEMENTS_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdarg.h>
#include <list>
#include <vector>
#include "Decipher.tab.h"
#include "location.hh"
#include "CD_ASTDefines.h"
#include "CD_Defines.h"

using namespace std;

class CDHLIRSyntaxElement;
class CDASTSyntaxElement;
class CDASTscdeclaration_unit;
class CDASTscdeclarations;
class CDASTscdeclaration;
class CDASTdeclaration_specifiers;
class CDASTinit_declarator_list;
class CDASTinit_declarator;
class CDASTstorage_class_specifier;
class CDASTtype_specifier;
class CDASTstruct_or_union_specifier;
class CDASTstruct_or_union;
class CDASTstruct_declaration_list;
class CDASTstruct_declaration;
class CDASTspecifier_qualifier_list;
class CDASTstruct_declarator_list;
class CDASTstruct_declarator;
class CDASTenum_specifier;
class CDASTenumerator_list;
class CDASTenumerator;
class CDASTtype_qualifier;
class CDASTdeclarator;
class CDASTdirect_declarator;
class CDASTpointer;
class CDASTtype_qualifier_list;
class CDASTparameter_type_list;
class CDASTparameter_list;
class CDASTparameter_declaration;
class CDASTtype_name;
class CDASTabstract_declarator;
class CDASTdirect_abstract_declarator;
class CDASTinitializer;
class CDASTinitializer_list;
class CDASTqualified_id;
class CDASTassignment_expression;
class CDASTconstant_expression;

class CDASTSyntaxElement{
public:
	CDASTSyntaxElement();
	CDASTSyntaxElement(DLNONTERMINAL_PRODUCTION_RULE, decipher::location *);
	~CDASTSyntaxElement(){}
	unsigned int GetObjectSerialNumber() const{ return m_ObjectSerialNumber; }
	decipher::location *GetObjectLocation() const { return m_location; }
	friend ostream &operator<<(ostream &ostr,const CDASTSyntaxElement &OBJ);
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,CDHLIRSyntaxElement *&child);
	ofstream *SetOutputFilename(DLAST_EMMITERS emmiter,string filename);
protected:
	void DEBUG_TraceOnTraversal();
	void DEBUG_TraceOnASTCreation();
	void DEBUG_TraceOnGraphizEmmition1();
	void DEBUG_TraceOnGraphizEmmition2();
protected:
	unsigned int m_NumberOfDescendants;
	vector<CDASTSyntaxElement *> m_Descendants;
	static unsigned int m_ObjectSerialNumberCounter;
	const unsigned int m_ObjectSerialNumber;
protected:
	decipher::location *m_location;	// location of syntax element
	DLLOCATION_HLIR *m_HLIRlocation;
	static vector<ofstream *> m_OutputFiles;
public:
	DLNONTERMINAL_CODE m_NonTerminalCode;
	DLNONTERMINAL_PRODUCTION_RULE m_NonTerminal_ProductionCode;
};
class CDASTTOKEN : public CDASTSyntaxElement {
public:
	CDASTTOKEN(DLTERMINAL_CODE token,decipher::location *loc,
		DLNONTERMINAL_PRODUCTION_RULE pr,
		char *tokenstr=NULL);
	~CDASTTOKEN();
	friend ostream &operator<<(ostream &ostr,const CDASTTOKEN &OBJ);
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
		CDHLIRSyntaxElement *&child);
	char * GetTokenString(){ return m_tokenstring;}
protected:
public:
	DLTERMINAL_CODE m_TerminalCode;	// token id
	char * m_tokenstring;		    // Holds the token representation in the
};

class CDASTscdeclaration_unit : public CDASTSyntaxElement {
public:
	CDASTscdeclaration_unit(CDASTscdeclarations *scde0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTscdeclaration_unit();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
public:
	bool m_IsTypedef;
};

class CDASTscdeclarations : public CDASTSyntaxElement {
public:
	CDASTscdeclarations(CDASTscdeclaration *scde0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTscdeclarations(CDASTTOKEN *TOKE0, CDASTtype_name *type1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTscdeclarations(CDASTscdeclaration *scde0, CDASTscdeclarations *scde1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTscdeclarations(CDASTTOKEN *TOKE0, CDASTtype_name *type1, CDASTscdeclarations *scde2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTscdeclarations();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTscdeclaration : public CDASTSyntaxElement {
public:
	CDASTscdeclaration(CDASTdeclaration_specifiers *decl0, CDASTTOKEN *TOKE1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTscdeclaration(CDASTdeclaration_specifiers *decl0, CDASTinit_declarator_list *init1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTscdeclaration();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTdeclaration_specifiers : public CDASTSyntaxElement {
public:
	CDASTdeclaration_specifiers(CDASTstorage_class_specifier *stor0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdeclaration_specifiers(CDASTstorage_class_specifier *stor0, CDASTdeclaration_specifiers *decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdeclaration_specifiers(CDASTtype_specifier *type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdeclaration_specifiers(CDASTtype_specifier *type0, CDASTdeclaration_specifiers *decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdeclaration_specifiers(CDASTtype_qualifier *type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdeclaration_specifiers(CDASTtype_qualifier *type0, CDASTdeclaration_specifiers *decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTdeclaration_specifiers();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTinit_declarator_list : public CDASTSyntaxElement {
public:
	CDASTinit_declarator_list(CDASTinit_declarator *init0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTinit_declarator_list(CDASTinit_declarator_list *init0, CDASTTOKEN *TOKE1, CDASTinit_declarator *init2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTinit_declarator_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTinit_declarator : public CDASTSyntaxElement {
public:
	CDASTinit_declarator(CDASTdeclarator *decl0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTinit_declarator(CDASTdeclarator *decl0, CDASTTOKEN *TOKE1, CDASTinitializer *init2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTinit_declarator();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTstorage_class_specifier : public CDASTSyntaxElement {
public:
	CDASTstorage_class_specifier(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTstorage_class_specifier();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTtype_specifier : public CDASTSyntaxElement {
public:
	CDASTtype_specifier(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTtype_specifier(CDASTstruct_or_union_specifier *stru0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTtype_specifier(CDASTenum_specifier *enum0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTtype_specifier();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTstruct_or_union_specifier : public CDASTSyntaxElement {
public:
	CDASTstruct_or_union_specifier(CDASTstruct_or_union *stru0, CDASTqualified_id *qual1, CDASTTOKEN *TOKE2, CDASTstruct_declaration_list *stru3, CDASTTOKEN *TOKE4, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTstruct_or_union_specifier(CDASTstruct_or_union *stru0, CDASTTOKEN *TOKE1, CDASTstruct_declaration_list *stru2, CDASTTOKEN *TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTstruct_or_union_specifier(CDASTstruct_or_union *stru0, CDASTqualified_id *qual1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTstruct_or_union_specifier();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTstruct_or_union : public CDASTSyntaxElement {
public:
	CDASTstruct_or_union(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTstruct_or_union();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTstruct_declaration_list : public CDASTSyntaxElement {
public:
	CDASTstruct_declaration_list(CDASTstruct_declaration *stru0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTstruct_declaration_list(CDASTstruct_declaration_list *stru0, CDASTstruct_declaration *stru1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTstruct_declaration_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTstruct_declaration : public CDASTSyntaxElement {
public:
	CDASTstruct_declaration(CDASTspecifier_qualifier_list *spec0, CDASTstruct_declarator_list *stru1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTstruct_declaration();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTspecifier_qualifier_list : public CDASTSyntaxElement {
public:
	CDASTspecifier_qualifier_list(CDASTtype_specifier *type0, CDASTspecifier_qualifier_list *spec1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTspecifier_qualifier_list(CDASTtype_specifier *type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTspecifier_qualifier_list(CDASTtype_qualifier *type0, CDASTspecifier_qualifier_list *spec1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTspecifier_qualifier_list(CDASTtype_qualifier *type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTspecifier_qualifier_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTstruct_declarator_list : public CDASTSyntaxElement {
public:
	CDASTstruct_declarator_list(CDASTstruct_declarator *stru0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTstruct_declarator_list(CDASTstruct_declarator_list *stru0, CDASTTOKEN *TOKE1, CDASTstruct_declarator *stru2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTstruct_declarator_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTstruct_declarator : public CDASTSyntaxElement {
public:
	CDASTstruct_declarator(CDASTdeclarator *decl0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTstruct_declarator(CDASTTOKEN *TOKE0, CDASTconstant_expression *cons1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTstruct_declarator(CDASTdeclarator *decl0, CDASTTOKEN *TOKE1, CDASTconstant_expression *cons2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTstruct_declarator();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTenum_specifier : public CDASTSyntaxElement {
public:
	CDASTenum_specifier(CDASTTOKEN *TOKE0, CDASTTOKEN *TOKE1, CDASTenumerator_list *enum2, CDASTTOKEN *TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTenum_specifier(CDASTTOKEN *TOKE0, CDASTqualified_id *qual1, CDASTTOKEN *TOKE2, CDASTenumerator_list *enum3, CDASTTOKEN *TOKE4, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTenum_specifier(CDASTTOKEN *TOKE0, CDASTqualified_id *qual1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTenum_specifier();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTenumerator_list : public CDASTSyntaxElement {
public:
	CDASTenumerator_list(CDASTenumerator *enum0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTenumerator_list(CDASTenumerator_list *enum0, CDASTTOKEN *TOKE1, CDASTenumerator *enum2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTenumerator_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTenumerator : public CDASTSyntaxElement {
public:
	CDASTenumerator(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTenumerator(CDASTTOKEN *TOKE0, CDASTTOKEN *TOKE1, CDASTconstant_expression *cons2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTenumerator();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTtype_qualifier : public CDASTSyntaxElement {
public:
	CDASTtype_qualifier(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTtype_qualifier();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTdeclarator : public CDASTSyntaxElement {
public:
	CDASTdeclarator(CDASTpointer *poin0, CDASTdirect_declarator *dire1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdeclarator(CDASTdirect_declarator *dire0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTdeclarator();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTdirect_declarator : public CDASTSyntaxElement {
public:
	CDASTdirect_declarator(CDASTqualified_id *qual0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_declarator(CDASTTOKEN *TOKE0, CDASTdeclarator *decl1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_declarator(CDASTdirect_declarator *dire0, CDASTTOKEN *TOKE1, CDASTconstant_expression *cons2, CDASTTOKEN *TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_declarator(CDASTdirect_declarator *dire0, CDASTTOKEN *TOKE1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_declarator(CDASTdirect_declarator *dire0, CDASTTOKEN *TOKE1, CDASTparameter_type_list *para2, CDASTTOKEN *TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTdirect_declarator();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTpointer : public CDASTSyntaxElement {
public:
	CDASTpointer(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTpointer(CDASTTOKEN *TOKE0, CDASTtype_qualifier_list *type1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTpointer(CDASTTOKEN *TOKE0, CDASTpointer *poin1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTpointer(CDASTTOKEN *TOKE0, CDASTtype_qualifier_list *type1, CDASTpointer *poin2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTpointer();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTtype_qualifier_list : public CDASTSyntaxElement {
public:
	CDASTtype_qualifier_list(CDASTtype_qualifier *type0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTtype_qualifier_list(CDASTtype_qualifier_list *type0, CDASTtype_qualifier *type1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTtype_qualifier_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTparameter_type_list : public CDASTSyntaxElement {
public:
	CDASTparameter_type_list(CDASTparameter_list *para0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTparameter_type_list(CDASTparameter_list *para0, CDASTTOKEN *TOKE1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTparameter_type_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTparameter_list : public CDASTSyntaxElement {
public:
	CDASTparameter_list(CDASTparameter_declaration *para0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTparameter_list(CDASTparameter_list *para0, CDASTTOKEN *TOKE1, CDASTparameter_declaration *para2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTparameter_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTparameter_declaration : public CDASTSyntaxElement {
public:
	CDASTparameter_declaration(CDASTdeclaration_specifiers *decl0, CDASTdeclarator *decl1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTparameter_declaration(CDASTdeclaration_specifiers *decl0, CDASTabstract_declarator *abst1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTparameter_declaration(CDASTdeclaration_specifiers *decl0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTparameter_declaration();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTtype_name : public CDASTSyntaxElement {
public:
	CDASTtype_name(CDASTspecifier_qualifier_list *spec0, CDASTabstract_declarator *abst1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTtype_name();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTabstract_declarator : public CDASTSyntaxElement {
public:
	CDASTabstract_declarator(CDASTpointer *poin0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTabstract_declarator(CDASTdirect_abstract_declarator *dire0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTabstract_declarator(CDASTpointer *poin0, CDASTdirect_abstract_declarator *dire1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTabstract_declarator();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTdirect_abstract_declarator : public CDASTSyntaxElement {
public:
	CDASTdirect_abstract_declarator(CDASTTOKEN *TOKE0, CDASTabstract_declarator *abst1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_abstract_declarator(CDASTTOKEN *TOKE0, CDASTTOKEN *TOKE1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_abstract_declarator(CDASTTOKEN *TOKE0, CDASTconstant_expression *cons1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_abstract_declarator(CDASTdirect_abstract_declarator *dire0, CDASTTOKEN *TOKE1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_abstract_declarator(CDASTdirect_abstract_declarator *dire0, CDASTTOKEN *TOKE1, CDASTconstant_expression *cons2, CDASTTOKEN *TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_abstract_declarator(CDASTTOKEN *TOKE0, CDASTparameter_type_list *para1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTdirect_abstract_declarator(CDASTdirect_abstract_declarator *dire0, CDASTTOKEN *TOKE1, CDASTparameter_type_list *para2, CDASTTOKEN *TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTdirect_abstract_declarator();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTinitializer : public CDASTSyntaxElement {
public:
	CDASTinitializer(CDASTassignment_expression *assi0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTinitializer(CDASTTOKEN *TOKE0, CDASTinitializer_list *init1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTinitializer(CDASTTOKEN *TOKE0, CDASTinitializer_list *init1, CDASTTOKEN *TOKE2, CDASTTOKEN *TOKE3, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTinitializer();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTinitializer_list : public CDASTSyntaxElement {
public:
	CDASTinitializer_list(CDASTinitializer *init0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTinitializer_list(CDASTinitializer_list *init0, CDASTTOKEN *TOKE1, CDASTinitializer *init2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTinitializer_list();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTqualified_id : public CDASTSyntaxElement {
public:
	CDASTqualified_id(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTqualified_id(CDASTTOKEN *TOKE0, CDASTTOKEN *TOKE1, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	CDASTqualified_id(CDASTqualified_id *qual0, CDASTTOKEN *TOKE1, CDASTTOKEN *TOKE2, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTqualified_id();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTassignment_expression : public CDASTSyntaxElement {
public:
	CDASTassignment_expression(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTassignment_expression();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

class CDASTconstant_expression : public CDASTSyntaxElement {
public:
	CDASTconstant_expression(CDASTTOKEN *TOKE0, decipher::location *loc, DLNONTERMINAL_PRODUCTION_RULE pr);
	virtual ~CDASTconstant_expression();
	virtual void ASTGraphEmmiter(CDASTSyntaxElement *parent);
	virtual CDHLIRSyntaxElement *ASTToHLIRGenerationPass(CDHLIRSyntaxElement *&parent,
						CDHLIRSyntaxElement *&child);
};

#endif