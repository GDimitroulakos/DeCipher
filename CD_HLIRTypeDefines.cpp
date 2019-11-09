#include "CD_HLIRTypeDefines.h"

const string DLlinkage_string[] = { "EXTERN", "STATIC", "NONE","UNITIALIZED" };

const string g_DLstorage_class_string[] = { "auto", "register", "static",
"extern", "typedef","UNITIALIZED" };
const string g_DLtype_qualifier_string[] = { "const", "volatile", "in", "out", "UNITIALIZED"};
const string g_DLfunction_specifier_string[] ={"inline", "UNITIALIZED" };
char const *g_DLInteger_Signness[]={
	"signed",
	"unsigned"
};
char const *g_DLInteger_Precision[]={
	"short",
	"", // Regular
	"long",
	"long long",
	"char"
};
char const *g_DLFloating_Precision[]={
	"float",
	"double", 
	"long double",	
};
char const *g_DLType_Complexity[]={
	"Unknown", 
	"Basic",
	"Derived"
};
char const *g_DLType_Category[]={
	"Unknown", 
	"void",
	"int",
	"array",
	"structure",
	"union",
	"function",
	"pointer"
};
char const *g_DLType_Specifier_Strings[]={
	"Unknown",
	"void",
	"char",
	"short",
	"int",
	"long",
	"signed",
	"unsigned",
	"float",
	"double"
	"typename"
};
struct DLtype_spec_alternatives DLg_type_specs[31]={
	{0,-1,{DLTSP_VOID,DLTSP_UNKNOWN},"void","Void"},
	{8,1,{DLTSP_CHAR,DLTSP_UNKNOWN},"char","Char"},
	{8,1,{DLTSP_SIGNED,DLTSP_CHAR,DLTSP_UNKNOWN},"signed char","SignedChar"},
	{8,0,{DLTSP_UNSIGNED,DLTSP_CHAR,DLTSP_UNKNOWN},"unsigned char","UnsignedChar"},
	{16,1,{DLTSP_SHORT,DLTSP_UNKNOWN},"short","Short"},
	{16,1,{DLTSP_SIGNED,DLTSP_SHORT,DLTSP_UNKNOWN},"signed short","SignedShort"},
	{16,1,{DLTSP_SHORT,DLTSP_INT,DLTSP_UNKNOWN},"short int","ShortInt"},
	{16,1,{DLTSP_SIGNED,DLTSP_SHORT,DLTSP_INT,DLTSP_UNKNOWN},"signed short int","SignedShortInt"},
	{16,0,{DLTSP_UNSIGNED,DLTSP_SHORT,DLTSP_UNKNOWN},"unsigned short","UnsignedShort"},
	{16,0,{DLTSP_UNSIGNED,DLTSP_SHORT,DLTSP_INT,DLTSP_UNKNOWN},"unsigned short int","UnsignedShortInt"},
	{32,1,{DLTSP_INT,DLTSP_UNKNOWN},"int","Int"},
	{32,1,{DLTSP_SIGNED,DLTSP_UNKNOWN},"signed","Signed"},
	{32,1,{DLTSP_SIGNED,DLTSP_INT,DLTSP_UNKNOWN},"signed int","SignedInt"},
	{32,0,{DLTSP_UNSIGNED,DLTSP_UNKNOWN},"unsigned","Unsigned"},
	{32,0,{DLTSP_UNSIGNED,DLTSP_INT,DLTSP_UNKNOWN},"unsigned int","UnsignedInt"},
	{32,1,{DLTSP_LONG,DLTSP_UNKNOWN},"long","Long"},
	{32,1,{DLTSP_SIGNED,DLTSP_LONG,DLTSP_UNKNOWN},"signed long","SignedLong"},
	{32,1,{DLTSP_LONG,DLTSP_INT,DLTSP_UNKNOWN},"long int","LongInt"},
	{32,1,{DLTSP_SIGNED,DLTSP_LONG,DLTSP_INT,DLTSP_UNKNOWN},"signed long int","SignedLongInt"},
	{32,0,{DLTSP_UNSIGNED,DLTSP_LONG,DLTSP_UNKNOWN},"unsigned long","UnsignedLong"},
	{32,0,{DLTSP_UNSIGNED,DLTSP_LONG,DLTSP_INT,DLTSP_UNKNOWN},"unsigned long int","UnsignedLongInt"},
	{64,1,{DLTSP_LONG,DLTSP_LONG,DLTSP_UNKNOWN},"long long","LongLong"},
	{64,1,{DLTSP_SIGNED,DLTSP_LONG,DLTSP_LONG,DLTSP_UNKNOWN},"signed long long","SignedLongLong"},
	{64,1,{DLTSP_LONG,DLTSP_LONG,DLTSP_INT,DLTSP_UNKNOWN},"long long int","LongLongInt"},
	{64,1,{DLTSP_SIGNED,DLTSP_LONG,DLTSP_LONG,DLTSP_INT,DLTSP_UNKNOWN},"signed long long int","SignedLongLongInt"},
	{64,0,{DLTSP_UNSIGNED,DLTSP_LONG,DLTSP_LONG,DLTSP_UNKNOWN},"unsigned long long","UnsignedLongLong"},
	{64,0,{DLTSP_UNSIGNED,DLTSP_LONG,DLTSP_LONG,DLTSP_INT,DLTSP_UNKNOWN},"unsigned long long int","UnsignedLongLongInt"},
	{32,1,{DLTSP_FLOAT,DLTSP_UNKNOWN},"float","Float"},
	{64,1,{DLTSP_DOUBLE,DLTSP_UNKNOWN},"double","Double"},
	{64,1,{DLTSP_LONG,DLTSP_DOUBLE,DLTSP_UNKNOWN},"long double","LongDouble"},	
	{-1,-1,{},"terminator not usable element","Terminator"}
};
