/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\CD_driver.cpp																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
#include "CD_driver.h"
#include "Decipher.tab.h"

DecipherParser_driver::DecipherParser_driver(int numfiles, char** files)
: trace_scanning(false), trace_parsing(false){
int i;
	m_ASTRoot=NULL;
	for(i=0; i<numfiles; i++){
		m_files.push_back((string)files[i]);
	}
}
DecipherParser_driver::~DecipherParser_driver(){
}
int DecipherParser_driver::parse(){
list<string>::iterator it;

int res=0;
	for( it = m_files.begin(); it != m_files.end(); it++){
		scan_begin(*it);
		decipher::DecipherParserClass parser(*this);
		parser.set_debug_level(trace_parsing);
		res = parser.parse();
		if ( m_ASTRoot != NULL ){
			//Extract_AST_Graph("AST_CDecl.dot");
		}		
		scan_end();
	}
return res;
}
void DecipherParser_driver::error(const decipher::location& l, const std::string& m){
	cout << endl <<"syntax error at:" << l << ": " << m << std::endl;
}
void decipher::DecipherParserClass::error(const decipher::location& l, const std::string& m){
	driver.error (l, m);
}
void DecipherParser_driver::scan_begin(string filename){
	m_curfile = fopen(filename.c_str(),"r");
	if (m_curfile != NULL){
		yyrestart(m_curfile);
	}
	else{
		cout << endl << "Error! Cannot open file " << filename << endl;
		exit(1);
	}
}
void DecipherParser_driver::scan_end(){
fclose(m_curfile);
}
void DecipherParser_driver::error(const std::string& m){
	cout << m << std::endl;
}
void DecipherParser_driver::Extract_AST_Graph(string filename){
ofstream *ofile;
	ofile = m_ASTRoot->SetOutputFilename(DLASTO_ASTDOT,filename);
	*ofile << "digraph G{" << endl;
	m_ASTRoot->ASTGraphEmmiter(NULL);
	*ofile << "}";
	ofile->close();
	system("dot -Tgif AST_CDecl.dot -o AST_CDecl.gif");
}
CDHLIRSyntaxElement *DecipherParser_driver::GenerateHLIR(){
CDHLIRSyntaxElement *p, *c;
	m_HLIRRoot = new CDHLIR_ROOT();
	m_ASTRoot->ASTToHLIRGenerationPass(m_HLIRRoot,c);
return m_HLIRRoot;
}
int DecipherParser_driver::Extract_HLIR_Graph(string outputFile){
	cout << endl << "Generating HLIR Graph for Graphviz...";
	if ( m_HLIRRoot ){
		m_HLIRRoot->SetOutputFile(outputFile);
		m_HLIRRoot->HLIRGraphEmmiter(NULL);
		system("dot -Tgif HLIR_CDecl.dot -o HLIR_CDecl.gif");
	}
	else{
		cout  << "FAILED";
	}
return 0;
}
void DecipherParser_driver::CDecl(){
	m_HLIRRoot->CDeclTraversal();
}