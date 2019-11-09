/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\scdecl.y																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
%skeleton "lalr1.cc"
%require "2.4.1"
%defines
%define parser_class_name "DecipherParserClass"
%define namespace "decipher"

%code requires {
	#include <string>
	#include <stack>
	#include "CD_ASTSyntaxElements.h"
	#include "CD_ASTDefines.h"
	#include "location.hh"
	class DecipherParser_driver;
	class CDASTSyntaxElement;
	extern decipher::location *DLloc_;	
	using namespace std;
	extern list<string> g_TypesSymbolTable;
	extern bool g_IsInStructUnionDeclaration /*=false*/;
	extern bool g_IsTypedef /*=false*/;
	extern bool g_IsDirectDeclarator /*=false*/;
}

// The parsing context.
%parse-param { DecipherParser_driver& driver }
%lex-param { DecipherParser_driver& driver }

%locations
%initial-action{
	// Initialize the initial location.
	//@$.begin.filename = @$.end.filename = &driver.file;
};

%debug
%verbose
%error-verbose

// Symbols.
%union{
	int ival;
	char *str;
	decipher::location *loc;
	CDASTSyntaxElement *ast;
};

%code {
	#include "CD_driver.h"
}

%nonassoc <ast> LEAST
%token ENDOFFILE 0 "end of file"
%token <ast> CONSTANT_EXPRESSION SEMICOLON COMMA EQUALSIGN LBRACE RBRACE COLON LPARENTHESIS RPARENTHESIS LBRACKET RBRACKET ASTERISK 
%token <ast> INT LONG REGISTER FLOAT DOUBLE UNSIGNED SIGNED TYPE_NAME 
%token <ast> STRUCT IDENTIFIER UNION TYPEDEF ENUM EXTERN STATIC 
%token <ast> AUTO VOID ELLIPSIS CHAR SHORT TYPE_EXPRESSION 
%nonassoc <ast> CONST VOLATILE IN OUT SCOPE_OP 
%type <ast> scdeclaration_unit scdeclarations scdeclaration declaration_specifiers init_declarator_list 
init_declarator storage_class_specifier type_specifier struct_or_union_specifier struct_or_union 
struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator 
enum_specifier enumerator_list enumerator type_qualifier declarator 
direct_declarator pointer type_qualifier_list parameter_type_list parameter_list 
parameter_declaration type_name abstract_declarator direct_abstract_declarator initializer 
initializer_list qualified_id assignment_expression constant_expression 
%start scdeclaration_unit
%%
scdeclaration_unit :	{driver.m_ASTRoot = NULL; }
| scdeclarations  { $$= new CDASTscdeclaration_unit((CDASTscdeclarations *)$1 ,(decipher::location *)&yylloc ,DLAST_Scdeclaration_unit__Scdeclarations_ );driver.m_ASTRoot = $$; }
;
scdeclarations :scdeclaration  { $$= new CDASTscdeclarations((CDASTscdeclaration *)$1 ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__Scdeclaration_ ); }
| TYPE_EXPRESSION type_name  { $$= new CDASTscdeclarations((CDASTTOKEN *)$1 ,(CDASTtype_name *)$2 ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__TYPE_EXPRESSION_Type_name_ ); }
| scdeclaration scdeclarations  { $$= new CDASTscdeclarations((CDASTscdeclaration *)$1 ,(CDASTscdeclarations *)$2 ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__Scdeclaration_Scdeclarations_ ); }
| TYPE_EXPRESSION type_name scdeclarations  { $$= new CDASTscdeclarations((CDASTTOKEN *)$1 ,(CDASTtype_name *)$2 ,(CDASTscdeclarations *)$3 ,(decipher::location *)&yylloc ,DLAST_Scdeclarations__TYPE_EXPRESSION_Type_name_Scdeclarations_ ); }
;
scdeclaration :declaration_specifiers SEMICOLON  { $$= new CDASTscdeclaration((CDASTdeclaration_specifiers *)$1 ,(CDASTTOKEN *)$2 ,(decipher::location *)&yylloc ,DLAST_Scdeclaration__Declaration_specifiers_SEMICOLON_ ); }
| declaration_specifiers init_declarator_list SEMICOLON  { $$= new CDASTscdeclaration((CDASTdeclaration_specifiers *)$1 ,(CDASTinit_declarator_list *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Scdeclaration__Declaration_specifiers_Init_declarator_list_SEMICOLON_ ); }
;
declaration_specifiers :storage_class_specifier  { $$= new CDASTdeclaration_specifiers((CDASTstorage_class_specifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Storage_class_specifier_ ); }
| storage_class_specifier declaration_specifiers  { $$= new CDASTdeclaration_specifiers((CDASTstorage_class_specifier *)$1 ,(CDASTdeclaration_specifiers *)$2 ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Storage_class_specifier_Declaration_specifiers_ ); }
| type_specifier  { $$= new CDASTdeclaration_specifiers((CDASTtype_specifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_specifier_ ); }
| type_specifier declaration_specifiers  { $$= new CDASTdeclaration_specifiers((CDASTtype_specifier *)$1 ,(CDASTdeclaration_specifiers *)$2 ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_specifier_Declaration_specifiers_ ); }
| type_qualifier  { $$= new CDASTdeclaration_specifiers((CDASTtype_qualifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_qualifier_ ); }
| type_qualifier declaration_specifiers  { $$= new CDASTdeclaration_specifiers((CDASTtype_qualifier *)$1 ,(CDASTdeclaration_specifiers *)$2 ,(decipher::location *)&yylloc ,DLAST_Declaration_specifiers__Type_qualifier_Declaration_specifiers_ ); }
;
init_declarator_list :init_declarator  { $$= new CDASTinit_declarator_list((CDASTinit_declarator *)$1 ,(decipher::location *)&yylloc ,DLAST_Init_declarator_list__Init_declarator_ ); }
| init_declarator_list COMMA init_declarator  { $$= new CDASTinit_declarator_list((CDASTinit_declarator_list *)$1 ,(CDASTTOKEN *)$2 ,(CDASTinit_declarator *)$3 ,(decipher::location *)&yylloc ,DLAST_Init_declarator_list__Init_declarator_list_COMMA_Init_declarator_ ); }
;
init_declarator :declarator  { $$= new CDASTinit_declarator((CDASTdeclarator *)$1 ,(decipher::location *)&yylloc ,DLAST_Init_declarator__Declarator_ ); }
| declarator EQUALSIGN initializer  { $$= new CDASTinit_declarator((CDASTdeclarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTinitializer *)$3 ,(decipher::location *)&yylloc ,DLAST_Init_declarator__Declarator_EQUALSIGN_Initializer_ ); }
;
storage_class_specifier :TYPEDEF  {g_IsTypedef = true; $$= new CDASTstorage_class_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__TYPEDEF_ ); }
| EXTERN  { $$= new CDASTstorage_class_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__EXTERN_ ); }
| STATIC  { $$= new CDASTstorage_class_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__STATIC_ ); }
| AUTO  { $$= new CDASTstorage_class_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__AUTO_ ); }
| REGISTER  { $$= new CDASTstorage_class_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Storage_class_specifier__REGISTER_ ); }
;
type_specifier :VOID  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__VOID_ ); }
| CHAR  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__CHAR_ ); }
| SHORT  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__SHORT_ ); }
| INT  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__INT_ ); }
| LONG  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__LONG_ ); }
| FLOAT  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__FLOAT_ ); }
| DOUBLE  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__DOUBLE_ ); }
| SIGNED  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__SIGNED_ ); }
| UNSIGNED  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__UNSIGNED_ ); }
| struct_or_union_specifier  { $$= new CDASTtype_specifier((CDASTstruct_or_union_specifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__Struct_or_union_specifier_ ); }
| enum_specifier  { $$= new CDASTtype_specifier((CDASTenum_specifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__Enum_specifier_ ); }
| TYPE_NAME  { $$= new CDASTtype_specifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_specifier__TYPE_NAME_ ); }
;
struct_or_union_specifier :struct_or_union qualified_id LBRACE struct_declaration_list RBRACE  { g_IsInStructUnionDeclaration = false;$$= new CDASTstruct_or_union_specifier((CDASTstruct_or_union *)$1 ,(CDASTqualified_id *)$2 ,(CDASTTOKEN *)$3,(CDASTstruct_declaration_list *)$4 ,(CDASTTOKEN *)$5 ,(decipher::location *)&yylloc ,DLAST_Struct_or_union_specifier__Struct_or_union_Qualified_id_LBRACE_Struct_declaration_list_RBRACE_ ); }
| struct_or_union LBRACE  struct_declaration_list RBRACE  { g_IsInStructUnionDeclaration = false; $$= new CDASTstruct_or_union_specifier((CDASTstruct_or_union *)$1 ,(CDASTTOKEN *)$2 ,(CDASTstruct_declaration_list *)$3 ,(CDASTTOKEN *)$4 ,(decipher::location *)&yylloc ,DLAST_Struct_or_union_specifier__Struct_or_union_LBRACE_Struct_declaration_list_RBRACE_ ); }
| struct_or_union qualified_id %prec LEAST { $$= new CDASTstruct_or_union_specifier((CDASTstruct_or_union *)$1 ,(CDASTqualified_id *)$2 ,(decipher::location *)&yylloc ,DLAST_Struct_or_union_specifier__Struct_or_union_Qualified_id_ ); }
;
struct_or_union :STRUCT  {g_IsInStructUnionDeclaration = true; $$= new CDASTstruct_or_union((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Struct_or_union__STRUCT_ ); }
| UNION  { g_IsInStructUnionDeclaration = true; $$= new CDASTstruct_or_union((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Struct_or_union__UNION_ ); }
;
struct_declaration_list :struct_declaration  { $$= new CDASTstruct_declaration_list((CDASTstruct_declaration *)$1 ,(decipher::location *)&yylloc ,DLAST_Struct_declaration_list__Struct_declaration_ ); }
| struct_declaration_list struct_declaration  { $$= new CDASTstruct_declaration_list((CDASTstruct_declaration_list *)$1 ,(CDASTstruct_declaration *)$2 ,(decipher::location *)&yylloc ,DLAST_Struct_declaration_list__Struct_declaration_list_Struct_declaration_ ); }
;
struct_declaration :specifier_qualifier_list struct_declarator_list SEMICOLON  { $$= new CDASTstruct_declaration((CDASTspecifier_qualifier_list *)$1 ,(CDASTstruct_declarator_list *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Struct_declaration__Specifier_qualifier_list_Struct_declarator_list_SEMICOLON_ ); }
;
specifier_qualifier_list :type_specifier specifier_qualifier_list  { $$= new CDASTspecifier_qualifier_list((CDASTtype_specifier *)$1 ,(CDASTspecifier_qualifier_list *)$2 ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_specifier_Specifier_qualifier_list_ ); }
| type_specifier  { $$= new CDASTspecifier_qualifier_list((CDASTtype_specifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_specifier_ ); }
| type_qualifier specifier_qualifier_list  { $$= new CDASTspecifier_qualifier_list((CDASTtype_qualifier *)$1 ,(CDASTspecifier_qualifier_list *)$2 ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_qualifier_Specifier_qualifier_list_ ); }
| type_qualifier  { $$= new CDASTspecifier_qualifier_list((CDASTtype_qualifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Specifier_qualifier_list__Type_qualifier_ ); }
;
struct_declarator_list :struct_declarator  { $$= new CDASTstruct_declarator_list((CDASTstruct_declarator *)$1 ,(decipher::location *)&yylloc ,DLAST_Struct_declarator_list__Struct_declarator_ ); }
| struct_declarator_list COMMA struct_declarator  { $$= new CDASTstruct_declarator_list((CDASTstruct_declarator_list *)$1 ,(CDASTTOKEN *)$2 ,(CDASTstruct_declarator *)$3 ,(decipher::location *)&yylloc ,DLAST_Struct_declarator_list__Struct_declarator_list_COMMA_Struct_declarator_ ); }
;
struct_declarator :declarator  { $$= new CDASTstruct_declarator((CDASTdeclarator *)$1 ,(decipher::location *)&yylloc ,DLAST_Struct_declarator__Declarator_ ); }
| COLON constant_expression  { $$= new CDASTstruct_declarator((CDASTTOKEN *)$1 ,(CDASTconstant_expression *)$2 ,(decipher::location *)&yylloc ,DLAST_Struct_declarator__COLON_Constant_expression_ ); }
| declarator COLON constant_expression  { $$= new CDASTstruct_declarator((CDASTdeclarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTconstant_expression *)$3 ,(decipher::location *)&yylloc ,DLAST_Struct_declarator__Declarator_COLON_Constant_expression_ ); }
;
enum_specifier :ENUM LBRACE enumerator_list RBRACE  { $$= new CDASTenum_specifier((CDASTTOKEN *)$1 ,(CDASTTOKEN *)$2 ,(CDASTenumerator_list *)$3 ,(CDASTTOKEN *)$4 ,(decipher::location *)&yylloc ,DLAST_Enum_specifier__ENUM_LBRACE_Enumerator_list_RBRACE_ ); }
| ENUM qualified_id LBRACE enumerator_list RBRACE  { $$= new CDASTenum_specifier((CDASTTOKEN *)$1 ,(CDASTqualified_id *)$2 ,(CDASTTOKEN *)$3 ,(CDASTenumerator_list *)$4 ,(CDASTTOKEN *)$5 ,(decipher::location *)&yylloc ,DLAST_Enum_specifier__ENUM_Qualified_id_LBRACE_Enumerator_list_RBRACE_ ); }
| ENUM qualified_id %prec LEAST { $$= new CDASTenum_specifier((CDASTTOKEN *)$1 ,(CDASTqualified_id *)$2 ,(decipher::location *)&yylloc ,DLAST_Enum_specifier__ENUM_Qualified_id_ ); }
;
enumerator_list :enumerator  { $$= new CDASTenumerator_list((CDASTenumerator *)$1 ,(decipher::location *)&yylloc ,DLAST_Enumerator_list__Enumerator_ ); }
| enumerator_list COMMA enumerator  { $$= new CDASTenumerator_list((CDASTenumerator_list *)$1 ,(CDASTTOKEN *)$2 ,(CDASTenumerator *)$3 ,(decipher::location *)&yylloc ,DLAST_Enumerator_list__Enumerator_list_COMMA_Enumerator_ ); }
;
enumerator :IDENTIFIER  { $$= new CDASTenumerator((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Enumerator__IDENTIFIER_ ); }
| IDENTIFIER EQUALSIGN constant_expression  { $$= new CDASTenumerator((CDASTTOKEN *)$1 ,(CDASTTOKEN *)$2 ,(CDASTconstant_expression *)$3 ,(decipher::location *)&yylloc ,DLAST_Enumerator__IDENTIFIER_EQUALSIGN_Constant_expression_ ); }
;
type_qualifier :CONST  { $$= new CDASTtype_qualifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__CONST_ ); }
| VOLATILE  { $$= new CDASTtype_qualifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__VOLATILE_ ); }
| IN  { $$= new CDASTtype_qualifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__IN_ ); }
| OUT  { $$= new CDASTtype_qualifier((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_qualifier__OUT_ ); }
;
declarator :pointer direct_declarator  { $$= new CDASTdeclarator((CDASTpointer *)$1 ,(CDASTdirect_declarator *)$2 ,(decipher::location *)&yylloc ,DLAST_Declarator__Pointer_Direct_declarator_ ); }
| direct_declarator  { $$= new CDASTdeclarator((CDASTdirect_declarator *)$1 ,(decipher::location *)&yylloc ,DLAST_Declarator__Direct_declarator_ ); }
;
direct_declarator : qualified_id  { $$= new CDASTdirect_declarator((CDASTqualified_id *)$1 ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Qualified_id_ ); }
| LPARENTHESIS declarator RPARENTHESIS  { $$= new CDASTdirect_declarator((CDASTTOKEN *)$1 ,(CDASTdeclarator *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__LPARENTHESIS_Declarator_RPARENTHESIS_ ); }
| direct_declarator LBRACKET constant_expression RBRACKET  { $$= new CDASTdirect_declarator((CDASTdirect_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTconstant_expression *)$3 ,(CDASTTOKEN *)$4 ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LBRACKET_Constant_expression_RBRACKET_ ); }
| direct_declarator LBRACKET RBRACKET  { $$= new CDASTdirect_declarator((CDASTdirect_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LBRACKET_RBRACKET_ ); }
| direct_declarator LPARENTHESIS parameter_type_list RPARENTHESIS  { $$= new CDASTdirect_declarator((CDASTdirect_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTparameter_type_list *)$3 ,(CDASTTOKEN *)$4 ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LPARENTHESIS_Parameter_type_list_RPARENTHESIS_ ); }
| direct_declarator LPARENTHESIS RPARENTHESIS  { $$= new CDASTdirect_declarator((CDASTdirect_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_declarator__Direct_declarator_LPARENTHESIS_RPARENTHESIS_ ); }
;
pointer :ASTERISK %prec LEAST { $$= new CDASTpointer((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_ ); }
| ASTERISK type_qualifier_list %prec LEAST { $$= new CDASTpointer((CDASTTOKEN *)$1 ,(CDASTtype_qualifier_list *)$2 ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_Type_qualifier_list_ ); }
| ASTERISK pointer  { $$= new CDASTpointer((CDASTTOKEN *)$1 ,(CDASTpointer *)$2 ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_Pointer_ ); }
| ASTERISK type_qualifier_list pointer  { $$= new CDASTpointer((CDASTTOKEN *)$1 ,(CDASTtype_qualifier_list *)$2 ,(CDASTpointer *)$3 ,(decipher::location *)&yylloc ,DLAST_Pointer__ASTERISK_Type_qualifier_list_Pointer_ ); }
;
type_qualifier_list :type_qualifier  { $$= new CDASTtype_qualifier_list((CDASTtype_qualifier *)$1 ,(decipher::location *)&yylloc ,DLAST_Type_qualifier_list__Type_qualifier_ ); }
| type_qualifier_list type_qualifier  { $$= new CDASTtype_qualifier_list((CDASTtype_qualifier_list *)$1 ,(CDASTtype_qualifier *)$2 ,(decipher::location *)&yylloc ,DLAST_Type_qualifier_list__Type_qualifier_list_Type_qualifier_ ); }
;
parameter_type_list :parameter_list  { $$= new CDASTparameter_type_list((CDASTparameter_list *)$1 ,(decipher::location *)&yylloc ,DLAST_Parameter_type_list__Parameter_list_ ); }
| parameter_list COMMA ELLIPSIS  { $$= new CDASTparameter_type_list((CDASTparameter_list *)$1 ,(CDASTTOKEN *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Parameter_type_list__Parameter_list_COMMA_ELLIPSIS_ ); }
;
parameter_list :parameter_declaration  { $$= new CDASTparameter_list((CDASTparameter_declaration *)$1 ,(decipher::location *)&yylloc ,DLAST_Parameter_list__Parameter_declaration_ ); }
| parameter_list COMMA parameter_declaration  { $$= new CDASTparameter_list((CDASTparameter_list *)$1 ,(CDASTTOKEN *)$2 ,(CDASTparameter_declaration *)$3 ,(decipher::location *)&yylloc ,DLAST_Parameter_list__Parameter_list_COMMA_Parameter_declaration_ ); }
;
parameter_declaration :declaration_specifiers declarator  { $$= new CDASTparameter_declaration((CDASTdeclaration_specifiers *)$1 ,(CDASTdeclarator *)$2 ,(decipher::location *)&yylloc ,DLAST_Parameter_declaration__Declaration_specifiers_Declarator_ ); }
| declaration_specifiers abstract_declarator  { $$= new CDASTparameter_declaration((CDASTdeclaration_specifiers *)$1 ,(CDASTabstract_declarator *)$2 ,(decipher::location *)&yylloc ,DLAST_Parameter_declaration__Declaration_specifiers_Abstract_declarator_ ); }
| declaration_specifiers  { $$= new CDASTparameter_declaration((CDASTdeclaration_specifiers *)$1 ,(decipher::location *)&yylloc ,DLAST_Parameter_declaration__Declaration_specifiers_ ); }
;
type_name :specifier_qualifier_list abstract_declarator  { $$= new CDASTtype_name((CDASTspecifier_qualifier_list *)$1 ,(CDASTabstract_declarator *)$2 ,(decipher::location *)&yylloc ,DLAST_Type_name__Specifier_qualifier_list_Abstract_declarator_ ); }
;
abstract_declarator :pointer  { $$= new CDASTabstract_declarator((CDASTpointer *)$1 ,(decipher::location *)&yylloc ,DLAST_Abstract_declarator__Pointer_ ); }
| direct_abstract_declarator  { $$= new CDASTabstract_declarator((CDASTdirect_abstract_declarator *)$1 ,(decipher::location *)&yylloc ,DLAST_Abstract_declarator__Direct_abstract_declarator_ ); }
| pointer direct_abstract_declarator  { $$= new CDASTabstract_declarator((CDASTpointer *)$1 ,(CDASTdirect_abstract_declarator *)$2 ,(decipher::location *)&yylloc ,DLAST_Abstract_declarator__Pointer_Direct_abstract_declarator_ ); }
;
direct_abstract_declarator :LPARENTHESIS abstract_declarator RPARENTHESIS  { $$= new CDASTdirect_abstract_declarator((CDASTTOKEN *)$1 ,(CDASTabstract_declarator *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LPARENTHESIS_Abstract_declarator_RPARENTHESIS_ ); }
| LBRACKET RBRACKET  { $$= new CDASTdirect_abstract_declarator((CDASTTOKEN *)$1 ,(CDASTTOKEN *)$2 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LBRACKET_RBRACKET_ ); }
| LBRACKET constant_expression RBRACKET  { $$= new CDASTdirect_abstract_declarator((CDASTTOKEN *)$1 ,(CDASTconstant_expression *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LBRACKET_Constant_expression_RBRACKET_ ); }
| direct_abstract_declarator LBRACKET RBRACKET  { $$= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LBRACKET_RBRACKET_ ); }
| direct_abstract_declarator LBRACKET constant_expression RBRACKET  { $$= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTconstant_expression *)$3 ,(CDASTTOKEN *)$4 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LBRACKET_Constant_expression_RBRACKET_ ); }
| LPARENTHESIS RPARENTHESIS  { $$= new CDASTdirect_abstract_declarator((CDASTTOKEN *)$1 ,(CDASTTOKEN *)$2 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LPARENTHESIS_RPARENTHESIS_ ); }
| LPARENTHESIS parameter_type_list RPARENTHESIS  { $$= new CDASTdirect_abstract_declarator((CDASTTOKEN *)$1 ,(CDASTparameter_type_list *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__LPARENTHESIS_Parameter_type_list_RPARENTHESIS_ ); }
| direct_abstract_declarator LPARENTHESIS RPARENTHESIS  { $$= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LPARENTHESIS_RPARENTHESIS_ ); }
| direct_abstract_declarator LPARENTHESIS parameter_type_list RPARENTHESIS  { $$= new CDASTdirect_abstract_declarator((CDASTdirect_abstract_declarator *)$1 ,(CDASTTOKEN *)$2 ,(CDASTparameter_type_list *)$3 ,(CDASTTOKEN *)$4 ,(decipher::location *)&yylloc ,DLAST_Direct_abstract_declarator__Direct_abstract_declarator_LPARENTHESIS_Parameter_type_list_RPARENTHESIS_ ); }
;
initializer :assignment_expression  { $$= new CDASTinitializer((CDASTassignment_expression *)$1 ,(decipher::location *)&yylloc ,DLAST_Initializer__Assignment_expression_ ); }
| LBRACE initializer_list RBRACE  { $$= new CDASTinitializer((CDASTTOKEN *)$1 ,(CDASTinitializer_list *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Initializer__LBRACE_Initializer_list_RBRACE_ ); }
| LBRACE initializer_list COMMA RBRACE  { $$= new CDASTinitializer((CDASTTOKEN *)$1 ,(CDASTinitializer_list *)$2 ,(CDASTTOKEN *)$3 ,(CDASTTOKEN *)$4 ,(decipher::location *)&yylloc ,DLAST_Initializer__LBRACE_Initializer_list_COMMA_RBRACE_ ); }
;
initializer_list :initializer  { $$= new CDASTinitializer_list((CDASTinitializer *)$1 ,(decipher::location *)&yylloc ,DLAST_Initializer_list__Initializer_ ); }
| initializer_list COMMA initializer  { $$= new CDASTinitializer_list((CDASTinitializer_list *)$1 ,(CDASTTOKEN *)$2 ,(CDASTinitializer *)$3 ,(decipher::location *)&yylloc ,DLAST_Initializer_list__Initializer_list_COMMA_Initializer_ ); }
;
qualified_id :IDENTIFIER  { if ( g_IsTypedef && !g_IsInStructUnionDeclaration ){
								g_TypesSymbolTable.push_back((string)((CDASTTOKEN *)$1)->m_tokenstring);
								g_IsTypedef = false;
								g_IsDirectDeclarator = false;
							}
							$$= new CDASTqualified_id((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Qualified_id__IDENTIFIER_ ); }
| SCOPE_OP IDENTIFIER  {	if ( g_IsTypedef && !g_IsInStructUnionDeclaration ){
								g_TypesSymbolTable.push_back((string)((CDASTTOKEN *)$1)->m_tokenstring);
								g_IsTypedef = false;
								g_IsDirectDeclarator = false;
							}
							$$= new CDASTqualified_id((CDASTTOKEN *)$1 ,(CDASTTOKEN *)$2 ,(decipher::location *)&yylloc ,DLAST_Qualified_id__SCOPE_OP_IDENTIFIER_ ); }
| qualified_id SCOPE_OP IDENTIFIER  { $$= new CDASTqualified_id((CDASTqualified_id *)$1 ,(CDASTTOKEN *)$2 ,(CDASTTOKEN *)$3 ,(decipher::location *)&yylloc ,DLAST_Qualified_id__Qualified_id_SCOPE_OP_IDENTIFIER_ ); }
;
assignment_expression :CONSTANT_EXPRESSION  { $$= new CDASTassignment_expression((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Assignment_expression__CONSTANT_EXPRESSION_ ); }
;
constant_expression :CONSTANT_EXPRESSION  { $$= new CDASTconstant_expression((CDASTTOKEN *)$1 ,(decipher::location *)&yylloc ,DLAST_Constant_expression__CONSTANT_EXPRESSION_ ); }
;
%%
bool g_IsDirectDeclarator =false;
bool g_IsInStructUnionDeclaration=false;
bool g_IsTypedef=false;