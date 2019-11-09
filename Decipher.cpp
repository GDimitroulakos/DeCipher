#include "CD_driver.h"

void main(int argc, char **argv){
DecipherParser_driver driver(argc-1, &(argv[1]));
	driver.parse();
	driver.GenerateHLIR();
	//driver.Extract_HLIR_Graph("HLIR_Graph.dot");
	driver.CDecl();
}