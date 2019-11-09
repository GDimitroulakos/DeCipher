/* *********************************************************************************** */
/* Title :							      */
/* File :CD_HLIRDefines.h																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* CoAuthor: Christakis Lezos																  */
/* Creation Date: 12/3/2012		*/
/* *********************************************************************************** */
#ifndef DLHLIRDEFINES_
#define DLHLIRDEFINES_
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "CD_Defines.h"
#include "CD_HLIRTemplates.h"

extern char const *g_DLHLIRtypeidentifier[];
extern char const *g_DLHLIRcontextidentifier[];

typedef enum typespecifiers_{
	POINTER, FUNCTION, ARRAY, STRUCT, UNION, 
	INT, FLOAT, DOUBLE, LONG, SHORT, CHAR
} TYPESPECIFIERS;

class CDHLIRSyntaxElement;

/*
typedef enum constant_category{
	CC_INTEGER_DECIMAL=0, CC_INTEGER_OCTAL, CC_INTEGER_HEX,
	CC_FLOATING, CC_CHARACTER, CC_CHARACTER_HEX_ESCSEQ,
	CC_CHARACTER_OCTAL_ESCSEQ, CC_CHARACTER_UNIVERSAL_ESCSEQ,
	CC_CHARACTER_SIMPLE_ESCSEQ
}CONSTANT_CATEGORY;
}
*/
/*
typedef union tokenvalue_{
	int i;
	unsigned int ui;
	long long int ill;
	unsigned long long int uill;
	long double ld;
	double d;
	float f;
} TOKENVALUE;
*/
/*
typedef struct constant_properties{
	constant_properties();
	constant_properties(const constant_properties &Init);
	~constant_properties();	
	CONSTANT_CATEGORY m_ConstantCategory;
	TOKENVALUE m_tokenvalue;    // Applicable in arithmetic tokens. Especially
	// for character constants Holds the ASCII
	// or Universal code 
	char * m_actualvaluestring; // The string after removing prefixes and suffixes
	unsigned char m_longness;   // How many l s are used to indicate constant width ( <=2)
	unsigned char m_signness;   // How many u s are used to indicate sign ( <=1)
	unsigned char m_floatness;  // How many f s are used to indicate float ( <=1)
	unsigned char m_wideness;   // Applicable to character constants ( <=1)
	unsigned char m_eschexseq;  // Applicable to character constants indicates
	// hexadecimal escape character sequence ( <=1)
	unsigned char m_escoctseq;  // Applicable to character constants indicates
	// octal escape character sequence ( <=1)
	unsigned char m_escdecseq;  // Applicable to character constants indicates
	// decimal escape character sequence ( <=1)
	unsigned char m_escuniseq;  // Applicable to character constants indicates
	// decimal escape character sequence ( <=1)
} CONSTANT_PROPERTIES;
*/

typedef enum DLhlir_syntaxelements_category{
	DLCAT_NOTINITIALIZED,DLCAT_EXPRESSION, DLCAT_DECLARATION,
	DLCAT_STATEMENT, DLCAT_TYPEEXPRESSION
} DLHLIR_ELEMENT_CATEGORY;

typedef enum DLobject_categories{
	DLOC_GENERAL=-1, DLOC_FORLOOPS=0, DLOC_FUNDEF
}DLOBJECT_CATEGORY;

typedef enum DLcompile_time_error_actions{
	DLERR_EXIT, DLERR_INFORM, DLERR_FLAG
} DLERRACT;

typedef enum DLexpression_result_type{
	DLL_VALUE=0, DLR_VALUE, DLNOT_APPLICABLE
} DLEXPRESSION_RESULT_TYPE;

typedef enum DLexpression_associativity{
	DLLL_TO_R=0, DLR_TO_L, DLASS_NOT_APPLICABLE
}DLEXPRESSION_ASSOCIATIVITY;

typedef enum DLhlir_syntaxelements_type{
	DL_Unitialized= 0,

	DLE_IDENTIFIER,	
	DLE_CONSTANT,
	DLE_STRINGLITERAL,

	DLE_GroupingExpression,

	DLE_FunctionCall,
	DLE_ArrayReference,
	DLE_StructureMember,
	DLE_StructurePointerMember,
	DLE_PostfixIncreament,
	DLE_PostfixDecreament,

	DLE_LogicalNegate,
	DLE_OnesComplement,
	DLE_UnaryPlus,
	DLE_UnaryMinus,
	DLE_PrefixIncreament,
	DLE_PrefixDecreament,
	DLE_Indirection,
	DLE_AddressOf,
	DLE_SizeOf_Expression,
	DLE_SizeOf_Type,

	DLE_TypeConversion,

	DLE_Multiplication,
	DLE_Division,
	DLE_IntegerRemainder,
	DLE_Addition,
	DLE_Subtraction,
	DLE_LeftShift,
	DLE_RightShift,

	DLE_GreaterThan,
	DLE_GreaterThanOrEqual,	
	DLE_LessThan,
	DLE_LessThanOrEqual,
	DLE_EqualTo,
	DLE_NotEqualTo,

	DLE_BitwiseAND,
	DLE_BitwiseExclusiveOR,
	DLE_BitwiseInclusiveOR,
	DLE_LogicalAND,
	DLE_LogicalOR,

	DLE_Conditional,

	DLE_Assignment,
	DLE_AssignmentAddTo,
	DLE_AssignmentSubtractFrom,
	DLE_AssignmentMultiplyBy,
	DLE_AssignmentDivideBy,
	DLE_AssignmentModuloBy,
	DLE_AssignmentShiftLeftBy,
	DLE_AssignmentShiftRightBy,
	DLE_AssignmentANDWith,
	DLE_AssignmentExclusiveORWith,
	DLE_AssignmentInclusiveORWith,
	DLE_CommaExpression,

	DLS_Compound,
	DLS_Label,
	DLS_LabelCase,
	DLS_LabelDefault,
	DLS_ExpressionStatement,
	DLS_WhileLoop,
	DLS_DoWhileLoop,	
	DLS_ForLoop,
	DLS_If,
	DLS_Switch,
	DLS_GOTO,
	DLS_Break,
	DLS_Continue,
	DLS_Return,

	DLT_VoidType,
	DLT_IntegerType,
	DLT_FloatingPointType,
	DLT_CharacterType,
	DLT_EnumeratedType_Decl,
	DLT_EnumeratedType_Def,
	DLT_ArrayType,
	DLT_StructureType_Decl,
	DLT_StructureType_Def,
	DLT_UnionType_Decl,
	DLT_UnionType_Def,
	DLT_FunctionType,
	DLT_PointerType,

	DL_ROOT,
	DL_TranslationUnit,	
	DL_Declaration,
	DL_TypeDeclaration,
	DL_Typename,
	DL_Declarator,
	DL_TypeQualifier,
	DL_TypeSpecifier,
	DL_Initializer,		
	DL_Enumerator,
	DL_FunctionDefinition
} DLHLIR_ELEMENT_TYPE;

typedef enum DLhlir_contexts{
	DLE_NotApplicable = -1,
	DL_Root_RootSingleContext =0,
	
	DLE_Grouping_Expression,

	DLE_FunctionCall_FunctionName,
	DLE_FunctionCall_Arguments,

	DLE_ArraySubscript_ArrayBase,
	DLE_ArraySubscript_ArraySubscript,

	DLE_StructureMember_StructureBase,
	DLE_StructureMember_Member,

	DLE_StructurePointerMember_StructurePointer,
	DLE_StructurePointerMember_StructurePointerMember,

	DLE_BinaryExpression_Argument1,
	DLE_BinaryExpression_Argument2,

	DLE_UnaryExpression_Argument,

	DLE_TypeConversion_Type,
	DLE_TypeConversion_expression,

	DLE_ConditionalExpression_Condition,
	DLE_ConditionalExpression_TrueAlternative,
	DLE_ConditionalExpression_FalseAlternative,

	DLE_Assignment_LHS,
	DLE_Assignment_RHS,

	DLE_CommaExpression_Argument1,
	DLE_CommaExpression_Argument2,

	DLS_CompoundStatement_Declarations,
	DLS_CompoundStatement_Statements,

	DLS_Label_Identifier,
	DLS_Label_Statement,

	DLS_LabelCase_Expression,
	DLS_LabelCase_Statement,

	DLS_LabelDefault_Statement,

	DLS_ExpressionStatement_Expression,

	DLS_WhileLoopStatement_Expression,
	DLS_WhileLoopStatement_Statement,

	DLS_DoWhileLoop_Statement,
	DLS_DoWhileLoop_Expression,

	DLS_ForLoop_Initialization,
	DLS_ForLoop_Finalization,
	DLS_ForLoop_Adjustment,
	DLS_ForLoop_Body,

	DLS_If_Expression,
	DLS_If_Statement,
	DLS_If_ElseStatement,

	DLS_Switch_Expression,
	DLS_Switch_Statement,

	DLS_GOTO_Identifier,	
	DLS_Return_Expression,

	DLT_ArrayType_ElementType,
	DLT_ArrayType_ArraySize,

	DLT_FunctionType_FunctionReferenceType,	
	DLT_FunctionType_Parameters,

	DLT_PointerType_PointerType,	

	DLT_StructureType_Declarations,
	DLT_StructureType_StructureTag,

	DLT_UnionType_Declarations,
	DLT_UnionType_UnionTag,

	DLT_EnumeratedType_Identifier,
	DLT_EnumeratedType_Enumerators,

	DL_TranslationUnit_Declaration,
	DL_TranslationUnit_FunctionDefinition,

	DL_Declaration_Declarators,
	DL_Declaration_TypeSpecifiers,	
	DL_Declaration_TypeQualifiers,

	DL_Typename_TypeSpecifiers,
	DL_Typename_TypeExpression,
	DL_Typename_TypeQualifiers,

	DL_Declarator_identifier,
	DL_Declarator_TypeExpression,
	DL_Declarator_Initializer,

	DL_TypeQualifier_TypeExpression,

	DL_TypeSpecifier_TypeName,

	DL_Initializer_Initializers,

	DL_Enumerator_Identifier,
	DL_Enumerator_IntegerInitializer,

	DL_FunctionDefinition_CompoundStatement,
	DL_FunctionDefinition_Declarator,
	DL_FunctionDefinition_TypeSpecifiers,
	DL_FunctionDefinition_TypeQualifiers
} DLHLIR_CONTEXT;


class type_info_ {
public:
	
	string m_DeclaratorName;
	string m_DeclaratorUnscrambledType;		
	list<CDHLIRSyntaxElement *> m_TypeTree;	
} ;
 
#endif