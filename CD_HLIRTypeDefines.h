///////////////////////////////////////////////////////////////////////////
////// Author : Grigorios Dimitroulakos  //////////////////////////////////
////// File   : TypeDefines.h	 //////////////////////////////////
////// Date of Creation : 05/2011       //////////////////////////////////
////// Phase 1 Completed :              //////////////////////////////////
////// Purpose(Phase 1): 
///////////////////////////////////////////////////////////////////////////
#ifndef DLTYPE_DEFINES
#define DLTYPE_DEFINES
#include <iostream>
#include <string>

using namespace std;

typedef struct DLenumaration_constant{
	string m_Identifier;
	int	  m_IdentifierValue;
} DLENUM_CONSTANT;

struct DLtype_spec_alternatives{
	unsigned int m_bitwidth;
	int m_signed; // -1 NA, 0 unsigned, 1 signed
	enum DLtype_specifiers m_typespecifier[5];
	char *const m_string;
	char *const m_GraphvizFrientlyString;
};

extern struct DLtype_spec_alternatives DLg_type_specs[31];
extern const string DLlinkage_string[];
extern const string g_DLstorage_class_string[];
extern const string g_DLtype_qualifier_string[];
extern char const *g_DLType_Specifier_Strings[];
typedef enum{DLSGN_SIGNED=0, DLSGN_UNSIGNED} DLINTEGER_SIGNNESS;
typedef enum{DLPRC_SHORT=0, DLPRC_REGULAR, DLPRC_LONG, DLPRC_LONGLONG, DLPRC_CHAR } DLINTEGER_PRECISION;
typedef enum{DLFPRC_FLOAT=0, DLFPRC_DOUBLE, DLFPRC_LONGDOUBLE} DLFLOATING_PRECISION;
typedef enum DLlinkage_types {	DLLT_EXTERN=0, DLLT_STATIC, DLLT_NONE,
DLLT_UNITIALIZED } DLLINKAGE_TYPE;  

typedef enum DLstorage_class_types { DLSCT_AUTO=0, DLSCT_REGISTER , 
DLSCT_STATIC , DLSCT_EXTERN ,
DLSCT_TYPEDEF,DLSCT_UNITIALIZED } DLSTORAGE_CLASS;
typedef enum DLtype_qualifiers { DLTQL_CONST=0, DLTQL_VOLATILE , 
DLTQL_IN, DLTQL_OUT ,DLTQL_UNITIALIZED } DLTYPE_QUALIFIER;
typedef enum DLfunction_specifier { DLFSP_INLINE=0, DLFSP_UNITIALIZED  } DLFUNCTION_SPECIFIER;
typedef enum DLtype_compleXity{
	DLTX_UNKNOWN=0, 
	DLTX_BASIC,
	DLTX_DERIVED	
}DLTYPE_COMPLEXITY;

typedef enum message_types {
	MSG_TYPE_SPECIFIER =0,
	MSG_STORAGE_CLASS,
	MSG_FUNCTION_SPECIFIER,
	MSG_INSTALL_TYPE_SPECIFIER
} MESSAGE_TYPE;

typedef enum DLtype_Categories{
	DLTC_UNKNOWN=0,
	DLTC_VOID,
	DLTC_INTEGER, 
	DLTC_FLOAT,
	DLTC_ARRAY,
	DLTC_STRUCTURE,
	DLTC_UNION,
	DLTC_FUNCTION,
	DLTC_POINTER
}DLTYPE_CATEGORY;

typedef enum DLtype_specifiers{
	DLTSP_UNKNOWN = 0,
	DLTSP_VOID,
	DLTSP_CHAR,
	DLTSP_SHORT,
	DLTSP_INT,
	DLTSP_LONG,
	DLTSP_SIGNED,
	DLTSP_UNSIGNED,
	DLTSP_FLOAT,
	DLTSP_DOUBLE,
	DLTSP_TYPENAME
}DLTYPE_SPECIFIERS;


#endif