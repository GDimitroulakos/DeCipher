#include "CD_HLIRDefines.h"

char const *signstrings[]={"signed","unsigned"};
char const *integerprecisionstrings[]={"short","int","long","long long", "char"};

char const *g_DLHLIRtypeidentifier[]={
	"_Unitialized",

	"E_IDENTIFIER",
	"E_CONSTANT",
	"E_STRINGLITERAL",

	"E_GroupingExpression",

	"E_FunctionCall",
	"E_ArrayReference",
	"E_StructureMember",
	"E_StructurePointerMember",
	"E_PostfixIncreament",
	"E_PostfixDecreament",

	"E_LogicalNegate",
	"E_OnesComplement",
	"E_UnaryPlus",
	"E_UnaryMinus",
	"E_PrefixIncreament",
	"E_PrefixDecreament",
	"E_Indirection",
	"E_AddressOf",
	"E_SizeOf_Expression",
	"E_SizeOf_Type",

	"E_TypeConversion",

	"E_Multiplication",
	"E_Division",
	"E_IntegerRemainder",
	"E_Addition",
	"E_Subtraction",
	"E_LeftShift",
	"E_RightShift",

	"E_GreaterThan",
	"E_GreaterThanOrEqual",	
	"E_LessThan",
	"E_LessThanOrEqual",
	"E_EqualTo",
	"E_NotEqualTo",

	"E_BitwiseAND",
	"E_BitwiseExclusiveOR",
	"E_BitwiseInclusiveOR",
	"E_LogicalAND",
	"E_LogicalOR",

	"E_Conditional",

	"E_Assignment",
	"E_AssignmentAddTo",
	"E_AssignmentSubtractFrom",
	"E_AssignmentMultiplyBy",
	"E_AssignmentDivideBy",
	"E_AssignmentModuloBy",
	"E_AssignmentShiftLeftBy",
	"E_AssignmentShiftRightBy",
	"E_AssignmentANDWith",
	"E_AssignmentExclusiveORWith",
	"E_AssignmentInclusiveORWith",
	"E_CommaExpression",

	"S_CompoundStatement",
	"S_Label",
	"S_LabelCase",
	"S_LabelDefault",
	"S_ExpressionStatement",
	"S_WhileLoop",
	"S_DoWhileLoop",	
	"S_ForLoop",
	"S_If",
	"S_Switch",
	"S_GOTO",
	"S_Break",
	"S_Continue",
	"S_Return",

	"T_VoidType",
	"T_IntegerType",
	"T_FloatingPointType",
	"T_CharacterType",
	"T_EnumeratedType_Decl",
	"T_EnumeratedType_Def",
	"T_ArrayType",
	"T_StructureType_Decl",
	"T_StructureType_Def",
	"T_UnionType_Decl",
	"T_UnionType_Def",
	"T_FunctionType",
	"T_PointerType",

	"_ROOT",
	"_TranslationUnit",
	"_Declaration",
	"_TypeDeclaration",
	"_Typename",
	"_Declarator",
	"_TypeQualifier",
	"_TypeSpecifier",
	"_Initializer",
	"_Enumerator",
	"_FunctionDefinition"
};
char const *g_DLHLIRcontextidentifier[]={
	"_Root_RootSingleContext",
	
	"E_Grouping_Expression",

	"E_FunctionCall_FunctionName",
	"E_FunctionCall_Arguments",

	"E_ArrayReference_ArrayBase",
	"E_ArrayReference_ArraySubscript",

	"E_StructureMember_StructureBase",
	"E_StructureMember_Member",

	"E_StructurePointerMember_StructurePointer",
	"E_StructurePointerMember_StructurePointerMember",

	"E_BinaryExpression_Argument1",
	"E_BinaryExpression_Argument2",

	"E_UnaryExpression_Argument",
	
	"E_TypeConversion_Type",
	"E_TypeConversion_expression",

	"E_ConditionalExpression_Condition",
	"E_ConditionalExpression_TrueAlternative",
	"E_ConditionalExpression_FalseAlternative",

	"E_Assignment_LHS",
	"E_Assignment_RHS",

	"E_CommaExpression_Argument1",
	"E_CommaExpression_Argument2",

	"S_CompoundStatement_Declarations",
	"S_CompoundStatement_Statements",
	
	"S_Label_Identifier",
	"S_Label_Statement",

	"S_LabelCase_Expression",
	"S_LabelCase_Statement",

	"S_LabelDefault_Statement",
	
	"S_ExpressionStatement_Expression",

	"S_WhileLoopStatement_Expression",
	"S_WhileLoopStatement_Statement",

	"S_DoWhileLoop_Statement",
	"S_DoWhileLoop_Expression",

	"S_ForLoop_Initialization",
	"S_ForLoop_Finalization",
	"S_ForLoop_Adjustment",
	"S_ForLoop_Body",

	"S_If_Expression",
	"S_If_Statement",
	"S_If_ElseStatement",

	"S_Switch_Expression",
	"S_Switch_Statement",

	"S_GOTO_Identifier",	
	"S_Return_Expression",	

	"T_ArrayType_ElementType",
	"T_ArrayType_ArraySize",
	
	"T_FunctionType_FunctionReferenceType",	
	"T_FunctionType_Parameters",
	
	"T_PointerType_PointerType",

	"T_StructureType_Declarations",
	"T_StructureType_StructureTag",

	"T_UnionType_Declarations",
	"T_UnionType_UnionTag",
	
	"T_EnumeratedType_Identifier",
	"T_EnumeratedType_Enumerators",

	"_TranslationUnit_Declaration",
	"_TranslationUnit_FunctionDefinition",

	"_Declaration_Declarators",
	"_Declaration_TypeSpecifiers",
	"_Declaration_TypeQualifiers",
	
	"_Typename_TypeSpecifiers",
	"_Typename_TypeExpression",
	"_Typename_TypeQualifiers",	
	
	"_Declarator_identifier",
	"_Declarator_TypeExpression",
	"_Declarator_Initializer",
	
	"_TypeQualifier_TypeExpression",

	"_TypeSpecifier_TypeName",
	
	"_Initializer_Initializers",
	
	"_Enumerator_Identifier",
	"_Enumerator_IntegerInitializer",
	
	"_FunctionDefinition_CompoundStatement",
	"_FunctionDefinition_Declarator",
	"_FunctionDefinition_TypeSpecifiers",
	"_FunctionDefinition_TypeQualifiers"
};

