/* *********************************************************************************** */
/* Title : Automatically Generated C++ File by the GAN Tool								      */
/* File :C:\Users\ALMA\Desktop\scdecl_out\CD_Defines.cpp																	  */
/* Main Author: Grigorios Dimitroulakos															  */
/* Contributors: Christakis Lezos																  */
/* Creation Time:19:2, 19/3/2012		*/
/* *********************************************************************************** */
#include "CD_Defines.h"

location_::location_(const location_ &Init){
	start_line = Init.start_line;
	start_column = Init.start_column;
	end_line = Init.end_line;
	end_column = Init.end_column;
}
location_ &location_::operator =(const location_ &RHS){
	start_line = RHS.start_line;
	start_column = RHS.start_column;
	end_line = RHS.end_line;
	end_column = RHS.end_column;
	return *this;
}
ostream &operator<<(ostream &ostr,const class location_ &loc){
	ostr << endl << loc.start_line << ":" << loc.start_column << "-"
	<< loc.end_line << ":" << loc.end_column;
return ostr;
}
char *DLStrDup_cpp(string s){
size_t len=strlen(s.c_str())+1;
char *newstring;
	if ( len > 1){
		newstring = new char[len];
#ifdef MICROSOFT_COMPLIANT
		strncpy_s(newstring,len,s.c_str(),len);
#else
		strcpy(newstring,s.c_str());
#endif
	}
	else{
		return NULL;
	}
return newstring;	
}
char *DLStrDup_cpp(char *s){
size_t len=strlen(s)+1;
char *newstring;
	if ( len > 1){
		newstring = new char[len];
#ifdef MICROSOFT_COMPLIANT
		strncpy_s(newstring,len,s,len);
#else
		strcpy(newstring,s);
#endif
	}
	else{
		return NULL;
	}
return newstring;
}