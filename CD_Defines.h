/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\CD_Defines.h																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */

#ifndef DLIRDEFINES_
#define DLIRDEFINES_

#include <iostream>
#include <stdlib.h>
#include <ostream>
using namespace std;

#ifdef BISON_DLLOCATION_HH
#define DLINTERFACE_CONSTRUCTOR location_(scdecl::location *loc){ \
	start_line = loc->begin.line;\
	start_column = loc->begin.column;\
	end_line = loc->end.line;\
	end_column =loc->end.column; }
#endif

typedef class location_{
public:
	location_(){ start_line = -1; start_column = -1;
			end_line = -1; end_column = -1;}
	location_(const location_ &Init);
	location_ &operator=(const location_ &RHS);
#ifdef BISON_DLLOCATION_HH
	DLINTERFACE_CONSTRUCTOR
#endif
	friend ostream &operator<<(ostream &ostr,const class location_ &OBJ);
public:
	int start_line;
	int start_column;
	int end_line;
	int end_column;
} DLLOCATION_HLIR;

char *DLStrDup_cpp(string s);
char *DLStrDup_cpp(char *s);
#endif