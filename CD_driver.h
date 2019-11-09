/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\CD_driver.h																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
#ifndef SCDECL_DRIVER_HH
#define SCDECL_DRIVER_HH
#include "decipher.tab.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <list>
#include "CD_ASTSyntaxElements.h"
#include "CD_HLIRSyntaxElements.h"
extern void yyrestart(FILE *);
using namespace std;
extern decipher::location* DLloc_;
class DecipherParser_driver;
// Tell Flex the lexer’s prototype ...
#define YY_DECL \
decipher::DecipherParserClass::token_type \
yylex (decipher::DecipherParserClass::semantic_type* yylval, \
	decipher::DecipherParserClass::location_type* yylloc, \
	DecipherParser_driver& driver)
// ... and declare it for the parser’s sake.
YY_DECL;
// Conducting the whole scanning and parsing of Calc++.
class CDHLIRSyntaxElement;
class DecipherParser_driver{
public:
	DecipherParser_driver (int numfiles, char** files);
	virtual ~DecipherParser_driver();

	bool trace_scanning;
	bool trace_parsing;

	void scan_begin(string filename);
	void scan_end();
	// Run the parser. Return 0 on success.
	int parse();
	CDHLIRSyntaxElement *GenerateHLIR();
	int Extract_HLIR_Graph(string outputFile);
	void CDecl();

	std::list<string> m_files;
	// The file that we currently process.
	FILE *m_curfile;
	void Extract_AST_Graph(string filename);

	// Error handling.
	void error (const decipher::location& l, const std::string& m);
	void error (const std::string& m);
public:
	CDASTSyntaxElement *m_ASTRoot;
	CDHLIRSyntaxElement *m_HLIRRoot;	
};
#endif // ! SCDECL_DRIVER_HH
