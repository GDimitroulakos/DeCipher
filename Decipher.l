/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\scdecl.l																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
%option noyywrap
/*%option noyywrap batch debug option for scanner removed*/
%{
#include <iostream>
#include "CD_ASTSyntaxElements.h"
#include "CD_driver.h"
#include "Decipher.tab.h"
//#define DEBUG_SCANNER1
inline void DEBUG(decipher::DecipherParserClass::location_type*, char *text=NULL);
/* By default yylex returns int, we use token_type.
Unfortunately yyterminate by default returns 0, which is
not of token_type. */
#define yyterminate() return token::ENDOFFILE
typedef decipher::DecipherParserClass::token token;
CDASTTOKEN *newtoken;
list<string> g_TypesSymbolTable;
bool IsTypeName(string name);
%}
%{
#define YY_USER_ACTION yylloc->columns(yyleng);
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%%

%{
yylloc->step();
%}


[0-9]+		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_CONSTANT_EXPRESSION, yylloc, DLTOKEN_CONSTANT_EXPRESSION, yytext);
					  yylval->ast = newtoken;
					  return token::CONSTANT_EXPRESSION;
				}
"int"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_INT, yylloc, DLTOKEN_INT, yytext);
					  yylval->ast = newtoken;
					  return token::INT;
				}
"long"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_LONG, yylloc, DLTOKEN_LONG, yytext);
					  yylval->ast = newtoken;
					  return token::LONG;
				}
"register"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_REGISTER, yylloc, DLTOKEN_REGISTER, yytext);
					  yylval->ast = newtoken;
					  return token::REGISTER;
				}
"float"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_FLOAT, yylloc, DLTOKEN_FLOAT, yytext);
					  yylval->ast = newtoken;
					  return token::FLOAT;
				}
"double"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_DOUBLE, yylloc, DLTOKEN_DOUBLE, yytext);
					  yylval->ast = newtoken;
					  return token::DOUBLE;
				}
"unsigned"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_UNSIGNED, yylloc, DLTOKEN_UNSIGNED, yytext);
					  yylval->ast = newtoken;
					  return token::UNSIGNED;
				}
"signed"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_SIGNED, yylloc, DLTOKEN_SIGNED, yytext);
					  yylval->ast = newtoken;
					  return token::SIGNED;
				}
regexp_TYPE_NAME		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_TYPE_NAME, yylloc, DLTOKEN_TYPE_NAME, yytext);
					  yylval->ast = newtoken;
					  return token::TYPE_NAME;
				}
"struct"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_STRUCT, yylloc, DLTOKEN_STRUCT, yytext);
					  yylval->ast = newtoken;
					  return token::STRUCT;
				}
"union"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_UNION, yylloc, DLTOKEN_UNION, yytext);
					  yylval->ast = newtoken;
					  return token::UNION;
				}
"typedef"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_TYPEDEF, yylloc, DLTOKEN_TYPEDEF, yytext);
					  yylval->ast = newtoken;
					  return token::TYPEDEF;
				}
"enum"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_ENUM, yylloc, DLTOKEN_ENUM, yytext);
					  yylval->ast = newtoken;
					  return token::ENUM;
				}
"extern"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_EXTERN, yylloc, DLTOKEN_EXTERN, yytext);
					  yylval->ast = newtoken;
					  return token::EXTERN;
				}
"static"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_STATIC, yylloc, DLTOKEN_STATIC, yytext);
					  yylval->ast = newtoken;
					  return token::STATIC;
				}
"auto"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_AUTO, yylloc, DLTOKEN_AUTO, yytext);
					  yylval->ast = newtoken;
					  return token::AUTO;
				}
"void"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_VOID, yylloc, DLTOKEN_VOID, yytext);
					  yylval->ast = newtoken;
					  return token::VOID;
				}
"..."		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_ELLIPSIS, yylloc, DLTOKEN_ELLIPSIS, yytext);
					  yylval->ast = newtoken;
					  return token::ELLIPSIS;
				}
"char"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_CHAR, yylloc, DLTOKEN_CHAR, yytext);
					  yylval->ast = newtoken;
					  return token::CHAR;
				}
"short"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_SHORT, yylloc, DLTOKEN_SHORT, yytext);
					  yylval->ast = newtoken;
					  return token::SHORT;
				}
"const"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_CONST, yylloc, DLTOKEN_CONST, yytext);
					  yylval->ast = newtoken;
					  return token::CONST;
				}
"volatile"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_VOLATILE, yylloc, DLTOKEN_VOLATILE, yytext);
					  yylval->ast = newtoken;
					  return token::VOLATILE;
				}
"in"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_IN, yylloc, DLTOKEN_IN, yytext);
					  yylval->ast = newtoken;
					  return token::IN;
				}
"out"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_OUT, yylloc, DLTOKEN_OUT, yytext);
					  yylval->ast = newtoken;
					  return token::OUT;
				}
"::"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_SCOPE_OP, yylloc, DLTOKEN_SCOPE_OP, yytext);
					  yylval->ast = newtoken;
					  return token::SCOPE_OP;
				}
";"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_SEMICOLON, yylloc, DLTOKEN_SEMICOLON, yytext);
					  yylval->ast = newtoken;
					  return token::SEMICOLON;
				}
","		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_COMMA, yylloc, DLTOKEN_COMMA, yytext);
					  yylval->ast = newtoken;
					  return token::COMMA;
				}
"="		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_EQUALSIGN, yylloc, DLTOKEN_EQUALSIGN, yytext);
					  yylval->ast = newtoken;
					  return token::EQUALSIGN;
				}
"{"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_LBRACE, yylloc, DLTOKEN_LBRACE, yytext);
					  yylval->ast = newtoken;
					  return token::LBRACE;
				}
"}"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_RBRACE, yylloc, DLTOKEN_RBRACE, yytext);
					  yylval->ast = newtoken;
					  return token::RBRACE;
				}
":"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_COLON, yylloc, DLTOKEN_COLON, yytext);
					  yylval->ast = newtoken;
					  return token::COLON;
				}
"("		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_LPARENTHESIS, yylloc, DLTOKEN_LPARENTHESIS, yytext);
					  yylval->ast = newtoken;
					  return token::LPARENTHESIS;
				}
")"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_RPARENTHESIS, yylloc, DLTOKEN_RPARENTHESIS, yytext);
					  yylval->ast = newtoken;
					  return token::RPARENTHESIS;
				}
"["		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_LBRACKET, yylloc, DLTOKEN_LBRACKET, yytext);
					  yylval->ast = newtoken;
					  return token::LBRACKET;
				}
"]"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_RBRACKET, yylloc, DLTOKEN_RBRACKET, yytext);
					  yylval->ast = newtoken;
					  return token::RBRACKET;
				}
"*"		{ DEBUG(yylloc); newtoken = new CDASTTOKEN(DLT_ASTERISK, yylloc, DLTOKEN_ASTERISK, yytext);
					  yylval->ast = newtoken;
					  return token::ASTERISK;
				}
{L}({L}|{D})*		{ DEBUG(yylloc); 
					  if ( IsTypeName((string)yytext) ){
						 newtoken = new CDASTTOKEN(DLT_TYPE_NAME, yylloc, DLTOKEN_TYPE_NAME, yytext);
						 yylval->ast = newtoken;
						 return token::TYPE_NAME;
					  }
					  else{
						 newtoken = new CDASTTOKEN(DLT_IDENTIFIER, yylloc, DLTOKEN_IDENTIFIER, yytext);
						 yylval->ast = newtoken;
						 return token::IDENTIFIER;
					  }
					 
					}
"//%%"				{ return token::ENDOFFILE;}
%%
inline void DEBUG(decipher::DecipherParserClass::location_type* yylloc, char *text){
#ifdef DEBUG_SCANNER1
	if (text == NULL ){
		cout << endl << "yytext:"<<scdecltext
		<< endl << "line:" << *yylloc;
	}
	else{
		cout << endl << "yytext:" << text
		<< endl << "line:" << *yylloc;
	}
#endif
}
bool IsTypeName(string name){
list<string>::iterator it;
	for ( it = g_TypesSymbolTable.begin(); it != g_TypesSymbolTable.end(); it ++){
		if ( name == (*it)){
			return true;
		}
	}
return false;
}