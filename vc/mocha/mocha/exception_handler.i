#line 1 "..\\..\\..\\src\\mocha\\roaster\\utils\\exception_handler.cc"
#line 1 "Y:\\mocha\\src\\mocha/roaster/utils/exception_handler.h"


























#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdlib"

#pragma once


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 





#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


















#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



#line 46 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"










#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"














#pragma once
































































































































#line 145 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"


#line 148 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"





#line 154 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"



#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"


#line 1 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"












#pragma once








#line 23 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"
#line 24 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"





typedef __w64 unsigned int   size_t;
#line 31 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

#line 33 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"
















#line 50 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"


namespace vc_attributes
{
#line 55 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

enum YesNoMaybe
{
	
	No = 0x0fff0001,
	Maybe = 0x0fff0010,
	Yes = 0x0fff0100
};

typedef enum YesNoMaybe YesNoMaybe;

enum AccessType
{
	NoAccess = 0,
	Read = 1,
	Write = 2,
	ReadWrite = 3
};

typedef enum AccessType AccessType;



[repeatable]
[source_annotation_attribute( Parameter )]
struct PreAttribute
{

	PreAttribute();
#line 85 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

	unsigned int Deref;
	YesNoMaybe Valid;
	YesNoMaybe Null;
	YesNoMaybe Tainted;
	AccessType Access;
	size_t ValidElementsConst;
	size_t ValidBytesConst;
	const wchar_t* ValidElements;
	const wchar_t* ValidBytes;
	const wchar_t* ValidElementsLength;
	const wchar_t* ValidBytesLength;
	size_t WritableElementsConst;
	size_t WritableBytesConst;
	const wchar_t* WritableElements;
	const wchar_t* WritableBytes;
	const wchar_t* WritableElementsLength;
	const wchar_t* WritableBytesLength;
	size_t ElementSizeConst;
	const wchar_t* ElementSize;
	YesNoMaybe NullTerminated;
	const wchar_t* Condition;
};

[repeatable]
[source_annotation_attribute( Parameter|ReturnValue )]
struct PostAttribute
{

	PostAttribute();
#line 116 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

	unsigned int Deref;
	YesNoMaybe Valid;
	YesNoMaybe Null;
	YesNoMaybe Tainted;
	AccessType Access;
	size_t ValidElementsConst;
	size_t ValidBytesConst;
	const wchar_t* ValidElements;
	const wchar_t* ValidBytes;
	const wchar_t* ValidElementsLength;
	const wchar_t* ValidBytesLength;
	size_t WritableElementsConst;
	size_t WritableBytesConst;
	const wchar_t* WritableElements;
	const wchar_t* WritableBytes;
	const wchar_t* WritableElementsLength;
	const wchar_t* WritableBytesLength;
	size_t ElementSizeConst;
	const wchar_t* ElementSize;
	YesNoMaybe NullTerminated;
	YesNoMaybe MustCheck;
	const wchar_t* Condition;
};

[source_annotation_attribute( Parameter )]
struct FormatStringAttribute
{

	FormatStringAttribute();
#line 147 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

	const wchar_t* Style;
	const wchar_t* UnformattedAlternative;
};

[repeatable]
[source_annotation_attribute( ReturnValue )]
struct InvalidCheckAttribute
{

	InvalidCheckAttribute();
#line 159 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

	long Value;
};

[source_annotation_attribute( Method )]
struct SuccessAttribute
{

	SuccessAttribute();
#line 169 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

	const wchar_t* Condition;
};

[repeatable]
[source_annotation_attribute( Parameter )]
struct PreBoundAttribute
{

	PreBoundAttribute();
#line 180 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"
	unsigned int Deref;
};

[repeatable]
[source_annotation_attribute( Parameter|ReturnValue )]
struct PostBoundAttribute
{

	PostBoundAttribute();
#line 190 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"
	unsigned int Deref;
};

[repeatable]
[source_annotation_attribute( Parameter )]
struct PreRangeAttribute
{

	PreRangeAttribute();
#line 200 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"
	unsigned int Deref;
	const char* MinVal;
	const char* MaxVal;
};

[repeatable]
[source_annotation_attribute( Parameter|ReturnValue )]
struct PostRangeAttribute
{

	PostRangeAttribute();
#line 212 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"
	unsigned int Deref;
	const char* MinVal;
	const char* MaxVal;
};

#line 218 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"


};  
#line 222 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"






















typedef ::vc_attributes::YesNoMaybe SA_YesNoMaybe;
const ::vc_attributes::YesNoMaybe SA_Yes = ::vc_attributes::Yes;
const ::vc_attributes::YesNoMaybe SA_No = ::vc_attributes::No;
const ::vc_attributes::YesNoMaybe SA_Maybe = ::vc_attributes::Maybe;

typedef ::vc_attributes::AccessType SA_AccessType;
const ::vc_attributes::AccessType SA_NoAccess = ::vc_attributes::NoAccess;
const ::vc_attributes::AccessType SA_Read = ::vc_attributes::Read;
const ::vc_attributes::AccessType SA_Write = ::vc_attributes::Write;
const ::vc_attributes::AccessType SA_ReadWrite = ::vc_attributes::ReadWrite;


typedef ::vc_attributes::PreAttribute          SA_Pre;
typedef ::vc_attributes::PostAttribute         SA_Post;
typedef ::vc_attributes::FormatStringAttribute SA_FormatString;
typedef ::vc_attributes::InvalidCheckAttribute SA_InvalidCheck; 
typedef ::vc_attributes::SuccessAttribute      SA_Success;
typedef ::vc_attributes::PreBoundAttribute     SA_PreBound;
typedef ::vc_attributes::PostBoundAttribute    SA_PostBound;
typedef ::vc_attributes::PreRangeAttribute     SA_PreRange;
typedef ::vc_attributes::PostRangeAttribute    SA_PostRange;
#line 266 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"















#line 282 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

#line 284 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"




















#line 305 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"


#line 308 "c:\\program files\\microsoft visual studio 10.0\\vc\\include\\codeanalysis\\sourceannotations.h"

#line 161 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"
#line 162 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"







































































































































































































































































































































































































































































































































































































































































                                                




                                                


























































































































































































































#line 1034 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"































































































#line 1130 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"



































































































#line 1230 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"



















































#line 1282 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"



















































































































































































































#line 1494 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"
extern "C" {




#line 1500 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"




























































































































































































































#line 1721 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
#line 1755 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"



































































































































































































































    
    
#line 1985 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"






#line 1992 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"
#line 1993 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"


}
#line 1997 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\sal.h"



#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#pragma pack(push,8)

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"












#pragma once






#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"








#pragma pack(push,8)


extern "C" {
#line 34 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"








#line 43 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"





typedef __w64 unsigned int   uintptr_t;
#line 50 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"

#line 52 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"





typedef char *  va_list;
#line 59 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"

#line 61 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"





#line 67 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"











#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"


#line 82 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"













#line 96 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"












































#line 141 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"


}
#line 145 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"

#pragma pack(pop)

#line 149 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\vadefs.h"
#line 64 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


extern "C" {
#line 68 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





#line 74 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 84 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"







#line 92 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 99 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 101 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 109 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 111 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 112 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"













#line 126 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 127 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





#line 133 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"







#line 141 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 143 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 145 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"







#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 154 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 159 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 161 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 162 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 169 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 170 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


 

#line 175 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
  
 #line 177 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 178 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"










#line 189 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 190 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 197 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 198 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

















#line 216 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 221 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"








#line 230 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 237 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 238 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





#line 244 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 251 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 252 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 260 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


#line 268 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 270 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"










#line 289 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 291 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 292 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 293 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"










#line 304 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 311 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 312 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"







#line 320 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 322 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 323 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



 
  
 



#line 333 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 334 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


 
  
  
 



#line 344 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 345 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


 
  
   
  

#line 353 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
 



#line 358 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 359 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


 
  
 



#line 368 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 369 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


 
  
 



#line 378 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 379 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



#line 383 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





#line 389 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 394 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 396 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 397 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"












typedef size_t rsize_t;

#line 412 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 413 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





typedef __w64 int            intptr_t;
#line 420 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 422 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














typedef __w64 int            ptrdiff_t;
#line 438 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 440 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"







typedef unsigned short wint_t;
typedef unsigned short wctype_t;

#line 451 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


















typedef int errno_t;
#line 471 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


typedef __w64 long __time32_t;   

#line 476 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


typedef __int64 __time64_t;     

#line 481 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





typedef __time64_t time_t;      
#line 488 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 490 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"







#line 498 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 499 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 504 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 506 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 507 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 512 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 514 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 515 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"





#line 521 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



#line 525 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"




#line 530 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 532 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 533 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"












  void __cdecl _invalid_parameter_noinfo(void);
  __declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(void);
#line 548 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

 __declspec(noreturn)
void __cdecl _invoke_watson(   const wchar_t *,    const wchar_t *,    const wchar_t *, unsigned int, uintptr_t);






 







 
  
 #line 568 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 569 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"







#line 577 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


































































































































































#line 740 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 741 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 1807 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"















































































































































#line 1951 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"
#line 1952 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct * pthreadlocinfo;
typedef struct threadmbcinfostruct * pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct
{
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
} _locale_tstruct, *_locale_t;


typedef struct tagLC_ID {
        unsigned short wLanguage;
        unsigned short wCountry;
        unsigned short wCodePage;
} LC_ID, *LPLC_ID;

#line 1973 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


typedef struct threadlocaleinfostruct {
        int refcount;
        unsigned int lc_codepage;
        unsigned int lc_collate_cp;
        unsigned long lc_handle[6]; 
        LC_ID lc_id[6];
        struct {
            char *locale;
            wchar_t *wlocale;
            int *refcount;
            int *wrefcount;
        } lc_category[6];
        int lc_clike;
        int mb_cur_max;
        int * lconv_intl_refcount;
        int * lconv_num_refcount;
        int * lconv_mon_refcount;
        struct lconv * lconv;
        int * ctype1_refcount;
        unsigned short * ctype1;
        const unsigned short * pctype;
        const unsigned char * pclmap;
        const unsigned char * pcumap;
        struct __lc_time_data * lc_time_curr;
} threadlocinfo;

#line 2002 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"


}
#line 2006 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



#line 2010 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 2012 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



#line 2016 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 2018 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



#line 2022 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 2024 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"






#line 2031 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"



#line 2035 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#pragma pack(pop)

#line 2039 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"

#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#pragma pack(push,8)









 
#line 20 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"









































#line 62 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#line 64 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
#line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

		





#line 73 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
#line 74 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

		


		




		

 
  

 

#line 91 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 
  
 #line 95 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


 
#line 99 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 
  
 #line 103 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"













































	
	






		


			
		#line 161 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
	#line 162 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

	
	




		

#line 172 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
			
		#line 174 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
	#line 175 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

	
	

#line 180 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#line 182 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
		
	#line 184 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#line 186 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"




#line 191 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


	
		#pragma detect_mismatch("_MSC_VER", "1600")
	#line 196 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

	
		
		     #pragma detect_mismatch("_ITERATOR_DEBUG_LEVEL", "0")
		





#line 207 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
	#line 208 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
#line 209 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"





#line 215 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"




#line 220 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#line 222 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
#line 223 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"



#line 227 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"









#line 237 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#line 239 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"



 
#line 244 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


 












#line 260 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 
 

 #line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 









 









 









 
































#line 330 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 




#line 336 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 
 
#line 339 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 
 

 #line 344 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"











#line 356 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"













#pragma once

















#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"










#pragma comment(lib,"libcpmt")


#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"
#line 48 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"
#line 49 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"

#line 51 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"

#line 53 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"

#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\use_ansi.h"
#line 358 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"







#line 366 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"







#line 374 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


 











 
  

#line 392 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
   
  #line 394 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 #line 395 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"






 










 
  

#line 416 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
   
  #line 418 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 #line 419 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 
  

#line 424 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
   
  #line 426 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 #line 427 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


 

   


#line 435 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
    
   #line 437 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 #line 439 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


 
  

#line 445 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
   
  #line 447 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 #line 448 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


 
  

#line 454 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
   
  #line 456 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 #line 457 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


 
  

#line 463 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
   
  #line 465 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 #line 466 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 

#line 470 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 
   


     
   #line 477 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 #line 478 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"


    
#line 482 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"



		

 
  
  
  




  
  
  

  







   
   
   
  #line 511 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

  
  
  
  

 












#line 531 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 

 
namespace std {
typedef bool _Bool;
}
 #line 539 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

		





		






typedef __int64 _Longlong;
typedef unsigned __int64 _ULonglong;

		


 
  
 #line 562 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"






 
#line 570 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

		
 
#line 574 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
 
  
typedef unsigned short char16_t;
typedef unsigned int char32_t;
 #line 579 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

 #line 581 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

		
		






 
namespace std {
enum _Uninitialized
	{	
	_Noinit
	};

		

#pragma warning(push)
#pragma warning(disable:4412)
class  _Lockit
	{	
public:
 

  
















#line 624 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
	__thiscall _Lockit();	
	explicit __thiscall _Lockit(int);	
	__thiscall ~_Lockit();	
  #line 628 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

    static  void __cdecl _Lockit_ctor(int);
    static  void __cdecl _Lockit_dtor(int);

private:
    static  void __cdecl _Lockit_ctor(_Lockit *);
    static  void __cdecl _Lockit_ctor(_Lockit *, int);
    static  void __cdecl _Lockit_dtor(_Lockit *);

	 _Lockit(const _Lockit&);				
	_Lockit&  operator=(const _Lockit&);	

	int _Locktype;

  











#line 655 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
	};

 



































































  



  


  



  


  
 #line 741 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

class  _Mutex
	{	
public:

 
  
























#line 773 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
    __thiscall _Mutex(_Uninitialized)
		{	
		}

    __thiscall _Mutex();
	__thiscall ~_Mutex();
	void __thiscall _Lock();
	void __thiscall _Unlock();
  #line 782 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

private:
    static  void __cdecl _Mutex_ctor(_Mutex *);
    static  void __cdecl _Mutex_dtor(_Mutex *);
    static  void __cdecl _Mutex_Lock(_Mutex *);
    static  void __cdecl _Mutex_Unlock(_Mutex *);

	 _Mutex(const _Mutex&);				
	_Mutex&  operator=(const _Mutex&);	
	void *_Mtx;

  







#line 802 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
	};

class  _Init_locks
	{	
public:
 
      










#line 820 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
    __thiscall _Init_locks();
	__thiscall ~_Init_locks();
  #line 823 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

private:
    static  void __cdecl _Init_locks_ctor(_Init_locks *);
    static  void __cdecl _Init_locks_dtor(_Init_locks *);

 







#line 837 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"
	};

#pragma warning(pop)
}
 #line 842 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"





		

 void __cdecl _Atexit(void (__cdecl *)(void));

typedef int _Mbstatet;
typedef unsigned long _Uint32t;





 

 #pragma pack(pop)

#line 863 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"






#line 6 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdlib"







 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"















#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"














#pragma once

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"
















#line 35 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"









































#line 77 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"






#line 84 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"
#line 85 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"







#line 93 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"
#line 94 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"
































#line 127 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits.h"
#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"





#pragma pack(push,8)


extern "C" {
#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"







#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"










typedef int (__cdecl * _onexit_t)(void);



#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"



#line 61 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"




#line 66 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


#line 69 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"






typedef struct _div_t {
        int quot;
        int rem;
} div_t;

typedef struct _ldiv_t {
        long quot;
        long rem;
} ldiv_t;

typedef struct _lldiv_t {
        long long quot;
        long long rem;
} lldiv_t;


#line 92 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"










#pragma pack(4)
typedef struct {
    unsigned char ld[10];
} _LDOUBLE;
#pragma pack()













#line 121 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

typedef struct {
        double x;
} _CRT_DOUBLE;

typedef struct {
    float f;
} _CRT_FLOAT;





typedef struct {
        


        long double x;
} _LONGDOUBLE;



#pragma pack(4)
typedef struct {
    unsigned char ld12[12];
} _LDBL12;
#pragma pack()


#line 151 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"












 extern int __mb_cur_max;



#line 168 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
 int __cdecl ___mb_cur_max_func(void);
 int __cdecl ___mb_cur_max_l_func(_locale_t);
#line 171 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"





































typedef void (__cdecl *_purecall_handler)(void); 


 _purecall_handler __cdecl _set_purecall_handler(   _purecall_handler _Handler);
 _purecall_handler __cdecl _get_purecall_handler(void);
#line 214 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


extern "C++"
{




#line 223 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
}
#line 225 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"



typedef void (__cdecl *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t); 


 _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(   _invalid_parameter_handler _Handler);
 _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);
#line 234 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


extern "C++"
{




#line 243 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
}
#line 245 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"




 extern int * __cdecl _errno(void);


errno_t __cdecl _set_errno(  int _Value);
errno_t __cdecl _get_errno(  int * _Value);
#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

 unsigned long * __cdecl __doserrno(void);


errno_t __cdecl _set_doserrno(  unsigned long _Value);
errno_t __cdecl _get_doserrno(  unsigned long * _Value);


  char ** __cdecl __sys_errlist(void);


  int * __cdecl __sys_nerr(void);













#line 281 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


 extern int __argc;          
 extern char ** __argv;      
 extern wchar_t ** __wargv;  







#line 294 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"





 extern char ** _environ;    
 extern wchar_t ** _wenviron;    
#line 302 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  extern char * _pgmptr;      
  extern wchar_t * _wpgmptr;  














#line 320 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

errno_t __cdecl _get_pgmptr(     char ** _Value);
errno_t __cdecl _get_wpgmptr(     wchar_t ** _Value);



  extern int _fmode;          



#line 331 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

 errno_t __cdecl _set_fmode(  int _Mode);
 errno_t __cdecl _get_fmode(  int * _PMode);





#line 340 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
extern "C++"
{
template <typename _CountofType, size_t _SizeOfArray>
char (*__countof_helper( _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];

}
#line 347 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
#line 348 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"





 __declspec(noreturn) void __cdecl exit(  int _Code);
 __declspec(noreturn) void __cdecl _exit(  int _Code);
 void __cdecl abort(void);
#line 357 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

 unsigned int __cdecl _set_abort_behavior(  unsigned int _Flags,   unsigned int _Mask);



        int       __cdecl abs(  int _X);
        long      __cdecl labs(  long _X);
        long long __cdecl llabs(  long long _X);
#line 366 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

        __int64    __cdecl _abs64(__int64);















#line 384 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"













#line 398 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
        int    __cdecl atexit(void (__cdecl *)(void));
#line 400 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


  double  __cdecl atof(   const char *_String);
  double  __cdecl _atof_l(   const char *_String,    _locale_t _Locale);
#line 405 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
   int    __cdecl atoi(   const char *_Str);
  int    __cdecl _atoi_l(   const char *_Str,    _locale_t _Locale);
  long   __cdecl atol(   const char *_Str);
  long   __cdecl _atol_l(   const char *_Str,    _locale_t _Locale);



  void * __cdecl bsearch_s(  const void * _Key,    const void * _Base, 
          rsize_t _NumOfElements,   rsize_t _SizeOfElements,
          int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);
#line 416 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
  void * __cdecl bsearch(  const void * _Key,    const void * _Base, 
          size_t _NumOfElements,   size_t _SizeOfElements,
          int (__cdecl * _PtFuncCompare)(const void *, const void *));


 void __cdecl qsort_s(   void * _Base, 
          rsize_t _NumOfElements,   rsize_t _SizeOfElements,
          int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void *_Context);
#line 425 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
 void __cdecl qsort(   void * _Base, 
	  size_t _NumOfElements,   size_t _SizeOfElements, 
          int (__cdecl * _PtFuncCompare)(const void *, const void *));
#line 429 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
         unsigned short __cdecl _byteswap_ushort(  unsigned short _Short);
         unsigned long  __cdecl _byteswap_ulong (  unsigned long _Long);
         unsigned __int64 __cdecl _byteswap_uint64(  unsigned __int64 _Int64);
  div_t  __cdecl div(  int _Numerator,   int _Denominator);
   char * __cdecl getenv(   const char * _VarName);

  errno_t __cdecl getenv_s(  size_t * _ReturnSize,     char * _DstBuf,   rsize_t _DstSize,    const char * _VarName);
#line 437 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl getenv_s(  size_t * _ReturnSize, char (&_Dest)[_Size],    const char * _VarName) throw() { return getenv_s(_ReturnSize, _Dest, _Size, _VarName); } }



#line 442 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  errno_t __cdecl _dupenv_s(    char **_PBuffer,   size_t * _PBufferSizeInBytes,    const char * _VarName);



#line 448 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  errno_t __cdecl _itoa_s(  int _Value,     char * _DstBuf,   size_t _Size,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _itoa_s(  int _Value, char (&_Dest)[_Size],   int _Radix) throw() { return _itoa_s(_Value, _Dest, _Size, _Radix); } }
  char * __cdecl _itoa( int _Value,   char *_Dest,  int _Radix);
  errno_t __cdecl _i64toa_s(  __int64 _Val,     char * _DstBuf,   size_t _Size,   int _Radix);
  char * __cdecl _i64toa(  __int64 _Val,    char * _DstBuf,   int _Radix);
  errno_t __cdecl _ui64toa_s(  unsigned __int64 _Val,     char * _DstBuf,   size_t _Size,   int _Radix);
  char * __cdecl _ui64toa(  unsigned __int64 _Val,    char * _DstBuf,   int _Radix);
  __int64 __cdecl _atoi64(   const char * _String);
  __int64 __cdecl _atoi64_l(   const char * _String,    _locale_t _Locale);
  __int64 __cdecl _strtoi64(   const char * _String,     char ** _EndPtr,   int _Radix);
  __int64 __cdecl _strtoi64_l(   const char * _String,     char ** _EndPtr,   int _Radix,    _locale_t _Locale);
  unsigned __int64 __cdecl _strtoui64(   const char * _String,     char ** _EndPtr,   int _Radix);
  unsigned __int64 __cdecl _strtoui64_l(   const char * _String,     char ** _EndPtr,   int  _Radix,    _locale_t _Locale);
  ldiv_t __cdecl ldiv(  long _Numerator,   long _Denominator);
  lldiv_t __cdecl lldiv(  long long _Numerator,   long long _Denominator);

extern "C++"
{
    inline long abs(long _X)
    {
        return labs(_X);
    }
    inline long long abs(long long _X)
    {
        return llabs(_X);
    }
    inline ldiv_t div(long _A1, long _A2)
    {
        return ldiv(_A1, _A2);
    }
    inline lldiv_t div(long long _A1, long long _A2)
    {
        return lldiv(_A1, _A2);
    }
}
#line 485 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
  errno_t __cdecl _ltoa_s(  long _Val,     char * _DstBuf,   size_t _Size,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ltoa_s(  long _Value, char (&_Dest)[_Size],   int _Radix) throw() { return _ltoa_s(_Value, _Dest, _Size, _Radix); } }
  char * __cdecl _ltoa( long _Value,   char *_Dest,  int _Radix);
  int    __cdecl mblen(     const char * _Ch,   size_t _MaxCount);
  int    __cdecl _mblen_l(     const char * _Ch,   size_t _MaxCount,    _locale_t _Locale);
  size_t __cdecl _mbstrlen(   const char * _Str);
  size_t __cdecl _mbstrlen_l(   const char *_Str,    _locale_t _Locale);
  size_t __cdecl _mbstrnlen(   const char *_Str,   size_t _MaxCount);
  size_t __cdecl _mbstrnlen_l(   const char *_Str,   size_t _MaxCount,    _locale_t _Locale);
 int    __cdecl mbtowc(   wchar_t * _DstCh,      const char * _SrcCh,   size_t _SrcSizeInBytes);
 int    __cdecl _mbtowc_l(   wchar_t * _DstCh,      const char * _SrcCh,   size_t _SrcSizeInBytes,    _locale_t _Locale);
  errno_t __cdecl mbstowcs_s(  size_t * _PtNumOfCharConverted,     wchar_t * _DstBuf,   size_t _SizeInWords,      const char * _SrcBuf,   size_t _MaxCount );
extern "C++" { template <size_t _Size> inline errno_t __cdecl mbstowcs_s(  size_t * _PtNumOfCharConverted,   wchar_t (&_Dest)[_Size],    const char * _Source,   size_t _MaxCount) throw() { return mbstowcs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount); } }
  size_t __cdecl mbstowcs(  wchar_t *_Dest,  const char * _Source,  size_t _MaxCount);

  errno_t __cdecl _mbstowcs_s_l(  size_t * _PtNumOfCharConverted,     wchar_t * _DstBuf,   size_t _SizeInWords,      const char * _SrcBuf,   size_t _MaxCount,    _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _mbstowcs_s_l(  size_t * _PtNumOfCharConverted, wchar_t (&_Dest)[_Size],    const char * _Source,   size_t _MaxCount,    _locale_t _Locale) throw() { return _mbstowcs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale); } }
  size_t __cdecl _mbstowcs_l(    wchar_t *_Dest,    const char * _Source,   size_t _MaxCount,    _locale_t _Locale);

  int    __cdecl rand(void);


#line 508 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  int    __cdecl _set_error_mode(  int _Mode);

 void   __cdecl srand(  unsigned int _Seed);
  double __cdecl strtod(   const char * _Str,     char ** _EndPtr);
  double __cdecl _strtod_l(   const char * _Str,     char ** _EndPtr,    _locale_t _Locale);
  long   __cdecl strtol(   const char * _Str,     char ** _EndPtr,   int _Radix );
  long   __cdecl _strtol_l(   const char *_Str,     char **_EndPtr,   int _Radix,    _locale_t _Locale);
  unsigned long __cdecl strtoul(   const char * _Str,     char ** _EndPtr,   int _Radix);
  unsigned long __cdecl _strtoul_l(const char * _Str,     char **_EndPtr,   int _Radix,    _locale_t _Locale);


 int __cdecl system(   const char * _Command);
#line 522 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
  errno_t __cdecl _ultoa_s(  unsigned long _Val,     char * _DstBuf,   size_t _Size,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ultoa_s(  unsigned long _Value, char (&_Dest)[_Size],   int _Radix) throw() { return _ultoa_s(_Value, _Dest, _Size, _Radix); } }
  char * __cdecl _ultoa( unsigned long _Value,   char *_Dest,  int _Radix);
  int    __cdecl wctomb(    char * _MbCh,   wchar_t _WCh);
  int    __cdecl _wctomb_l(   char * _MbCh,   wchar_t _WCh,    _locale_t _Locale);

  errno_t __cdecl wctomb_s(  int * _SizeConverted,     char * _MbCh,   rsize_t _SizeInBytes,   wchar_t _WCh);
#line 530 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
  errno_t __cdecl _wctomb_s_l(  int * _SizeConverted,     char * _MbCh,   size_t _SizeInBytes,   wchar_t _WCh,    _locale_t _Locale);
  errno_t __cdecl wcstombs_s(  size_t * _PtNumOfCharConverted,     char * _Dst,   size_t _DstSizeInBytes,    const wchar_t * _Src,   size_t _MaxCountInBytes);
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcstombs_s(  size_t * _PtNumOfCharConverted,   char (&_Dest)[_Size],    const wchar_t * _Source,   size_t _MaxCount) throw() { return wcstombs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount); } }
  size_t __cdecl wcstombs(  char *_Dest,  const wchar_t * _Source,  size_t _MaxCount);
  errno_t __cdecl _wcstombs_s_l(  size_t * _PtNumOfCharConverted,     char * _Dst,   size_t _DstSizeInBytes,    const wchar_t * _Src,   size_t _MaxCountInBytes,    _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcstombs_s_l(  size_t * _PtNumOfCharConverted,   char (&_Dest)[_Size],    const wchar_t * _Source,   size_t _MaxCount,    _locale_t _Locale) throw() { return _wcstombs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale); } }
  size_t __cdecl _wcstombs_l(    char *_Dest,    const wchar_t * _Source,   size_t _MaxCount,    _locale_t _Locale);

























#line 563 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


































#line 598 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
    __declspec(noalias) __declspec(restrict)    void * __cdecl calloc(  size_t _Count,   size_t _Size);
                     __declspec(noalias)                                                                             void   __cdecl free( void * _Memory);
    __declspec(noalias) __declspec(restrict)                              void * __cdecl malloc(  size_t _Size);

   __declspec(noalias) __declspec(restrict)                           void * __cdecl realloc( void * _Memory,   size_t _NewSize);

   __declspec(noalias) __declspec(restrict)                       void * __cdecl _recalloc( void * _Memory,   size_t _Count,   size_t _Size);
                     __declspec(noalias)                                                                             void   __cdecl _aligned_free( void * _Memory);
   __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_malloc(  size_t _Size,   size_t _Alignment);
   __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_offset_malloc(  size_t _Size,   size_t _Alignment,   size_t _Offset);

   __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_realloc( void * _Memory,   size_t _NewSize,   size_t _Alignment);

   __declspec(noalias) __declspec(restrict)                       void * __cdecl _aligned_recalloc( void * _Memory,   size_t _Count,   size_t _Size,   size_t _Alignment);

   __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_offset_realloc( void * _Memory,   size_t _NewSize,   size_t _Alignment,   size_t _Offset);

   __declspec(noalias) __declspec(restrict)                       void * __cdecl _aligned_offset_recalloc( void * _Memory,   size_t _Count,   size_t _Size,   size_t _Alignment,   size_t _Offset);
                                                   size_t __cdecl _aligned_msize( void * _Memory,   size_t _Alignment,   size_t _Offset);


















#line 636 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

#line 638 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"





  errno_t __cdecl _itow_s (  int _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _itow_s(  int _Value, wchar_t (&_Dest)[_Size],   int _Radix) throw() { return _itow_s(_Value, _Dest, _Size, _Radix); } }
  wchar_t * __cdecl _itow( int _Value,   wchar_t *_Dest,  int _Radix);
  errno_t __cdecl _ltow_s (  long _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ltow_s(  long _Value, wchar_t (&_Dest)[_Size],   int _Radix) throw() { return _ltow_s(_Value, _Dest, _Size, _Radix); } }
  wchar_t * __cdecl _ltow( long _Value,   wchar_t *_Dest,  int _Radix);
  errno_t __cdecl _ultow_s (  unsigned long _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ultow_s(  unsigned long _Value, wchar_t (&_Dest)[_Size],   int _Radix) throw() { return _ultow_s(_Value, _Dest, _Size, _Radix); } }
  wchar_t * __cdecl _ultow( unsigned long _Value,   wchar_t *_Dest,  int _Radix);
  double __cdecl wcstod(   const wchar_t * _Str,     wchar_t ** _EndPtr);
  double __cdecl _wcstod_l(   const wchar_t *_Str,     wchar_t ** _EndPtr,    _locale_t _Locale);
  long   __cdecl wcstol(   const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix);
  long   __cdecl _wcstol_l(   const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix,    _locale_t _Locale);
  unsigned long __cdecl wcstoul(   const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix);
  unsigned long __cdecl _wcstoul_l(   const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix,    _locale_t _Locale);
   wchar_t * __cdecl _wgetenv(   const wchar_t * _VarName);
  errno_t __cdecl _wgetenv_s(  size_t * _ReturnSize,     wchar_t * _DstBuf,   size_t _DstSizeInWords,    const wchar_t * _VarName);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wgetenv_s(  size_t * _ReturnSize, wchar_t (&_Dest)[_Size],    const wchar_t * _VarName) throw() { return _wgetenv_s(_ReturnSize, _Dest, _Size, _VarName); } }




#line 666 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  errno_t __cdecl _wdupenv_s(    wchar_t **_Buffer,   size_t *_BufferSizeInWords,    const wchar_t *_VarName);



#line 672 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"



 int __cdecl _wsystem(   const wchar_t * _Command);
#line 677 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
  double __cdecl _wtof(   const wchar_t *_Str);
  double __cdecl _wtof_l(   const wchar_t *_Str,    _locale_t _Locale);
  int __cdecl _wtoi(   const wchar_t *_Str);
  int __cdecl _wtoi_l(   const wchar_t *_Str,    _locale_t _Locale);
  long __cdecl _wtol(   const wchar_t *_Str);
  long __cdecl _wtol_l(   const wchar_t *_Str,    _locale_t _Locale);

  errno_t __cdecl _i64tow_s(  __int64 _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
  wchar_t * __cdecl _i64tow(  __int64 _Val,    wchar_t * _DstBuf,   int _Radix);
  errno_t __cdecl _ui64tow_s(  unsigned __int64 _Val,     wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
  wchar_t * __cdecl _ui64tow(  unsigned __int64 _Val,    wchar_t * _DstBuf,   int _Radix);
  __int64   __cdecl _wtoi64(   const wchar_t *_Str);
  __int64   __cdecl _wtoi64_l(   const wchar_t *_Str,    _locale_t _Locale);
  __int64   __cdecl _wcstoi64(   const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix);
  __int64   __cdecl _wcstoi64_l(   const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix,    _locale_t _Locale);
  unsigned __int64  __cdecl _wcstoui64(   const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix);
  unsigned __int64  __cdecl _wcstoui64_l(   const wchar_t *_Str ,     wchar_t ** _EndPtr,   int _Radix,    _locale_t _Locale);


#line 697 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"














#line 712 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  char * __cdecl _fullpath(    char * _FullPath,    const char * _Path,   size_t _SizeInBytes);





#line 720 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  errno_t __cdecl _ecvt_s(    char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDights,   int * _PtDec,   int * _PtSign);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ecvt_s(char (&_Dest)[_Size],   double _Value,   int _NumOfDigits,   int * _PtDec,   int * _PtSign) throw() { return _ecvt_s(_Dest, _Size, _Value, _NumOfDigits, _PtDec, _PtSign); } }
   char * __cdecl _ecvt(  double _Val,   int _NumOfDigits,   int * _PtDec,   int * _PtSign);
  errno_t __cdecl _fcvt_s(    char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _fcvt_s(char (&_Dest)[_Size],   double _Value,   int _NumOfDigits,   int * _PtDec,   int * _PtSign) throw() { return _fcvt_s(_Dest, _Size, _Value, _NumOfDigits, _PtDec, _PtSign); } }
   char * __cdecl _fcvt(  double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);
 errno_t __cdecl _gcvt_s(    char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDigits);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _gcvt_s(char (&_Dest)[_Size],   double _Value,   int _NumOfDigits) throw() { return _gcvt_s(_Dest, _Size, _Value, _NumOfDigits); } }
  char * __cdecl _gcvt(  double _Val,   int _NumOfDigits,    char * _DstBuf);

  int __cdecl _atodbl(  _CRT_DOUBLE * _Result,    char * _Str);
  int __cdecl _atoldbl(  _LDOUBLE * _Result,    char * _Str);
  int __cdecl _atoflt(  _CRT_FLOAT * _Result,    char * _Str);
  int __cdecl _atodbl_l(  _CRT_DOUBLE * _Result,    char * _Str,    _locale_t _Locale);
  int __cdecl _atoldbl_l(  _LDOUBLE * _Result,    char * _Str,    _locale_t _Locale);
  int __cdecl _atoflt_l(  _CRT_FLOAT * _Result,    char * _Str,    _locale_t _Locale);
         unsigned long __cdecl _lrotl(  unsigned long _Val,   int _Shift);
         unsigned long __cdecl _lrotr(  unsigned long _Val,   int _Shift);
  errno_t   __cdecl _makepath_s(    char * _PathResult,   size_t _SizeInWords,    const char * _Drive,    const char * _Dir,    const char * _Filename,
           const char * _Ext);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _makepath_s(char (&_Path)[_Size],    const char * _Drive,    const char * _Dir,    const char * _Filename,    const char * _Ext) throw() { return _makepath_s(_Path, _Size, _Drive, _Dir, _Filename, _Ext); } }
  void __cdecl _makepath(  char *_Path,  const char * _Drive,  const char * _Dir,  const char * _Filename,  const char * _Ext);












#line 756 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"












#line 769 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
        _onexit_t __cdecl _onexit(   _onexit_t _Func);
#line 771 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
        


 void __cdecl perror(   const char * _ErrMsg);
#line 776 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

#pragma warning (push)
#pragma warning (disable:6540) 
  int    __cdecl _putenv(   const char * _EnvString);
  errno_t __cdecl _putenv_s(   const char * _Name,    const char * _Value);
         unsigned int __cdecl _rotl(  unsigned int _Val,   int _Shift);
         unsigned __int64 __cdecl _rotl64(  unsigned __int64 _Val,   int _Shift);
         unsigned int __cdecl _rotr(  unsigned int _Val,   int _Shift);
         unsigned __int64 __cdecl _rotr64(  unsigned __int64 _Val,   int _Shift);
#pragma warning (pop)

 errno_t __cdecl _searchenv_s(   const char * _Filename,    const char * _EnvVar,     char * _ResultPath,   size_t _SizeInBytes);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _searchenv_s(   const char * _Filename,    const char * _EnvVar, char (&_ResultPath)[_Size]) throw() { return _searchenv_s(_Filename, _EnvVar, _ResultPath, _Size); } }
  void __cdecl _searchenv( const char * _Filename,  const char * _EnvVar,   char *_ResultPath);

  void   __cdecl _splitpath(   const char * _FullPath,    char * _Drive,    char * _Dir,    char * _Filename,    char * _Ext);
  errno_t  __cdecl _splitpath_s(   const char * _FullPath, 
		    char * _Drive,   size_t _DriveSize, 
		    char * _Dir,   size_t _DirSize, 
		    char * _Filename,   size_t _FilenameSize, 
		    char * _Ext,   size_t _ExtSize);
extern "C++" { template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize> inline errno_t __cdecl _splitpath_s(  const char *_Dest, char (&_Drive)[_DriveSize], char (&_Dir)[_DirSize], char (&_Name)[_NameSize], char (&_Ext)[_ExtSize]) throw() { return _splitpath_s(_Dest, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize); } }

 void   __cdecl _swab(     char * _Buf1,      char * _Buf2, int _SizeInBytes);








#line 809 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  wchar_t * __cdecl _wfullpath(    wchar_t * _FullPath,    const wchar_t * _Path,   size_t _SizeInWords);



#line 815 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

  errno_t __cdecl _wmakepath_s(    wchar_t * _PathResult,   size_t _SIZE,    const wchar_t * _Drive,    const wchar_t * _Dir,    const wchar_t * _Filename,
           const wchar_t * _Ext);        
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wmakepath_s(wchar_t (&_ResultPath)[_Size],    const wchar_t * _Drive,    const wchar_t * _Dir,    const wchar_t * _Filename,    const wchar_t * _Ext) throw() { return _wmakepath_s(_ResultPath, _Size, _Drive, _Dir, _Filename, _Ext); } }
  void __cdecl _wmakepath(  wchar_t *_ResultPath,  const wchar_t * _Drive,  const wchar_t * _Dir,  const wchar_t * _Filename,  const wchar_t * _Ext);


 void __cdecl _wperror(   const wchar_t * _ErrMsg);
#line 824 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
  int    __cdecl _wputenv(   const wchar_t * _EnvString);
  errno_t __cdecl _wputenv_s(   const wchar_t * _Name,    const wchar_t * _Value);
 errno_t __cdecl _wsearchenv_s(   const wchar_t * _Filename,    const wchar_t * _EnvVar,     wchar_t * _ResultPath,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wsearchenv_s(   const wchar_t * _Filename,    const wchar_t * _EnvVar, wchar_t (&_ResultPath)[_Size]) throw() { return _wsearchenv_s(_Filename, _EnvVar, _ResultPath, _Size); } }
  void __cdecl _wsearchenv( const wchar_t * _Filename,  const wchar_t * _EnvVar,   wchar_t *_ResultPath);
  void   __cdecl _wsplitpath(   const wchar_t * _FullPath,    wchar_t * _Drive,    wchar_t * _Dir,    wchar_t * _Filename,    wchar_t * _Ext);
 errno_t __cdecl _wsplitpath_s(   const wchar_t * _FullPath, 
		    wchar_t * _Drive,   size_t _DriveSize, 
		    wchar_t * _Dir,   size_t _DirSize, 
		    wchar_t * _Filename,   size_t _FilenameSize, 
		    wchar_t * _Ext,   size_t _ExtSize);
extern "C++" { template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize> inline errno_t __cdecl _wsplitpath_s(  const wchar_t *_Path, wchar_t (&_Drive)[_DriveSize], wchar_t (&_Dir)[_DirSize], wchar_t (&_Name)[_NameSize], wchar_t (&_Ext)[_ExtSize]) throw() { return _wsplitpath_s(_Path, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize); } }


#line 839 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "SetErrorMode" " instead. See online help for details."))  void __cdecl _seterrormode(  int _Mode);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "Beep" " instead. See online help for details."))  void __cdecl _beep(  unsigned _Frequency,   unsigned _Duration);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "Sleep" " instead. See online help for details."))  void __cdecl _sleep(  unsigned long _Duration);

#line 846 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"
















#pragma warning(push)
#pragma warning(disable: 4141)  
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ecvt" ". See online help for details."))   char * __cdecl ecvt(  double _Val,   int _NumOfDigits,   int * _PtDec,   int * _PtSign);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcvt" ". See online help for details."))   char * __cdecl fcvt(  double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_gcvt" ". See online help for details.")) 		 char * __cdecl gcvt(  double _Val,   int _NumOfDigits,    char * _DstBuf);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_itoa" ". See online help for details.")) 		 char * __cdecl itoa(  int _Val,    char * _DstBuf,   int _Radix);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ltoa" ". See online help for details.")) 		 char * __cdecl ltoa(  long _Val,    char * _DstBuf,   int _Radix);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putenv" ". See online help for details."))  int    __cdecl putenv(   const char * _EnvString);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_swab" ". See online help for details."))										 void   __cdecl swab(    char * _Buf1,    char * _Buf2,   int _SizeInBytes);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ultoa" ". See online help for details.")) 	 char * __cdecl ultoa(  unsigned long _Val,    char * _Dstbuf,   int _Radix);
#pragma warning(pop)
_onexit_t __cdecl onexit(   _onexit_t _Func);

#line 876 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

#line 878 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"


}

#line 883 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

#pragma pack(pop)

#line 887 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdlib.h"

#line 14 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdlib"
#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdlib"

 

namespace std {
using :: size_t; using :: div_t; using :: ldiv_t;

using :: abort; using :: abs; using :: atexit;
using :: atof; using :: atoi; using :: atol;
using :: bsearch; using :: calloc; using :: div;
using :: exit; using :: free; using :: getenv;
using :: labs; using :: ldiv; using :: malloc;
using :: mblen; using :: mbstowcs; using :: mbtowc;
using :: qsort; using :: rand; using :: realloc;
using :: srand; using :: strtod; using :: strtol;
using :: strtoul; using :: system;
using :: wcstombs; using :: wctomb;

using :: lldiv_t;

using :: llabs; using :: lldiv;
}
 #line 37 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdlib"

#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdlib"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"

#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"

#pragma once





 
  
  
  
 #line 13 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstddef"

#pragma once










 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"














#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"


extern "C" {
#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"













namespace std { typedef decltype(__nullptr) nullptr_t; }
using ::std::nullptr_t;
#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"
#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"



















#line 62 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"









#line 72 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"

 extern unsigned long  __cdecl __threadid(void);

 extern uintptr_t __cdecl __threadhandle(void);


}
#line 80 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"

#line 82 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"
#line 14 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstddef"
#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstddef"

 
namespace std {
using :: ptrdiff_t; using :: size_t;
}
 #line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstddef"

#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstddef"





#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"

 #pragma pack(push,8)
 #pragma warning(push,3)

namespace std {
		
 

 
 
 
 
 

 
 

 



  
  

   
   

 
























#line 68 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"

		


		
 
 

		

template<bool _Test,
	class _Ty1,
	class _Ty2>
	class _If
	{	
public:
	typedef _Ty2 _Type;
	};

template<class _Ty1,
	class _Ty2>
	class _If<true, _Ty1, _Ty2>
	{	
public:
	typedef _Ty1 _Type;
	};

 
  

	namespace tr1 {
typedef char (&_No)[1];
typedef char (&_Yes)[2];
	}	
 #line 103 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"

 

  

struct _Bool_struct
	{	
	int _Member;
	};

  









   

typedef int _Bool_struct::* _Bool_type;
  #line 127 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"

 #line 129 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"

		
		
template<class _Arg,
	class _Result>
	struct unary_function
	{	
	typedef _Arg argument_type;
	typedef _Result result_type;
	};

		
template<class _Arg1,
	class _Arg2,
	class _Result>
	struct binary_function
	{	
	typedef _Arg1 first_argument_type;
	typedef _Arg2 second_argument_type;
	typedef _Result result_type;
	};
}


 #pragma warning(pop)
 #pragma pack(pop)

#line 157 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"
#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstddef"





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

 #pragma pack(push,8)
 #pragma warning(push,3)










namespace std {

  


  



  



}

 

 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"












#pragma once

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"








#pragma pack(push,8)







typedef void (__cdecl *terminate_function)();
typedef void (__cdecl *terminate_handler)();
typedef void (__cdecl *unexpected_function)();
typedef void (__cdecl *unexpected_handler)();





#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"








struct _EXCEPTION_POINTERS;

typedef void (__cdecl *_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS*);
#line 54 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"

 __declspec(noreturn) void __cdecl terminate(void);
 void __cdecl unexpected(void);

 int __cdecl _is_exception_typeof(  const type_info &_Type,   struct _EXCEPTION_POINTERS * _ExceptionPtr);



 terminate_function __cdecl set_terminate(   terminate_function _NewPtFunc);
extern "C"  terminate_function __cdecl _get_terminate(void);
 unexpected_function __cdecl set_unexpected(   unexpected_function _NewPtFunc);
extern "C"  unexpected_function __cdecl _get_unexpected(void);
#line 67 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"



 _se_translator_function __cdecl _set_se_translator(   _se_translator_function _NewPtFunc);
#line 72 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"
 bool __cdecl __uncaught_exception();









#pragma pack(pop)
#line 84 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"
#line 85 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\eh.h"
#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"














#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"





#pragma pack(push,8)


extern "C" {
#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"





#line 45 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"













typedef struct _heapinfo {
        int * _pentry;
        size_t _size;
        int _useflag;
        } _HEAPINFO;

#line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"



































#line 101 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"







































#line 141 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"

 int     __cdecl _resetstkoflw (void);



 unsigned long __cdecl _set_malloc_crt_max_wait(  unsigned long _NewValue);








#line 156 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"

   void *  __cdecl _expand( void * _Memory,   size_t _NewSize);
  size_t  __cdecl _msize( void * _Memory);




#line 164 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"

 void *          __cdecl _alloca(  size_t _Size);
  int     __cdecl _heapadd(  void * _Memory,   size_t _Size);
  int     __cdecl _heapchk(void);
  int     __cdecl _heapmin(void);
 int     __cdecl _heapset(  unsigned int _Fill);
  int     __cdecl _heapwalk(   _HEAPINFO * _EntryInfo);
 size_t  __cdecl _heapused(size_t * _Used, size_t * _Commit);

 intptr_t __cdecl _get_heap_handle(void);











#line 186 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"

typedef char __static_assert_t[ (sizeof(unsigned int) <= 8) ];


#pragma warning(push)
#pragma warning(disable:6540)
__inline void *_MarkAllocaS(   void *_Ptr, unsigned int _Marker)
{
    if (_Ptr)
    {
        *((unsigned int*)_Ptr) = _Marker;
        _Ptr = (char*)_Ptr + 8;
    }
    return _Ptr;
}
#pragma warning(pop)
#line 203 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"








#line 212 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"






#line 219 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"








__declspec(noalias) __inline void __cdecl _freea( void * _Memory)
{
    unsigned int _Marker;
    if (_Memory)
    {
        _Memory = (char*)_Memory - 8;
        _Marker = *(unsigned int *)_Memory;
        if (_Marker == 0xDDDD)
        {
            free(_Memory);
        }





#line 244 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"
    }
}
#line 247 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"
#line 248 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"




#line 253 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"

#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"






















}
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"

#pragma pack(pop)

#line 283 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\malloc.h"
#line 40 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"














#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"


extern "C" {
#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"




#line 30 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
















 void *  __cdecl _memccpy(   void * _Dst,   const void * _Src,   int _Val,   size_t _MaxCount);
  const void *  __cdecl memchr(    const void * _Buf ,   int _Val,   size_t _MaxCount);
  int     __cdecl _memicmp(   const void * _Buf1,    const void * _Buf2,   size_t _Size);
  int     __cdecl _memicmp_l(   const void * _Buf1,    const void * _Buf2,   size_t _Size,    _locale_t _Locale);
         int     __cdecl memcmp(   const void * _Buf1,    const void * _Buf2,   size_t _Size);
         void *  __cdecl memcpy(    void * _Dst,    const void * _Src,   size_t _Size);

 errno_t  __cdecl memcpy_s(    void * _Dst,   rsize_t _DstSize,    const void * _Src,   rsize_t _MaxCount);





















#line 76 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"










#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
#line 88 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
        void *  __cdecl memset(    void * _Dst,   int _Val,   size_t _Size);



__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memccpy" ". See online help for details."))  void * __cdecl memccpy(  void * _Dst,    const void * _Src,   int _Val,   size_t _Size);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memicmp" ". See online help for details."))  int __cdecl memicmp(   const void * _Buf1,    const void * _Buf2,   size_t _Size);
#line 95 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

  errno_t __cdecl _strset_s(    char * _Dst,   size_t _DstSize,   int _Value);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strset_s(    char (&_Dest)[_Size],   int _Value) throw() { return _strset_s(_Dest, _Size, _Value); } }
  char * __cdecl _strset(  char *_Dest,  int _Value);

  errno_t __cdecl strcpy_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src);
#line 104 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl strcpy_s(  char (&_Dest)[_Size],    const char * _Source) throw() { return strcpy_s(_Dest, _Size, _Source); } }
  char * __cdecl strcpy(  char *_Dest,  const char * _Source);

  errno_t __cdecl strcat_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src);
#line 109 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl strcat_s(    char (&_Dest)[_Size],    const char * _Source) throw() { return strcat_s(_Dest, _Size, _Source); } }
  char * __cdecl strcat(  char *_Dest,  const char * _Source);
         int     __cdecl strcmp(   const char * _Str1,    const char * _Str2);
         size_t  __cdecl strlen(   const char * _Str);
  size_t  __cdecl strnlen(   const char * _Str,   size_t _MaxCount);

 static __inline size_t  __cdecl strnlen_s(    const char * _Str,   size_t _MaxCount)
{
    return (_Str==0) ? 0 : strnlen(_Str, _MaxCount);
}
#line 120 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

  errno_t __cdecl memmove_s(    void * _Dst,   rsize_t _DstSize,    const void * _Src,   rsize_t _MaxCount);
#line 123 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"



#line 127 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
  void *  __cdecl memmove(    void * _Dst,    const void * _Src,   size_t _Size);
#line 129 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"




#line 134 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

  char *  __cdecl _strdup(   const char * _Src);



#line 140 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

  const char *  __cdecl strchr(   const char * _Str,   int _Val);
  int     __cdecl _stricmp(    const char * _Str1,     const char * _Str2);
  int     __cdecl _strcmpi(    const char * _Str1,     const char * _Str2);
  int     __cdecl _stricmp_l(    const char * _Str1,     const char * _Str2,    _locale_t _Locale);
  int     __cdecl strcoll(    const char * _Str1,     const  char * _Str2);
  int     __cdecl _strcoll_l(    const char * _Str1,     const char * _Str2,    _locale_t _Locale);
  int     __cdecl _stricoll(    const char * _Str1,     const char * _Str2);
  int     __cdecl _stricoll_l(    const char * _Str1,     const char * _Str2,    _locale_t _Locale);
  int     __cdecl _strncoll  (   const char * _Str1,    const char * _Str2,   size_t _MaxCount);
  int     __cdecl _strncoll_l(   const char * _Str1,    const char * _Str2,   size_t _MaxCount,    _locale_t _Locale);
  int     __cdecl _strnicoll (   const char * _Str1,    const char * _Str2,   size_t _MaxCount);
  int     __cdecl _strnicoll_l(   const char * _Str1,    const char * _Str2,   size_t _MaxCount,    _locale_t _Locale);
  size_t  __cdecl strcspn(    const char * _Str,     const char * _Control);
   char *  __cdecl _strerror(   const char * _ErrMsg);
  errno_t __cdecl _strerror_s(    char * _Buf,   size_t _SizeInBytes,    const char * _ErrMsg);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strerror_s(char (&_Buffer)[_Size],    const char * _ErrorMessage) throw() { return _strerror_s(_Buffer, _Size, _ErrorMessage); } }
   char *  __cdecl strerror(  int);

  errno_t __cdecl strerror_s(    char * _Buf,   size_t _SizeInBytes,   int _ErrNum);
#line 161 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl strerror_s(char (&_Buffer)[_Size],   int _ErrorMessage) throw() { return strerror_s(_Buffer, _Size, _ErrorMessage); } }
  errno_t __cdecl _strlwr_s(    char * _Str,   size_t _Size);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strlwr_s(    char (&_String)[_Size]) throw() { return _strlwr_s(_String, _Size); } }
  char * __cdecl _strlwr(  char *_String);
  errno_t __cdecl _strlwr_s_l(    char * _Str,   size_t _Size,    _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strlwr_s_l(    char (&_String)[_Size],    _locale_t _Locale) throw() { return _strlwr_s_l(_String, _Size, _Locale); } }
  char * __cdecl _strlwr_l(    char *_String,    _locale_t _Locale);

  errno_t __cdecl strncat_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src,   rsize_t _MaxCount);
#line 171 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl strncat_s(    char (&_Dest)[_Size],    const char * _Source,   size_t _Count) throw() { return strncat_s(_Dest, _Size, _Source, _Count); } }
#pragma warning(push)
#pragma warning(disable:6059)

  char * __cdecl strncat(    char *_Dest,    const char * _Source,   size_t _Count);
#pragma warning(pop)


#line 180 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
  int     __cdecl strncmp(   const char * _Str1,    const char * _Str2,   size_t _MaxCount);
#line 182 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
  int     __cdecl _strnicmp(   const char * _Str1,    const char * _Str2,   size_t _MaxCount);
  int     __cdecl _strnicmp_l(   const char * _Str1,    const char * _Str2,   size_t _MaxCount,    _locale_t _Locale);

  errno_t __cdecl strncpy_s(    char * _Dst,   rsize_t _SizeInBytes,    const char * _Src,   rsize_t _MaxCount);
#line 187 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl strncpy_s(char (&_Dest)[_Size],    const char * _Source,   size_t _Count) throw() { return strncpy_s(_Dest, _Size, _Source, _Count); } }
  char * __cdecl strncpy(   char *_Dest,    const char * _Source,   size_t _Count);
  errno_t __cdecl _strnset_s(    char * _Str,   size_t _SizeInBytes,   int _Val,   size_t _MaxCount);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strnset_s(    char (&_Dest)[_Size],   int _Val,   size_t _Count) throw() { return _strnset_s(_Dest, _Size, _Val, _Count); } }
  char * __cdecl _strnset(    char *_Dest,   int _Val,   size_t _Count);
  const char *  __cdecl strpbrk(   const char * _Str,    const char * _Control);
  const char *  __cdecl strrchr(   const char * _Str,   int _Ch);
 char *  __cdecl _strrev(    char * _Str);
  size_t  __cdecl strspn(   const char * _Str,    const char * _Control);
  const char *  __cdecl strstr(   const char * _Str,    const char * _SubStr);
   char *  __cdecl strtok(    char * _Str,    const char * _Delim);

  char *  __cdecl strtok_s(    char * _Str,    const char * _Delim,        char ** _Context);
#line 201 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
  errno_t __cdecl _strupr_s(    char * _Str,   size_t _Size);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strupr_s(    char (&_String)[_Size]) throw() { return _strupr_s(_String, _Size); } }
  char * __cdecl _strupr(  char *_String);
  errno_t __cdecl _strupr_s_l(    char * _Str,   size_t _Size, _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strupr_s_l(    char (&_String)[_Size], _locale_t _Locale) throw() { return _strupr_s_l(_String, _Size, _Locale); } }
  char * __cdecl _strupr_l(    char *_String,    _locale_t _Locale);
  size_t  __cdecl strxfrm (   char * _Dst,    const char * _Src,   size_t _MaxCount);
  size_t  __cdecl _strxfrm_l(   char * _Dst,    const char * _Src,   size_t _MaxCount,    _locale_t _Locale);


extern "C++" {


 inline char * __cdecl strchr(   char * _Str,   int _Ch)
	{ return (char*)strchr((const char*)_Str, _Ch); }
 inline char * __cdecl strpbrk(   char * _Str,    const char * _Control)
	{ return (char*)strpbrk((const char*)_Str, _Control); }
 inline char * __cdecl strrchr(   char * _Str,   int _Ch)
	{ return (char*)strrchr((const char*)_Str, _Ch); }
 inline char * __cdecl strstr(   char * _Str,    const char * _SubStr)
	{ return (char*)strstr((const char*)_Str, _SubStr); }
#line 223 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"


 inline void * __cdecl memchr(   void * _Pv,   int _C,   size_t _N)
	{ return (void*)memchr((const void*)_Pv, _C, _N); }
#line 228 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
}
#line 230 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"






#line 237 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strdup" ". See online help for details."))  char * __cdecl strdup(   const char * _Src);



#line 243 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"


 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strcmpi" ". See online help for details."))  int __cdecl strcmpi(   const char * _Str1,    const char * _Str2);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_stricmp" ". See online help for details."))  int __cdecl stricmp(   const char * _Str1,    const char * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strlwr" ". See online help for details."))  char * __cdecl strlwr(    char * _Str);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnicmp" ". See online help for details."))  int __cdecl strnicmp(   const char * _Str1,    const char * _Str,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnset" ". See online help for details."))  char * __cdecl strnset(    char * _Str,   int _Val,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strrev" ". See online help for details."))  char * __cdecl strrev(    char * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strset" ". See online help for details."))         char * __cdecl strset(    char * _Str,   int _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strupr" ". See online help for details."))  char * __cdecl strupr(    char * _Str);

#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"









#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

  wchar_t * __cdecl _wcsdup(   const wchar_t * _Str);



#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"


  errno_t __cdecl wcscat_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src);
#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcscat_s(    wchar_t (&_Dest)[_Size],    const wchar_t * _Source) throw() { return wcscat_s(_Dest, _Size, _Source); } }
  wchar_t * __cdecl wcscat(  wchar_t *_Dest,  const wchar_t * _Source);
  const wchar_t * __cdecl wcschr(   const wchar_t * _Str, wchar_t _Ch);
  int __cdecl wcscmp(   const wchar_t * _Str1,    const wchar_t * _Str2);

  errno_t __cdecl wcscpy_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src);
#line 282 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcscpy_s(wchar_t (&_Dest)[_Size],    const wchar_t * _Source) throw() { return wcscpy_s(_Dest, _Size, _Source); } }
  wchar_t * __cdecl wcscpy(  wchar_t *_Dest,  const wchar_t * _Source);
  size_t __cdecl wcscspn(   const wchar_t * _Str,    const wchar_t * _Control);
  size_t __cdecl wcslen(   const wchar_t * _Str);
  size_t __cdecl wcsnlen(   const wchar_t * _Src,   size_t _MaxCount);

 static __inline size_t __cdecl wcsnlen_s(   const wchar_t * _Src,   size_t _MaxCount)
{
    return (_Src == 0) ? 0 : wcsnlen(_Src, _MaxCount);
}
#line 293 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

  errno_t __cdecl wcsncat_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src,   rsize_t _MaxCount);
#line 296 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcsncat_s(    wchar_t (&_Dest)[_Size],    const wchar_t * _Source,   size_t _Count) throw() { return wcsncat_s(_Dest, _Size, _Source, _Count); } }
#pragma warning(push)
#pragma warning(disable:6059)
  wchar_t * __cdecl wcsncat(    wchar_t *_Dest,    const wchar_t * _Source,   size_t _Count);
#pragma warning(pop)
  int __cdecl wcsncmp(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);

  errno_t __cdecl wcsncpy_s(    wchar_t * _Dst,   rsize_t _SizeInWords,    const wchar_t * _Src,   rsize_t _MaxCount);
#line 305 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcsncpy_s(wchar_t (&_Dest)[_Size],    const wchar_t * _Source,   size_t _Count) throw() { return wcsncpy_s(_Dest, _Size, _Source, _Count); } }
  wchar_t * __cdecl wcsncpy(   wchar_t *_Dest,    const wchar_t * _Source,   size_t _Count);
  const wchar_t * __cdecl wcspbrk(   const wchar_t * _Str,    const wchar_t * _Control);
  const wchar_t * __cdecl wcsrchr(   const wchar_t * _Str,   wchar_t _Ch);
  size_t __cdecl wcsspn(   const wchar_t * _Str,    const wchar_t * _Control);
  const wchar_t * __cdecl wcsstr(   const wchar_t * _Str,    const wchar_t * _SubStr);
   wchar_t * __cdecl wcstok(    wchar_t * _Str,    const wchar_t * _Delim);

  wchar_t * __cdecl wcstok_s(    wchar_t * _Str,    const wchar_t * _Delim,        wchar_t ** _Context);
#line 315 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
   wchar_t * __cdecl _wcserror(  int _ErrNum);
  errno_t __cdecl _wcserror_s(    wchar_t * _Buf,   size_t _SizeInWords,   int _ErrNum);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcserror_s(wchar_t (&_Buffer)[_Size],   int _Error) throw() { return _wcserror_s(_Buffer, _Size, _Error); } }
   wchar_t * __cdecl __wcserror(   const wchar_t * _Str);
  errno_t __cdecl __wcserror_s(    wchar_t * _Buffer,   size_t _SizeInWords,    const wchar_t * _ErrMsg);
extern "C++" { template <size_t _Size> inline errno_t __cdecl __wcserror_s(wchar_t (&_Buffer)[_Size],    const wchar_t * _ErrorMessage) throw() { return __wcserror_s(_Buffer, _Size, _ErrorMessage); } }

  int __cdecl _wcsicmp(   const wchar_t * _Str1,    const wchar_t * _Str2);
  int __cdecl _wcsicmp_l(   const wchar_t * _Str1,    const wchar_t * _Str2,    _locale_t _Locale);
  int __cdecl _wcsnicmp(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);
  int __cdecl _wcsnicmp_l(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount,    _locale_t _Locale);
  errno_t __cdecl _wcsnset_s(    wchar_t * _Dst,   size_t _SizeInWords,   wchar_t _Val,   size_t _MaxCount);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsnset_s(    wchar_t (&_Dst)[_Size], wchar_t _Val,   size_t _MaxCount) throw() { return _wcsnset_s(_Dst, _Size, _Val, _MaxCount); } }
  wchar_t * __cdecl _wcsnset(    wchar_t *_Str, wchar_t _Val,   size_t _MaxCount);
 wchar_t * __cdecl _wcsrev(    wchar_t * _Str);
  errno_t __cdecl _wcsset_s(    wchar_t * _Dst,   size_t _SizeInWords,   wchar_t _Value);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsset_s(    wchar_t (&_Str)[_Size], wchar_t _Val) throw() { return _wcsset_s(_Str, _Size, _Val); } }
  wchar_t * __cdecl _wcsset(    wchar_t *_Str, wchar_t _Val);

  errno_t __cdecl _wcslwr_s(    wchar_t * _Str,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcslwr_s(    wchar_t (&_String)[_Size]) throw() { return _wcslwr_s(_String, _Size); } }
  wchar_t * __cdecl _wcslwr(  wchar_t *_String);
  errno_t __cdecl _wcslwr_s_l(    wchar_t * _Str,   size_t _SizeInWords,    _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcslwr_s_l(    wchar_t (&_String)[_Size],    _locale_t _Locale) throw() { return _wcslwr_s_l(_String, _Size, _Locale); } }
  wchar_t * __cdecl _wcslwr_l(    wchar_t *_String,    _locale_t _Locale);
  errno_t __cdecl _wcsupr_s(    wchar_t * _Str,   size_t _Size);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsupr_s(    wchar_t (&_String)[_Size]) throw() { return _wcsupr_s(_String, _Size); } }
  wchar_t * __cdecl _wcsupr(  wchar_t *_String);
  errno_t __cdecl _wcsupr_s_l(    wchar_t * _Str,   size_t _Size,    _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsupr_s_l(    wchar_t (&_String)[_Size],    _locale_t _Locale) throw() { return _wcsupr_s_l(_String, _Size, _Locale); } }
  wchar_t * __cdecl _wcsupr_l(    wchar_t *_String,    _locale_t _Locale);
  size_t __cdecl wcsxfrm(   wchar_t * _Dst,    const wchar_t * _Src,   size_t _MaxCount);
  size_t __cdecl _wcsxfrm_l(   wchar_t * _Dst,    const wchar_t *_Src,   size_t _MaxCount,    _locale_t _Locale);
  int __cdecl wcscoll(   const wchar_t * _Str1,    const wchar_t * _Str2);
  int __cdecl _wcscoll_l(   const wchar_t * _Str1,    const wchar_t * _Str2,    _locale_t _Locale);
  int __cdecl _wcsicoll(   const wchar_t * _Str1,    const wchar_t * _Str2);
  int __cdecl _wcsicoll_l(   const wchar_t * _Str1,    const wchar_t *_Str2,    _locale_t _Locale);
  int __cdecl _wcsncoll(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);
  int __cdecl _wcsncoll_l(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount,    _locale_t _Locale);
  int __cdecl _wcsnicoll(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);
  int __cdecl _wcsnicoll_l(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount,    _locale_t _Locale);




extern "C++" {
 inline wchar_t * __cdecl wcschr(   wchar_t *_Str, wchar_t _Ch)
        {return ((wchar_t *)wcschr((const wchar_t *)_Str, _Ch)); }
 inline wchar_t * __cdecl wcspbrk(   wchar_t *_Str,    const wchar_t *_Control)
        {return ((wchar_t *)wcspbrk((const wchar_t *)_Str, _Control)); }
 inline wchar_t * __cdecl wcsrchr(   wchar_t *_Str,   wchar_t _Ch)
        {return ((wchar_t *)wcsrchr((const wchar_t *)_Str, _Ch)); }
 inline wchar_t * __cdecl wcsstr(   wchar_t *_Str,    const wchar_t *_SubStr)
        {return ((wchar_t *)wcsstr((const wchar_t *)_Str, _SubStr)); }
}
#line 371 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
#line 372 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"






#line 379 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsdup" ". See online help for details."))  wchar_t * __cdecl wcsdup(   const wchar_t * _Str);



#line 385 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"





 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicmp" ". See online help for details."))  int __cdecl wcsicmp(   const wchar_t * _Str1,    const wchar_t * _Str2);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnicmp" ". See online help for details."))  int __cdecl wcsnicmp(   const wchar_t * _Str1,    const wchar_t * _Str2,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnset" ". See online help for details."))  wchar_t * __cdecl wcsnset(    wchar_t * _Str,   wchar_t _Val,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsrev" ". See online help for details."))  wchar_t * __cdecl wcsrev(    wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsset" ". See online help for details."))  wchar_t * __cdecl wcsset(    wchar_t * _Str, wchar_t _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcslwr" ". See online help for details."))  wchar_t * __cdecl wcslwr(    wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsupr" ". See online help for details."))  wchar_t * __cdecl wcsupr(    wchar_t * _Str);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicoll" ". See online help for details."))  int __cdecl wcsicoll(   const wchar_t * _Str1,    const wchar_t * _Str2);

#line 400 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"


#line 403 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"



}
#line 408 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"

#line 410 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

 

#line 45 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

 



































#line 83 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

 namespace std {





 
#line 92 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

class  exception
    {   
public:
      exception();
     explicit  exception(const char * const &);
      exception(const char * const &, int);
      exception(const exception&);
     exception&  operator=(const exception&);
     virtual  ~exception();
     virtual const char *  what() const;

private:
     void  _Copy_str(const char *);
     void  _Tidy();

    const char * _Mywhat;
    bool _Mydofree;
    };

















































































using ::set_terminate; using ::terminate_handler; using ::terminate; using ::set_unexpected; using ::unexpected_handler; using ::unexpected;

typedef void (__cdecl *_Prhand)(const exception&);

 bool __cdecl uncaught_exception();

}

 










































































































#line 308 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"


namespace std {


#line 314 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

		
class bad_exception : public exception
	{	
public:
	 bad_exception(const char *_Message = "bad exception")
		throw ()
		: exception(_Message)
		{	
		}

	virtual  ~bad_exception() throw ()
		{	
		}

 





#line 336 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

	};

		
class bad_alloc : public exception
	{	
public:
	 bad_alloc(const char *_Message) throw ()
		: exception(_Message)
		{	
		}

	 bad_alloc() throw ()
		: exception("bad allocation", 1)
		{	
		}

	virtual  ~bad_alloc() throw ()
		{	
		}

 





#line 364 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

	};


		
class bad_array_new_length
	: public bad_alloc
	{	
public:

	bad_array_new_length() throw ()
		: bad_alloc("bad array new length")
		{	
		}
	};
#line 380 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"


}









#line 393 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

 void __cdecl __ExceptionPtrCreate(  void* );
 void __cdecl __ExceptionPtrDestroy(   void* );
 void __cdecl __ExceptionPtrCopy(  void*,   const void* );
 void __cdecl __ExceptionPtrAssign(   void*,   const void* );
 bool __cdecl __ExceptionPtrCompare(  const void*,   const void*);

 void __cdecl __ExceptionPtrCurrentException(  void*);
 void __cdecl __ExceptionPtrRethrow(  const void*);
 void __cdecl __ExceptionPtrCopyException(   void*,   const void*,   const void*);

namespace std {


typedef ::std:: nullptr_t _Null_type;


#line 411 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"

class _Exception_ptr
	{
public:
	_Exception_ptr()
		{
		__ExceptionPtrCreate(this);
		}
	_Exception_ptr(_Null_type)
		{
		__ExceptionPtrCreate(this);
		}
	~_Exception_ptr()
		{
		__ExceptionPtrDestroy(this);
		}
	_Exception_ptr(  const _Exception_ptr& _Rhs)
		{
		__ExceptionPtrCopy(this, const_cast<_Exception_ptr*>(&_Rhs));
		}
	_Exception_ptr& operator=(  const _Exception_ptr& _Rhs)
		{
		__ExceptionPtrAssign(this, const_cast<_Exception_ptr*>(&_Rhs));
		return *this;
		}
	_Exception_ptr& operator=(_Null_type)
		{
		_Exception_ptr _Ptr;
		__ExceptionPtrAssign(this, &_Ptr);
		return *this;
		}

	void _RethrowException() const
		{
		__ExceptionPtrRethrow(const_cast<_Exception_ptr*>(this));
		}

	static _Exception_ptr _Current_exception()
		{
		_Exception_ptr _Retval;
		__ExceptionPtrCurrentException(&_Retval);
		return _Retval;
		}
	static _Exception_ptr _Copy_exception(  void* _Except,   const void* _Ptr)
		{
		_Exception_ptr _Retval = 0;
		if (!_Ptr)
			{
			
			return _Retval;
			}
		__ExceptionPtrCopyException(&_Retval, _Except, _Ptr);
		return _Retval;
		}
private:
	void* _Data1;
	void* _Data2;
	};

inline bool operator==(  const _Exception_ptr& _Lhs,   const _Exception_ptr& _Rhs)
	{
	return __ExceptionPtrCompare(const_cast<_Exception_ptr*>(&_Lhs),const_cast<_Exception_ptr*>(&_Rhs));
	}

inline bool operator==(_Null_type,   const _Exception_ptr& _Rhs)
	{
	_Exception_ptr _Ptr;
	return __ExceptionPtrCompare(&_Ptr,const_cast<_Exception_ptr*>(&_Rhs));
	}

inline bool operator==(  const _Exception_ptr& _Lhs, _Null_type)
	{
	return operator==(0,_Lhs);
	}

typedef _Exception_ptr exception_ptr;

inline exception_ptr current_exception()
	{
	return _Exception_ptr::_Current_exception();
	}

inline void rethrow_exception(  exception_ptr _P)
	{
	_P._RethrowException();
	}

template <class _E> void *__GetExceptionInfo(_E);

template<class _E> exception_ptr copy_exception(_E _Except)
	{
	return _Exception_ptr::_Copy_exception(&_Except, __GetExceptionInfo(_Except));
	}

}







 #pragma warning(pop)
 #pragma pack(pop)

#line 517 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"
#line 518 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\exception"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

 #pragma pack(push,8)
 #pragma warning(push,3)
 

  








#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

namespace std {

		
 




typedef void (__cdecl * new_handler) ();
#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"
 #line 34 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

 
struct nothrow_t
	{	
	};

extern const nothrow_t nothrow;	
 #line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

		
 new_handler __cdecl set_new_handler(   new_handler)
	throw ();	
}

		
void __cdecl operator delete(void *) throw ();
#pragma warning (suppress: 4985)
 void *__cdecl operator new(size_t _Size) throw (...);

 
  
inline void *__cdecl operator new(size_t, void *_Where) throw ()
	{	
	return (_Where);
	}

inline void __cdecl operator delete(void *, void *) throw ()
	{	
	}
 #line 64 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

 
  
inline void *__cdecl operator new[](size_t, void *_Where) throw ()
	{	
	return (_Where);
	}

inline void __cdecl operator delete[](void *, void *) throw ()
	{	
	}
 #line 76 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

void __cdecl operator delete[](void *) throw ();	

 void *__cdecl operator new[](size_t _Size)
	throw (...);	

 
  
 void *__cdecl operator new(size_t _Size, const ::std:: nothrow_t&)
	throw ();

 void *__cdecl operator new[](size_t _Size, const ::std:: nothrow_t&)
	throw ();	

void __cdecl operator delete(void *, const ::std:: nothrow_t&)
	throw ();	

void __cdecl operator delete[](void *, const ::std:: nothrow_t&)
	throw ();	
 #line 96 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"


 
using ::std:: new_handler;
 #line 101 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

 
 #pragma warning(pop)
 #pragma pack(pop)

#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"
#line 108 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\climits"

#pragma once





#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\climits"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"

#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdio"

#pragma once










 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"














#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"





#pragma pack(push,8)


extern "C" {
#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

























struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;

#line 69 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"










#line 80 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"













#line 94 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"





















#line 116 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"













 FILE * __cdecl __iob_func(void);
#line 131 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"










#line 142 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"



typedef __int64 fpos_t;




#line 151 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
#line 152 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"


#line 155 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"






#line 162 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
























  int __cdecl _filbuf(   FILE * _File );
  int __cdecl _flsbuf(  int _Ch,    FILE * _File);




  FILE * __cdecl _fsopen(   const char * _Filename,    const char * _Mode,   int _ShFlag);
#line 194 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

 void __cdecl clearerr(   FILE * _File);

  errno_t __cdecl clearerr_s(   FILE * _File );
#line 199 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl fclose(   FILE * _File);
  int __cdecl _fcloseall(void);




  FILE * __cdecl _fdopen(  int _FileHandle,    const char * _Mode);
#line 207 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

  int __cdecl feof(  FILE * _File);
  int __cdecl ferror(  FILE * _File);
  int __cdecl fflush(   FILE * _File);
  int __cdecl fgetc(   FILE * _File);
  int __cdecl _fgetchar(void);
  int __cdecl fgetpos(   FILE * _File ,   fpos_t * _Pos);
  char * __cdecl fgets(    char * _Buf,   int _MaxCount,    FILE * _File);




  int __cdecl _fileno(  FILE * _File);
#line 221 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"




#line 226 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

  char * __cdecl _tempnam(   const char * _DirName,    const char * _FilePrefix);



#line 232 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

  int __cdecl _flushall(void);
   FILE * __cdecl fopen(   const char * _Filename,    const char * _Mode);

  errno_t __cdecl fopen_s(     FILE ** _File,    const char * _Filename,    const char * _Mode);
#line 238 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl fprintf(   FILE * _File,     const char * _Format, ...);

  int __cdecl fprintf_s(   FILE * _File,     const char * _Format, ...);
#line 242 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl fputc(  int _Ch,    FILE * _File);
  int __cdecl _fputchar(  int _Ch);
  int __cdecl fputs(   const char * _Str,    FILE * _File);
  size_t __cdecl fread(  void * _DstBuf,   size_t _ElementSize,   size_t _Count,    FILE * _File);

  size_t __cdecl fread_s(  void * _DstBuf,   size_t _DstSize,   size_t _ElementSize,   size_t _Count,    FILE * _File);
#line 249 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
   FILE * __cdecl freopen(   const char * _Filename,    const char * _Mode,    FILE * _File);

  errno_t __cdecl freopen_s(     FILE ** _File,    const char * _Filename,    const char * _Mode,    FILE * _OldFile);
#line 253 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
   int __cdecl fscanf(   FILE * _File,     const char * _Format, ...);
   int __cdecl _fscanf_l(   FILE * _File,     const char * _Format,    _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl fscanf_s(   FILE * _File,     const char * _Format, ...);
#line 260 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _fscanf_s_l(   FILE * _File,     const char * _Format,    _locale_t _Locale, ...);
#pragma warning(pop)
  int __cdecl fsetpos(   FILE * _File,   const fpos_t * _Pos);
  int __cdecl fseek(   FILE * _File,   long _Offset,   int _Origin);
  long __cdecl ftell(   FILE * _File);

  int __cdecl _fseeki64(   FILE * _File,   __int64 _Offset,   int _Origin);
  __int64 __cdecl _ftelli64(   FILE * _File);

  size_t __cdecl fwrite(   const void * _Str,   size_t _Size,   size_t _Count,    FILE * _File);
  int __cdecl getc(   FILE * _File);
  int __cdecl getchar(void);
  int __cdecl _getmaxstdio(void);

 char * __cdecl gets_s(    char * _Buf,   rsize_t _Size);
#line 276 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
extern "C++" { template <size_t _Size> inline char * __cdecl gets_s(char (&_Buffer)[_Size]) throw() { return gets_s(_Buffer, _Size); } }
  char * __cdecl gets(  char *_Buffer);
 int __cdecl _getw(   FILE * _File);




  int __cdecl _pclose(   FILE * _File);
  FILE * __cdecl _popen(   const char * _Command,    const char * _Mode);
  int __cdecl printf(    const char * _Format, ...);

  int __cdecl printf_s(    const char * _Format, ...);
#line 289 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl putc(  int _Ch,    FILE * _File);
  int __cdecl putchar(  int _Ch);
  int __cdecl puts(   const char * _Str);
  int __cdecl _putw(  int _Word,    FILE * _File);


 int __cdecl remove(   const char * _Filename);
  int __cdecl rename(   const char * _OldFilename,    const char * _NewFilename);
 int __cdecl _unlink(   const char * _Filename);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_unlink" ". See online help for details."))  int __cdecl unlink(   const char * _Filename);
#line 301 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
#line 302 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
 void __cdecl rewind(   FILE * _File);
  int __cdecl _rmtmp(void);
   int __cdecl scanf(    const char * _Format, ...);
   int __cdecl _scanf_l(    const char * _Format,    _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl scanf_s(    const char * _Format, ...);
#line 311 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _scanf_s_l(    const char * _Format,    _locale_t _Locale, ...);
#pragma warning(pop)
  void __cdecl setbuf(   FILE * _File,      char * _Buffer);
  int __cdecl _setmaxstdio(  int _Max);
  unsigned int __cdecl _set_output_format(  unsigned int _Format);
  unsigned int __cdecl _get_output_format(void);
  int __cdecl setvbuf(   FILE * _File,     char * _Buf,   int _Mode,   size_t _Size);
  int __cdecl _snprintf_s(    char * _DstBuf,   size_t _SizeInBytes,   size_t _MaxCount,     const char * _Format, ...);
extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl _snprintf_s(  char (&_Dest)[_Size],   size_t _MaxCount,     const char * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return _vsnprintf_s(_Dest, _Size, _MaxCount, _Format, _ArgList); } __pragma(warning(pop)); }

  int __cdecl sprintf_s(    char * _DstBuf,   size_t _SizeInBytes,     const char * _Format, ...);
#line 323 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl sprintf_s(  char (&_Dest)[_Size],     const char * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return vsprintf_s(_Dest, _Size, _Format, _ArgList); } __pragma(warning(pop)); }
  int __cdecl _scprintf(    const char * _Format, ...);
   int __cdecl sscanf(   const char * _Src,     const char * _Format, ...);
   int __cdecl _sscanf_l(   const char * _Src,     const char * _Format,    _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl sscanf_s(   const char * _Src,     const char * _Format, ...);
#line 332 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _sscanf_s_l(   const char * _Src,     const char * _Format,    _locale_t _Locale, ...);
   int __cdecl _snscanf(     const char * _Src,   size_t _MaxCount,     const char * _Format, ...);
   int __cdecl _snscanf_l(     const char * _Src,   size_t _MaxCount,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _snscanf_s(     const char * _Src,   size_t _MaxCount,     const char * _Format, ...);
  int __cdecl _snscanf_s_l(     const char * _Src,   size_t _MaxCount,     const char * _Format,    _locale_t _Locale, ...);
#pragma warning(pop)
   FILE * __cdecl tmpfile(void);

  errno_t __cdecl tmpfile_s(    FILE ** _File);
  errno_t __cdecl tmpnam_s(    char * _Buf,   rsize_t _Size);
#line 343 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
extern "C++" { template <size_t _Size> inline errno_t __cdecl tmpnam_s(  char (&_Buf)[_Size]) throw() { return tmpnam_s(_Buf, _Size); } }
  char * __cdecl tmpnam(  char *_Buffer);
  int __cdecl ungetc(  int _Ch,    FILE * _File);
  int __cdecl vfprintf(   FILE * _File,     const char * _Format, va_list _ArgList);

  int __cdecl vfprintf_s(   FILE * _File,     const char * _Format, va_list _ArgList);
#line 350 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl vprintf(    const char * _Format, va_list _ArgList);

  int __cdecl vprintf_s(    const char * _Format, va_list _ArgList);
#line 354 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
   int __cdecl vsnprintf(  char * _DstBuf,   size_t _MaxCount,     const char * _Format, va_list _ArgList);

  int __cdecl vsnprintf_s(    char * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const char * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl vsnprintf_s(  char (&_Dest)[_Size],   size_t _MaxCount,     const char * _Format, va_list _Args) throw() { return vsnprintf_s(_Dest, _Size, _MaxCount, _Format, _Args); } }
#line 359 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _vsnprintf_s(    char * _DstBuf,   size_t _SizeInBytes,   size_t _MaxCount,     const char * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl _vsnprintf_s(  char (&_Dest)[_Size],   size_t _MaxCount,     const char * _Format, va_list _Args) throw() { return _vsnprintf_s(_Dest, _Size, _MaxCount, _Format, _Args); } }
#pragma warning(push)
#pragma warning(disable:4793)
  int __cdecl _snprintf(   char *_Dest,   size_t _Count,     const char * _Format, ...);   int __cdecl _vsnprintf(   char *_Dest,   size_t _Count,     const char * _Format, va_list _Args);
#pragma warning(pop)

 int __cdecl vsprintf_s(    char * _DstBuf,   size_t _SizeInBytes,     const char * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl vsprintf_s(  char (&_Dest)[_Size],     const char * _Format, va_list _Args) throw() { return vsprintf_s(_Dest, _Size, _Format, _Args); } }
#line 369 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
#pragma warning(push)
#pragma warning(disable:4793)
  int __cdecl sprintf(  char *_Dest,  const char * _Format, ...);   int __cdecl vsprintf(  char *_Dest,  const char * _Format, va_list _Args);
#pragma warning(pop)
  int __cdecl _vscprintf(    const char * _Format, va_list _ArgList);
  int __cdecl _snprintf_c(  char * _DstBuf,   size_t _MaxCount,     const char * _Format, ...);
  int __cdecl _vsnprintf_c(  char *_DstBuf,   size_t _MaxCount,     const char * _Format, va_list _ArgList);

  int __cdecl _fprintf_p(   FILE * _File,     const char * _Format, ...);
  int __cdecl _printf_p(    const char * _Format, ...);
  int __cdecl _sprintf_p(    char * _Dst,   size_t _MaxCount,     const char * _Format, ...);
  int __cdecl _vfprintf_p(   FILE * _File,     const char * _Format, va_list _ArgList);
  int __cdecl _vprintf_p(    const char * _Format, va_list _ArgList);
  int __cdecl _vsprintf_p(    char * _Dst,   size_t _MaxCount,     const char * _Format, va_list _ArgList);
  int __cdecl _scprintf_p(    const char * _Format, ...);
  int __cdecl _vscprintf_p(    const char * _Format, va_list _ArgList);
 int __cdecl _set_printf_count_output(  int _Value);
 int __cdecl _get_printf_count_output(void);

  int __cdecl _printf_l(    const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _printf_p_l(    const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _printf_s_l(    const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _vprintf_l(    const char * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vprintf_p_l(    const char * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vprintf_s_l(    const char * _Format,    _locale_t _Locale, va_list _ArgList);

  int __cdecl _fprintf_l(   FILE * _File,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _fprintf_p_l(   FILE * _File,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _fprintf_s_l(   FILE * _File,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _vfprintf_l(   FILE * _File,    const char * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfprintf_p_l(   FILE * _File,    const char * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfprintf_s_l(   FILE * _File,    const char * _Format,    _locale_t _Locale, va_list _ArgList);

   int __cdecl _sprintf_l(   char * _DstBuf,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _sprintf_p_l(    char * _DstBuf,   size_t _MaxCount,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _sprintf_s_l(    char * _DstBuf,   size_t _DstSize,     const char * _Format,    _locale_t _Locale, ...);
   int __cdecl _vsprintf_l(   char * _DstBuf,    const char * _Format,    _locale_t, va_list _ArgList);
  int __cdecl _vsprintf_p_l(    char * _DstBuf,   size_t _MaxCount,     const char* _Format,    _locale_t _Locale,  va_list _ArgList);
  int __cdecl _vsprintf_s_l(    char * _DstBuf,   size_t _DstSize,     const char * _Format,    _locale_t _Locale, va_list _ArgList);

  int __cdecl _scprintf_l(    const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _scprintf_p_l(    const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _vscprintf_l(    const char * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vscprintf_p_l(    const char * _Format,    _locale_t _Locale, va_list _ArgList);

   int __cdecl _snprintf_l(  char * _DstBuf,   size_t _MaxCount,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _snprintf_c_l(  char * _DstBuf,   size_t _MaxCount,     const char * _Format,    _locale_t _Locale, ...);
  int __cdecl _snprintf_s_l(    char * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const char * _Format,    _locale_t _Locale, ...);
   int __cdecl _vsnprintf_l(  char * _DstBuf,   size_t _MaxCount,     const char * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnprintf_c_l(  char * _DstBuf,   size_t _MaxCount, const char *,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnprintf_s_l(    char * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const char* _Format,   _locale_t _Locale, va_list _ArgList);







#line 428 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"




  FILE * __cdecl _wfsopen(   const wchar_t * _Filename,    const wchar_t * _Mode,   int _ShFlag);
#line 434 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

  wint_t __cdecl fgetwc(   FILE * _File);
  wint_t __cdecl _fgetwchar(void);
  wint_t __cdecl fputwc(  wchar_t _Ch,    FILE * _File);
  wint_t __cdecl _fputwchar(  wchar_t _Ch);
  wint_t __cdecl getwc(   FILE * _File);
  wint_t __cdecl getwchar(void);
  wint_t __cdecl putwc(  wchar_t _Ch,    FILE * _File);
  wint_t __cdecl putwchar(  wchar_t _Ch);
  wint_t __cdecl ungetwc(  wint_t _Ch,    FILE * _File);

  wchar_t * __cdecl fgetws(    wchar_t * _Dst,   int _SizeInWords,    FILE * _File);
  int __cdecl fputws(   const wchar_t * _Str,    FILE * _File);
  wchar_t * __cdecl _getws_s(    wchar_t * _Str,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline wchar_t * __cdecl _getws_s(  wchar_t (&_String)[_Size]) throw() { return _getws_s(_String, _Size); } }
  wchar_t * __cdecl _getws(  wchar_t *_String);
  int __cdecl _putws(   const wchar_t * _Str);

  int __cdecl fwprintf(   FILE * _File,     const wchar_t * _Format, ...);

  int __cdecl fwprintf_s(   FILE * _File,     const wchar_t * _Format, ...);
#line 456 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl wprintf(    const wchar_t * _Format, ...);

  int __cdecl wprintf_s(    const wchar_t * _Format, ...);
#line 460 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _scwprintf(    const wchar_t * _Format, ...);
  int __cdecl vfwprintf(   FILE * _File,     const wchar_t * _Format, va_list _ArgList);

  int __cdecl vfwprintf_s(   FILE * _File,     const wchar_t * _Format, va_list _ArgList);
#line 465 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl vwprintf(    const wchar_t * _Format, va_list _ArgList);

  int __cdecl vwprintf_s(    const wchar_t * _Format, va_list _ArgList);
#line 469 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"


 int __cdecl swprintf_s(    wchar_t * _Dst,   size_t _SizeInWords,     const wchar_t * _Format, ...);
#line 473 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl swprintf_s(  wchar_t (&_Dest)[_Size],     const wchar_t * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return vswprintf_s(_Dest, _Size, _Format, _ArgList); } __pragma(warning(pop)); }

 int __cdecl vswprintf_s(    wchar_t * _Dst,   size_t _SizeInWords,     const wchar_t * _Format, va_list _ArgList);
#line 477 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
extern "C++" { template <size_t _Size> inline int __cdecl vswprintf_s(  wchar_t (&_Dest)[_Size],     const wchar_t * _Format, va_list _Args) throw() { return vswprintf_s(_Dest, _Size, _Format, _Args); } }

  int __cdecl _swprintf_c(    wchar_t * _DstBuf,   size_t _SizeInWords,     const wchar_t * _Format, ...);
  int __cdecl _vswprintf_c(    wchar_t * _DstBuf,   size_t _SizeInWords,     const wchar_t * _Format, va_list _ArgList);

  int __cdecl _snwprintf_s(    wchar_t * _DstBuf,   size_t _SizeInWords,   size_t _MaxCount,     const wchar_t * _Format, ...);
extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl _snwprintf_s(  wchar_t (&_Dest)[_Size],   size_t _Count,     const wchar_t * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return _vsnwprintf_s(_Dest, _Size, _Count, _Format, _ArgList); } __pragma(warning(pop)); }
  int __cdecl _vsnwprintf_s(    wchar_t * _DstBuf,   size_t _SizeInWords,   size_t _MaxCount,     const wchar_t * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl _vsnwprintf_s(  wchar_t (&_Dest)[_Size],   size_t _Count,     const wchar_t * _Format, va_list _Args) throw() { return _vsnwprintf_s(_Dest, _Size, _Count, _Format, _Args); } }
#pragma warning(push)
#pragma warning(disable:4793)
  int __cdecl _snwprintf(   wchar_t *_Dest,   size_t _Count,     const wchar_t * _Format, ...);   int __cdecl _vsnwprintf(   wchar_t *_Dest,   size_t _Count,     const wchar_t * _Format, va_list _Args);
#pragma warning(pop)

  int __cdecl _fwprintf_p(   FILE * _File,     const wchar_t * _Format, ...);
  int __cdecl _wprintf_p(    const wchar_t * _Format, ...);
  int __cdecl _vfwprintf_p(   FILE * _File,     const wchar_t * _Format, va_list _ArgList);
  int __cdecl _vwprintf_p(    const wchar_t * _Format, va_list _ArgList);
  int __cdecl _swprintf_p(    wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format, ...);
  int __cdecl _vswprintf_p(    wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format, va_list _ArgList);
  int __cdecl _scwprintf_p(    const wchar_t * _Format, ...);
  int __cdecl _vscwprintf_p(    const wchar_t * _Format, va_list _ArgList);

  int __cdecl _wprintf_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _wprintf_p_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _wprintf_s_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _vwprintf_l(    const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vwprintf_p_l(    const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vwprintf_s_l(    const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);

  int __cdecl _fwprintf_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _fwprintf_p_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _fwprintf_s_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _vfwprintf_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfwprintf_p_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfwprintf_s_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);

  int __cdecl _swprintf_c_l(    wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _swprintf_p_l(    wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _swprintf_s_l(    wchar_t * _DstBuf,   size_t _DstSize,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _vswprintf_c_l(    wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vswprintf_p_l(    wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vswprintf_s_l(    wchar_t * _DstBuf,   size_t _DstSize,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);

  int __cdecl _scwprintf_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _scwprintf_p_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _vscwprintf_p_l(    const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);

   int __cdecl _snwprintf_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _snwprintf_s_l(    wchar_t * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, ...);
   int __cdecl _vsnwprintf_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnwprintf_s_l(    wchar_t * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);










#line 540 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"


#pragma warning(push)
#pragma warning(disable:4141 4996 4793)
 __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl _swprintf(   wchar_t *_Dest,     const wchar_t * _Format, ...);  __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl _vswprintf(   wchar_t *_Dest,     const wchar_t * _Format, va_list _Args);
 __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl __swprintf_l( wchar_t *_Dest,     const wchar_t * _Format, _locale_t _Plocinfo, ...);  __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl __vswprintf_l( wchar_t *_Dest,     const wchar_t * _Format, _locale_t _Plocinfo, va_list _Args);
#pragma warning(pop)


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\swprintf.inl"












#pragma once







#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\swprintf.inl"










#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\swprintf.inl"

#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int swprintf(wchar_t * _String, size_t _Count, const wchar_t * _Format, ...)
{
    va_list _Arglist;
    int _Ret;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    _Ret = _vswprintf_c_l(_String, _Count, _Format, 0, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl vswprintf(wchar_t * _String, size_t _Count, const wchar_t * _Format, va_list _Ap)
{
    return _vswprintf_c_l(_String, _Count, _Format, 0, _Ap);
}
#pragma warning( pop )


#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\swprintf.inl"

#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int _swprintf_l(wchar_t * _String, size_t _Count, const wchar_t * _Format, _locale_t _Plocinfo, ...)
{
    va_list _Arglist;
    int _Ret;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Plocinfo) ) + ( (sizeof(_Plocinfo) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    _Ret = _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl _vswprintf_l(wchar_t * _String, size_t _Count, const wchar_t * _Format, _locale_t _Plocinfo, va_list _Ap)
{
    return _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Ap);
}
#pragma warning( pop )


#pragma warning( push )
#pragma warning( disable : 4996 )

#pragma warning( push )
#pragma warning( disable : 4793 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  __inline int swprintf(   wchar_t * _String,     const wchar_t * _Format, ...)
{
    va_list _Arglist;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    int _Ret = _vswprintf(_String, _Format, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  __inline int __cdecl vswprintf(   wchar_t * _String,     const wchar_t * _Format, va_list _Ap)
{
    return _vswprintf(_String, _Format, _Ap);
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4793 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  __inline int _swprintf_l(   wchar_t * _String,     const wchar_t * _Format, _locale_t _Plocinfo, ...)
{
    va_list _Arglist;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Plocinfo) ) + ( (sizeof(_Plocinfo) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    int _Ret = __vswprintf_l(_String, _Format, _Plocinfo, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  __inline int __cdecl _vswprintf_l(   wchar_t * _String,     const wchar_t * _Format, _locale_t _Plocinfo, va_list _Ap)
{
    return __vswprintf_l(_String, _Format, _Plocinfo, _Ap);
}
#pragma warning( pop )

#pragma warning( pop )

#line 126 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\swprintf.inl"

#line 128 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\swprintf.inl"
#line 129 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\swprintf.inl"

#line 550 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
#line 551 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"













#line 565 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

  wchar_t * __cdecl _wtempnam(   const wchar_t * _Directory,    const wchar_t * _FilePrefix);



#line 571 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

  int __cdecl _vscwprintf(    const wchar_t * _Format, va_list _ArgList);
  int __cdecl _vscwprintf_l(    const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
   int __cdecl fwscanf(   FILE * _File,     const wchar_t * _Format, ...);
   int __cdecl _fwscanf_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl fwscanf_s(   FILE * _File,     const wchar_t * _Format, ...);
#line 581 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _fwscanf_s_l(   FILE * _File,     const wchar_t * _Format,    _locale_t _Locale, ...);
   int __cdecl swscanf(   const wchar_t * _Src,     const wchar_t * _Format, ...);
   int __cdecl _swscanf_l(   const wchar_t * _Src,     const wchar_t * _Format,    _locale_t _Locale, ...);

  int __cdecl swscanf_s(   const wchar_t *_Src,     const wchar_t * _Format, ...);
#line 587 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _swscanf_s_l(   const wchar_t * _Src,     const wchar_t * _Format,    _locale_t _Locale, ...);
   int __cdecl _snwscanf(     const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format, ...);
   int __cdecl _snwscanf_l(     const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _snwscanf_s(     const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format, ...);
  int __cdecl _snwscanf_s_l(     const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format,    _locale_t _Locale, ...);
   int __cdecl wscanf(    const wchar_t * _Format, ...);
   int __cdecl _wscanf_l(    const wchar_t * _Format,    _locale_t _Locale, ...);

  int __cdecl wscanf_s(    const wchar_t * _Format, ...);
#line 597 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
  int __cdecl _wscanf_s_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
#pragma warning(pop)

  FILE * __cdecl _wfdopen(  int _FileHandle ,    const wchar_t * _Mode);
   FILE * __cdecl _wfopen(   const wchar_t * _Filename,    const wchar_t * _Mode);
  errno_t __cdecl _wfopen_s(     FILE ** _File,    const wchar_t * _Filename,    const wchar_t * _Mode);
   FILE * __cdecl _wfreopen(   const wchar_t * _Filename,    const wchar_t * _Mode,    FILE * _OldFile);
  errno_t __cdecl _wfreopen_s(     FILE ** _File,    const wchar_t * _Filename,    const wchar_t * _Mode,    FILE * _OldFile);





  FILE * __cdecl _wpopen(   const wchar_t *_Command,    const wchar_t * _Mode);
 int __cdecl _wremove(   const wchar_t * _Filename);
  errno_t __cdecl _wtmpnam_s(    wchar_t * _DstBuf,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wtmpnam_s(  wchar_t (&_Buffer)[_Size]) throw() { return _wtmpnam_s(_Buffer, _Size); } }
  wchar_t * __cdecl _wtmpnam(  wchar_t *_Buffer);

  wint_t __cdecl _fgetwc_nolock(   FILE * _File);
  wint_t __cdecl _fputwc_nolock(  wchar_t _Ch,    FILE * _File);
  wint_t __cdecl _ungetwc_nolock(  wint_t _Ch,    FILE * _File);






#line 626 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"
inline wint_t __cdecl getwchar()
        {return (fgetwc((&__iob_func()[0]))); }   
inline wint_t __cdecl putwchar(wchar_t _C)
        {return (fputwc(_C, (&__iob_func()[1]))); }       
#line 631 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"










#line 642 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"


#line 645 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"


#line 648 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"















#line 664 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"











 void __cdecl _lock_file(   FILE * _File);
 void __cdecl _unlock_file(   FILE * _File);

  int __cdecl _fclose_nolock(   FILE * _File);
  int __cdecl _fflush_nolock(   FILE * _File);
  size_t __cdecl _fread_nolock(  void * _DstBuf,   size_t _ElementSize,   size_t _Count,    FILE * _File);
  size_t __cdecl _fread_nolock_s(  void * _DstBuf,   size_t _DstSize,   size_t _ElementSize,   size_t _Count,    FILE * _File);
  int __cdecl _fseek_nolock(   FILE * _File,   long _Offset,   int _Origin);
  long __cdecl _ftell_nolock(   FILE * _File);
  int __cdecl _fseeki64_nolock(   FILE * _File,   __int64 _Offset,   int _Origin);
  __int64 __cdecl _ftelli64_nolock(   FILE * _File);
  size_t __cdecl _fwrite_nolock(   const void * _DstBuf,   size_t _Size,   size_t _Count,    FILE * _File);
  int __cdecl _ungetc_nolock(  int _Ch,    FILE * _File);












#line 701 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"











#line 713 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_tempnam" ". See online help for details."))  char * __cdecl tempnam(   const char * _Directory,    const char * _FilePrefix);



#line 719 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcloseall" ". See online help for details."))  int __cdecl fcloseall(void);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fdopen" ". See online help for details."))  FILE * __cdecl fdopen(  int _FileHandle,    const char * _Format);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fgetchar" ". See online help for details."))  int __cdecl fgetchar(void);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fileno" ". See online help for details."))  int __cdecl fileno(  FILE * _File);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_flushall" ". See online help for details."))  int __cdecl flushall(void);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fputchar" ". See online help for details."))  int __cdecl fputchar(  int _Ch);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_getw" ". See online help for details."))  int __cdecl getw(   FILE * _File);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putw" ". See online help for details."))  int __cdecl putw(  int _Ch,    FILE * _File);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_rmtmp" ". See online help for details."))  int __cdecl rmtmp(void);

#line 731 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"


}
#line 735 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

#pragma pack(pop)

#line 739 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdio.h"

#line 14 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdio"
#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdio"


 
 
 
 
 
 
 

 
 
 
 





typedef FILE _iobuf;

 
namespace std {
using :: _iobuf;

using :: size_t; using :: fpos_t; using :: FILE;
using :: clearerr; using :: fclose; using :: feof;
using :: ferror; using :: fflush; using :: fgetc;
using :: fgetpos; using :: fgets; using :: fopen;
using :: fprintf; using :: fputc; using :: fputs;
using :: fread; using :: freopen; using :: fscanf;
using :: fseek; using :: fsetpos; using :: ftell;
using :: fwrite; using :: getc; using :: getchar;
using :: gets; using :: perror;
using :: putc; using :: putchar;
using :: printf; using :: puts; using :: remove;
using :: rename; using :: rewind; using :: scanf;
using :: setbuf; using :: setvbuf; using :: sprintf;
using :: sscanf; using :: tmpfile; using :: tmpnam;
using :: ungetc; using :: vfprintf; using :: vprintf;
using :: vsprintf;
}
 #line 58 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdio"

#line 60 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdio"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstring"

#pragma once










 
#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstring"

 
namespace std {
using :: size_t; using :: memchr; using :: memcmp;

using :: memcpy; using :: memmove; using :: memset;
using :: strcat; using :: strchr; using :: strcmp;
using :: strcoll; using :: strcpy; using :: strcspn;
using :: strerror; using :: strlen; using :: strncat;
using :: strncmp; using :: strncpy; using :: strpbrk;
using :: strrchr; using :: strspn; using :: strstr;
using :: strtok; using :: strxfrm;
}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstring"

#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstring"





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cwchar"

#pragma once










 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

















#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 24 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#pragma pack(push,8)


extern "C" {
#line 30 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"





















































typedef unsigned long _fsize_t; 

#line 86 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"



struct _wfinddata32_t {
        unsigned    attrib;
        __time32_t  time_create;    
        __time32_t  time_access;    
        __time32_t  time_write;
        _fsize_t    size;
        wchar_t     name[260];
};

struct _wfinddata32i64_t {
        unsigned    attrib;
        __time32_t  time_create;    
        __time32_t  time_access;    
        __time32_t  time_write;
        __int64     size;
        wchar_t     name[260];
};

struct _wfinddata64i32_t {
        unsigned    attrib;
        __time64_t  time_create;    
        __time64_t  time_access;    
        __time64_t  time_write;
        _fsize_t    size;
        wchar_t     name[260];
};

struct _wfinddata64_t {
        unsigned    attrib;
        __time64_t  time_create;    
        __time64_t  time_access;    
        __time64_t  time_write;
        __int64     size;
        wchar_t     name[260];
};



















#line 144 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


#line 147 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"






























#line 178 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#line 180 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
#line 181 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

 const unsigned short * __cdecl __pctype_func(void);

 extern const unsigned short *_pctype;


#line 188 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
#line 189 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
#line 190 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"





 extern const unsigned short _wctype[];
#line 197 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

 const wctype_t * __cdecl __pwctype_func(void);

 extern const wctype_t *_pwctype;


#line 204 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
#line 205 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
#line 206 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"







                                
















  int __cdecl iswalpha(  wint_t _C);
  int __cdecl _iswalpha_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswupper(  wint_t _C);
  int __cdecl _iswupper_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswlower(  wint_t _C);
  int __cdecl _iswlower_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswdigit(  wint_t _C);
  int __cdecl _iswdigit_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswxdigit(  wint_t _C);
  int __cdecl _iswxdigit_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswspace(  wint_t _C);
  int __cdecl _iswspace_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswpunct(  wint_t _C);
  int __cdecl _iswpunct_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswalnum(  wint_t _C);
  int __cdecl _iswalnum_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswprint(  wint_t _C);
  int __cdecl _iswprint_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswgraph(  wint_t _C);
  int __cdecl _iswgraph_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswcntrl(  wint_t _C);
  int __cdecl _iswcntrl_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl iswascii(  wint_t _C);
  int __cdecl isleadbyte(  int _C);
  int __cdecl _isleadbyte_l(  int _C,    _locale_t _Locale);

  wint_t __cdecl towupper(  wint_t _C);
  wint_t __cdecl _towupper_l(  wint_t _C,    _locale_t _Locale);
  wint_t __cdecl towlower(  wint_t _C);
  wint_t __cdecl _towlower_l(  wint_t _C,    _locale_t _Locale); 
  int __cdecl iswctype(  wint_t _C,   wctype_t _Type);
  int __cdecl _iswctype_l(  wint_t _C,   wctype_t _Type,    _locale_t _Locale);

  int __cdecl __iswcsymf(  wint_t _C);
  int __cdecl _iswcsymf_l(  wint_t _C,    _locale_t _Locale);
  int __cdecl __iswcsym(  wint_t _C);
  int __cdecl _iswcsym_l(  wint_t _C,    _locale_t _Locale);

__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "iswctype" " instead. See online help for details."))  int __cdecl is_wctype(  wint_t _C,   wctype_t _Type);


#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"












#line 285 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

    wchar_t * __cdecl _wgetcwd(  wchar_t * _DstBuf,   int _SizeInWords);
    wchar_t * __cdecl _wgetdcwd(  int _Drive,   wchar_t * _DstBuf,   int _SizeInWords);
   wchar_t * __cdecl _wgetdcwd_nolock(  int _Drive,   wchar_t * _DstBuf,   int _SizeInWords);





#line 295 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

  int __cdecl _wchdir(   const wchar_t * _Path);
  int __cdecl _wmkdir(   const wchar_t * _Path);
  int __cdecl _wrmdir(   const wchar_t * _Path);


#line 302 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"



  int __cdecl _waccess(   const wchar_t * _Filename,   int _AccessMode);
  errno_t __cdecl _waccess_s(   const wchar_t * _Filename,   int _AccessMode);
  int __cdecl _wchmod(   const wchar_t * _Filename,   int _Mode);
   int __cdecl _wcreat(   const wchar_t * _Filename,   int _PermissionMode);
  intptr_t __cdecl _wfindfirst32(   const wchar_t * _Filename,   struct _wfinddata32_t * _FindData);
  int __cdecl _wfindnext32(  intptr_t _FindHandle,   struct _wfinddata32_t * _FindData);
 int __cdecl _wunlink(   const wchar_t * _Filename);
  int __cdecl _wrename(   const wchar_t * _OldFilename,    const wchar_t * _NewFilename);
 errno_t __cdecl _wmktemp_s(    wchar_t * _TemplateName,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wmktemp_s(wchar_t (&_TemplateName)[_Size]) throw() { return _wmktemp_s(_TemplateName, _Size); } }
  wchar_t * __cdecl _wmktemp(  wchar_t *_TemplateName);

  intptr_t __cdecl _wfindfirst32i64(   const wchar_t * _Filename,   struct _wfinddata32i64_t * _FindData);
  intptr_t __cdecl _wfindfirst64i32(   const wchar_t * _Filename,   struct _wfinddata64i32_t * _FindData);
  intptr_t __cdecl _wfindfirst64(   const wchar_t * _Filename,   struct _wfinddata64_t * _FindData);
  int __cdecl _wfindnext32i64(  intptr_t _FindHandle,   struct _wfinddata32i64_t * _FindData);
  int __cdecl _wfindnext64i32(  intptr_t _FindHandle,   struct _wfinddata64i32_t * _FindData);
  int __cdecl _wfindnext64(  intptr_t _FindHandle,   struct _wfinddata64_t * _FindData);

  errno_t __cdecl _wsopen_s(  int * _FileHandle,    const wchar_t * _Filename,   int _OpenFlag,   int _ShareFlag,   int _PermissionFlag);






#line 332 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


extern "C++"   int __cdecl _wopen(   const wchar_t * _Filename,   int _OpenFlag,   int _PermissionMode = 0);
extern "C++"   int __cdecl _wsopen(   const wchar_t * _Filename,   int _OpenFlag,   int _ShareFlag, int _PermissionMode = 0);

#line 338 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


#line 341 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"





  wchar_t * __cdecl _wsetlocale(  int _Category,    const wchar_t * _Locale);


#line 350 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"





 intptr_t __cdecl _wexecl(   const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wexecle(   const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wexeclp(   const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wexeclpe(   const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wexecv(   const wchar_t * _Filename,    const wchar_t * const * _ArgList);
 intptr_t __cdecl _wexecve(   const wchar_t * _Filename,    const wchar_t * const * _ArgList,
           const wchar_t * const * _Env);
 intptr_t __cdecl _wexecvp(   const wchar_t * _Filename,    const wchar_t * const * _ArgList);
 intptr_t __cdecl _wexecvpe(   const wchar_t * _Filename,    const wchar_t * const * _ArgList, 
           const wchar_t * const * _Env);
 intptr_t __cdecl _wspawnl(  int _Mode,    const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wspawnle(  int _Mode,    const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wspawnlp(  int _Mode,    const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wspawnlpe(  int _Mode,    const wchar_t * _Filename,    const wchar_t * _ArgList, ...);
 intptr_t __cdecl _wspawnv(  int _Mode,    const wchar_t * _Filename,    const wchar_t * const * _ArgList);
 intptr_t __cdecl _wspawnve(  int _Mode,    const wchar_t * _Filename,    const wchar_t * const * _ArgList,
           const wchar_t * const * _Env);
 intptr_t __cdecl _wspawnvp(  int _Mode,    const wchar_t * _Filename,    const wchar_t * const * _ArgList);
 intptr_t __cdecl _wspawnvpe(  int _Mode,    const wchar_t * _Filename,    const wchar_t * const * _ArgList,
           const wchar_t * const * _Env);






#line 382 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


































#line 417 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


























#line 444 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#line 446 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"







typedef unsigned short _ino_t;      


typedef unsigned short ino_t;
#line 458 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#line 460 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


typedef unsigned int _dev_t;        


typedef unsigned int dev_t;
#line 467 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#line 469 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


typedef long _off_t;                


typedef long off_t;
#line 476 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#line 478 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"



struct _stat32 {
        _dev_t     st_dev;
        _ino_t     st_ino;
        unsigned short st_mode;
        short      st_nlink;
        short      st_uid;
        short      st_gid;
        _dev_t     st_rdev;
        _off_t     st_size;
        __time32_t st_atime;
        __time32_t st_mtime;
        __time32_t st_ctime;
        };



struct stat {
        _dev_t     st_dev;
        _ino_t     st_ino;
        unsigned short st_mode;
        short      st_nlink;
        short      st_uid;
        short      st_gid;
        _dev_t     st_rdev;
        _off_t     st_size;
        time_t st_atime;
        time_t st_mtime;
        time_t st_ctime;
        };

#line 512 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

struct _stat32i64 {
        _dev_t     st_dev;
        _ino_t     st_ino;
        unsigned short st_mode;
        short      st_nlink;
        short      st_uid;
        short      st_gid;
        _dev_t     st_rdev;
        __int64    st_size;
        __time32_t st_atime;
        __time32_t st_mtime;
        __time32_t st_ctime;
        };

struct _stat64i32 {
        _dev_t     st_dev;
        _ino_t     st_ino;
        unsigned short st_mode;
        short      st_nlink;
        short      st_uid;
        short      st_gid;
        _dev_t     st_rdev;
        _off_t     st_size;
        __time64_t st_atime;
        __time64_t st_mtime;
        __time64_t st_ctime;
        };

struct _stat64 {
        _dev_t     st_dev;
        _ino_t     st_ino;
        unsigned short st_mode;
        short      st_nlink;
        short      st_uid;
        short      st_gid;
        _dev_t     st_rdev;
        __int64    st_size;
        __time64_t st_atime;
        __time64_t st_mtime;
        __time64_t st_ctime;
        };























#line 578 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"



#line 582 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"





 int __cdecl _wstat32(   const wchar_t * _Name,   struct _stat32 * _Stat);

 int __cdecl _wstat32i64(   const wchar_t * _Name,   struct _stat32i64 * _Stat);
 int __cdecl _wstat64i32(   const wchar_t * _Name,   struct _stat64i32 * _Stat);
 int __cdecl _wstat64(   const wchar_t * _Name,   struct _stat64 * _Stat);


#line 595 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#line 597 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"










  errno_t __cdecl _cgetws_s(    wchar_t * _Buffer, size_t _SizeInWords,   size_t * _SizeRead);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _cgetws_s(  wchar_t (&_Buffer)[_Size], size_t * _SizeRead) throw() { return _cgetws_s(_Buffer, _Size, _SizeRead); } }
  wchar_t * __cdecl _cgetws(    wchar_t *_Buffer);
  wint_t __cdecl _getwch(void);
  wint_t __cdecl _getwche(void);
  wint_t __cdecl _putwch(wchar_t _WCh);
  wint_t __cdecl _ungetwch(wint_t _WCh);
  int __cdecl _cputws(   const wchar_t * _String);
  int __cdecl _cwprintf(    const wchar_t * _Format, ...);
  int __cdecl _cwprintf_s(    const wchar_t * _Format, ...);
   int __cdecl _cwscanf(    const wchar_t * _Format, ...);
   int __cdecl _cwscanf_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _cwscanf_s(    const wchar_t * _Format, ...);
  int __cdecl _cwscanf_s_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
  int __cdecl _vcwprintf(    const wchar_t *_Format, va_list _ArgList);
  int __cdecl _vcwprintf_s(    const wchar_t *_Format, va_list _ArgList);

  int __cdecl _cwprintf_p(    const wchar_t * _Format, ...);
  int __cdecl _vcwprintf_p(    const wchar_t*  _Format, va_list _ArgList);

 int __cdecl _cwprintf_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
 int __cdecl _cwprintf_s_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
 int __cdecl _vcwprintf_l(    const wchar_t *_Format,    _locale_t _Locale, va_list _ArgList);
 int __cdecl _vcwprintf_s_l(    const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);
 int __cdecl _cwprintf_p_l(    const wchar_t * _Format,    _locale_t _Locale, ...);
 int __cdecl _vcwprintf_p_l(    const wchar_t * _Format,    _locale_t _Locale, va_list _ArgList);

 wint_t __cdecl _putwch_nolock(wchar_t _WCh);
 wint_t __cdecl _getwch_nolock(void);
 wint_t __cdecl _getwche_nolock(void);
 wint_t __cdecl _ungetwch_nolock(wint_t _WCh);


#line 641 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"






























































































































































































































































































































#line 960 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"






















































































































































struct tm {
        int tm_sec;     
        int tm_min;     
        int tm_hour;    
        int tm_mday;    
        int tm_mon;     
        int tm_year;    
        int tm_wday;    
        int tm_yday;    
        int tm_isdst;   
        };

#line 1123 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"




 
  wchar_t * __cdecl _wasctime(  const struct tm * _Tm);
 errno_t __cdecl _wasctime_s(    wchar_t *_Buf,   size_t _SizeInWords,   const struct tm * _Tm);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wasctime_s(  wchar_t (&_Buffer)[_Size],   const struct tm * _Time) throw() { return _wasctime_s(_Buffer, _Size, _Time); } }

  wchar_t * __cdecl _wctime32(  const __time32_t *_Time);
 errno_t __cdecl _wctime32_s(    wchar_t* _Buf,   size_t _SizeInWords,   const __time32_t * _Time);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wctime32_s(  wchar_t (&_Buffer)[_Size],   const __time32_t * _Time) throw() { return _wctime32_s(_Buffer, _Size, _Time); } }

 size_t __cdecl wcsftime(    wchar_t * _Buf,   size_t _SizeInWords,     const wchar_t * _Format,    const struct tm * _Tm);
 size_t __cdecl _wcsftime_l(    wchar_t * _Buf,   size_t _SizeInWords,     const wchar_t *_Format,   const struct tm *_Tm,    _locale_t _Locale);

 errno_t __cdecl _wstrdate_s(    wchar_t * _Buf,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wstrdate_s(  wchar_t (&_Buffer)[_Size]) throw() { return _wstrdate_s(_Buffer, _Size); } }
  wchar_t * __cdecl _wstrdate(  wchar_t *_Buffer);

 errno_t __cdecl _wstrtime_s(    wchar_t * _Buf,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wstrtime_s(  wchar_t (&_Buffer)[_Size]) throw() { return _wstrtime_s(_Buffer, _Size); } }
  wchar_t * __cdecl _wstrtime(  wchar_t *_Buffer);

  wchar_t * __cdecl _wctime64(  const __time64_t * _Time);
 errno_t __cdecl _wctime64_s(    wchar_t* _Buf,   size_t _SizeInWords,   const __time64_t *_Time);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wctime64_s(  wchar_t (&_Buffer)[_Size],   const __time64_t * _Time) throw() { return _wctime64_s(_Buffer, _Size, _Time); } }


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wtime.inl"












#pragma once







#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wtime.inl"





#pragma warning(push)
#pragma warning(disable:4996)















static __inline wchar_t * __cdecl _wctime(const time_t * _Time)
{
#pragma warning( push )
#pragma warning( disable : 4996 )
    return _wctime64(_Time);
#pragma warning( pop )
}

static __inline errno_t __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t * _Time)
{
    return _wctime64_s(_Buffer, _SizeInWords, _Time);
}
#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wtime.inl"

#pragma warning(pop)

#line 61 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wtime.inl"
#line 62 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wtime.inl"
#line 1153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
#line 1154 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


#line 1157 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


typedef int mbstate_t;
typedef wchar_t _Wint_t;

 wint_t __cdecl btowc(int);
 size_t __cdecl mbrlen(     const char * _Ch,   size_t _SizeInBytes,
                                mbstate_t * _State);
 size_t __cdecl mbrtowc(   wchar_t * _DstCh,      const char * _SrcCh,
                                 size_t _SizeInBytes,   mbstate_t * _State);
 errno_t __cdecl mbsrtowcs_s(  size_t* _Retval,     wchar_t * _Dst,   size_t _Size,        const char ** _PSrc,   size_t _N,   mbstate_t * _State);
extern "C++" { template <size_t _Size> inline errno_t __cdecl mbsrtowcs_s(  size_t * _Retval,   wchar_t (&_Dest)[_Size],        const char ** _PSource,   size_t _Count,   mbstate_t * _State) throw() { return mbsrtowcs_s(_Retval, _Dest, _Size, _PSource, _Count, _State); } }
  size_t __cdecl mbsrtowcs(  wchar_t *_Dest,  const char ** _PSrc,  size_t _Count,  mbstate_t * _State);

 errno_t __cdecl wcrtomb_s(  size_t * _Retval,     char * _Dst,
          size_t _SizeInBytes,   wchar_t _Ch,   mbstate_t * _State);
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcrtomb_s(  size_t * _Retval,     char (&_Dest)[_Size],   wchar_t _Source,   mbstate_t * _State) throw() { return wcrtomb_s(_Retval, _Dest, _Size, _Source, _State); } }
  size_t __cdecl wcrtomb(  char *_Dest,  wchar_t _Source,  mbstate_t * _State);
 errno_t __cdecl wcsrtombs_s(  size_t * _Retval,     char * _Dst,
          size_t _SizeInBytes,        const wchar_t ** _Src,   size_t _Size,   mbstate_t * _State);
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcsrtombs_s(  size_t * _Retval,     char (&_Dest)[_Size],        const wchar_t ** _PSrc,   size_t _Count,   mbstate_t * _State) throw() { return wcsrtombs_s(_Retval, _Dest, _Size, _PSrc, _Count, _State); } }
  size_t __cdecl wcsrtombs(  char *_Dest,  const wchar_t ** _PSource,  size_t _Count,  mbstate_t * _State);
 int __cdecl wctob(  wint_t _WCh);






#line 1187 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
  void *  __cdecl memmove(    void * _Dst,    const void * _Src,   size_t _Size);
#line 1189 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
 void *  __cdecl memcpy(    void * _Dst,    const void * _Src,   size_t _Size);

 errno_t __cdecl memcpy_s(    void * _Dst,   rsize_t _DstSize,    const void * _Src,   rsize_t _MaxCount);
 errno_t __cdecl memmove_s(    void * _Dst,   rsize_t _DstSize,    const void * _Src,   rsize_t _MaxCount);
#line 1194 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
__inline int __cdecl fwide(   FILE * _F, int _M)
        {(void)_F; return (_M); }
__inline int __cdecl mbsinit(   const mbstate_t *_P)
        {return (_P == 0 || *_P == 0); }
__inline const wchar_t * __cdecl wmemchr(   const wchar_t *_S,   wchar_t _C,   size_t _N)
        {for (; 0 < _N; ++_S, --_N)
                if (*_S == _C)
                        return (const wchar_t *)(_S);
        return (0); }
__inline int __cdecl wmemcmp(   const wchar_t *_S1,    const wchar_t *_S2,   size_t _N)
        {for (; 0 < _N; ++_S1, ++_S2, --_N)
                if (*_S1 != *_S2)
                        return (*_S1 < *_S2 ? -1 : +1);
        return (0); }

__inline  wchar_t * __cdecl wmemcpy(  wchar_t *_S1,    const wchar_t *_S2,   size_t _N)
        {
#pragma warning( push )
#pragma warning( disable : 4996 6386 )
            return (wchar_t *)memcpy(_S1, _S2, _N*sizeof(wchar_t));
#pragma warning( pop )
        }

__inline  wchar_t * __cdecl wmemmove(    wchar_t *_S1,    const wchar_t *_S2,   size_t _N)
        {
#pragma warning( push )
#pragma warning( disable : 4996 6386 )
#pragma warning( disable : 6387)
			
            return (wchar_t *)memmove(_S1, _S2, _N*sizeof(wchar_t));
#pragma warning( pop )
        }


errno_t __cdecl wmemcpy_s(    wchar_t *_S1,   rsize_t _N1,    const wchar_t *_S2, rsize_t _N);
errno_t __cdecl wmemmove_s(    wchar_t *_S1,   rsize_t _N1,    const wchar_t *_S2,   rsize_t _N);
#line 1231 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

__inline wchar_t * __cdecl wmemset(    wchar_t *_S,   wchar_t _C,   size_t _N)
        {
            wchar_t *_Su = _S;
            for (; 0 < _N; ++_Su, --_N)
            {
                *_Su = _C;
            }
            return (_S);
        }


extern "C++" {
inline wchar_t * __cdecl wmemchr(   wchar_t *_S,   wchar_t _C,   size_t _N)
        { return (wchar_t *)wmemchr((const wchar_t *)_S, _C, _N); }
}
#line 1248 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"
#line 1249 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"


}       
#line 1253 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#pragma pack(pop)

#line 1257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wchar.h"

#line 14 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cwchar"
#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cwchar"

typedef mbstate_t _Mbstatet;

 
namespace std {
using :: _Mbstatet;

using :: mbstate_t; using :: size_t;
using :: tm; using :: wint_t;

using :: btowc; using :: fgetwc; using :: fgetws; using :: fputwc;
using :: fputws; using :: fwide; using :: fwprintf;
using :: fwscanf; using :: getwc; using :: getwchar;
using :: mbrlen; using :: mbrtowc; using :: mbsrtowcs;
using :: mbsinit; using :: putwc; using :: putwchar;
using :: swprintf; using :: swscanf; using :: ungetwc;
using :: vfwprintf; using :: vswprintf; using :: vwprintf;
using :: wcrtomb; using :: wprintf; using :: wscanf;
using :: wcsrtombs; using :: wcstol; using :: wcscat;
using :: wcschr; using :: wcscmp; using :: wcscoll;
using :: wcscpy; using :: wcscspn; using :: wcslen;
using :: wcsncat; using :: wcsncmp; using :: wcsncpy;
using :: wcspbrk; using :: wcsrchr; using :: wcsspn;

using :: wcstod; using :: wcstoul; using :: wcsstr;

using :: wcstok; using :: wcsxfrm; using :: wctob;
using :: wmemchr; using :: wmemcmp; using :: wmemcpy;
using :: wmemmove; using :: wmemset; using :: wcsftime;
}
 #line 46 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cwchar"

#line 48 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cwchar"





#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"












#pragma once

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"




#pragma pack(push,8)












extern "C" {
#line 35 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"

 





typedef void *_HFILE; 























#line 67 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"


typedef int (__cdecl * _CRT_REPORT_HOOK)(int, char *, int *);
typedef int (__cdecl * _CRT_REPORT_HOOKW)(int, wchar_t *, int *);



#line 75 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"




#line 80 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"




 





 










typedef int (__cdecl * _CRT_ALLOC_HOOK)(int, void *, size_t, int, long, const unsigned char *, int);


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"


#line 108 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"

 





































 














typedef void (__cdecl * _CRT_DUMP_CLIENT)(void *, size_t);


#line 166 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"


#line 169 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"

struct _CrtMemBlockHeader;
typedef struct _CrtMemState
{
        struct _CrtMemBlockHeader * pBlockHeader;
        size_t lCounts[5];
        size_t lSizes[5];
        size_t lHighWaterCount;
        size_t lTotalCount;
} _CrtMemState;


 















 













#line 212 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"



#line 216 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"



#line 220 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"



#line 224 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"





























































































































































































































































































































































































































































































































































































































































































































































































































#line 1022 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"


}



extern "C++" {



 







 
#pragma warning(suppress: 4985)
 void * __cdecl operator new[](size_t _Size);


 void * __cdecl operator new(
        size_t _Size,
        int,
        const char *,
        int
        );

#pragma warning(suppress: 4985)
 void * __cdecl operator new[](
        size_t _Size,
        int,
        const char *,
        int
        );

void __cdecl operator delete[](void *);

inline void __cdecl operator delete(void * _P, int, const char *, int)
        { ::operator delete(_P); }
inline void __cdecl operator delete[](void * _P, int, const char *, int)
        { ::operator delete[](_P); }
#line 1067 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"
























































#line 1124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"

}

#line 1128 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"

#line 1130 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"

#pragma pack(pop)

#line 1134 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdbg.h"

#line 12 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"

 #pragma pack(push,8)
 #pragma warning(push,3)

namespace std {
		

typedef _Longlong streamoff;
typedef _Longlong streamsize;

  
  

  


extern   const streamoff _BADOFF;
  #line 30 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"

		
template<class _Statetype>
	class fpos
	{	
	typedef fpos<_Statetype> _Myt;

public:
	 fpos(streamoff _Off = 0)
		: _Myoff(_Off), _Fpos(0), _Mystate(_Stz)
		{	
		}

	 fpos(_Statetype _State, fpos_t _Fileposition)
		: _Myoff(0), _Fpos(_Fileposition), _Mystate(_State)
		{	
		}

	_Statetype  state() const
		{	
		return (_Mystate);
		}

	void  state(_Statetype _State)
		{	
		_Mystate = _State;
		}

	fpos_t  seekpos() const
		{	
		return (_Fpos);
		}

	 operator streamoff() const
		{	
		return ((streamoff)(_Myoff + ((long)(_Fpos))));
		}

	streamoff  operator-(const _Myt& _Right) const
		{	
		return ((streamoff)*this - (streamoff)_Right);
		}

	_Myt&  operator+=(streamoff _Off)
		{	
		_Myoff += _Off;
		return (*this);
		}

	_Myt&  operator-=(streamoff _Off)
		{	
		_Myoff -= _Off;
		return (*this);
		}

	_Myt  operator+(streamoff _Off) const
		{	
		_Myt _Tmp = *this;
		return (_Tmp += _Off);
		}

	_Myt  operator-(streamoff _Off) const
		{	
		_Myt _Tmp = *this;
		return (_Tmp -= _Off);
		}

	bool  operator==(const _Myt& _Right) const
		{	
		return ((streamoff)*this == (streamoff)_Right);
		}

	bool  operator==(streamoff _Right) const
		{	
		return ((streamoff)*this == _Right);
		}

	bool  operator!=(const _Myt& _Right) const
		{	
		return (!(*this == _Right));
		}

private:
	 static const _Statetype _Stz;	
	streamoff _Myoff;	
	fpos_t _Fpos;	
	_Statetype _Mystate;	
	};

	
template<class _Statetype>
	 const _Statetype fpos<_Statetype>::_Stz = _Statetype();

 

 
 

typedef fpos<_Mbstatet> streampos;

typedef streampos wstreampos;

		
template<class _Elem,
	class _Int_type>
	struct _Char_traits
	{	
	typedef _Elem char_type;
	typedef _Int_type int_type;
	typedef streampos pos_type;
	typedef streamoff off_type;
	typedef _Mbstatet state_type;

	static int __cdecl compare(
		   const _Elem *_First1,
		   const _Elem *_First2, size_t _Count)
		{	
		for (; 0 < _Count; --_Count, ++_First1, ++_First2)
			if (!eq(*_First1, *_First2))
				return (lt(*_First1, *_First2) ? -1 : +1);
		return (0);
		}

	static size_t __cdecl length(   const _Elem *_First)
		{	
		size_t _Count;
		for (_Count = 0; !eq(*_First, _Elem()); ++_First)
			++_Count;
		return (_Count);
		}

	static _Elem *__cdecl copy(
		  _Elem *_First1,
		   const _Elem *_First2, size_t _Count)
		{	
		_Elem *_Next = _First1;
		for (; 0 < _Count; --_Count, ++_Next, ++_First2)
			assign(*_Next, *_First2);
		return (_First1);
		}

	static _Elem *__cdecl _Copy_s(
		  _Elem *_First1, size_t _Dest_size,
		   const _Elem *_First2, size_t _Count)
		{	
		{ if (!(_Dest_size >= _Count)) { ((void)0); ::_invalid_parameter_noinfo_noreturn(); return (0); } };
		return (copy(_First1, _First2, _Count));
		}

	static const _Elem *__cdecl find(
		   const _Elem *_First,
		size_t _Count, const _Elem& _Ch)
		{	
		for (; 0 < _Count; --_Count, ++_First)
			if (eq(*_First, _Ch))
				return (_First);
		return (0);
		}

	static _Elem *__cdecl move(
		  _Elem *_First1,
		   const _Elem *_First2, size_t _Count)
		{	
		_Elem *_Next = _First1;
		if (_First2 < _Next && _Next < _First2 + _Count)
			for (_Next += _Count, _First2 += _Count; 0 < _Count; --_Count)
				assign(*--_Next, *--_First2);
		else
			for (; 0 < _Count; --_Count, ++_Next, ++_First2)
				assign(*_Next, *_First2);
		return (_First1);
		}

	static _Elem *__cdecl assign(
		  _Elem *_First,
		size_t _Count, _Elem _Ch)
		{	
		_Elem *_Next = _First;
		for (; 0 < _Count; --_Count, ++_Next)
			assign(*_Next, _Ch);
		return (_First);
		}

	static void __cdecl assign(_Elem& _Left, const _Elem& _Right)
		{	
		_Left = _Right;
		}

	static bool __cdecl eq(const _Elem& _Left, const _Elem& _Right)
		{	
		return (_Left == _Right);
		}

	static bool __cdecl lt(const _Elem& _Left, const _Elem& _Right)
		{	
		return (_Left < _Right);
		}

	static _Elem __cdecl to_char_type(const int_type& _Meta)
		{	
		return ((_Elem)_Meta);
		}

	static int_type __cdecl to_int_type(const _Elem& _Ch)
		{	
		return ((int_type)_Ch);
		}

	static bool __cdecl eq_int_type(const int_type& _Left,
		const int_type& _Right)
		{	
		return (_Left == _Right);
		}

	static int_type __cdecl not_eof(const int_type& _Meta)
		{	
		return (_Meta != eof() ? (int_type)_Meta : (int_type)!eof());
		}

	static int_type __cdecl eof()
		{	
		return ((int_type)(-1));
		}
	};

		
template<class _Elem>
	struct char_traits
		: public _Char_traits<_Elem, long>
	{	
	};

 













#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"

		
template<>
	struct char_traits<wchar_t>
	{	
	typedef wchar_t _Elem;
	typedef _Elem char_type;	
	typedef wint_t int_type;
	typedef streampos pos_type;
	typedef streamoff off_type;
	typedef _Mbstatet state_type;

	static int __cdecl compare(const _Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return (:: wmemcmp(_First1, _First2, _Count));
		}

	static size_t __cdecl length(const _Elem *_First)
		{	
		return (:: wcslen(_First));
		}

	static _Elem *__cdecl copy(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return ((_Elem *):: wmemcpy(_First1, _First2, _Count));
		}

	static _Elem *__cdecl _Copy_s(
		  _Elem *_First1, size_t _Size_in_words,
		   const _Elem *_First2, size_t _Count)
		{	
		::wmemcpy_s((_First1), (_Size_in_words), (_First2), (_Count));
		return _First1;
		}

	static const _Elem *__cdecl find(const _Elem *_First, size_t _Count,
		const _Elem& _Ch)
		{	
		return ((const _Elem *):: wmemchr(_First, _Ch, _Count));
		}

	static _Elem *__cdecl move(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return ((_Elem *):: wmemmove(_First1, _First2, _Count));
		}

	static _Elem *__cdecl assign(_Elem *_First, size_t _Count, _Elem _Ch)
		{	
		return ((_Elem *):: wmemset(_First, _Ch, _Count));
		}

	static void __cdecl assign(_Elem& _Left, const _Elem& _Right)
		{	
		_Left = _Right;
		}

	static bool __cdecl eq(const _Elem& _Left, const _Elem& _Right)
		{	
		return (_Left == _Right);
		}

	static bool __cdecl lt(const _Elem& _Left, const _Elem& _Right)
		{	
		return (_Left < _Right);
		}

	static _Elem __cdecl to_char_type(const int_type& _Meta)
		{	
		return (_Meta);
		}

	static int_type __cdecl to_int_type(const _Elem& _Ch)
		{	
		return (_Ch);
		}

	static bool __cdecl eq_int_type(const int_type& _Left,
		const int_type& _Right)
		{	
		return (_Left == _Right);
		}

	static int_type __cdecl not_eof(const int_type& _Meta)
		{	
		return (_Meta != eof() ? _Meta : !eof());
		}

	static int_type __cdecl eof()
		{	
		return ((wint_t)(0xFFFF));
		}
	};

 
		
template<> struct char_traits<unsigned short>
	{	
	typedef unsigned short _Elem;
	typedef _Elem char_type;	
	typedef wint_t int_type;
	typedef streampos pos_type;
	typedef streamoff off_type;
	typedef _Mbstatet state_type;

	static int __cdecl compare(const _Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return (:: wmemcmp((const wchar_t *)_First1,
			(const wchar_t *)_First2, _Count));
		}

	static size_t __cdecl length(const _Elem *_First)
		{	
		return (:: wcslen((const wchar_t *)_First));
		}

	static _Elem *__cdecl copy(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return ((_Elem *):: wmemcpy((wchar_t *)_First1,
			(const wchar_t *)_First2, _Count));
		}

	static _Elem *__cdecl _Copy_s(
		  _Elem *_First1, size_t _Size_in_words,
		   const _Elem *_First2, size_t _Count)
		{	
		::wmemcpy_s(((wchar_t *)_First1), (_Size_in_words), ((const wchar_t *)_First2), (_Count));
		return _First1;
		}

	static const _Elem *__cdecl find(const _Elem *_First, size_t _Count,
		const _Elem& _Ch)
		{	
		return ((const _Elem *):: wmemchr((const wchar_t *)_First,
			_Ch, _Count));
		}

	static _Elem *__cdecl move(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return ((_Elem *):: wmemmove((wchar_t *)_First1,
			(const wchar_t *)_First2, _Count));
		}

	static _Elem *__cdecl assign(_Elem *_First, size_t _Count, _Elem _Ch)
		{	
		return ((_Elem *):: wmemset((wchar_t *)_First, _Ch, _Count));
		}

	static void __cdecl assign(_Elem& _Left, const _Elem& _Right)
		{	
		_Left = _Right;
		}

	static bool __cdecl eq(const _Elem& _Left, const _Elem& _Right)
		{	
		return (_Left == _Right);
		}

	static bool __cdecl lt(const _Elem& _Left, const _Elem& _Right)
		{	
		return (_Left < _Right);
		}

	static _Elem __cdecl to_char_type(const int_type& _Meta)
		{	
		return (_Meta);
		}

	static int_type __cdecl to_int_type(const _Elem& _Ch)
		{	
		return (_Ch);
		}

	static bool __cdecl eq_int_type(const int_type& _Left,
		const int_type& _Right)
		{	
		return (_Left == _Right);
		}

	static int_type __cdecl not_eof(const int_type& _Meta)
		{	
		return (_Meta != eof() ? _Meta : !eof());
		}

	static int_type __cdecl eof()
		{	
		return ((wint_t)(0xFFFF));
		}
	};
 #line 472 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"

		
template<> struct char_traits<char>
	{	
	typedef char _Elem;
	typedef _Elem char_type;
	typedef int int_type;
	typedef streampos pos_type;
	typedef streamoff off_type;
	typedef _Mbstatet state_type;

	static int __cdecl compare(const _Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return (:: memcmp(_First1, _First2, _Count));
		}

	static size_t __cdecl length(const _Elem *_First)
		{	
		return (:: strlen(_First));
		}

	static _Elem *__cdecl copy(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return ((_Elem *):: memcpy(_First1, _First2, _Count));
		}

	static _Elem *__cdecl _Copy_s(
		  _Elem *_First1, size_t _Size_in_bytes,
		   const _Elem *_First2, size_t _Count)
		{	
		::memcpy_s((_First1), (_Size_in_bytes), (_First2), (_Count));
		return _First1;
		}

	static const _Elem *__cdecl find(const _Elem *_First, size_t _Count,
		const _Elem& _Ch)
		{	
		return ((const _Elem *):: memchr(_First, _Ch, _Count));
		}

	static _Elem *__cdecl move(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
		{	
		return ((_Elem *):: memmove(_First1, _First2, _Count));
		}

	static _Elem *__cdecl assign(_Elem *_First, size_t _Count, _Elem _Ch)
		{	
		return ((_Elem *):: memset(_First, _Ch, _Count));
		}

	static void __cdecl assign(_Elem& _Left, const _Elem& _Right)
		{	
		_Left = _Right;
		}

	static bool __cdecl eq(const _Elem& _Left, const _Elem& _Right)
		{	
		return (_Left == _Right);
		}

	static bool __cdecl lt(const _Elem& _Left, const _Elem& _Right)
		{	
		return ((unsigned char)_Left < (unsigned char)_Right);
		}

	static _Elem __cdecl to_char_type(const int_type& _Meta)
		{	
		return ((_Elem)_Meta);
		}

	static int_type __cdecl to_int_type(const _Elem& _Ch)
		{	
		return ((unsigned char)_Ch);
		}

	static bool __cdecl eq_int_type(const int_type& _Left,
		const int_type& _Right)
		{	
		return (_Left == _Right);
		}

	static int_type __cdecl not_eof(const int_type& _Meta)
		{	
		return (_Meta != eof() ? _Meta : !eof());
		}

	static int_type __cdecl eof()
		{	
		return ((-1));
		}
	};

		
template<class _Ty>
	class allocator;
class ios_base;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_ios;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class istreambuf_iterator;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class ostreambuf_iterator;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_streambuf;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_istream;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_ostream;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_iostream;
template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Alloc = allocator<_Elem> >
	class basic_stringbuf;
template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Alloc = allocator<_Elem> >
	class basic_istringstream;
template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Alloc = allocator<_Elem> >
	class basic_ostringstream;
template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Alloc = allocator<_Elem> >
	class basic_stringstream;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_filebuf;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_ifstream;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_ofstream;
template<class _Elem,
	class _Traits = char_traits<_Elem> >
	class basic_fstream;

 








#line 631 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"

		
typedef basic_ios<char, char_traits<char> > ios;
typedef basic_streambuf<char, char_traits<char> > streambuf;
typedef basic_istream<char, char_traits<char> > istream;
typedef basic_ostream<char, char_traits<char> > ostream;
typedef basic_iostream<char, char_traits<char> > iostream;
typedef basic_stringbuf<char, char_traits<char>,
	allocator<char> > stringbuf;
typedef basic_istringstream<char, char_traits<char>,
	allocator<char> > istringstream;
typedef basic_ostringstream<char, char_traits<char>,
	allocator<char> > ostringstream;
typedef basic_stringstream<char, char_traits<char>,
	allocator<char> > stringstream;
typedef basic_filebuf<char, char_traits<char> > filebuf;
typedef basic_ifstream<char, char_traits<char> > ifstream;
typedef basic_ofstream<char, char_traits<char> > ofstream;
typedef basic_fstream<char, char_traits<char> > fstream;

		
typedef basic_ios<wchar_t, char_traits<wchar_t> > wios;
typedef basic_streambuf<wchar_t, char_traits<wchar_t> >
	wstreambuf;
typedef basic_istream<wchar_t, char_traits<wchar_t> > wistream;
typedef basic_ostream<wchar_t, char_traits<wchar_t> > wostream;
typedef basic_iostream<wchar_t, char_traits<wchar_t> > wiostream;
typedef basic_stringbuf<wchar_t, char_traits<wchar_t>,
	allocator<wchar_t> > wstringbuf;
typedef basic_istringstream<wchar_t, char_traits<wchar_t>,
	allocator<wchar_t> > wistringstream;
typedef basic_ostringstream<wchar_t, char_traits<wchar_t>,
	allocator<wchar_t> > wostringstream;
typedef basic_stringstream<wchar_t, char_traits<wchar_t>,
	allocator<wchar_t> > wstringstream;
typedef basic_filebuf<wchar_t, char_traits<wchar_t> > wfilebuf;
typedef basic_ifstream<wchar_t, char_traits<wchar_t> > wifstream;
typedef basic_ofstream<wchar_t, char_traits<wchar_t> > wofstream;
typedef basic_fstream<wchar_t, char_traits<wchar_t> > wfstream;


 










#line 684 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 690 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"
#line 691 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ymath.h"

#pragma once





 
extern "C" {
 #line 11 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ymath.h"


#pragma pack(push, 8)

		





		






		
typedef union
	{	
	unsigned short _Word[8];
	float _Float;
	double _Double;
	long double _Long_double;
	} _Dconst;

		
void __cdecl _Feraise(int);

		
 double __cdecl _Cosh(double, double);
 short __cdecl _Dtest(double *);
 short __cdecl _Exp(double *, double, short);
 double __cdecl _Sinh(double, double);
extern   _Dconst _Denorm, _Hugeval, _Inf,
	_Nan, _Snan;

		
 float __cdecl _FCosh(float, float);
 short __cdecl _FDtest(float *);
 short __cdecl _FExp(float *, float, short);
 float __cdecl _FSinh(float, float);
extern   _Dconst _FDenorm, _FInf, _FNan, _FSnan;

		
 long double __cdecl _LCosh(long double, long double);
 short __cdecl _LDtest(long double *);
 short __cdecl _LExp(long double *, long double, short);
 long double __cdecl _LSinh(long double, long double);
extern   _Dconst _LDenorm, _LInf, _LNan, _LSnan;

 
}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ymath.h"


#pragma pack(pop)

#line 70 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ymath.h"
#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ymath.h"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cfloat"

#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"















#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtwrn.h"











#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtwrn.h"






























































#line 81 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtwrn.h"
#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"








#line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"

#line 34 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"
#line 35 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"
#line 36 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"


extern "C" {
#line 40 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"











































  unsigned int __cdecl _clearfp(void);
#pragma warning(push)
#pragma warning(disable: 4141)
   unsigned int __cdecl _controlfp(  unsigned int _NewValue,  unsigned int _Mask);
#pragma warning(pop)
  void __cdecl _set_controlfp(  unsigned int _NewValue,   unsigned int _Mask);
  errno_t __cdecl _controlfp_s(  unsigned int *_CurrentState,   unsigned int _NewValue,   unsigned int _Mask);
  unsigned int __cdecl _statusfp(void);
  void __cdecl _fpreset(void);


  void __cdecl _statusfp2(  unsigned int *_X86_status,   unsigned int *_SSE2_status);
#line 96 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"










































































#line 171 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"

  unsigned int __cdecl _control87(  unsigned int _NewValue,  unsigned int _Mask);

  int __cdecl __control87_2(  unsigned int _NewValue,   unsigned int _Mask,
                                    unsigned int* _X86_cw,   unsigned int* _Sse2_cw);
#line 177 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"



  extern int * __cdecl __fpecode(void);































  double __cdecl _copysign (  double _Number,   double _Sign);
  double __cdecl _chgsign (  double _X);

#line 216 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"
  double __cdecl _scalb(  double _X,   long _Y);
  double __cdecl _logb(  double _X);
  double __cdecl _nextafter(  double _X,   double _Y);
  int    __cdecl _finite(  double _X);
  int    __cdecl _isnan(  double _X);
  int    __cdecl _fpclass(  double _X);

























  void __cdecl fpreset(void);





























































#line 310 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"


}
#line 314 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"

#line 316 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\float.h"
#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cfloat"

#line 10 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cfloat"





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cmath"

#pragma once










 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"

















#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 19 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"





#pragma pack(push,8)


extern "C" {
#line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"








struct _exception {
        int type;       
        char *name;     
        double arg1;    
        double arg2;    
        double retval;  
        } ;


#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"







struct _complex {
        double x,y; 
        } ;




#line 62 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"


#line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
#line 66 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"






















 extern double _HUGE;


#line 92 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
#line 93 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"













        double  __cdecl acos(  double _X);
        double  __cdecl asin(  double _X);
        double  __cdecl atan(  double _X);
        double  __cdecl atan2(  double _Y,   double _X);





        double  __cdecl cos(  double _X);
        double  __cdecl cosh(  double _X);
        double  __cdecl exp(  double _X);
 double  __cdecl fabs(  double _X);
        double  __cdecl fmod(  double _X,   double _Y);
        double  __cdecl log(  double _X);
        double  __cdecl log10(  double _X);
        double  __cdecl pow(  double _X,   double _Y);
        double  __cdecl sin(  double _X);
        double  __cdecl sinh(  double _X);
        double  __cdecl tan(  double _X);
        double  __cdecl tanh(  double _X);
        double  __cdecl sqrt(  double _X);






 double  __cdecl _cabs(  struct _complex _Complex_value);
 double  __cdecl ceil(  double _X);
 double  __cdecl floor(  double _X);
 double  __cdecl frexp(  double _X,   int * _Y);
 double  __cdecl _hypot(  double _X,   double _Y);
 float   __cdecl _hypotf(  float _X,   float _Y);
 double  __cdecl _j0(  double _X );
 double  __cdecl _j1(  double _X );
 double  __cdecl _jn(int _X,   double _Y);
 double  __cdecl ldexp(  double _X,   int _Y);




#line 149 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
        int     __cdecl _matherr(   struct _exception * _Except);
#line 151 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
#line 152 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
 double  __cdecl modf(  double _X,   double * _Y);

 double  __cdecl _y0(  double _X);
 double  __cdecl _y1(  double _X);
 double  __cdecl _yn(  int _X,   double _Y);




static __inline double __cdecl hypot(  double _X,   double _Y)
{
    return _hypot(_X, _Y);
}

static __inline float __cdecl hypotf(  float _X,   float _Y)
{
    return _hypotf(_X, _Y);
}

#line 172 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"



 int     __cdecl _set_SSE2_enable(  int _Flag);

#line 178 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"






































#line 217 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"











































#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"



































































inline long double acosl(  long double _X)
        {return (acos((double)_X)); }
inline long double asinl(  long double _X)
        {return (asin((double)_X)); }
inline long double atanl(  long double _X)
        {return (atan((double)_X)); }
inline long double atan2l(  long double _Y,   long double _X)
        {return (atan2((double)_Y, (double)_X)); }
inline long double ceill(  long double _X)
        {return (ceil((double)_X)); }
inline long double cosl(  long double _X)
        {return (cos((double)_X)); }
inline long double coshl(  long double _X)
        {return (cosh((double)_X)); }
inline long double expl(  long double _X)
        {return (exp((double)_X)); }
inline long double fabsl(  long double _X)
        {return (fabs((double)_X)); }
inline long double floorl(  long double _X)
        {return (floor((double)_X)); }
inline long double fmodl(  long double _X,   long double _Y)
        {return (fmod((double)_X, (double)_Y)); }
inline long double frexpl(  long double _X,   int *_Y)
        {return (frexp((double)_X, _Y)); }
inline long double ldexpl(  long double _X,   int _Y)
        {return (ldexp((double)_X, _Y)); }
inline long double logl(  long double _X)
        {return (log((double)_X)); }
inline long double log10l(  long double _X)
        {return (log10((double)_X)); }
inline long double modfl(  long double _X,   long double *_Y)
        {double _Di, _Df = modf((double)_X, &_Di);
        *_Y = (long double)_Di;
        return (_Df); }
inline long double powl(  long double _X,   long double _Y)
        {return (pow((double)_X, (double)_Y)); }
inline long double sinl(  long double _X)
        {return (sin((double)_X)); }
inline long double sinhl(  long double _X)
        {return (sinh((double)_X)); }
inline long double sqrtl(  long double _X)
        {return (sqrt((double)_X)); }

inline long double tanl(  long double _X)
        {return (tan((double)_X)); }


#line 376 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"

inline long double tanhl(  long double _X)
        {return (tanh((double)_X)); }

inline long double _chgsignl(  long double _Number)
{
    return _chgsign(static_cast<double>(_Number)); 
}

inline long double _copysignl(  long double _Number,   long double _Sign)
{
    return _copysign(static_cast<double>(_Number), static_cast<double>(_Sign)); 
}

inline float frexpf(  float _X,   int *_Y)
        {return ((float)frexp((double)_X, _Y)); }


inline float fabsf(  float _X)
        {return ((float)fabs((double)_X)); }
inline float ldexpf(  float _X,   int _Y)
        {return ((float)ldexp((double)_X, _Y)); }

inline float acosf(  float _X)
        {return ((float)acos((double)_X)); }
inline float asinf(  float _X)
        {return ((float)asin((double)_X)); }
inline float atanf(  float _X)
        {return ((float)atan((double)_X)); }
inline float atan2f(  float _Y,   float _X)
        {return ((float)atan2((double)_Y, (double)_X)); }
inline float ceilf(  float _X)
        {return ((float)ceil((double)_X)); }
inline float cosf(  float _X)
        {return ((float)cos((double)_X)); }
inline float coshf(  float _X)
        {return ((float)cosh((double)_X)); }
inline float expf(  float _X)
        {return ((float)exp((double)_X)); }
inline float floorf(  float _X)
        {return ((float)floor((double)_X)); }
inline float fmodf(  float _X,   float _Y)
        {return ((float)fmod((double)_X, (double)_Y)); }
inline float logf(  float _X)
        {return ((float)log((double)_X)); }
inline float log10f(  float _X)
        {return ((float)log10((double)_X)); }
inline float modff(  float _X,   float *_Y)
        { double _Di, _Df = modf((double)_X, &_Di);
        *_Y = (float)_Di;
        return ((float)_Df); }
inline float powf(  float _X,   float _Y)
        {return ((float)pow((double)_X, (double)_Y)); }
inline float sinf(  float _X)
        {return ((float)sin((double)_X)); }
inline float sinhf(  float _X)
        {return ((float)sinh((double)_X)); }
inline float sqrtf(  float _X)
        {return ((float)sqrt((double)_X)); }
inline float tanf(  float _X)
        {return ((float)tan((double)_X)); }
inline float tanhf(  float _X)
        {return ((float)tanh((double)_X)); }
#line 440 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
#line 441 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
#line 442 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
#line 443 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"

















 extern double HUGE;


#line 464 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_cabs" ". See online help for details."))  double  __cdecl cabs(  struct _complex _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j0" ". See online help for details."))  double  __cdecl j0(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j1" ". See online help for details."))  double  __cdecl j1(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_jn" ". See online help for details."))  double  __cdecl jn(  int _X,   double _Y);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y0" ". See online help for details."))  double  __cdecl y0(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y1" ". See online help for details."))  double  __cdecl y1(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_yn" ". See online help for details."))  double  __cdecl yn(  int _X,   double _Y);

#line 474 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"

#line 476 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"


}

extern "C++" {

template<class _Ty> inline
        _Ty _Pow_int(_Ty _X, int _Y)
        {unsigned int _N;
        if (_Y >= 0)
                _N = (unsigned int)_Y;
        else
                _N = (unsigned int)(-_Y);
        for (_Ty _Z = _Ty(1); ; _X *= _X)
                {if ((_N & 1) != 0)
                        _Z *= _X;
                if ((_N >>= 1) == 0)
                        return (_Y < 0 ? _Ty(1) / _Z : _Z); }}

inline double __cdecl abs(  double _X)
        {return (fabs(_X)); }
inline double __cdecl pow(  double _X,   int _Y)
        {return (_Pow_int(_X, _Y)); }
inline float __cdecl abs(  float _X)
        {return (fabsf(_X)); }
inline float __cdecl acos(  float _X)
        {return (acosf(_X)); }
inline float __cdecl asin(  float _X)
        {return (asinf(_X)); }
inline float __cdecl atan(  float _X)
        {return (atanf(_X)); }
inline float __cdecl atan2(  float _Y,   float _X)
        {return (atan2f(_Y, _X)); }
inline float __cdecl ceil(  float _X)
        {return (ceilf(_X)); }
inline float __cdecl cos(  float _X)
        {return (cosf(_X)); }
inline float __cdecl cosh(  float _X)
        {return (coshf(_X)); }
inline float __cdecl exp(  float _X)
        {return (expf(_X)); }
inline float __cdecl fabs(  float _X)
        {return (fabsf(_X)); }
inline float __cdecl floor(  float _X)
        {return (floorf(_X)); }
inline float __cdecl fmod(  float _X,   float _Y)
        {return (fmodf(_X, _Y)); }
inline float __cdecl frexp(  float _X,   int * _Y)
        {return (frexpf(_X, _Y)); }
inline float __cdecl ldexp(  float _X,   int _Y)
        {return (ldexpf(_X, _Y)); }
inline float __cdecl log(  float _X)
        {return (logf(_X)); }
inline float __cdecl log10(  float _X)
        {return (log10f(_X)); }
inline float __cdecl modf(  float _X,   float * _Y)
        {return (modff(_X, _Y)); }
inline float __cdecl pow(  float _X,   float _Y)
        {return (powf(_X, _Y)); }
inline float __cdecl pow(  float _X,   int _Y)
        {return (_Pow_int(_X, _Y)); }
inline float __cdecl sin(  float _X)
        {return (sinf(_X)); }
inline float __cdecl sinh(  float _X)
        {return (sinhf(_X)); }
inline float __cdecl sqrt(  float _X)
        {return (sqrtf(_X)); }
inline float __cdecl tan(  float _X)
        {return (tanf(_X)); }
inline float __cdecl tanh(  float _X)
        {return (tanhf(_X)); }
inline long double __cdecl abs(  long double _X)
        {return (fabsl(_X)); }
inline long double __cdecl acos(  long double _X)
        {return (acosl(_X)); }
inline long double __cdecl asin(  long double _X)
        {return (asinl(_X)); }
inline long double __cdecl atan(  long double _X)
        {return (atanl(_X)); }
inline long double __cdecl atan2(  long double _Y,   long double _X)
        {return (atan2l(_Y, _X)); }
inline long double __cdecl ceil(  long double _X)
        {return (ceill(_X)); }
inline long double __cdecl cos(  long double _X)
        {return (cosl(_X)); }
inline long double __cdecl cosh(  long double _X)
        {return (coshl(_X)); }
inline long double __cdecl exp(  long double _X)
        {return (expl(_X)); }
inline long double __cdecl fabs(  long double _X)
        {return (fabsl(_X)); }
inline long double __cdecl floor(  long double _X)
        {return (floorl(_X)); }
inline long double __cdecl fmod(  long double _X,   long double _Y)
        {return (fmodl(_X, _Y)); }
inline long double __cdecl frexp(  long double _X,   int * _Y)
        {return (frexpl(_X, _Y)); }
inline long double __cdecl ldexp(  long double _X,   int _Y)
        {return (ldexpl(_X, _Y)); }
inline long double __cdecl log(  long double _X)
        {return (logl(_X)); }
inline long double __cdecl log10(  long double _X)
        {return (log10l(_X)); }
inline long double __cdecl modf(  long double _X,   long double * _Y)
        {return (modfl(_X, _Y)); }
inline long double __cdecl pow(  long double _X,   long double _Y)
        {return (powl(_X, _Y)); }
inline long double __cdecl pow(  long double _X,   int _Y)
        {return (_Pow_int(_X, _Y)); }
inline long double __cdecl sin(  long double _X)
        {return (sinl(_X)); }
inline long double __cdecl sinh(  long double _X)
        {return (sinhl(_X)); }
inline long double __cdecl sqrt(  long double _X)
        {return (sqrtl(_X)); }
inline long double __cdecl tan(  long double _X)
        {return (tanl(_X)); }
inline long double __cdecl tanh(  long double _X)
        {return (tanhl(_X)); }

}
#line 598 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"

#pragma pack(pop)

#line 602 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"







































#line 642 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"

#line 14 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cmath"
#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cmath"

 

namespace std {
using :: acosf; using :: asinf;
using :: atanf; using :: atan2f; using :: ceilf;
using :: cosf; using :: coshf; using :: expf;
using :: fabsf; using :: floorf; using :: fmodf;
using :: frexpf; using :: ldexpf; using :: logf;
using :: log10f; using :: modff; using :: powf;
using :: sinf; using :: sinhf; using :: sqrtf;
using :: tanf; using :: tanhf;

using :: acosl; using :: asinl;
using :: atanl; using :: atan2l; using :: ceill;
using :: cosl; using :: coshl; using :: expl;
using :: fabsl; using :: floorl; using :: fmodl;
using :: frexpl; using :: ldexpl; using :: logl;
using :: log10l; using :: modfl; using :: powl;
using :: sinl; using :: sinhl; using :: sqrtl;
using :: tanl; using :: tanhl;

using :: abs;

using :: acos; using :: asin;
using :: atan; using :: atan2; using :: ceil;
using :: cos; using :: cosh; using :: exp;
using :: fabs; using :: floor; using :: fmod;
using :: frexp; using :: ldexp; using :: log;
using :: log10; using :: modf; using :: pow;
using :: sin; using :: sinh; using :: sqrt;
using :: tan; using :: tanh;
}
 #line 49 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cmath"

#line 51 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cmath"





#line 10 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"



 #pragma pack(push,8)
 #pragma warning(push,3)

namespace std {










 

		
typedef enum
	{	
	denorm_indeterminate = -1,
	denorm_absent = 0,
	denorm_present = 1}
		float_denorm_style;

		
typedef enum
	{	
	round_indeterminate = -1,
	round_toward_zero = 0,
	round_to_nearest = 1,
	round_toward_infinity = 2,
	round_toward_neg_infinity = 3}
		float_round_style;

		
struct  _Num_base
	{	
	static const float_denorm_style has_denorm = (float_denorm_style)(denorm_absent);
	static const bool has_denorm_loss = (bool)(false);
	static const bool has_infinity = (bool)(false);
	static const bool has_quiet_NaN = (bool)(false);
	static const bool has_signaling_NaN = (bool)(false);
	static const bool is_bounded = (bool)(false);
	static const bool is_exact = (bool)(false);
	static const bool is_iec559 = (bool)(false);
	static const bool is_integer = (bool)(false);
	static const bool is_modulo = (bool)(false);
	static const bool is_signed = (bool)(false);
	static const bool is_specialized = (bool)(false);
	static const bool tinyness_before = (bool)(false);
	static const bool traps = (bool)(false);
	static const float_round_style round_style = (float_round_style)(round_toward_zero);
	static const int digits = (int)(0);
	static const int digits10 = (int)(0);

 
	static const int max_digits10 = (int)(0);
 #line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static const int max_exponent = (int)(0);
	static const int max_exponent10 = (int)(0);
	static const int min_exponent = (int)(0);
	static const int min_exponent10 = (int)(0);
	static const int radix = (int)(0);
	};

		
template<class _Ty>
	class numeric_limits
		: public _Num_base
	{	
public:
	static _Ty (__cdecl min)() throw ()
		{	
		return (_Ty(0));
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (_Ty(0));
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 101 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (_Ty(0));
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (_Ty(0));
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (_Ty(0));
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (_Ty(0));
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (_Ty(0));
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (_Ty(0));
		}
	};

template<class _Ty>
	class numeric_limits<const _Ty>
		: public numeric_limits<_Ty>
	{	
	};

template<class _Ty>
	class numeric_limits<volatile _Ty>
		: public numeric_limits<_Ty>
	{	
	};

template<class _Ty>
	class numeric_limits<const volatile _Ty>
		: public numeric_limits<_Ty>
	{	
	};

		
struct  _Num_int_base
	: public _Num_base
	{	
	static const bool is_bounded = (bool)(true);
	static const bool is_exact = (bool)(true);
	static const bool is_integer = (bool)(true);
	static const bool is_modulo = (bool)(true);
	static const bool is_specialized = (bool)(true);
	static const int radix = (int)(2);
	};

		
struct  _Num_float_base
	: public _Num_base
	{	
	static const float_denorm_style has_denorm = (float_denorm_style)(denorm_present);
	static const bool has_denorm_loss = (bool)(true);
	static const bool has_infinity = (bool)(true);
	static const bool has_quiet_NaN = (bool)(true);
	static const bool has_signaling_NaN = (bool)(true);
	static const bool is_bounded = (bool)(true);
	static const bool is_exact = (bool)(false);
	static const bool is_iec559 = (bool)(true);
	static const bool is_integer = (bool)(false);
	static const bool is_modulo = (bool)(false);
	static const bool is_signed = (bool)(true);
	static const bool is_specialized = (bool)(true);
	static const bool tinyness_before = (bool)(true);
	static const bool traps = (bool)(true);
	static const float_round_style round_style = (float_round_style)(round_to_nearest);
	static const int radix = (int)(2);
	};

		
template<> class  numeric_limits<char>
	: public _Num_int_base
	{	
public:
	typedef char _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return ((-128));
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (127);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 208 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)((-128) != 0);
	static const int digits = (int)(8 - ((-128) != 0 ? 1 : 0));
	static const int digits10 = (int)((8 - ((-128) != 0 ? 1 : 0)) * 301L / 1000);
#line 243 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 - ((-128) != 0 ? 1 : 0)) * 301L / 1000);
#line 247 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 248 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<wchar_t>
	: public _Num_int_base
	{	
public:
	typedef wchar_t _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return ((_Ty)0x0000);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return ((_Ty)0xffff);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(0x0000 != 0);
	static const int digits = (int)(8 * sizeof (wchar_t) - (0x0000 != 0 ? 1 : 0));
#line 307 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	static const int digits10 = (int)((8 * sizeof (wchar_t) - (0x0000 != 0 ? 1 : 0)) * 301L / 1000);
#line 309 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (wchar_t) - (0x0000 != 0 ? 1 : 0)) * 301L / 1000);
#line 313 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 314 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<_Bool>
	: public _Num_int_base
	{	
public:
	typedef bool _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (false);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (true);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 339 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_modulo = (bool)(false);
	static const bool is_signed = (bool)(false);
	static const int digits = (int)(1);
	static const int digits10 = (int)(0);

 
	static const int max_digits10 = (int)(0);
 #line 378 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<signed char>
	: public _Num_int_base
	{	
public:
	typedef signed char _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return ((-128));
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (127);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 403 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(true);
	static const int digits = (int)(8 - 1);
	static const int digits10 = (int)((8 - 1) * 301L / 1000);

 
	static const int max_digits10 = (int)(2 + (8 - 1) * 301L / 1000);
 #line 441 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<unsigned char>
	: public _Num_int_base
	{	
public:
	typedef unsigned char _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (0);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (0xff);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 466 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(false);
	static const int digits = (int)(8);
	static const int digits10 = (int)(8 * 301L / 1000);

 
	static const int max_digits10 = (int)(2 + (8) * 301L / 1000);
 #line 504 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<short>
	: public _Num_int_base
	{	
public:
	typedef short _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return ((-32768));
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (32767);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 529 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(true);
	static const int digits = (int)(8 * sizeof (short) - 1);
	static const int digits10 = (int)((8 * sizeof (short) - 1) * 301L / 1000);
#line 564 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (short) - 1) * 301L / 1000);
#line 568 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 569 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

 
		
template<> class  numeric_limits<unsigned short>
	: public _Num_int_base
	{	
public:
	typedef unsigned short _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (0);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (0xffff);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 595 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(false);
	static const int digits = (int)(8 * sizeof (unsigned short));
	static const int digits10 = (int)(8 * sizeof (unsigned short) * 301L / 1000);
#line 630 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (unsigned short)) * 301L / 1000);
#line 634 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 635 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};
 #line 637 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 



























































#line 699 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

		
template<> class  numeric_limits<int>
	: public _Num_int_base
	{	
public:
	typedef int _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return ((-2147483647 - 1));
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (2147483647);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 723 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(true);
	static const int digits = (int)(8 * sizeof (int) - 1);
	static const int digits10 = (int)((8 * sizeof (int) - 1) * 301L / 1000);
#line 758 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (int) - 1) * 301L / 1000);
#line 762 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 763 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<unsigned int>
	: public _Num_int_base
	{	
public:
	typedef unsigned int _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (0);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (0xffffffff);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 788 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(false);
	static const int digits = (int)(8 * sizeof (unsigned int));
	static const int digits10 = (int)(8 * sizeof (unsigned int) * 301L / 1000);
#line 823 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (unsigned int)) * 301L / 1000);
#line 827 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 828 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<long>
	: public _Num_int_base
	{	
public:
	typedef long _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return ((-2147483647L - 1));
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (2147483647L);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 853 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(true);
	static const int digits = (int)(8 * sizeof (long) - 1);
	static const int digits10 = (int)((8 * sizeof (long) - 1) * 301L / 1000);
#line 888 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (long) - 1) * 301L / 1000);
#line 892 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 893 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<unsigned long>
	: public _Num_int_base
	{	
public:
	typedef unsigned long _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (0);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (0xffffffffUL);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 918 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(false);
	static const int digits = (int)(8 * sizeof (unsigned long));
	static const int digits10 = (int)(8 * sizeof (unsigned long) * 301L / 1000);
#line 953 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (unsigned long)) * 301L / 1000);
#line 957 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 958 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

 



























































#line 1021 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
		
template<> class  numeric_limits<__int64>
	: public _Num_int_base
	{	
public:
	typedef __int64 _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (-0x7fffffffffffffff - 1);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (0x7fffffffffffffff);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 1046 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(true);
	static const int digits = (int)(8 * sizeof (__int64) - 1);
	static const int digits10 = (int)((8 * sizeof (__int64) - 1) * 301L / 1000);
#line 1081 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (__int64) - 1) * 301L / 1000);
#line 1085 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 1086 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};

		
template<> class  numeric_limits<unsigned __int64>
	: public _Num_int_base
	{	
public:
	typedef unsigned __int64 _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (0);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (0xffffffffffffffff);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return ((min)());
		}
 #line 1111 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (0);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (0);
		}

	static const bool is_signed = (bool)(false);
	static const int digits = (int)(8 * sizeof (unsigned __int64));
	static const int digits10 = (int)(8 * sizeof (unsigned __int64) * 301L / 1000);
#line 1146 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

 
	static const int max_digits10 = (int)(2 + (8 * sizeof (unsigned __int64)) * 301L / 1000);
#line 1150 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
 #line 1151 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
	};
 #line 1153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

		
template<> class  numeric_limits<float>
	: public _Num_float_base
	{	
public:
	typedef float _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (1.175494351e-38F);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (3.402823466e+38F);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return (-(max)());
		}
 #line 1177 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (1.192092896e-07F);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0.5);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (:: _FDenorm._Float);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (:: _FInf._Float);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (:: _FNan._Float);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (:: _FSnan._Float);
		}

	static const int digits = (int)(24);
	static const int digits10 = (int)(6);

 
	static const int max_digits10 = (int)(2 + 6);
 #line 1214 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static const int max_exponent = (int)((int)128);
	static const int max_exponent10 = (int)((int)38);
	static const int min_exponent = (int)((int)(-125));
	static const int min_exponent10 = (int)((int)(-37));
	};

		
template<> class  numeric_limits<double>
	: public _Num_float_base
	{	
public:
	typedef double _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (2.2250738585072014e-308);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (1.7976931348623158e+308);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return (-(max)());
		}
 #line 1244 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (2.2204460492503131e-016);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0.5);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (:: _Denorm._Double);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (:: _Inf._Double);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (:: _Nan._Double);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (:: _Snan._Double);
		}

	static const int digits = (int)(53);
	static const int digits10 = (int)(15);

 
	static const int max_digits10 = (int)(2 + 15);
 #line 1281 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static const int max_exponent = (int)((int)1024);
	static const int max_exponent10 = (int)((int)308);
	static const int min_exponent = (int)((int)(-1021));
	static const int min_exponent10 = (int)((int)(-307));
	};

		
template<> class  numeric_limits<long double>
	: public _Num_float_base
	{	
public:
	typedef long double _Ty;

	static _Ty (__cdecl min)() throw ()
		{	
		return (2.2250738585072014e-308);
		}

	static _Ty (__cdecl max)() throw ()
		{	
		return (1.7976931348623158e+308);
		}

 
	static _Ty __cdecl lowest() throw ()
		{	
		return (-(max)());
		}
 #line 1311 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static _Ty __cdecl epsilon() throw ()
		{	
		return (2.2204460492503131e-016);
		}

	static _Ty __cdecl round_error() throw ()
		{	
		return (0.5);
		}

	static _Ty __cdecl denorm_min() throw ()
		{	
		return (:: _LDenorm._Long_double);
		}

	static _Ty __cdecl infinity() throw ()
		{	
		return (:: _LInf._Long_double);
		}

	static _Ty __cdecl quiet_NaN() throw ()
		{	
		return (:: _LNan._Long_double);
		}

	static _Ty __cdecl signaling_NaN() throw ()
		{	
		return (:: _LSnan._Long_double);
		}

	static const int digits = (int)(53);
	static const int digits10 = (int)(15);

 
	static const int max_digits10 = (int)(2 + 15);
 #line 1348 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"

	static const int max_exponent = (int)((int)1024);
	static const int max_exponent10 = (int)((int)308);
	static const int min_exponent = (int)((int)(-1021));
	static const int min_exponent10 = (int)((int)(-307));
	};

  
























































































































































































































































































#line 1637 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
}
 #pragma warning(pop)
 #pragma pack(pop)

#line 1642 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"
#line 1643 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\limits"






#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xtr1common"

#pragma once





 #pragma pack(push,8)
 #pragma warning(push,3)

 

 

#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xtr1common"

  

	



































































































































namespace std {		
	
template<class _T1,
	class _Ret>
	struct unary_function;

	
template<class _T1,
	class _T2,
	class _Ret>
	struct binary_function;

	namespace tr1 {	
	
struct _Nil
	{	
	};
static _Nil _Nil_obj;

	
template<class _Ty,
	_Ty _Val>
	struct integral_constant
	{	
	static const _Ty value = _Val;

	typedef _Ty value_type;
	typedef integral_constant<_Ty, _Val> type;
	};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

	
template<bool _First,
	bool _Second>
	struct _Or;
template<>
	struct _Or<false, false>
		: false_type
		{	
		};

template<>
	struct _Or<false, true>
		: true_type
		{	
		};

template<>
	struct _Or<true, false>
		: true_type
		{	
		};

template<>
	struct _Or<true, true>
		: true_type
		{	
		};

	
template<bool>
	struct _Cat_base;
template<>
	struct _Cat_base<false>
	: false_type
	{	
	};

template<>
	struct _Cat_base<true>
	: true_type
	{	
	};

	
template<class _Ty>
	struct _Is_integral
		: false_type
	{	
	};

template<>
	struct _Is_integral<bool>
		: true_type
	{	
	};

template<>
	struct _Is_integral<char>
		: true_type
	{	
	};

template<>
	struct _Is_integral<unsigned char>
		: true_type
	{	
	};

template<>
	struct _Is_integral<signed char>
		: true_type
	{	
	};

 
template<>
	struct _Is_integral<wchar_t>
		: true_type
	{	
	};
 #line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xtr1common"

template<>
	struct _Is_integral<unsigned short>
		: true_type
	{	
	};

template<>
	struct _Is_integral<signed short>
		: true_type
	{	
	};

template<>
	struct _Is_integral<unsigned int>
		: true_type
	{	
	};

template<>
	struct _Is_integral<signed int>
		: true_type
	{	
	};

template<>
	struct _Is_integral<unsigned long>
		: true_type
	{	
	};

template<>
	struct _Is_integral<signed long>
		: true_type
	{	
	};

 
template<>
	struct _Is_integral<__int64>
		: true_type
	{	
	};

template<>
	struct _Is_integral<unsigned __int64>
		: true_type
	{	
	};
 #line 315 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xtr1common"

	
template<class _Ty>
	struct _Is_floating_point
		: false_type
	{	
	};

template<>
	struct _Is_floating_point<float>
		: true_type
	{	
	};

template<>
	struct _Is_floating_point<double>
		: true_type
	{	
	};

template<>
	struct _Is_floating_point<long double>
		: true_type
	{	
	};

	
template<class _Ty>
	struct _Remove_reference
	{	
	typedef _Ty _Type;
	};

template<class _Ty>
	struct _Remove_reference<_Ty&>
	{	
	typedef _Ty _Type;
	};

template<class _Ty>
	struct _Remove_reference<_Ty&&>
	{	
	typedef _Ty _Type;
	};

	
template<class _Ty>
	struct _Remove_rvalue_reference
	{	
	typedef _Ty _Type;
	};

template<class _Ty>
	struct _Remove_rvalue_reference<_Ty&&>
	{	
	typedef _Ty _Type;
	};

	
template<class _Tgt,
	class _Src>
	struct _Copy_cv
	{	
	typedef typename _Remove_reference<_Tgt>::_Type _Tgtx;
	typedef _Tgtx& _Type;
	};

template<class _Tgt,
	class _Src>
	struct _Copy_cv<_Tgt, const _Src>
	{	
	typedef typename _Remove_reference<_Tgt>::_Type _Tgtx;
	typedef const _Tgtx& _Type;
	};

template<class _Tgt,
	class _Src>
	struct _Copy_cv<_Tgt, volatile _Src>
	{	
	typedef typename _Remove_reference<_Tgt>::_Type _Tgtx;
	typedef volatile _Tgtx& _Type;
	};

template<class _Tgt,
	class _Src>
	struct _Copy_cv<_Tgt, const volatile _Src>
	{	
	typedef typename _Remove_reference<_Tgt>::_Type _Tgtx;
	typedef const volatile _Tgtx& _Type;
	};

template<class _Tgt,
	class _Src>
	struct _Copy_cv<_Tgt, _Src&>
	{	
	typedef typename _Copy_cv<_Tgt, _Src>::_Type _Type;
	};

	
 






	
_No _Has_result_type(...);

template<class _Ty>
	_Yes _Has_result_type(_Ty *,
		typename _Remove_reference<typename _Ty::result_type>::_Type * = 0);



	}	
}
 #pragma warning(pop)
 #pragma pack(pop)

#line 436 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xtr1common"
#line 437 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xtr1common"





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

 #pragma pack(push,8)
 #pragma warning(push,3)

	


  

  


  
  
  
  


  
  
  
  
  

  

  

  

  


  

  

  

  


namespace std {
	namespace tr1 {	
	
template<class _Ty>
	struct _Ptr_traits
	{	
	};

template<class _Ty>
	struct _Ptr_traits<_Ty *>
	{	
	static const bool _Is_const = false;
	static const bool _Is_volatile = false;
	};

template<class _Ty>
	struct _Ptr_traits<const _Ty *>
	{	
	static const bool _Is_const = true;
	static const bool _Is_volatile = false;
	};

template<class _Ty>
	struct _Ptr_traits<volatile _Ty *>
	{	
	static const bool _Is_const = false;
	static const bool _Is_volatile = true;
	};

template<class _Ty>
	struct _Ptr_traits<const volatile _Ty *>
	{	
	static const bool _Is_const = true;
	static const bool _Is_volatile = true;
	};

template<class _Ty>
	struct _Is_funptr
		: false_type
	{	
	};

template<class _Ty>
	struct _Is_memfunptr
		: false_type
	{	
	};

 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 

#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 
  
  
  
  
  
  

 

















































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 




#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  
  
  
  
  
  
  
  
  
  
  
  
  

 




























#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret      >
	struct _Is_funptr<_Ret (*)(    )>
	: true_type
	{	
	};

template<class _Ret      >
	struct _Is_funptr<_Ret (*)(     ...)>
	: true_type
	{	
	};

 















































#line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"
 
#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  

 













#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0    >
	struct _Is_funptr<_Ret (*)(_Arg0    )>
	: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_funptr<_Ret (*)(_Arg0     ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(  )>
		: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(   ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(  ) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(   ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(  ) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(   ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(  ) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0    >
	struct _Is_memfunptr<_Ret (_Arg0::*)(   ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_funptr<_Ret (*)(_Arg0 ,   _Arg1)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_funptr<_Ret (*)(_Arg0 ,   _Arg1 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 ,   class _Arg1>
	struct _Is_memfunptr<_Ret (_Arg0::*)(  _Arg1 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1 , _Arg2)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1 , _Arg2 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1 , class _Arg2>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1 , _Arg2 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2 , _Arg3)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2 , _Arg3 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2 , _Arg3 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3 , _Arg4)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3 , _Arg4 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3 , _Arg4 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 37 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4 , _Arg5)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4 , _Arg5 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4 , _Arg5 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5 , _Arg6 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 45 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6 , _Arg7 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 49 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7 , _Arg8 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 53 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  

 

#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 277 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"



template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9)>
	: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_funptr<_Ret (*)(_Arg0 , _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9 ...)>
	: true_type
	{	
	};

 
template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9 ...)>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9 ...) const>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9 ...) volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9) const volatile>
		: true_type
	{	
	};

template<class _Ret , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
	struct _Is_memfunptr<_Ret (_Arg0::*)(_Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8 , _Arg9 ...) const volatile>
		: true_type
	{	
	};
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxtype_traits"





#line 278 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"




















#line 100 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

	
	
template<class _Ty>
	struct remove_const
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_const<const _Ty>
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_const<const _Ty[]>
	{	
	typedef _Ty type[];
	};

template<class _Ty, unsigned int _Nx>
	struct remove_const<const _Ty[_Nx]>
	{	
	typedef _Ty type[_Nx];
	};

	
template<class _Ty>
	struct remove_volatile
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_volatile<volatile _Ty>
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_volatile<volatile _Ty[]>
	{	
	typedef _Ty type[];
	};

template<class _Ty, unsigned int _Nx>
	struct remove_volatile<volatile _Ty[_Nx]>
	{	
	typedef _Ty type[_Nx];
	};

	
template<class _Ty>
	struct remove_cv
	{	
	typedef typename remove_const<typename remove_volatile<_Ty>::type>::type
		type;
	};

	
template<class _Ty>
	struct add_const
	{	
	typedef const _Ty type;
	};

template<class _Ty>
	struct add_const<_Ty&>
	{	
	typedef _Ty& type;
	};

	
template<class _Ty>
	struct add_volatile
	{	
	typedef volatile _Ty type;
	};

template<class _Ty>
	struct add_volatile<_Ty&>
	{	
	typedef _Ty& type;
	};

	
template<class _Ty>
	struct add_cv
	{	
	typedef typename add_const<typename add_volatile<_Ty>::type>::type type;
	};

	
template<class _Ty>
	struct remove_reference
	: _Remove_reference<_Ty>
	{	
	typedef typename _Remove_reference<_Ty>::_Type type;
	};

	
template<class _Ty>
	struct add_reference
	{	
	typedef typename _Remove_reference<_Ty>::_Type& type;
	};

template<>
	struct add_reference<void>
	{	
	typedef void type;
	};

template<>
	struct add_reference<const void>
	{	
	typedef const void type;
	};

template<>
	struct add_reference<volatile void>
	{	
	typedef volatile void type;
	};

template<>
	struct add_reference<const volatile void>
	{	
	typedef const volatile void type;
	};

	
template<class _Ty>
	struct add_lvalue_reference
	{	
	typedef typename add_reference<_Ty>::type type;
	};

	
template<class _Ty>
	struct add_rvalue_reference
	{	
	typedef _Ty && type;
	};

template<class _Ty>
	struct add_rvalue_reference<_Ty&>
	{	
	typedef _Ty& type;
	};

template<>
	struct add_rvalue_reference<void>
	{	
	typedef void type;
	};

template<>
	struct add_rvalue_reference<const void>
	{	
	typedef const void type;
	};

template<>
	struct add_rvalue_reference<volatile void>
	{	
	typedef volatile void type;
	};

template<>
	struct add_rvalue_reference<const volatile void>
	{	
	typedef const volatile void type;
	};

	
template<class _Ty>
	struct remove_extent
	{	
	typedef _Ty type;
	};

template<class _Ty, unsigned int _Ix>
	struct remove_extent<_Ty[_Ix]>
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_extent<_Ty[]>
	{	
	typedef _Ty type;
	};

	
template<class _Ty>
	struct remove_all_extents
	{	
	typedef _Ty type;
	};

template<class _Ty, unsigned int _Ix>
	struct remove_all_extents<_Ty[_Ix]>
	{	
	typedef typename remove_all_extents<_Ty>::type type;
	};

template<class _Ty>
	struct remove_all_extents<_Ty[]>
	{	
	typedef typename remove_all_extents<_Ty>::type type;
	};

	
template<class _Ty>
	struct remove_pointer
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_pointer<_Ty *>
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_pointer<_Ty *const>
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_pointer<_Ty *volatile>
	{	
	typedef _Ty type;
	};

template<class _Ty>
	struct remove_pointer<_Ty *const volatile>
	{	
	typedef _Ty type;
	};

	
template<class _Ty>
	struct add_pointer
	{	
	typedef typename remove_reference<_Ty>::type *type;
	};

	
	
template<class _Ty>
	struct _Is_void
	: false_type
	{	
	};

template<>
	struct _Is_void<void>
	: true_type
	{	
	};

template<class _Ty>
	struct is_void
	: _Is_void<typename remove_cv<_Ty>::type>
	{	
	};

	
template<class _Ty>
	struct is_integral
	: _Is_integral<typename remove_cv<_Ty>::type>
	{	
	};

	
template<class _Ty>
	struct is_floating_point
	: _Is_floating_point<typename remove_cv<_Ty>::type>
	{	
	};

	
template<class _Ty>
	struct is_array
	: false_type
	{	
	};

template<class _Ty, size_t _Nx>
	struct is_array<_Ty[_Nx]>
	: true_type
	{	
	};

template<class _Ty>
	struct is_array<_Ty[]>
	: true_type
	{	
	};

 
	
template<class _Ty>
	struct is_lvalue_reference
	: false_type
	{	
	};

template<class _Ty>
	struct is_lvalue_reference<_Ty&>
	: true_type
	{	
	};

	
template<class _Ty>
	struct is_rvalue_reference
	: false_type
	{	
	};

template<class _Ty>
	struct is_rvalue_reference<_Ty&&>
	: true_type
	{	
	};

	
template<class _Ty>
	struct is_reference
	: _Cat_base<is_lvalue_reference<_Ty>::value
		|| is_rvalue_reference<_Ty>::value>
	{	
	};

 












#line 454 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

	
template<class _Ty>
	struct _Is_member_object_pointer
	: false_type
	{	
	};

template<class _Ty1, class _Ty2>
	struct _Is_member_object_pointer<_Ty1 _Ty2::*>
	: _Cat_base<!_Is_memfunptr<_Ty1 _Ty2::*>::value>
	{	
	};

template<class _Ty>
	struct is_member_object_pointer
	: _Is_member_object_pointer<typename remove_cv<_Ty>::type>
	{	
	};

	
template<class _Ty>
	struct is_member_function_pointer
	: _Cat_base<_Is_memfunptr<typename remove_cv<_Ty>::type>::value>
	{	
	};

	
template<class _Ty>
	struct _Is_pointer
	: false_type
	{	
	};

template<class _Ty>
	struct _Is_pointer<_Ty *>
	: _Cat_base<!is_member_object_pointer<_Ty *>::value
		&& !is_member_function_pointer<_Ty *>::value>
	{	
	};

template<class _Ty>
	struct is_pointer
	: _Is_pointer<typename remove_cv<_Ty>::type>
	{	
	};

	
template<class _Ty>
	struct is_union : _Cat_base<__is_union(_Ty)>
	{	
	};

	
template<class _Ty>
	struct is_class : _Cat_base<__is_class(_Ty)>
	{	
	};

	
template<class _Ty>
	struct is_function
	: _Cat_base<_Is_funptr<typename remove_cv<_Ty>::type *>::value>
	{	
	};

template<class _Ty>
	struct is_function<_Ty&>
	: false_type
	{	
	};

	
template<class _Ty>
	struct is_arithmetic
	: _Cat_base<is_integral<_Ty>::value
		|| is_floating_point<_Ty>::value>
	{	
	};

	
template<class _Ty>
	struct is_fundamental
	: _Cat_base<is_arithmetic<_Ty>::value
		|| is_void<_Ty>::value>
	{	
	};

	
template<class _Ty>
	struct is_object
	: _Cat_base<!is_function<_Ty>::value
		&& !is_reference<_Ty>::value
		&& !is_void<_Ty>::value>
	{	
	};

	

template<class _From, class _To>
	struct is_convertible : _Cat_base<is_void<_From>::value && is_void<_To>::value || __is_convertible_to(_From, _To)>
	{	
	};

	

template<class _Ty>
	struct is_enum : _Cat_base<__is_enum(_Ty)>
	{	
	};

	
template<class _Ty>
	struct is_compound
	: _Cat_base<!is_fundamental<_Ty>::value>
	{	
	};

	
template<class _Ty>
	struct is_member_pointer
	: _Cat_base<is_member_object_pointer<_Ty>::value
		|| is_member_function_pointer<_Ty>::value>
	{	
	};

	
template<class _Ty>
	struct is_scalar
	: _Cat_base<is_arithmetic<_Ty>::value
		|| is_enum<_Ty>::value
		|| is_pointer<_Ty>::value
		|| is_member_pointer<_Ty>::value>
	{	
	};

template<class _Ty>
	struct is_scalar<_Ty&>
	: false_type
	{
	};

	
template<class _Ty>
	struct is_const
	: _Cat_base<_Ptr_traits<_Ty *>::_Is_const
		&& !is_function<_Ty>::value>
	{	
	};

template<class _Ty, unsigned int _Nx>
	struct is_const<_Ty[_Nx]>
	: false_type
	{	
	};

template<class _Ty, unsigned int _Nx>
	struct is_const<const _Ty[_Nx]>
	: true_type
	{	
	};

template<class _Ty>
	struct is_const<_Ty&>
	: false_type
	{	
	};

	
template<class _Ty>
	struct is_volatile
	: _Cat_base<_Ptr_traits<_Ty *>::_Is_volatile
		&& !is_function<_Ty>::value>
	{	
	};

template<class _Ty>
	struct is_volatile<_Ty&>
	: false_type
	{	
	};

	
template<class _Ty>
	struct _Is_pod : _Cat_base<is_void<_Ty>::value || is_scalar<_Ty>::value || __has_trivial_constructor(_Ty) && __is_pod(_Ty)>
	{	
	};

template<class _Ty>
	struct is_pod
	: _Is_pod<typename ::std:: tr1::remove_all_extents<_Ty>::type>
	{	
	};

	
template<class _Ty>
	struct is_empty : _Cat_base<__is_empty(_Ty)>
	{	
	};

	
template<class _Ty>
	struct is_polymorphic : _Cat_base<__is_polymorphic(_Ty)>
	{	
	};

	
template<class _Ty>
	struct is_abstract : _Cat_base<__is_abstract(_Ty)>
	{	
	};

 
	
template<class _Ty>
	struct is_standard_layout : is_pod<_Ty>
	{	
	};

	
template<class _Ty>
	struct is_trivial : is_pod<_Ty>
	{	
	};
 #line 679 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

	
template<class _Ty>
	struct has_trivial_constructor : _Cat_base<is_pod<_Ty>::value || __has_trivial_constructor(_Ty)>
	{	
	};

	
template<class _Ty>
	struct has_trivial_copy : _Cat_base<is_pod<_Ty>::value || __has_trivial_copy(_Ty)>
	{	
	};

 
	
template<class _Ty>
	struct has_trivial_default_constructor : _Cat_base<is_pod<_Ty>::value || __has_trivial_constructor(_Ty)>
	{	
	};

	
template<class _Ty>
	struct has_trivial_copy_constructor : _Cat_base<is_pod<_Ty>::value || __has_trivial_copy(_Ty)>
	{	
	};
 #line 705 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

	
template<class _Ty>
	struct has_trivial_assign : _Cat_base<is_pod<_Ty>::value || __has_trivial_assign(_Ty)>
	{	
	};

	
template<class _Ty>
	struct has_trivial_destructor : _Cat_base<!is_void<_Ty>::value && (is_pod<_Ty>::value || __has_trivial_destructor(_Ty))>
	{	
	};

	
template<class _Ty>
	struct has_nothrow_constructor : _Cat_base<is_pod<_Ty>::value || __has_nothrow_constructor(_Ty)>
	{	
	};

	
template<class _Ty>
	struct has_nothrow_copy : _Cat_base<is_pod<_Ty>::value || __has_nothrow_copy(_Ty)>
	{	
	};

 
	
template<class _Ty>
	struct has_nothrow_default_constructor : _Cat_base<is_pod<_Ty>::value || __has_nothrow_constructor(_Ty)>
	{	
	};

	
template<class _Ty>
	struct has_nothrow_copy_constructor : _Cat_base<is_pod<_Ty>::value || __has_nothrow_copy(_Ty)>
	{	
	};
 #line 743 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

	
template<class _Ty>
	struct has_nothrow_assign : _Cat_base<is_pod<_Ty>::value || __has_nothrow_assign(_Ty)>
	{	
	};

	
template<class _Ty>
	struct has_virtual_destructor : _Cat_base<__has_virtual_destructor(_Ty)>
	{	
	};

	
template<class _Ty>
	struct _Has_signed_vals
	: _Cat_base<(typename remove_cv<_Ty>::type)(-1)
		< (typename remove_cv<_Ty>::type)(0)>
	{	
	};

template<class _Ty>
	struct is_signed
	: _Cat_base<is_floating_point<_Ty>::value || is_integral<_Ty>::value
		&& _Has_signed_vals<
			typename _If<is_integral<_Ty>::value, _Ty, int>::_Type>::value>
	{	
	};

	
template<class _Ty>
	struct is_unsigned
	: _Cat_base<is_integral<_Ty>::value
		&& !_Has_signed_vals<
			typename _If<is_integral<_Ty>::value, _Ty, int>::_Type>::value>
	{	
	};

	
template<class _Ty>
	struct make_signed
	{	
	static const size_t _Bytes = sizeof (_Ty);

	typedef typename _If<is_signed<_Ty>::value, _Ty,
		typename _If<_Bytes <= sizeof (char), signed char,
			typename _If<_Bytes <= sizeof (short), short,
				typename _If<_Bytes <= sizeof (int), int,
					typename _If<_Bytes <= sizeof (long), long,
						_Longlong>::_Type>::_Type>::_Type>
							::_Type>::_Type type;
	};

	
template<class _Ty>
	struct make_unsigned
	{	
	static const size_t _Bytes = sizeof (_Ty);

	typedef typename _If<is_unsigned<_Ty>::value, _Ty,
		typename _If<_Bytes <= sizeof (char), unsigned char,
			typename _If<_Bytes <= sizeof (short), unsigned short,
				typename _If<_Bytes <= sizeof (int), unsigned int,
					typename _If<_Bytes <= sizeof (long), unsigned long,
						_ULonglong>::_Type>::_Type>::_Type>
							::_Type>::_Type type;
	};

	
template<class _Ty>
	struct _Get_align
	{	
	_Ty _Elt0;
	char _Elt1;
	_Ty _Elt2;
	};



template<class _Ty>
	struct alignment_of
	: integral_constant<size_t, (sizeof(_Get_align<_Ty>) - 2 * sizeof(_Ty))>
	{	
	};

template<class _Ty>
	struct alignment_of<_Ty&>
	: integral_constant<size_t, (sizeof(_Get_align<_Ty *>) - 2 * sizeof(_Ty *))>
	{	
	};

	




template<class _Ty, size_t _Len> union _Align_type
	{	
	_Ty _Val;
	char _Pad[_Len];
	};

template<size_t _Len, size_t _Align, class _Ty, bool _Ok>
	struct _Aligned;

template<size_t _Len, size_t _Align, class _Ty>
	struct _Aligned<_Len, _Align, _Ty, true>
	{	
	typedef _Align_type<_Ty, _Len> _Type;
	};

template<size_t _Len, size_t _Align>
	struct _Aligned<_Len, _Align, long, false>
	{	
	typedef _Align_type<double, _Len> _Type;
	};

template<size_t _Len, size_t _Align>
	struct _Aligned<_Len, _Align, int, false>
	{	
	typedef typename _Aligned<_Len, _Align, long, _Align == (sizeof(_Get_align<long>) - 2 * sizeof(long))>::_Type _Type;
	};

template<size_t _Len, size_t _Align>
	struct _Aligned<_Len, _Align, short, false>
	{	
	typedef typename _Aligned<_Len, _Align, int, _Align == (sizeof(_Get_align<int>) - 2 * sizeof(int))>::_Type _Type;
	};

template<size_t _Len, size_t _Align>
	struct _Aligned<_Len, _Align, char, false>
	{	
	typedef typename _Aligned<_Len, _Align, short, _Align == (sizeof(_Get_align<short>) - 2 * sizeof(short))>::_Type _Type;
	};

template<size_t _Len, size_t _Align>
	struct aligned_storage
	{	
	typedef typename _Aligned<_Len, _Align, char, _Align == (sizeof(_Get_align<char>) - 2 * sizeof(char))>::_Type type;
	};





	
template<class _Ty>
	struct rank
	: integral_constant<size_t, 0>
	{	
	};

template<class _Ty, unsigned int _Ix>
	struct rank<_Ty[_Ix]>
	: integral_constant<size_t, rank<_Ty>::value + 1>
	{	
	};

template<class _Ty>
	struct rank<_Ty[]>
	: integral_constant<size_t, rank<_Ty>::value + 1>
	{	
	};

	
template<class _Ty, unsigned int _Nx>
	struct _Extent
	: integral_constant<size_t, 0>
	{	
	};

template<class _Ty, unsigned int _Ix>
	struct _Extent<_Ty[_Ix], 0>
	: integral_constant<size_t, _Ix>
	{	
	};

template<class _Ty, unsigned int _Nx, unsigned int _Ix>
	struct _Extent<_Ty[_Ix], _Nx>
	: _Extent<_Ty, _Nx - 1>
	{	
	};

template<class _Ty, unsigned int _Nx>
	struct _Extent<_Ty[], _Nx>
	: _Extent<_Ty, _Nx - 1>
	{	
	};

template<class _Ty, unsigned int _Nx = 0>
	struct extent
	: _Extent<_Ty, _Nx>
	{	
	};

	
template<class _Ty1, class _Ty2>
	struct is_same
	: false_type
	{	
	};

template<class _Ty1>
	struct is_same<_Ty1, _Ty1>
	: true_type
	{	
	};

	
template<class _Base, class _Der>
	struct is_base_of : _Cat_base<__is_base_of(_Base, _Der)>
	{	
	};


	
template<class _Ty>
	struct decay
	{	
	typedef typename remove_reference<_Ty>::type _Ty1;

	typedef typename _If<is_array<_Ty1>::value,
		typename remove_extent<_Ty1>::type *,
		typename _If<is_function<_Ty1>::value,
			typename add_pointer<_Ty1>::type,
			typename remove_cv<_Ty1>::type>::_Type>::_Type type;
	};

	
template<bool _Test,
	class _Type = void>
	struct enable_if
	{	
	};

template<class _Type>
	struct enable_if<true, _Type>
	{	
	typedef _Type type;
	};

	
template<bool _Test,
	class _Ty1,
	class _Ty2>
	struct conditional
	{	
	typedef _Ty2 type;
	};

template<class _Ty1,
	class _Ty2>
	struct conditional<true, _Ty1, _Ty2>
	{	
	typedef _Ty1 type;
	};

	}	

 
using tr1::add_const;
using tr1::add_cv;
using tr1::add_pointer;
using tr1::add_lvalue_reference;
using tr1::add_reference;	
using tr1::add_rvalue_reference;
using tr1::add_volatile;
using tr1::aligned_storage;
using tr1::alignment_of;
using tr1::conditional;
using tr1::decay;
using tr1::enable_if;
using tr1::extent;
using tr1::false_type;
using tr1::has_nothrow_assign;
using tr1::has_nothrow_constructor;	
using tr1::has_nothrow_copy;	
using tr1::has_nothrow_copy_constructor;
using tr1::has_nothrow_default_constructor;
using tr1::has_trivial_assign;
using tr1::has_trivial_constructor;	
using tr1::has_trivial_copy;	
using tr1::has_trivial_copy_constructor;
using tr1::has_trivial_default_constructor;
using tr1::has_trivial_destructor;
using tr1::has_virtual_destructor;
using tr1::integral_constant;
using tr1::is_abstract;
using tr1::is_arithmetic;
using tr1::is_array;
using tr1::is_base_of;
using tr1::is_class;
using tr1::is_compound;
using tr1::is_const;
using tr1::is_convertible;
using tr1::is_empty;
using tr1::is_enum;
using tr1::is_floating_point;
using tr1::is_function;
using tr1::is_fundamental;
using tr1::is_integral;
using tr1::is_lvalue_reference;
using tr1::is_member_function_pointer;
using tr1::is_member_object_pointer;
using tr1::is_member_pointer;
using tr1::is_object;
using tr1::is_pod;
using tr1::is_pointer;
using tr1::is_polymorphic;
using tr1::is_reference;
using tr1::is_rvalue_reference;
using tr1::is_same;
using tr1::is_scalar;
using tr1::is_signed;
using tr1::is_standard_layout;
using tr1::is_trivial;
using tr1::is_union;
using tr1::is_unsigned;
using tr1::is_void;
using tr1::is_volatile;
using tr1::make_signed;
using tr1::make_unsigned;
using tr1::rank;
using tr1::remove_all_extents;
using tr1::remove_const;
using tr1::remove_cv;
using tr1::remove_extent;
using tr1::remove_pointer;
using tr1::remove_reference;
using tr1::_Remove_rvalue_reference;
using tr1::remove_volatile;
using tr1::true_type;
 #line 1076 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"

 

template<class _Ty>
	struct _Arithmetic_traits;

template<>
	struct _Arithmetic_traits<bool>
	{	
	static const int _Rank = 1;
	};

template<>
	struct _Arithmetic_traits<char>
	{	
	static const int _Rank = _Arithmetic_traits<bool>::_Rank + 1;
	};

template<>
	struct _Arithmetic_traits<signed char>
	{	
	static const int _Rank = _Arithmetic_traits<char>::_Rank;
	};

template<>
	struct _Arithmetic_traits<unsigned char>
	{	
	static const int _Rank = _Arithmetic_traits<char>::_Rank;
	};

template<>
	struct _Arithmetic_traits<short>
	{	
	static const int _Rank = _Arithmetic_traits<char>::_Rank + 1;
	};

template<>
	struct _Arithmetic_traits<unsigned short>
	{	
	static const int _Rank = _Arithmetic_traits<short>::_Rank;
	};

template<>
	struct _Arithmetic_traits<int>
	{	
	static const int _Rank = _Arithmetic_traits<short>::_Rank + 1;
	};

template<>
	struct _Arithmetic_traits<unsigned int>
	{	
	static const int _Rank = _Arithmetic_traits<int>::_Rank;
	};

template<>
	struct _Arithmetic_traits<long>
	{	
	static const int _Rank = _Arithmetic_traits<int>::_Rank + 1;
	};

template<>
	struct _Arithmetic_traits<unsigned long>
	{	
	static const int _Rank = _Arithmetic_traits<long>::_Rank;
	};

template<>
	struct _Arithmetic_traits<long long>
	{	
	static const int _Rank = _Arithmetic_traits<long>::_Rank + 1;
	};

template<>
	struct _Arithmetic_traits<unsigned long long>
	{	
	static const int _Rank = _Arithmetic_traits<long long>::_Rank;
	};

template<>
	struct _Arithmetic_traits<float>
	{
	static const int _Rank = _Arithmetic_traits<long long>::_Rank + 1;
	};

template<>
	struct _Arithmetic_traits<double>
	{
	static const int _Rank = _Arithmetic_traits<float>::_Rank + 1;
	};

template<>
	struct _Arithmetic_traits<long double>
	{
	static const int _Rank = _Arithmetic_traits<double>::_Rank + 1;
	};

template<bool _Unsigned> struct _Pickinteger
	{	
	typedef int _Type;
	};

template<>
	struct _Pickinteger<true>
	{	
	typedef unsigned int _Type;
	};

template<class _Ty,
	bool _Small>
	struct _Promote_to_int;

template<class _Ty>
	struct _Promote_to_int<_Ty, true>
	{	
	typedef int _Type;
	};

template<class _Ty>
	struct _Promote_to_int<_Ty, false>
	{	
	typedef typename _Pickinteger<tr1::is_unsigned<_Ty>::value>::_Type _Type;
	};

template<class _Ty,
	bool _Small>
	struct _Maybepromote;

template<class _Ty>
	struct _Maybepromote<_Ty, false>
	{	
	typedef _Ty _Type;
	};

template<class _Ty>
	struct _Maybepromote<_Ty, true>
	{	
	typedef typename _Promote_to_int<_Ty, sizeof(_Ty) < sizeof(int)>::_Type
		_Type;
	};

template<class _Ty>
	struct _Ipromo
	{	
	static const bool _Lessthan =
		_Arithmetic_traits<_Ty>::_Rank < _Arithmetic_traits<int>::_Rank;
	typedef typename _Maybepromote<_Ty, _Lessthan>::_Type _Type;
	};

template<class _Ty0,
	class _Ty1,
	bool _Second>
	struct _Common_typeX
	{	
	typedef _Ty1 _Type;
	};

template<class _Ty0,
	class _Ty1>
	struct _Common_typeX<_Ty0, _Ty1, false>
	{	
	typedef _Ty0 _Type;
	};

template<class _Ty0,
	class _Ty1,
	bool _Uns0,
	bool _Uns1>
	struct _Common_typeY
	{	
	typedef _Ty0 _Type;
	};

template<class _Ty0,
	class _Ty1>
	struct _Common_typeY<_Ty0, _Ty1, false, true>
	{	
	typedef _Ty1 _Type;
	};

template<class _Ty0,
	class _Ty1,
	int _Rank0,
	int _Rank1>
	struct _Common_type
	{	
	typedef typename _Common_typeX<_Ty0, _Ty1, _Rank0 < _Rank1>::_Type _Type;
	};

template<class _Ty0,
	class _Ty1,
	int _Rank>
	struct _Common_type<_Ty0, _Ty1, _Rank, _Rank>
	{	
	typedef typename _Common_typeY<_Ty0, _Ty1,
		tr1::is_unsigned<_Ty0>::value,
		tr1::is_unsigned<_Ty1>::value>::_Type _Type;
	};

template<class _Ty0,
	class _Ty1>
	struct common_type
	{	
	typedef typename _Ipromo<_Ty0>::_Type _PromoTy0;
	typedef typename _Ipromo<_Ty1>::_Type _PromoTy1;
	typedef typename _Common_type<_PromoTy0, _PromoTy1,
		_Arithmetic_traits<_PromoTy0>::_Rank,
		_Arithmetic_traits<_PromoTy1>::_Rank>::_Type type;
	};

 #line 1286 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"
}
 #pragma warning(pop)
 #pragma pack(pop)

#line 1291 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"
#line 1292 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\type_traits"






#line 10 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"

 #pragma pack(push,8)
 #pragma warning(push,3)

 #pragma warning(disable: 4180 4512)

namespace std {
	namespace tr1 {
	
template<class _Type>
	class reference_wrapper;

 
template<class _Type>
	struct _Unrefwrap
	{	
	typedef typename decay<_Type>::type type;
	};

template<class _Type>
	struct _Unrefwrap<reference_wrapper<_Type> >
	{	
	typedef _Type& type;
	};

template<class _Type>
	struct _Unrefwrap<const reference_wrapper<_Type> >
	{	
	typedef _Type& type;
	};

template<class _Type>
	struct _Unrefwrap<volatile reference_wrapper<_Type> >
	{	
	typedef _Type& type;
	};

template<class _Type>
	struct _Unrefwrap<const volatile reference_wrapper<_Type> >
	{	
	typedef _Type& type;
	};

 





#line 60 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"
	}	
using tr1::_Unrefwrap;

	
template<class _Ty>
	struct identity
	{	
	typedef _Ty type;

	const _Ty& operator()(const _Ty& _Left) const
		{	
		return (_Left);
		}
	};

	
template<class _Ty> inline
	_Ty&& forward(typename identity<_Ty>::type& _Arg)
	{	
	return ((_Ty&&)_Arg);
	}

	
template<class _Ty> inline
	typename tr1::_Remove_reference<_Ty>::_Type&&
		move(_Ty&& _Arg)
	{	
	return ((typename tr1::_Remove_reference<_Ty>::_Type&&)_Arg);
	}

	
template<class _Ty> inline
	typename tr1::_Remove_reference<_Ty>::_Type&&
		_Move(_Ty&& _Arg)
	{	
	return ((typename tr1::_Remove_reference<_Ty>::_Type&&)_Arg);
	}

		
template<class _Ty> inline
	void swap(_Ty& _Left, _Ty& _Right)
	{	
	_Ty _Tmp = _Move(_Left);
	_Left = _Move(_Right);
	_Right = _Move(_Tmp);
	}

		
template<class _Ty> inline
	void _Swap_adl(_Ty& _Left, _Ty& _Right)
	{	
	swap(_Left, _Right);
	}

		

template<class _Ty1,
	class _Ty2>
	struct _Pair_base
	{	
	typedef _Pair_base<_Ty1, _Ty2> _Myt;
	typedef _Ty1 first_type;
	typedef _Ty2 second_type;

	_Pair_base()
		: first(_Ty1()), second(_Ty2())
		{	
		}

	_Pair_base(const _Pair_base<_Ty1, _Ty2>& _Right)
		: first(_Right.first), second(_Right.second)
		{	
		}

	_Pair_base(const _Ty1& _Val1, const _Ty2& _Val2)
		: first(_Val1), second(_Val2)
		{	
		}

	typedef typename tr1::remove_reference<_Ty1>::type _Ty1x;
	typedef typename tr1::remove_reference<_Ty2>::type _Ty2x;

	_Pair_base(_Ty1x&& _Val1, _Ty2x&& _Val2)
		: first(::std:: move(_Val1)),
			second(::std:: move(_Val2))
		{	
		}

	_Pair_base(const _Ty1x& _Val1, _Ty2x&& _Val2)
		: first(_Val1), second(::std:: move(_Val2))
		{	
		}

	_Pair_base(_Ty1x&& _Val1, const _Ty2x& _Val2)
		: first(::std:: move(_Val1)), second(_Val2)
		{	
		}

	template<class _Other1,
		class _Other2>
		_Pair_base(_Other1&& _Val1, _Other2&& _Val2)
		: first(::std:: forward<_Other1>(_Val1)),
			second(::std:: forward<_Other2>(_Val2))
		{	
		}

	_Ty1 first;	
	_Ty2 second;	
	};

template<class _Ty1,
	class _Ty2>
	struct pair
		: public _Pair_base<_Ty1, _Ty2>
	{	
	typedef _Pair_base<_Ty1, _Ty2> _Mybase;

	typedef pair<_Ty1, _Ty2> _Myt;
	typedef _Ty1 first_type;
	typedef _Ty2 second_type;

	pair()
		: _Mybase()
		{	
		}

	pair(const _Ty1& _Val1, const _Ty2& _Val2)
		: _Mybase(_Val1, _Val2)
		{	
		}

	template<class _Other1,
		class _Other2>
		pair(pair<_Other1, _Other2>& _Right)
		: _Mybase(_Right.first, _Right.second)
		{	
		}

	template<class _Other1,
		class _Other2>
		pair(const pair<_Other1, _Other2>& _Right)
		: _Mybase(_Right.first, _Right.second)
		{	
		}

	void swap(_Myt& _Right)
		{	
		if (this != &_Right)
			{	
			_Swap_adl(this->first, _Right.first);
			_Swap_adl(this->second, _Right.second);
			}
		}

	_Myt& operator=(const _Myt& _Right)
		{	
		this->first = _Right.first;
		this->second = _Right.second;
		return (*this);
		}

	typedef typename tr1::remove_reference<_Ty1>::type _Ty1x;
	typedef typename tr1::remove_reference<_Ty2>::type _Ty2x;

	pair(_Ty1x&& _Val1, _Ty2x&& _Val2)
		: _Mybase(::std:: move(_Val1),
			::std:: move(_Val2))
		{	
		}

	pair(const _Ty1x& _Val1, _Ty2x&& _Val2)
		: _Mybase(_Val1,
			::std:: move(_Val2))
		{	
		}

	pair(_Ty1x&& _Val1, const _Ty2x& _Val2)
		: _Mybase(::std:: move(_Val1),
			_Val2)
		{	
		}

	template<class _Other1,
		class _Other2>
		pair(_Other1&& _Val1, _Other2&& _Val2)
		: _Mybase(::std:: forward<_Other1>(_Val1),
			::std:: forward<_Other2>(_Val2))
		{	
		}

	template<class _Other1,
		class _Other2>
		pair(pair<_Other1, _Other2>&& _Right)
		: _Mybase(::std:: forward<_Other1>(_Right.first),
			::std:: forward<_Other2>(_Right.second))
		{	
		}

	pair& operator=(pair<_Ty1, _Ty2>&& _Right)
		{	
		this->first = ::std:: move(_Right.first);
		this->second = ::std:: move(_Right.second);
		return (*this);
		}

	void swap(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
			this->first = ::std:: move(_Right.first);
			this->second = ::std:: move(_Right.second);
			}
		}
	};

		

template<class _Ty1,
	class _Ty2> inline
	void swap(pair<_Ty1, _Ty2>& _Left, pair<_Ty1, _Ty2>& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Ty1,
	class _Ty2> inline
	void swap(pair<_Ty1, _Ty2>& _Left, pair<_Ty1, _Ty2>&& _Right)
	{	
	typedef pair<_Ty1, _Ty2> _Myt;
	_Left.swap(::std:: forward<_Myt>(_Right));
	}

template<class _Ty1,
	class _Ty2> inline
	void swap(pair<_Ty1, _Ty2>&& _Left, pair<_Ty1, _Ty2>& _Right)
	{	
	typedef pair<_Ty1, _Ty2> _Myt;
	_Right.swap(::std:: forward<_Myt>(_Left));
	}

template<class _Ty1,
	class _Ty2> inline
	bool operator==(const pair<_Ty1, _Ty2>& _Left,
		const pair<_Ty1, _Ty2>& _Right)
	{	
	return (_Left.first == _Right.first && _Left.second == _Right.second);
	}

template<class _Ty1,
	class _Ty2> inline
	bool operator!=(const pair<_Ty1, _Ty2>& _Left,
		const pair<_Ty1, _Ty2>& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _Ty1,
	class _Ty2> inline
	bool operator<(const pair<_Ty1, _Ty2>& _Left,
		const pair<_Ty1, _Ty2>& _Right)
	{	
	return (_Left.first < _Right.first ||
		!(_Right.first < _Left.first) && _Left.second < _Right.second);
	}

template<class _Ty1,
	class _Ty2> inline
	bool operator>(const pair<_Ty1, _Ty2>& _Left,
		const pair<_Ty1, _Ty2>& _Right)
	{	
	return (_Right < _Left);
	}

template<class _Ty1,
	class _Ty2> inline
	bool operator<=(const pair<_Ty1, _Ty2>& _Left,
		const pair<_Ty1, _Ty2>& _Right)
	{	
	return (!(_Right < _Left));
	}

template<class _Ty1,
	class _Ty2> inline
	bool operator>=(const pair<_Ty1, _Ty2>& _Left,
		const pair<_Ty1, _Ty2>& _Right)
	{	
	return (!(_Left < _Right));
	}

	

template<class _Ty1,
	class _Ty2> inline
	pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type>
		make_pair(_Ty1&& _Val1, _Ty2&& _Val2)
	{	
	typedef pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type> _Mypair;
	return (_Mypair(::std:: forward<_Ty1>(_Val1),
		::std:: forward<_Ty2>(_Val2)));
	}

template<class _Ty1,
	class _Ty2> inline
	pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type>
		make_pair(const _Ty1& _Val1, _Ty2&& _Val2)
	{	
	typedef pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type> _Mypair;
	return (_Mypair((typename _Unrefwrap<_Ty1>::type)_Val1,
		::std:: forward<_Ty2>(_Val2)));
	}

template<class _Ty1,
	class _Ty2> inline
	pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type>
		make_pair(_Ty1&& _Val1, const _Ty2& _Val2)
	{	
	typedef pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type> _Mypair;
	return (_Mypair(::std:: forward<_Ty1>(_Val1),
		(typename _Unrefwrap<_Ty2>::type)_Val2));
	}

template<class _Ty1,
	class _Ty2> inline
	pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type>
		make_pair(const _Ty1& _Val1, const _Ty2& _Val2)
	{	
	typedef pair<typename _Unrefwrap<_Ty1>::type,
		typename _Unrefwrap<_Ty2>::type> _Mypair;
	return (_Mypair((typename _Unrefwrap<_Ty1>::type)_Val1,
		(typename _Unrefwrap<_Ty2>::type)_Val2));
	}

 
template<class _InIt> inline
	_InIt begin(const pair<_InIt, _InIt>& _Pair)
	{	
	return (_Pair.first);
	}

template<class _InIt> inline
	_InIt end(const pair<_InIt, _InIt>& _Pair)
	{	
	return (_Pair.second);
	}
 #line 412 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"

		
	namespace rel_ops
		{	
template<class _Ty> inline
	bool operator!=(const _Ty& _Left, const _Ty& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _Ty> inline
	bool operator>(const _Ty& _Left, const _Ty& _Right)
	{	
	return (_Right < _Left);
	}

template<class _Ty> inline
	bool operator<=(const _Ty& _Left, const _Ty& _Right)
	{	
	return (!(_Right < _Left));
	}

template<class _Ty> inline
	bool operator>=(const _Ty& _Left, const _Ty& _Right)
	{	
	return (!(_Left < _Right));
	}
		}
}

 
namespace std {
	namespace tr1 {	
	
template<class _Tuple>
	struct tuple_size;
template<size_t _Idx,
	class _Tuple>
	struct tuple_element;
template<class _Ty1,
	class _Ty2>
	struct tuple_size<::std:: pair<_Ty1, _Ty2> >
	{	
	static const int value = 2;
	};

template<int _Idx,
	class _Ty>
	struct _Pair_data;
template<class _Ty1,
	class _Ty2>
	struct _Pair_data<0, ::std:: pair<_Ty1, _Ty2> >
	{	
	typedef _Ty1& _Type;
	typedef const _Ty1& _CType;

	static _Type _Val(::std:: pair<_Ty1, _Ty2>& _Pr)
		{	
		return (_Pr.first);
		}

	static _CType _Val(const ::std:: pair<_Ty1, _Ty2>& _Pr)
		{	
		return (_Pr.first);
		}
	};

template<class _Ty1,
	class _Ty2>
	struct _Pair_data<1, ::std:: pair<_Ty1, _Ty2> >
	{	
	typedef _Ty2& _Type;
	typedef const _Ty2& _CType;

	static _Type _Val(::std:: pair<_Ty1, _Ty2>& _Pr)
		{	
		return (_Pr.second);
		}

	static _CType _Val(const ::std:: pair<_Ty1, _Ty2>& _Pr)
		{	
		return (_Pr.second);
		}
	};

template<class _Ty1,
	class _Ty2>
	struct tuple_element<0, ::std:: pair<_Ty1, _Ty2> >
	{	
	typedef _Ty1 type;
	};

template<class _Ty1,
	class _Ty2>
	struct tuple_element<1, ::std:: pair<_Ty1, _Ty2> >
	{	
	typedef _Ty2 type;
	};

template<int _Idx,
	class _Ty1,
	class _Ty2>
	typename _Pair_data<_Idx, ::std:: pair<_Ty1, _Ty2> >::_Type
		get(::std:: pair<_Ty1, _Ty2>& _Pr)
	{	
	return (_Pair_data<_Idx, ::std:: pair<_Ty1, _Ty2> >::_Val(_Pr));
	}

template<int _Idx,
	class _Ty1,
	class _Ty2>
	typename _Pair_data<_Idx, ::std:: pair<_Ty1, _Ty2> >::_CType
		get(const ::std:: pair<_Ty1, _Ty2>& _Pr)
	{	
	return (_Pair_data<_Idx, ::std:: pair<_Ty1, _Ty2> >::_Val(_Pr));
	}
	}	
}
 #line 531 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"

 
namespace std {
using tr1::get;
using tr1::tuple_element;
using tr1::tuple_size;
}
 #line 539 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"

 #pragma warning(pop)
 #pragma pack(pop)

#line 544 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"
#line 545 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"






















#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

 #pragma pack(push,8)
 #pragma warning(push,3)

namespace std {
		

 












#line 30 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
  
 #line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
struct  _Container_base0
	{	
	void _Orphan_all()
		{	
		}

	void _Swap_all(_Container_base0&)
		{	
		}
	};

struct _Iterator_base0
	{	
	void _Adopt(const void *)
		{	
		}

	const _Container_base0 *_Getcont() const
		{	
		return (0);
		}
	};

struct _Container_base12;
struct _Iterator_base12;

		
struct _Container_proxy
	{	
	_Container_proxy()
		: _Mycont(0), _Myfirstiter(0)
		{	
		}

	const _Container_base12 *_Mycont;
	_Iterator_base12 *_Myfirstiter;
	};

struct  _Container_base12
	{	
public:
	_Container_base12()
		: _Myproxy(0)
		{	
		}

	_Container_base12(const _Container_base12&)
		: _Myproxy(0)
		{	
		}

	_Container_base12& operator=(const _Container_base12&)
		{	
		return (*this);
		}

	~_Container_base12()
		{	
		_Orphan_all();
		}

	_Iterator_base12 **_Getpfirst() const
		{	
		return (_Myproxy == 0 ? 0 : &_Myproxy->_Myfirstiter);
		}

	void _Orphan_all();	
	void _Swap_all(_Container_base12&);	

	_Container_proxy *_Myproxy;
	};

struct _Iterator_base12
	{	
public:
	_Iterator_base12()
		: _Myproxy(0), _Mynextiter(0)
		{	
		}

	_Iterator_base12(const _Iterator_base12& _Right)
		: _Myproxy(0), _Mynextiter(0)
		{	
		*this = _Right;
		}

	_Iterator_base12& operator=(const _Iterator_base12& _Right)
		{	
		if (_Myproxy != _Right._Myproxy)
			_Adopt(_Right._Myproxy->_Mycont);
		return (*this);
		}

	~_Iterator_base12()
		{	
 


#line 133 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
		}

	void _Adopt(const _Container_base12 *_Parent)
		{	
		if (_Parent != 0)
			{	
			_Container_proxy *_Parent_proxy = _Parent->_Myproxy;

 








#line 151 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
			_Myproxy = _Parent_proxy;
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
			}
		}

	void _Clrcont()
		{	
		_Myproxy = 0;
		}

	const _Container_base12 *_Getcont() const
		{	
		return (_Myproxy == 0 ? 0 : _Myproxy->_Mycont);
		}

	_Iterator_base12 **_Getpnext()
		{	
		return (&_Mynextiter);
		}

	void _Orphan_me()
		{	
 











#line 186 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
		}

	_Container_proxy *_Myproxy;
	_Iterator_base12 *_Mynextiter;
	};

		
inline void _Container_base12::_Orphan_all()
	{	
 









#line 206 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
	}

inline void _Container_base12::_Swap_all(_Container_base12& _Right)
	{	
 

#line 213 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

	_Container_proxy *_Temp = _Myproxy;
	_Myproxy = _Right._Myproxy;
	_Right._Myproxy = _Temp;

	if (_Myproxy != 0)
		_Myproxy->_Mycont = (_Container_base12 *)this;
	if (_Right._Myproxy != 0)
		_Right._Myproxy->_Mycont = (_Container_base12 *)&_Right;
	}

 
typedef _Container_base0 _Container_base;
typedef _Iterator_base0 _Iterator_base;
 


#line 231 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		

 


::std:: tr1::_No _Has_unchecked_type(...);

template<class _Ty>
	::std:: tr1::_Yes _Has_unchecked_type(_Ty *,
		typename _Ty::_Unchecked_type * = 0);

template<class _Iter,
	bool>
	struct _Unchecked_helper
	{	
	typedef _Iter type;
	};

template<class _Iter>
	struct _Unchecked_helper<_Iter, true>
	{	
	typedef typename _Iter::_Unchecked_type type;
	};

template<class _Iter>
	struct _Get_unchecked_type
	{	
	typedef typename _Unchecked_helper<_Iter,
		(sizeof (_Has_unchecked_type((_Iter *)0)) == sizeof (::std:: tr1::_Yes))>::type type;
	};

		
template<class _Iter> inline
	_Iter _Unchecked(_Iter _Src)
	{	
	return (_Src);
	}

		
template<class _Iter,
	class _UIter> inline
	_Iter& _Rechecked(_Iter& _Dest, _UIter _Src)
	{	
	_Dest = _Src;
	return (_Dest);
	}

		
template<class _Iter>
	struct _Is_checked_helper
	: public ::std:: tr1::integral_constant<bool, (sizeof (_Has_unchecked_type((_Iter *)0)) == sizeof (::std:: tr1::_Yes))>
	{	
	};

		
template<class _Iter> inline
	_Is_checked_helper<_Iter> _Is_checked(_Iter)
	{	
	return (_Is_checked_helper<_Iter>());
	}

		
		
struct input_iterator_tag
	{	
	};

struct output_iterator_tag
	{	
	};

struct forward_iterator_tag
	: public input_iterator_tag, output_iterator_tag
	{	
	};

struct bidirectional_iterator_tag
	: public forward_iterator_tag
	{	
	};

struct random_access_iterator_tag
	: public bidirectional_iterator_tag
	{	
	};

struct _Int_iterator_tag
	{	
	};

		
struct _Nonscalar_ptr_iterator_tag
	{	
	};
struct _Scalar_ptr_iterator_tag
	{	
	};

		
template<class _Category,
	class _Ty,
	class _Diff = ptrdiff_t,
	class _Pointer = _Ty *,
	class _Reference = _Ty&>
	struct iterator
	{	
	typedef _Category iterator_category;
	typedef _Ty value_type;
	typedef _Diff difference_type;
	typedef _Diff distance_type;	
	typedef _Pointer pointer;
	typedef _Reference reference;
	};

template<class _Category,
	class _Ty,
	class _Diff,
	class _Pointer,
	class _Reference,
	class _Base>
	struct _Iterator012
		: public _Base
	{
	typedef _Category iterator_category;
	typedef _Ty value_type;
	typedef _Diff difference_type;
	typedef _Diff distance_type;	
	typedef _Pointer pointer;
	typedef _Reference reference;
	};

struct _Outit
	: public iterator<output_iterator_tag, void, void,
		void, void>
	{	
	};

		
template<class _Iter>
	struct iterator_traits
	{	
	typedef typename _Iter::iterator_category iterator_category;
	typedef typename _Iter::value_type value_type;
	typedef typename _Iter::difference_type difference_type;
	typedef difference_type distance_type;	
	typedef typename _Iter::pointer pointer;
	typedef typename _Iter::reference reference;
	};

template<class _Ty>
	struct iterator_traits<_Ty *>
	{	
	typedef random_access_iterator_tag iterator_category;
	typedef _Ty value_type;
	typedef ptrdiff_t difference_type;
	typedef ptrdiff_t distance_type;	
	typedef _Ty *pointer;
	typedef _Ty& reference;
	};

template<class _Ty>
	struct iterator_traits<const _Ty *>
	{	
	typedef random_access_iterator_tag iterator_category;
	typedef _Ty value_type;
	typedef ptrdiff_t difference_type;
	typedef ptrdiff_t distance_type;	
	typedef const _Ty *pointer;
	typedef const _Ty& reference;
	};

template<> struct iterator_traits<_Bool>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<char>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<signed char>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<unsigned char>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

 
template<> struct iterator_traits<wchar_t>
	{	
	typedef _Int_iterator_tag iterator_category;
	};
 #line 429 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

template<> struct iterator_traits<short>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<unsigned short>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<int>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<unsigned int>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<long>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<unsigned long>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

 
template<> struct iterator_traits<__int64>
	{	
	typedef _Int_iterator_tag iterator_category;
	};

template<> struct iterator_traits<unsigned __int64>
	{	
	typedef _Int_iterator_tag iterator_category;
	};
 #line 471 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _Iter> inline
	typename iterator_traits<_Iter>::iterator_category
		_Iter_cat(const _Iter&)
	{	
	typename iterator_traits<_Iter>::iterator_category _Cat;
	return (_Cat);
	}

		
template<class _Iter1,
	class _Iter2> inline
	_Nonscalar_ptr_iterator_tag _Ptr_cat(_Iter1&, _Iter2&)
	{	
	_Nonscalar_ptr_iterator_tag _Cat;
	return (_Cat);
	}

template<class _Elem1,
	class _Elem2>
	struct _Ptr_cat_helper
	{	
	typedef _Nonscalar_ptr_iterator_tag _Type;
	};

template<class _Elem>
	struct _Ptr_cat_helper<_Elem, _Elem>
	{	
	typedef typename ::std:: tr1::conditional<
		::std:: tr1::is_scalar<_Elem>::value,
			_Scalar_ptr_iterator_tag,
			_Nonscalar_ptr_iterator_tag>::type _Type;
	};

template<class _Anything>
	struct _Ptr_cat_helper<_Anything *, const _Anything *>
	{	
	typedef _Scalar_ptr_iterator_tag _Type;
	};

template<class _Elem1,
	class _Elem2> inline
	typename _Ptr_cat_helper<_Elem1, _Elem2>::_Type
		_Ptr_cat(_Elem1 *, _Elem2 *)
	{	
	typename _Ptr_cat_helper<_Elem1, _Elem2>::_Type _Cat;
	return (_Cat);
	}

template<class _Elem1,
	class _Elem2> inline
	typename _Ptr_cat_helper<_Elem1, _Elem2>::_Type
		_Ptr_cat(const _Elem1 *, _Elem2 *)
	{	
	typename _Ptr_cat_helper<_Elem1, _Elem2>::_Type _Cat;
	return (_Cat);
	}

		

 
  
  
  
  
  
  
  
  

 















































































































































































































































#line 783 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
		

template<class _Iter> inline
	typename iterator_traits<_Iter>::value_type *_Val_type(_Iter)
	{	
	return (0);
	}

		
template<class _InIt,
	class _Diff> inline
	void advance(_InIt& _Where, _Diff _Off)
	{	
	_Advance(_Where, _Off, _Iter_cat(_Where));
	}

template<class _InIt,
	class _Diff> inline
	void _Advance(_InIt& _Where, _Diff _Off, input_iterator_tag)
	{	
 


#line 809 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

	for (; 0 < _Off; --_Off)
		++_Where;
	}

template<class _FI,
	class _Diff> inline
	void _Advance(_FI& _Where, _Diff _Off, forward_iterator_tag)
	{	
 


#line 822 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

	for (; 0 < _Off; --_Off)
		++_Where;
	}

template<class _BI,
	class _Diff> inline
	void _Advance(_BI& _Where, _Diff _Off, bidirectional_iterator_tag)
	{	
	for (; 0 < _Off; --_Off)
		++_Where;
	for (; _Off < 0; ++_Off)
		--_Where;
	}

template<class _RI,
	class _Diff> inline
	void _Advance(_RI& _Where, _Diff _Off, random_access_iterator_tag)
	{	
	_Where += _Off;
	}

		

template<class _Iter> inline
	typename iterator_traits<_Iter>::difference_type
		*_Dist_type(_Iter)
	{	
	return (0);
	}

		
template<class _InIt,
	class _Diff> inline
		void _Distance2(_InIt _First, _InIt _Last, _Diff& _Off,
			input_iterator_tag)
	{	
	for (; _First != _Last; ++_First)
		++_Off;
	}

template<class _FwdIt,
	class _Diff> inline
		void _Distance2(_FwdIt _First, _FwdIt _Last, _Diff& _Off,
			forward_iterator_tag)
	{	
	for (; _First != _Last; ++_First)
		++_Off;
	}

template<class _BidIt,
	class _Diff> inline
		void _Distance2(_BidIt _First, _BidIt _Last, _Diff& _Off,
			bidirectional_iterator_tag)
	{	
	for (; _First != _Last; ++_First)
		++_Off;
	}

template<class _RanIt,
	class _Diff> inline
		void _Distance2(_RanIt _First, _RanIt _Last, _Diff& _Off,
			random_access_iterator_tag)
	{	
 





#line 893 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

	_Off += _Last - _First;
	}

template<class _InIt> inline
	typename iterator_traits<_InIt>::difference_type
		distance(_InIt _First, _InIt _Last)
	{	
	typename iterator_traits<_InIt>::difference_type _Off = 0;
	_Distance2(_First, _Last, _Off, _Iter_cat(_First));
	return (_Off);
	}

template<class _InIt,
	class _Diff> inline
		void _Distance(_InIt _First, _InIt _Last, _Diff& _Off)
	{	
	_Distance2(_First, _Last, _Off, _Iter_cat(_First));
	}

 
		
template<class _InIt,
	class _Diff> inline
		_InIt _Increment(_InIt _First, _Diff _Off,
			input_iterator_tag)
	{	
	for (; 0 < _Off; --_Off)
		++_First;
	return (_First);
	}

template<class _FwdIt,
	class _Diff> inline
		_FwdIt _Increment(_FwdIt _First, _Diff _Off,
			forward_iterator_tag)
	{	
	for (; 0 < _Off; --_Off)
		++_First;
	return (_First);
	}

template<class _BidIt,
	class _Diff> inline
		_BidIt _Increment(_BidIt _First, _Diff _Off,
			bidirectional_iterator_tag)
	{	
	for (; _Off < 0; ++_Off)
		--_First;
	for (; 0 < _Off; --_Off)
		++_First;
	return (_First);
	}

template<class _RanIt,
	class _Diff> inline
		_RanIt _Increment(_RanIt _First, _Diff _Off,
			random_access_iterator_tag)
	{	
	return (_First + _Off);
	}

template<class _InIt> inline
	_InIt next(_InIt _First,
		typename iterator_traits<_InIt>::difference_type _Off = 1)
	{	
	return (_Increment(_First, _Off, _Iter_cat(_First)));
	}

template<class _InIt> inline
	_InIt prev(_InIt _First,
		typename iterator_traits<_InIt>::difference_type _Off = 1)
	{	
	return (_Increment(_First, -_Off, _Iter_cat(_First)));
	}

template<class _Container> inline
	typename _Container::iterator begin(_Container& _Cont)
	{	
	return (_Cont.begin());
	}

template<class _Container> inline
	typename _Container::const_iterator begin(const _Container& _Cont)
	{	
	return (_Cont.begin());
	}

template<class _Container> inline
	typename _Container::iterator end(_Container& _Cont)
	{	
	return (_Cont.end());
	}

template<class _Container> inline
	typename _Container::const_iterator end(const _Container& _Cont)
	{	
	return (_Cont.end());
	}

template<class _Ty,
	size_t _Size> inline
	_Ty *begin(_Ty (&_Array)[_Size])
	{	
	return (&_Array[0]);
	}

template<class _Ty,
	size_t _Size> inline
	_Ty *end(_Ty (&_Array)[_Size])
	{	
	return (&_Array[0] + _Size);
	}
 #line 1007 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _RanIt,
	class _Base>
	class _Revranit
		: public _Base
	{	
public:
	typedef _Revranit<_RanIt, _Base> _Myt;
 	typedef typename _Base::difference_type difference_type;
	typedef typename _Base::pointer pointer;
	typedef typename _Base::reference reference;
	typedef _RanIt iterator_type;

	_Revranit()
		{	
		}

	explicit _Revranit(_RanIt _Right)
		: current(_Right)
		{	
		}

	template<class _RanIt2,
		class _Base2>
		_Revranit(const _Revranit<_RanIt2, _Base2>& _Right)
		: current(_Right.base())
		{	
		}

	_RanIt base() const
		{	
		return (current);
		}

	reference operator*() const
		{	
		_RanIt _Tmp = current;
		return (*--_Tmp);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myt& operator++()
		{	
		--current;
		return (*this);
		}

	_Myt operator++(int)
		{	
		_Myt _Tmp = *this;
		--current;
		return (_Tmp);
		}

	_Myt& operator--()
		{	
		++current;
		return (*this);
		}

	_Myt operator--(int)
		{	
		_Myt _Tmp = *this;
		++current;
		return (_Tmp);
		}

	template<class _RanIt2,
		class _Base2>
		bool _Equal(const _Revranit<_RanIt2, _Base2>& _Right) const
		{	
		return (current == _Right.base());
		}



	_Myt& operator+=(difference_type _Off)
		{	
		current -= _Off;
		return (*this);
		}

	_Myt operator+(difference_type _Off) const
		{	
		return (_Myt(current - _Off));
		}

	_Myt& operator-=(difference_type _Off)
		{	
		current += _Off;
		return (*this);
		}

	_Myt operator-(difference_type _Off) const
		{	
		return (_Myt(current + _Off));
		}

	reference operator[](difference_type _Off) const
		{	
		return (*(*this + _Off));
		}

	template<class _RanIt2,
		class _Base2>
		bool _Less(const _Revranit<_RanIt2, _Base2>& _Right) const
		{	
		return (_Right.base() < current);
		}

	difference_type operator-(const _Myt& _Right) const
		{	
		return (_Right.base() - current);
		}

protected:
	_RanIt current;	
	};

		
template<class _RanIt,
	class _Base,
	class _Diff> inline
	_Revranit<_RanIt, _Base>
		operator+(_Diff _Off,
		const _Revranit<_RanIt, _Base>& _Right)
	{	
	return (_Right + _Off);
	}

template<class _RanIt1,
	class _Base1,
	class _RanIt2,
	class _Base2> inline
	typename _Base1::difference_type operator-(
		const _Revranit<_RanIt1, _Base1>& _Left,
		const _Revranit<_RanIt2, _Base2>& _Right)
	{	
	return (_Right.base() - _Left.base());
	}

template<class _RanIt1,
	class _Base1,
	class _RanIt2,
	class _Base2> inline
	bool operator==(
		const _Revranit<_RanIt1, _Base1>& _Left,
		const _Revranit<_RanIt2, _Base2>& _Right)
	{	
	return (_Left._Equal(_Right));
	}

template<class _RanIt1,
	class _Base1,
	class _RanIt2,
	class _Base2> inline
	bool operator!=(
		const _Revranit<_RanIt1, _Base1>& _Left,
		const _Revranit<_RanIt2, _Base2>& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _RanIt1,
	class _Base1,
	class _RanIt2,
	class _Base2> inline
	bool operator<(
		const _Revranit<_RanIt1, _Base1>& _Left,
		const _Revranit<_RanIt2, _Base2>& _Right)
	{	
	return (_Left._Less(_Right));
	}

template<class _RanIt1,
	class _Base1,
	class _RanIt2,
	class _Base2> inline
	bool operator>(
		const _Revranit<_RanIt1, _Base1>& _Left,
		const _Revranit<_RanIt2, _Base2>& _Right)
	{	
	return (_Right < _Left);
	}

template<class _RanIt1,
	class _Base1,
	class _RanIt2,
	class _Base2> inline
	bool operator<=(
		const _Revranit<_RanIt1, _Base1>& _Left,
		const _Revranit<_RanIt2, _Base2>& _Right)
	{	
	return (!(_Right < _Left));
	}

template<class _RanIt1,
	class _Base1,
	class _RanIt2,
	class _Base2> inline
	bool operator>=(
		const _Revranit<_RanIt1, _Base1>& _Left,
		const _Revranit<_RanIt2, _Base2>& _Right)
	{	
	return (!(_Left < _Right));
	}

		
template<class _RanIt>
	class reverse_iterator
		: public _Revranit<_RanIt, iterator<
			typename iterator_traits<_RanIt>::iterator_category,
			typename iterator_traits<_RanIt>::value_type,
			typename iterator_traits<_RanIt>::difference_type,
			typename iterator_traits<_RanIt>::pointer,
			typename iterator_traits<_RanIt>::reference> >
	{	
	typedef reverse_iterator<_RanIt> _Myt;
	typedef _Revranit<_RanIt, iterator<
		typename iterator_traits<_RanIt>::iterator_category,
		typename iterator_traits<_RanIt>::value_type,
		typename iterator_traits<_RanIt>::difference_type,
		typename iterator_traits<_RanIt>::pointer,
		typename iterator_traits<_RanIt>::reference> > _Mybase;

public:
 	typedef typename iterator_traits<_RanIt>::difference_type difference_type;
	typedef typename iterator_traits<_RanIt>::pointer pointer;
	typedef typename iterator_traits<_RanIt>::reference reference;
	typedef _RanIt iterator_type;

	reverse_iterator()
		{	
		}

	explicit reverse_iterator(_RanIt _Right)
		: _Mybase(_Right)
		{	
		}

	template<class _Other>
		reverse_iterator(const reverse_iterator<_Other>& _Right)
		: _Mybase(_Right.base())
		{	
		}

	reverse_iterator(_Mybase _Right)
		: _Mybase(_Right)
		{	
		}

	_Myt& operator++()
		{	
		++*((_Mybase *)this);
		return (*this);
		}

	_Myt operator++(int)
		{	
		_Myt _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myt& operator--()
		{	
		--*((_Mybase *)this);
		return (*this);
		}

	_Myt operator--(int)
		{	
		_Myt _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	_Myt& operator+=(difference_type _Off)
		{	
		*((_Mybase *)this) += _Off;
		return (*this);
		}

	_Myt operator+(difference_type _Off) const
		{	
		_Myt _Tmp = *this;
		return (_Tmp += _Off);
		}

	_Myt& operator-=(difference_type _Off)
		{	
		*((_Mybase *)this) -= _Off;
		return (*this);
		}

	_Myt operator-(difference_type _Off) const
		{	
		_Myt _Tmp = *this;
		return (_Tmp -= _Off);
		}
	};

template<class _RanIt>
	struct _Is_checked_helper<reverse_iterator<_RanIt> >
	: public _Is_checked_helper<_RanIt>
	{	
	};

		
template<class _RanIt,
	class _Diff> inline
	reverse_iterator<_RanIt> operator+(_Diff _Off,
		const reverse_iterator<_RanIt>& _Right)
	{	
	return (_Right + _Off);
	}

template<class _RanIt1,
	class _RanIt2> inline
	typename reverse_iterator<_RanIt1>::difference_type
		operator-(const reverse_iterator<_RanIt1>& _Left,
			const reverse_iterator<_RanIt2>& _Right)
	{	
	return (_Right.base() - _Left.base());
	}

template<class _RanIt1,
	class _RanIt2> inline
	bool operator==(const reverse_iterator<_RanIt1>& _Left,
		const reverse_iterator<_RanIt2>& _Right)
	{	
	return (_Left._Equal(_Right));
	}

template<class _RanIt1,
	class _RanIt2> inline
	bool operator!=(const reverse_iterator<_RanIt1>& _Left,
		const reverse_iterator<_RanIt2>& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _RanIt1,
	class _RanIt2> inline
	bool operator<(const reverse_iterator<_RanIt1>& _Left,
		const reverse_iterator<_RanIt2>& _Right)
	{	
	return (_Left._Less(_Right));
	}

template<class _RanIt1,
	class _RanIt2> inline
	bool operator>(const reverse_iterator<_RanIt1>& _Left,
		const reverse_iterator<_RanIt2>& _Right)
	{	
	return (_Right < _Left);
	}

template<class _RanIt1,
	class _RanIt2> inline
	bool operator<=(const reverse_iterator<_RanIt1>& _Left,
		const reverse_iterator<_RanIt2>& _Right)
	{	
	return (!(_Right < _Left));
	}

template<class _RanIt1,
	class _RanIt2> inline
	bool operator>=(const reverse_iterator<_RanIt1>& _Left,
		const reverse_iterator<_RanIt2>& _Right)
	{	
	return (!(_Left < _Right));
	}

		
template<class _BidIt,
	class _Ty,
	class _Reference = _Ty&,
	class _Pointer = _Ty *,
	class _Diff = ptrdiff_t>
	class reverse_bidirectional_iterator
		: public iterator<bidirectional_iterator_tag, _Ty, _Diff,
			_Pointer, _Reference>
	{	
public:
	typedef reverse_bidirectional_iterator<_BidIt, _Ty, _Reference,
		_Pointer, _Diff> _Myt;
	typedef _BidIt iterator_type;

	reverse_bidirectional_iterator()
		{	
		}

	explicit reverse_bidirectional_iterator(_BidIt _Right)
		: current(_Right)
		{	
		}

	_BidIt base() const
		{	
		return (current);
		}

	_Reference operator*() const
		{	
		_BidIt _Tmp = current;
		return (*--_Tmp);
		}

	_Pointer operator->() const
		{	
		_Reference _Tmp = **this;
		return (&_Tmp);
		}

	_Myt& operator++()
		{	
		--current;
		return (*this);
		}

	_Myt operator++(int)
		{	
		_Myt _Tmp = *this;
		--current;
		return (_Tmp);
		}

	_Myt& operator--()
		{	
		++current;
		return (*this);
		}

	_Myt operator--(int)
		{	
		_Myt _Tmp = *this;
		++current;
		return (_Tmp);
		}

	bool operator==(const _Myt& _Right) const
		{	
		return (current == _Right.current);
		}

	bool operator!=(const _Myt& _Right) const
		{	
		return (!(*this == _Right));
		}

protected:
	_BidIt current;	
	};

		
template<class _BidIt,
	class _BidIt2 = _BidIt>
	class _Revbidit
		: public iterator<
			typename iterator_traits<_BidIt>::iterator_category,
			typename iterator_traits<_BidIt>::value_type,
			typename iterator_traits<_BidIt>::difference_type,
			typename iterator_traits<_BidIt>::pointer,
			typename iterator_traits<_BidIt>::reference>
	{	
public:
	typedef _Revbidit<_BidIt, _BidIt2> _Myt;
	typedef typename iterator_traits<_BidIt>::difference_type _Diff;
	typedef typename iterator_traits<_BidIt>::pointer _Pointer;
	typedef typename iterator_traits<_BidIt>::reference _Reference;
	typedef _BidIt iterator_type;

	_Revbidit()
		{	
		}

	explicit _Revbidit(_BidIt _Right)
		: current(_Right)
		{	
		}

	_Revbidit(const _Revbidit<_BidIt2>& _Other)
		: current (_Other.base())
		{	
		}

	_BidIt base() const
		{	
		return (current);
		}

	_Reference operator*() const
		{	
		_BidIt _Tmp = current;
		return (*--_Tmp);
		}

	_Pointer operator->() const
		{	
		_Reference _Tmp = **this;
		return (&_Tmp);
		}

	_Myt& operator++()
		{	
		--current;
		return (*this);
		}

	_Myt operator++(int)
		{	
		_Myt _Tmp = *this;
		--current;
		return (_Tmp);
		}

	_Myt& operator--()
		{	
		++current;
		return (*this);
		}

	_Myt operator--(int)
		{	
		_Myt _Tmp = *this;
		++current;
		return (_Tmp);
		}

	bool operator==(const _Myt& _Right) const
		{	
		return (current == _Right.current);
		}

	bool operator!=(const _Myt& _Right) const
		{	
		return (!(*this == _Right));
		}

protected:
	_BidIt current;
	};

		
template<class _Ty,
	size_t _Size>
	class _Array_const_iterator
		: public _Iterator012<random_access_iterator_tag,
			_Ty,
			ptrdiff_t,
			const _Ty *,
			const _Ty&,
			_Iterator_base>
	{	
public:
	typedef _Array_const_iterator<_Ty, _Size> _Myiter;
	typedef random_access_iterator_tag iterator_category;

	typedef _Ty value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef const _Ty *pointer;
	typedef const _Ty& reference;
	enum {_EEN_SIZE = _Size};	
	enum {_EEN_IDL =
		0};	

 
	_Array_const_iterator()
		{	
		_Ptr = 0;
		}

	explicit _Array_const_iterator(pointer _Parg, size_t _Off = 0)
		{	
		_Ptr = _Parg + _Off;
		}

	typedef pointer _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
		{	
		_Ptr = _Right;
		return (*this);
		}

	_Unchecked_type _Unchecked() const
		{	
		return (_Ptr);
		}

	reference operator*() const
		{	
		return (*_Ptr);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myiter& operator++()
		{	
		++_Ptr;
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
		--_Ptr;
		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	_Myiter& operator+=(difference_type _Off)
		{	
		_Ptr += _Off;
		return (*this);
		}

	_Myiter operator+(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp += _Off);
		}

	_Myiter& operator-=(difference_type _Off)
		{	
		return (*this += -_Off);
		}

	_Myiter operator-(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp -= _Off);
		}

	difference_type operator-(const _Myiter& _Right) const
		{	
		return (_Ptr - _Right._Ptr);
		}

	reference operator[](difference_type _Off) const
		{	
		return (*(*this + _Off));
		}

	bool operator==(const _Myiter& _Right) const
		{	
		return (_Ptr == _Right._Ptr);
		}

	bool operator!=(const _Myiter& _Right) const
		{	
		return (!(*this == _Right));
		}

	bool operator<(const _Myiter& _Right) const
		{	
		return (_Ptr < _Right._Ptr);
		}

	bool operator>(const _Myiter& _Right) const
		{	
		return (_Right < *this);
		}

	bool operator<=(const _Myiter& _Right) const
		{	
		return (!(_Right < *this));
		}

	bool operator>=(const _Myiter& _Right) const
		{	
		return (!(*this < _Right));
		}

	pointer _Ptr;	

 








































































































































































































#line 1907 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
	};

template<class _Ty,
	size_t _Size> inline
	typename _Array_const_iterator<_Ty, _Size>::_Unchecked_type
		_Unchecked(_Array_const_iterator<_Ty, _Size> _Iter)
	{	
	return (_Iter._Unchecked());
	}

template<class _Ty,
	size_t _Size> inline
	_Array_const_iterator<_Ty, _Size>&
		_Rechecked(_Array_const_iterator<_Ty, _Size>& _Iter,
			typename _Array_const_iterator<_Ty, _Size>
				::_Unchecked_type _Right)
	{	
	return (_Iter._Rechecked(_Right));
	}

template<class _Ty,
	size_t _Size> inline
	_Array_const_iterator<_Ty, _Size> operator+(
		typename _Array_const_iterator<_Ty, _Size>::difference_type _Off,
		_Array_const_iterator<_Ty, _Size> _Next)
	{	
	return (_Next += _Off);
	}

		
template<class _Ty,
	size_t _Size>
	class _Array_iterator
		: public _Array_const_iterator<_Ty, _Size>
	{	
public:
	typedef _Array_iterator<_Ty, _Size> _Myiter;
	typedef _Array_const_iterator<_Ty, _Size> _Mybase;
	typedef random_access_iterator_tag iterator_category;

	typedef _Ty value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef _Ty *pointer;
	typedef _Ty& reference;

	_Array_iterator()
		{	
		}

	explicit _Array_iterator(pointer _Parg, size_t _Off = 0)
		: _Mybase(_Parg, _Off)
		{	
		}
	enum {_EEN_SIZE = _Size};	
	enum {_EEN_IDL =
		0};	

	typedef pointer _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
		{	
		((_Mybase *)this)->_Rechecked(_Right);
		return (*this);
		}

	_Unchecked_type _Unchecked() const
		{	
		return ((pointer)((_Mybase *)this)->_Unchecked());
		}

	reference operator*() const
		{	
		return ((reference)**(_Mybase *)this);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myiter& operator++()
		{	
		++*(_Mybase *)this;
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
		--*(_Mybase *)this;
		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	_Myiter& operator+=(difference_type _Off)
		{	
		*(_Mybase *)this += _Off;
		return (*this);
		}

	_Myiter operator+(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp += _Off);
		}

	_Myiter& operator-=(difference_type _Off)
		{	
		return (*this += -_Off);
		}

	_Myiter operator-(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp -= _Off);
		}

	difference_type operator-(const _Mybase& _Right) const
		{	
		return (*(_Mybase *)this - _Right);
		}

	reference operator[](difference_type _Off) const
		{	
		return (*(*this + _Off));
		}
	};

template<class _Ty,
	size_t _Size> inline
	typename _Array_iterator<_Ty, _Size>::_Unchecked_type
		_Unchecked(_Array_iterator<_Ty, _Size> _Iter)
	{	
	return (_Iter._Unchecked());
	}

template<class _Ty,
	size_t _Size> inline
	_Array_iterator<_Ty, _Size>&
		_Rechecked(_Array_iterator<_Ty, _Size>& _Iter,
			typename _Array_iterator<_Ty, _Size>
				::_Unchecked_type _Right)
	{	
	return (_Iter._Rechecked(_Right));
	}

template<class _Ty,
	size_t _Size> inline
	_Array_iterator<_Ty, _Size> operator+(
		typename _Array_iterator<_Ty, _Size>::difference_type _Off,
		_Array_iterator<_Ty, _Size> _Next)
	{	
	return (_Next += _Off);
	}

		
		
template<class _Ty> inline
	const _Ty& (max)(const _Ty& _Left, const _Ty& _Right)
	{	
	return (((_Left) < (_Right)) ? _Right : _Left);
	}

		
template<class _Ty,
	class _Pr> inline
	const _Ty& (max)(const _Ty& _Left, const _Ty& _Right, _Pr _Pred)
	{	
	return (_Pred(_Left, _Right) ? _Right : _Left);
	}

		
template<class _Ty> inline
	const _Ty& (min)(const _Ty& _Left, const _Ty& _Right)
	{	
	return (((_Right) < (_Left)) ? _Right : _Left);
	}

		
template<class _Ty,
	class _Pr> inline
	const _Ty& (min)(const _Ty& _Left, const _Ty& _Right, _Pr _Pred)
	{	
	return (_Pred(_Right, _Left) ? _Right : _Left);
	}

		
  

template<class _Ty> inline
	pair<const _Ty, const _Ty>
		minmax(const _Ty& _Left, const _Ty& _Right)
	{	
	return (_Right < _Left
		? pair<const _Ty, const _Ty>(_Right, _Left)
		: pair<const _Ty, const _Ty>(_Left, _Right));
	}

		
template<class _Ty,
	class _Pr> inline
	pair<const _Ty, const _Ty>
		minmax(const _Ty& _Left, const _Ty& _Right, _Pr _Pred)
	{	
	return (_Pred(_Right, _Left)
		? pair<const _Ty, const _Ty>(_Right, _Left)
		: pair<const _Ty, const _Ty>(_Left, _Right));
	}

		
template<class _FwdIt1,
	class _FwdIt2> inline
	void iter_swap(_FwdIt1 _Left, _FwdIt2 _Right)
	{	
	swap(*_Left, *_Right);
	}

		
template<class _InIt,
	class _OutIt> inline
	_OutIt _Copy_impl(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Nonscalar_ptr_iterator_tag)
	{	
	for (; _First != _Last; ++_Dest, ++_First)
		*_Dest = *_First;
	return (_Dest);
	}

template<class _InIt,
	class _OutIt> inline
	_OutIt _Copy_impl(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Scalar_ptr_iterator_tag)
	{	
	ptrdiff_t _Count = _Last - _First;
	:: memmove(&*_Dest, &*_First,
		_Count * sizeof (*_First));
	return (_Dest + _Count);
	}

template<class _InIt,
	class _OutIt> inline
	_OutIt _Copy_impl(_InIt _First, _InIt _Last,
		_OutIt _Dest)
	{	
	return (_Copy_impl(_First, _Last,
		_Dest, _Ptr_cat(_First, _Dest)));
	}

 
template<class _InIt,
	class _OutIt> inline
	_OutIt copy(_InIt _First, _InIt _Last,
		_OutIt _Dest)
	{	
	return (_Rechecked(_Dest,
		_Copy_impl(_Unchecked(_First), _Unchecked(_Last),
			_Unchecked(_Dest))));
	}

 




























































#line 2241 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

 
		
template<class _InIt,
	class _Diff,
	class _OutIt> inline
	_OutIt _Copy_n(_InIt _First, _Diff _Count,
		_OutIt _Dest, input_iterator_tag)
	{	
	*_Dest = *_First;	
	while (0 < --_Count)
		*++_Dest = *++_First;
	return (++_Dest);
	}

template<class _InIt,
	class _Diff,
	class _OutIt> inline
	_OutIt _Copy_n(_InIt _First, _Diff _Count,
		_OutIt _Dest, forward_iterator_tag)
	{	
	for (; 0 < _Count; --_Count, ++_Dest, ++_First)
		*_Dest = *_First;
	return (_Dest);
	}

template<class _InIt,
	class _Diff,
	class _OutIt> inline
	_OutIt _Copy_n(_InIt _First, _Diff _Count,
		_OutIt _Dest, _Nonscalar_ptr_iterator_tag)
	{	
	return (_Copy_n(_First, _Count,
		_Dest, _Iter_cat(_First)));
	}

template<class _InIt,
	class _Diff,
	class _OutIt> inline
	_OutIt _Copy_n(_InIt _First, _Diff _Count,
		_OutIt _Dest, _Scalar_ptr_iterator_tag)
	{	
	:: memmove(&*_Dest, &*_First,
		_Count * sizeof (*_First));
	return (_Dest + _Count);
	}

template<class _InIt,
	class _Diff,
	class _OutIt> inline
	_OutIt _Copy_n(_InIt _First, _Diff _Count,
		_OutIt _Dest)
	{	
	return (_Copy_n(_First, _Count,
		_Dest, _Ptr_cat(_First, _Dest)));
	}

 
template<class _InIt,
	class _Diff,
	class _OutIt> inline
	_OutIt copy_n(_InIt _First, _Diff _Count,
		_OutIt _Dest)
	{	
	if (_Count <= 0)
		return (_Dest);
	else
		return (_Rechecked(_Dest,
			_Copy_n(_Unchecked(_First), _Count,
				_Unchecked(_Dest))));
	}

 




















































































































#line 2431 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
 #line 2432 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _BidIt1,
	class _BidIt2> inline
	_BidIt2 _Copy_backward(_BidIt1 _First, _BidIt1 _Last,
		_BidIt2 _Dest, _Nonscalar_ptr_iterator_tag)
	{	
	while (_First != _Last)
		*--_Dest = *--_Last;
	return (_Dest);
	}

template<class _InIt,
	class _OutIt> inline
	_OutIt _Copy_backward(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Scalar_ptr_iterator_tag)
	{	
	ptrdiff_t _Count = _Last - _First;
	:: memmove(&*_Dest - _Count, &*_First,
		_Count * sizeof (*_First));
	return (_Dest - _Count);
	}

template<class _BidIt1,
	class _BidIt2> inline
	_BidIt2 _Copy_backward(_BidIt1 _First, _BidIt1 _Last,
		_BidIt2 _Dest)
	{	
	return (_Copy_backward(_First, _Last,
		_Dest, _Ptr_cat(_First, _Dest)));
	}

 
template<class _BidIt1,
	class _BidIt2> inline
	_BidIt2 copy_backward(_BidIt1 _First, _BidIt1 _Last,
		_BidIt2 _Dest)
	{	
	return (_Rechecked(_Dest,
		_Copy_backward(_Unchecked(_First), _Unchecked(_Last),
			_Unchecked(_Dest))));
	}

 





























#line 2506 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _InIt,
	class _OutIt> inline
	_OutIt _Move(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Nonscalar_ptr_iterator_tag)
	{	
	for (; _First != _Last; ++_Dest, ++_First)
		*_Dest = ::std:: move(*_First);
	return (_Dest);
	}

template<class _InIt,
	class _OutIt> inline
	_OutIt _Move(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Scalar_ptr_iterator_tag)
	{	
	ptrdiff_t _Count = _Last - _First;
	:: memmove(&*_Dest, &*_First,
		_Count * sizeof (*_First));
	return (_Dest + _Count);
	}

template<class _InIt,
	class _OutIt> inline
	_OutIt _Move(_InIt _First, _InIt _Last,
		_OutIt _Dest)
	{	
	return (_Move(_First, _Last,
		_Dest, _Ptr_cat(_First, _Dest)));
	}

 
template<class _InIt,
	class _OutIt> inline
	_OutIt move(_InIt _First, _InIt _Last,
		_OutIt _Dest)
	{	
	return (_Rechecked(_Dest,
		_Move(_Unchecked(_First), _Unchecked(_Last),
			_Unchecked(_Dest))));
	}

 




























































#line 2611 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _BidIt1,
	class _BidIt2> inline
	_BidIt2 _Move_backward(_BidIt1 _First, _BidIt1 _Last,
		_BidIt2 _Dest, _Nonscalar_ptr_iterator_tag)
	{	
	while (_First != _Last)
		*--_Dest = ::std:: move(*--_Last);
	return (_Dest);
	}

template<class _InIt,
	class _OutIt> inline
	_OutIt _Move_backward(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Scalar_ptr_iterator_tag)
	{	
	ptrdiff_t _Count = _Last - _First;
	:: memmove(&*_Dest - _Count, &*_First,
		_Count * sizeof (*_First));
	return (_Dest - _Count);
	}

template<class _BidIt1,
	class _BidIt2> inline
	_BidIt2 _Move_backward(_BidIt1 _First, _BidIt1 _Last,
		_BidIt2 _Dest)
	{	
	return (_Move_backward(_First, _Last,
		_Dest, _Ptr_cat(_First, _Dest)));
	}

 
template<class _BidIt1,
	class _BidIt2> inline
	_BidIt2 move_backward(_BidIt1 _First, _BidIt1 _Last,
		_BidIt2 _Dest)
	{	
	return (_Rechecked(_Dest,
		_Move_backward(_Unchecked(_First), _Unchecked(_Last),
			_Unchecked(_Dest))));
	}

 





























#line 2685 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _FwdIt,
	class _Ty> inline
	void _Fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
	{	
	for (; _First != _Last; ++_First)
		*_First = _Val;
	}

inline void _Fill(char *_First, char *_Last, int _Val)
	{	
	:: memset(_First, _Val, _Last - _First);
	}

inline void _Fill(signed char *_First, signed char *_Last, int _Val)
	{	
	:: memset(_First, _Val, _Last - _First);
	}

inline void _Fill(unsigned char *_First, unsigned char *_Last, int _Val)
	{	
	:: memset(_First, _Val, _Last - _First);
	}

template<class _FwdIt,
	class _Ty> inline
	void fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
	{	
	;
	_Fill(_Unchecked(_First), _Unchecked(_Last), _Val);
	}

		
template<class _OutIt,
	class _Diff,
	class _Ty> inline
	void _Fill_n(_OutIt _Dest, _Diff _Count, const _Ty& _Val)
	{	
	for (; 0 < _Count; --_Count, ++_Dest)
		*_Dest = _Val;
	}

inline void _Fill_n(char *_Dest, size_t _Count, int _Val)
	{	
	:: memset(_Dest, _Val, _Count);
	}

inline void _Fill_n(signed char *_Dest, size_t _Count, int _Val)
	{	
	:: memset(_Dest, _Val, _Count);
	}

inline void _Fill_n(unsigned char *_Dest, size_t _Count, int _Val)
	{	
	:: memset(_Dest, _Val, _Count);
	}

 
template<class _OutIt,
	class _Diff,
	class _Ty> inline
	void fill_n(_OutIt _Dest, _Diff _Count, const _Ty& _Val)
	{	
	_Fill_n(_Unchecked(_Dest), _Count, _Val);
	}

 



























































#line 2813 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _InIt1,
	class _InIt2> inline
	pair<_InIt1, _InIt2>
		_Mismatch(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2)
	{	
	for (; _First1 != _Last1 && *_First1 == *_First2; )
		++_First1, ++_First2;
	return (pair<_InIt1, _InIt2>(_First1, _First2));
	}

 
template<class _InIt1,
	class _InIt2> inline
	pair<_InIt1, _InIt2>
		mismatch(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2)
	{	
	::std:: pair<typename _Get_unchecked_type<_InIt1>::type, _InIt2> _Ans(
		::std:: _Mismatch(_Unchecked(_First1), _Unchecked(_Last1),
			_First2));
	return (::std:: pair<_InIt1, _InIt2>(
		_Rechecked(_First1, _Ans.first),
		_Ans.second));
	}

 




















































#line 2895 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _InIt1,
	class _InIt2,
	class _Pr> inline
	pair<_InIt1, _InIt2>
		_Mismatch(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2, _Pr _Pred)
	{	
	for (; _First1 != _Last1 && _Pred(*_First1, *_First2); )
		++_First1, ++_First2;
	return (pair<_InIt1, _InIt2>(_First1, _First2));
	}

 
template<class _InIt1,
	class _InIt2,
	class _Pr> inline
	pair<_InIt1, _InIt2>
		mismatch(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2, _Pr _Pred)
	{	
	::std:: pair<typename _Get_unchecked_type<_InIt1>::type, _InIt2> _Ans(
		::std:: _Mismatch(_Unchecked(_First1), _Unchecked(_Last1),
			_First2, _Pred));
	return (::std:: pair<_InIt1, _InIt2>(
		_Rechecked(_First1, _Ans.first),
		_Ans.second));
	}

 
























































#line 2983 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _InIt1,
	class _InIt2> inline
	bool _Equal(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2)
	{	
	for (; _First1 != _Last1; ++_First1, ++_First2)
		if (!(*_First1 == *_First2))
			return (false);
	return (true);
	}

inline bool _Equal(const char *_First1, const char *_Last1,
	const char *_First2)
	{	
	return (:: memcmp(_First1, _First2, _Last1 - _First1) == 0);
	}

inline bool _Equal(const signed char *_First1, const signed char *_Last1,
	const signed char *_First2)
	{	
	return (:: memcmp(_First1, _First2, _Last1 - _First1) == 0);
	}

inline bool _Equal(const unsigned char *_First1, const unsigned char *_Last1,
	const unsigned char *_First2)
	{	
	return (:: memcmp(_First1, _First2, _Last1 - _First1) == 0);
	}

 
template<class _InIt1,
	class _InIt2> inline
	bool equal(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2)
	{	
	return (_Equal(_Unchecked(_First1), _Unchecked(_Last1),
		_Unchecked(_First2)));
	}

 







































#line 3064 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _InIt1,
	class _InIt2,
	class _Pr> inline
	bool _Equal(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _Pr _Pred)
	{	
	for (; _First1 != _Last1; ++_First1, ++_First2)
		if (!_Pred(*_First1, *_First2))
			return (false);
	return (true);
	}

 
template<class _InIt1,
	class _InIt2,
	class _Pr> inline
	bool equal(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _Pr _Pred)
	{	
	return (_Equal(_Unchecked(_First1), _Unchecked(_Last1),
		_Unchecked(_First2), _Pred));
	}

 











































#line 3134 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		
template<class _InIt1,
	class _InIt2> inline
	bool _Lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _InIt2 _Last2)
	{	
	for (; _First1 != _Last1 && _First2 != _Last2; ++_First1, ++_First2)
		if (((*_First1) < (*_First2)))
			return (true);
		else if (*_First2 < *_First1)
			return (false);
	return (_First1 == _Last1 && _First2 != _Last2);
	}

inline bool _Lexicographical_compare(
	const unsigned char *_First1, const unsigned char *_Last1,
	const unsigned char *_First2, const unsigned char *_Last2)
	{	
	ptrdiff_t _Num1 = _Last1 - _First1;
	ptrdiff_t _Num2 = _Last2 - _First2;
	int _Ans = :: memcmp(_First1, _First2, _Num1 < _Num2 ? _Num1 : _Num2);
	return (_Ans < 0 || _Ans == 0 && _Num1 < _Num2);
	}

 









#line 3170 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

template<class _InIt1,
	class _InIt2> inline
	bool lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _InIt2 _Last2)
	{	
	;
	;
	return (_Lexicographical_compare(_Unchecked(_First1), _Unchecked(_Last1),
		_Unchecked(_First2), _Unchecked(_Last2)));
	}

		
template<class _InIt1,
	class _InIt2,
	class _Pr> inline
	bool _Lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _InIt2 _Last2, _Pr _Pred)
	{	
	for (; _First1 != _Last1 && _First2 != _Last2; ++_First1, ++_First2)
		if (_Pred(*_First1, *_First2))
			return (true);
		else if (_Pred(*_First2, *_First1))
			return (false);
	return (_First1 == _Last1 && _First2 != _Last2);
	}

template<class _InIt1,
	class _InIt2,
	class _Pr> inline
	bool lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _InIt2 _Last2, _Pr _Pred)
	{	
	;
	;
	;
	return (_Lexicographical_compare(_Unchecked(_First1), _Unchecked(_Last1),
		_Unchecked(_First2), _Unchecked(_Last2), _Pred));
	}

		
template<class _BidIt> inline
	void _Reverse(_BidIt _First, _BidIt _Last, bidirectional_iterator_tag)
	{	
	for (; _First != _Last && _First != --_Last; ++_First)
		::std:: iter_swap(_First, _Last);
	}

template<class _BidIt> inline
	void reverse(_BidIt _First, _BidIt _Last)
	{	
	;
	_Reverse(_Unchecked(_First), _Unchecked(_Last), _Iter_cat(_First));
	}

		
template<class _FwdIt> inline
	void _Rotate(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last,
		forward_iterator_tag)
	{	
	for (_FwdIt _Next = _Mid; ; )
		{	
		::std:: iter_swap(_First, _Next);
		if (++_First == _Mid)
			if (++_Next == _Last)
				break;	
			else
				_Mid = _Next;	
		else if (++_Next == _Last)
			_Next = _Mid;	
		}
	}

template<class _BidIt> inline
	void _Rotate(_BidIt _First, _BidIt _Mid, _BidIt _Last,
		bidirectional_iterator_tag)
	{	
	::std:: reverse(_First, _Mid);
	::std:: reverse(_Mid, _Last);
	::std:: reverse(_First, _Last);
	}

template<class _RanIt,
	class _Diff,
	class _Ty> inline
	void _Rotate(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Diff *, _Ty *)
	{	
	_Diff _Shift = _Mid - _First;
	_Diff _Count = _Last - _First;

	for (_Diff _Factor = _Shift; _Factor != 0; )
		{	
		_Diff _Tmp = _Count % _Factor;
		_Count = _Factor;
		_Factor = _Tmp;
		}

	if (_Count < _Last - _First)
		for (; 0 < _Count; --_Count)
			{	
			_RanIt _Hole = _First + _Count;
			_RanIt _Next = _Hole;
			_RanIt _Next1 = _Next + _Shift == _Last ? _First : _Next + _Shift;
			for (; ; )
				{	
				iter_swap(_Next, _Next1);
				_Next = _Next1;
				_Next1 = _Shift < _Last - _Next1 ? _Next1 + _Shift
					: _First + (_Shift - (_Last - _Next1));
				if (_Next1 == _Hole)
					break;
				}
			}
	}

template<class _RanIt> inline
	void _Rotate(_RanIt _First, _RanIt _Mid, _RanIt _Last,
		random_access_iterator_tag)
	{	
	_Rotate(_First, _Mid, _Last, _Dist_type(_First), _Val_type(_First));
	}

template<class _FwdIt> inline
	_FwdIt rotate(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last)
	{	
	;
	;
	if (_First != _Mid && _Mid != _Last)
		{	
		_Rotate(_Unchecked(_First), _Unchecked(_Mid), _Unchecked(_Last),
			_Iter_cat(_First));
		::std:: advance(_First, ::std:: distance(_Mid, _Last));
		}
	return (_First);
	}

		
template<class _Elem>
	class  _Yarn
	{	
public:
	typedef _Yarn<_Elem> _Myt;

	 _Yarn()
		: _Myptr(0), _Nul(0)
		{	
		}

	 _Yarn(const _Myt& _Right)
		: _Myptr(0), _Nul(0)
		{	
		*this = _Right;
		}

	 _Yarn(const _Elem *_Right)
		: _Myptr(0), _Nul(0)
		{	
		*this = _Right;
		}

	_Myt&  operator=(const _Myt& _Right)
		{	
		return (*this = _Right._Myptr);
		}

	_Myt&  operator=(const _Elem *_Right)
		{	
		if (_Myptr != _Right)
			{	
			_Tidy();

			if (_Right != 0)
				{	
				const _Elem *_Ptr = _Right;
				while (*_Ptr != (_Elem)0)
					++_Ptr;
				size_t _Count = ((const char *)++_Ptr - (const char *)_Right)
					* sizeof (_Elem);

 




				_Myptr = (_Elem *):: malloc(_Count);
 #line 3356 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

				if (_Myptr != 0)
					:: memcpy(_Myptr, _Right, _Count);
				}
			}
		return (*this);
		}

	 ~_Yarn()
		{	
		_Tidy();
		}

	bool  empty() const
		{	
		return (_Myptr == 0);
		}

	const _Elem * c_str() const
		{	
		return (_Myptr != 0 ? _Myptr : &_Nul);
		}

	bool  _Empty() const
		{	
		return (_Myptr == 0);
		}

	const _Elem * _C_str() const
		{	
		return (_Myptr != 0 ? _Myptr : &_Nul);
		}

private:
	void  _Tidy()
		{	
		if (_Myptr != 0)

 



			:: free(_Myptr);
 #line 3400 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"

		_Myptr = 0;
		}

	_Elem *_Myptr;	
	_Elem _Nul;		
	};

 __declspec(noreturn) void __cdecl _Xinvalid_argument(   const char *);
 __declspec(noreturn) void __cdecl _Xlength_error(   const char *);
 __declspec(noreturn) void __cdecl _Xout_of_range(   const char *);
 __declspec(noreturn) void __cdecl _Xoverflow_error(   const char *);
 __declspec(noreturn) void __cdecl _Xruntime_error(   const char *);
}
 #pragma warning(pop)
 #pragma pack(pop)

#line 3418 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"
#line 3419 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xutility"























#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"

 #pragma pack(push,8)
 #pragma warning(push,3)

 

 
 

 #pragma warning(disable: 4100)


 
 
 
#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"

namespace std {
		
template<class _Ty> inline
	_Ty  *_Allocate(size_t _Count, _Ty  *)
	{	
	void *_Ptr = 0;

	if (_Count <= 0)
		_Count = 0;
	else if (((size_t)(-1) / sizeof (_Ty) < _Count)
		|| (_Ptr = ::operator new(_Count * sizeof (_Ty))) == 0)
		throw bad_alloc(0);

	return ((_Ty  *)_Ptr);
	}

		
template<class _Ty1,
	class _Ty2> inline
	void _Construct(_Ty1  *_Ptr, _Ty2&& _Val)
	{	
	void  *_Vptr = _Ptr;
	::new (_Vptr) _Ty1(::std:: forward<_Ty2>(_Val));
	}

template<class _Ty1> inline
	void _Construct(_Ty1  *_Ptr)
	{	
	void  *_Vptr = _Ptr;

	::new (_Vptr) _Ty1();
	}

		
template<class _Ty> inline
	void _Destroy(_Ty  *_Ptr)
	{	
	_Ptr->~_Ty();
	}

template<> inline
	void _Destroy(char  *)
	{	
	}

template<> inline
	void _Destroy(wchar_t  *)
	{	
	}

 
template<> inline
	void _Destroy(unsigned short  *)
	{	
	}
 #line 82 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"

		
template<class _Alloc> inline
	void _Destroy_range(typename _Alloc::pointer _First,
		typename _Alloc::pointer _Last, _Alloc& _Al)
	{	
	_Destroy_range(_First, _Last, _Al, _Ptr_cat(_First, _Last));
	}

template<class _Alloc> inline
	void _Destroy_range(typename _Alloc::pointer _First,
		typename _Alloc::pointer _Last, _Alloc& _Al,
		_Nonscalar_ptr_iterator_tag)
	{	
	for (; _First != _Last; ++_First)
		_Dest_val(_Al, _First);
	}

template<class _Alloc> inline
	void _Destroy_range(typename _Alloc::pointer _First,
		typename _Alloc::pointer _Last, _Alloc& _Al,
		_Scalar_ptr_iterator_tag)
	{	
	}

		
template<class _Ty> inline
	_Ty * addressof(_Ty& _Val)
	{	
	return ((_Ty *) &(char&)_Val);
	}

		
template<class _Ty>
	struct _Allocator_base
	{	
	typedef _Ty value_type;
	};

		
template<class _Ty>
	struct _Allocator_base<const _Ty>
	{	
	typedef _Ty value_type;
	};

		
template<class _Ty>
	class allocator
		: public _Allocator_base<_Ty>
	{	
public:
	typedef _Allocator_base<_Ty> _Mybase;
	typedef typename _Mybase::value_type value_type;

	typedef value_type  *pointer;
	typedef value_type & reference;
	typedef const value_type  *const_pointer;
	typedef const value_type & const_reference;

	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	template<class _Other>
		struct rebind
		{	
		typedef allocator<_Other> other;
		};

	pointer address(reference _Val) const
		{	
		return ((pointer) &(char&)_Val);
		}

	const_pointer address(const_reference _Val) const
		{	
		return ((const_pointer) &(char&)_Val);
		}

	allocator() throw ()
		{	
		}

	allocator(const allocator<_Ty>&) throw ()
		{	
		}

	template<class _Other>
		allocator(const allocator<_Other>&) throw ()
		{	
		}

	template<class _Other>
		allocator<_Ty>& operator=(const allocator<_Other>&)
		{	
		return (*this);
		}

	void deallocate(pointer _Ptr, size_type)
		{	
		::operator delete(_Ptr);
		}

	pointer allocate(size_type _Count)
		{	
		return (_Allocate(_Count, (pointer)0));
		}

	pointer allocate(size_type _Count, const void  *)
		{	
		return (allocate(_Count));
		}

	void construct(pointer _Ptr, const _Ty& _Val)
		{	
		_Construct(_Ptr, _Val);
		}

	void construct(pointer _Ptr, _Ty&& _Val)
		{	
		::new ((void  *)_Ptr) _Ty(::std:: forward<_Ty>(_Val));
		}

	template<class _Other>
		void construct(pointer _Ptr, _Other&& _Val)
		{	
		::new ((void  *)_Ptr) _Ty(::std:: forward<_Other>(_Val));
		}

	void destroy(pointer _Ptr)
		{	
		_Destroy(_Ptr);
		}

	size_t max_size() const throw ()
		{	
		size_t _Count = (size_t)(-1) / sizeof (_Ty);
		return (0 < _Count ? _Count : 1);
		}
	};

		
template<> class allocator<void>
	{	
public:
	typedef void _Ty;
	typedef _Ty  *pointer;
	typedef const _Ty  *const_pointer;
	typedef _Ty value_type;

	template<class _Other>
		struct rebind
		{	
		typedef allocator<_Other> other;
		};

	allocator() throw ()
		{	
		}

	allocator(const allocator<_Ty>&) throw ()
		{	
		}

	template<class _Other>
		allocator(const allocator<_Other>&) throw ()
		{	
		}

	template<class _Other>
		allocator<_Ty>& operator=(const allocator<_Other>&)
		{	
		return (*this);
		}
	};

template<class _Ty,
	class _Other> inline
	bool operator==(const allocator<_Ty>&,
		const allocator<_Other>&) throw ()
	{	
	return (true);
	}

template<class _Ty,
	class _Other> inline
	bool operator!=(const allocator<_Ty>& _Left,
		const allocator<_Other>& _Right) throw ()
	{	
	return (!(_Left == _Right));
	}

		
template<class _Alloc,
	class _Ty1,
	class _Ty2>
	void _Cons_val(_Alloc& _Alval, _Ty1 *_Pdest, _Ty2&& _Src)
	{	
	_Alval.construct(_Pdest, ::std:: forward<_Ty2>(_Src));
	}

template<class _Alloc,
	class _Ty1>
	void _Dest_val(_Alloc& _Alval, _Ty1 *_Pdest)
	{	
	_Alval.destroy(_Pdest);
	}
}

 

 #pragma warning(pop)
 #pragma pack(pop)

#line 297 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"
#line 298 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"






















#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

 #pragma pack(push,8)
 #pragma warning(push,3)

namespace std {
  #pragma warning(disable: 4251)

template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Ax = allocator<_Elem> >
	class basic_string;

  
  
  

		
template<class _Elem,
	class _Traits,
	class _Alloc>
	class _String_const_iterator
		: public _Iterator012<random_access_iterator_tag,
			typename _Alloc::value_type,
			typename _Alloc::difference_type,
			typename _Alloc::const_pointer,
			typename _Alloc::const_reference,
			_Iterator_base>
	{	
public:
	typedef _String_const_iterator<_Elem, _Traits, _Alloc> _Myiter;
	typedef basic_string<_Elem, _Traits, _Alloc> _Mystr;
	typedef random_access_iterator_tag iterator_category;

	typedef typename _Alloc::value_type value_type;
	typedef typename _Alloc::difference_type difference_type;
	typedef typename _Alloc::const_pointer pointer;
	typedef typename _Alloc::const_reference reference;

	_String_const_iterator()
		{	
		this->_Ptr = 0;
		}

	_String_const_iterator(pointer _Parg, const _Container_base *_Pstring)
		{	
		this->_Adopt(_Pstring);
		this->_Ptr = _Parg;
		}

	typedef pointer _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
		{	
		this->_Ptr = _Right;
		return (*this);
		}

	_Unchecked_type _Unchecked() const
		{	
		return (_Unchecked_type(this->_Ptr));
		}

	reference operator*() const
		{	
 










#line 83 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"





#line 89 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		;

		return (*this->_Ptr);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myiter& operator++()
		{	
 









#line 113 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"




#line 118 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		++this->_Ptr;
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
 








#line 142 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"



#line 146 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		--this->_Ptr;
		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	_Myiter& operator+=(difference_type _Off)
		{	
 










#line 172 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"





#line 178 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		_Ptr += _Off;
		return (*this);
		}

	_Myiter operator+(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp += _Off);
		}

	_Myiter& operator-=(difference_type _Off)
		{	
		return (*this += -_Off);
		}

	_Myiter operator-(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp -= _Off);
		}

	difference_type operator-(const _Myiter& _Right) const
		{	
		_Compat(_Right);
		return (this->_Ptr - _Right._Ptr);
		}

	reference operator[](difference_type _Off) const
		{	
		return (*(*this + _Off));
		}

	bool operator==(const _Myiter& _Right) const
		{	
		_Compat(_Right);
		return (this->_Ptr == _Right._Ptr);
		}

	bool operator!=(const _Myiter& _Right) const
		{	
		return (!(*this == _Right));
		}

	bool operator<(const _Myiter& _Right) const
		{	
		_Compat(_Right);
		return (this->_Ptr < _Right._Ptr);
		}

	bool operator>(const _Myiter& _Right) const
		{	
		return (_Right < *this);
		}

	bool operator<=(const _Myiter& _Right) const
		{	
		return (!(_Right < *this));
		}

	bool operator>=(const _Myiter& _Right) const
		{	
		return (!(*this < _Right));
		}

 










#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"






#line 262 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"
	void _Compat(const _Myiter&) const
		{	
		}
 #line 266 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

	pointer _Ptr;	
	};

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	typename _String_const_iterator<_Elem, _Traits, _Alloc>::_Unchecked_type
		_Unchecked(_String_const_iterator<_Elem, _Traits, _Alloc> _Iter)
	{	
	return (_Iter._Unchecked());
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	_String_const_iterator<_Elem, _Traits, _Alloc>
		_Rechecked(_String_const_iterator<_Elem, _Traits, _Alloc>& _Iter,
			typename _String_const_iterator<_Elem, _Traits, _Alloc>
				::_Unchecked_type _Right)
	{	
	return (_Iter._Rechecked(_Right));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	_String_const_iterator<_Elem, _Traits, _Alloc> operator+(
		typename _String_const_iterator<_Elem, _Traits, _Alloc>
			::difference_type _Off,
		_String_const_iterator<_Elem, _Traits, _Alloc> _Next)
	{	
	return (_Next += _Off);
	}

		
template<class _Elem,
	class _Traits,
	class _Alloc>
	class _String_iterator
		: public _String_const_iterator<_Elem, _Traits, _Alloc>
	{	
public:
	typedef _String_iterator<_Elem, _Traits, _Alloc> _Myiter;
	typedef _String_const_iterator<_Elem, _Traits, _Alloc> _Mybase;
	typedef basic_string<_Elem, _Traits, _Alloc> _Mystr;
	typedef random_access_iterator_tag iterator_category;

	typedef typename _Mystr::value_type value_type;
	typedef typename _Mystr::difference_type difference_type;
	typedef typename _Mystr::pointer pointer;
	typedef typename _Mystr::reference reference;

	_String_iterator()
		{	
		}

	_String_iterator(pointer _Parg, const _Container_base *_Pstring)
		: _Mybase(_Parg, _Pstring)
		{	
		}

	typedef pointer _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
		{	
		this->_Ptr = _Right;
		return (*this);
		}

	_Unchecked_type _Unchecked() const
		{	
		return (_Unchecked_type(this->_Ptr));
		}

	reference operator*() const
		{	
		return ((reference)**(_Mybase *)this);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myiter& operator++()
		{	
		++*(_Mybase *)this;
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
		--*(_Mybase *)this;
		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	_Myiter& operator+=(difference_type _Off)
		{	
		*(_Mybase *)this += _Off;
		return (*this);
		}

	_Myiter operator+(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp += _Off);
		}

	_Myiter& operator-=(difference_type _Off)
		{	
		return (*this += -_Off);
		}

	_Myiter operator-(difference_type _Off) const
		{	
		_Myiter _Tmp = *this;
		return (_Tmp -= _Off);
		}

	difference_type operator-(const _Mybase& _Right) const
		{	
		return ((_Mybase)*this - _Right);
		}

	reference operator[](difference_type _Off) const
		{	
		return (*(*this + _Off));
		}
	};

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	typename _String_iterator<_Elem, _Traits, _Alloc>::_Unchecked_type
		_Unchecked(_String_iterator<_Elem, _Traits, _Alloc> _Iter)
	{	
	return (_Iter._Unchecked());
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	_String_iterator<_Elem, _Traits, _Alloc>
		_Rechecked(_String_iterator<_Elem, _Traits, _Alloc>& _Iter,
			typename _String_iterator<_Elem, _Traits, _Alloc>
				::_Unchecked_type _Right)
	{	
	return (_Iter._Rechecked(_Right));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	_String_iterator<_Elem, _Traits, _Alloc> operator+(
		typename _String_iterator<_Elem, _Traits, _Alloc>
			::difference_type _Off,
		_String_iterator<_Elem, _Traits, _Alloc> _Next)
	{	
	return (_Next += _Off);
	}

		
template<class _Elem,
	class _Alloc>
	class _String_val
		: public _Container_base
	{	
public:
 
	typedef typename _Alloc::template rebind<_Elem>::other _Alty;

	_String_val(_Alty _Al = _Alty())
		: _Alval(_Al)
		{	
		}

	~_String_val()
		{	
		}

 





















#line 484 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

	typedef typename _Alty::size_type size_type;
	typedef typename _Alty::difference_type difference_type;
	typedef typename _Alty::pointer pointer;
	typedef typename _Alty::const_pointer const_pointer;
	typedef typename _Alty::reference reference;
	typedef typename _Alty::const_reference const_reference;
	typedef typename _Alty::value_type value_type;

	enum
		{	
		_BUF_SIZE = 16 / sizeof (_Elem) < 1 ? 1
			: 16 / sizeof (_Elem)};
	enum
		{	
		_ALLOC_MASK = sizeof (_Elem) <= 1 ? 15
			: sizeof (_Elem) <= 2 ? 7
			: sizeof (_Elem) <= 4 ? 3
			: sizeof (_Elem) <= 8 ? 1 : 0};

	union _Bxty
		{	
		_Elem _Buf[_BUF_SIZE];
		_Elem *_Ptr;
		char _Alias[_BUF_SIZE];	
		} _Bx;

	size_type _Mysize;	
	size_type _Myres;	
	_Alty _Alval;	
	};

		
template<class _Elem,
	class _Traits,
	class _Ax>
	class basic_string
		: public _String_val<_Elem, _Ax>
	{	
public:
	typedef basic_string<_Elem, _Traits, _Ax> _Myt;
	typedef _String_val<_Elem, _Ax> _Mybase;
	typedef typename _Mybase::_Alty _Alloc;
	typedef typename _Alloc::size_type size_type;
	typedef typename _Alloc::difference_type difference_type;
	typedef typename _Alloc::pointer pointer;
	typedef typename _Alloc::const_pointer const_pointer;
	typedef typename _Alloc::reference reference;
	typedef typename _Alloc::const_reference const_reference;
	typedef typename _Alloc::value_type value_type;

	typedef _String_iterator<_Elem, _Traits, _Alloc> iterator;
	typedef _String_const_iterator<_Elem, _Traits, _Alloc> const_iterator;

	typedef ::std:: reverse_iterator<iterator> reverse_iterator;
	typedef ::std:: reverse_iterator<const_iterator> const_reverse_iterator;

	basic_string(const _Myt& _Right)
		: _Mybase(_Right._Alval)
		{	
		_Tidy();
		assign(_Right, 0, npos);
		}

	basic_string()
		: _Mybase()
		{	
		_Tidy();
		}

	explicit basic_string(const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Tidy();
		}

	basic_string(const _Myt& _Right, size_type _Roff,
		size_type _Count = npos)
		: _Mybase(_Right._Alval)
		{	
		_Tidy();
		assign(_Right, _Roff, _Count);
		}

	basic_string(const _Myt& _Right, size_type _Roff, size_type _Count,
		const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Tidy();
		assign(_Right, _Roff, _Count);
		}

	basic_string(const _Elem *_Ptr, size_type _Count)
		: _Mybase()
		{	
		_Tidy();
		assign(_Ptr, _Count);
		}

	basic_string(const _Elem *_Ptr, size_type _Count, const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Tidy();
		assign(_Ptr, _Count);
		}

	basic_string(const _Elem *_Ptr)
		: _Mybase()
		{	
		_Tidy();
		assign(_Ptr);
		}

	basic_string(const _Elem *_Ptr, const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Tidy();
		assign(_Ptr);
		}

	basic_string(size_type _Count, _Elem _Ch)
		: _Mybase()
		{	
		_Tidy();
		assign(_Count, _Ch);
		}

	basic_string(size_type _Count, _Elem _Ch, const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Tidy();
		assign(_Count, _Ch);
		}

	template<class _It>
		basic_string(_It _First, _It _Last)
		: _Mybase()
		{	
		_Tidy();
		_Construct(_First, _Last, _Iter_cat(_First));
		}

	template<class _It>
		basic_string(_It _First, _It _Last, const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Tidy();
		_Construct(_First, _Last, _Iter_cat(_First));
		}

	template<class _It>
		void _Construct(_It _Count,
			_It _Ch, _Int_iterator_tag)
		{	
		assign((size_type)_Count, (_Elem)_Ch);
		}

	template<class _It>
		void _Construct(_It _First,
			_It _Last, input_iterator_tag)
		{	
		try {
		for (; _First != _Last; ++_First)
			append((size_type)1, (_Elem)*_First);
		} catch (...) {
		_Tidy(true);
		throw;
		}
		}

	template<class _It>
		void _Construct(_It _First,
			_It _Last, forward_iterator_tag)
		{	
		;
		size_type _Count = 0;
		_Distance(_First, _Last, _Count);
		reserve(_Count);

		try {
		for (; _First != _Last; ++_First)
			append((size_type)1, (_Elem)*_First);
		} catch (...) {
		_Tidy(true);
		throw;
		}
		}

	basic_string(const_pointer _First, const_pointer _Last)
		: _Mybase()
		{	
		;
		_Tidy();
		if (_First != _Last)
			assign(&*_First, _Last - _First);
		}

	basic_string(const_pointer _First, const_pointer _Last,
		const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		;
		_Tidy();
		if (_First != _Last)
			assign(&*_First, _Last - _First);
		}

	basic_string(const_iterator _First, const_iterator _Last)
		: _Mybase()
		{	
		;
		_Tidy();
		if (_First != _Last)
			assign(&*_First, _Last - _First);
		}

	basic_string(_Myt&& _Right)
		: _Mybase(::std:: forward<_Alloc>(_Right._Alval))
		{	
		_Tidy();
		assign(::std:: forward<_Myt>(_Right));
		}

	_Myt& operator=(_Myt&& _Right)
		{	
		return (assign(::std:: forward<_Myt>(_Right)));
		}

	_Myt& assign(_Myt&& _Right)
		{	
		if (this == &_Right)
			;
		else if (get_allocator() != _Right.get_allocator()
			&& this->_BUF_SIZE <= _Right._Myres)
			*this = _Right;
		else
			{	
			_Tidy(true);
			if (_Right._Myres < this->_BUF_SIZE)
				_Traits::move(this->_Bx._Buf, _Right._Bx._Buf,
					_Right._Mysize + 1);
			else
				{	
				this->_Bx._Ptr = _Right._Bx._Ptr;
				_Right._Bx._Ptr = 0;
				}
			this->_Mysize = _Right._Mysize;
			this->_Myres = _Right._Myres;

			_Right._Mysize = 0;
			_Right._Myres = 0;
			}
		return (*this);
		}

	void swap(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
 


#line 747 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

			assign(::std:: forward<_Myt>(_Right));
			}
		}

	~basic_string()
		{	
		_Tidy(true);
		}

	typedef _Traits traits_type;
	typedef _Alloc allocator_type;

	 static const size_type npos;	

	_Myt& operator=(const _Myt& _Right)
		{	
		return (assign(_Right));
		}

	_Myt& operator=(const _Elem *_Ptr)
		{	
		return (assign(_Ptr));
		}

	_Myt& operator=(_Elem _Ch)
		{	
		return (assign(1, _Ch));
		}

	_Myt& operator+=(const _Myt& _Right)
		{	
		return (append(_Right));
		}

	_Myt& operator+=(const _Elem *_Ptr)
		{	
		return (append(_Ptr));
		}

	_Myt& operator+=(_Elem _Ch)
		{	
		return (append((size_type)1, _Ch));
		}

	_Myt& append(const _Myt& _Right)
		{	
		return (append(_Right, 0, npos));
		}

	_Myt& append(const _Myt& _Right,
		size_type _Roff, size_type _Count)
		{	
		if (_Right.size() < _Roff)
			_Xran();	
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	
		if (npos - this->_Mysize <= _Count)
			_Xlen();	

		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	
			_Traits::copy(_Myptr() + this->_Mysize,
				_Right._Myptr() + _Roff, _Count);
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& append(const _Elem *_Ptr, size_type _Count)
		{	
 


#line 823 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (_Inside(_Ptr))
			return (append(*this, _Ptr - _Myptr(), _Count));	
		if (npos - this->_Mysize <= _Count)
			_Xlen();	

		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	
			_Traits::copy(_Myptr() + this->_Mysize, _Ptr, _Count);
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& append(const _Elem *_Ptr)
		{	
		;
		return (append(_Ptr, _Traits::length(_Ptr)));
		}

	_Myt& append(size_type _Count, _Elem _Ch)
		{	
		if (npos - this->_Mysize <= _Count)
			_Xlen();	

		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	
			_Chassign(this->_Mysize, _Count, _Ch);
			_Eos(_Num);
			}
		return (*this);
		}

	template<class _It>
		_Myt& append(_It _First, _It _Last)
		{	
		return (_Append(_First, _Last, _Iter_cat(_First)));
		}

	template<class _It>
		_Myt& _Append(_It _Count, _It _Ch, _Int_iterator_tag)
		{	
		return (append((size_type)_Count, (_Elem)_Ch));
		}

	template<class _It>
		_Myt& _Append(_It _First, _It _Last, input_iterator_tag)
		{	
		return (replace(end(), end(), _First, _Last));
		}

	_Myt& append(const_pointer _First, const_pointer _Last)
		{	
		return (replace(end(), end(), _First, _Last));
		}

	_Myt& append(const_iterator _First, const_iterator _Last)
		{	
		return (replace(end(), end(), _First, _Last));
		}

	_Myt& assign(const _Myt& _Right)
		{	
		return (assign(_Right, 0, npos));
		}

	_Myt& assign(const _Myt& _Right,
		size_type _Roff, size_type _Count)
		{	
		if (_Right.size() < _Roff)
			_Xran();	
		size_type _Num = _Right.size() - _Roff;
		if (_Count < _Num)
			_Num = _Count;	

		if (this == &_Right)
			erase((size_type)(_Roff + _Num)), erase(0, _Roff);	
		else if (_Grow(_Num))
			{	
			_Traits::copy(_Myptr(), _Right._Myptr() + _Roff, _Num);
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& assign(const _Elem *_Ptr, size_type _Count)
		{	
 


#line 916 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (_Inside(_Ptr))
			return (assign(*this, _Ptr - _Myptr(), _Count));	

		if (_Grow(_Count))
			{	
			_Traits::copy(_Myptr(), _Ptr, _Count);
			_Eos(_Count);
			}
		return (*this);
		}

	_Myt& assign(const _Elem *_Ptr)
		{	
		;
		return (assign(_Ptr, _Traits::length(_Ptr)));
		}

	_Myt& assign(size_type _Count, _Elem _Ch)
		{	
		if (_Count == npos)
			_Xlen();	

		if (_Grow(_Count))
			{	
			_Chassign(0, _Count, _Ch);
			_Eos(_Count);
			}
		return (*this);
		}

	template<class _It>
		_Myt& assign(_It _First, _It _Last)
		{	
		return (_Assign(_First, _Last, _Iter_cat(_First)));
		}

	template<class _It>
		_Myt& _Assign(_It _Count, _It _Ch, _Int_iterator_tag)
		{	
		return (assign((size_type)_Count, (_Elem)_Ch));
		}

	template<class _It>
		_Myt& _Assign(_It _First, _It _Last, input_iterator_tag)
		{	
		return (replace(begin(), end(), _First, _Last));
		}

	_Myt& assign(const_pointer _First, const_pointer _Last)
		{	
		return (replace(begin(), end(), _First, _Last));
		}

	_Myt& assign(const_iterator _First, const_iterator _Last)
		{	
		return (replace(begin(), end(), _First, _Last));
		}

	_Myt& insert(size_type _Off, const _Myt& _Right)
		{	
		return (insert(_Off, _Right, 0, npos));
		}

	_Myt& insert(size_type _Off,
		const _Myt& _Right, size_type _Roff, size_type _Count)
		{	
		if (this->_Mysize < _Off || _Right.size() < _Roff)
			_Xran();	
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	
		if (npos - this->_Mysize <= _Count)
			_Xlen();	

		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off, this->_Mysize - _Off);	
			if (this == &_Right)
				_Traits::move(_Myptr() + _Off,
					_Myptr() + (_Off < _Roff ? _Roff + _Count : _Roff),
						_Count);	
			else
				_Traits::copy(_Myptr() + _Off,
					_Right._Myptr() + _Roff, _Count);	
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& insert(size_type _Off,
		const _Elem *_Ptr, size_type _Count)
		{	
 


#line 1014 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (_Inside(_Ptr))
			return (insert(_Off, *this,
				_Ptr - _Myptr(), _Count));	
		if (this->_Mysize < _Off)
			_Xran();	
		if (npos - this->_Mysize <= _Count)
			_Xlen();	
		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off, this->_Mysize - _Off);	
			_Traits::copy(_Myptr() + _Off, _Ptr, _Count);	
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& insert(size_type _Off, const _Elem *_Ptr)
		{	
		;
		return (insert(_Off, _Ptr, _Traits::length(_Ptr)));
		}

	_Myt& insert(size_type _Off,
		size_type _Count, _Elem _Ch)
		{	
		if (this->_Mysize < _Off)
			_Xran();	
		if (npos - this->_Mysize <= _Count)
			_Xlen();	
		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off, this->_Mysize - _Off);	
			_Chassign(_Off, _Count, _Ch);	
			_Eos(_Num);
			}
		return (*this);
		}

	iterator insert(const_iterator _Where)
		{	
		return (insert(_Where, _Elem()));
		}

	iterator insert(const_iterator _Where, _Elem _Ch)
		{	
		size_type _Off = _Pdif(_Where, begin());
		insert(_Off, 1, _Ch);
		return (begin() + _Off);
		}

	void insert(const_iterator _Where, size_type _Count, _Elem _Ch)
		{	
		size_type _Off = _Pdif(_Where, begin());
		insert(_Off, _Count, _Ch);
		}

	template<class _It>
		void insert(const_iterator _Where, _It _First, _It _Last)
		{	
		_Insert(_Where, _First, _Last, _Iter_cat(_First));
		}

	template<class _It>
		void _Insert(const_iterator _Where, _It _Count, _It _Ch,
			_Int_iterator_tag)
		{	
		insert(_Where, (size_type)_Count, (_Elem)_Ch);
		}

	template<class _It>
		void _Insert(const_iterator _Where, _It _First, _It _Last,
			input_iterator_tag)
		{	
		replace(_Where, _Where, _First, _Last);
		}

	void insert(const_iterator _Where,
		const_pointer _First, const_pointer _Last)
		{	
		replace(_Where, _Where, _First, _Last);
		}

	void insert(const_iterator _Where,
		const_iterator _First, const_iterator _Last)
		{	
		replace(_Where, _Where, _First, _Last);
		}

	_Myt& erase(size_type _Off = 0,
		size_type _Count = npos)
		{	
		if (this->_Mysize < _Off)
			_Xran();	
		if (this->_Mysize - _Off < _Count)
			_Count = this->_Mysize - _Off;	
		if (0 < _Count)
			{	
			_Traits::move(_Myptr() + _Off, _Myptr() + _Off + _Count,
				this->_Mysize - _Off - _Count);
			size_type _Newsize = this->_Mysize - _Count;
			_Eos(_Newsize);
			}
		return (*this);
		}

	iterator erase(const_iterator _Where)
		{	
		size_type _Count = _Pdif(_Where, begin());
		erase(_Count, 1);
		return (iterator(_Myptr() + _Count, this));
		}

	iterator erase(const_iterator _First, const_iterator _Last)
		{	
		size_type _Count = _Pdif(_First, begin());
		erase(_Count, _Pdif(_Last, _First));
		return (iterator(_Myptr() + _Count, this));
		}

	void clear()
		{	
		_Eos(0);
		}

	_Myt& replace(size_type _Off, size_type _N0, const _Myt& _Right)
		{	
		return (replace(_Off, _N0, _Right, 0, npos));
		}

	_Myt& replace(size_type _Off,
		size_type _N0, const _Myt& _Right, size_type _Roff, size_type _Count)
		{	
		if (this->_Mysize < _Off || _Right.size() < _Roff)
			_Xran();	
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	
		if (npos - _Count <= this->_Mysize - _N0)
			_Xlen();	

		size_type _Nm = this->_Mysize - _N0 - _Off;	
		size_type _Newsize = this->_Mysize + _Count - _N0;
		if (this->_Mysize < _Newsize)
			_Grow(_Newsize);

		if (this != &_Right)
			{	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off + _N0, _Nm);	
			_Traits::copy(_Myptr() + _Off,
				_Right._Myptr() + _Roff, _Count);	
			}
		else if (_Count <= _N0)
			{	
			_Traits::move(_Myptr() + _Off,
				_Myptr() + _Roff, _Count);	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off + _N0, _Nm);	
			}
		else if (_Roff <= _Off)
			{	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off + _N0, _Nm);	
			_Traits::move(_Myptr() + _Off,
				_Myptr() + _Roff, _Count);	
			}
		else if (_Off + _N0 <= _Roff)
			{	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off + _N0, _Nm);	
			_Traits::move(_Myptr() + _Off,
				_Myptr() + (_Roff + _Count - _N0), _Count);	
			}
		else
			{	
			_Traits::move(_Myptr() + _Off,
				_Myptr() + _Roff, _N0);	
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off + _N0, _Nm);	
			_Traits::move(_Myptr() + _Off + _N0, _Myptr() + _Roff + _Count,
				_Count - _N0);	
			}

		_Eos(_Newsize);
		return (*this);
		}

	_Myt& replace(size_type _Off,
		size_type _N0, const _Elem *_Ptr, size_type _Count)
		{	
 


#line 1215 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (_Inside(_Ptr))
			return (replace(_Off, _N0, *this,
				_Ptr - _Myptr(), _Count));	
		if (this->_Mysize < _Off)
			_Xran();	
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	
		if (npos - _Count <= this->_Mysize - _N0)
			_Xlen();	
		size_type _Nm = this->_Mysize - _N0 - _Off;

		if (_Count < _N0)
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off + _N0, _Nm);	
		size_type _Num;
		if ((0 < _Count || 0 < _N0)
			&& _Grow(_Num = this->_Mysize + _Count - _N0))
			{	
			if (_N0 < _Count)
				_Traits::move(_Myptr() + _Off + _Count,
					_Myptr() + _Off + _N0, _Nm);	
			_Traits::copy(_Myptr() + _Off, _Ptr, _Count);	
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& replace(size_type _Off, size_type _N0, const _Elem *_Ptr)
		{	
		;
		return (replace(_Off, _N0, _Ptr, _Traits::length(_Ptr)));
		}

	_Myt& replace(size_type _Off,
		size_type _N0, size_type _Count, _Elem _Ch)
		{	
		if (this->_Mysize < _Off)
			_Xran();	
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	
		if (npos - _Count <= this->_Mysize - _N0)
			_Xlen();	
		size_type _Nm = this->_Mysize - _N0 - _Off;

		if (_Count < _N0)
			_Traits::move(_Myptr() + _Off + _Count,
				_Myptr() + _Off + _N0, _Nm);	
		size_type _Num;
		if ((0 < _Count || 0 < _N0)
			&& _Grow(_Num = this->_Mysize + _Count - _N0))
			{	
			if (_N0 < _Count)
				_Traits::move(_Myptr() + _Off + _Count,
					_Myptr() + _Off + _N0, _Nm);	
			_Chassign(_Off, _Count, _Ch);	
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& replace(const_iterator _First, const_iterator _Last,
		const _Myt& _Right)
		{	
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Right));
		}

	_Myt& replace(const_iterator _First, const_iterator _Last,
		const _Elem *_Ptr, size_type _Count)
		{	
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Ptr, _Count));
		}

	_Myt& replace(const_iterator _First, const_iterator _Last,
		const _Elem *_Ptr)
		{	
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Ptr));
		}

	_Myt& replace(const_iterator _First, const_iterator _Last,
		size_type _Count, _Elem _Ch)
		{	
		return (replace(
			_Pdif(_First, begin()), _Pdif(_Last, _First), _Count, _Ch));
		}

	template<class _It>
		_Myt& replace(const_iterator _First, const_iterator _Last,
			_It _First2, _It _Last2)
		{	
		return (_Replace(_First, _Last,
			_First2, _Last2, _Iter_cat(_First2)));
		}

	template<class _It>
		_Myt& _Replace(const_iterator _First, const_iterator _Last,
			_It _Count, _It _Ch, _Int_iterator_tag)
		{	
		return (replace(_First, _Last, (size_type)_Count, (_Elem)_Ch));
		}

	template<class _It>
		_Myt& _Replace(const_iterator _First, const_iterator _Last,
			_It _First2, _It _Last2, input_iterator_tag)
		{	
		_Myt _Right(_First2, _Last2);
		replace(_First, _Last, _Right);
		return (*this);
		}

	_Myt& replace(const_iterator _First, const_iterator _Last,
		const_pointer _First2, const_pointer _Last2)
		{	
		if (_First2 == _Last2)
			erase(_Pdif(_First, begin()), _Pdif(_Last, _First));
		else
			replace(_Pdif(_First, begin()), _Pdif(_Last, _First),
				&*_First2, _Last2 - _First2);
		return (*this);
		}

	_Myt& replace(const_iterator _First, const_iterator _Last,
		const_iterator _First2, const_iterator _Last2)
		{	
		if (_First2 == _Last2)
			erase(_Pdif(_First, begin()), _Pdif(_Last, _First));
		else
			replace(_Pdif(_First, begin()), _Pdif(_Last, _First),
				&*_First2, _Last2 - _First2);
		return (*this);
		}

	iterator begin()
		{	
		return (iterator(_Myptr(), this));
		}

	const_iterator begin() const
		{	
		return (const_iterator(_Myptr(), this));
		}

	iterator end()
		{	
		return (iterator(_Myptr() + this->_Mysize, this));
		}

	const_iterator end() const
		{	
		return (const_iterator(_Myptr() + this->_Mysize, this));
		}

	reverse_iterator rbegin()
		{	
		return (reverse_iterator(end()));
		}

	const_reverse_iterator rbegin() const
		{	
		return (const_reverse_iterator(end()));
		}

	reverse_iterator rend()
		{	
		return (reverse_iterator(begin()));
		}

	const_reverse_iterator rend() const
		{	
		return (const_reverse_iterator(begin()));
		}

 
	const_iterator cbegin() const
		{	
		return (((const _Myt *)this)->begin());
		}

	const_iterator cend() const
		{	
		return (((const _Myt *)this)->end());
		}

	const_reverse_iterator crbegin() const
		{	
		return (((const _Myt *)this)->rbegin());
		}

	const_reverse_iterator crend() const
		{	
		return (((const _Myt *)this)->rend());
		}

	void shrink_to_fit()
		{	
		if (size() < capacity())
			{	
			_Myt _Tmp(*this);
			swap(_Tmp);
			}
		}
 #line 1420 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

	reference at(size_type _Off)
		{	
		if (this->_Mysize <= _Off)
			_Xran();	
		return (_Myptr()[_Off]);
		}

	const_reference at(size_type _Off) const
		{	
		if (this->_Mysize <= _Off)
			_Xran();	
		return (_Myptr()[_Off]);
		}

	reference operator[](size_type _Off)
		{	
 





#line 1444 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

#line 1446 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		return (_Myptr()[_Off]);
		}

	const_reference operator[](size_type _Off) const
		{	
 



#line 1457 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

#line 1459 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		return (_Myptr()[_Off]);
		}

	void push_back(_Elem _Ch)
		{	
		insert(end(), _Ch);
		}

 
	void pop_back()
		{	
		erase(this->_Mysize - 1);	
		}

	reference front()
		{	
		return (*begin());
		}

	const_reference front() const
		{	
		return (*begin());
		}

	reference back()
		{	
		return (*(end() - 1));
		}

	const_reference back() const
		{	
		return (*(end() - 1));
		}
 #line 1494 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

	const _Elem *c_str() const
		{	
		return (_Myptr());
		}

	const _Elem *data() const
		{	
		return (c_str());
		}

	size_type length() const
		{	
		return (this->_Mysize);
		}

	size_type size() const
		{	
		return (this->_Mysize);
		}

	size_type max_size() const
		{	
		size_type _Num = this->_Alval.max_size();
		return (_Num <= 1 ? 1 : _Num - 1);
		}

	void resize(size_type _Newsize)
		{	
		resize(_Newsize, _Elem());
		}

	void resize(size_type _Newsize, _Elem _Ch)
		{	
		if (_Newsize <= this->_Mysize)
			erase(_Newsize);
		else
			append(_Newsize - this->_Mysize, _Ch);
		}

	size_type capacity() const
		{	
		return (this->_Myres);
		}

	void reserve(size_type _Newcap = 0)
		{	
		if (this->_Mysize <= _Newcap && this->_Myres != _Newcap)
			{	
			size_type _Size = this->_Mysize;
			if (_Grow(_Newcap, true))
				_Eos(_Size);
			}
		}

	bool empty() const
		{	
		return (this->_Mysize == 0);
		}

	

	size_type copy(_Elem *_Ptr,
		size_type _Count, size_type _Off = 0) const
		{	
 


#line 1563 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (this->_Mysize < _Off)
			_Xran();	
		if (this->_Mysize - _Off < _Count)
			_Count = this->_Mysize - _Off;
		_Traits::copy(_Ptr, _Myptr() + _Off, _Count);
		return (_Count);
		}

	size_type _Copy_s(_Elem *_Dest, size_type _Dest_size,
		size_type _Count, size_type _Off = 0) const
		{	
 


#line 1579 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (this->_Mysize < _Off)
			_Xran();	
		if (this->_Mysize - _Off < _Count)
			_Count = this->_Mysize - _Off;
		_Traits::_Copy_s(_Dest, _Dest_size, _Myptr() + _Off, _Count);
		return (_Count);
		}

	void swap(_Myt& _Right)
		{	
		if (this == &_Right)
			;	
		else if (this->_Alval == _Right._Alval)
			{	
 

#line 1597 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

			::std:: swap(this->_Bx, _Right._Bx);
			::std:: swap(this->_Mysize, _Right._Mysize);
			::std:: swap(this->_Myres, _Right._Myres);
			}
		else
			{	
			_Myt _Tmp = *this;

			*this = _Right;
			_Right = _Tmp;
			}
		}

	size_type find(const _Myt& _Right, size_type _Off = 0) const
		{	
		return (find(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	
 


#line 1623 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (_Count == 0 && _Off <= this->_Mysize)
			return (_Off);	

		size_type _Nm;
		if (_Off < this->_Mysize && _Count <= (_Nm = this->_Mysize - _Off))
			{	
			const _Elem *_Uptr, *_Vptr;
			for (_Nm -= _Count - 1, _Vptr = _Myptr() + _Off;
				(_Uptr = _Traits::find(_Vptr, _Nm, *_Ptr)) != 0;
				_Nm -= _Uptr - _Vptr + 1, _Vptr = _Uptr + 1)
				if (_Traits::compare(_Uptr, _Ptr, _Count) == 0)
					return (_Uptr - _Myptr());	
			}

		return (npos);	
		}

	size_type find(const _Elem *_Ptr, size_type _Off = 0) const
		{	
		;
		return (find(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find(_Elem _Ch, size_type _Off = 0) const
		{	
		return (find((const _Elem *)&_Ch, _Off, 1));
		}

	size_type rfind(const _Myt& _Right, size_type _Off = npos) const
		{	
		return (rfind(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type rfind(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	
 


#line 1664 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (_Count == 0)
			return (_Off < this->_Mysize ? _Off
				: this->_Mysize);	
		if (_Count <= this->_Mysize)
			{	
			const _Elem *_Uptr = _Myptr() +
				(_Off < this->_Mysize - _Count ? _Off
					: this->_Mysize - _Count);
			for (; ; --_Uptr)
				if (_Traits::eq(*_Uptr, *_Ptr)
					&& _Traits::compare(_Uptr, _Ptr, _Count) == 0)
					return (_Uptr - _Myptr());	
				else if (_Uptr == _Myptr())
					break;	
			}

		return (npos);	
		}

	size_type rfind(const _Elem *_Ptr, size_type _Off = npos) const
		{	
		;
		return (rfind(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type rfind(_Elem _Ch, size_type _Off = npos) const
		{	
		return (rfind((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_first_of(const _Myt& _Right,
		size_type _Off = 0) const
		{	
		return (find_first_of(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find_first_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	
 


#line 1708 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (0 < _Count && _Off < this->_Mysize)
			{	
			const _Elem *const _Vptr = _Myptr() + this->_Mysize;
			for (const _Elem *_Uptr = _Myptr() + _Off; _Uptr < _Vptr; ++_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) != 0)
					return (_Uptr - _Myptr());	
			}

		return (npos);	
		}

	size_type find_first_of(const _Elem *_Ptr, size_type _Off = 0) const
		{	
		;
		return (find_first_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_first_of(_Elem _Ch, size_type _Off = 0) const
		{	
		return (find((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_last_of(const _Myt& _Right,
		size_type _Off = npos) const
		{	
		return (find_last_of(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find_last_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	
 


#line 1744 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (0 < _Count && 0 < this->_Mysize)
			{	
			const _Elem *_Uptr = _Myptr()
				+ (_Off < this->_Mysize ? _Off : this->_Mysize - 1);
			for (; ; --_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) != 0)
					return (_Uptr - _Myptr());	
				else if (_Uptr == _Myptr())
					break;	
			}

		return (npos);	
		}

	size_type find_last_of(const _Elem *_Ptr,
		size_type _Off = npos) const
		{	
		;
		return (find_last_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_last_of(_Elem _Ch, size_type _Off = npos) const
		{	
		return (rfind((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_first_not_of(const _Myt& _Right,
		size_type _Off = 0) const
		{	
		return (find_first_not_of(_Right._Myptr(), _Off,
			_Right.size()));
		}

	size_type find_first_not_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	
 


#line 1785 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (_Off < this->_Mysize)
			{	
			const _Elem *const _Vptr = _Myptr() + this->_Mysize;
			for (const _Elem *_Uptr = _Myptr() + _Off; _Uptr < _Vptr; ++_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) == 0)
					return (_Uptr - _Myptr());
			}
		return (npos);
		}

	size_type find_first_not_of(const _Elem *_Ptr,
		size_type _Off = 0) const
		{	
		;
		return (find_first_not_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_first_not_of(_Elem _Ch, size_type _Off = 0) const
		{	
		return (find_first_not_of((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_last_not_of(const _Myt& _Right,
		size_type _Off = npos) const
		{	
		return (find_last_not_of(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find_last_not_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	
 


#line 1821 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (0 < this->_Mysize)
			{	
			const _Elem *_Uptr = _Myptr()
				+ (_Off < this->_Mysize ? _Off : this->_Mysize - 1);
			for (; ; --_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) == 0)
					return (_Uptr - _Myptr());
				else if (_Uptr == _Myptr())
					break;
			}
		return (npos);
		}

	size_type find_last_not_of(const _Elem *_Ptr,
		size_type _Off = npos) const
		{	
		;
		return (find_last_not_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_last_not_of(_Elem _Ch, size_type _Off = npos) const
		{	
		return (find_last_not_of((const _Elem *)&_Ch, _Off, 1));
		}

	_Myt substr(size_type _Off = 0, size_type _Count = npos) const
		{	
		return (_Myt(*this, _Off, _Count, get_allocator()));
		}

	int compare(const _Myt& _Right) const
		{	
		return (compare(0, this->_Mysize, _Right._Myptr(), _Right.size()));
		}

	int compare(size_type _Off, size_type _N0,
		const _Myt& _Right) const
		{	
		return (compare(_Off, _N0, _Right, 0, npos));
		}

	int compare(size_type _Off,
		size_type _N0, const _Myt& _Right,
		size_type _Roff, size_type _Count) const
		{	
		if (_Right.size() < _Roff)
			_Xran();	
		if (_Right._Mysize - _Roff < _Count)
			_Count = _Right._Mysize - _Roff;	
		return (compare(_Off, _N0, _Right._Myptr() + _Roff, _Count));
		}

	int compare(const _Elem *_Ptr) const
		{	
		;
		return (compare(0, this->_Mysize, _Ptr, _Traits::length(_Ptr)));
		}

	int compare(size_type _Off, size_type _N0, const _Elem *_Ptr) const
		{	
		;
		return (compare(_Off, _N0, _Ptr, _Traits::length(_Ptr)));
		}

	int compare(size_type _Off,
		size_type _N0, const _Elem *_Ptr, size_type _Count) const
		{	
 


#line 1893 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

		if (this->_Mysize < _Off)
			_Xran();	
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	

		size_type _Ans = _Traits::compare(_Myptr() + _Off, _Ptr,
			_N0 < _Count ? _N0 : _Count);
		return (_Ans != 0 ? (int)_Ans : _N0 < _Count ? -1
			: _N0 == _Count ? 0 : +1);
		}

	allocator_type get_allocator() const
		{	
		return (this->_Alval);
		}

	void _Chassign(size_type _Off, size_type _Count, _Elem _Ch)
		{	
		if (_Count == 1)
			_Traits::assign(*(_Myptr() + _Off), _Ch);
		else
			_Traits::assign(_Myptr() + _Off, _Count, _Ch);
		}

	void _Copy(size_type _Newsize, size_type _Oldlen)
		{	
		size_type _Newres = _Newsize | this->_ALLOC_MASK;
		if (max_size() < _Newres)
			_Newres = _Newsize;	
		else if (this->_Myres / 2 <= _Newres / 3)
			;
		else if (this->_Myres <= max_size() - this->_Myres / 2)
			_Newres = this->_Myres
				+ this->_Myres / 2;	
		else
			_Newres = max_size();	

		_Elem *_Ptr;
		try {
			_Ptr = this->_Alval.allocate(_Newres + 1);
		} catch (...) {
			_Newres = _Newsize;	
			try {
				_Ptr = this->_Alval.allocate(_Newres + 1);
			} catch (...) {
			_Tidy(true);	
			throw;
			}
		}

		if (0 < _Oldlen)
			_Traits::copy(_Ptr, _Myptr(), _Oldlen);	
		_Tidy(true);
		this->_Bx._Ptr = _Ptr;
		this->_Myres = _Newres;
		_Eos(_Oldlen);
		}

	void _Eos(size_type _Newsize)
		{	
		_Traits::assign(_Myptr()[this->_Mysize = _Newsize], _Elem());
		}

	bool _Grow(size_type _Newsize,
		bool _Trim = false)
		{	
		if (max_size() < _Newsize)
			_Xlen();	
		if (this->_Myres < _Newsize)
			_Copy(_Newsize, this->_Mysize);	
		else if (_Trim && _Newsize < this->_BUF_SIZE)
			_Tidy(true,	
				_Newsize < this->_Mysize ? _Newsize : this->_Mysize);
		else if (_Newsize == 0)
			_Eos(0);	
		return (0 < _Newsize);	
		}

	bool _Inside(const _Elem *_Ptr)
		{	
		if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + this->_Mysize <= _Ptr)
			return (false);	
		else
			return (true);
		}

	static size_type _Pdif(const_iterator _P2,
		const_iterator _P1)
		{	
		return ((_P2)._Ptr == 0 ? 0 : _P2 - _P1);
		}

	void _Tidy(bool _Built = false,
		size_type _Newsize = 0)
		{	
		if (!_Built)
			;
		else if (this->_BUF_SIZE <= this->_Myres)
			{	
			_Elem *_Ptr = this->_Bx._Ptr;
			if (0 < _Newsize)
				_Traits::copy(this->_Bx._Buf, _Ptr, _Newsize);
			this->_Alval.deallocate(_Ptr, this->_Myres + 1);
			}
		this->_Myres = this->_BUF_SIZE - 1;
		_Eos(_Newsize);
		}

	_Elem *_Myptr()
		{	
		return (this->_BUF_SIZE <= this->_Myres ? this->_Bx._Ptr
			: this->_Bx._Buf);
		}

	const _Elem *_Myptr() const
		{	
		return (this->_BUF_SIZE <= this->_Myres ? this->_Bx._Ptr
			: this->_Bx._Buf);
		}

	__declspec(noreturn) void _Xlen() const
		{	
		_Xlength_error("string too long");
		}

	__declspec(noreturn) void _Xran() const
		{	
		_Xout_of_range("invalid string position");
		}
	};

		
template<class _Elem,
	class _Traits,
	class _Alloc>
	 const typename basic_string<_Elem, _Traits, _Alloc>::size_type
		basic_string<_Elem, _Traits, _Alloc>::npos =
			(typename basic_string<_Elem, _Traits, _Alloc>::size_type)(-1);

		

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	void swap(basic_string<_Elem, _Traits, _Alloc>& _Left,
		basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	void swap(basic_string<_Elem, _Traits, _Alloc>& _Left,
		basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	void swap(basic_string<_Elem, _Traits, _Alloc>&& _Left,
		basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	_Right.swap(_Left);
	}

typedef basic_string<char, char_traits<char>, allocator<char> >
	string;
typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >
	wstring;

 
typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t> >
	u16string;
typedef basic_string<char32_t, char_traits<char32_t>, allocator<char32_t> >
	u32string;
 #line 2073 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 2079 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"
#line 2080 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"






#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

 #pragma pack(push,8)
 #pragma warning(push,3)

 #pragma warning(disable: 4100 4180 4244)

 
  
 #line 17 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

namespace std {
		
template<class _Ty>
	struct plus
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left + _Right);
		}
	};

		
template<class _Ty>
	struct minus
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left - _Right);
		}
	};

		
template<class _Ty>
	struct multiplies
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left * _Right);
		}
	};

		
template<class _Ty>
	struct divides
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left / _Right);
		}
	};

		
template<class _Ty>
	struct modulus
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left % _Right);
		}
	};

		
template<class _Ty>
	struct negate
		: public unary_function<_Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left) const
		{	
		return (-_Left);
		}
	};

		
template<class _Ty>
	struct equal_to
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left == _Right);
		}
	};

		
template<class _Ty>
	struct not_equal_to
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left != _Right);
		}
	};

		
template<class _Ty>
	struct greater
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left > _Right);
		}
	};

		
template<class _Ty>
	struct less
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left < _Right);
		}
	};

		
template<class _Ty>
	struct greater_equal
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left >= _Right);
		}
	};

		
template<class _Ty>
	struct less_equal
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left <= _Right);
		}
	};

		
template<class _Ty>
	struct logical_and
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left && _Right);
		}
	};

		
template<class _Ty>
	struct logical_or
		: public binary_function<_Ty, _Ty, bool>
	{	
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left || _Right);
		}
	};

		
template<class _Ty>
	struct logical_not
		: public unary_function<_Ty, bool>
	{	
	bool operator()(const _Ty& _Left) const
		{	
		return (!_Left);
		}
	};

 
		
template<class _Ty>
	struct bit_and
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left & _Right);
		}
	};

		
template<class _Ty>
	struct bit_or
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left | _Right);
		}
	};

		
template<class _Ty>
	struct bit_xor
		: public binary_function<_Ty, _Ty, _Ty>
	{	
	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	
		return (_Left ^ _Right);
		}
	};
 #line 218 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

		
template<class _Fn1>
	class unary_negate
	: public unary_function<typename _Fn1::argument_type, bool>
	{	
public:
	explicit unary_negate(const _Fn1& _Func)
		: _Functor(_Func)
		{	
		}

	bool operator()(const typename _Fn1::argument_type& _Left) const
		{	
		return (!_Functor(_Left));
		}

protected:
	_Fn1 _Functor;	
	};

		
template<class _Fn1> inline
	unary_negate<_Fn1> not1(const _Fn1& _Func)
	{	
	return (::std:: unary_negate<_Fn1>(_Func));
	}

		
template<class _Fn2>
	class binary_negate
		: public binary_function<typename _Fn2::first_argument_type,
			typename _Fn2::second_argument_type, bool>
	{	
public:
	explicit binary_negate(const _Fn2& _Func)
		: _Functor(_Func)
		{	
		}

	bool operator()(const typename _Fn2::first_argument_type& _Left,
		const typename _Fn2::second_argument_type& _Right) const
		{	
		return (!_Functor(_Left, _Right));
		}

protected:
	_Fn2 _Functor;	
	};

		
template<class _Fn2> inline
	binary_negate<_Fn2> not2(const _Fn2& _Func)
	{	
	return (::std:: binary_negate<_Fn2>(_Func));
	}

		
template<class _Fn2>
	class binder1st
		: public unary_function<typename _Fn2::second_argument_type,
			typename _Fn2::result_type>
	{	
public:
	typedef unary_function<typename _Fn2::second_argument_type,
		typename _Fn2::result_type> _Base;
	typedef typename _Base::argument_type argument_type;
	typedef typename _Base::result_type result_type;

	binder1st(const _Fn2& _Func,
		const typename _Fn2::first_argument_type& _Left)
		: op(_Func), value(_Left)
		{	
		}

	result_type operator()(const argument_type& _Right) const
		{	
		return (op(value, _Right));
		}

	result_type operator()(argument_type& _Right) const
		{	
		return (op(value, _Right));
		}

protected:
	_Fn2 op;	
	typename _Fn2::first_argument_type value;	
	};

		
template<class _Fn2,
	class _Ty> inline
	binder1st<_Fn2> bind1st(const _Fn2& _Func, const _Ty& _Left)
		{	
		typename _Fn2::first_argument_type _Val(_Left);
		return (::std:: binder1st<_Fn2>(_Func, _Val));
		}

		
template<class _Fn2>
	class binder2nd
		: public unary_function<typename _Fn2::first_argument_type,
			typename _Fn2::result_type>
	{	
public:
	typedef unary_function<typename _Fn2::first_argument_type,
		typename _Fn2::result_type> _Base;
	typedef typename _Base::argument_type argument_type;
	typedef typename _Base::result_type result_type;

	binder2nd(const _Fn2& _Func,
		const typename _Fn2::second_argument_type& _Right)
		: op(_Func), value(_Right)
		{	
		}

	result_type operator()(const argument_type& _Left) const
		{	
		return (op(_Left, value));
		}

	result_type operator()(argument_type& _Left) const
		{	
		return (op(_Left, value));
		}

protected:
	_Fn2 op;	
	typename _Fn2::second_argument_type value;	
	};

		
template<class _Fn2,
	class _Ty> inline
	binder2nd<_Fn2> bind2nd(const _Fn2& _Func, const _Ty& _Right)
	{	
	typename _Fn2::second_argument_type _Val(_Right);
	return (::std:: binder2nd<_Fn2>(_Func, _Val));
	}

		
template<class _Arg,
	class _Result,
	class _Fn = _Result (*)(_Arg)>
	class pointer_to_unary_function
		: public unary_function<_Arg, _Result>
	{	
public:
	explicit pointer_to_unary_function(_Fn _Left)
		: _Pfun(_Left)
		{	
		}

	_Result operator()(_Arg _Left) const
		{	
		return (_Pfun(_Left));
		}

protected:
	_Fn _Pfun;	
	};

		
template<class _Arg1,
	class _Arg2,
	class _Result,
	class _Fn = _Result (*)(_Arg1, _Arg2)>
	class pointer_to_binary_function
		: public binary_function<_Arg1, _Arg2, _Result>
	{	
public:
	explicit pointer_to_binary_function(_Fn _Left)
		: _Pfun(_Left)
		{	
		}

	_Result operator()(_Arg1 _Left, _Arg2 _Right) const
		{	
		return (_Pfun(_Left, _Right));
		}

protected:
	_Fn _Pfun;	
	};

		
template<class _Arg,
	class _Result> inline
	pointer_to_unary_function<_Arg, _Result,
		_Result (__cdecl *)(_Arg)>
		ptr_fun(_Result (__cdecl *_Left)(_Arg))
	{	
	return (pointer_to_unary_function<_Arg, _Result,
		_Result (__cdecl *)(_Arg)>(_Left));
	}

 
template<class _Arg,
	class _Result> inline
	pointer_to_unary_function<_Arg, _Result,
		_Result (__stdcall *)(_Arg)>
			ptr_fun(_Result (__stdcall *_Left)(_Arg))
	{	
	return (pointer_to_unary_function<_Arg, _Result,
		_Result (__stdcall *)(_Arg)>(_Left));
	}

  
template<class _Arg,
	class _Result> inline
	pointer_to_unary_function<_Arg, _Result,
		_Result (__fastcall *)(_Arg)>
			ptr_fun(_Result (__fastcall *_Left)(_Arg))
	{	
	return (pointer_to_unary_function<_Arg, _Result,
		_Result (__fastcall *)(_Arg)>(_Left));
	}
  #line 437 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

 #line 439 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

 











template<class _Arg1,
	class _Arg2,
	class _Result> inline
	pointer_to_binary_function<_Arg1, _Arg2, _Result,
		_Result (__cdecl *)(_Arg1, _Arg2)>
		ptr_fun(_Result (__cdecl *_Left)(_Arg1, _Arg2))
	{	
	return (pointer_to_binary_function<_Arg1, _Arg2, _Result,
		_Result (__cdecl *)(_Arg1, _Arg2)>(_Left));
	}

 
template<class _Arg1,
	class _Arg2,
	class _Result> inline
	pointer_to_binary_function<_Arg1, _Arg2, _Result,
		_Result(__stdcall *)(_Arg1, _Arg2)>
			ptr_fun(_Result (__stdcall *_Left)(_Arg1, _Arg2))
	{	
	return (pointer_to_binary_function<_Arg1, _Arg2, _Result,
		_Result (__stdcall *)(_Arg1, _Arg2)>(_Left));
	}

  
template<class _Arg1,
	class _Arg2,
	class _Result> inline
	pointer_to_binary_function<_Arg1, _Arg2, _Result,
		_Result(__fastcall *)(_Arg1, _Arg2)>
			ptr_fun(_Result (__fastcall *_Left)(_Arg1, _Arg2))
	{	
	return (pointer_to_binary_function<_Arg1, _Arg2, _Result,
		_Result (__fastcall *)(_Arg1, _Arg2)>(_Left));
	}
  #line 487 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

 #line 489 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"

 












		
template<class _Result,
	class _Ty>
	class mem_fun_t
		: public unary_function<_Ty *, _Result>
	{	
public:
	explicit mem_fun_t(_Result (_Ty::*_Pm)())
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(_Ty *_Pleft) const
		{	
		return ((_Pleft->*_Pmemfun)());
		}

private:
	_Result (_Ty::*_Pmemfun)();	
	};

		
template<class _Result,
	class _Ty,
	class _Arg>
	class mem_fun1_t
		: public binary_function<_Ty *, _Arg, _Result>
	{	
public:
	explicit mem_fun1_t(_Result (_Ty::*_Pm)(_Arg))
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(_Ty *_Pleft, _Arg _Right) const
		{	
		return ((_Pleft->*_Pmemfun)(_Right));
		}

private:
	_Result (_Ty::*_Pmemfun)(_Arg);	
	};

		
template<class _Result,
	class _Ty>
	class const_mem_fun_t
		: public unary_function<const _Ty *, _Result>
	{	
public:
	explicit const_mem_fun_t(_Result (_Ty::*_Pm)() const)
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(const _Ty *_Pleft) const
		{	
		return ((_Pleft->*_Pmemfun)());
		}

private:
	_Result (_Ty::*_Pmemfun)() const;	
	};

		
template<class _Result,
	class _Ty,
	class _Arg>
	class const_mem_fun1_t
		: public binary_function<const _Ty *, _Arg, _Result>
	{	
public:
	explicit const_mem_fun1_t(_Result (_Ty::*_Pm)(_Arg) const)
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(const _Ty *_Pleft, _Arg _Right) const
		{	
		return ((_Pleft->*_Pmemfun)(_Right));
		}

private:
	_Result (_Ty::*_Pmemfun)(_Arg) const;	
	};

		
template<class _Result,
	class _Ty> inline
	mem_fun_t<_Result, _Ty> mem_fun(_Result (_Ty::*_Pm)())
	{	
	return (mem_fun_t<_Result, _Ty>(_Pm));
	}

template<class _Result,
	class _Ty,
	class _Arg> inline
	mem_fun1_t<_Result, _Ty, _Arg> mem_fun(_Result (_Ty::*_Pm)(_Arg))
	{	
	return (mem_fun1_t<_Result, _Ty, _Arg>(_Pm));
	}

template<class _Result,
	class _Ty> inline
	const_mem_fun_t<_Result, _Ty>
		mem_fun(_Result (_Ty::*_Pm)() const)
	{	
	return (const_mem_fun_t<_Result, _Ty>(_Pm));
	}

template<class _Result,
	class _Ty,
	class _Arg> inline
	const_mem_fun1_t<_Result, _Ty, _Arg>
		mem_fun(_Result (_Ty::*_Pm)(_Arg) const)
	{	
	return (const_mem_fun1_t<_Result, _Ty, _Arg>(_Pm));
	}

		
template<class _Result,
	class _Ty,
	class _Arg> inline
	mem_fun1_t<_Result, _Ty, _Arg> mem_fun1(_Result (_Ty::*_Pm)(_Arg))
	{	
	return (mem_fun1_t<_Result, _Ty, _Arg>(_Pm));
	}

		
template<class _Result,
	class _Ty>
	class mem_fun_ref_t
		: public unary_function<_Ty, _Result>
	{	
public:
	explicit mem_fun_ref_t(_Result (_Ty::*_Pm)())
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(_Ty& _Left) const
		{	
		return ((_Left.*_Pmemfun)());
		}

private:
	_Result (_Ty::*_Pmemfun)();	
	};

		
template<class _Result,
	class _Ty,
	class _Arg>
	class mem_fun1_ref_t
		: public binary_function<_Ty, _Arg, _Result>
	{	
public:
	explicit mem_fun1_ref_t(_Result (_Ty::*_Pm)(_Arg))
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(_Ty& _Left, _Arg _Right) const
		{	
		return ((_Left.*_Pmemfun)(_Right));
		}

private:
	_Result (_Ty::*_Pmemfun)(_Arg);	
	};

		
template<class _Result,
	class _Ty>
	class const_mem_fun_ref_t
		: public unary_function<_Ty, _Result>
	{	
public:
	explicit const_mem_fun_ref_t(_Result (_Ty::*_Pm)() const)
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(const _Ty& _Left) const
		{	
		return ((_Left.*_Pmemfun)());
		}

private:
	_Result (_Ty::*_Pmemfun)() const;	
	};

		
template<class _Result,
	class _Ty,
	class _Arg>
	class const_mem_fun1_ref_t
		: public binary_function<_Ty, _Arg, _Result>
	{	
public:
	explicit const_mem_fun1_ref_t(_Result (_Ty::*_Pm)(_Arg) const)
		: _Pmemfun(_Pm)
		{	
		}

	_Result operator()(const _Ty& _Left, _Arg _Right) const
		{	
		return ((_Left.*_Pmemfun)(_Right));
		}

private:
	_Result (_Ty::*_Pmemfun)(_Arg) const;	
	};

		
template<class _Result,
	class _Ty> inline
	mem_fun_ref_t<_Result, _Ty> mem_fun_ref(_Result (_Ty::*_Pm)())
	{	
	return (mem_fun_ref_t<_Result, _Ty>(_Pm));
	}

template<class _Result,
	class _Ty,
	class _Arg> inline
	mem_fun1_ref_t<_Result, _Ty, _Arg>
		mem_fun_ref(_Result (_Ty::*_Pm)(_Arg))
	{	
	return (mem_fun1_ref_t<_Result, _Ty, _Arg>(_Pm));
	}

template<class _Result,
	class _Ty> inline
	const_mem_fun_ref_t<_Result, _Ty>
		mem_fun_ref(_Result (_Ty::*_Pm)() const)
	{	
	return (const_mem_fun_ref_t<_Result, _Ty>(_Pm));
	}

template<class _Result,
	class _Ty,
	class _Arg> inline
	const_mem_fun1_ref_t<_Result, _Ty, _Arg>
		mem_fun_ref(_Result (_Ty::*_Pm)(_Arg) const)
	{	
	return (const_mem_fun1_ref_t<_Result, _Ty, _Arg>(_Pm));
	}

		
template<class _Result,
	class _Ty,
	class _Arg> inline
	mem_fun1_ref_t<_Result, _Ty, _Arg> mem_fun1_ref(_Result (_Ty::*_Pm)(_Arg))
	{	
	return (mem_fun1_ref_t<_Result, _Ty, _Arg>(_Pm));
	}

	
template<class _Kty>
	class hash
		: public unary_function<_Kty, size_t>
	{	
public:
	size_t operator()(const _Kty& _Keyval) const
		{	
		ldiv_t _Qrem = :: ldiv((long)(size_t)_Keyval, 127773);

		_Qrem.rem = 16807 * _Qrem.rem - 2836 * _Qrem.quot;
		if (_Qrem.rem < 0)
			_Qrem.rem += 2147483647;
		return ((size_t)_Qrem.rem);
		}
	};

template<>
	class hash<_ULonglong>
		: public unary_function<_ULonglong, size_t>
	{	
public:
	typedef _ULonglong _Kty;
	typedef _Uint32t _Inttype;	

	size_t operator()(const _Kty& _Keyval) const
		{	
		return (hash<_Inttype>()((_Inttype)(_Keyval & 0xffffffffUL))
			^ hash<_Inttype>()((_Inttype)(_Keyval >> 32)));
		}
	};

template<>
	class hash<_Longlong>
		: public unary_function<_Longlong, size_t>
	{	
public:
	typedef _Longlong _Kty;
	typedef _Uint32t _Inttype;	

	size_t operator()(const _Kty& _Keyval) const
		{	
		return (hash<_ULonglong>()((_ULonglong)_Keyval));
		}
	};

template<class _Ty>
	class hash<_Ty *>
		: public unary_function<_Ty *, size_t>
	{	
public:
	typedef _Ty *_Kty;
	typedef _Uint32t _Inttype;	

	size_t operator()(_Kty _Keyval) const
		{	
		typedef typename ::std:: _If<sizeof (_Ty *) <= sizeof (_Inttype),
			_Inttype, _ULonglong>::_Type _Integer;
		return (hash<_Integer>()((_Integer)_Keyval));
		}
	};

template<>
	class hash<float>
		: public unary_function<float, size_t>
	{	
public:
	typedef float _Kty;
	typedef _Uint32t _Inttype;	

	size_t operator()(const _Kty& _Keyval) const
		{	
		_Inttype _Bits = *(_Inttype *)&_Keyval;
		return (hash<_Inttype>()(_Bits == 0x80000000 ? 0 : _Bits));
		}
	};

template<>
	class hash<double>
		: public unary_function<double, size_t>
	{	
public:
	typedef double _Kty;
	typedef _ULonglong _Inttype;	

	size_t operator()(const _Kty& _Keyval) const
		{	
		_Inttype _Bits = *(_Inttype *)&_Keyval;
		return (hash<_Inttype>()(
			(_Bits & (0xffffffffffffffff >> 1)) == 0 ? 0 : _Bits));
		}
	};

template<>
	class hash<long double>
		: public unary_function<long double, size_t>
	{	
public:
	typedef long double _Kty;
	typedef _ULonglong _Inttype;	

	size_t operator()(const _Kty& _Keyval) const
		{	
		_Inttype _Bits = *(_Inttype *)&_Keyval;
		return (hash<_Inttype>()(
			(_Bits & (0xffffffffffffffff >> 1)) == 0 ? 0 : _Bits));
		}
	};

template<>
	class hash<::std:: string>
		: public unary_function<::std:: string, size_t>
	{	
public:
	typedef ::std:: string _Kty;

	size_t operator()(const _Kty& _Keyval) const
		{	
		size_t _Val = 2166136261U;
		size_t _First = 0;
		size_t _Last = _Keyval.size();
		size_t _Stride = 1 + _Last / 10;

		for(; _First < _Last; _First += _Stride)
			_Val = 16777619U * _Val ^ (size_t)_Keyval[_First];
		return (_Val);
		}
	};

template<>
	class hash<::std:: wstring>
		: public unary_function<::std:: wstring, size_t>
	{	
public:
	typedef ::std:: wstring _Kty;

	size_t operator()(const _Kty& _Keyval) const
		{	
		size_t _Val = 2166136261U;
		size_t _First = 0;
		size_t _Last = _Keyval.size();
		size_t _Stride = 1 + _Last / 10;

		for(; _First < _Last; _First += _Stride)
			_Val = 16777619U * _Val ^ (size_t)_Keyval[_First];
		return (_Val);
		}
	};

	namespace tr1 {
using ::std:: hash;
	}	
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 918 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"
#line 919 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfunctional"






















#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

#pragma once





 #pragma pack(push,8)
 #pragma warning(push,3)

 
 

 #pragma warning(disable: 4700)

namespace std {
		
template<class _Ty> inline
	pair<_Ty  *, ptrdiff_t>

		get_temporary_buffer(ptrdiff_t _Count)

	{	
	_Ty  *_Pbuf;

	if (_Count < 0)
		_Count = 0;
	else if (((size_t)(-1) / sizeof (_Ty) < _Count))
		throw bad_alloc(0);
	for (_Pbuf = 0; 0 < _Count; _Count /= 2)
		if ((_Pbuf = (_Ty  *)operator new(
			(size_t)_Count * sizeof (_Ty), nothrow)) != 0)
			break;

	return (pair<_Ty  *, ptrdiff_t>(_Pbuf, _Count));
	}

		
template<class _Ty> inline
	void return_temporary_buffer(_Ty *_Pbuf)
	{	
	operator delete(_Pbuf);
	}

		
template<class _InIt,
	class _Diff,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy_n(_InIt _First, _Diff _Count,
		_FwdIt _Dest, input_iterator_tag)
	{	
	_FwdIt _Next = _Dest;

	try {
	_Construct(&*_Dest, *_First);	
	while (0 < --_Count)
		_Construct(&*++_Dest, *++_First);
	} catch (...) {
	for (; _Next != _Dest; ++_Next)
		_Destroy(&*_Next);
	throw;
	}
	return (++_Dest);
	}

template<class _InIt,
	class _Diff,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy_n(_InIt _First, _Diff _Count,
		_FwdIt _Dest, forward_iterator_tag)
	{	
	_FwdIt _Next = _Dest;

	try {
	for (; 0 < _Count; --_Count, ++_Dest, ++_First)
		_Construct(&*_Dest, *_First);
	} catch (...) {
	for (; _Next != _Dest; ++_Next)
		_Destroy(&*_Next);
	throw;
	}
	return (_Dest);
	}

template<class _InIt,
	class _Diff,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy_n(_InIt _First, _Diff _Count,
		_FwdIt _Dest, _Nonscalar_ptr_iterator_tag)
	{	
	return (_Uninitialized_copy_n(_First, _Count,
		_Dest, _Iter_cat(_First)));
	}

template<class _InIt,
	class _Diff,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy_n(_InIt _First, _Diff _Count,
		_FwdIt _Dest, _Scalar_ptr_iterator_tag)
	{	
	:: memmove(&*_Dest, &*_First,
		_Count * sizeof (*_First));
	return (_Dest + _Count);
	}

template<class _InIt,
	class _Diff,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy_n(_InIt _First, _Diff _Count,
		_FwdIt _Dest)
	{	
	return (_Uninitialized_copy_n(_First, _Count,
		_Dest, _Ptr_cat(_First, _Dest)));
	}

 
template<class _InIt,
	class _Diff,
	class _FwdIt> inline
	_FwdIt uninitialized_copy_n(_InIt _First, _Diff _Count,
		_FwdIt _Dest)
	{	
	if (_Count <= 0)
		return (_Dest);
	else
		return (_Rechecked(_Dest,
			_Uninitialized_copy_n(_First, _Count,
				_Unchecked(_Dest))));
	}

 




















































































































#line 249 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

		
template<class _InIt,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy0(_InIt _First, _InIt _Last,
		_FwdIt _Dest, _Nonscalar_ptr_iterator_tag)
	{	
	_FwdIt _Next = _Dest;

	try {
	for (; _First != _Last; ++_Dest, ++_First)
		_Construct(&*_Dest, *_First);
	} catch (...) {
	for (; _Next != _Dest; ++_Next)
		_Destroy(&*_Next);
	throw;
	}
	return (_Dest);
	}

template<class _InIt,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy0(_InIt _First, _InIt _Last,
		_FwdIt _Dest, _Scalar_ptr_iterator_tag)
	{	
	ptrdiff_t _Count = _Last - _First;
	:: memmove(&*_Dest, &*_First,
		_Count * sizeof (*_First));
	return (_Dest + _Count);
	}

template<class _InIt,
	class _FwdIt> inline
	_FwdIt _Uninitialized_copy0(_InIt _First, _InIt _Last,
		_FwdIt _Dest)
	{	
	return (_Uninitialized_copy0(_First, _Last,
		_Dest, _Ptr_cat(_First, _Dest)));
	}

 
template<class _InIt,
	class _FwdIt> inline
	_FwdIt uninitialized_copy(_InIt _First, _InIt _Last,
		_FwdIt _Dest)
	{	
	return (_Rechecked(_Dest,
		_Uninitialized_copy0(_Unchecked(_First), _Unchecked(_Last),
			_Unchecked(_Dest))));
	}

 




























































#line 362 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

		
template<class _InIt,
	class _FwdIt,
	class _Alloc> inline
	_FwdIt _Uninit_copy(_InIt _First, _InIt _Last, _FwdIt _Dest,
		_Alloc& _Al, _Nonscalar_ptr_iterator_tag)
	{	
	;
	;
	_FwdIt _Next = _Dest;

	try {
	for (; _First != _Last; ++_Dest, ++_First)
		_Cons_val(_Al, _Dest, *_First);
	} catch (...) {
	for (; _Next != _Dest; ++_Next)
		_Dest_val(_Al, _Next);
	throw;
	}
	return (_Dest);
	}

template<class _InIt,
	class _FwdIt,
	class _Alloc> inline
	_FwdIt _Uninit_copy(_InIt _First, _InIt _Last, _FwdIt _Dest,
		_Alloc& _Al, _Scalar_ptr_iterator_tag)
	{	
	return (_Uninit_copy(_First, _Last, _Dest,
		_Al, _Nonscalar_ptr_iterator_tag()));
	}

template<class _Ty1,
	class _Ty2> inline
	_Ty2 *_Uninit_copy(_Ty1 *_First, _Ty1 *_Last, _Ty2 *_Dest,
		allocator<_Ty2>&, _Scalar_ptr_iterator_tag)
	{	
	;
	;
	size_t _Count = (size_t)(_Last - _First);
	return ((_Ty2 *):: memmove(&*_Dest, &*_First,
		_Count * sizeof (*_First)) + _Count);	
	}

template<class _InIt,
	class _FwdIt,
	class _Alloc> inline
	_FwdIt _Uninitialized_copy(_InIt _First, _InIt _Last, _FwdIt _Dest,
		_Alloc& _Al)
	{	
	return (_Uninit_copy(_First, _Last, _Dest, _Al,
		_Ptr_cat(_First, _Dest)));
	}

		
template<class _InIt,
	class _FwdIt,
	class _Alloc,
	class _Valty> inline
	_FwdIt _Uninit_move(_InIt _First, _InIt _Last, _FwdIt _Dest,
		_Alloc& _Al, _Valty *, _Nonscalar_ptr_iterator_tag)
	{	
	;
	;
	_FwdIt _Next = _Dest;

	try {
	for (; _First != _Last; ++_Dest, ++_First)
		_Cons_val(_Al, _Dest, (_Valty &&)*_First);
	} catch (...) {
	for (; _Next != _Dest; ++_Next)
		_Dest_val(_Al, _Next);
	throw;
	}
	return (_Dest);
	}

template<class _InIt,
	class _FwdIt,
	class _Alloc,
	class _Valty> inline
	_FwdIt _Uninit_move(_InIt _First, _InIt _Last, _FwdIt _Dest,
		_Alloc& _Al, _Valty *, _Scalar_ptr_iterator_tag)
	{	
	return (_Uninit_move(_First, _Last, _Dest,
		_Al, (_Valty *)0, _Nonscalar_ptr_iterator_tag()));
	}

template<class _Ty1,
	class _Ty2,
	class _Valty> inline
	_Ty2 *_Uninit_move(_Ty1 *_First, _Ty1 *_Last, _Ty2 *_Dest,
		allocator<_Ty2>&, _Valty *, _Scalar_ptr_iterator_tag)
	{	
	;
	;
	size_t _Count = (size_t)(_Last - _First);
	return ((_Ty2 *):: memmove(&*_Dest, &*_First,
		_Count * sizeof (*_First)) + _Count);	
	}

template<class _InIt,
	class _FwdIt,
	class _Alloc> inline
	_FwdIt _Uninitialized_move(_InIt _First, _InIt _Last, _FwdIt _Dest,
		_Alloc& _Al)
	{	
	return (_Uninit_move(_First, _Last, _Dest, _Al,
		_Val_type(_First), _Ptr_cat(_First, _Dest)));
	}

		
template<class _FwdIt,
	class _Tval> inline
	void _Uninit_fill(_FwdIt _First, _FwdIt _Last, const _Tval& _Val,
		_Nonscalar_ptr_iterator_tag)
	{	
	;
	_FwdIt _Next = _First;

	try {
	for (; _First != _Last; ++_First)
		_Construct(&*_First, _Val);
	} catch (...) {
	for (; _Next != _First; ++_Next)
		_Destroy(&*_Next);
	throw;
	}
	}

template<class _Ty,
	class _Tval> inline
	void _Uninit_fill(_Ty *_First, _Ty *_Last, const _Tval& _Val,
		_Scalar_ptr_iterator_tag)
	{	
	::std:: fill(_First, _Last, _Val);
	}

template<class _FwdIt,
	class _Tval> inline
	void uninitialized_fill(_FwdIt _First, _FwdIt _Last, const _Tval& _Val)
	{	
	_Uninit_fill(_First, _Last, _Val, _Ptr_cat(_First, _First));
	}

		
template<class _FwdIt,
	class _Diff,
	class _Tval> inline
	void _Uninit_fill_n(_FwdIt _First, _Diff _Count, const _Tval& _Val,
		_Nonscalar_ptr_iterator_tag)
	{	
 


#line 519 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	_FwdIt _Next = _First;

	try {
	for (; 0 < _Count; --_Count, ++_First)
		_Construct(&*_First, _Val);
	} catch (...) {
	for (; _Next != _First; ++_Next)
		_Destroy(&*_Next);
	throw;
	}
	}

template<class _Ty,
	class _Diff,
	class _Tval> inline
	void _Uninit_fill_n(_Ty *_First, _Diff _Count, const _Tval& _Val,
		_Scalar_ptr_iterator_tag)
	{	
	::std:: _Fill_n(_First, _Count, _Val);
	}

template<class _FwdIt,
	class _Diff,
	class _Tval> inline
	void uninitialized_fill_n(_FwdIt _First, _Diff _Count, const _Tval& _Val)
	{	
	_Uninit_fill_n(_First, _Count, _Val, _Ptr_cat(_First, _First));
	}

		
template<class _FwdIt,
	class _Diff,
	class _Tval,
	class _Alloc,
	class _Valty> inline
	void _Uninit_fill_n(_FwdIt _First, _Diff _Count,
		const _Tval *_Pval, _Alloc& _Al,
			_Valty *, _Nonscalar_ptr_iterator_tag)
	{	
 


#line 563 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	_FwdIt _Next = _First;

	try {
	for (; 0 < _Count; --_Count, ++_First)
		_Cons_val(_Al, _First, *_Pval);
	} catch (...) {
	for (; _Next != _First; ++_Next)
		_Dest_val(_Al, _Next);
	throw;
	}
	}

template<class _FwdIt,
	class _Diff,
	class _Tval,
	class _Alloc,
	class _Valty> inline
	void _Uninit_fill_n(_FwdIt _First, _Diff _Count,
		const _Tval *_Pval, _Alloc& _Al,
			_Valty *, _Scalar_ptr_iterator_tag)
	{	
	_Uninit_fill_n(_First, _Count,
		_Pval, _Al, (_Valty *)0, _Nonscalar_ptr_iterator_tag());
	}

template<class _Ty,
	class _Diff,
	class _Tval,
	class _Valty> inline
	void _Uninit_fill_n(_Ty *_First, _Diff _Count,
		const _Tval *_Pval, allocator<_Ty>&,
			_Valty *, _Scalar_ptr_iterator_tag)
	{	
	_Fill_n(_First, _Count, *_Pval);
	}

template<class _FwdIt,
	class _Diff,
	class _Tval,
	class _Alloc> inline
	void _Uninitialized_fill_n(_FwdIt _First, _Diff _Count,
		const _Tval *_Pval, _Alloc& _Al)
	{	
	_Uninit_fill_n(_First, _Count, _Pval, _Al,
		_Val_type(_First), _Ptr_cat(_First, _First));
	}

		
template<class _FwdIt,
	class _Diff,
	class _Tval,
	class _Alloc,
	class _Valty> inline
	void _Uninit_def_fill_n(_FwdIt _First, _Diff _Count,
		const _Tval *, _Alloc& _Al,
			_Valty *, _Nonscalar_ptr_iterator_tag)
	{	
 


#line 625 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	_FwdIt _Next = _First;

	try {
	for (; 0 < _Count; --_Count, ++_First)

		_Cons_val(_Al, _First, _Valty());

	} catch (...) {
	for (; _Next != _First; ++_Next)
		_Dest_val(_Al, _Next);
	throw;
	}
	}

template<class _FwdIt,
	class _Diff,
	class _Tval,
	class _Alloc,
	class _Valty> inline
	void _Uninit_def_fill_n(_FwdIt _First, _Diff _Count,
		const _Tval *_Pval, _Alloc& _Al,
			_Valty *, _Scalar_ptr_iterator_tag)
	{	
	_Uninit_def_fill_n(_First, _Count,
		_Pval, _Al, (_Valty *)0, _Nonscalar_ptr_iterator_tag());
	}

template<class _Ty,
	class _Diff,
	class _Tval,
	class _Valty> inline
	void _Uninit_def_fill_n(_Ty *_First, _Diff _Count,
		const _Tval *, allocator<_Ty>&,
			_Valty *, _Scalar_ptr_iterator_tag)
	{	
	_Fill_n(_First, _Count, (_Valty)0);
	}

template<class _FwdIt,
	class _Diff,
	class _Tval,
	class _Alloc> inline
	void _Uninitialized_default_fill_n(_FwdIt _First, _Diff _Count,
		const _Tval *_Pval, _Alloc& _Al)
	{	
	_Uninit_def_fill_n(_First, _Count, _Pval, _Al,
		_Val_type(_First), _Ptr_cat(_First, _First));
	}

		
template<class _FwdIt,
	class _Ty>
	class raw_storage_iterator
		: public _Outit
	{	
public:
	typedef _FwdIt iterator_type;	
	typedef _FwdIt iter_type;	
	typedef _Ty element_type;	

	explicit raw_storage_iterator(_FwdIt _First)
		: _Next(_First)
		{	
		}

	raw_storage_iterator<_FwdIt, _Ty>& operator*()
		{	
		return (*this);
		}

	raw_storage_iterator<_FwdIt, _Ty>& operator=(const _Ty& _Val)
		{	
		_Construct(&*_Next, _Val);
		return (*this);
		}

	raw_storage_iterator<_FwdIt, _Ty>& operator++()
		{	
		++_Next;
		return (*this);
		}

	raw_storage_iterator<_FwdIt, _Ty> operator++(int)
		{	
		raw_storage_iterator<_FwdIt, _Ty> _Ans = *this;
		++_Next;
		return (_Ans);
		}

private:
	_FwdIt _Next;	
	};

		
template<class _Ty>
	class _Temp_iterator
		: public _Outit
	{	
public:
	typedef _Ty  *_Pty;

	_Temp_iterator(ptrdiff_t _Count = 0)
		{	
		_Buf._Begin = 0;
		_Buf._Current = 0;
		_Buf._Hiwater = 0;
		_Buf._Size = _Count;	
		_Pbuf = &_Buf;
		}

	_Temp_iterator(const _Temp_iterator<_Ty>& _Right)
		{	
		_Buf._Begin = 0;	
		_Buf._Current = 0;
		_Buf._Hiwater = 0;
		_Buf._Size = 0;
		*this = _Right;
		}

	~_Temp_iterator()
		{	
		if (_Buf._Begin != 0)
			{	
			for (_Pty _Next = _Buf._Begin;
				_Next != _Buf._Hiwater; ++_Next)
				_Destroy(&*_Next);
			::std:: return_temporary_buffer(_Buf._Begin);
			}
		}

	_Temp_iterator<_Ty>& operator=(const _Temp_iterator<_Ty>& _Right)
		{	
		_Pbuf = _Right._Pbuf;
		return (*this);
		}

	_Temp_iterator<_Ty>& operator=(const _Ty& _Val)
		{	
		if (_Pbuf->_Current < _Pbuf->_Hiwater)
			*_Pbuf->_Current++ = _Val;	
		else
			{	
			_Pty _Ptr = &*_Pbuf->_Current;
			_Construct(_Ptr, _Val);
			_Pbuf->_Hiwater = ++_Pbuf->_Current;
			}
		return (*this);
		}

	_Temp_iterator<_Ty>& operator=(_Ty&& _Val)
		{	
		if (_Pbuf->_Current < _Pbuf->_Hiwater)
			*_Pbuf->_Current++ =
				::std:: forward<_Ty>(_Val);	
		else
			{	
			_Pty _Ptr = &*_Pbuf->_Current;
			_Construct(_Ptr, ::std:: forward<_Ty>(_Val));
			_Pbuf->_Hiwater = ++_Pbuf->_Current;
			}
		return (*this);
		}

	_Temp_iterator<_Ty>& operator*()
		{	
		return (*this);
		}

	_Temp_iterator<_Ty>& operator++()
		{	
		return (*this);
		}

	_Temp_iterator<_Ty>& operator++(int)
		{	
		return (*this);
		}

	_Temp_iterator<_Ty>& _Init()
		{	
		_Pbuf->_Current = _Pbuf->_Begin;
		return (*this);
		}

	_Pty _First() const
		{	
		return (_Pbuf->_Begin);
		}

	_Pty _Last() const
		{	
		return (_Pbuf->_Current);
		}

	ptrdiff_t _Maxlen()
		{	
		if (_Pbuf->_Begin == 0 && 0 < _Pbuf->_Size)
			{	
			pair<_Pty, ptrdiff_t> _Pair =

				::std:: get_temporary_buffer<_Ty>(_Pbuf->_Size);

			_Pbuf->_Begin = _Pair.first;
			_Pbuf->_Current = _Pair.first;
			_Pbuf->_Hiwater = _Pair.first;
			_Pbuf->_Size = _Pair.second;
			}
		return (_Pbuf->_Size);
		}

private:
	struct _Bufpar
		{	
		_Pty _Begin;	
		_Pty _Current;	
		_Pty _Hiwater;	
		ptrdiff_t _Size;	
		};
	_Bufpar _Buf;	
	_Bufpar *_Pbuf;	
	};

		
template<class _Ty>
	class auto_ptr;

template<class _Ty>
	struct auto_ptr_ref
		{	
	explicit auto_ptr_ref(_Ty *_Right)
		: _Ref(_Right)
		{	
		}

	_Ty *_Ref;	
	};

template<class _Ty>
	class auto_ptr
		{	
public:
	typedef auto_ptr<_Ty> _Myt;
	typedef _Ty element_type;

	explicit auto_ptr(_Ty *_Ptr = 0) throw ()
		: _Myptr(_Ptr)
		{	
		}

	auto_ptr(_Myt& _Right) throw ()
		: _Myptr(_Right.release())
		{	
		}

	auto_ptr(auto_ptr_ref<_Ty> _Right) throw ()
		{	
		_Ty *_Ptr = _Right._Ref;
		_Right._Ref = 0;	
		_Myptr = _Ptr;	
		}

	template<class _Other>
		operator auto_ptr<_Other>() throw ()
		{	
		return (auto_ptr<_Other>(*this));
		}

	template<class _Other>
		operator auto_ptr_ref<_Other>() throw ()
		{	
		_Other *_Cvtptr = _Myptr;	
		auto_ptr_ref<_Other> _Ans(_Cvtptr);
		_Myptr = 0;	
		return (_Ans);
		}

	template<class _Other>
		_Myt& operator=(auto_ptr<_Other>& _Right) throw ()
		{	
		reset(_Right.release());
		return (*this);
		}

	template<class _Other>
		auto_ptr(auto_ptr<_Other>& _Right) throw ()
		: _Myptr(_Right.release())
		{	
		}

	_Myt& operator=(_Myt& _Right) throw ()
		{	
		reset(_Right.release());
		return (*this);
		}

	_Myt& operator=(auto_ptr_ref<_Ty> _Right) throw ()
		{	
		_Ty *_Ptr = _Right._Ref;
		_Right._Ref = 0;	
		reset(_Ptr);	
		return (*this);
		}

	~auto_ptr()
		{	
		delete _Myptr;
		}

	_Ty& operator*() const throw ()
		{	
 


#line 940 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

		return (*get());
		}

	_Ty *operator->() const throw ()
		{	
 


#line 950 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

		return (get());
		}

	_Ty *get() const throw ()
		{	
		return (_Myptr);
		}

	_Ty *release() throw ()
		{	
		_Ty *_Tmp = _Myptr;
		_Myptr = 0;
		return (_Tmp);
		}

	void reset(_Ty *_Ptr = 0)
		{	
		if (_Ptr != _Myptr)
			delete _Myptr;
		_Myptr = _Ptr;
		}

private:
	_Ty *_Myptr;	
	};
}

 
 



 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"














#pragma once






 
 
 #line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"

#pragma pack(push,8)

 



 

#line 35 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"

struct __type_info_node {
    void *_MemPtr;
    __type_info_node* _Next;
};

extern __type_info_node __type_info_root_node;

class type_info {
public:
 
	size_t hash_code() const throw ()
		{	
		const char *_Keyval = name();
		size_t _Val = 2166136261U;
		size_t _First = 0;
		size_t _Last = :: strlen(_Keyval);
		size_t _Stride = 1 + _Last / 10;

		for(; _First < _Last; _First += _Stride)
			_Val = 16777619U * _Val ^ (size_t)_Keyval[_First];
		return (_Val);
		}
 #line 59 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"

    


    virtual ~type_info();
     bool  operator==(const type_info& _Rhs) const;
     bool  operator!=(const type_info& _Rhs) const;
     int  before(const type_info& _Rhs) const;
     const char*  name(__type_info_node* __ptype_info_node = &__type_info_root_node) const;
     const char*  raw_name() const;
private:
    void *_M_data;
    char _M_d_name[1];
     type_info(const type_info& _Rhs);
    type_info&  operator=(const type_info& _Rhs);
     static const char *__cdecl _Name_base(const type_info *,__type_info_node* __ptype_info_node);
     static void __cdecl _Type_info_dtor(type_info *);
};

 

 namespace std {

using ::type_info;

 }





 namespace std {

class  bad_cast : public exception {
public:










     bad_cast(const char * _Message = "bad cast");
     bad_cast(const bad_cast &);
    virtual  ~bad_cast();
#line 108 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"
};

class  bad_typeid : public exception {
public:










     bad_typeid(const char * _Message = "bad typeid");
     bad_typeid(const bad_typeid &);
    virtual  ~bad_typeid();
#line 126 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"

};

class  __non_rtti_object : public bad_typeid {
public:










     __non_rtti_object(const char * _Message);
     __non_rtti_object(const __non_rtti_object &);
    virtual  ~__non_rtti_object();
#line 145 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"
};

 }
 

 























































#line 207 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"

#line 209 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"

#pragma pack(pop)

#line 213 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\typeinfo"







#line 985 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"
 

 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"












#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 19 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"















#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"









#line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"





#pragma pack(push,8)


extern "C" {
#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"













#line 56 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"







typedef struct __JUMP_BUFFER {
    unsigned long Ebp;
    unsigned long Ebx;
    unsigned long Edi;
    unsigned long Esi;
    unsigned long Esp;
    unsigned long Eip;
    unsigned long Registration;
    unsigned long TryLevel;
    unsigned long Cookie;
    unsigned long UnwindFunc;
    unsigned long UnwindData[6];
} _JUMP_BUFFER;


























































































































































#line 231 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"





typedef int jmp_buf[16];

#line 239 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"




int __cdecl _setjmp(  jmp_buf _Buf);


}
#line 248 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"


extern "C"
{
 __declspec(noreturn) void __cdecl longjmp(  jmp_buf _Buf,   int _Value) throw(...);
}


#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"

#pragma pack(pop)

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\setjmp.h"
#line 20 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"










#pragma once






#line 19 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"
















#pragma once






#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"

















#pragma once






#line 26 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"

















#pragma once






#line 26 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"










#pragma once






#line 19 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"


















#pragma once






#line 27 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"




















#pragma once






#line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"



























#pragma once






#line 36 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"





#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"


















#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 20 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"



#line 24 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"


extern "C" { 


#line 30 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"

typedef union __declspec(intrin_type) __declspec(align(8)) __m64
{
    unsigned __int64    m64_u64;
    float               m64_f32[2];
    __int8              m64_i8[8];
    __int16             m64_i16[4];
    __int32             m64_i32[2];    
    __int64             m64_i64;
    unsigned __int8     m64_u8[8];
    unsigned __int16    m64_u16[4];
    unsigned __int32    m64_u32[2];
} __m64;


void  _m_empty(void);
__m64 _m_from_int(int _I);
int   _m_to_int(__m64 _M);
__m64 _m_packsswb(__m64 _MM1, __m64 _MM2);
__m64 _m_packssdw(__m64 _MM1, __m64 _MM2);
__m64 _m_packuswb(__m64 _MM1, __m64 _MM2);
__m64 _m_punpckhbw(__m64 _MM1, __m64 _MM2);
__m64 _m_punpckhwd(__m64 _MM1, __m64 _MM2);
__m64 _m_punpckhdq(__m64 _MM1, __m64 _MM2);
__m64 _m_punpcklbw(__m64 _MM1, __m64 _MM2);
__m64 _m_punpcklwd(__m64 _MM1, __m64 _MM2);
__m64 _m_punpckldq(__m64 _MM1, __m64 _MM2);


__m64 _m_paddb(__m64 _MM1, __m64 _MM2);
__m64 _m_paddw(__m64 _MM1, __m64 _MM2);
__m64 _m_paddd(__m64 _MM1, __m64 _MM2);
__m64 _m_paddsb(__m64 _MM1, __m64 _MM2);
__m64 _m_paddsw(__m64 _MM1, __m64 _MM2);
__m64 _m_paddusb(__m64 _MM1, __m64 _MM2);
__m64 _m_paddusw(__m64 _MM1, __m64 _MM2);
__m64 _m_psubb(__m64 _MM1, __m64 _MM2);
__m64 _m_psubw(__m64 _MM1, __m64 _MM2);
__m64 _m_psubd(__m64 _MM1, __m64 _MM2);
__m64 _m_psubsb(__m64 _MM1, __m64 _MM2);
__m64 _m_psubsw(__m64 _MM1, __m64 _MM2);
__m64 _m_psubusb(__m64 _MM1, __m64 _MM2);
__m64 _m_psubusw(__m64 _MM1, __m64 _MM2);
__m64 _m_pmaddwd(__m64 _MM1, __m64 _MM2);
__m64 _m_pmulhw(__m64 _MM1, __m64 _MM2);
__m64 _m_pmullw(__m64 _MM1, __m64 _MM2);


__m64 _m_psllw(__m64 _M, __m64 _Count);
__m64 _m_psllwi(__m64 _M, int _Count);
__m64 _m_pslld(__m64 _M, __m64 _Count);
__m64 _m_pslldi(__m64 _M, int _Count);
__m64 _m_psllq(__m64 _M, __m64 _Count);
__m64 _m_psllqi(__m64 _M, int _Count);
__m64 _m_psraw(__m64 _M, __m64 _Count);
__m64 _m_psrawi(__m64 _M, int _Count);
__m64 _m_psrad(__m64 _M, __m64 _Count);
__m64 _m_psradi(__m64 _M, int _Count);
__m64 _m_psrlw(__m64 _M, __m64 _Count);
__m64 _m_psrlwi(__m64 _M, int _Count);
__m64 _m_psrld(__m64 _M, __m64 _Count);
__m64 _m_psrldi(__m64 _M, int _Count);
__m64 _m_psrlq(__m64 _M, __m64 _Count);
__m64 _m_psrlqi(__m64 _M, int _Count);


__m64 _m_pand(__m64 _MM1, __m64 _MM2);
__m64 _m_pandn(__m64 _MM1, __m64 _MM2);
__m64 _m_por(__m64 _MM1, __m64 _MM2);
__m64 _m_pxor(__m64 _MM1, __m64 _MM2);


__m64 _m_pcmpeqb(__m64 _MM1, __m64 _MM2);
__m64 _m_pcmpeqw(__m64 _MM1, __m64 _MM2);
__m64 _m_pcmpeqd(__m64 _MM1, __m64 _MM2);
__m64 _m_pcmpgtb(__m64 _MM1, __m64 _MM2);
__m64 _m_pcmpgtw(__m64 _MM1, __m64 _MM2);
__m64 _m_pcmpgtd(__m64 _MM1, __m64 _MM2);


__m64 _mm_setzero_si64(void);
__m64 _mm_set_pi32(int _I1, int _I0);
__m64 _mm_set_pi16(short _S3, short _S2, short _S1, short _S0);
__m64 _mm_set_pi8(char _B7, char _B6, char _B5, char _B4,
                  char _B3, char _B2, char _B1, char _B0);
__m64 _mm_set1_pi32(int _I);
__m64 _mm_set1_pi16(short _S);
__m64 _mm_set1_pi8(char _B);
__m64 _mm_setr_pi32(int _I1, int _I0);
__m64 _mm_setr_pi16(short _S3, short _S2, short _S1, short _S0);
__m64 _mm_setr_pi8(char _B7, char _B6, char _B5, char _B4,
                   char _B3, char _B2, char _B1, char _B0);




























































}; 
#line 184 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"

#line 186 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"
#line 187 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"
#line 188 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"

#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"
#line 43 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"

















typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
     float               m128_f32[4];
     unsigned __int64    m128_u64[2];
     __int8              m128_i8[16];
     __int16             m128_i16[8];
     __int32             m128_i32[4];
     __int64             m128_i64[2];
     unsigned __int8     m128_u8[16];
     unsigned __int16    m128_u16[8];
     unsigned __int32    m128_u32[4];
 } __m128;





#line 77 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"

 
 
 
 
 
 
 
 
 
 




 
 
 
 
 
 
 
 
 
 







































































 
 
 


extern "C" { 
  
#line 181 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"





extern __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern __m128 _mm_sub_ss(__m128 _A, __m128 _B);
extern __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern __m128 _mm_mul_ss(__m128 _A, __m128 _B);
extern __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern __m128 _mm_div_ss(__m128 _A, __m128 _B);
extern __m128 _mm_div_ps(__m128 _A, __m128 _B);
extern __m128 _mm_sqrt_ss(__m128 _A);
extern __m128 _mm_sqrt_ps(__m128 _A);
extern __m128 _mm_rcp_ss(__m128 _A);
extern __m128 _mm_rcp_ps(__m128 _A);
extern __m128 _mm_rsqrt_ss(__m128 _A);
extern __m128 _mm_rsqrt_ps(__m128 _A);
extern __m128 _mm_min_ss(__m128 _A, __m128 _B);
extern __m128 _mm_min_ps(__m128 _A, __m128 _B);
extern __m128 _mm_max_ss(__m128 _A, __m128 _B);
extern __m128 _mm_max_ps(__m128 _A, __m128 _B);





extern __m128 _mm_and_ps(__m128 _A, __m128 _B);
extern __m128 _mm_andnot_ps(__m128 _A, __m128 _B);
extern __m128 _mm_or_ps(__m128 _A, __m128 _B);
extern __m128 _mm_xor_ps(__m128 _A, __m128 _B);





extern __m128 _mm_cmpeq_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpeq_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmplt_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmplt_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmple_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmple_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpgt_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpgt_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpge_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpge_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpneq_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpneq_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpnlt_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpnlt_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpnle_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpnle_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpngt_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpngt_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpnge_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpnge_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpord_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpord_ps(__m128 _A, __m128 _B);
extern __m128 _mm_cmpunord_ss(__m128 _A, __m128 _B);
extern __m128 _mm_cmpunord_ps(__m128 _A, __m128 _B);
extern int _mm_comieq_ss(__m128 _A, __m128 _B);
extern int _mm_comilt_ss(__m128 _A, __m128 _B);
extern int _mm_comile_ss(__m128 _A, __m128 _B);
extern int _mm_comigt_ss(__m128 _A, __m128 _B);
extern int _mm_comige_ss(__m128 _A, __m128 _B);
extern int _mm_comineq_ss(__m128 _A, __m128 _B);
extern int _mm_ucomieq_ss(__m128 _A, __m128 _B);
extern int _mm_ucomilt_ss(__m128 _A, __m128 _B);
extern int _mm_ucomile_ss(__m128 _A, __m128 _B);
extern int _mm_ucomigt_ss(__m128 _A, __m128 _B);
extern int _mm_ucomige_ss(__m128 _A, __m128 _B);
extern int _mm_ucomineq_ss(__m128 _A, __m128 _B);





extern int _mm_cvt_ss2si(__m128 _A);
extern __m64 _mm_cvt_ps2pi(__m128 _A);
extern int _mm_cvtt_ss2si(__m128 _A);
extern __m64 _mm_cvtt_ps2pi(__m128 _A);
extern __m128 _mm_cvt_si2ss(__m128, int);
extern __m128 _mm_cvt_pi2ps(__m128, __m64);
extern float _mm_cvtss_f32(__m128 _A);








#line 275 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"





extern __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern __m128 _mm_unpackhi_ps(__m128 _A, __m128 _B);
extern __m128 _mm_unpacklo_ps(__m128 _A, __m128 _B);
extern __m128 _mm_loadh_pi(__m128, __m64 const*);
extern __m128 _mm_movehl_ps(__m128, __m128);
extern __m128 _mm_movelh_ps(__m128, __m128);
extern void _mm_storeh_pi(__m64 *, __m128);
extern __m128 _mm_loadl_pi(__m128, __m64 const*);
extern void _mm_storel_pi(__m64 *, __m128);
extern int _mm_movemask_ps(__m128 _A);





extern int _m_pextrw(__m64, int);
extern __m64 _m_pinsrw(__m64, int, int);
extern __m64 _m_pmaxsw(__m64, __m64);
extern __m64 _m_pmaxub(__m64, __m64);
extern __m64 _m_pminsw(__m64, __m64);
extern __m64 _m_pminub(__m64, __m64);
extern int _m_pmovmskb(__m64);
extern __m64 _m_pmulhuw(__m64, __m64);
extern __m64 _m_pshufw(__m64, int);
extern void _m_maskmovq(__m64, __m64, char *);
extern __m64 _m_pavgb(__m64, __m64);
extern __m64 _m_pavgw(__m64, __m64);
extern __m64 _m_psadbw(__m64, __m64);





extern __m128 _mm_set_ss(float _A);
extern __m128 _mm_set_ps1(float _A);
extern __m128 _mm_set_ps(float _A, float _B, float _C, float _D);
extern __m128 _mm_setr_ps(float _A, float _B, float _C, float _D);
extern __m128 _mm_setzero_ps(void);
extern __m128 _mm_load_ss(float const*_A);
extern __m128 _mm_load_ps1(float const*_A);
extern __m128 _mm_load_ps(float const*_A);
extern __m128 _mm_loadr_ps(float const*_A);
extern __m128 _mm_loadu_ps(float const*_A);
extern void _mm_store_ss(float *_V, __m128 _A);
extern void _mm_store_ps1(float *_V, __m128 _A);
extern void _mm_store_ps(float *_V, __m128 _A);
extern void _mm_storer_ps(float *_V, __m128 _A);
extern void _mm_storeu_ps(float *_V, __m128 _A);
extern void _mm_prefetch(char const*_A, int _Sel);
extern void _mm_stream_pi(__m64 *, __m64);
extern void _mm_stream_ps(float *, __m128);
extern __m128 _mm_move_ss(__m128 _A, __m128 _B);

extern void _mm_sfence(void);
extern unsigned int _mm_getcsr(void);
extern void _mm_setcsr(unsigned int);






























 
 
 

 
 
 
 
 
 
 
 
__inline __m128 _mm_cvtpi16_ps(__m64 a)
{
  __m128 tmp;
  __m64  ext_val = _m_pcmpgtw(_mm_setzero_si64(), a);

  tmp = _mm_cvt_pi2ps(_mm_setzero_ps(), _m_punpckhwd(a, ext_val));
  return(_mm_cvt_pi2ps(_mm_movelh_ps(tmp, tmp), 
                        _m_punpcklwd(a, ext_val)));
}


 
 
 
 
 
 
 
 
__inline __m128 _mm_cvtpu16_ps(__m64 a)
{
  __m128 tmp;
  __m64  ext_val = _mm_setzero_si64();

  tmp = _mm_cvt_pi2ps(_mm_setzero_ps(), _m_punpckhwd(a, ext_val));
  return(_mm_cvt_pi2ps(_mm_movelh_ps(tmp, tmp), 
                        _m_punpcklwd(a, ext_val)));
}


 
 
 
 
 
 
 
 
__inline __m64 _mm_cvtps_pi16(__m128 a)
{
  return _m_packssdw(_mm_cvt_ps2pi(a), 
                        _mm_cvt_ps2pi(_mm_movehl_ps(a, a)));
}


 
 
 
 
 
 
 
 
__inline __m128 _mm_cvtpi8_ps(__m64 a)
{
  __m64  ext_val = _m_pcmpgtb(_mm_setzero_si64(), a);

  return _mm_cvtpi16_ps(_m_punpcklbw(a, ext_val));
}


 
 
 
 
 
 
 
 
 
__inline __m128 _mm_cvtpu8_ps(__m64 a)
{
  return _mm_cvtpu16_ps(_m_punpcklbw(a, _mm_setzero_si64()));
}


 
 
 
 
 
 
 
 
__inline __m64 _mm_cvtps_pi8(__m128 a)
{
  return _m_packsswb(_mm_cvtps_pi16(a), _mm_setzero_si64());
}


 
 
 
 
 
 
 
 
 
__inline __m128 _mm_cvtpi32x2_ps(__m64 a, __m64 b)
{
  return _mm_movelh_ps(_mm_cvt_pi2ps(_mm_setzero_ps(), a), 
                       _mm_cvt_pi2ps(_mm_setzero_ps(), b)); 
}



}; 
#line 487 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"

#line 489 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"

#line 491 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"
#line 492 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmmintrin.h"
#line 34 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"

typedef union __declspec(intrin_type) __declspec(align(16)) __m128i {
    __int8              m128i_i8[16];
    __int16             m128i_i16[8];
    __int32             m128i_i32[4];    
    __int64             m128i_i64[2];
    unsigned __int8     m128i_u8[16];
    unsigned __int16    m128i_u16[8];
    unsigned __int32    m128i_u32[4];
    unsigned __int64    m128i_u64[2];
} __m128i;

typedef struct __declspec(intrin_type) __declspec(align(16)) __m128d {
    double              m128d_f64[2];
} __m128d;






 
 
 


extern "C" { 
  
#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"





extern __m128d _mm_add_sd(__m128d _A, __m128d _B);
extern __m128d _mm_add_pd(__m128d _A, __m128d _B);
extern __m128d _mm_sub_sd(__m128d _A, __m128d _B);
extern __m128d _mm_sub_pd(__m128d _A, __m128d _B);
extern __m128d _mm_mul_sd(__m128d _A, __m128d _B);
extern __m128d _mm_mul_pd(__m128d _A, __m128d _B);
extern __m128d _mm_sqrt_sd(__m128d _A, __m128d _B);
extern __m128d _mm_sqrt_pd(__m128d _A);
extern __m128d _mm_div_sd(__m128d _A, __m128d _B);
extern __m128d _mm_div_pd(__m128d _A, __m128d _B);
extern __m128d _mm_min_sd(__m128d _A, __m128d _B);
extern __m128d _mm_min_pd(__m128d _A, __m128d _B);
extern __m128d _mm_max_sd(__m128d _A, __m128d _B);
extern __m128d _mm_max_pd(__m128d _A, __m128d _B);





extern __m128d _mm_and_pd(__m128d _A, __m128d _B);
extern __m128d _mm_andnot_pd(__m128d _A, __m128d _B);
extern __m128d _mm_or_pd(__m128d _A, __m128d _B);
extern __m128d _mm_xor_pd(__m128d _A, __m128d _B);





extern __m128d _mm_cmpeq_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpeq_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmplt_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmplt_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmple_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmple_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpgt_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpgt_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpge_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpge_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpneq_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpneq_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpnlt_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpnlt_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpnle_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpnle_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpngt_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpngt_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpnge_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpnge_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpord_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpord_sd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpunord_pd(__m128d _A, __m128d _B);
extern __m128d _mm_cmpunord_sd(__m128d _A, __m128d _B);
extern int _mm_comieq_sd(__m128d _A, __m128d _B);
extern int _mm_comilt_sd(__m128d _A, __m128d _B);
extern int _mm_comile_sd(__m128d _A, __m128d _B);
extern int _mm_comigt_sd(__m128d _A, __m128d _B);
extern int _mm_comige_sd(__m128d _A, __m128d _B);
extern int _mm_comineq_sd(__m128d _A, __m128d _B);
extern int _mm_ucomieq_sd(__m128d _A, __m128d _B);
extern int _mm_ucomilt_sd(__m128d _A, __m128d _B);
extern int _mm_ucomile_sd(__m128d _A, __m128d _B);
extern int _mm_ucomigt_sd(__m128d _A, __m128d _B);
extern int _mm_ucomige_sd(__m128d _A, __m128d _B);
extern int _mm_ucomineq_sd(__m128d _A, __m128d _B);





extern __m128d _mm_cvtepi32_pd(__m128i _A);
extern __m128i _mm_cvtpd_epi32(__m128d _A);
extern __m128i _mm_cvttpd_epi32(__m128d _A);
extern __m128 _mm_cvtepi32_ps(__m128i _A);
extern __m128i _mm_cvtps_epi32(__m128 _A);
extern __m128i _mm_cvttps_epi32(__m128 _A);
extern __m128 _mm_cvtpd_ps(__m128d _A);
extern __m128d _mm_cvtps_pd(__m128 _A);
extern __m128 _mm_cvtsd_ss(__m128 _A, __m128d _B);
extern __m128d _mm_cvtss_sd(__m128d _A, __m128 _B);

extern int _mm_cvtsd_si32(__m128d _A);
extern int _mm_cvttsd_si32(__m128d _A);
extern __m128d _mm_cvtsi32_sd(__m128d _A, int _B);

extern __m64 _mm_cvtpd_pi32(__m128d _A);
extern __m64 _mm_cvttpd_pi32(__m128d _A);
extern __m128d _mm_cvtpi32_pd(__m64 _A);





extern __m128d _mm_unpackhi_pd(__m128d _A, __m128d _B);
extern __m128d _mm_unpacklo_pd(__m128d _A, __m128d _B);
extern int _mm_movemask_pd(__m128d _A);
extern __m128d _mm_shuffle_pd(__m128d _A, __m128d _B, int _I);





extern __m128d _mm_load_pd(double const*_Dp);
extern __m128d _mm_load1_pd(double const*_Dp);
extern __m128d _mm_loadr_pd(double const*_Dp);
extern __m128d _mm_loadu_pd(double const*_Dp);
extern __m128d _mm_load_sd(double const*_Dp);
extern __m128d _mm_loadh_pd(__m128d _A, double const*_Dp);
extern __m128d _mm_loadl_pd(__m128d _A, double const*_Dp);





extern __m128d _mm_set_sd(double _W);
extern __m128d _mm_set1_pd(double _A);
extern __m128d _mm_set_pd(double _Z, double _Y);
extern __m128d _mm_setr_pd(double _Y, double _Z);
extern __m128d _mm_setzero_pd(void);
extern __m128d _mm_move_sd(__m128d _A, __m128d _B);





extern void _mm_store_sd(double *_Dp, __m128d _A);
extern void _mm_store1_pd(double *_Dp, __m128d _A);
extern void _mm_store_pd(double *_Dp, __m128d _A);
extern void _mm_storeu_pd(double *_Dp, __m128d _A);
extern void _mm_storer_pd(double *_Dp, __m128d _A);
extern void _mm_storeh_pd(double *_Dp, __m128d _A);
extern void _mm_storel_pd(double *_Dp, __m128d _A);





extern __m128i _mm_add_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_add_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_add_epi32(__m128i _A, __m128i _B);
extern __m64 _mm_add_si64(__m64 _A, __m64 _B);
extern __m128i _mm_add_epi64(__m128i _A, __m128i _B);
extern __m128i _mm_adds_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_adds_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_adds_epu8(__m128i _A, __m128i _B);
extern __m128i _mm_adds_epu16(__m128i _A, __m128i _B);
extern __m128i _mm_avg_epu8(__m128i _A, __m128i _B);
extern __m128i _mm_avg_epu16(__m128i _A, __m128i _B);
extern __m128i _mm_madd_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_max_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_max_epu8(__m128i _A, __m128i _B);
extern __m128i _mm_min_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_min_epu8(__m128i _A, __m128i _B);
extern __m128i _mm_mulhi_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_mulhi_epu16(__m128i _A, __m128i _B);
extern __m128i _mm_mullo_epi16(__m128i _A, __m128i _B);
extern __m64 _mm_mul_su32(__m64 _A, __m64 _B);
extern __m128i _mm_mul_epu32(__m128i _A, __m128i _B);
extern __m128i _mm_sad_epu8(__m128i _A, __m128i _B);
extern __m128i _mm_sub_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_sub_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_sub_epi32(__m128i _A, __m128i _B);
extern __m64 _mm_sub_si64(__m64 _A, __m64 _B);
extern __m128i _mm_sub_epi64(__m128i _A, __m128i _B);
extern __m128i _mm_subs_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_subs_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_subs_epu8(__m128i _A, __m128i _B);
extern __m128i _mm_subs_epu16(__m128i _A, __m128i _B);





extern __m128i _mm_and_si128(__m128i _A, __m128i _B);
extern __m128i _mm_andnot_si128(__m128i _A, __m128i _B);
extern __m128i _mm_or_si128(__m128i _A, __m128i _B);
extern __m128i _mm_xor_si128(__m128i _A, __m128i _B);





extern __m128i _mm_slli_si128(__m128i _A, int _Imm);
extern __m128i _mm_slli_epi16(__m128i _A, int _Count);
extern __m128i _mm_sll_epi16(__m128i _A, __m128i _Count);
extern __m128i _mm_slli_epi32(__m128i _A, int _Count);
extern __m128i _mm_sll_epi32(__m128i _A, __m128i _Count);
extern __m128i _mm_slli_epi64(__m128i _A, int _Count);
extern __m128i _mm_sll_epi64(__m128i _A, __m128i _Count);
extern __m128i _mm_srai_epi16(__m128i _A, int _Count);
extern __m128i _mm_sra_epi16(__m128i _A, __m128i _Count);
extern __m128i _mm_srai_epi32(__m128i _A, int _Count);
extern __m128i _mm_sra_epi32(__m128i _A, __m128i _Count);
extern __m128i _mm_srli_si128(__m128i _A, int _Imm);
extern __m128i _mm_srli_epi16(__m128i _A, int _Count);
extern __m128i _mm_srl_epi16(__m128i _A, __m128i _Count);
extern __m128i _mm_srli_epi32(__m128i _A, int _Count);
extern __m128i _mm_srl_epi32(__m128i _A, __m128i _Count);
extern __m128i _mm_srli_epi64(__m128i _A, int _Count);
extern __m128i _mm_srl_epi64(__m128i _A, __m128i _Count);





extern __m128i _mm_cmpeq_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_cmpeq_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_cmpeq_epi32(__m128i _A, __m128i _B);
extern __m128i _mm_cmpgt_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_cmpgt_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_cmpgt_epi32(__m128i _A, __m128i _B);
extern __m128i _mm_cmplt_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_cmplt_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_cmplt_epi32(__m128i _A, __m128i _B);





extern __m128i _mm_cvtsi32_si128(int _A);
extern int _mm_cvtsi128_si32(__m128i _A);





extern __m128i _mm_packs_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_packs_epi32(__m128i _A, __m128i _B);
extern __m128i _mm_packus_epi16(__m128i _A, __m128i _B);
extern int _mm_extract_epi16(__m128i _A, int _Imm);
extern __m128i _mm_insert_epi16(__m128i _A, int _B, int _Imm);
extern int _mm_movemask_epi8(__m128i _A);
extern __m128i _mm_shuffle_epi32(__m128i _A, int _Imm);
extern __m128i _mm_shufflehi_epi16(__m128i _A, int _Imm);
extern __m128i _mm_shufflelo_epi16(__m128i _A, int _Imm);
extern __m128i _mm_unpackhi_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_unpackhi_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_unpackhi_epi32(__m128i _A, __m128i _B);
extern __m128i _mm_unpackhi_epi64(__m128i _A, __m128i _B);
extern __m128i _mm_unpacklo_epi8(__m128i _A, __m128i _B);
extern __m128i _mm_unpacklo_epi16(__m128i _A, __m128i _B);
extern __m128i _mm_unpacklo_epi32(__m128i _A, __m128i _B);
extern __m128i _mm_unpacklo_epi64(__m128i _A, __m128i _B);





extern __m128i _mm_load_si128(__m128i const*_P);
extern __m128i _mm_loadu_si128(__m128i const*_P);
extern __m128i _mm_loadl_epi64(__m128i const*_P);





extern __m128i _mm_set_epi64(__m64 _Q1, __m64 _Q0);
extern __m128i _mm_set_epi32(int _I3, int _I2, int _I1, int _I0);
extern __m128i _mm_set_epi16(short _W7, short _W6, short _W5, short _W4,
                             short _W3, short _W2, short _W1, short _W0);
extern __m128i _mm_set_epi8(char _B15, char _B14, char _B13, char _B12, 
                            char _B11, char _B10, char _B9, char _B8, 
                            char _B7, char _B6, char _B5, char _B4, 
                            char _B3, char _B2, char _B1, char _B0);
extern __m128i _mm_set1_epi64(__m64 _Q);
extern __m128i _mm_set1_epi32(int _I);
extern __m128i _mm_set1_epi16(short _W);
extern __m128i _mm_set1_epi8(char _B);
extern __m128i _mm_setl_epi64(__m128i _Q);
extern __m128i _mm_setr_epi64(__m64 _Q0, __m64 _Q1);
extern __m128i _mm_setr_epi32(int _I0, int _I1, int _I2, int _I3);
extern __m128i _mm_setr_epi16(short _W0, short _W1, short _W2, short _W3, 
                              short _W4, short _W5, short _W6, short _W7);
extern __m128i _mm_setr_epi8(char _B15, char _B14, char _B13, char _B12, 
                             char _B11, char _B10, char _B9, char _B8, 
                             char _B7, char _B6, char _B5, char _B4, 
                             char _B3, char _B2, char _B1, char _B0);
extern __m128i _mm_setzero_si128(void);





extern void _mm_store_si128(__m128i *_P, __m128i _B);
extern void _mm_storeu_si128(__m128i *_P, __m128i _B);
extern void _mm_storel_epi64(__m128i *_P, __m128i _Q);
extern void _mm_maskmoveu_si128(__m128i _D, __m128i _N, char *_P);





extern __m128i _mm_move_epi64(__m128i _Q);
extern __m128i _mm_movpi64_epi64(__m64 _Q);
extern __m64 _mm_movepi64_pi64(__m128i _Q);





extern void _mm_stream_pd(double *_Dp, __m128d _A);
extern void _mm_stream_si128(__m128i *_P, __m128i _A);
extern void _mm_clflush(void const*_P);
extern void _mm_lfence(void);
extern void _mm_mfence(void);
extern void _mm_stream_si32(int *_P, int _I);
extern void _mm_pause(void);





extern double _mm_cvtsd_f64(__m128d _A);







extern __m128  _mm_castpd_ps(__m128d);
extern __m128i _mm_castpd_si128(__m128d);
extern __m128d _mm_castps_pd(__m128);
extern __m128i _mm_castps_si128(__m128);
extern __m128  _mm_castsi128_ps(__m128i);
extern __m128d _mm_castsi128_pd(__m128i);













#line 407 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"


}; 
#line 411 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"

#line 413 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"

#line 415 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"
#line 416 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\emmintrin.h"
#line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"

 
 
 














 
 
 


extern "C" { 
  
#line 58 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"





extern __m128 _mm_addsub_ps(__m128 a, __m128 b);
extern __m128 _mm_hadd_ps(__m128 a, __m128 b);
extern __m128 _mm_hsub_ps(__m128 a, __m128 b);
extern __m128 _mm_movehdup_ps(__m128 a);
extern __m128 _mm_moveldup_ps(__m128 a);





extern __m128d _mm_addsub_pd(__m128d a, __m128d b);
extern __m128d _mm_hadd_pd(__m128d a, __m128d b);
extern __m128d _mm_hsub_pd(__m128d a, __m128d b);
extern __m128d _mm_loaddup_pd(double const * dp);
extern __m128d _mm_movedup_pd(__m128d a);




extern __m128i _mm_lddqu_si128(__m128i const *p);







extern void _mm_monitor(void const *p, unsigned extensions, unsigned hints);




extern void _mm_mwait(unsigned extensions, unsigned hints);


}; 
#line 100 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"

#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"

#line 104 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"
#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\pmmintrin.h"
#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"









extern "C" {
#line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"

    
    

    extern __m128i _mm_hadd_epi16 (__m128i a, __m128i b);
    extern __m128i _mm_hadd_epi32 (__m128i a, __m128i b);
    extern __m128i _mm_hadds_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_hadd_pi16 (__m64 a, __m64 b);
    extern __m64 _mm_hadd_pi32 (__m64 a, __m64 b);
    extern __m64 _mm_hadds_pi16 (__m64 a, __m64 b);

    
    

    extern __m128i _mm_hsub_epi16 (__m128i a, __m128i b);
    extern __m128i _mm_hsub_epi32 (__m128i a, __m128i b);
    extern __m128i _mm_hsubs_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_hsub_pi16 (__m64 a, __m64 b);
    extern __m64 _mm_hsub_pi32 (__m64 a, __m64 b);
    extern __m64 _mm_hsubs_pi16 (__m64 a, __m64 b);

    
    

    extern __m128i _mm_maddubs_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_maddubs_pi16 (__m64 a, __m64 b);

    
    

    extern __m128i _mm_mulhrs_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_mulhrs_pi16 (__m64 a, __m64 b);

    
    

    extern __m128i _mm_shuffle_epi8 (__m128i a, __m128i b);

    extern __m64 _mm_shuffle_pi8 (__m64 a, __m64 b);

    
    

    extern __m128i _mm_sign_epi8 (__m128i a, __m128i b);
    extern __m128i _mm_sign_epi16 (__m128i a, __m128i b);
    extern __m128i _mm_sign_epi32 (__m128i a, __m128i b);

    extern __m64 _mm_sign_pi8 (__m64 a, __m64 b);
    extern __m64 _mm_sign_pi16 (__m64 a, __m64 b);
    extern __m64 _mm_sign_pi32 (__m64 a, __m64 b);

    
    

    extern __m128i _mm_alignr_epi8 (__m128i a, __m128i b, int n);

    extern __m64 _mm_alignr_pi8 (__m64 a, __m64 b, int n);

    
    

    extern __m128i _mm_abs_epi8 (__m128i a);
    extern __m128i _mm_abs_epi16 (__m128i a);
    extern __m128i _mm_abs_epi32 (__m128i a);

    extern __m64 _mm_abs_pi8 (__m64 a);
    extern __m64 _mm_abs_pi16 (__m64 a);
    extern __m64 _mm_abs_pi32 (__m64 a);


};
#line 108 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"

#line 110 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"

#line 112 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"

#line 114 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\tmmintrin.h"
#line 28 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"


















































extern "C" {
#line 80 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"

        
        

        extern __m128i _mm_blend_epi16 (__m128i v1, __m128i v2,
                                        const int mask);
        extern __m128i _mm_blendv_epi8 (__m128i v1, __m128i v2, __m128i mask);

        
        

        extern __m128  _mm_blend_ps (__m128  v1, __m128  v2, const int mask);
        extern __m128  _mm_blendv_ps(__m128  v1, __m128  v2, __m128 v3);

        
        

        extern __m128d _mm_blend_pd (__m128d v1, __m128d v2, const int mask);
        extern __m128d _mm_blendv_pd(__m128d v1, __m128d v2, __m128d v3);

        
        

        extern __m128  _mm_dp_ps(__m128  val1, __m128  val2, const int mask);
        extern __m128d _mm_dp_pd(__m128d val1, __m128d val2, const int mask);

        
        

        extern __m128i _mm_cmpeq_epi64(__m128i val1, __m128i val2);

        

        extern __m128i _mm_min_epi8 (__m128i val1, __m128i val2);
        extern __m128i _mm_max_epi8 (__m128i val1, __m128i val2);

        extern __m128i _mm_min_epu16(__m128i val1, __m128i val2);
        extern __m128i _mm_max_epu16(__m128i val1, __m128i val2);

        extern __m128i _mm_min_epi32(__m128i val1, __m128i val2);
        extern __m128i _mm_max_epi32(__m128i val1, __m128i val2);
        extern __m128i _mm_min_epu32(__m128i val1, __m128i val2);
        extern __m128i _mm_max_epu32(__m128i val1, __m128i val2);

        
        

        extern __m128i _mm_mullo_epi32(__m128i a, __m128i b);

        
        

        extern __m128i _mm_mul_epi32(__m128i a, __m128i b);

        
        

        extern int _mm_testz_si128(__m128i mask, __m128i val);

        
        

        extern int _mm_testc_si128(__m128i mask, __m128i val);

        
        
        

        extern int _mm_testnzc_si128(__m128i mask, __m128i s2);

        
        
        
        
        

        extern __m128 _mm_insert_ps(__m128 dst, __m128 src, const int ndx);

        




        
        

        extern int _mm_extract_ps(__m128 src, const int ndx);

        
        




        
        





        
        

        extern __m128i _mm_insert_epi8 (__m128i dst, int s, const int ndx);
        extern __m128i _mm_insert_epi32(__m128i dst, int s, const int ndx);



#line 190 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"
        
        

        extern int   _mm_extract_epi8 (__m128i src, const int ndx);
        extern int   _mm_extract_epi32(__m128i src, const int ndx);



#line 199 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"

        
        

        extern __m128i _mm_minpos_epu16(__m128i shortValues);

        

        extern __m128d _mm_round_pd(__m128d val, int iRoundMode);
        extern __m128d _mm_round_sd(__m128d dst, __m128d val, int iRoundMode);

        

        extern __m128  _mm_round_ps(__m128  val, int iRoundMode);
        extern __m128  _mm_round_ss(__m128 dst, __m128  val, int iRoundMode);

        

        extern __m128i _mm_cvtepi8_epi32 (__m128i byteValues);
        extern __m128i _mm_cvtepi16_epi32(__m128i shortValues);
        extern __m128i _mm_cvtepi8_epi64 (__m128i byteValues); 
        extern __m128i _mm_cvtepi32_epi64(__m128i intValues);
        extern __m128i _mm_cvtepi16_epi64(__m128i shortValues);
        extern __m128i _mm_cvtepi8_epi16 (__m128i byteValues);

        

        extern __m128i _mm_cvtepu8_epi32 (__m128i byteValues);
        extern __m128i _mm_cvtepu16_epi32(__m128i shortValues);
        extern __m128i _mm_cvtepu8_epi64 (__m128i shortValues);
        extern __m128i _mm_cvtepu32_epi64(__m128i intValues);
        extern __m128i _mm_cvtepu16_epi64(__m128i shortValues);
        extern __m128i _mm_cvtepu8_epi16 (__m128i byteValues);


        
        

        extern __m128i _mm_packus_epi32(__m128i val1, __m128i val2);

        
        
        

        extern __m128i _mm_mpsadbw_epu8(__m128i s1, __m128i s2, const int msk);

        



        extern __m128i _mm_stream_load_si128(__m128i* v1);


}; 
#line 254 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"

#line 256 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"

#line 258 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"
#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\smmintrin.h"
#line 28 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"



extern "C" {
#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"












































 
    extern __m128i _mm_cmpistrm (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistri (__m128i a, __m128i b, const int mode);

    extern __m128i _mm_cmpestrm (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestri (__m128i a, int la, __m128i b, int lb, const int mode);





    extern int     _mm_cmpistrz (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistrc (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistrs (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistro (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistra (__m128i a, __m128i b, const int mode);

    extern int     _mm_cmpestrz (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestrc (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestrs (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestro (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestra (__m128i a, int la, __m128i b, int lb, const int mode);






    extern __m128i _mm_cmpgt_epi64(__m128i val1, __m128i val2);





    extern int _mm_popcnt_u32(unsigned int v);



#line 116 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"





    extern unsigned int _mm_crc32_u8 (unsigned int crc, unsigned char v);
    extern unsigned int _mm_crc32_u16(unsigned int crc, unsigned short v);
    extern unsigned int _mm_crc32_u32(unsigned int crc, unsigned int v);



#line 128 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"


}; 
#line 132 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"

#line 134 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"

#line 136 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"
#line 137 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\nmmintrin.h"
#line 27 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"



extern "C" {
#line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"





extern __m128i _mm_aesdec_si128(__m128i v, __m128i rkey);





extern __m128i _mm_aesdeclast_si128(__m128i v, __m128i rkey);





extern __m128i _mm_aesenc_si128(__m128i v, __m128i rkey);





extern __m128i _mm_aesenclast_si128(__m128i v, __m128i rkey);





extern __m128i _mm_aesimc_si128(__m128i v);






extern __m128i _mm_aeskeygenassist_si128(__m128i ckey, const int rcon);







extern __m128i _mm_clmulepi64_si128(__m128i v1, __m128i v2, 
					    const int imm8);





}; 
#line 85 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"

#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"

#line 89 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"
#line 90 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\wmmintrin.h"
#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"


extern "C" {
#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"





typedef union __declspec(intrin_type) __declspec(align(32)) __m256 { 
    float m256_f32[8];
} __m256;
    
typedef struct __declspec(intrin_type) __declspec(align(32)) {
    double m256d_f64[4]; 
} __m256d;

typedef union  __declspec(intrin_type) __declspec(align(32)) __m256i {
    __int8              m256i_i8[32];
    __int16             m256i_i16[16];
    __int32             m256i_i32[8];
    __int64             m256i_i64[4];
    unsigned __int8     m256i_u8[32];
    unsigned __int16    m256i_u16[16];
    unsigned __int32    m256i_u32[8];
    unsigned __int64    m256i_u64[4];
} __m256i;













































extern __m256d __cdecl _mm256_add_pd(__m256d m1, __m256d m2);









extern __m256 __cdecl _mm256_add_ps(__m256 m1, __m256 m2);












extern __m256d __cdecl _mm256_addsub_pd(__m256d m1, __m256d m2);












extern __m256 __cdecl _mm256_addsub_ps(__m256 m1, __m256 m2);








extern __m256d __cdecl _mm256_and_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_and_ps(__m256 m1, __m256 m2);








extern __m256d __cdecl _mm256_andnot_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_andnot_ps(__m256 m1, __m256 m2);













extern __m256d __cdecl _mm256_blend_pd(__m256d m1, __m256d m2, const int mask);













extern __m256 __cdecl _mm256_blend_ps(__m256 m1, __m256 m2, const int mask);









extern __m256d __cdecl _mm256_blendv_pd(__m256d m1, __m256d m2, __m256d m3);









extern __m256 __cdecl _mm256_blendv_ps(__m256 m1, __m256 m2, __m256 mask);








extern __m256d __cdecl _mm256_div_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_div_ps(__m256 m1, __m256 m2);














extern __m256 __cdecl _mm256_dp_ps(__m256 m1, __m256 m2, const int mask);








extern __m256d __cdecl _mm256_hadd_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_hadd_ps(__m256 m1, __m256 m2);








extern __m256d __cdecl _mm256_hsub_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_hsub_ps(__m256 m1, __m256 m2);








extern __m256d __cdecl _mm256_max_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_max_ps(__m256 m1, __m256 m2);








extern __m256d __cdecl _mm256_min_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_min_ps(__m256 m1, __m256 m2);









extern __m256d __cdecl _mm256_mul_pd(__m256d m1, __m256d m2);









extern __m256 __cdecl _mm256_mul_ps(__m256 m1, __m256 m2);








extern __m256d __cdecl _mm256_or_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_or_ps(__m256 m1, __m256 m2);











extern __m256d __cdecl _mm256_shuffle_pd(__m256d m1, __m256d m2, const int select);












extern __m256 __cdecl _mm256_shuffle_ps(__m256 m1, __m256 m2, const int select);








extern __m256d __cdecl _mm256_sub_pd(__m256d m1, __m256d m2);









extern __m256 __cdecl _mm256_sub_ps(__m256 m1, __m256 m2);








extern __m256d __cdecl _mm256_xor_pd(__m256d m1, __m256d m2);








extern __m256 __cdecl _mm256_xor_ps(__m256 m1, __m256 m2);














extern __m128d __cdecl _mm_cmp_pd(__m128d m1, __m128d m2, const int predicate);
extern __m256d __cdecl _mm256_cmp_pd(__m256d m1, __m256d m2, const int predicate);














extern __m128 __cdecl _mm_cmp_ps(__m128 m1, __m128 m2, const int predicate);
extern __m256 __cdecl _mm256_cmp_ps(__m256 m1, __m256 m2, const int predicate);












extern __m128d __cdecl _mm_cmp_sd(__m128d m1, __m128d m2, const int predicate);












extern __m128 __cdecl _mm_cmp_ss(__m128 m1, __m128 m2, const int predicate);








extern __m256d __cdecl _mm256_cvtepi32_pd(__m128i m1);








extern __m256  __cdecl _mm256_cvtepi32_ps(__m256i m1);









extern __m128  __cdecl _mm256_cvtpd_ps(__m256d m1);








extern __m256i __cdecl _mm256_cvtps_epi32(__m256 m1);









extern __m256d __cdecl _mm256_cvtps_pd(__m128 m1);












extern __m128i __cdecl _mm256_cvttpd_epi32(__m256d m1);








extern __m128i __cdecl _mm256_cvtpd_epi32(__m256d m1);












extern __m256i __cdecl _mm256_cvttps_epi32(__m256 m1);







extern __m128  __cdecl _mm256_extractf128_ps(__m256 m1, const int offset);
extern __m128d __cdecl _mm256_extractf128_pd(__m256d m1, const int offset);
extern __m128i __cdecl _mm256_extractf128_si256(__m256i m1, const int offset);






extern void __cdecl _mm256_zeroall(void);







extern void __cdecl _mm256_zeroupper(void);









extern __m256  __cdecl _mm256_permutevar_ps(__m256 m1, __m256i control);
extern __m128  __cdecl _mm_permutevar_ps(__m128 a, __m128i control);









extern __m256  __cdecl _mm256_permute_ps(__m256 m1, int control);
extern __m128  __cdecl _mm_permute_ps(__m128 a, int control);









extern __m256d __cdecl _mm256_permutevar_pd(__m256d m1, __m256i control);
extern __m128d __cdecl _mm_permutevar_pd(__m128d a, __m128i control);









extern __m256d __cdecl _mm256_permute_pd(__m256d m1, int control);
extern __m128d __cdecl _mm_permute_pd(__m128d a, int control);








extern __m256  __cdecl _mm256_permute2f128_ps(__m256 m1, __m256 m2, int control);
extern __m256d __cdecl _mm256_permute2f128_pd(__m256d m1, __m256d m2, int control);
extern __m256i __cdecl _mm256_permute2f128_si256(__m256i m1, __m256i m2, int control);








extern __m256  __cdecl _mm256_broadcast_ss(float const *a);
extern __m128  __cdecl _mm_broadcast_ss(float const *a);







extern __m256d __cdecl _mm256_broadcast_sd(double const *a);







extern __m256  __cdecl _mm256_broadcast_ps(__m128 const *a);
extern __m256d __cdecl _mm256_broadcast_pd(__m128d const *a);









extern __m256  __cdecl _mm256_insertf128_ps(__m256, __m128 a, int offset);
extern __m256d __cdecl _mm256_insertf128_pd(__m256d, __m128d a, int offset);
extern __m256i __cdecl _mm256_insertf128_si256(__m256i, __m128i a, int offset);








extern __m256d __cdecl _mm256_load_pd(double const *a);
extern void    __cdecl _mm256_store_pd(double *a, __m256d b);








extern __m256  __cdecl _mm256_load_ps(float const *a);
extern void    __cdecl _mm256_store_ps(float *a, __m256 b);








extern __m256d __cdecl _mm256_loadu_pd(double const *a);
extern void    __cdecl _mm256_storeu_pd(double *a, __m256d b);








extern __m256  __cdecl _mm256_loadu_ps(float const *a);
extern void    __cdecl _mm256_storeu_ps(float *a, __m256 b);








extern __m256i __cdecl _mm256_load_si256(__m256i const *a);
extern void    __cdecl _mm256_store_si256(__m256i *a, __m256i b);








extern __m256i __cdecl _mm256_loadu_si256(__m256i const *a);
extern void    __cdecl _mm256_storeu_si256(__m256i *a, __m256i b); 



















extern __m256d __cdecl _mm256_maskload_pd(double const *a, __m256i mask);
extern void    __cdecl _mm256_maskstore_pd(double *a, __m256i mask, __m256d b);
extern __m128d __cdecl _mm_maskload_pd(double const *a, __m128i mask);
extern void    __cdecl _mm_maskstore_pd(double *a, __m128i mask, __m128d b); 



















extern __m256  __cdecl _mm256_maskload_ps(float const *a, __m256i mask);
extern void    __cdecl _mm256_maskstore_ps(float *a, __m256i mask, __m256 b); 
extern __m128  __cdecl _mm_maskload_ps(float const *a, __m128i mask);
extern void    __cdecl _mm_maskstore_ps(float *a, __m128i mask, __m128 b); 







extern __m256  __cdecl _mm256_movehdup_ps(__m256 a);







extern __m256  __cdecl _mm256_moveldup_ps(__m256 a);







extern __m256d __cdecl _mm256_movedup_pd(__m256d a);









extern __m256i __cdecl _mm256_lddqu_si256(__m256i const *a);







extern void    __cdecl _mm256_stream_si256(__m256i *p, __m256i a);








extern void    __cdecl _mm256_stream_pd(double *p, __m256d a);








extern void    __cdecl _mm256_stream_ps(float *p, __m256 a);








extern __m256  __cdecl _mm256_rcp_ps(__m256 a);










extern __m256  __cdecl _mm256_rsqrt_ps(__m256 a);








extern __m256d __cdecl _mm256_sqrt_pd(__m256d a);








extern __m256  __cdecl _mm256_sqrt_ps(__m256 a);












extern __m256d __cdecl _mm256_round_pd(__m256d a, int iRoundMode);














extern __m256  __cdecl _mm256_round_ps(__m256 a, int iRoundMode);









extern __m256d __cdecl _mm256_unpackhi_pd(__m256d m1, __m256d m2);







extern __m256  __cdecl _mm256_unpackhi_ps(__m256 m1, __m256 m2); 







extern __m256d __cdecl _mm256_unpacklo_pd(__m256d m1, __m256d m2);







extern __m256  __cdecl _mm256_unpacklo_ps(__m256 m1, __m256 m2);









extern int     __cdecl _mm256_testz_si256(__m256i s1, __m256i s2);
extern int     __cdecl _mm256_testc_si256(__m256i s1, __m256i s2);
extern int     __cdecl _mm256_testnzc_si256(__m256i s1, __m256i s2);












extern int     __cdecl _mm256_testz_pd(__m256d s1, __m256d s2);
extern int     __cdecl _mm256_testc_pd(__m256d s1, __m256d s2);
extern int     __cdecl _mm256_testnzc_pd(__m256d s1, __m256d s2);
extern int     __cdecl _mm_testz_pd(__m128d s1, __m128d s2);
extern int     __cdecl _mm_testc_pd(__m128d s1, __m128d s2);
extern int     __cdecl _mm_testnzc_pd(__m128d s1, __m128d s2);












extern int     __cdecl _mm256_testz_ps(__m256 s1, __m256 s2);
extern int     __cdecl _mm256_testc_ps(__m256 s1, __m256 s2);
extern int     __cdecl _mm256_testnzc_ps(__m256 s1, __m256 s2);
extern int     __cdecl _mm_testz_ps(__m128 s1, __m128 s2);
extern int     __cdecl _mm_testc_ps(__m128 s1, __m128 s2);
extern int     __cdecl _mm_testnzc_ps(__m128 s1, __m128 s2);








extern int     __cdecl _mm256_movemask_pd(__m256d a);








extern int     __cdecl _mm256_movemask_ps(__m256 a);




extern __m256d __cdecl _mm256_setzero_pd(void);
extern __m256  __cdecl _mm256_setzero_ps(void);
extern __m256i __cdecl _mm256_setzero_si256(void);




extern __m256d __cdecl _mm256_set_pd(double, double, double, double);
extern __m256  __cdecl _mm256_set_ps(float, float, float, float, float, float, float, float);
extern __m256i __cdecl _mm256_set_epi8(char, char, char, char, char, char, char, char,
                                       char, char, char, char, char, char, char, char,
                                       char, char, char, char, char, char, char, char,
                                       char, char, char, char, char, char, char, char);
extern __m256i __cdecl _mm256_set_epi16(short, short, short, short, short, short, short, short,
                                        short, short, short, short, short, short, short, short);
extern __m256i __cdecl _mm256_set_epi32(int, int, int, int, int, int, int, int);
extern __m256i __cdecl _mm256_set_epi64x(long long, long long, long long, long long);

extern __m256d __cdecl _mm256_setr_pd(double, double, double, double);
extern __m256  __cdecl _mm256_setr_ps(float, float, float, float, float, float, float, float);
extern __m256i __cdecl _mm256_setr_epi8(char, char, char, char, char, char, char, char,
                                        char, char, char, char, char, char, char, char,
                                        char, char, char, char, char, char, char, char,
                                        char, char, char, char, char, char, char, char);
extern __m256i __cdecl _mm256_setr_epi16(short, short, short, short, short, short, short, short,
                                         short, short, short, short, short, short, short, short);
extern __m256i __cdecl _mm256_setr_epi32(int, int, int, int, int, int, int, int);
extern __m256i __cdecl _mm256_setr_epi64x(long long, long long, long long, long long);




extern __m256d __cdecl _mm256_set1_pd(double);
extern __m256  __cdecl _mm256_set1_ps(float);
extern __m256i __cdecl _mm256_set1_epi8(char);
extern __m256i __cdecl _mm256_set1_epi16(short);
extern __m256i __cdecl _mm256_set1_epi32(int);
extern __m256i __cdecl _mm256_set1_epi64x(long long);







extern __m256  __cdecl _mm256_castpd_ps(__m256d a);
extern __m256d __cdecl _mm256_castps_pd(__m256 a);
extern __m256i __cdecl _mm256_castps_si256(__m256 a);
extern __m256i __cdecl _mm256_castpd_si256(__m256d a);
extern __m256  __cdecl _mm256_castsi256_ps(__m256i a);
extern __m256d __cdecl _mm256_castsi256_pd(__m256i a);
extern __m128  __cdecl _mm256_castps256_ps128(__m256 a);
extern __m128d __cdecl _mm256_castpd256_pd128(__m256d a);
extern __m128i __cdecl _mm256_castsi256_si128(__m256i a);
extern __m256  __cdecl _mm256_castps128_ps256(__m128 a);
extern __m256d __cdecl _mm256_castpd128_pd256(__m128d a);
extern __m256i __cdecl _mm256_castsi128_si256(__m128i a);


}; 
#line 1075 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"

#line 1077 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"

#line 1079 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"
#line 1080 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\immintrin.h"

#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mm3dnow.h"















#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mm3dnow.h"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mmintrin.h"




























































































































































































#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mm3dnow.h"



extern "C" { 
#line 28 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mm3dnow.h"



void _m_femms(void);
__m64 _m_pavgusb(__m64, __m64);
__m64 _m_pf2id(__m64);
__m64 _m_pfacc(__m64, __m64);
__m64 _m_pfadd(__m64, __m64);
__m64 _m_pfcmpeq(__m64, __m64);
__m64 _m_pfcmpge(__m64, __m64);
__m64 _m_pfcmpgt(__m64, __m64);
__m64 _m_pfmax(__m64, __m64);
__m64 _m_pfmin(__m64, __m64);
__m64 _m_pfmul(__m64, __m64);
__m64 _m_pfrcp(__m64);
__m64 _m_pfrcpit1(__m64, __m64);
__m64 _m_pfrcpit2(__m64, __m64);
__m64 _m_pfrsqrt(__m64);
__m64 _m_pfrsqit1(__m64, __m64);
__m64 _m_pfsub(__m64, __m64);
__m64 _m_pfsubr(__m64, __m64);
__m64 _m_pi2fd(__m64);
__m64 _m_pmulhrw(__m64, __m64);
void _m_prefetch(void*);
void _m_prefetchw(volatile const void*_Source);

__m64 _m_from_float(float);
float _m_to_float(__m64);



__m64 _m_pf2iw(__m64);
__m64 _m_pfnacc(__m64, __m64);
__m64 _m_pfpnacc(__m64, __m64);
__m64 _m_pi2fw(__m64);
__m64 _m_pswapd(__m64);


}; 
#line 68 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mm3dnow.h"

#line 70 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mm3dnow.h"
#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\mm3dnow.h"
#line 28 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"
#line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"

#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"


extern "C" {
#line 35 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




































#line 72 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"


#line 75 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"






#line 82 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 92 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 112 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"








#line 121 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 126 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"




#line 131 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"
    
#line 133 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"


 void * __cdecl _alloca(size_t _Size);
int __cdecl abs(  int);


 unsigned short __cdecl _byteswap_ushort(  unsigned short value);
 unsigned long __cdecl _byteswap_ulong(  unsigned long value);
 unsigned __int64 __cdecl _byteswap_uint64(  unsigned __int64 value);

















void __cdecl __debugbreak(void);
void __cdecl _disable(void);


__int64 __emul(int,int);
unsigned __int64 __emulu(unsigned int,unsigned int);
void __cdecl _enable(void);


















long __cdecl _InterlockedDecrement(long volatile *);







long _InterlockedExchange(long volatile *, long);









short _InterlockedExchange16(short volatile *, short);
char _InterlockedExchange8(char volatile *, char);
long _InterlockedExchangeAdd(long volatile *, long);







short _InterlockedExchangeAdd16(short volatile *, short);
char _InterlockedExchangeAdd8(char volatile *, char);
long _InterlockedCompareExchange (long volatile *, long, long);












__int64 _InterlockedCompareExchange64(__int64 volatile *, __int64, __int64);

long __cdecl _InterlockedIncrement(long volatile *);







long _InterlockedOr(long volatile *, long);
char _InterlockedOr8(char volatile *, char);
short _InterlockedOr16(short volatile *, short);









long _InterlockedXor(long volatile *, long);
char _InterlockedXor8(char volatile *, char);
short _InterlockedXor16(short volatile *, short);









long _InterlockedAnd(long volatile *, long);
char _InterlockedAnd8(char volatile *, char);
short _InterlockedAnd16(short volatile *, short);









long _InterlockedAddLargeStatistic(__int64 volatile *, long);
int __cdecl _inp(unsigned short);
int __cdecl inp(unsigned short);
unsigned long __cdecl _inpd(unsigned short);
unsigned long __cdecl inpd(unsigned short);
unsigned short __cdecl _inpw(unsigned short);
unsigned short __cdecl inpw(unsigned short);







long __cdecl labs(  long);







 unsigned long __cdecl _lrotl(  unsigned long,  int);
 unsigned long __cdecl _lrotr(  unsigned long,  int);
unsigned __int64 __ll_lshift(unsigned __int64,int);
__int64 __ll_rshift(__int64,int);







































 int __cdecl memcmp(   const void *,   const void *,  size_t _Size);
void * __cdecl memcpy(    void *,   const void *,  size_t _Size);
void * __cdecl memset(    void *,  int,  size_t _Size);




int __cdecl _outp(unsigned short,int);
int __cdecl outp(unsigned short,int);
unsigned long __cdecl _outpd(unsigned short,unsigned long);
unsigned long __cdecl outpd(unsigned short,unsigned long);
unsigned short __cdecl _outpw(unsigned short,unsigned short);
unsigned short __cdecl outpw(unsigned short,unsigned short);











void * _ReturnAddress(void);



 unsigned int __cdecl _rotl(  unsigned int,  int);

 unsigned int __cdecl _rotr(  unsigned int,  int);



int __cdecl _setjmp(jmp_buf);











 int __cdecl strcmp(   const char *,   const char *);
 size_t __cdecl strlen(   const char *);

char * __cdecl strset(    char *,  int);







unsigned __int64 __ull_rshift(unsigned __int64,int);






void * _AddressOfReturnAddress(void);



void _m_empty(void);
__m64 _m_from_int(int);
int _m_to_int(__m64);
__m64 _m_packsswb(__m64,__m64);
__m64 _m_packssdw(__m64,__m64);
__m64 _m_packuswb(__m64,__m64);
__m64 _m_punpckhbw(__m64,__m64);
__m64 _m_punpckhwd(__m64,__m64);
__m64 _m_punpckhdq(__m64,__m64);
__m64 _m_punpcklbw(__m64,__m64);
__m64 _m_punpcklwd(__m64,__m64);
__m64 _m_punpckldq(__m64,__m64);
__m64 _m_paddb(__m64,__m64);
__m64 _m_paddw(__m64,__m64);
__m64 _m_paddd(__m64,__m64);
__m64 _m_paddsb(__m64,__m64);
__m64 _m_paddsw(__m64,__m64);
__m64 _m_paddusb(__m64,__m64);
__m64 _m_paddusw(__m64,__m64);
__m64 _m_psubb(__m64,__m64);
__m64 _m_psubw(__m64,__m64);
__m64 _m_psubd(__m64,__m64);
__m64 _m_psubsb(__m64,__m64);
__m64 _m_psubsw(__m64,__m64);
__m64 _m_psubusb(__m64,__m64);
__m64 _m_psubusw(__m64,__m64);
__m64 _m_pmaddwd(__m64,__m64);
__m64 _m_pmulhw(__m64,__m64);
__m64 _m_pmullw(__m64,__m64);
__m64 _m_psllw(__m64,__m64);
__m64 _m_psllwi(__m64,int);
__m64 _m_pslld(__m64,__m64);
__m64 _m_pslldi(__m64,int);
__m64 _m_psllq(__m64,__m64);
__m64 _m_psllqi(__m64,int);
__m64 _m_psraw(__m64,__m64);
__m64 _m_psrawi(__m64,int);
__m64 _m_psrad(__m64,__m64);
__m64 _m_psradi(__m64,int);
__m64 _m_psrlw(__m64,__m64);
__m64 _m_psrlwi(__m64,int);
__m64 _m_psrld(__m64,__m64);
__m64 _m_psrldi(__m64,int);
__m64 _m_psrlq(__m64,__m64);
__m64 _m_psrlqi(__m64,int);
__m64 _m_pand(__m64,__m64);
__m64 _m_pandn(__m64,__m64);
__m64 _m_por(__m64,__m64);
__m64 _m_pxor(__m64,__m64);
__m64 _m_pcmpeqb(__m64,__m64);
__m64 _m_pcmpeqw(__m64,__m64);
__m64 _m_pcmpeqd(__m64,__m64);
__m64 _m_pcmpgtb(__m64,__m64);
__m64 _m_pcmpgtw(__m64,__m64);
__m64 _m_pcmpgtd(__m64,__m64);
__m64 _mm_setzero_si64(void);
__m64 _mm_set_pi32(int,int);
__m64 _mm_set_pi16(short,short,short,short);
__m64 _mm_set_pi8(char,char,char,char,char,char,char,char);
__m64 _mm_set1_pi32(int);
__m64 _mm_set1_pi16(short);
__m64 _mm_set1_pi8(char);
__m64 _mm_setr_pi32(int,int);
__m64 _mm_setr_pi16(short,short,short,short);
__m64 _mm_setr_pi8(char,char,char,char,char,char,char,char);
int _m_pextrw(__m64,int);
__m64 _m_pinsrw(__m64,int,int);
__m64 _m_pmaxsw(__m64,__m64);
__m64 _m_pmaxub(__m64,__m64);
__m64 _m_pminsw(__m64,__m64);
__m64 _m_pminub(__m64,__m64);
int _m_pmovmskb(__m64);
__m64 _m_pmulhuw(__m64,__m64);
__m64 _m_pshufw(__m64,int);
void _m_maskmovq(__m64,__m64,char*);
__m64 _m_pavgb(__m64,__m64);
__m64 _m_pavgw(__m64,__m64);
__m64 _m_psadbw(__m64,__m64);
__m64 _m_from_float(float);
float _m_to_float(__m64);
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_add_ps(__m128,__m128);
__m128 _mm_sub_ss(__m128,__m128);
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_mul_ss(__m128,__m128);
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_div_ss(__m128,__m128);
__m128 _mm_div_ps(__m128,__m128);
__m128 _mm_sqrt_ss(__m128);
__m128 _mm_sqrt_ps(__m128);
__m128 _mm_rcp_ss(__m128);
__m128 _mm_rcp_ps(__m128);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_rsqrt_ps(__m128);
__m128 _mm_min_ss(__m128,__m128);
__m128 _mm_min_ps(__m128,__m128);
__m128 _mm_max_ss(__m128,__m128);
__m128 _mm_max_ps(__m128,__m128);
__m128 _mm_and_ps(__m128,__m128);
__m128 _mm_andnot_ps(__m128,__m128);
__m128 _mm_or_ps(__m128,__m128);
__m128 _mm_xor_ps(__m128,__m128);
__m128 _mm_cmpeq_ss(__m128,__m128);
__m128 _mm_cmpeq_ps(__m128,__m128);
__m128 _mm_cmplt_ss(__m128,__m128);
__m128 _mm_cmplt_ps(__m128,__m128);
__m128 _mm_cmple_ss(__m128,__m128);
__m128 _mm_cmple_ps(__m128,__m128);
__m128 _mm_cmpgt_ss(__m128,__m128);
__m128 _mm_cmpgt_ps(__m128,__m128);
__m128 _mm_cmpge_ss(__m128,__m128);
__m128 _mm_cmpge_ps(__m128,__m128);
__m128 _mm_cmpneq_ss(__m128,__m128);
__m128 _mm_cmpneq_ps(__m128,__m128);
__m128 _mm_cmpnlt_ss(__m128,__m128);
__m128 _mm_cmpnlt_ps(__m128,__m128);
__m128 _mm_cmpnle_ss(__m128,__m128);
__m128 _mm_cmpnle_ps(__m128,__m128);
__m128 _mm_cmpngt_ss(__m128,__m128);
__m128 _mm_cmpngt_ps(__m128,__m128);
__m128 _mm_cmpnge_ss(__m128,__m128);
__m128 _mm_cmpnge_ps(__m128,__m128);
__m128 _mm_cmpord_ss(__m128,__m128);
__m128 _mm_cmpord_ps(__m128,__m128);
__m128 _mm_cmpunord_ss(__m128,__m128);
__m128 _mm_cmpunord_ps(__m128,__m128);
int _mm_comieq_ss(__m128,__m128);
int _mm_comilt_ss(__m128,__m128);
int _mm_comile_ss(__m128,__m128);
int _mm_comigt_ss(__m128,__m128);
int _mm_comige_ss(__m128,__m128);
int _mm_comineq_ss(__m128,__m128);
int _mm_ucomieq_ss(__m128,__m128);
int _mm_ucomilt_ss(__m128,__m128);
int _mm_ucomile_ss(__m128,__m128);
int _mm_ucomigt_ss(__m128,__m128);
int _mm_ucomige_ss(__m128,__m128);
int _mm_ucomineq_ss(__m128,__m128);
int _mm_cvt_ss2si(__m128);
__m64 _mm_cvt_ps2pi(__m128);
int _mm_cvtt_ss2si(__m128);
__m64 _mm_cvtt_ps2pi(__m128);
__m128 _mm_cvt_si2ss(__m128,int);
__m128 _mm_cvt_pi2ps(__m128,__m64);
__m128 _mm_shuffle_ps(__m128,__m128,unsigned int);
__m128 _mm_unpackhi_ps(__m128,__m128);
__m128 _mm_unpacklo_ps(__m128,__m128);
__m128 _mm_loadh_pi(__m128,__m64 const*);
void _mm_storeh_pi(__m64*,__m128);
__m128 _mm_loadl_pi(__m128,__m64 const*);
void _mm_storel_pi(__m64*,__m128);
int _mm_movemask_ps(__m128);
__m128 _mm_set_ss(float);
__m128 _mm_set_ps1(float);
__m128 _mm_set_ps(float,float,float,float);
__m128 _mm_setr_ps(float,float,float,float);
__m128 _mm_setzero_ps(void);
__m128 _mm_load_ss(float const*);
__m128 _mm_load_ps1(float const*);
__m128 _mm_load_ps(float const*);
__m128 _mm_loadr_ps(float const*);
__m128 _mm_loadu_ps(float const*);
__m128 _mm_move_ss(__m128,__m128);
void _mm_store_ss(float*,__m128);
void _mm_store_ps1(float*,__m128);
void _mm_store_ps(float*,__m128);
void _mm_storer_ps(float*,__m128);
void _mm_storeu_ps(float*,__m128);
void _mm_prefetch(char const*,int);
void _mm_stream_pi(__m64*,__m64);
void _mm_stream_ps(float*,__m128);
void _mm_sfence(void);
unsigned int _mm_getcsr(void);
void _mm_setcsr(unsigned int);
__m128 _mm_movelh_ps(__m128,__m128);
__m128 _mm_movehl_ps(__m128,__m128);
void _m_prefetch(void*);
void _m_prefetchw(volatile const void*_Source);
void _m_femms(void);
__m64 _m_pavgusb(__m64,__m64);
__m64 _m_pf2id(__m64);
__m64 _m_pfacc(__m64,__m64);
__m64 _m_pfadd(__m64,__m64);
__m64 _m_pfcmpeq(__m64,__m64);
__m64 _m_pfcmpge(__m64,__m64);
__m64 _m_pfcmpgt(__m64,__m64);
__m64 _m_pfmax(__m64,__m64);
__m64 _m_pfmin(__m64,__m64);
__m64 _m_pfmul(__m64,__m64);
__m64 _m_pfrcp(__m64);
__m64 _m_pfrcpit1(__m64,__m64);
__m64 _m_pfrcpit2(__m64,__m64);
__m64 _m_pfrsqrt(__m64);
__m64 _m_pfrsqit1(__m64,__m64);
__m64 _m_pfsub(__m64,__m64);
__m64 _m_pfsubr(__m64,__m64);
__m64 _m_pi2fd(__m64);
__m64 _m_pmulhrw(__m64,__m64);
__m64 _m_pf2iw(__m64);
__m64 _m_pfnacc(__m64,__m64);
__m64 _m_pfpnacc(__m64,__m64);
__m64 _m_pi2fw(__m64);
__m64 _m_pswapd(__m64);
__m128d _mm_add_sd(__m128d,__m128d);
__m128d _mm_add_pd(__m128d,__m128d);
__m128d _mm_div_sd(__m128d,__m128d);
__m128d _mm_div_pd(__m128d,__m128d);
__m128d _mm_max_sd(__m128d,__m128d);
__m128d _mm_max_pd(__m128d,__m128d);
__m128d _mm_min_sd(__m128d,__m128d);
__m128d _mm_min_pd(__m128d,__m128d);
__m128d _mm_mul_sd(__m128d,__m128d);
__m128d _mm_mul_pd(__m128d,__m128d);
__m128d _mm_sqrt_sd(__m128d, __m128d);
__m128d _mm_sqrt_pd(__m128d);
__m128d _mm_sub_sd(__m128d,__m128d);
__m128d _mm_sub_pd(__m128d,__m128d);
__m128d _mm_and_pd(__m128d,__m128d);
__m128d _mm_andnot_pd(__m128d,__m128d);
__m128d _mm_or_pd(__m128d,__m128d);
__m128d _mm_xor_pd(__m128d,__m128d);
__m128d _mm_cmpeq_sd(__m128d,__m128d);
__m128d _mm_cmpeq_pd(__m128d,__m128d);
__m128d _mm_cmplt_sd(__m128d,__m128d);
__m128d _mm_cmplt_pd(__m128d,__m128d);
__m128d _mm_cmple_sd(__m128d,__m128d);
__m128d _mm_cmple_pd(__m128d,__m128d);
__m128d _mm_cmpgt_sd(__m128d,__m128d);
__m128d _mm_cmpgt_pd(__m128d,__m128d);
__m128d _mm_cmpge_sd(__m128d,__m128d);
__m128d _mm_cmpge_pd(__m128d,__m128d);
__m128d _mm_cmpneq_sd(__m128d,__m128d);
__m128d _mm_cmpneq_pd(__m128d,__m128d);
__m128d _mm_cmpnlt_sd(__m128d,__m128d);
__m128d _mm_cmpnlt_pd(__m128d,__m128d);
__m128d _mm_cmpnle_sd(__m128d,__m128d);
__m128d _mm_cmpnle_pd(__m128d,__m128d);
__m128d _mm_cmpngt_sd(__m128d,__m128d);
__m128d _mm_cmpngt_pd(__m128d,__m128d);
__m128d _mm_cmpnge_sd(__m128d,__m128d);
__m128d _mm_cmpnge_pd(__m128d,__m128d);
__m128d _mm_cmpord_sd(__m128d,__m128d);
__m128d _mm_cmpord_pd(__m128d,__m128d);
__m128d _mm_cmpunord_sd(__m128d,__m128d);
__m128d _mm_cmpunord_pd(__m128d,__m128d);
int _mm_comieq_sd(__m128d,__m128d);
int _mm_comilt_sd(__m128d,__m128d);
int _mm_comile_sd(__m128d,__m128d);
int _mm_comigt_sd(__m128d,__m128d);
int _mm_comige_sd(__m128d,__m128d);
int _mm_comineq_sd(__m128d,__m128d);
int _mm_ucomieq_sd(__m128d,__m128d);
int _mm_ucomilt_sd(__m128d,__m128d);
int _mm_ucomile_sd(__m128d,__m128d);
int _mm_ucomigt_sd(__m128d,__m128d);
int _mm_ucomige_sd(__m128d,__m128d);
int _mm_ucomineq_sd(__m128d,__m128d);
__m128 _mm_cvtpd_ps(__m128d);
__m128d _mm_cvtps_pd(__m128);
__m128d _mm_cvtepi32_pd(__m128i);
__m128i _mm_cvtpd_epi32(__m128d);
int _mm_cvtsd_si32(__m128d);
__m128 _mm_cvtsd_ss(__m128,__m128d);
__m128d _mm_cvtsi32_sd(__m128d,int);
__m128d _mm_cvtss_sd(__m128d,__m128);
__m128i _mm_cvttpd_epi32(__m128d);
int _mm_cvttsd_si32(__m128d);
__m128 _mm_cvtepi32_ps(__m128i);
__m128i _mm_cvtps_epi32(__m128);
__m128i _mm_cvttps_epi32(__m128);
__m64 _mm_cvtpd_pi32(__m128d);
__m64 _mm_cvttpd_pi32(__m128d);
__m128d _mm_cvtpi32_pd(__m64);
__m128d _mm_unpackhi_pd(__m128d,__m128d);
__m128d _mm_unpacklo_pd(__m128d,__m128d);
int _mm_movemask_pd(__m128d);
__m128d _mm_shuffle_pd(__m128d,__m128d,int);
__m128d _mm_load_pd(double const*);
__m128d _mm_load1_pd(double const*);
__m128d _mm_loadr_pd(double const*);
__m128d _mm_loadu_pd(double const*);
__m128d _mm_load_sd(double const*);
__m128d _mm_loadh_pd(__m128d,double const*);
__m128d _mm_loadl_pd(__m128d,double const*);
__m128d _mm_set_sd(double);
__m128d _mm_set1_pd(double);
__m128d _mm_set_pd(double,double);
__m128d _mm_setr_pd(double,double);
__m128d _mm_setzero_pd(void);
__m128d _mm_move_sd(__m128d,__m128d);
void _mm_store_sd(double*,__m128d);
void _mm_store1_pd(double*,__m128d);
void _mm_store_pd(double*,__m128d);
void _mm_storeu_pd(double*,__m128d);
void _mm_storer_pd(double*,__m128d);
void _mm_storeh_pd(double*,__m128d);
void _mm_storel_pd(double*,__m128d);
__m128i _mm_add_epi8(__m128i,__m128i);
__m128i _mm_add_epi16(__m128i,__m128i);
__m128i _mm_add_epi32(__m128i,__m128i);
__m64 _mm_add_si64(__m64,__m64);
__m128i _mm_add_epi64(__m128i,__m128i);
__m128i _mm_adds_epi8(__m128i,__m128i);
__m128i _mm_adds_epi16(__m128i,__m128i);
__m128i _mm_adds_epu8(__m128i,__m128i);
__m128i _mm_adds_epu16(__m128i,__m128i);
__m128i _mm_avg_epu8(__m128i,__m128i);
__m128i _mm_avg_epu16(__m128i,__m128i);
__m128i _mm_madd_epi16(__m128i,__m128i);
__m128i _mm_max_epi16(__m128i,__m128i);
__m128i _mm_max_epu8(__m128i,__m128i);
__m128i _mm_min_epi16(__m128i,__m128i);
__m128i _mm_min_epu8(__m128i,__m128i);
__m128i _mm_mulhi_epi16(__m128i,__m128i);
__m128i _mm_mulhi_epu16(__m128i,__m128i);
__m128i _mm_mullo_epi16(__m128i,__m128i);
__m64 _mm_mul_su32(__m64,__m64);
__m128i _mm_mul_epu32(__m128i,__m128i);
__m128i _mm_sad_epu8(__m128i,__m128i);
__m128i _mm_sub_epi8(__m128i,__m128i);
__m128i _mm_sub_epi16(__m128i,__m128i);
__m128i _mm_sub_epi32(__m128i,__m128i);
__m64 _mm_sub_si64(__m64,__m64);
__m128i _mm_sub_epi64(__m128i,__m128i);
__m128i _mm_subs_epi8(__m128i,__m128i);
__m128i _mm_subs_epi16(__m128i,__m128i);
__m128i _mm_subs_epu8(__m128i,__m128i);
__m128i _mm_subs_epu16(__m128i,__m128i);
__m128i _mm_andnot_si128(__m128i,__m128i);
__m128i _mm_and_si128(__m128i,__m128i);
__m128i _mm_or_si128(__m128i,__m128i);
__m128i _mm_xor_si128(__m128i,__m128i);
__m128i _mm_slli_si128(__m128i,int);
__m128i _mm_slli_epi16(__m128i,int);
__m128i _mm_sll_epi16(__m128i,__m128i);
__m128i _mm_slli_epi32(__m128i,int);
__m128i _mm_sll_epi32(__m128i,__m128i);
__m128i _mm_slli_epi64(__m128i,int);
__m128i _mm_sll_epi64(__m128i,__m128i);
__m128i _mm_srai_epi16(__m128i,int);
__m128i _mm_sra_epi16(__m128i,__m128i);
__m128i _mm_srai_epi32(__m128i,int);
__m128i _mm_sra_epi32(__m128i,__m128i);
__m128i _mm_srli_si128(__m128i,int);
__m128i _mm_srli_epi16(__m128i,int);
__m128i _mm_srl_epi16(__m128i,__m128i);
__m128i _mm_srli_epi32(__m128i,int);
__m128i _mm_srl_epi32(__m128i,__m128i);
__m128i _mm_srli_epi64(__m128i,int);
__m128i _mm_srl_epi64(__m128i,__m128i);
__m128i _mm_cmpeq_epi8(__m128i,__m128i);
__m128i _mm_cmpeq_epi16(__m128i,__m128i);
__m128i _mm_cmpeq_epi32(__m128i,__m128i);
__m128i _mm_cmpgt_epi8(__m128i,__m128i);
__m128i _mm_cmpgt_epi16(__m128i,__m128i);
__m128i _mm_cmpgt_epi32(__m128i,__m128i);
__m128i _mm_cmplt_epi8(__m128i,__m128i);
__m128i _mm_cmplt_epi16(__m128i,__m128i);
__m128i _mm_cmplt_epi32(__m128i,__m128i);
__m128i _mm_cvtsi32_si128(int);
int _mm_cvtsi128_si32(__m128i);
__m128i _mm_packs_epi16(__m128i,__m128i);
__m128i _mm_packs_epi32(__m128i,__m128i);
__m128i _mm_packus_epi16(__m128i,__m128i);
int _mm_extract_epi16(__m128i,int);
__m128i _mm_insert_epi16(__m128i,int,int);
int _mm_movemask_epi8(__m128i);
__m128i _mm_shuffle_epi32(__m128i,int);
__m128i _mm_shufflehi_epi16(__m128i,int);
__m128i _mm_shufflelo_epi16(__m128i,int);
__m128i _mm_unpackhi_epi8(__m128i,__m128i);
__m128i _mm_unpackhi_epi16(__m128i,__m128i);
__m128i _mm_unpackhi_epi32(__m128i,__m128i);
__m128i _mm_unpackhi_epi64(__m128i,__m128i);
__m128i _mm_unpacklo_epi8(__m128i,__m128i);
__m128i _mm_unpacklo_epi16(__m128i,__m128i);
__m128i _mm_unpacklo_epi32(__m128i,__m128i);
__m128i _mm_unpacklo_epi64(__m128i,__m128i);
__m128i _mm_load_si128(__m128i const*);
__m128i _mm_loadu_si128(__m128i const*);
__m128i _mm_loadl_epi64(__m128i const*);
__m128i _mm_set_epi64(__m64,__m64);
__m128i _mm_set_epi32(int,int,int,int);
__m128i _mm_set_epi16(short,short,short,short,short,short,short,short);
__m128i _mm_set_epi8(char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char);
__m128i _mm_set1_epi64(__m64);
__m128i _mm_set1_epi32(int);
__m128i _mm_set1_epi16(short);
__m128i _mm_set1_epi8(char);
__m128i _mm_setl_epi64(__m128i);
__m128i _mm_setr_epi64(__m64,__m64);
__m128i _mm_setr_epi32(int,int,int,int);
__m128i _mm_setr_epi16(short,short,short,short,short,short,short,short);
__m128i _mm_setr_epi8(char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char);
__m128i _mm_setzero_si128(void);
void _mm_store_si128(__m128i*,__m128i);
void _mm_storeu_si128(__m128i*,__m128i);
void _mm_storel_epi64(__m128i*,__m128i);
void _mm_maskmoveu_si128(__m128i,__m128i,char*);
__m128i _mm_move_epi64(__m128i);
__m128i _mm_movpi64_epi64(__m64);
__m64 _mm_movepi64_pi64(__m128i);
void _mm_stream_pd(double*,__m128d);
void _mm_stream_si128(__m128i*,__m128i);
void _mm_clflush(void const *);
void _mm_lfence(void);
void _mm_mfence(void);
void _mm_stream_si32(int*,int);
void _mm_pause(void);
__m128 _mm_addsub_ps(__m128,__m128);
__m128d _mm_addsub_pd(__m128d,__m128d);
__m128 _mm_hadd_ps(__m128,__m128);
__m128d _mm_hadd_pd(__m128d,__m128d);
__m128 _mm_hsub_ps(__m128,__m128);
__m128d _mm_hsub_pd(__m128d,__m128d);
__m128i _mm_lddqu_si128(__m128i const*);
void _mm_monitor(void const*,unsigned int,unsigned int);
__m128d _mm_movedup_pd(__m128d);
__m128d _mm_loaddup_pd(double const*);
__m128 _mm_movehdup_ps(__m128);
__m128 _mm_moveldup_ps(__m128);
void _mm_mwait(unsigned int,unsigned int);
__m128i _mm_hadd_epi16 (__m128i a, __m128i b);
__m128i _mm_hadd_epi32 (__m128i a, __m128i b);
__m128i _mm_hadds_epi16 (__m128i a, __m128i b);
__m64 _mm_hadd_pi16 (__m64 a, __m64 b);
__m64 _mm_hadd_pi32 (__m64 a, __m64 b);
__m64 _mm_hadds_pi16 (__m64 a, __m64 b);
__m128i _mm_hsub_epi16 (__m128i a, __m128i b);
__m128i _mm_hsub_epi32 (__m128i a, __m128i b);
__m128i _mm_hsubs_epi16 (__m128i a, __m128i b);
__m64 _mm_hsub_pi16 (__m64 a, __m64 b);
__m64 _mm_hsub_pi32 (__m64 a, __m64 b);
__m64 _mm_hsubs_pi16 (__m64 a, __m64 b);
__m128i _mm_maddubs_epi16 (__m128i a, __m128i b);
__m64 _mm_maddubs_pi16 (__m64 a, __m64 b);
__m128i _mm_mulhrs_epi16 (__m128i a, __m128i b);
__m64 _mm_mulhrs_pi16 (__m64 a, __m64 b);
__m128i _mm_shuffle_epi8 (__m128i a, __m128i b);
__m64 _mm_shuffle_pi8 (__m64 a, __m64 b);
__m128i _mm_sign_epi8 (__m128i a, __m128i b);
__m128i _mm_sign_epi16 (__m128i a, __m128i b);
__m128i _mm_sign_epi32 (__m128i a, __m128i b);
__m64 _mm_sign_pi8 (__m64 a, __m64 b);
__m64 _mm_sign_pi16 (__m64 a, __m64 b);
__m64 _mm_sign_pi32 (__m64 a, __m64 b);
__m128i _mm_alignr_epi8 (__m128i a, __m128i b, int n);
__m64 _mm_alignr_pi8 (__m64 a, __m64 b, int n);
__m128i _mm_abs_epi8 (__m128i a);
__m128i _mm_abs_epi16 (__m128i a);
__m128i _mm_abs_epi32 (__m128i a);
__m64 _mm_abs_pi8 (__m64 a);
__m64 _mm_abs_pi16 (__m64 a);
__m64 _mm_abs_pi32 (__m64 a);








__m128i _mm_blend_epi16 (__m128i v1, __m128i v2, const int mask);
__m128i _mm_blendv_epi8 (__m128i v1, __m128i v2, __m128i mask);
__m128 _mm_blend_ps (__m128 v1, __m128 v2, const int mask);
__m128 _mm_blendv_ps(__m128 v1, __m128 v2, __m128 v3);
__m128d _mm_blend_pd (__m128d v1, __m128d v2, const int mask);
__m128d _mm_blendv_pd(__m128d v1, __m128d v2, __m128d v3);
__m128 _mm_dp_ps(__m128 val1, __m128 val2, const int mask);
__m128d _mm_dp_pd(__m128d val1, __m128d val2, const int mask);
__m128i _mm_cmpeq_epi64(__m128i val1, __m128i val2);
__m128i _mm_min_epi8 (__m128i val1, __m128i val2);
__m128i _mm_max_epi8 (__m128i val1, __m128i val2);
__m128i _mm_min_epu16(__m128i val1, __m128i val2);
__m128i _mm_max_epu16(__m128i val1, __m128i val2);
__m128i _mm_min_epi32(__m128i val1, __m128i val2);
__m128i _mm_max_epi32(__m128i val1, __m128i val2);
__m128i _mm_min_epu32(__m128i val1, __m128i val2);
__m128i _mm_max_epu32(__m128i val1, __m128i val2);
__m128i _mm_mullo_epi32(__m128i a, __m128i b);
__m128i _mm_mul_epi32(__m128i a, __m128i b);
int _mm_testz_si128(__m128i mask, __m128i val);
int _mm_testc_si128(__m128i mask, __m128i val);
int _mm_testnzc_si128(__m128i mask, __m128i s2);
__m128 _mm_insert_ps(__m128 dst, __m128 src, const int ndx);
int _mm_extract_ps(__m128 src, const int ndx);
__m128i _mm_insert_epi8 (__m128i dst, int s, const int ndx);
__m128i _mm_insert_epi32(__m128i dst, int s, const int ndx);
int _mm_extract_epi8 (__m128i src, const int ndx);
int _mm_extract_epi32(__m128i src, const int ndx);
__m128i _mm_minpos_epu16(__m128i shortValues);
__m128d _mm_round_pd(__m128d val, int iRoundMode);
__m128d _mm_round_sd(__m128d dst, __m128d val, int iRoundMode);
__m128 _mm_round_ps(__m128 val, int iRoundMode);
__m128 _mm_round_ss(__m128 dst, __m128 val, int iRoundMode);
__m128i _mm_cvtepi8_epi32 (__m128i byteValues);
__m128i _mm_cvtepi16_epi32(__m128i shortValues);
__m128i _mm_cvtepi8_epi64 (__m128i byteValues);
__m128i _mm_cvtepi32_epi64(__m128i intValues);
__m128i _mm_cvtepi16_epi64(__m128i shortValues);
__m128i _mm_cvtepi8_epi16 (__m128i byteValues);
__m128i _mm_cvtepu8_epi32 (__m128i byteValues);
__m128i _mm_cvtepu16_epi32(__m128i shortValues);
__m128i _mm_cvtepu8_epi64 (__m128i shortValues);
__m128i _mm_cvtepu32_epi64(__m128i intValues);
__m128i _mm_cvtepu16_epi64(__m128i shortValues);
__m128i _mm_cvtepu8_epi16 (__m128i byteValues);
__m128i _mm_packus_epi32(__m128i val1, __m128i val2);
__m128i _mm_mpsadbw_epu8(__m128i s1, __m128i s2, const int msk);
__m128i _mm_stream_load_si128(__m128i* v1);


__m128i _mm_cmpistrm (__m128i a, __m128i b, const int mode);
int _mm_cmpistri (__m128i a, __m128i b, const int mode);
__m128i _mm_cmpestrm (__m128i a, int la, __m128i b, int lb, const int mode);
int _mm_cmpestri (__m128i a, int la, __m128i b, int lb, const int mode);
int _mm_cmpistrz (__m128i a, __m128i b, const int mode);
int _mm_cmpistrc (__m128i a, __m128i b, const int mode);
int _mm_cmpistrs (__m128i a, __m128i b, const int mode);
int _mm_cmpistro (__m128i a, __m128i b, const int mode);
int _mm_cmpistra (__m128i a, __m128i b, const int mode);
int _mm_cmpestrz (__m128i a, int la, __m128i b, int lb, const int mode);
int _mm_cmpestrc (__m128i a, int la, __m128i b, int lb, const int mode);
int _mm_cmpestrs (__m128i a, int la, __m128i b, int lb, const int mode);
int _mm_cmpestro (__m128i a, int la, __m128i b, int lb, const int mode);
int _mm_cmpestra (__m128i a, int la, __m128i b, int lb, const int mode);
__m128i _mm_cmpgt_epi64(__m128i val1, __m128i val2);
int _mm_popcnt_u32(unsigned int v);

unsigned int _mm_crc32_u8 (unsigned int crc, unsigned char v);
unsigned int _mm_crc32_u16(unsigned int crc, unsigned short v);
unsigned int _mm_crc32_u32(unsigned int crc, unsigned int v);

void _WriteBarrier(void);
void _ReadWriteBarrier(void);










unsigned long __readcr0(void);
unsigned long __readcr2(void);
unsigned long __readcr3(void);
unsigned long __readcr4(void);
unsigned long __readcr8(void);




void __writecr0(unsigned);
void __writecr3(unsigned);
void __writecr4(unsigned);
void __writecr8(unsigned);

unsigned __readdr(unsigned int);

void __writedr(unsigned int, unsigned);

unsigned __readeflags(void);

void __writeeflags(unsigned);
void __wbinvd(void);
void __invlpg(void*);
unsigned __int64 __readmsr(unsigned long);
void __writemsr(unsigned long, unsigned __int64);
unsigned __int64 __rdtsc(void);
void __movsb(unsigned char *, unsigned char const *, size_t);
void __movsw(unsigned short *, unsigned short const *, size_t);
void __movsd(unsigned long *, unsigned long const *, size_t);









void __addfsbyte(unsigned long Offset, unsigned char Data);
void __addfsword(unsigned long Offset, unsigned short Data);
void __addfsdword(unsigned long Offset, unsigned long Data);
void __incfsbyte(unsigned long Offset);
void __incfsword(unsigned long Offset);
void __incfsdword(unsigned long Offset);








unsigned char __inbyte(unsigned short Port);
unsigned short __inword(unsigned short Port);
unsigned long __indword(unsigned short Port);
void __outbyte(unsigned short Port, unsigned char Data);
void __outword(unsigned short Port, unsigned short Data);
void __outdword(unsigned short Port, unsigned long Data);
void __inbytestring(unsigned short Port, unsigned char *Buffer, unsigned long Count);
void __inwordstring(unsigned short Port, unsigned short *Buffer, unsigned long Count);
void __indwordstring(unsigned short Port, unsigned long *Buffer, unsigned long Count);
void __outbytestring(unsigned short Port, unsigned char *Buffer, unsigned long Count);
void __outwordstring(unsigned short Port, unsigned short *Buffer, unsigned long Count);
void __outdwordstring(unsigned short Port, unsigned long *Buffer, unsigned long Count);
unsigned int __getcallerseflags();



void __vmx_vmptrst(unsigned __int64 *);



void __vmx_off(void);

void __svm_clgi(void);
void __svm_invlpga(void*, int);
void __svm_skinit(int);
void __svm_stgi(void);
void __svm_vmload(size_t);
void __svm_vmrun(size_t);
void __svm_vmsave(size_t);
void __halt(void);
void __sidt(void*);
void __lidt(void*);
void __ud2(void);
void __nop(void);











void __stosb(unsigned char *, unsigned char, size_t);
void __stosw(unsigned short *, unsigned short, size_t);
void __stosd(unsigned long *, unsigned long, size_t);

unsigned char _bittest(long const *a, long b);
unsigned char _bittestandset(long *a, long b);
unsigned char _bittestandreset(long *a, long b);
unsigned char _bittestandcomplement(long *a, long b);
unsigned char _interlockedbittestandset(long volatile *a, long b);
unsigned char _interlockedbittestandreset(long volatile *a, long b);






void __cpuid(int a[4], int b);
void __cpuidex(int a[4], int b, int c);
unsigned __int64 __readpmc(unsigned long a);
unsigned long __segmentlimit(unsigned long a);

unsigned char __readfsbyte(unsigned long Offset);
unsigned short __readfsword(unsigned long Offset);
unsigned long __readfsdword(unsigned long Offset);
unsigned __int64 __readfsqword(unsigned long Offset);
void __writefsbyte(unsigned long Offset, unsigned char Data);
void __writefsword(unsigned long Offset, unsigned short Data);
void __writefsdword(unsigned long Offset, unsigned long Data);
void __writefsqword(unsigned long Offset, unsigned __int64 Data);


 unsigned __int64 __cdecl _rotl64(  unsigned __int64,  int);
 unsigned __int64 __cdecl _rotr64(  unsigned __int64,  int);
__int64 __cdecl _abs64(__int64);

unsigned char _BitScanForward(unsigned long* Index, unsigned long Mask);
unsigned char _BitScanReverse(unsigned long* Index, unsigned long Mask);


 wchar_t * __cdecl wcscat(      wchar_t *,    const wchar_t * _Source);
  int __cdecl wcscmp(   const wchar_t *,   const wchar_t *);
 wchar_t * __cdecl wcscpy(   wchar_t *,    const wchar_t * _Source);
  size_t __cdecl wcslen(   const wchar_t *);
#pragma warning(suppress: 4985)
 wchar_t * __cdecl _wcsset(    wchar_t *, wchar_t);




void __int2c(void);
void _ReadBarrier(void);
unsigned char _rotr8(unsigned char value, unsigned char shift);
unsigned short _rotr16(unsigned short value, unsigned char shift);
unsigned char _rotl8(unsigned char value, unsigned char shift);
unsigned short _rotl16(unsigned short value, unsigned char shift);
short _InterlockedIncrement16(short volatile *Addend);
short _InterlockedDecrement16(short volatile *Addend);
short _InterlockedCompareExchange16(short volatile *Destination, short Exchange, short Comparand);
char _InterlockedCompareExchange8(char volatile *Destination, char Exchange, char Comparand);
























































































































































void __nvreg_save_fence(void);
void __nvreg_restore_fence(void);




















unsigned short __lzcnt16(unsigned short);
unsigned int __lzcnt(unsigned int);

unsigned short __popcnt16(unsigned short);
unsigned int __popcnt(unsigned int);

__m128i _mm_extract_si64(__m128i,__m128i);
__m128i _mm_extracti_si64(__m128i, int, int);
__m128i _mm_insert_si64(__m128i,__m128i);
__m128i _mm_inserti_si64(__m128i, __m128i, int, int);
void _mm_stream_sd(double*,__m128d);
void _mm_stream_ss(float*,__m128);
unsigned __int64 __rdtscp(unsigned int*);




















































































































































































































































































































































































#line 1667 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"
























#line 1692 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"


}
#line 1696 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"
#line 1697 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"
#line 1698 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\intrin.h"

#line 988 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

  
  
  

namespace std {
 
template<class _Ty>
	struct default_delete;

template<class _Ty,
	class _Dx = default_delete<_Ty> >
	class unique_ptr;
 #line 1002 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	namespace tr1 {	
	
class bad_weak_ptr
	: public exception
	{	
public:
	explicit bad_weak_ptr(const char * = 0)
		{	
		}

	virtual const char * what() const throw()
		{	
		return ("tr1::bad_weak_ptr");
		}
	};

	
class _Ref_count_base
	{	
private:
	virtual void _Destroy() = 0;
	virtual void _Delete_this() = 0;

	long _Uses;
	long _Weaks;

protected:
	_Ref_count_base()
		: _Uses(1), _Weaks(1)
		{	
		}

public:
	virtual ~_Ref_count_base()
		{	
		}

	bool _Incref_nz()
		{	
		for (; ; )
			{	
			long _Count = (volatile long&)_Uses;
			if (_Count == 0)
				return (false);
			if (_InterlockedCompareExchange(&_Uses, _Count + 1, _Count) == _Count)
				return (true);
			}
		}

	void _Incref()
		{	
		_InterlockedIncrement(&_Uses);
		}

	void _Incwref()
		{	
		_InterlockedIncrement(&_Weaks);
		}

	void _Decref()
		{	
		if (_InterlockedDecrement(&_Uses) == 0)
			{	
			_Destroy();
			_Decwref();
			}
		}

	void _Decwref()
		{	
		if (_InterlockedDecrement(&_Weaks) == 0)
			_Delete_this();
		}

	long _Use_count() const
		{	
		return (_Uses);
		}

	bool _Expired() const
		{	
		return (_Uses == 0);
		}

	virtual void *_Get_deleter(const  type_info&) const
		{	
		return (0);
		}
	};

	
template<class _Ty>
	class _Ref_count
	: public _Ref_count_base
	{	
public:
	_Ref_count(_Ty *_Px)
		: _Ref_count_base(), _Ptr(_Px)
		{	
		}

private:
	virtual void _Destroy()
		{	
		delete _Ptr;
		}

	virtual void _Delete_this()
		{	
		delete this;
		}

	_Ty * _Ptr;
	};

template<class _Ty,
	class _Dx>
	class _Ref_count_del
	: public _Ref_count_base
	{	
public:
	_Ref_count_del(_Ty *_Px, _Dx _Dt)
		: _Ref_count_base(), _Ptr(_Px), _Dtor(_Dt)
		{	
		}

	virtual void *_Get_deleter(const  type_info& _Type) const
		{	
		return ((void *)(_Type == typeid(_Dx) ? &_Dtor : 0));
		}

private:
	virtual void _Destroy()
		{	
		_Dtor(_Ptr);
		}

	virtual void _Delete_this()
		{	
		delete this;
		}

	_Ty * _Ptr;
	_Dx _Dtor;	
	};

template<class _Ty,
	class _Dx,
	class _Alloc>
	class _Ref_count_del_alloc
	: public _Ref_count_base
	{	
public:
	typedef _Ref_count_del_alloc<_Ty, _Dx, _Alloc> _Myty;
	typedef typename _Alloc::template rebind<_Myty>::other _Myalty;

	_Ref_count_del_alloc(_Ty *_Px, _Dx _Dt, _Myalty _Al)
		: _Ref_count_base(), _Ptr(_Px), _Dtor(_Dt), _Myal(_Al)
		{	
		}

	virtual void *_Get_deleter(const  type_info& _Type) const
		{	
		return ((void *)(_Type == typeid(_Dx) ? &_Dtor : 0));
		}

private:
	virtual void _Destroy()
		{	
		_Dtor(_Ptr);
		}

	virtual void _Delete_this()
		{	
		_Myalty _Al = _Myal;
		_Dest_val(_Al, this);
		_Al.deallocate(this, 1);
		}

	_Ty * _Ptr;
	_Dx _Dtor;	
	_Myalty _Myal;	
	};

	
template<class _Ty>
	class weak_ptr;
template<class _Ty>
	class shared_ptr;
template<class _Ty>
	class enable_shared_from_this;
struct _Static_tag {};
struct _Const_tag {};
struct _Dynamic_tag {};
template<class _Ty1,
	class _Ty2>
	void _Do_enable(_Ty1 *, enable_shared_from_this<_Ty2> *,
		_Ref_count_base *);

template<class _Ty>
	inline void _Enable_shared(_Ty *_Ptr, _Ref_count_base *_Refptr,
		typename _Ty::_EStype * = 0)
	{	
	if (_Ptr)
		_Do_enable(_Ptr,
			(enable_shared_from_this<typename _Ty::_EStype>*)_Ptr, _Refptr);
	}

inline void _Enable_shared(const volatile void *, const volatile void *)
	{	
	}

	
template<class _Ty>
	class _Ptr_base
	{	
public:
	typedef _Ptr_base<_Ty> _Myt;
	typedef _Ty _Elem;
	typedef _Elem element_type;

	_Ptr_base()
		: _Ptr(0), _Rep(0)
		{	
		}

	_Ptr_base(_Myt&& _Right)
		: _Ptr(0), _Rep(0)
		{	
		_Assign_rv(::std:: forward<_Myt>(_Right));
		}

	template<class _Ty2>
		_Ptr_base(_Ptr_base<_Ty2>&& _Right)
		: _Ptr(_Right._Ptr), _Rep(_Right._Rep)
		{	
		_Right._Ptr = 0;
		_Right._Rep = 0;
		}

	_Myt& operator=(_Myt&& _Right)
		{	
		_Assign_rv(::std:: forward<_Myt>(_Right));
		return (*this);
		}

	void _Assign_rv(_Myt&& _Right)
		{	
		if (this != &_Right)
			_Swap(_Right);
		}

	long use_count() const
		{	
		return (_Rep ? _Rep->_Use_count() : 0);
		}

	void _Swap(_Ptr_base& _Right)
		{	
		::std:: swap(_Rep, _Right._Rep);
		::std:: swap(_Ptr, _Right._Ptr);
		}

	template<class _Ty2>
		bool owner_before(const _Ptr_base<_Ty2>& _Right) const
		{	
		return (_Rep < _Right._Rep);
		}

	void *_Get_deleter(const  type_info& _Type) const
		{	
		return (_Rep ? _Rep->_Get_deleter(_Type) : 0);
		}

	_Ty *_Get() const
		{	
		return (_Ptr);
		}

	bool _Expired() const
		{	
		return (!_Rep || _Rep->_Expired());
		}

	void _Decref()
		{	
		if (_Rep != 0)
			_Rep->_Decref();
		}

	void _Reset()
		{	
		_Reset(0, 0);
		}

	template<class _Ty2>
		void _Reset(const _Ptr_base<_Ty2>& _Other)
		{	
		_Reset(_Other._Ptr, _Other._Rep, false);
		}

	template<class _Ty2>
		void _Reset(const _Ptr_base<_Ty2>& _Other, bool _Throw)
		{	
		_Reset(_Other._Ptr, _Other._Rep, _Throw);
		}

	template<class _Ty2>
		void _Reset(const _Ptr_base<_Ty2>& _Other, const _Static_tag&)
		{	
		_Reset(static_cast<_Elem *>(_Other._Ptr), _Other._Rep);
		}

	template<class _Ty2>
		void _Reset(const _Ptr_base<_Ty2>& _Other, const _Const_tag&)
		{	
		_Reset(const_cast<_Elem *>(_Other._Ptr), _Other._Rep);
		}

	template<class _Ty2>
		void _Reset(const _Ptr_base<_Ty2>& _Other, const _Dynamic_tag&)
		{	
		_Elem *_Ptr = dynamic_cast<_Elem *>(_Other._Ptr);
		if (_Ptr)
			_Reset(_Ptr, _Other._Rep);
		else
			_Reset();
		}

	template<class _Ty2>
		void _Reset(auto_ptr<_Ty2>& _Other)
		{	
		_Ty2 *_Px = _Other.get();
		_Reset0(_Px, new _Ref_count<_Elem>(_Px));
		_Other.release();
		_Enable_shared(_Px, _Rep);
		}

 
	template<class _Ty2>
		void _Reset(_Ty *_Ptr, const _Ptr_base<_Ty2>& _Other)
		{	
		_Reset(_Ptr, _Other._Rep);
		}
 #line 1348 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	void _Reset(_Ty *_Other_ptr, _Ref_count_base *_Other_rep)
		{	
		if (_Other_rep)
			_Other_rep->_Incref();
		_Reset0(_Other_ptr, _Other_rep);
		}

	void _Reset(_Ty *_Other_ptr, _Ref_count_base *_Other_rep, bool _Throw)
		{	
			
			
		if (_Other_rep && _Other_rep->_Incref_nz())
			_Reset0(_Other_ptr, _Other_rep);
		else if (_Throw)
			throw bad_weak_ptr(0);
		}

	void _Reset0(_Ty *_Other_ptr, _Ref_count_base *_Other_rep)
		{	
		if (_Rep != 0)
			_Rep->_Decref();
		_Rep = _Other_rep;
		_Ptr = _Other_ptr;
		}

	void _Decwref()
		{	
		if (_Rep != 0)
			_Rep->_Decwref();
		}

	void _Resetw()
		{	
		_Resetw((_Elem *)0, 0);
		}

	template<class _Ty2>
		void _Resetw(const _Ptr_base<_Ty2>& _Other)
		{	
		_Resetw(_Other._Ptr, _Other._Rep);
		}

	template<class _Ty2>
		void _Resetw(const _Ty2 *_Other_ptr, _Ref_count_base *_Other_rep)
		{	
		_Resetw(const_cast<_Ty2*>(_Other_ptr), _Other_rep);
		}

	template<class _Ty2>
		void _Resetw(_Ty2 *_Other_ptr, _Ref_count_base *_Other_rep)
		{	
		if (_Other_rep)
			_Other_rep->_Incwref();
		if (_Rep != 0)
			_Rep->_Decwref();
		_Rep = _Other_rep;
		_Ptr = _Other_ptr;
		}

private:
	_Ty *_Ptr;
	_Ref_count_base *_Rep;
	template<class _Ty0>
		friend class _Ptr_base;
	};

	
template<class _Ty>
	class shared_ptr
		: public _Ptr_base<_Ty>
	{	
public:
	typedef shared_ptr<_Ty> _Myt;
	typedef _Ptr_base<_Ty> _Mybase;

	shared_ptr()
		{	
		}

	template<class _Ux>
		explicit shared_ptr(_Ux *_Px)
		{	
		_Resetp(_Px);
		}

	template<class _Ux,
		class _Dx>
		shared_ptr(_Ux *_Px, _Dx _Dt)
		{	
		_Resetp(_Px, _Dt);
		}



 

	shared_ptr(::std:: nullptr_t)
		{	
		_Resetp((_Ty *)0);
		}

	template<class _Dx>
		shared_ptr(::std:: nullptr_t, _Dx _Dt)
		{	
		_Resetp((_Ty *)0, _Dt);
		}

	template<class _Dx,
		class _Alloc>
		shared_ptr(::std:: nullptr_t, _Dx _Dt, _Alloc _Ax)
		{	
		_Resetp((_Ty *)0, _Dt, _Ax);
		}
 #line 1464 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	template<class _Ux,
		class _Dx,
		class _Alloc>
		shared_ptr(_Ux *_Px, _Dx _Dt, _Alloc _Ax)
		{	
		_Resetp(_Px, _Dt, _Ax);
		}


 
	template<class _Ty2>
		shared_ptr(const shared_ptr<_Ty2>& _Right, _Ty *_Px)
		{	
		this->_Reset(_Px, _Right);
		}
 #line 1481 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	shared_ptr(const _Myt& _Other)
		{	
		this->_Reset(_Other);
		}

	template<class _Ty2>
		shared_ptr(const shared_ptr<_Ty2>& _Other,
			typename enable_if<is_convertible<_Ty2 *, _Ty *>::value,
				void *>::type * = 0)
		{	
		this->_Reset(_Other);
		}

	template<class _Ty2>
		explicit shared_ptr(const weak_ptr<_Ty2>& _Other,
			bool _Throw = true)
		{	
		this->_Reset(_Other, _Throw);
		}

	template<class _Ty2>
		shared_ptr(auto_ptr<_Ty2>& _Other)
		{	
		this->_Reset(_Other);
		}

	template<class _Ty2>
		shared_ptr(const shared_ptr<_Ty2>& _Other, const _Static_tag& _Tag)
		{	
		this->_Reset(_Other, _Tag);
		}

	template<class _Ty2>
		shared_ptr(const shared_ptr<_Ty2>& _Other, const _Const_tag& _Tag)
		{	
		this->_Reset(_Other, _Tag);
		}

	template<class _Ty2>
		shared_ptr(const shared_ptr<_Ty2>& _Other, const _Dynamic_tag& _Tag)
		{	
		this->_Reset(_Other, _Tag);
		}

	shared_ptr(_Myt&& _Right)
		: _Mybase(::std:: forward<_Myt>(_Right))
		{	
		}

	template<class _Ty2>
		shared_ptr(shared_ptr<_Ty2>&& _Right,
			typename enable_if<is_convertible<_Ty2 *, _Ty *>::value,
				void *>::type * = 0)
		: _Mybase(::std:: forward<shared_ptr<_Ty2> >(_Right))
		{	
		}

 
	template<class _Ux,
		class _Dx>
		shared_ptr(::std:: unique_ptr<_Ux, _Dx>&& _Right)
		{	
		_Resetp(_Right.release(), _Right.get_deleter());
		}

	template<class _Ux,
		class _Dx>
		_Myt& operator=(unique_ptr<_Ux, _Dx>&& _Right)
		{	
		shared_ptr(::std:: move(_Right)).swap(*this);
		return (*this);
		}
 #line 1555 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	_Myt& operator=(_Myt&& _Right)
		{	
		shared_ptr(::std:: move(_Right)).swap(*this);
		return (*this);
		}

	template<class _Ty2>
		_Myt& operator=(shared_ptr<_Ty2>&& _Right)
		{	
		shared_ptr(::std:: move(_Right)).swap(*this);
		return (*this);
		}

	void swap(_Myt&& _Right)
		{	
		_Mybase::swap(::std:: move(_Right));
		}

	~shared_ptr()
		{	
		this->_Decref();
		}

	_Myt& operator=(const _Myt& _Right)
		{	
		shared_ptr(_Right).swap(*this);
		return (*this);
		}

	template<class _Ty2>
		_Myt& operator=(const shared_ptr<_Ty2>& _Right)
		{	
		shared_ptr(_Right).swap(*this);
		return (*this);
		}

	template<class _Ty2>
		_Myt& operator=(auto_ptr<_Ty2>& _Right)
		{	
		shared_ptr(_Right).swap(*this);
		return (*this);
		}

	void reset()
		{	
		shared_ptr().swap(*this);
		}

	template<class _Ux>
		void reset(_Ux *_Px)
		{	
		shared_ptr(_Px).swap(*this);
		}

	template<class _Ux,
		class _Dx>
		void reset(_Ux *_Px, _Dx _Dt)
		{	
		shared_ptr(_Px, _Dt).swap(*this);
		}


	template<class _Ux,
		class _Dx,
		class _Alloc>
		void reset(_Ux *_Px, _Dx _Dt, _Alloc _Ax)
		{	
		shared_ptr(_Px, _Dt, _Ax).swap(*this);
		}


	void swap(_Myt& _Other)
		{	
		this->_Swap(_Other);
		}

	_Ty *get() const
		{	
		return (this->_Get());
		}

	typename tr1::add_reference<_Ty>::type operator*() const
		{	
		return (*this->_Get());
		}

	_Ty *operator->() const
		{	
		return (this->_Get());
		}

	bool unique() const
		{	
		return (this->use_count() == 1);
		}

	operator ::std:: _Bool_type() const
		{	
		return (this->_Get() != 0 ? (&::std:: _Bool_struct::_Member) : 0);
		}

private:
	template<class _Ux>
		void _Resetp(_Ux *_Px)
		{	
		try {	
		_Resetp0(_Px, new _Ref_count<_Ux>(_Px));
		} catch (...) {	
		delete _Px;
		throw;
		}
		}

	template<class _Ux,
		class _Dx>
		void _Resetp(_Ux *_Px, _Dx _Dt)
		{	
		try {	
		_Resetp0(_Px, new _Ref_count_del<_Ux, _Dx>(_Px, _Dt));
		} catch (...) {	
		_Dt(_Px);
		throw;
		}
		}


	template<class _Ux,
		class _Dx,
		class _Alloc>
		void _Resetp(_Ux *_Px, _Dx _Dt, _Alloc _Ax)
		{	
		typedef _Ref_count_del_alloc<_Ux, _Dx, _Alloc> _Refd;
		typename _Alloc::template rebind<_Refd>::other _Al = _Ax;

		try {	
		_Refd *_Ptr = _Al.allocate(1);
		new (_Ptr) _Refd(_Px, _Dt, _Al);
		_Resetp0(_Px, _Ptr);
		} catch (...) {	
		_Dt(_Px);
		throw;
		}
		}


public:
	template<class _Ux>
		void _Resetp0(_Ux *_Px, _Ref_count_base *_Rx)
		{	
		this->_Reset0(_Px, _Rx);
		_Enable_shared(_Px, _Rx);
		}
	};

template<class _Ty1,
	class _Ty2>
	bool operator==(const shared_ptr<_Ty1>& _S1,
		const shared_ptr<_Ty2>& _S2)
	{	
	return (_S1.get() == _S2.get());
	}

template<class _Ty1,
	class _Ty2>
	bool operator!=(const shared_ptr<_Ty1>& _S1,
		const shared_ptr<_Ty2>& _S2)
	{	
	return (!(_S1 == _S2));
	}

template<class _Ty1,
	class _Ty2>
	bool operator<(const shared_ptr<_Ty1>& _S1,
		const shared_ptr<_Ty2>& _S2)
	{	
	return (_S1.get() < _S2.get());
	}

template<class _Ty1,
	class _Ty2>
	bool operator>=(const shared_ptr<_Ty1>& _S1,
		const shared_ptr<_Ty2>& _S2)
	{	
	return (!(_S1 < _S2));
	}

template<class _Ty1,
	class _Ty2>
	bool operator>(const shared_ptr<_Ty1>& _S1,
		const shared_ptr<_Ty2>& _S2)
	{	
	return (_S2 < _S1);
	}

template<class _Ty1,
	class _Ty2>
	bool operator<=(const shared_ptr<_Ty1>& _S1,
		const shared_ptr<_Ty2>& _S2)
	{	
	return (!(_S2 < _S1));
	}

template<class _Elem,
	class _Traits,
	class _Ty>
	basic_ostream<_Elem, _Traits>&
	operator<<(basic_ostream<_Elem, _Traits>& _Out,
		const shared_ptr<_Ty>& _Px)
	{	
	return (_Out << _Px.get());
	}

template<class _Ty>
	void swap(shared_ptr<_Ty>& _Left,
		shared_ptr<_Ty>& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Ty>
	void swap(shared_ptr<_Ty>& _Left,
		shared_ptr<_Ty>&& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Ty>
	void swap(shared_ptr<_Ty>&& _Left,
		shared_ptr<_Ty>& _Right)
	{	
	_Right.swap(_Left);
	}

template<class _Ty1,
	class _Ty2>
	shared_ptr<_Ty1> static_pointer_cast(const shared_ptr<_Ty2>& _Other)
	{	
	return (shared_ptr<_Ty1>(_Other, _Static_tag()));
	}

template<class _Ty1,
	class _Ty2>
	shared_ptr<_Ty1> const_pointer_cast(const shared_ptr<_Ty2>& _Other)
	{	
	return (shared_ptr<_Ty1>(_Other, _Const_tag()));
	}

template<class _Ty1,
	class _Ty2>
	shared_ptr<_Ty1> dynamic_pointer_cast(const shared_ptr<_Ty2>& _Other)
	{	
	return (shared_ptr<_Ty1>(_Other, _Dynamic_tag()));
	}

template<class _Dx,
	class _Ty>
	_Dx *get_deleter(const shared_ptr<_Ty>& _Sx)
	{	
	return ((_Dx *)_Sx._Get_deleter(typeid(_Dx)));
	}

 

	
template<class _Ty>
	class _Ref_count_obj
	: public _Ref_count_base
	{	
public:
 
 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 

#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 
  
  
  
  
  
  

 

















































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 




#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  
  
  
  
  
  
  
  
  
  
  
  
  

 




























#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 

#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(    )
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(    );
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"
 
#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  

 













#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0    >
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0    )
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0)    );
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 ,   class _Arg1>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 ,   _Arg1 && _Ax1)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) ,   ::std:: forward<_Arg1>(_Ax1));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1 , class _Arg2>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1 , _Arg2 && _Ax2)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1) , ::std:: forward<_Arg2>(_Ax2));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2 , _Arg3 && _Ax3)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2) , ::std:: forward<_Arg3>(_Ax3));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3 , _Arg4 && _Ax4)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3) , ::std:: forward<_Arg4>(_Ax4));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 37 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4 , _Arg5 && _Ax5)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4) , ::std:: forward<_Arg5>(_Ax5));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5 , _Arg6 && _Ax6)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5) , ::std:: forward<_Arg6>(_Ax6));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 45 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6 , _Arg7 && _Ax7)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6) , ::std:: forward<_Arg7>(_Ax7));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 49 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7 , _Arg8 && _Ax8)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7) , ::std:: forward<_Arg8>(_Ax8));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 53 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  

 

#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
 #line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7, _Arg8 && _Ax8 , _Arg9 && _Ax9)
		: _Ref_count_base()
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7), ::std:: forward<_Arg8>(_Ax8) , ::std:: forward<_Arg9>(_Ax9));
		}
 #line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 












 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"




















#line 1828 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"
 

	_Ty *_Getptr() const
		{	
		return ((_Ty *)&_Storage);
		}

private:
	virtual void _Destroy()
		{	
		_Getptr()->~_Ty();
		}

	virtual void _Delete_this()
		{	
		delete this;
		}

	typename aligned_storage<sizeof(_Ty),
		alignment_of<_Ty>::value>::type _Storage;
	};

	
template<class _Ty,
	class _Alloc>
	class _Ref_count_obj_alloc
	: public _Ref_count_base
	{	
public:
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Myty;
	typedef typename _Alloc::template rebind<_Myty>::other _Myalty;

 
 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 

#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 
  
  
  
  
  
  

 

















































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 




#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  
  
  
  
  
  
  
  
  
  
  
  
  

 




























#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 

#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al      )
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(    );
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"
 
#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  

 













#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0    >
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0    )
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0)    );
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 ,   class _Arg1>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 ,   _Arg1 && _Ax1)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) ,   ::std:: forward<_Arg1>(_Ax1));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1 , class _Arg2>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1 , _Arg2 && _Ax2)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1) , ::std:: forward<_Arg2>(_Ax2));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1, class _Arg2 , class _Arg3>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2 , _Arg3 && _Ax3)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2) , ::std:: forward<_Arg3>(_Ax3));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3 , _Arg4 && _Ax4)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3) , ::std:: forward<_Arg4>(_Ax4));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 37 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4 , _Arg5 && _Ax5)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4) , ::std:: forward<_Arg5>(_Ax5));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5 , _Arg6 && _Ax6)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5) , ::std:: forward<_Arg6>(_Ax6));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 45 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6 , _Arg7 && _Ax7)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6) , ::std:: forward<_Arg7>(_Ax7));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 49 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7 , _Arg8 && _Ax8)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7) , ::std:: forward<_Arg8>(_Ax8));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 53 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  

 

#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 

 
	template<class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9>
 #line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

	_Ref_count_obj_alloc(_Myalty _Al , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7, _Arg8 && _Ax8 , _Arg9 && _Ax9)
		: _Ref_count_base(), _Myal(_Al)
		{	
		new ((void *) &_Storage) _Ty(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7), ::std:: forward<_Arg8>(_Ax8) , ::std:: forward<_Arg9>(_Ax9));
		}
 #line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"

 







































#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"




















#line 1863 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"
 

	_Ty *_Getptr() const
		{	
		return ((_Ty *)&_Storage);
		}

private:
	virtual void _Destroy()
		{	
		_Getptr()->~_Ty();
		}

	virtual void _Delete_this()
		{	
		_Myalty _Al = _Myal;
		_Dest_val(_Al, this);
		_Al.deallocate(this, 1);
		}

	typename aligned_storage<sizeof (_Ty),
		alignment_of<_Ty>::value>::type _Storage;
	_Myalty _Myal;	
	};

 
 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 

#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"





 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 
  
  
  
  
  
  

 

















































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 




#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  
  
  
  
  
  
  
  
  
  
  
  
  

 




























#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty      > inline
	shared_ptr<_Ty> make_shared(    )
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(    );

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc      > inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg      )
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg      );
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"
 
#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  

 













#line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0    > inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0    )
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0)    );

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0    > inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0    )
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0)    );
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 
  

 

#line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 ,   class _Arg1> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 ,   _Arg1 && _Ax1)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) ,   ::std:: forward<_Arg1>(_Ax1));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 ,   class _Arg1> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 ,   _Arg1 && _Ax1)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) ,   ::std:: forward<_Arg1>(_Ax1));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1 , class _Arg2> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1 , _Arg2 && _Ax2)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1) , ::std:: forward<_Arg2>(_Ax2));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1 , class _Arg2> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1 , _Arg2 && _Ax2)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1) , ::std:: forward<_Arg2>(_Ax2));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 29 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2 , _Arg3 && _Ax3)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2) , ::std:: forward<_Arg3>(_Ax3));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1, class _Arg2 , class _Arg3> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2 , _Arg3 && _Ax3)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2) , ::std:: forward<_Arg3>(_Ax3));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3 , _Arg4 && _Ax4)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3) , ::std:: forward<_Arg4>(_Ax4));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1, class _Arg2, class _Arg3 , class _Arg4> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3 , _Arg4 && _Ax4)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3) , ::std:: forward<_Arg4>(_Ax4));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 37 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

































#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4 , _Arg5 && _Ax5)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4) , ::std:: forward<_Arg5>(_Ax5));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4 , class _Arg5> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4 , _Arg5 && _Ax5)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4) , ::std:: forward<_Arg5>(_Ax5));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

























#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5 , _Arg6 && _Ax6)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5) , ::std:: forward<_Arg6>(_Ax6));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5 , class _Arg6> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5 , _Arg6 && _Ax6)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5) , ::std:: forward<_Arg6>(_Ax6));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 45 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

















#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6 , _Arg7 && _Ax7)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6) , ::std:: forward<_Arg7>(_Ax7));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6 , class _Arg7> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6 , _Arg7 && _Ax7)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6) , ::std:: forward<_Arg7>(_Ax7));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 49 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 









#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"


#line 105 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7 , _Arg8 && _Ax8)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7) , ::std:: forward<_Arg8>(_Ax8));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7 , class _Arg8> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7 , _Arg8 && _Ax8)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7) , ::std:: forward<_Arg8>(_Ax8));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 53 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"





 







#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 47 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 55 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 63 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 71 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 79 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"







#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  

 

#line 97 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 102 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  

 

#line 107 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 














#line 124 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"














#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
  
  
  
  
  
  
  
  
  
  
  
  
 #line 153 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 158 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 160 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

 


#line 165 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
  
 #line 167 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

















































  
  
  
  


































#line 255 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 259 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 263 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 265 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"

#line 271 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
	#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"



 












 












 
	
template<class _Ty , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9> inline
	shared_ptr<_Ty> make_shared(_Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7, _Arg8 && _Ax8 , _Arg9 && _Ax9)
	{	
	_Ref_count_obj<_Ty> * _Rx = new _Ref_count_obj<_Ty>(::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7), ::std:: forward<_Arg8>(_Ax8) , ::std:: forward<_Arg9>(_Ax9));

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}

	
template<class _Ty,
	class _Alloc , class _Arg0 , class _Arg1, class _Arg2, class _Arg3, class _Arg4, class _Arg5, class _Arg6, class _Arg7, class _Arg8 , class _Arg9> inline
		shared_ptr<_Ty> allocate_shared(
			const _Alloc& _Al_arg , _Arg0 && _Ax0 , _Arg1 && _Ax1, _Arg2 && _Ax2, _Arg3 && _Ax3, _Arg4 && _Ax4, _Arg5 && _Ax5, _Arg6 && _Ax6, _Arg7 && _Ax7, _Arg8 && _Ax8 , _Arg9 && _Ax9)
	{	
	typedef _Ref_count_obj_alloc<_Ty, _Alloc> _Refoa;
	typename _Alloc::template rebind<_Refoa>::other _Alref = _Al_arg;

	_Refoa * _Rx = _Alref.allocate(1);

	try {
		new (_Rx) _Refoa(_Al_arg , ::std:: forward<_Arg0>(_Ax0) , ::std:: forward<_Arg1>(_Ax1), ::std:: forward<_Arg2>(_Ax2), ::std:: forward<_Arg3>(_Ax3), ::std:: forward<_Arg4>(_Ax4), ::std:: forward<_Arg5>(_Ax5), ::std:: forward<_Arg6>(_Ax6), ::std:: forward<_Arg7>(_Ax7), ::std:: forward<_Arg8>(_Ax8) , ::std:: forward<_Arg9>(_Ax9));
	} catch (...) {
		_Alref.deallocate(_Rx, 1);
	throw;
	}

	shared_ptr<_Ty> _Ret;
	_Ret._Resetp0(_Rx->_Getptr(), _Rx);
	return (_Ret);
	}
 #line 65 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xxshared"





#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"






#line 279 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap1"
















































































































#line 57 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xfwrap"




















#line 1891 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"
 

 #line 1894 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	
template<class _Ty>
	class weak_ptr
		: public _Ptr_base<_Ty>
	{	
	typedef typename _Ptr_base<_Ty>::_Elem _Elem;

public:
	weak_ptr()
		{	
		}

	template<class _Ty2>
		weak_ptr(const shared_ptr<_Ty2>& _Other,
			typename enable_if<is_convertible<_Ty2 *, _Ty *>::value,
				void *>::type * = 0)
		{	
		this->_Resetw(_Other);
		}

	weak_ptr(const weak_ptr& _Other)
		{	
		this->_Resetw(_Other);
		}

	template<class _Ty2>
		weak_ptr(const weak_ptr<_Ty2>& _Other,
			typename enable_if<is_convertible<_Ty2 *, _Ty *>::value,
				void *>::type * = 0)
		{	
		this->_Resetw(_Other);
		}

	~weak_ptr()
		{	
		this->_Decwref();
		}

	weak_ptr& operator=(const weak_ptr& _Right)
		{	
		this->_Resetw(_Right);
		return (*this);
		}

	template<class _Ty2>
		weak_ptr& operator=(const weak_ptr<_Ty2>& _Right)
		{	
		this->_Resetw(_Right);
		return (*this);
		}

	template<class _Ty2>
		weak_ptr& operator=(shared_ptr<_Ty2>& _Right)
		{	
		this->_Resetw(_Right);
		return (*this);
		}

	void reset()
		{	
		this->_Resetw();
		}

	void swap(weak_ptr& _Other)
		{	
		this->_Swap(_Other);
		}

	bool expired() const
		{	
		return (this->_Expired());
		}

	shared_ptr<_Ty> lock() const
		{	
		return (shared_ptr<_Elem>(*this, false));
		}
	};









template<class _Ty>
	void swap(weak_ptr<_Ty>& _W1, weak_ptr<_Ty>& _W2)
	{	
	_W1.swap(_W2);
	}

	
template<class _Ty> class enable_shared_from_this
	{	
public:
	typedef _Ty _EStype;

	shared_ptr<_Ty> shared_from_this()
		{	
		return (shared_ptr<_Ty>(_Wptr));
		}

	shared_ptr<const _Ty> shared_from_this() const
		{	
		return (shared_ptr<const _Ty>(_Wptr));
		}

protected:
	enable_shared_from_this()
		{	
		}

	enable_shared_from_this(const enable_shared_from_this&)
		{	
		}

	enable_shared_from_this& operator=(const enable_shared_from_this&)
		{	
		return (*this);
		}

	~enable_shared_from_this()
		{	
		}

private:
	template<class _Ty1,
		class _Ty2>
		friend void _Do_enable(
			_Ty1 *,
			enable_shared_from_this<_Ty2>*,
			_Ref_count_base *);

	mutable weak_ptr<_Ty> _Wptr;
	};

template<class _Ty1,
	class _Ty2>
	inline void _Do_enable(
		_Ty1 *_Ptr,
		enable_shared_from_this<_Ty2> *_Es,
		_Ref_count_base *_Refptr)
	{	
	_Es->_Wptr._Resetw(_Ptr, _Refptr);
	}
	}	
}
 #line 2045 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

 
namespace std {
	

	
template<class _Ty>
	struct default_delete
	{	
	typedef default_delete<_Ty> _Myt;

	default_delete()
		{	
		}

	template<class _Ty2>
		default_delete(const default_delete<_Ty2>&)
		{	
		}

	void operator()(_Ty *_Ptr) const
		{	
		if (0 < sizeof (_Ty))	
			delete _Ptr;
		}
	};

template<class _Ty>
	struct default_delete<_Ty[]>
	{	
	typedef default_delete<_Ty> _Myt;

	default_delete()
		{	
		}

	void operator()(_Ty *_Ptr) const
		{	
		if (0 < sizeof (_Ty))	
			delete[] _Ptr;
		}

	template<class _Other>
		void operator()(_Other *) const;	
	};

	
::std:: tr1::_No _Has_pointer_type(...);

template<class _Ty>
	::std:: tr1::_Yes _Has_pointer_type(_Ty *,
		typename _Ty::pointer * = 0);

template<class _Ty,
	class _Dx,
	bool>
	struct _Hold_pointer_type
	{	
	typedef _Ty *pointer;
	};

template<class _Ty,
	class _Dx>
	struct _Hold_pointer_type<_Ty, _Dx, true>
	{	
	typedef typename _Dx::pointer pointer;
	};

 



	
template<class _Ty,
	class _Dx,
	bool _Empty_deleter>
	class _Unique_ptr_base
	{	
public:
	typedef typename tr1::remove_reference<_Dx>::type _Dx_noref;
	typedef typename _Hold_pointer_type<_Ty, _Dx_noref, (sizeof (_Has_pointer_type((_Dx_noref *)0)) == sizeof (::std:: tr1::_Yes))>::pointer pointer;

	_Unique_ptr_base(pointer _Ptr, _Dx _Dt)
		: _Myptr(_Ptr), _Mydel(_Dt)
		{	
		}

	template<class _Ptr2,
		class _Dx2>
		_Unique_ptr_base(_Ptr2 _Ptr, _Dx2 _Dt)
		: _Myptr(_Ptr), _Mydel(_Dt)
		{	
		}

	_Dx_noref& get_deleter()
		{	
		return (_Mydel);
		}

	const _Dx_noref& get_deleter() const
		{	
		return (_Mydel);
		}

	pointer _Myptr;	
	_Dx _Mydel;		
	};

template<class _Ty,
	class _Dx>
	class _Unique_ptr_base<_Ty, _Dx, true>
		: public _Dx
	{	
public:
	typedef _Dx _Mybase;
	typedef typename tr1::remove_reference<_Dx>::type _Dx_noref;
	typedef typename _Hold_pointer_type<_Ty, _Dx_noref, (sizeof (_Has_pointer_type((_Dx_noref *)0)) == sizeof (::std:: tr1::_Yes))>::pointer pointer;

	_Unique_ptr_base(pointer _Ptr, _Dx _Dt)
		: _Myptr(_Ptr), _Mybase(_Dt)
		{	
		}

	template<class _Ptr2,
		class _Dx2>
		_Unique_ptr_base(_Ptr2 _Ptr, _Dx2 _Dt)
		: _Myptr(_Ptr), _Mybase(_Dt)
		{	
		}

	_Dx_noref& get_deleter()
		{	
		return (*this);
		}

	const _Dx_noref& get_deleter() const
		{	
		return (*this);
		}

	pointer _Myptr;	
	};

	
template<class _Ty,
	class _Dx>	
	class unique_ptr
		: public _Unique_ptr_base<_Ty, _Dx,
			tr1::is_empty<_Dx>::value
				|| tr1::is_same<default_delete<_Ty>, _Dx>::value>
	{	
public:
	typedef unique_ptr<_Ty, _Dx> _Myt;
	typedef _Unique_ptr_base<_Ty, _Dx,
		tr1::is_empty<_Dx>::value
			|| tr1::is_same<default_delete<_Ty>, _Dx>::value> _Mybase;
	typedef typename _Mybase::pointer pointer;
	typedef _Ty element_type;
	typedef _Dx deleter_type;

	unique_ptr()
		: _Mybase(pointer(), _Dx())
		{	
		static_assert(!is_pointer<_Dx>::value,
			"unique_ptr constructed with null deleter pointer");
		}

 
	unique_ptr(::std:: nullptr_t)
		: _Mybase(pointer(), _Dx())
		{	
		static_assert(!is_pointer<_Dx>::value,
			"unique_ptr constructed with null deleter pointer");
		}

	_Myt& operator=(::std:: nullptr_t)
		{	
		reset();
		return (*this);
		}
 #line 2227 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	explicit unique_ptr(pointer _Ptr)
		: _Mybase(_Ptr, _Dx())
		{	
		static_assert(!is_pointer<_Dx>::value,
			"unique_ptr constructed with null deleter pointer");
		}

	unique_ptr(pointer _Ptr,
		typename _If<tr1::is_reference<_Dx>::value, _Dx,
			const typename tr1::remove_reference<_Dx>::type&>::_Type _Dt)
		: _Mybase(_Ptr, _Dt)
		{	
		}

	unique_ptr(pointer _Ptr, typename tr1::remove_reference<_Dx>::type&& _Dt)
		: _Mybase(_Ptr, ::std:: move(_Dt))
		{	


		}

	unique_ptr(unique_ptr&& _Right)
		: _Mybase(_Right.release(),
			::std:: forward<_Dx>(_Right.get_deleter()))
		{	
		}

	template<class _Ty2,
		class _Dx2>
		unique_ptr(unique_ptr<_Ty2, _Dx2>&& _Right)
			: _Mybase(_Right.release(),
				::std:: forward<_Dx2>(_Right.get_deleter()))
		{	
		}

	template<class _Ty2,
		class _Dx2>
		_Myt& operator=(unique_ptr<_Ty2, _Dx2>&& _Right)
		{	
		reset(_Right.release());
		this->get_deleter() = ::std:: move(_Right.get_deleter());
		return (*this);
		}

	_Myt& operator=(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
			reset(_Right.release());
			this->get_deleter() = ::std:: move(_Right.get_deleter());
			}
		return (*this);
		}

	void swap(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
			_Swap_adl(this->_Myptr, _Right._Myptr);
			_Swap_adl(this->get_deleter(),
				_Right.get_deleter());
			}
		}

	void swap(_Myt& _Right)
		{	
		_Swap_adl(this->_Myptr, _Right._Myptr);
		_Swap_adl(this->get_deleter(),
			_Right.get_deleter());
		}

	~unique_ptr()
		{	
		_Delete();
		}

	typename tr1::add_reference<_Ty>::type operator*() const
		{	
		return (*this->_Myptr);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	pointer get() const
		{	
		return (this->_Myptr);
		}

	operator ::std:: _Bool_type() const
		{	
		return (this->_Myptr != pointer() ? (&::std:: _Bool_struct::_Member) : 0);
		}

	pointer release()
		{	
		pointer _Ans = this->_Myptr;
		this->_Myptr = pointer();
		return (_Ans);
		}

	void reset(pointer _Ptr = pointer())
		{	
		if (_Ptr != this->_Myptr)
			{	
			_Delete();
			this->_Myptr = _Ptr;
			}
		}

private:
	void _Delete()
		{	
		if (this->_Myptr != pointer())
			this->get_deleter()(this->_Myptr);
		}

	unique_ptr(const _Myt&);	
	template<class _Ty2,
		class _Dx2>
		unique_ptr(const unique_ptr<_Ty2, _Dx2>&);	

	_Myt& operator=(const _Myt&);	
	template<class _Ty2,
		class _Dx2>
		_Myt& operator=(const unique_ptr<_Ty2, _Dx2>&);	
	};

	
template<class _Ty,
	class _Dx>
	class unique_ptr<_Ty[], _Dx>
		: public _Unique_ptr_base<_Ty, _Dx,
			tr1::is_empty<_Dx>::value
				|| tr1::is_same<default_delete<_Ty[]>, _Dx>::value>
	{	
public:
	typedef unique_ptr<_Ty[], _Dx> _Myt;
	typedef _Unique_ptr_base<_Ty, _Dx,
		tr1::is_empty<_Dx>::value
			|| tr1::is_same<default_delete<_Ty[]>, _Dx>::value> _Mybase;
	typedef typename _Mybase::pointer pointer;
	typedef _Ty element_type;
	typedef _Dx deleter_type;

	unique_ptr()
		: _Mybase(pointer(), _Dx())
		{	
		static_assert(!is_pointer<_Dx>::value,
			"unique_ptr constructed with null deleter pointer");
		}

	explicit unique_ptr(pointer _Ptr)
		: _Mybase(_Ptr, _Dx())
		{	
		static_assert(!is_pointer<_Dx>::value,
			"unique_ptr constructed with null deleter pointer");
		}

	unique_ptr(pointer _Ptr,
		typename _If<tr1::is_reference<_Dx>::value, _Dx,
			const typename tr1::remove_reference<_Dx>::type&>::_Type _Dt)
		: _Mybase(_Ptr, _Dt)
		{	
		}

public:
	unique_ptr(pointer _Ptr, typename tr1::remove_reference<_Dx>::type&& _Dt)
		: _Mybase(_Ptr, ::std:: move(_Dt))
		{	


		}

	unique_ptr(unique_ptr&& _Right)
		: _Mybase(_Right.release(),
			::std:: forward<_Dx>(_Right.get_deleter()))
		{	
		}

private:
	template<class _Ty2,
		class _Dx2>
		unique_ptr(unique_ptr<_Ty2, _Dx2>&& _Right);	

	template<class _Ty2,
		class _Dx2>
		_Myt& operator=(unique_ptr<_Ty2, _Dx2>&& _Right);	

public:
	_Myt& operator=(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
			reset(_Right.release());
			this->get_deleter() = ::std:: move(_Right.get_deleter());
			}
		return (*this);
		}

	void swap(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
			_Swap_adl(this->_Myptr, _Right._Myptr);
			_Swap_adl(this->get_deleter(),
				_Right.get_deleter());
			}
		}

 
	unique_ptr(::std:: nullptr_t)
		: _Mybase(pointer(), _Dx())
		{	
		static_assert(!is_pointer<_Dx>::value,
			"unique_ptr constructed with null deleter pointer");
		}

	_Myt& operator=(::std:: nullptr_t)
		{	
		reset();
		return (*this);
		}

	void reset(::std:: nullptr_t)
		{	
		if (this->_Myptr != 0)
			{	
			_Delete();
			this->_Myptr = 0;
			}
		}
 #line 2464 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

	void swap(_Myt& _Right)
		{	
		_Swap_adl(this->_Myptr, _Right._Myptr);
		_Swap_adl(this->get_deleter(), _Right.get_deleter());
		}

	~unique_ptr()
		{	
		_Delete();
		}

	typename tr1::add_reference<_Ty>::type operator[](size_t _Idx) const
		{	
		return (this->_Myptr[_Idx]);
		}

	pointer get() const
		{	
		return (this->_Myptr);
		}

	operator ::std:: _Bool_type() const
		{	
		return (this->_Myptr != 0 ? (&::std:: _Bool_struct::_Member) : 0);
		}

	pointer release()
		{	
		pointer _Ans = this->_Myptr;
		this->_Myptr = pointer();
		return (_Ans);
		}

	void reset(pointer _Ptr = pointer())
		{	
		if (_Ptr != this->_Myptr)
			{	
			_Delete();
			this->_Myptr = _Ptr;
			}
		}

private:
	template<class _Ptr2>
		explicit unique_ptr(_Ptr2);	

	template<class _Ptr2,
		class _Dx2>
		unique_ptr(_Ptr2, _Dx2);	

	unique_ptr(const _Myt&);	
	template<class _Ty2,
		class _Dx2>
		unique_ptr(const unique_ptr<_Ty2, _Dx2>&);	

	_Myt& operator=(const _Myt&);	
	template<class _Ty2,
		class _Dx2>
		_Myt& operator=(const unique_ptr<_Ty2, _Dx2>&);	

	template<class _Ptr2>
		void reset(_Ptr2);	

	void _Delete()
		{	
		this->get_deleter()(this->_Myptr);
		}
	};

template<class _Ty,
	class _Dx>
	void swap(unique_ptr<_Ty, _Dx>& _Left,
		unique_ptr<_Ty, _Dx>& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Ty,
	class _Dx>
	void swap(unique_ptr<_Ty, _Dx>& _Left,
		unique_ptr<_Ty, _Dx>&& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Ty,
	class _Dx>
	void swap(unique_ptr<_Ty, _Dx>&& _Left,
		unique_ptr<_Ty, _Dx>& _Right)
	{	
	_Right.swap(_Left);
	}

template<class _Ty1,
	class _Dx1,
	class _Ty2,
	class _Dx2>
	bool operator==(const unique_ptr<_Ty1, _Dx1>& _Left,
		const unique_ptr<_Ty2, _Dx2>& _Right)
	{	
	return (_Left.get() == _Right.get());
	}

template<class _Ty1,
	class _Dx1,
	class _Ty2,
	class _Dx2>
	bool operator!=(const unique_ptr<_Ty1, _Dx1>& _Left,
		const unique_ptr<_Ty2, _Dx2>& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _Ty1,
	class _Dx1,
	class _Ty2,
	class _Dx2>
	bool operator<(const unique_ptr<_Ty1, _Dx1>& _Left,
		const unique_ptr<_Ty2, _Dx2>& _Right)
	{	
	return (_Left.get() < _Right.get());
	}

template<class _Ty1,
	class _Dx1,
	class _Ty2,
	class _Dx2>
	bool operator>=(const unique_ptr<_Ty1, _Dx1>& _Left,
		const unique_ptr<_Ty2, _Dx2>& _Right)
	{	
	return (!(_Left < _Right));
	}

template<class _Ty1,
	class _Dx1,
	class _Ty2,
	class _Dx2>
	bool operator>(const unique_ptr<_Ty1, _Dx1>& _Left,
		const unique_ptr<_Ty2, _Dx2>& _Right)
	{	
	return (_Right < _Left);
	}

template<class _Ty1,
	class _Dx1,
	class _Ty2,
	class _Dx2>
	bool operator<=(const unique_ptr<_Ty1, _Dx1>& _Left,
		const unique_ptr<_Ty2, _Dx2>& _Right)
	{	
	return (!(_Right < _Left));
	}

		
	namespace pointer_safety {
enum pointer_safety {	
	relaxed,
	preferred,
	strict
	};
	}	

typedef pointer_safety::pointer_safety _Pointer_safety;

inline void declare_reachable(void *)
	{	
	}

template<class _Ty> inline
	_Ty *undeclare_reachable(_Ty *_Ptr)
	{	
	return (_Ptr);
	}

inline void declare_no_pointers(char *, size_t)
	{	
	}

inline void undeclare_no_pointers(char *, size_t)
	{	
	}

inline _Pointer_safety get_pointer_safety()
	{	
	return (pointer_safety::relaxed);
	}

 
using tr1::allocate_shared;
using tr1::bad_weak_ptr;
using tr1::const_pointer_cast;
using tr1::dynamic_pointer_cast;
using tr1::enable_shared_from_this;
using tr1::get_deleter;
using tr1::make_shared;
using tr1::shared_ptr;
using tr1::static_pointer_cast;
using tr1::swap;
using tr1::weak_ptr;
 #line 2665 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

		
template<class _Ty>
	struct owner_less;	

template<class _Ty>
	struct owner_less<shared_ptr<_Ty> >
		: public binary_function<shared_ptr<_Ty>, shared_ptr<_Ty>, bool>
	{	
	bool operator()(const shared_ptr<_Ty>& _Left,
		const shared_ptr<_Ty>& _Right) const
		{	
		return (_Left.owner_before(_Right));
		}

	bool operator()(const shared_ptr<_Ty>& _Left,
		const weak_ptr<_Ty>& _Right) const
		{	
		return (_Left.owner_before(_Right));
		}

	bool operator()(const weak_ptr<_Ty>& _Left,
		const shared_ptr<_Ty>& _Right) const
		{	
		return (_Left.owner_before(_Right));
		}
	};

template<class _Ty>
	struct owner_less<weak_ptr<_Ty> >
		: public binary_function<weak_ptr<_Ty>, weak_ptr<_Ty>, bool>
	{	
	bool operator()(const weak_ptr<_Ty>& _Left,
		const weak_ptr<_Ty>& _Right) const
		{	
		return (_Left.owner_before(_Right));
		}

	bool operator()(const weak_ptr<_Ty>& _Left,
		const shared_ptr<_Ty>& _Right) const
		{	
		return (_Left.owner_before(_Right));
		}

	bool operator()(const shared_ptr<_Ty>& _Left,
		const weak_ptr<_Ty>& _Right) const
		{	
		return (_Left.owner_before(_Right));
		}
	};
}
 #line 2717 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"

 

 #pragma warning(pop)
 #pragma pack(pop)

#line 2724 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"
#line 2725 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\memory"























#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"

#pragma once






 #pragma pack(push,8)
 #pragma warning(push,3)
namespace std {




		
class logic_error
	: public exception
	{	
public:
	typedef exception _Mybase;

	explicit logic_error(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit logic_error(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class domain_error
	: public logic_error
	{	
public:
	typedef logic_error _Mybase;

	explicit domain_error(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit domain_error(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 70 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class invalid_argument
	: public logic_error
	{	
public:
	typedef logic_error _Mybase;

	explicit invalid_argument(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit invalid_argument(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 98 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class length_error
	: public logic_error
	{	
public:
	typedef logic_error _Mybase;

	explicit length_error(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit length_error(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 126 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class out_of_range
	: public logic_error
	{	
public:
	typedef logic_error _Mybase;

	explicit out_of_range(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit out_of_range(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 154 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class runtime_error
	: public exception
	{	
public:
	typedef exception _Mybase;

	explicit runtime_error(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit runtime_error(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 182 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class overflow_error
	: public runtime_error
	{	
public:
	typedef runtime_error _Mybase;

	explicit overflow_error(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit overflow_error(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 210 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class underflow_error
	: public runtime_error
	{	
public:
	typedef runtime_error _Mybase;

	explicit underflow_error(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit underflow_error(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 238 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};

		
class range_error
	: public runtime_error
	{	
public:
	typedef runtime_error _Mybase;

	explicit range_error(const string& _Message)
		: _Mybase(_Message.c_str())
		{	
		}

	explicit range_error(const char *_Message)
		: _Mybase(_Message)
		{	
		}

 

 





#line 266 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
	};
}
 #pragma warning(pop)
 #pragma pack(pop)

#line 272 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
#line 273 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"





#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

 #pragma pack(push,8)
 #pragma warning(push,3)

namespace std {
		
template<class _Mylist, class _Base = _Iterator_base0>
	class _List_unchecked_const_iterator
		: public _Iterator012<bidirectional_iterator_tag,
			typename _Mylist::value_type,
			typename _Mylist::difference_type,
			typename _Mylist::const_pointer,
			typename _Mylist::const_reference,
			_Base>
	{	
public:
	typedef _List_unchecked_const_iterator<_Mylist, _Base> _Myiter;
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::const_pointer pointer;
	typedef typename _Mylist::const_reference reference;

	_List_unchecked_const_iterator()
		: _Ptr(0)
		{	
		}

	_List_unchecked_const_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Ptr(_Pnode)
		{	
		this->_Adopt(_Plist);
		}

	reference operator*() const
		{	
		return (_Mylist::_Myval(_Ptr));
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myiter& operator++()
		{	
		_Ptr = _Mylist::_Nextnode(_Ptr);
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
		_Ptr = _Mylist::_Prevnode(_Ptr);
		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	bool operator==(const _Myiter& _Right) const
		{	
		return (_Ptr == _Right._Ptr);
		}

	bool operator!=(const _Myiter& _Right) const
		{	
		return (!(*this == _Right));
		}

	_Nodeptr _Mynode() const
		{	
		return (_Ptr);
		}

	_Nodeptr _Ptr;	
	};

	
template<class _Mylist>
	class _List_unchecked_iterator
		: public _List_unchecked_const_iterator<_Mylist>
	{	
public:
	typedef _List_unchecked_iterator<_Mylist> _Myiter;
	typedef _List_unchecked_const_iterator<_Mylist> _Mybase;
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::pointer pointer;
	typedef typename _Mylist::reference reference;

	_List_unchecked_iterator()
		{	
		}

	_List_unchecked_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Mybase(_Pnode, _Plist)
		{	
		}

	reference operator*() const
		{	
		return ((reference)**(_Mybase *)this);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myiter& operator++()
		{	
		++(*(_Mybase *)this);
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
		--(*(_Mybase *)this);
		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}
	};

	
template<class _Mylist>
	class _List_const_iterator
		: public _List_unchecked_const_iterator<_Mylist, _Iterator_base>
	{	
public:
	typedef _List_const_iterator<_Mylist> _Myiter;
	typedef _List_unchecked_const_iterator<_Mylist, _Iterator_base> _Mybase;
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::const_pointer pointer;
	typedef typename _Mylist::const_reference reference;

	_List_const_iterator()
		: _Mybase()
		{	
		}

	_List_const_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Mybase(_Pnode, _Plist)
		{	
		}

	typedef _List_unchecked_const_iterator<_Mylist> _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
		{	
		this->_Ptr = _Right._Ptr;
		return (*this);
		}

	_Unchecked_type _Unchecked() const
		{	
		return (_Unchecked_type(this->_Ptr, (_Mylist *)this->_Getcont()));
		}

	reference operator*() const
		{	
 








#line 212 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"



#line 216 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		return (_Mylist::_Myval(this->_Ptr));
		}

	_Myiter& operator++()
		{	
 








#line 232 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"



#line 236 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		this->_Ptr = _Mylist::_Nextnode(this->_Ptr);
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
 









#line 261 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"





#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
		this->_Ptr = _Mylist::_Prevnode(this->_Ptr);
 #line 269 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	bool operator==(const _Myiter& _Right) const
		{	
 







#line 291 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"


#line 294 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		return (this->_Ptr == _Right._Ptr);
		}

	bool operator!=(const _Myiter& _Right) const
		{	
		return (!(*this == _Right));
		}
	};

template<class _Mylist> inline
	typename _List_const_iterator<_Mylist>::_Unchecked_type
		_Unchecked(_List_const_iterator<_Mylist> _Iter)
	{	
	return (_Iter._Unchecked());
	}

template<class _Mylist> inline
	_List_const_iterator<_Mylist>&
		_Rechecked(_List_const_iterator<_Mylist>& _Iter,
			typename _List_const_iterator<_Mylist>
				::_Unchecked_type _Right)
	{	
	return (_Iter._Rechecked(_Right));
	}

	
template<class _Mylist>
	class _List_iterator
		: public _List_const_iterator<_Mylist>
	{	
public:
	typedef _List_iterator<_Mylist> _Myiter;
	typedef _List_const_iterator<_Mylist> _Mybase;
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::pointer pointer;
	typedef typename _Mylist::reference reference;

	_List_iterator()
		{	
		}

	_List_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Mybase(_Pnode, _Plist)
		{	
		}

	typedef _List_unchecked_iterator<_Mylist> _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
		{	
		this->_Ptr = _Right._Ptr;
		return (*this);
		}

	_Unchecked_type _Unchecked() const
		{	
		return (_Unchecked_type(this->_Ptr, (_Mylist *)this->_Getcont()));
		}

	reference operator*() const
		{	
		return ((reference)**(_Mybase *)this);
		}

	pointer operator->() const
		{	
		return (&**this);
		}

	_Myiter& operator++()
		{	
		++(*(_Mybase *)this);
		return (*this);
		}

	_Myiter operator++(int)
		{	
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	
		--(*(_Mybase *)this);
		return (*this);
		}

	_Myiter operator--(int)
		{	
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}
	};

template<class _Mylist> inline
	typename _List_iterator<_Mylist>::_Unchecked_type
		_Unchecked(_List_iterator<_Mylist> _Iter)
	{	
	return (_Iter._Unchecked());
	}

template<class _Mylist> inline
	_List_iterator<_Mylist>&
		_Rechecked(_List_iterator<_Mylist>& _Iter,
			typename _List_iterator<_Mylist>
				::_Unchecked_type _Right)
	{	
	return (_Iter._Rechecked(_Right));
	}

		
template<class _Ty,
	class _Alloc>
	class _List_nod
		: public _Container_base
	{	
public:
	typedef typename _Alloc::template rebind<_Ty>::other _Alty;
	typedef typename _Alty::size_type size_type;

	struct _Node;
	typedef _Node *_Nodeptr;	
	typedef _Nodeptr& _Nodepref;

	struct _Node
		{	
		_Nodeptr _Next;	
		_Nodeptr _Prev;	
		_Ty _Myval;	

	private:
		_Node& operator=(const _Node&);
		};

 
	_List_nod(_Alloc _Al)
		: _Alnod(_Al), _Alval(_Al)
		{	
		}

 



















#line 462 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

	_Nodeptr _Myhead;	
	size_type _Mysize;	

	typename _Alloc::template rebind<_Node>::other
		_Alnod;	
	_Alty _Alval;	
	};

		
template<class _Ty,
	class _Alloc>
	class _List_val
		: public _List_nod<_Ty, _Alloc>
	{	
public:
	typedef _List_nod<_Ty, _Alloc> _Mybase;
	typedef typename _Mybase::_Nodeptr _Nodeptr;
	typedef typename _Mybase::_Nodepref _Nodepref;
	typedef typename _Alloc::template rebind<_Ty>::other _Alty;

	typedef typename _Alty::size_type size_type;
	typedef typename _Alty::difference_type difference_type;
	typedef typename _Alty::pointer pointer;
	typedef typename _Alty::const_pointer const_pointer;
	typedef typename _Alty::reference reference;
	typedef typename _Alty::const_reference const_reference;
	typedef typename _Alty::value_type value_type;

	_List_val(_Alloc _Al = _Alloc())
		: _Mybase(_Al)
		{	
		this->_Mysize = 0;
		this->_Myhead = this->_Alnod.allocate(1);
		this->_Nextnode(this->_Myhead) = this->_Myhead;
		this->_Prevnode(this->_Myhead) = this->_Myhead;
		}

	~_List_val()
		{	
		this->_Alnod.deallocate(this->_Myhead, 1);
		}

	_Nodeptr _Buynode(_Nodeptr _Next,
		_Nodeptr _Prev, const _Ty& _Val)
		{	
		_Nodeptr _Pnode = this->_Alnod.allocate(1);

		try {
		this->_Nextnode(_Pnode) = _Next;
		this->_Prevnode(_Pnode) = _Prev;
		_Cons_val(this->_Alval, ::std:: addressof(this->_Myval(_Pnode)), _Val);
		} catch (...) {
		this->_Alnod.deallocate(_Pnode, 1);
		throw;
		}

		return (_Pnode);
		}

	_Nodeptr _Buynode(_Nodeptr _Next,
		_Nodeptr _Prev)
		{	
		_Nodeptr _Pnode = this->_Alnod.allocate(1);

		try {
		this->_Nextnode(_Pnode) = _Next;
		this->_Prevnode(_Pnode) = _Prev;
		_Uninitialized_default_fill_n(::std:: addressof(this->_Myval(_Pnode)), 1,
			(_Ty *)0, this->_Alval);
		} catch (...) {
		this->_Alnod.deallocate(_Pnode, 1);
		throw;
		}

		return (_Pnode);
		}

	template<class _Valty>
		_Nodeptr _Buynode(_Nodeptr _Next,
		_Nodeptr _Prev, _Valty&& _Val)
		{	
		_Nodeptr _Pnode = this->_Alnod.allocate(1);

		try {
		this->_Nextnode(_Pnode) = _Next;
		this->_Prevnode(_Pnode) = _Prev;
		_Cons_val(this->_Alval, ::std:: addressof(this->_Myval(_Pnode)),
			::std:: forward<_Valty>(_Val));
		} catch (...) {
		this->_Alnod.deallocate(_Pnode, 1);
		throw;
		}

		return (_Pnode);
		}

	static _Nodepref _Nextnode(_Nodeptr _Pnode)
		{	
		return ((_Nodepref)(*_Pnode)._Next);
		}

	static _Nodepref _Prevnode(_Nodeptr _Pnode)
		{	
		return ((_Nodepref)(*_Pnode)._Prev);
		}

	static reference _Myval(_Nodeptr _Pnode)
		{	
		return ((reference)(*_Pnode)._Myval);
		}
	};

		
template<class _Ty,
	class _Ax = allocator<_Ty> >
	class list
		: public _List_val<_Ty, _Ax>
	{	
public:
	typedef list<_Ty, _Ax> _Myt;
	typedef _List_val<_Ty, _Ax> _Mybase;
	typedef typename _Mybase::_Alty _Alloc;
	typedef typename _Mybase::_Node _Node;
	typedef typename _Mybase::_Nodeptr _Nodeptr;

	typedef _Alloc allocator_type;
	typedef typename _Alloc::size_type size_type;
	typedef typename _Alloc::difference_type difference_type;
	typedef typename _Alloc::pointer pointer;
	typedef typename _Alloc::const_pointer const_pointer;
	typedef typename _Alloc::reference reference;
	typedef typename _Alloc::const_reference const_reference;
	typedef typename _Alloc::value_type value_type;

	typedef _List_const_iterator<_Mybase>
		const_iterator;
	typedef _List_iterator<_Mybase>
		iterator;

	typedef ::std:: reverse_iterator<iterator> reverse_iterator;
	typedef ::std:: reverse_iterator<const_iterator> const_reverse_iterator;

	list()
		: _Mybase()
		{	
		}

	explicit list(const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		}

	explicit list(size_type _Count)
		: _Mybase()
		{	
		resize(_Count);
		}

	list(size_type _Count, const _Ty& _Val)
		: _Mybase()
		{	
		_Construct_n(_Count, _Val);
		}

	list(size_type _Count, const _Ty& _Val, const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Construct_n(_Count, _Val);
		}

	list(const _Myt& _Right)
		: _Mybase(_Right._Alval)
		{	
		try {
		insert(begin(), _Right.begin(), _Right.end());
		} catch (...) {
		_Tidy();
		throw;
		}
		}

	template<class _Iter>
		list(_Iter _First, _Iter _Last)
		: _Mybase()
		{	
		_Construct(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		list(_Iter _First, _Iter _Last, const _Alloc& _Al)
		: _Mybase(_Al)
		{	
		_Construct(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Construct(_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	
		_Construct_n((size_type)_Count, (_Ty)_Val);
		}

	template<class _Iter>
		void _Construct(_Iter _First,
			_Iter _Last, input_iterator_tag)
		{	
		try {
		insert(begin(), _First, _Last);
		} catch (...) {
		_Tidy();
		throw;
		}
		}

	void _Construct_n(size_type _Count,
		const _Ty& _Val)
		{	
		try {
		_Insert_n(begin(), _Count, _Val);
		} catch (...) {
		_Tidy();
		throw;
		}
		}

	list(_Myt&& _Right)
		: _Mybase(_Right._Alval)
		{	
		_Assign_rv(::std:: forward<_Myt>(_Right));
		}

	_Myt& operator=(_Myt&& _Right)
		{	
		_Assign_rv(::std:: forward<_Myt>(_Right));
		return (*this);
		}

	void _Assign_rv(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
			clear();
			if (!_Right.empty())
				_Splice(begin(), _Right, _Right.begin(), _Right.end(),
					_Right._Mysize);
			}
		}

	void push_front(_Ty&& _Val)
		{	
		_Insert_rv(begin(), ::std:: forward<_Ty>(_Val));
		}

	void push_back(_Ty&& _Val)
		{	
		_Insert_rv(end(), ::std:: forward<_Ty>(_Val));
		}

	template<class _Valty>
		void emplace_front(_Valty&& _Val)
		{	
		_Insert_rv(begin(), ::std:: forward<_Valty>(_Val));
		}

	template<class _Valty>
		void emplace_back(_Valty&& _Val)
		{	
		_Insert_rv(end(), ::std:: forward<_Valty>(_Val));
		}

	template<class _Valty>
		iterator insert(const_iterator _Where, _Valty&& _Val)
		{	
		return (emplace(_Where, ::std:: forward<_Valty>(_Val)));
		}

	template<class _Valty>
		iterator emplace(const_iterator _Where, _Valty&& _Val)
		{	
		_Insert_rv(_Where, ::std:: forward<_Valty>(_Val));
		return (_Make_iter(--_Where));
		}

	template<class _Valty>
		void _Insert_rv(const_iterator _Where,
		_Valty&& _Val)
		{	
 


#line 753 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		_Nodeptr _Pnode = _Where._Mynode();
		_Nodeptr _Newnode =
			this->_Buynode(_Pnode, this->_Prevnode(_Pnode),
				::std:: forward<_Valty>(_Val));
		_Incsize(1);
		this->_Prevnode(_Pnode) = _Newnode;
		this->_Nextnode(this->_Prevnode(_Newnode)) = _Newnode;
		}

	void swap(_Myt&& _Right)
		{	
		_Assign_rv(::std:: forward<_Myt>(_Right));
		}

	~list()
		{	
		_Tidy();
		}

	_Myt& operator=(const _Myt& _Right)
		{	
		if (this != &_Right)
			assign(_Right.begin(), _Right.end());
		return (*this);
		}

	iterator begin()
		{	
		return (iterator(this->_Nextnode(this->_Myhead), this));
		}

	const_iterator begin() const
		{	
		return (const_iterator(this->_Nextnode(this->_Myhead), this));
		}

	iterator end()
		{	
		return (iterator(this->_Myhead, this));
		}

	const_iterator end() const
		{	
		return (const_iterator(this->_Myhead, this));
		}

	iterator _Make_iter(const_iterator _Where) const
		{	
		return (iterator(_Where._Ptr, this));
		}

	reverse_iterator rbegin()
		{	
		return (reverse_iterator(end()));
		}

	const_reverse_iterator rbegin() const
		{	
		return (const_reverse_iterator(end()));
		}

	reverse_iterator rend()
		{	
		return (reverse_iterator(begin()));
		}

	const_reverse_iterator rend() const
		{	
		return (const_reverse_iterator(begin()));
		}

 
	const_iterator cbegin() const
		{	
		return (((const _Myt *)this)->begin());
		}

	const_iterator cend() const
		{	
		return (((const _Myt *)this)->end());
		}

	const_reverse_iterator crbegin() const
		{	
		return (((const _Myt *)this)->rbegin());
		}

	const_reverse_iterator crend() const
		{	
		return (((const _Myt *)this)->rend());
		}
 #line 846 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

	void resize(size_type _Newsize)
		{	
		if (this->_Mysize < _Newsize)
			{	
			size_type _Count = 0;
			try {
			for (; this->_Mysize < _Newsize; ++_Count)
				_Insert(end());
			} catch (...) {
			for (; 0 < _Count; --_Count)
				pop_back();	
			throw;
			}
			}
		else
			while (_Newsize < this->_Mysize)
				pop_back();
		}

	void resize(size_type _Newsize, const _Ty& _Val)
		{	
		if (this->_Mysize < _Newsize)
			_Insert_n(end(), _Newsize - this->_Mysize, _Val);
		else
			while (_Newsize < this->_Mysize)
				pop_back();
		}

	size_type size() const
		{	
		return (this->_Mysize);
		}

	size_type max_size() const
		{	
		return (this->_Alval.max_size());
		}

	bool empty() const
		{	
		return (this->_Mysize == 0);
		}

	allocator_type get_allocator() const
		{	
		return (this->_Alval);
		}

	reference front()
		{	
		return (*begin());
		}

	const_reference front() const
		{	
		return (*begin());
		}

	reference back()
		{	
		return (*(--end()));
		}

	const_reference back() const
		{	
		return (*(--end()));
		}

	void push_front(const _Ty& _Val)
		{	
		_Insert(begin(), _Val);
		}

	void pop_front()
		{	
		erase(begin());
		}

	void push_back(const _Ty& _Val)
		{	
		_Insert(end(), _Val);
		}

	void pop_back()
		{	
		erase(--end());
		}

	template<class _Iter>
		void assign(_Iter _First, _Iter _Last)
		{	
		_Assign(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Assign(_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	
		_Assign_n((size_type)_Count, (_Ty)_Val);
		}

	template<class _Iter>
		void _Assign(_Iter _First, _Iter _Last, input_iterator_tag)
		{	
		clear();
		insert(begin(), _First, _Last);
		}

	void assign(size_type _Count, const _Ty& _Val)
		{	
		_Assign_n(_Count, _Val);
		}

	iterator insert(const_iterator _Where, const _Ty& _Val)
		{	
		_Insert(_Where, _Val);
		return (_Make_iter(--_Where));
		}

	void _Insert(const_iterator _Where,
		const _Ty& _Val)
		{	
 


#line 972 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		_Nodeptr _Pnode = _Where._Mynode();
		_Nodeptr _Newnode =
			this->_Buynode(_Pnode, this->_Prevnode(_Pnode), _Val);
		_Incsize(1);
		this->_Prevnode(_Pnode) = _Newnode;
		this->_Nextnode(this->_Prevnode(_Newnode)) = _Newnode;
		}

	void _Insert(const_iterator _Where)
		{	
 


#line 987 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		_Nodeptr _Pnode = _Where._Mynode();
		_Nodeptr _Newnode =
			this->_Buynode(_Pnode, this->_Prevnode(_Pnode));
		_Incsize(1);
		this->_Prevnode(_Pnode) = _Newnode;
		this->_Nextnode(this->_Prevnode(_Newnode)) = _Newnode;
		}

	void insert(const_iterator _Where, size_type _Count, const _Ty& _Val)
		{	
		_Insert_n(_Where, _Count, _Val);
		}

	template<class _Iter>
		void insert(const_iterator _Where, _Iter _First, _Iter _Last)
		{	
		_Insert(_Where, _First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Insert(const_iterator _Where, _Iter _Count, _Iter _Val,
			_Int_iterator_tag)
		{	
		_Insert_n(_Where, (size_type)_Count, (_Ty)_Val);
		}

	template<class _Iter>
		void _Insert(const_iterator _Where,
			_Iter _First, _Iter _Last, input_iterator_tag)
		{	
		size_type _Num = 0;

		try {
		for (; _First != _Last; ++_First, ++_Num)
			_Insert(_Where, *_First);
		} catch (...) {
		for (; 0 < _Num; --_Num)
			{	
			const_iterator _Before = _Where;
			erase(--_Before);
			}
		throw;
		}
		}

	template<class _Iter>
		void _Insert(const_iterator _Where,
			_Iter _First, _Iter _Last, forward_iterator_tag)
		{	
		;
		_Iter _Next = _First;

		try {
		for (; _First != _Last; ++_First)
			_Insert(_Where, *_First);
		} catch (...) {
		for (; _Next != _First; ++_Next)
			{	
			const_iterator _Before = _Where;
			erase(--_Before);
			}
		throw;
		}
		}

	iterator erase(const_iterator _Where)
		{	
 





#line 1062 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
		_Nodeptr _Pnode = (_Where++)._Mynode();
 #line 1064 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		if (_Pnode != this->_Myhead)
			{	
			this->_Nextnode(this->_Prevnode(_Pnode)) =
				this->_Nextnode(_Pnode);
			this->_Prevnode(this->_Nextnode(_Pnode)) =
				this->_Prevnode(_Pnode);

			_Dest_val(this->_Alnod, _Pnode);
			this->_Alnod.deallocate(_Pnode, 1);

			--this->_Mysize;
			}
		return (_Make_iter(_Where));
		}

	iterator erase(const_iterator _First, const_iterator _Last)
		{	
		if (_First == begin() && _Last == end())
			{	
			clear();
			return (end());
			}
		else
			{	
			while (_First != _Last)
				_First = erase(_First);
			return (_Make_iter(_Last));
			}
		}

	void clear()
		{	
 

#line 1100 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		_Nodeptr _Pnext;
		_Nodeptr _Pnode = this->_Nextnode(this->_Myhead);
		this->_Nextnode(this->_Myhead) = this->_Myhead;
		this->_Prevnode(this->_Myhead) = this->_Myhead;
		this->_Mysize = 0;

		for (; _Pnode != this->_Myhead; _Pnode = _Pnext)
			{	
			_Pnext = this->_Nextnode(_Pnode);

			_Dest_val(this->_Alnod, _Pnode);
			this->_Alnod.deallocate(_Pnode, 1);
			}
		}

	void swap(_Myt& _Right)
		{	
		if (this == &_Right)
			;	
		else if (this->_Alval == _Right._Alval)
			{	
			this->_Swap_all(_Right);
			::std:: swap(this->_Myhead, _Right._Myhead);
			::std:: swap(this->_Mysize, _Right._Mysize);
			}
		else
			{	
			iterator _Where = begin();
			splice(_Where, _Right);
			_Right.splice(_Right.begin(), *this, _Where, end());
			}
		}

	void splice(const_iterator _Where, _Myt& _Right)
		{	
		if (this != &_Right && !_Right.empty())
			{	
			_Splice(_Where, _Right, _Right.begin(), _Right.end(),
				_Right._Mysize);
			}
		}

	void splice(const_iterator _Where, _Myt& _Right,
		const_iterator _First)
		{	
 




#line 1152 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
		if (_First != _Right.end())
 #line 1154 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

			{	
			const_iterator _Last = _First;
			++_Last;
			if (this != &_Right
				|| (_Where != _First && _Where != _Last))
				_Splice(_Where, _Right, _First, _Last, 1);
			}
		}

	void splice(const_iterator _Where,
		_Myt& _Right, const_iterator _First, const_iterator _Last)
		{	
		if (_First != _Last && (this != &_Right || _Where != _Last))
			{	
			size_type _Count = 0;

			if (this == &_Right)
				;	
			else if (_First == _Right.begin() && _Last == _Right.end())
				_Count = _Right._Mysize;	
			else
				{	
				const_iterator _Next = _First;

				for (; _Next != _Last; ++_Next, ++_Count)
					if (_Next == _Right.end())
						_Xlength_error("list<T> bad splice");
				}
			_Splice(_Where, _Right, _First, _Last, _Count);
			}
		}

	void remove(const _Ty& _Val_arg)
		{	
		const _Ty _Val = _Val_arg;	
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pnode = _Phead->_Next;

		while (_Pnode != _Phead)
			if (_Pnode->_Myval == _Val)
				{	
				const _Nodeptr _Pprev = _Pnode->_Prev;
				const _Nodeptr _Perase = _Pnode;
				_Pnode = _Pnode->_Next;

				_Pprev->_Next = _Pnode;
				_Pnode->_Prev = _Pprev;

				_Dest_val(this->_Alnod, _Perase);
				this->_Alnod.deallocate(_Perase, 1);
				--this->_Mysize;
				}
			else
				_Pnode = _Pnode->_Next;
		}

	template<class _Pr1>
		void remove_if(_Pr1 _Pred)
		{	
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pnode = _Phead->_Next;

		while (_Pnode != _Phead)
			if (_Pred(_Pnode->_Myval))
				{	
				const _Nodeptr _Pprev = _Pnode->_Prev;
				const _Nodeptr _Perase = _Pnode;
				_Pnode = _Pnode->_Next;

				_Pprev->_Next = _Pnode;
				_Pnode->_Prev = _Pprev;

				_Dest_val(this->_Alnod, _Perase);
				this->_Alnod.deallocate(_Perase, 1);
				--this->_Mysize;
				}
			else
				_Pnode = _Pnode->_Next;
		}

	void unique()
		{	
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pprev = _Phead->_Next;
		_Nodeptr _Pnode = _Pprev->_Next;

		while (_Pnode != _Phead)
			if (_Pprev->_Myval == _Pnode->_Myval)
				{	
				const _Nodeptr _Perase = _Pnode;
				_Pnode = _Pnode->_Next;

				_Pprev->_Next = _Pnode;
				_Pnode->_Prev = _Pprev;

				_Dest_val(this->_Alnod, _Perase);
				this->_Alnod.deallocate(_Perase, 1);
				--this->_Mysize;
				}
			else
				{	
				_Pprev = _Pnode;
				_Pnode = _Pnode->_Next;
				}
		}

	template<class _Pr2>
		void unique(_Pr2 _Pred)
		{	
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pprev = _Phead->_Next;
		_Nodeptr _Pnode = _Pprev->_Next;

		while (_Pnode != _Phead)
			if (_Pred(_Pprev->_Myval, _Pnode->_Myval))
				{	
				const _Nodeptr _Perase = _Pnode;
				_Pnode = _Pnode->_Next;

				_Pprev->_Next = _Pnode;
				_Pnode->_Prev = _Pprev;

				_Dest_val(this->_Alnod, _Perase);
				this->_Alnod.deallocate(_Perase, 1);
				--this->_Mysize;
				}
			else
				{	
				_Pprev = _Pnode;
				_Pnode = _Pnode->_Next;
				}
		}

	void merge(_Myt& _Right)
		{	
		if (&_Right != this)
			{	
			iterator _First1 = begin(), _Last1 = end();
			iterator _First2 = _Right.begin(), _Last2 = _Right.end();
			;
			;

			while (_First1 != _Last1 && _First2 != _Last2)
				if (((*_First2) < (*_First1)))
					{	
					iterator _Mid2 = _First2;
					_Splice(_First1, _Right, _First2, ++_Mid2, 1);
					_First2 = _Mid2;
					}
				else
					++_First1;

			if (_First2 != _Last2)
				_Splice(_Last1, _Right, _First2, _Last2,
					_Right._Mysize);	
			}
		}

	template<class _Pr3>
		void merge(_Myt& _Right, _Pr3 _Pred)
		{	
		if (&_Right != this)
			{	
			iterator _First1 = begin(), _Last1 = end();
			iterator _First2 = _Right.begin(), _Last2 = _Right.end();
			;
			;

			while (_First1 != _Last1 && _First2 != _Last2)
				if (_Pred(*_First2, *_First1))
					{	
					iterator _Mid2 = _First2;
					_Splice(_First1, _Right, _First2, ++_Mid2, 1);
					_First2 = _Mid2;
					}
				else
					++_First1;

			if (_First2 != _Last2)
				_Splice(_Last1, _Right, _First2, _Last2,
					_Right._Mysize);	
			}
		}

	void sort()
		{	
		if (2 <= this->_Mysize)
			{	
			const size_t _MAXBINS = 25;
			_Myt _Templist(this->_Alval), _Binlist[_MAXBINS + 1];
			size_t _Maxbin = 0;

			while (!empty())
				{	
				_Templist._Splice_same(_Templist.begin(), *this, begin(),
					++begin(), 1);

				size_t _Bin;
				for (_Bin = 0; _Bin < _Maxbin && !_Binlist[_Bin].empty();
					++_Bin)
					{	
					_Binlist[_Bin].merge(_Templist);
					_Binlist[_Bin].swap(_Templist);
					}

				if (_Bin == _MAXBINS)
					_Binlist[_Bin - 1].merge(_Templist);
				else
					{	
					_Binlist[_Bin].swap(_Templist);
					if (_Bin == _Maxbin)
						++_Maxbin;
					}
				}

			for (size_t _Bin = 1; _Bin < _Maxbin; ++_Bin)
				_Binlist[_Bin].merge(_Binlist[_Bin - 1]);	
			splice(begin(), _Binlist[_Maxbin - 1]);	
			}
		}

	template<class _Pr3>
		void sort(_Pr3 _Pred)
		{	
		if (2 <= this->_Mysize)
			{	
			const size_t _MAXBINS = 25;
			_Myt _Templist(this->_Alval), _Binlist[_MAXBINS + 1];
			size_t _Maxbin = 0;

			while (!empty())
				{	
				_Templist._Splice_same(_Templist.begin(), *this, begin(),
					++begin(), 1);

				size_t _Bin;
				for (_Bin = 0; _Bin < _Maxbin && !_Binlist[_Bin].empty();
					++_Bin)
					{	
					_Binlist[_Bin].merge(_Templist, _Pred);
					_Binlist[_Bin].swap(_Templist);
					}

				if (_Bin == _MAXBINS)
					_Binlist[_Bin - 1].merge(_Templist, _Pred);
				else
					{	
					_Binlist[_Bin].swap(_Templist);
					if (_Bin == _Maxbin)
						++_Maxbin;
					}
				}

			for (size_t _Bin = 1; _Bin < _Maxbin; ++_Bin)
				_Binlist[_Bin].merge(_Binlist[_Bin - 1],
					_Pred);	
			splice(begin(), _Binlist[_Maxbin - 1]);	
			}
		}

	void reverse()
		{	
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pnode = _Phead;

		for (; ; )
			{	
			const _Nodeptr _Pnext = _Pnode->_Next;
			_Pnode->_Next = _Pnode->_Prev;
			_Pnode->_Prev = _Pnext;

			if (_Pnext == _Phead)
				break;
			_Pnode = _Pnext;
			}
		}

	void _Splice(const_iterator _Where,
		_Myt& _Right, const_iterator _First, const_iterator _Last,
		size_type _Count)
		{	
 














#line 1452 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
		if (this->_Alval == _Right._Alval)
			_Splice_same(_Where, _Right, _First, _Last, _Count);
 #line 1455 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"

		else
			{	
			for (const_iterator _Next = _First; _Next != _Last; ++_Next)
				insert(_Where, (_Ty &&)*_Next);
			_Right.erase(_First, _Last);
			}
		}

	void _Splice_same(const_iterator _Where,
		_Myt& _Right, const_iterator _First, const_iterator _Last,
		size_type _Count)
		{	
		if (this != &_Right)
			{	
			_Incsize(_Count);
			_Right._Mysize -= _Count;
			}
		this->_Nextnode(this->_Prevnode(_First._Mynode())) =
			_Last._Mynode();
		this->_Nextnode(this->_Prevnode(_Last._Mynode())) =
			_Where._Mynode();
		this->_Nextnode(this->_Prevnode(_Where._Mynode())) =
			_First._Mynode();

		_Nodeptr _Pnode = this->_Prevnode(_Where._Mynode());
		this->_Prevnode(_Where._Mynode()) =
			this->_Prevnode(_Last._Mynode());
		this->_Prevnode(_Last._Mynode()) =
			this->_Prevnode(_First._Mynode());
		this->_Prevnode(_First._Mynode()) = _Pnode;
		}

	void _Assign_n(size_type _Count, const _Ty& _Val)
		{	
		_Ty _Tmp = _Val;	
		clear();
		_Insert_n(begin(), _Count, _Tmp);
		}

	void _Tidy()
		{	
		clear();
		}

	void _Insert_n(const_iterator _Where,
		size_type _Count, const _Ty& _Val)
		{	
		size_type _Countsave = _Count;

		try {
		for (; 0 < _Count; --_Count)
			_Insert(_Where, _Val);
		} catch (...) {
		for (; _Count < _Countsave; ++_Count)
			{	
			const_iterator _Before = _Where;
			erase(--_Before);
			}
		throw;
		}
		}

	void _Incsize(size_type _Count)
		{	
		if (max_size() - this->_Mysize - 1 < _Count)
			_Xlength_error("list<T> too long");
		this->_Mysize += _Count;
		}

 















#line 1542 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
	};

		

template<class _Ty,
	class _Alloc> inline
	void swap(list<_Ty, _Alloc>& _Left, list<_Ty, _Alloc>& _Right)
	{	
	_Left.swap(_Right);
	}

template<class _Ty,
	class _Alloc> inline
	void swap(list<_Ty, _Alloc>& _Left, list<_Ty, _Alloc>&& _Right)
	{	
	typedef list<_Ty, _Alloc> _Myt;
	_Left.swap(::std:: forward<_Myt>(_Right));
	}

template<class _Ty,
	class _Alloc> inline
	void swap(list<_Ty, _Alloc>&& _Left, list<_Ty, _Alloc>& _Right)
	{	
	typedef list<_Ty, _Alloc> _Myt;
	_Right.swap(::std:: forward<_Myt>(_Left));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator==(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	
	return (_Left.size() == _Right.size()
		&& equal(_Left.begin(), _Left.end(), _Right.begin()));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator!=(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator<(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	
	return (lexicographical_compare(_Left.begin(), _Left.end(),
		_Right.begin(), _Right.end()));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator>(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	
	return (_Right < _Left);
	}

template<class _Ty,
	class _Alloc> inline
	bool operator<=(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	
	return (!(_Right < _Left));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator>=(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	
	return (!(_Left < _Right));
	}
}
 #pragma warning(pop)
 #pragma pack(pop)

#line 1623 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"
#line 1624 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\list"























#line 28 "Y:\\mocha\\src\\mocha/roaster/utils/exception_handler.h"
#line 1 "Y:\\mocha\\src\\mocha/roaster/misc/class_traits/uncopyable.h"



namespace mocha{
  class Uncopyable {
  private:
    inline void operator = (const Uncopyable&) {};
    inline Uncopyable (const Uncopyable&) {};
  public:
    inline Uncopyable () {};
  };
}

#line 15 "Y:\\mocha\\src\\mocha/roaster/misc/class_traits/uncopyable.h"
#line 29 "Y:\\mocha\\src\\mocha/roaster/utils/exception_handler.h"
#line 1 "Y:\\mocha\\src\\mocha/roaster/smart_pointer/ref_count/shared_ptr.h"














#line 1 "Y:\\mocha\\src\\mocha/roaster/smart_pointer/ref_count/refcount.h"




#line 1 "Y:\\mocha\\src\\mocha/roaster/smart_pointer/ref_count/refcount_base.h"



#line 1 "Y:\\mocha\\src\\mocha/roaster/misc/class_traits/uncopyable.h"














#line 5 "Y:\\mocha\\src\\mocha/roaster/smart_pointer/ref_count/refcount_base.h"
#line 1 "Y:\\mocha\\src\\mocha/roaster/misc/atomic.h"













#line 15 "Y:\\mocha\\src\\mocha/roaster/misc/atomic.h"
#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"




















#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



















#pragma warning(push)
#line 22 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"
#pragma warning(disable:4001) 
#line 24 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"

#pragma once


































































































					    























































#line 181 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"












#line 194 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"
#line 195 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



#line 199 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"







#line 207 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"
#line 208 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"







#line 216 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"
#line 217 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"






#line 224 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"

#line 226 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"

#line 228 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"

#line 230 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"

#line 232 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"


#line 235 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"
#line 236 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"








#line 245 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



#line 249 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



#line 253 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



#line 257 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



#line 261 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



#line 265 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"

#line 267 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"



#pragma warning(pop)


#line 274 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"
#line 275 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"

#line 277 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\sdkddkver.h"


#line 22 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"





#pragma once
#line 29 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"

















































#line 79 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"




















#line 100 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"



#line 104 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"



#line 108 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"



#line 112 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"



#line 116 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"





#line 122 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"




#line 127 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"
#line 128 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"







#line 136 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"
#line 137 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"



#pragma warning(disable:4514)

#pragma warning(disable:4103)
#line 144 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"

#pragma warning(push)
#line 147 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"
#pragma warning(disable:4001)
#pragma warning(disable:4201)
#pragma warning(disable:4214)
#line 151 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\excpt.h"














#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\excpt.h"





#pragma pack(push,8)


extern "C" {
#line 31 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\excpt.h"




typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;











struct _EXCEPTION_RECORD;
struct _CONTEXT;

EXCEPTION_DISPOSITION __cdecl _except_handler (
      struct _EXCEPTION_RECORD *_ExceptionRecord,
      void * _EstablisherFrame,
       struct _CONTEXT *_ContextRecord,
       void * _DispatcherContext
    );





























#line 91 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\excpt.h"













unsigned long __cdecl _exception_code(void);
void *        __cdecl _exception_info(void);
int           __cdecl _abnormal_termination(void);













}
#line 122 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\excpt.h"

#pragma pack(pop)

#line 126 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\excpt.h"
#line 152 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdarg.h"














#pragma once






#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdarg.h"








#line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdarg.h"
#line 153 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"
#line 154 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windows.h"

#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"











#pragma once




#line 18 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"
#line 19 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"













#line 33 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"


extern "C" {
#line 37 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"











typedef unsigned long ULONG;
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef char *PSZ;
#line 56 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"













#line 70 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"



#line 74 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"



#line 78 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"



#line 82 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"



#line 86 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"











#line 98 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"






#line 105 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"



#line 109 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"
#line 110 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"


























#line 137 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"





#line 143 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"







#line 151 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\windef.h"

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL            *PBOOL;
typedef BOOL             *LPBOOL;
typedef BYTE            *PBYTE;
typedef BYTE             *LPBYTE;
typedef int             *PINT;
typedef int              *LPINT;
typedef WORD            *PWORD;
typedef WORD             *LPWORD;
typedef long             *LPLONG;
typedef DWORD           *PDWORD;
typedef DWORD            *LPDWORD;
typedef void             *LPVOID;
typedef const void       *LPCVOID;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;


#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





















#pragma warning(push)
#line 24 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#pragma warning(disable:4201) 
#pragma warning(disable:4214) 


extern "C" {
#line 30 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"













#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 20 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"


extern "C" {
#line 24 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"











































#line 68 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"










                                













  int __cdecl _isctype(  int _C,   int _Type);
  int __cdecl _isctype_l(  int _C,   int _Type,    _locale_t _Locale);
   int __cdecl isalpha(  int _C);
  int __cdecl _isalpha_l(  int _C,    _locale_t _Locale);
   int __cdecl isupper(  int _C);
  int __cdecl _isupper_l(  int _C,    _locale_t _Locale);
   int __cdecl islower(  int _C);
  int __cdecl _islower_l(  int _C,    _locale_t _Locale);
   int __cdecl isdigit(  int _C);
  int __cdecl _isdigit_l(  int _C,    _locale_t _Locale);
  int __cdecl isxdigit(  int _C);
  int __cdecl _isxdigit_l(  int _C,    _locale_t _Locale);
   int __cdecl isspace(  int _C);
  int __cdecl _isspace_l(  int _C,    _locale_t _Locale);
  int __cdecl ispunct(  int _C);
  int __cdecl _ispunct_l(  int _C,    _locale_t _Locale);
   int __cdecl isalnum(  int _C);
  int __cdecl _isalnum_l(  int _C,    _locale_t _Locale);
  int __cdecl isprint(  int _C);
  int __cdecl _isprint_l(  int _C,    _locale_t _Locale);
  int __cdecl isgraph(  int _C);
  int __cdecl _isgraph_l(  int _C,    _locale_t _Locale);
  int __cdecl iscntrl(  int _C);
  int __cdecl _iscntrl_l(  int _C,    _locale_t _Locale);
   int __cdecl toupper(  int _C);
   int __cdecl tolower(  int _C);
   int __cdecl _tolower(  int _C);
  int __cdecl _tolower_l(  int _C,    _locale_t _Locale);
   int __cdecl _toupper(  int _C);
  int __cdecl _toupper_l(  int _C,    _locale_t _Locale);
  int __cdecl __isascii(  int _C);
  int __cdecl __toascii(  int _C);
  int __cdecl __iscsymf(  int _C);
  int __cdecl __iscsym(  int _C);

#line 128 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"



















































































#line 212 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"












































#line 257 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"






#line 264 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"





























































































#line 358 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"
















#line 375 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"

#line 377 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"


}
#line 381 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"

#line 383 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ctype.h"
#line 32 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
















#line 49 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









#line 59 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 60 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"








#line 69 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#line 75 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 76 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"


#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\sal_supp.h"


















































#line 52 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\sal_supp.h"







#line 60 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\sal_supp.h"

#line 62 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\sal_supp.h"

#line 4 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"
#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\specstrings_supp.h"







































































#line 73 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\specstrings_supp.h"








#line 82 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\specstrings_supp.h"

#line 84 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\specstrings_supp.h"

#line 5 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"




#pragma once
#line 11 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"




#line 16 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"


extern "C" {
#line 20 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"














#line 35 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"







#line 43 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"

















































































#line 125 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"
#line 126 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"





































#line 164 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"



























#line 192 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"






















































































#line 279 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"












}
#line 293 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"



























#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"

























#line 27 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"




























































































































































#pragma once
#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_undef.h"




































































































































































































































































































































































































#line 185 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"




























































































































































































































































































































































































































































































































































































































































































































































































































#line 982 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"
































































#line 1047 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"






















































#line 1102 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"
#line 1103 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"
#line 1104 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings_strict.h"


#line 321 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"
#line 322 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"

#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"




























































































































#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\sdv_driverspecs.h"





















#line 23 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\sdv_driverspecs.h"

#line 126 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"


#pragma once
#line 130 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"


extern "C" {
#line 134 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"






#line 141 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"


#line 144 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"









































































































#line 250 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"

	
	
	
	
	
	
	
	
	
	
	


#line 265 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	


	
	
	
	



	
	


	
	
	
	
	
	
	
	
	
	
	
	


	
	


	
	


	
	



	
	









	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


	
	
	
	
	


	
	
	
	
	
	


	

	
	
	
	
	
	


	

											  
	
	
	
	
	


	
	
	
	
	
	


	


	
	
	
	
	


	
	
	
	
	
	


	


	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	

	
	
	
	

	
	
	
	


	
	
	
	

	
	
	
	

	
	
	
	

	
	
	
	
	

	
	
	
	

	
	
	
	
	

	
	
	

	
	

	
	
	

	
	

	

	
	

    
	
	
	


	
	
	


	
	
	
	
	
	
	
	
	
	
	
	

	
	


	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	

	
	
	
	
	
	


	
	
	
	
	 
	


	
	
		
		
		
		
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	

	

	
	
	
	
	
	
	
	
	
	
	
	




	
	
	
	
	


	
	
	
	
	
	
	
	
	
	

	
	
	
	

	
	
	
	
	

	
	
	
	
	
	
	
	
	
	

	
	
	

	
	

	
	
	
	
	
	

	
	
	

	
	
	



	
	


	
		
	



	
	
	


	
	


















































































	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

#line 832 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"

	
	

    

	
	
	


}
#line 845 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"

#line 847 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\driverspecs.h"


#line 324 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"

#line 326 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\specstrings.h"



#line 78 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\kernelspecs.h"



































#pragma once
#line 38 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\kernelspecs.h"


extern "C" {
#line 42 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\kernelspecs.h"

	
	
	

	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	


	
	
	
	
	
	


	
	
	
	
	
	



	
	
	
	
	
	

	
	
	
	
	
	


	
	
	
	
	
	

	
	
	
	
	
	
	



	
	
	
	
	
	

	
	
	
	
	
	
	



	
	
	
	
	



	
	
	
	


	
	
	
	
	


	
	

	
	
	















}
#line 187 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\kernelspecs.h"

#line 79 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 83 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 87 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 89 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









#line 99 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 103 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#line 109 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


#line 112 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









#line 122 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 126 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"














#line 141 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 145 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"












#line 158 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"





























#line 31 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"
 


#line 35 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"
  
   
  

#line 40 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"
  typedef unsigned long POINTER_64_INT;
 #line 42 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"
 
#line 44 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"



#line 48 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"

#line 50 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"










#line 61 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"


#line 64 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"





#pragma once
#line 71 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"


extern "C" {
#line 75 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"

typedef signed char         INT8, *PINT8;
typedef signed short        INT16, *PINT16;
typedef signed int          INT32, *PINT32;
typedef signed __int64      INT64, *PINT64;
typedef unsigned char       UINT8, *PUINT8;
typedef unsigned short      UINT16, *PUINT16;
typedef unsigned int        UINT32, *PUINT32;
typedef unsigned __int64    UINT64, *PUINT64;





typedef signed int LONG32, *PLONG32;





typedef unsigned int ULONG32, *PULONG32;
typedef unsigned int DWORD32, *PDWORD32;







#line 105 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"

















#line 123 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"











#line 135 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"
    typedef __w64 int INT_PTR, *PINT_PTR;
    typedef __w64 unsigned int UINT_PTR, *PUINT_PTR;

    typedef __w64 long LONG_PTR, *PLONG_PTR;
    typedef __w64 unsigned long ULONG_PTR, *PULONG_PTR;

    

#line 144 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"
#line 145 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"





























































































































































































typedef unsigned short UHALF_PTR, *PUHALF_PTR;
typedef short HALF_PTR, *PHALF_PTR;
typedef __w64 long SHANDLE_PTR;
typedef __w64 unsigned long HANDLE_PTR;

















__inline
void * __ptr64
PtrToPtr64(
    const void *p
    )
{
    return((void * __ptr64) (unsigned __int64) (ULONG_PTR)p );
}

__inline
void *
Ptr64ToPtr(
    const void * __ptr64 p
    )
{
    return((void *) (ULONG_PTR) (unsigned __int64) p);
}

__inline
void * __ptr64
HandleToHandle64(
    const void *h
    )
{
    return((void * __ptr64)(__int64)(LONG_PTR)h );
}

__inline
void *
Handle64ToHandle(
    const void * __ptr64 h
    )
{
    return((void *) (ULONG_PTR) (unsigned __int64) h );
}
#line 391 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"






#line 398 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"























typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef LONG_PTR SSIZE_T, *PSSIZE_T;









































#line 465 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"





typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;





typedef __int64 LONG64, *PLONG64;






typedef unsigned __int64 ULONG64, *PULONG64;
typedef unsigned __int64 DWORD64, *PDWORD64;





typedef ULONG_PTR KAFFINITY;
typedef KAFFINITY *PKAFFINITY;


}
#line 496 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"

#line 498 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\basetsd.h"

#line 160 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 167 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 174 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 175 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 182 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 183 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 190 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 191 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 198 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 199 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 203 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 210 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 211 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 218 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 219 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 226 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 227 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 234 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 235 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




#line 240 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 242 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 243 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 250 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 251 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






#line 258 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 259 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"








#line 268 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 269 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"














#line 284 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef void *PVOID;
typedef void * __ptr64 PVOID64;








#line 300 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#line 306 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
















#line 323 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"








typedef char CHAR;
typedef short SHORT;
typedef long LONG;

typedef int INT;
#line 337 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 338 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






typedef wchar_t WCHAR;    



#line 349 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef WCHAR *PWCHAR, *LPWCH, *PWCH;
typedef const WCHAR *LPCWCH, *PCWCH;

typedef  WCHAR *NWPSTR, *LPWSTR, *PWSTR;
typedef  PWSTR *PZPWSTR;
typedef  const PWSTR *PCZPWSTR;
typedef  WCHAR  *LPUWSTR, *PUWSTR;
typedef  const WCHAR *LPCWSTR, *PCWSTR;
typedef  PCWSTR *PZPCWSTR;
typedef  const WCHAR  *LPCUWSTR, *PCUWSTR;

typedef  WCHAR *PZZWSTR;
typedef  const WCHAR *PCZZWSTR;
typedef  WCHAR  *PUZZWSTR;
typedef  const WCHAR  *PCUZZWSTR;

typedef  WCHAR *PNZWCH;
typedef  const WCHAR *PCNZWCH;
typedef  WCHAR  *PUNZWCH;
typedef  const WCHAR  *PCUNZWCH;



typedef const WCHAR *LPCWCHAR, *PCWCHAR;
typedef const WCHAR  *LPCUWCHAR, *PCUWCHAR;





typedef unsigned long UCSCHAR;



















typedef UCSCHAR *PUCSCHAR;
typedef const UCSCHAR *PCUCSCHAR;

typedef UCSCHAR *PUCSSTR;
typedef UCSCHAR  *PUUCSSTR;

typedef const UCSCHAR *PCUCSSTR;
typedef const UCSCHAR  *PCUUCSSTR;

typedef UCSCHAR  *PUUCSCHAR;
typedef const UCSCHAR  *PCUUCSCHAR;

#line 413 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef CHAR *PCHAR, *LPCH, *PCH;
typedef const CHAR *LPCCH, *PCCH;

typedef  CHAR *NPSTR, *LPSTR, *PSTR;
typedef  PSTR *PZPSTR;
typedef  const PSTR *PCZPSTR;
typedef  const CHAR *LPCSTR, *PCSTR;
typedef  PCSTR *PZPCSTR;

typedef  CHAR *PZZSTR;
typedef  const CHAR *PCZZSTR;

typedef  CHAR *PNZCH;
typedef  const CHAR *PCNZCH;
































typedef char TCHAR, *PTCHAR;
typedef unsigned char TBYTE , *PTBYTE ;

#line 468 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef LPCH LPTCH, PTCH;
typedef LPCCH LPCTCH, PCTCH;
typedef LPSTR PTSTR, LPTSTR, PUTSTR, LPUTSTR;
typedef LPCSTR PCTSTR, LPCTSTR, PCUTSTR, LPCUTSTR;
typedef PZZSTR PZZTSTR, PUZZTSTR;
typedef PCZZSTR PCZZTSTR, PCUZZTSTR;
typedef PNZCH PNZTCH, PUNZTCH;
typedef PCNZCH PCNZTCH, PCUNZTCH;


#line 480 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



typedef SHORT *PSHORT;  
typedef LONG *PLONG;    








typedef struct _PROCESSOR_NUMBER {
    WORD   Group;
    BYTE  Number;
    BYTE  Reserved;
} PROCESSOR_NUMBER, *PPROCESSOR_NUMBER;






typedef struct _GROUP_AFFINITY {
    KAFFINITY Mask;
    WORD   Group;
    WORD   Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY;






typedef void *HANDLE;


#line 519 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 521 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 525 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
typedef HANDLE *PHANDLE;





typedef BYTE   FCHAR;
typedef WORD   FSHORT;
typedef DWORD  FLONG;








typedef  long HRESULT;
#line 544 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 545 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


    


#line 551 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









#line 561 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"













#line 575 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




























typedef char CCHAR;          
typedef DWORD LCID;         
typedef PDWORD PLCID;       
typedef WORD   LANGID;      






















#line 630 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
typedef struct _FLOAT128 {
    __int64 LowPart;
    __int64 HighPart;
} FLOAT128;

typedef FLOAT128 *PFLOAT128;









typedef __int64 LONGLONG;
typedef unsigned __int64 ULONGLONG;


















#line 666 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef LONGLONG *PLONGLONG;
typedef ULONGLONG *PULONGLONG;



typedef LONGLONG USN;



#line 677 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    } ;
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
#line 687 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef LARGE_INTEGER *PLARGE_INTEGER;



#line 695 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
typedef union _ULARGE_INTEGER {
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } ;
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } u;
#line 705 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
    ULONGLONG QuadPart;
} ULARGE_INTEGER;

typedef ULARGE_INTEGER *PULARGE_INTEGER;








typedef struct _LUID {
    DWORD LowPart;
    LONG HighPart;
} LUID, *PLUID;


typedef ULONGLONG  DWORDLONG;
typedef DWORDLONG *PDWORDLONG;





























#line 757 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"












ULONGLONG
__stdcall
Int64ShllMod32 (
     ULONGLONG Value,
     DWORD ShiftCount
    );

LONGLONG
__stdcall
Int64ShraMod32 (
     LONGLONG Value,
     DWORD ShiftCount
    );

ULONGLONG
__stdcall
Int64ShrlMod32 (
     ULONGLONG Value,
     DWORD ShiftCount
    );


#pragma warning(push)
#line 793 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#pragma warning(disable:4035 4793)               

__inline ULONGLONG
__stdcall
Int64ShllMod32 (
     ULONGLONG Value,
     DWORD ShiftCount
    )
{
    __asm    {
        mov     ecx, ShiftCount
        mov     eax, dword ptr [Value]
        mov     edx, dword ptr [Value+4]
        shld    edx, eax, cl
        shl     eax, cl
    }
}

__inline LONGLONG
__stdcall
Int64ShraMod32 (
     LONGLONG Value,
     DWORD ShiftCount
    )
{
    __asm {
        mov     ecx, ShiftCount
        mov     eax, dword ptr [Value]
        mov     edx, dword ptr [Value+4]
        shrd    eax, edx, cl
        sar     edx, cl
    }
}

__inline ULONGLONG
__stdcall
Int64ShrlMod32 (
     ULONGLONG Value,
     DWORD ShiftCount
    )
{
    __asm    {
        mov     ecx, ShiftCount
        mov     eax, dword ptr [Value]
        mov     edx, dword ptr [Value+4]
        shrd    eax, edx, cl
        shr     edx, cl
    }
}


#pragma warning(pop)


#line 848 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#line 854 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"






extern "C" {
#line 862 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









































#line 904 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









unsigned int
__cdecl
_rotl (
     unsigned int Value,
     int Shift
    );


unsigned __int64
__cdecl
_rotl64 (
     unsigned __int64 Value,
     int Shift
    );


unsigned int
__cdecl
_rotr (
     unsigned int Value,
     int Shift
    );


unsigned __int64
__cdecl
_rotr64 (
     unsigned __int64 Value,
     int Shift
    );

#pragma intrinsic(_rotl)
#pragma intrinsic(_rotl64)
#pragma intrinsic(_rotr)
#pragma intrinsic(_rotr64)

#line 950 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


}
#line 954 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef BYTE  BOOLEAN;           
typedef BOOLEAN *PBOOLEAN;       





typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, * PRLIST_ENTRY;






typedef struct _SINGLE_LIST_ENTRY {
    struct _SINGLE_LIST_ENTRY *Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY;






typedef struct LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
} LIST_ENTRY32;
typedef LIST_ENTRY32 *PLIST_ENTRY32;

typedef struct LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
} LIST_ENTRY64;
typedef LIST_ENTRY64 *PLIST_ENTRY64;


#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"




















#line 22 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[ 8 ];
} GUID;
#line 29 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 30 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"




































#line 67 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"








typedef GUID *LPGUID;
#line 77 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"



typedef const GUID *LPCGUID;
#line 82 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"




typedef GUID IID;
typedef IID *LPIID;


typedef GUID CLSID;
typedef CLSID *LPCLSID;


typedef GUID FMTID;
typedef FMTID *LPFMTID;







#line 104 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"







#line 112 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 113 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"







#line 121 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 122 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"







#line 130 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 131 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"







#line 139 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 140 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"

#line 142 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"








__inline int InlineIsEqualGUID(const GUID & rguid1, const GUID & rguid2)
{
   return (
      ((unsigned long *) &rguid1)[0] == ((unsigned long *) &rguid2)[0] &&
      ((unsigned long *) &rguid1)[1] == ((unsigned long *) &rguid2)[1] &&
      ((unsigned long *) &rguid1)[2] == ((unsigned long *) &rguid2)[2] &&
      ((unsigned long *) &rguid1)[3] == ((unsigned long *) &rguid2)[3]);
}

__inline int IsEqualGUID(const GUID & rguid1, const GUID & rguid2)
{
    return !memcmp(&rguid1, &rguid2, sizeof(GUID));
}











#line 175 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"

















__inline int operator==(const GUID & guidOne, const GUID & guidOther)
{
    return IsEqualGUID(guidOne,guidOther);
}

__inline int operator!=(const GUID & guidOne, const GUID & guidOther)
{
    return !(guidOne == guidOther);
}
#line 202 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 203 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 204 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 205 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"
#line 206 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\guiddef.h"

#line 999 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




typedef struct  _OBJECTID {     
    GUID Lineage;
    DWORD Uniquifier;
} OBJECTID;
#line 1008 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





































































extern "C++" 
template <typename T, size_t N>
char (*RtlpNumberOf(  T (&)[N] ))[N];









































#line 1127 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#line 1133 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









































#line 1175 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

























typedef
 
 
EXCEPTION_DISPOSITION
__stdcall
EXCEPTION_ROUTINE (
     struct _EXCEPTION_RECORD *ExceptionRecord,
     PVOID EstablisherFrame,
     struct _CONTEXT *ContextRecord,
     PVOID DispatcherContext
    );

typedef EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;




































































































































































































































































































































































































































































































































































































































































































































#line 1922 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
























#line 1947 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





















#line 1969 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"













  
























































#line 2040 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
  
#line 2042 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




typedef ULONG_PTR KSPIN_LOCK;
typedef KSPIN_LOCK *PKSPIN_LOCK;






typedef struct __declspec(align(16)) _M128A {
    ULONGLONG Low;
    LONGLONG High;
} M128A, *PM128A;





typedef struct __declspec(align(16)) _XSAVE_FORMAT {
    WORD   ControlWord;
    WORD   StatusWord;
    BYTE  TagWord;
    BYTE  Reserved1;
    WORD   ErrorOpcode;
    DWORD ErrorOffset;
    WORD   ErrorSelector;
    WORD   Reserved2;
    DWORD DataOffset;
    WORD   DataSelector;
    WORD   Reserved3;
    DWORD MxCsr;
    DWORD MxCsr_Mask;
    M128A FloatRegisters[8];






#line 2085 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

    M128A XmmRegisters[8];
    BYTE  Reserved4[192];

    
    
    
    
    

    DWORD   StackControl[7];    
    DWORD   Cr0NpxState;

#line 2099 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

} XSAVE_FORMAT, *PXSAVE_FORMAT;

typedef struct __declspec(align(8)) _XSAVE_AREA_HEADER {
    DWORD64 Mask;
    DWORD64 Reserved[7];
} XSAVE_AREA_HEADER, *PXSAVE_AREA_HEADER;

typedef struct __declspec(align(16)) _XSAVE_AREA {
    XSAVE_FORMAT LegacyState;
    XSAVE_AREA_HEADER Header;
} XSAVE_AREA, *PXSAVE_AREA;

typedef struct _XSTATE_CONTEXT {
    DWORD64 Mask;
    DWORD Length;
    DWORD Reserved1;
     PXSAVE_AREA Area;


    DWORD Reserved2;
#line 2121 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

    PVOID Buffer;


    DWORD Reserved3;
#line 2127 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

} XSTATE_CONTEXT, *PXSTATE_CONTEXT;













typedef struct _CONTEXT_CHUNK {
    LONG Offset;
    DWORD Length;
} CONTEXT_CHUNK, *PCONTEXT_CHUNK;


























typedef struct _CONTEXT_EX {

    
    
    
    

    CONTEXT_CHUNK All;

    
    
    
    
    

    CONTEXT_CHUNK Legacy;

    
    
    
    
    
    
    

    CONTEXT_CHUNK XState;

} CONTEXT_EX, *PCONTEXT_EX;


































typedef char __C_ASSERT__[((sizeof(XSAVE_FORMAT) & (64 - 1)) == 0)?1:-1];
typedef char __C_ASSERT__[((((LONG)(LONG_PTR)&(((XSAVE_AREA *)0)->Header)) & (64 - 1)) == 0)?1:-1];


typedef char __C_ASSERT__[(sizeof(XSAVE_AREA) == 512 + 64)?1:-1];

#line 2241 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#pragma warning(push)
#line 3606 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#pragma warning(disable:4164)   
                                

#pragma function(_enable)
#pragma function(_disable)
#line 3612 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


#pragma warning(pop)


#line 3618 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 3620 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 3621 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





extern "C" {
#line 3628 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


















BOOLEAN
_bittest (
     LONG const *Base,
     LONG Offset
    );

BOOLEAN
_bittestandcomplement (
     LONG *Base,
     LONG Offset
    );

BOOLEAN
_bittestandset (
     LONG *Base,
     LONG Offset
    );

BOOLEAN
_bittestandreset (
     LONG *Base,
     LONG Offset
    );

BOOLEAN
_interlockedbittestandset (
       LONG volatile *Base,
     LONG Offset
    );

BOOLEAN
_interlockedbittestandreset (
       LONG volatile *Base,
     LONG Offset
    );

#pragma intrinsic(_bittest)
#pragma intrinsic(_bittestandcomplement)
#pragma intrinsic(_bittestandset)
#pragma intrinsic(_bittestandreset)
#pragma intrinsic(_interlockedbittestandset)
#pragma intrinsic(_interlockedbittestandreset)









BOOLEAN
_BitScanForward (
     DWORD *Index,
     DWORD Mask
    );


BOOLEAN
_BitScanReverse (
     DWORD *Index,
     DWORD Mask
    );

#pragma intrinsic(_BitScanForward)
#pragma intrinsic(_BitScanReverse)





































#line 3750 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"










SHORT
_InterlockedAnd16 (
       SHORT volatile *Destination,
     SHORT Value
    );

SHORT
_InterlockedCompareExchange16 (
       SHORT volatile *Destination,
     SHORT ExChange,
     SHORT Comperand
    );

SHORT
_InterlockedOr16 (
       SHORT volatile *Destination,
     SHORT Value
    );

#pragma intrinsic(_InterlockedAnd16)
#pragma intrinsic(_InterlockedCompareExchange16)
#pragma intrinsic(_InterlockedOr16)

#line 3784 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


#pragma warning(push)
#pragma warning(disable:4035 4793)

__forceinline
BOOLEAN
InterlockedBitTestAndComplement (
       LONG volatile *Base,
     LONG Bit
    )
{
    __asm {
           mov eax, Bit
           mov ecx, Base
           lock btc [ecx], eax
           setc al
    };
}
#pragma warning(pop)
#line 3805 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"











BYTE 
__readfsbyte (
     DWORD Offset
    );

WORD  
__readfsword (
     DWORD Offset
    );

DWORD
__readfsdword (
     DWORD Offset
    );

void
__writefsbyte (
     DWORD Offset,
     BYTE  Data
    );

void
__writefsword (
     DWORD Offset,
     WORD   Data
    );

void
__writefsdword (
     DWORD Offset,
     DWORD Data
    );

#pragma intrinsic(__readfsbyte)
#pragma intrinsic(__readfsword)
#pragma intrinsic(__readfsdword)
#pragma intrinsic(__writefsbyte)
#pragma intrinsic(__writefsword)
#pragma intrinsic(__writefsdword)

#line 3857 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





void
__incfsbyte (
     DWORD Offset
    );

void
__addfsbyte (
     DWORD Offset,
     BYTE  Value
    );

void
__incfsword (
     DWORD Offset
    );

void
__addfsword (
     DWORD Offset,
     WORD   Value
    );

void
__incfsdword (
     DWORD Offset
    );

void
__addfsdword (
     DWORD Offset,
     DWORD Value
    );

#pragma intrinsic(__incfsbyte)
#pragma intrinsic(__addfsbyte)
#pragma intrinsic(__incfsword)
#pragma intrinsic(__addfsword)
#pragma intrinsic(__incfsdword)
#pragma intrinsic(__addfsdword)

#line 3903 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 3905 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



void
_mm_pause (
    void
    );

#pragma intrinsic(_mm_pause)









#line 3924 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


}
#line 3928 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 3930 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#pragma warning( push )
#pragma warning( disable : 4793 )
__forceinline
void
MemoryBarrier (
    void
    )
{
    LONG Barrier;
    __asm {
        xchg Barrier, eax
    }
}
#pragma warning( pop )

#line 3951 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"























DWORD64
__readpmc (
     DWORD Counter
    );

#pragma intrinsic(__readpmc)
















#line 3997 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









DWORD64
__rdtsc (
    void
    );

#pragma intrinsic(__rdtsc)













#line 4026 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"








void
__int2c (
    void
    );

#pragma intrinsic(__int2c)


__forceinline
void
DbgRaiseAssertionFailure (
    void
    )

{
    __int2c();
}


















#line 4070 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 4072 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





__inline PVOID GetFiberData( void )    { return *(PVOID *) (ULONG_PTR) __readfsdword (0x10);}
__inline PVOID GetCurrentFiber( void ) { return (PVOID) (ULONG_PTR) __readfsdword (0x10);}


















#line 4098 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


#line 4101 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

















































#line 4151 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _FLOATING_SAVE_AREA {
    DWORD   ControlWord;
    DWORD   StatusWord;
    DWORD   TagWord;
    DWORD   ErrorOffset;
    DWORD   ErrorSelector;
    DWORD   DataOffset;
    DWORD   DataSelector;
    BYTE    RegisterArea[80];
    DWORD   Cr0NpxState;
} FLOATING_SAVE_AREA;

typedef FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;









typedef char __C_ASSERT__[(sizeof(XSAVE_FORMAT) == 512)?1:-1];

#line 4177 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"























#pragma warning(disable:4103)

#pragma pack(push,4)


#line 30 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"
#line 34 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"

#line 4182 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"











typedef struct _CONTEXT {

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    DWORD ContextFlags;

    
    
    
    
    

    DWORD   Dr0;
    DWORD   Dr1;
    DWORD   Dr2;
    DWORD   Dr3;
    DWORD   Dr6;
    DWORD   Dr7;

    
    
    
    

    FLOATING_SAVE_AREA FloatSave;

    
    
    
    

    DWORD   SegGs;
    DWORD   SegFs;
    DWORD   SegEs;
    DWORD   SegDs;

    
    
    
    

    DWORD   Edi;
    DWORD   Esi;
    DWORD   Ebx;
    DWORD   Edx;
    DWORD   Ecx;
    DWORD   Eax;

    
    
    
    

    DWORD   Ebp;
    DWORD   Eip;
    DWORD   SegCs;              
    DWORD   EFlags;             
    DWORD   Esp;
    DWORD   SegSs;

    
    
    
    
    

    BYTE    ExtendedRegisters[512];

} CONTEXT;

typedef CONTEXT *PCONTEXT;

#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


#line 36 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"
#line 37 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"

#line 4282 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


#line 4285 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef struct _LDT_ENTRY {
    WORD    LimitLow;
    WORD    BaseLow;
    union {
        struct {
            BYTE    BaseMid;
            BYTE    Flags1;     
            BYTE    Flags2;     
            BYTE    BaseHi;
        } Bytes;
        struct {
            DWORD   BaseMid : 8;
            DWORD   Type : 5;
            DWORD   Dpl : 2;
            DWORD   Pres : 1;
            DWORD   LimitHi : 4;
            DWORD   Sys : 1;
            DWORD   Reserved_0 : 1;
            DWORD   Default_Big : 1;
            DWORD   Granularity : 1;
            DWORD   BaseHi : 8;
        } Bits;
    } HighWord;
} LDT_ENTRY, *PLDT_ENTRY;

#line 4316 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"












































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 5385 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





















































































































































































#line 5567 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


















































































































































































































































































































































































































































































































































































































#line 6162 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









typedef struct _WOW64_FLOATING_SAVE_AREA {
    DWORD   ControlWord;
    DWORD   StatusWord;
    DWORD   TagWord;
    DWORD   ErrorOffset;
    DWORD   ErrorSelector;
    DWORD   DataOffset;
    DWORD   DataSelector;
    BYTE    RegisterArea[80];
    DWORD   Cr0NpxState;
} WOW64_FLOATING_SAVE_AREA;

typedef WOW64_FLOATING_SAVE_AREA *PWOW64_FLOATING_SAVE_AREA;

#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"























#pragma warning(disable:4103)

#pragma pack(push,4)


#line 30 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"
#line 34 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"

#line 6186 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"











typedef struct _WOW64_CONTEXT {

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    DWORD ContextFlags;

    
    
    
    
    

    DWORD   Dr0;
    DWORD   Dr1;
    DWORD   Dr2;
    DWORD   Dr3;
    DWORD   Dr6;
    DWORD   Dr7;

    
    
    
    

    WOW64_FLOATING_SAVE_AREA FloatSave;

    
    
    
    

    DWORD   SegGs;
    DWORD   SegFs;
    DWORD   SegEs;
    DWORD   SegDs;

    
    
    
    

    DWORD   Edi;
    DWORD   Esi;
    DWORD   Ebx;
    DWORD   Edx;
    DWORD   Ecx;
    DWORD   Eax;

    
    
    
    

    DWORD   Ebp;
    DWORD   Eip;
    DWORD   SegCs;              
    DWORD   EFlags;             
    DWORD   Esp;
    DWORD   SegSs;

    
    
    
    
    

    BYTE    ExtendedRegisters[512];

} WOW64_CONTEXT;

typedef WOW64_CONTEXT *PWOW64_CONTEXT;

#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


#line 36 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"
#line 37 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"

#line 6286 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


typedef struct _WOW64_LDT_ENTRY {
    WORD    LimitLow;
    WORD    BaseLow;
    union {
        struct {
            BYTE    BaseMid;
            BYTE    Flags1;     
            BYTE    Flags2;     
            BYTE    BaseHi;
        } Bytes;
        struct {
            DWORD   BaseMid : 8;
            DWORD   Type : 5;
            DWORD   Dpl : 2;
            DWORD   Pres : 1;
            DWORD   LimitHi : 4;
            DWORD   Sys : 1;
            DWORD   Reserved_0 : 1;
            DWORD   Default_Big : 1;
            DWORD   Granularity : 1;
            DWORD   BaseHi : 8;
        } Bits;
    } HighWord;
} WOW64_LDT_ENTRY, *PWOW64_LDT_ENTRY;

typedef struct _WOW64_DESCRIPTOR_TABLE_ENTRY {
    DWORD Selector;
    WOW64_LDT_ENTRY Descriptor;
} WOW64_DESCRIPTOR_TABLE_ENTRY, *PWOW64_DESCRIPTOR_TABLE_ENTRY;








typedef struct _EXCEPTION_RECORD {
    DWORD    ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
    } EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD32 {
    DWORD    ExceptionCode;
    DWORD ExceptionFlags;
    DWORD ExceptionRecord;
    DWORD ExceptionAddress;
    DWORD NumberParameters;
    DWORD ExceptionInformation[15];
} EXCEPTION_RECORD32, *PEXCEPTION_RECORD32;

typedef struct _EXCEPTION_RECORD64 {
    DWORD    ExceptionCode;
    DWORD ExceptionFlags;
    DWORD64 ExceptionRecord;
    DWORD64 ExceptionAddress;
    DWORD NumberParameters;
    DWORD __unusedAlignment;
    DWORD64 ExceptionInformation[15];
} EXCEPTION_RECORD64, *PEXCEPTION_RECORD64;





typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;



__declspec(dllimport)
void
__stdcall
RtlUnwind (
     PVOID TargetFrame,
     PVOID TargetIp,
     PEXCEPTION_RECORD ExceptionRecord,
     PVOID ReturnValue
    );














#line 6390 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"















#line 6406 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"













#line 6420 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef PVOID PACCESS_TOKEN;            
typedef PVOID PSECURITY_DESCRIPTOR;     
typedef PVOID PSID;     







































typedef DWORD ACCESS_MASK;
typedef ACCESS_MASK *PACCESS_MASK;
























































typedef struct _GENERIC_MAPPING {
    ACCESS_MASK GenericRead;
    ACCESS_MASK GenericWrite;
    ACCESS_MASK GenericExecute;
    ACCESS_MASK GenericAll;
} GENERIC_MAPPING;
typedef GENERIC_MAPPING *PGENERIC_MAPPING;












#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack4.h"























#pragma warning(disable:4103)

#pragma pack(push,4)


#line 30 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack4.h"


#line 33 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack4.h"
#line 34 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack4.h"

#line 6541 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _LUID_AND_ATTRIBUTES {
    LUID Luid;
    DWORD Attributes;
    } LUID_AND_ATTRIBUTES, * PLUID_AND_ATTRIBUTES;
typedef LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[1];
typedef LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;

#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"


#line 36 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"
#line 37 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"

#line 6550 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


































typedef struct _SID_IDENTIFIER_AUTHORITY {
    BYTE  Value[6];
} SID_IDENTIFIER_AUTHORITY, *PSID_IDENTIFIER_AUTHORITY;
#line 6588 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




typedef struct _SID {
   BYTE  Revision;
   BYTE  SubAuthorityCount;
   SID_IDENTIFIER_AUTHORITY IdentifierAuthority;



   DWORD SubAuthority[1];
#line 6601 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
} SID, *PISID;
#line 6603 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





                                                



#line 6613 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


typedef enum _SID_NAME_USE {
    SidTypeUser = 1,
    SidTypeGroup,
    SidTypeDomain,
    SidTypeAlias,
    SidTypeWellKnownGroup,
    SidTypeDeletedAccount,
    SidTypeInvalid,
    SidTypeUnknown,
    SidTypeComputer,
    SidTypeLabel
} SID_NAME_USE, *PSID_NAME_USE;

typedef struct _SID_AND_ATTRIBUTES {



    PSID Sid;
#line 6634 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
    DWORD Attributes;
    } SID_AND_ATTRIBUTES, * PSID_AND_ATTRIBUTES;

typedef SID_AND_ATTRIBUTES SID_AND_ATTRIBUTES_ARRAY[1];
typedef SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;


typedef ULONG_PTR SID_HASH_ENTRY, *PSID_HASH_ENTRY;

typedef struct _SID_AND_ATTRIBUTES_HASH {
    DWORD SidCount;
    PSID_AND_ATTRIBUTES SidAttr;
    SID_HASH_ENTRY Hash[32];
} SID_AND_ATTRIBUTES_HASH, *PSID_AND_ATTRIBUTES_HASH;





































































































































































































































































typedef enum {

    WinNullSid                                  = 0,
    WinWorldSid                                 = 1,
    WinLocalSid                                 = 2,
    WinCreatorOwnerSid                          = 3,
    WinCreatorGroupSid                          = 4,
    WinCreatorOwnerServerSid                    = 5,
    WinCreatorGroupServerSid                    = 6,
    WinNtAuthoritySid                           = 7,
    WinDialupSid                                = 8,
    WinNetworkSid                               = 9,
    WinBatchSid                                 = 10,
    WinInteractiveSid                           = 11,
    WinServiceSid                               = 12,
    WinAnonymousSid                             = 13,
    WinProxySid                                 = 14,
    WinEnterpriseControllersSid                 = 15,
    WinSelfSid                                  = 16,
    WinAuthenticatedUserSid                     = 17,
    WinRestrictedCodeSid                        = 18,
    WinTerminalServerSid                        = 19,
    WinRemoteLogonIdSid                         = 20,
    WinLogonIdsSid                              = 21,
    WinLocalSystemSid                           = 22,
    WinLocalServiceSid                          = 23,
    WinNetworkServiceSid                        = 24,
    WinBuiltinDomainSid                         = 25,
    WinBuiltinAdministratorsSid                 = 26,
    WinBuiltinUsersSid                          = 27,
    WinBuiltinGuestsSid                         = 28,
    WinBuiltinPowerUsersSid                     = 29,
    WinBuiltinAccountOperatorsSid               = 30,
    WinBuiltinSystemOperatorsSid                = 31,
    WinBuiltinPrintOperatorsSid                 = 32,
    WinBuiltinBackupOperatorsSid                = 33,
    WinBuiltinReplicatorSid                     = 34,
    WinBuiltinPreWindows2000CompatibleAccessSid = 35,
    WinBuiltinRemoteDesktopUsersSid             = 36,
    WinBuiltinNetworkConfigurationOperatorsSid  = 37,
    WinAccountAdministratorSid                  = 38,
    WinAccountGuestSid                          = 39,
    WinAccountKrbtgtSid                         = 40,
    WinAccountDomainAdminsSid                   = 41,
    WinAccountDomainUsersSid                    = 42,
    WinAccountDomainGuestsSid                   = 43,
    WinAccountComputersSid                      = 44,
    WinAccountControllersSid                    = 45,
    WinAccountCertAdminsSid                     = 46,
    WinAccountSchemaAdminsSid                   = 47,
    WinAccountEnterpriseAdminsSid               = 48,
    WinAccountPolicyAdminsSid                   = 49,
    WinAccountRasAndIasServersSid               = 50,
    WinNTLMAuthenticationSid                    = 51,
    WinDigestAuthenticationSid                  = 52,
    WinSChannelAuthenticationSid                = 53,
    WinThisOrganizationSid                      = 54,
    WinOtherOrganizationSid                     = 55,
    WinBuiltinIncomingForestTrustBuildersSid    = 56,
    WinBuiltinPerfMonitoringUsersSid            = 57,
    WinBuiltinPerfLoggingUsersSid               = 58,
    WinBuiltinAuthorizationAccessSid            = 59,
    WinBuiltinTerminalServerLicenseServersSid   = 60,
    WinBuiltinDCOMUsersSid                      = 61,
    WinBuiltinIUsersSid                         = 62,
    WinIUserSid                                 = 63,
    WinBuiltinCryptoOperatorsSid                = 64,
    WinUntrustedLabelSid                        = 65,
    WinLowLabelSid                              = 66,
    WinMediumLabelSid                           = 67,
    WinHighLabelSid                             = 68,
    WinSystemLabelSid                           = 69,
    WinWriteRestrictedCodeSid                   = 70,
    WinCreatorOwnerRightsSid                    = 71,
    WinCacheablePrincipalsGroupSid              = 72,
    WinNonCacheablePrincipalsGroupSid           = 73,
    WinEnterpriseReadonlyControllersSid         = 74,
    WinAccountReadonlyControllersSid            = 75,
    WinBuiltinEventLogReadersGroup              = 76,
    WinNewEnterpriseReadonlyControllersSid      = 77,
    WinBuiltinCertSvcDComAccessGroup            = 78,
    WinMediumPlusLabelSid                       = 79,
    WinLocalLogonSid                            = 80,
    WinConsoleLogonSid							= 81,
    WinThisOrganizationCertificateSid			= 82,
} WELL_KNOWN_SID_TYPE;
































































































typedef struct _ACL {
    BYTE  AclRevision;
    BYTE  Sbz1;
    WORD   AclSize;
    WORD   AceCount;
    WORD   Sbz2;
} ACL;
typedef ACL *PACL;






















typedef struct _ACE_HEADER {
    BYTE  AceType;
    BYTE  AceFlags;
    WORD   AceSize;
} ACE_HEADER;
typedef ACE_HEADER *PACE_HEADER;









































































































typedef struct _ACCESS_ALLOWED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_ALLOWED_ACE;

typedef ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

typedef struct _ACCESS_DENIED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_DENIED_ACE;
typedef ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

typedef struct _SYSTEM_AUDIT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_AUDIT_ACE;
typedef SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

typedef struct _SYSTEM_ALARM_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_ALARM_ACE;
typedef SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

typedef struct _SYSTEM_MANDATORY_LABEL_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_MANDATORY_LABEL_ACE, *PSYSTEM_MANDATORY_LABEL_ACE;











typedef struct _ACCESS_ALLOWED_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_ALLOWED_OBJECT_ACE, *PACCESS_ALLOWED_OBJECT_ACE;

typedef struct _ACCESS_DENIED_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_DENIED_OBJECT_ACE, *PACCESS_DENIED_OBJECT_ACE;

typedef struct _SYSTEM_AUDIT_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} SYSTEM_AUDIT_OBJECT_ACE, *PSYSTEM_AUDIT_OBJECT_ACE;

typedef struct _SYSTEM_ALARM_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} SYSTEM_ALARM_OBJECT_ACE, *PSYSTEM_ALARM_OBJECT_ACE;






typedef struct _ACCESS_ALLOWED_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
    
} ACCESS_ALLOWED_CALLBACK_ACE, *PACCESS_ALLOWED_CALLBACK_ACE;

typedef struct _ACCESS_DENIED_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
    
} ACCESS_DENIED_CALLBACK_ACE, *PACCESS_DENIED_CALLBACK_ACE;

typedef struct _SYSTEM_AUDIT_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
    
} SYSTEM_AUDIT_CALLBACK_ACE, *PSYSTEM_AUDIT_CALLBACK_ACE;

typedef struct _SYSTEM_ALARM_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
    
} SYSTEM_ALARM_CALLBACK_ACE, *PSYSTEM_ALARM_CALLBACK_ACE;

typedef struct _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
    
} ACCESS_ALLOWED_CALLBACK_OBJECT_ACE, *PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

typedef struct _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
    
} ACCESS_DENIED_CALLBACK_OBJECT_ACE, *PACCESS_DENIED_CALLBACK_OBJECT_ACE;

typedef struct _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
    
} SYSTEM_AUDIT_CALLBACK_OBJECT_ACE, *PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

typedef struct _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
    
} SYSTEM_ALARM_CALLBACK_OBJECT_ACE, *PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;















typedef enum _ACL_INFORMATION_CLASS {
    AclRevisionInformation = 1,
    AclSizeInformation
} ACL_INFORMATION_CLASS;






typedef struct _ACL_REVISION_INFORMATION {
    DWORD AclRevision;
} ACL_REVISION_INFORMATION;
typedef ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;





typedef struct _ACL_SIZE_INFORMATION {
    DWORD AceCount;
    DWORD AclBytesInUse;
    DWORD AclBytesFree;
} ACL_SIZE_INFORMATION;
typedef ACL_SIZE_INFORMATION *PACL_SIZE_INFORMATION;


























typedef WORD   SECURITY_DESCRIPTOR_CONTROL, *PSECURITY_DESCRIPTOR_CONTROL;

























































































typedef struct _SECURITY_DESCRIPTOR_RELATIVE {
    BYTE  Revision;
    BYTE  Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    DWORD Owner;
    DWORD Group;
    DWORD Sacl;
    DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE, *PISECURITY_DESCRIPTOR_RELATIVE;

typedef struct _SECURITY_DESCRIPTOR {
   BYTE  Revision;
   BYTE  Sbz1;
   SECURITY_DESCRIPTOR_CONTROL Control;
   PSID Owner;
   PSID Group;
   PACL Sacl;
   PACL Dacl;

   } SECURITY_DESCRIPTOR, *PISECURITY_DESCRIPTOR;


















































typedef struct _OBJECT_TYPE_LIST {
    WORD   Level;
    WORD   Sbz;
    GUID *ObjectType;
} OBJECT_TYPE_LIST, *POBJECT_TYPE_LIST;















typedef enum _AUDIT_EVENT_TYPE {
    AuditEventObjectAccess,
    AuditEventDirectoryServiceAccess
} AUDIT_EVENT_TYPE, *PAUDIT_EVENT_TYPE;


















































typedef struct _PRIVILEGE_SET {
    DWORD PrivilegeCount;
    DWORD Control;
    LUID_AND_ATTRIBUTES Privilege[1];
    } PRIVILEGE_SET, * PPRIVILEGE_SET;













typedef enum _ACCESS_REASON_TYPE{

    AccessReasonNone = 0x00000000,  

    
    
    
    
    
    AccessReasonAllowedAce = 0x00010000,    
    AccessReasonDeniedAce = 0x00020000,     

    AccessReasonAllowedParentAce = 0x00030000,    
    AccessReasonDeniedParentAce = 0x00040000,     

    AccessReasonMissingPrivilege = 0x00100000,
    AccessReasonFromPrivilege = 0x00200000,


    AccessReasonIntegrityLevel = 0x00300000,

    AccessReasonOwnership = 0x00400000,

    AccessReasonNullDacl = 0x00500000,
    AccessReasonEmptyDacl = 0x00600000,

    AccessReasonNoSD = 0x00700000,
    AccessReasonNoGrant = 0x00800000    
} ACCESS_REASON_TYPE;

 












typedef DWORD ACCESS_REASON;

typedef struct _ACCESS_REASONS{
        ACCESS_REASON Data[32];
} ACCESS_REASONS, *PACCESS_REASONS;
























typedef struct _SE_SECURITY_DESCRIPTOR
{
    DWORD Size;
    DWORD Flags;
    PSECURITY_DESCRIPTOR SecurityDescriptor;
} SE_SECURITY_DESCRIPTOR, *PSE_SECURITY_DESCRIPTOR;

typedef struct _SE_ACCESS_REQUEST
{
    DWORD Size;
    PSE_SECURITY_DESCRIPTOR SeSecurityDescriptor;
    ACCESS_MASK DesiredAccess;
    ACCESS_MASK PreviouslyGrantedAccess;
    PSID PrincipalSelfSid;      
    PGENERIC_MAPPING GenericMapping;
    DWORD ObjectTypeListCount;
    POBJECT_TYPE_LIST ObjectTypeList;
} SE_ACCESS_REQUEST, *PSE_ACCESS_REQUEST;


typedef struct _SE_ACCESS_REPLY
{
    DWORD Size;
    DWORD ResultListCount;  
    PACCESS_MASK GrantedAccess;
    PDWORD    AccessStatus;
    PACCESS_REASONS AccessReason;
    PPRIVILEGE_SET* Privileges;
} SE_ACCESS_REPLY, *PSE_ACCESS_REPLY;






























































typedef enum _SECURITY_IMPERSONATION_LEVEL {
    SecurityAnonymous,
    SecurityIdentification,
    SecurityImpersonation,
    SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL, * PSECURITY_IMPERSONATION_LEVEL;












































#line 7917 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

















typedef enum _TOKEN_TYPE {
    TokenPrimary = 1,
    TokenImpersonation
    } TOKEN_TYPE;
typedef TOKEN_TYPE *PTOKEN_TYPE;







typedef enum _TOKEN_ELEVATION_TYPE {
    TokenElevationTypeDefault = 1,
    TokenElevationTypeFull,
    TokenElevationTypeLimited,
} TOKEN_ELEVATION_TYPE, *PTOKEN_ELEVATION_TYPE;






typedef enum _TOKEN_INFORMATION_CLASS {
    TokenUser = 1,
    TokenGroups,
    TokenPrivileges,
    TokenOwner,
    TokenPrimaryGroup,
    TokenDefaultDacl,
    TokenSource,
    TokenType,
    TokenImpersonationLevel,
    TokenStatistics,
    TokenRestrictedSids,
    TokenSessionId,
    TokenGroupsAndPrivileges,
    TokenSessionReference,
    TokenSandBoxInert,
    TokenAuditPolicy,
    TokenOrigin,
    TokenElevationType,
    TokenLinkedToken,
    TokenElevation,
    TokenHasRestrictions,
    TokenAccessInformation,
    TokenVirtualizationAllowed,
    TokenVirtualizationEnabled,
    TokenIntegrityLevel,
    TokenUIAccess,
    TokenMandatoryPolicy,
    TokenLogonSid,
    MaxTokenInfoClass  
} TOKEN_INFORMATION_CLASS, *PTOKEN_INFORMATION_CLASS;






typedef struct _TOKEN_USER {
    SID_AND_ATTRIBUTES User;
} TOKEN_USER, *PTOKEN_USER;

typedef struct _TOKEN_GROUPS {
    DWORD GroupCount;



    SID_AND_ATTRIBUTES Groups[1];
#line 8005 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
} TOKEN_GROUPS, *PTOKEN_GROUPS;


typedef struct _TOKEN_PRIVILEGES {
    DWORD PrivilegeCount;
    LUID_AND_ATTRIBUTES Privileges[1];
} TOKEN_PRIVILEGES, *PTOKEN_PRIVILEGES;


typedef struct _TOKEN_OWNER {
    PSID Owner;
} TOKEN_OWNER, *PTOKEN_OWNER;


typedef struct _TOKEN_PRIMARY_GROUP {
    PSID PrimaryGroup;
} TOKEN_PRIMARY_GROUP, *PTOKEN_PRIMARY_GROUP;


typedef struct _TOKEN_DEFAULT_DACL {
    PACL DefaultDacl;
} TOKEN_DEFAULT_DACL, *PTOKEN_DEFAULT_DACL;

typedef struct _TOKEN_GROUPS_AND_PRIVILEGES {
    DWORD SidCount;
    DWORD SidLength;
    PSID_AND_ATTRIBUTES Sids;
    DWORD RestrictedSidCount;
    DWORD RestrictedSidLength;
    PSID_AND_ATTRIBUTES RestrictedSids;
    DWORD PrivilegeCount;
    DWORD PrivilegeLength;
    PLUID_AND_ATTRIBUTES Privileges;
    LUID AuthenticationId;
} TOKEN_GROUPS_AND_PRIVILEGES, *PTOKEN_GROUPS_AND_PRIVILEGES;

typedef struct _TOKEN_LINKED_TOKEN {
    HANDLE LinkedToken;
} TOKEN_LINKED_TOKEN, *PTOKEN_LINKED_TOKEN;

typedef struct _TOKEN_ELEVATION {
    DWORD TokenIsElevated;
} TOKEN_ELEVATION, *PTOKEN_ELEVATION;

typedef struct _TOKEN_MANDATORY_LABEL {
    SID_AND_ATTRIBUTES Label;
} TOKEN_MANDATORY_LABEL, *PTOKEN_MANDATORY_LABEL;








typedef struct _TOKEN_MANDATORY_POLICY {
    DWORD Policy;
} TOKEN_MANDATORY_POLICY, *PTOKEN_MANDATORY_POLICY;

typedef struct _TOKEN_ACCESS_INFORMATION {
    PSID_AND_ATTRIBUTES_HASH SidHash;
    PSID_AND_ATTRIBUTES_HASH RestrictedSidHash;
    PTOKEN_PRIVILEGES Privileges;
    LUID AuthenticationId;
    TOKEN_TYPE TokenType;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    TOKEN_MANDATORY_POLICY MandatoryPolicy;
    DWORD Flags;
} TOKEN_ACCESS_INFORMATION, *PTOKEN_ACCESS_INFORMATION;







typedef struct _TOKEN_AUDIT_POLICY {
    BYTE  PerUserPolicy[(((53)) >> 1) + 1];
} TOKEN_AUDIT_POLICY, *PTOKEN_AUDIT_POLICY;



typedef struct _TOKEN_SOURCE {
    CHAR SourceName[8];
    LUID SourceIdentifier;
} TOKEN_SOURCE, *PTOKEN_SOURCE;


typedef struct _TOKEN_STATISTICS {
    LUID TokenId;
    LUID AuthenticationId;
    LARGE_INTEGER ExpirationTime;
    TOKEN_TYPE TokenType;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    DWORD DynamicCharged;
    DWORD DynamicAvailable;
    DWORD GroupCount;
    DWORD PrivilegeCount;
    LUID ModifiedId;
} TOKEN_STATISTICS, *PTOKEN_STATISTICS;



typedef struct _TOKEN_CONTROL {
    LUID TokenId;
    LUID AuthenticationId;
    LUID ModifiedId;
    TOKEN_SOURCE TokenSource;
} TOKEN_CONTROL, *PTOKEN_CONTROL;

typedef struct _TOKEN_ORIGIN {
    LUID OriginatingLogonSession ;
} TOKEN_ORIGIN, * PTOKEN_ORIGIN ;


typedef enum _MANDATORY_LEVEL {
    MandatoryLevelUntrusted = 0,
    MandatoryLevelLow,
    MandatoryLevelMedium,
    MandatoryLevelHigh,
    MandatoryLevelSystem,
    MandatoryLevelSecureProcess,
    MandatoryLevelCount
} MANDATORY_LEVEL, *PMANDATORY_LEVEL;











typedef BOOLEAN SECURITY_CONTEXT_TRACKING_MODE,
                    * PSECURITY_CONTEXT_TRACKING_MODE;







typedef struct _SECURITY_QUALITY_OF_SERVICE {
    DWORD Length;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
    BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_OF_SERVICE, * PSECURITY_QUALITY_OF_SERVICE;






typedef struct _SE_IMPERSONATION_STATE {
    PACCESS_TOKEN Token;
    BOOLEAN CopyOnOpen;
    BOOLEAN EffectiveOnly;
    SECURITY_IMPERSONATION_LEVEL Level;
} SE_IMPERSONATION_STATE, *PSE_IMPERSONATION_STATE;






typedef DWORD SECURITY_INFORMATION, *PSECURITY_INFORMATION;































#line 8206 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#line 8212 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 8216 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





















#line 8238 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"








typedef struct _JOB_SET_ARRAY {
    HANDLE JobHandle;   
    DWORD MemberLevel;  
    DWORD Flags;        
} JOB_SET_ARRAY, *PJOB_SET_ARRAY;




typedef struct _NT_TIB {
    struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
    PVOID StackBase;
    PVOID StackLimit;
    PVOID SubSystemTib;

    union {
        PVOID FiberData;
        DWORD Version;
    };


#line 8268 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
    PVOID ArbitraryUserPointer;
    struct _NT_TIB *Self;
} NT_TIB;
typedef NT_TIB *PNT_TIB;




typedef struct _NT_TIB32 {
    DWORD ExceptionList;
    DWORD StackBase;
    DWORD StackLimit;
    DWORD SubSystemTib;


    union {
        DWORD FiberData;
        DWORD Version;
    };


#line 8290 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

    DWORD ArbitraryUserPointer;
    DWORD Self;
} NT_TIB32, *PNT_TIB32;

typedef struct _NT_TIB64 {
    DWORD64 ExceptionList;
    DWORD64 StackBase;
    DWORD64 StackLimit;
    DWORD64 SubSystemTib;


    union {
        DWORD64 FiberData;
        DWORD Version;
    };



#line 8310 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

    DWORD64 ArbitraryUserPointer;
    DWORD64 Self;
} NT_TIB64, *PNT_TIB64;








typedef struct _UMS_CREATE_THREAD_ATTRIBUTES {  
    DWORD UmsVersion;   
        PVOID UmsContext;   
        PVOID UmsCompletionList;   
} UMS_CREATE_THREAD_ATTRIBUTES, *PUMS_CREATE_THREAD_ATTRIBUTES; 

typedef struct _QUOTA_LIMITS {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;
    LARGE_INTEGER TimeLimit;
} QUOTA_LIMITS, *PQUOTA_LIMITS;







typedef union _RATE_QUOTA_LIMIT {
    DWORD RateData;
    struct {
        DWORD RatePercent : 7;
        DWORD Reserved0   : 25;
    } ;
} RATE_QUOTA_LIMIT, *PRATE_QUOTA_LIMIT;

typedef struct _QUOTA_LIMITS_EX {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;               
    LARGE_INTEGER TimeLimit;
    SIZE_T WorkingSetLimit;             
    SIZE_T Reserved2;
    SIZE_T Reserved3;
    SIZE_T Reserved4;
    DWORD  Flags;
    RATE_QUOTA_LIMIT CpuRateLimit;
} QUOTA_LIMITS_EX, *PQUOTA_LIMITS_EX;

typedef struct _IO_COUNTERS {
    ULONGLONG  ReadOperationCount;
    ULONGLONG  WriteOperationCount;
    ULONGLONG  OtherOperationCount;
    ULONGLONG ReadTransferCount;
    ULONGLONG WriteTransferCount;
    ULONGLONG OtherTransferCount;
} IO_COUNTERS;
typedef IO_COUNTERS *PIO_COUNTERS;




typedef enum _HARDWARE_COUNTER_TYPE {
    PMCCounter,
    MaxHardwareCounterType
} HARDWARE_COUNTER_TYPE, *PHARDWARE_COUNTER_TYPE;

typedef struct _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
    LARGE_INTEGER TotalUserTime;
    LARGE_INTEGER TotalKernelTime;
    LARGE_INTEGER ThisPeriodTotalUserTime;
    LARGE_INTEGER ThisPeriodTotalKernelTime;
    DWORD TotalPageFaultCount;
    DWORD TotalProcesses;
    DWORD ActiveProcesses;
    DWORD TotalTerminatedProcesses;
} JOBOBJECT_BASIC_ACCOUNTING_INFORMATION, *PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

typedef struct _JOBOBJECT_BASIC_LIMIT_INFORMATION {
    LARGE_INTEGER PerProcessUserTimeLimit;
    LARGE_INTEGER PerJobUserTimeLimit;
    DWORD LimitFlags;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    DWORD ActiveProcessLimit;
    ULONG_PTR Affinity;
    DWORD PriorityClass;
    DWORD SchedulingClass;
} JOBOBJECT_BASIC_LIMIT_INFORMATION, *PJOBOBJECT_BASIC_LIMIT_INFORMATION;

typedef struct _JOBOBJECT_EXTENDED_LIMIT_INFORMATION {
    JOBOBJECT_BASIC_LIMIT_INFORMATION BasicLimitInformation;
    IO_COUNTERS IoInfo;
    SIZE_T ProcessMemoryLimit;
    SIZE_T JobMemoryLimit;
    SIZE_T PeakProcessMemoryUsed;
    SIZE_T PeakJobMemoryUsed;
} JOBOBJECT_EXTENDED_LIMIT_INFORMATION, *PJOBOBJECT_EXTENDED_LIMIT_INFORMATION;

typedef struct _JOBOBJECT_BASIC_PROCESS_ID_LIST {
    DWORD NumberOfAssignedProcesses;
    DWORD NumberOfProcessIdsInList;
    ULONG_PTR ProcessIdList[1];
} JOBOBJECT_BASIC_PROCESS_ID_LIST, *PJOBOBJECT_BASIC_PROCESS_ID_LIST;

typedef struct _JOBOBJECT_BASIC_UI_RESTRICTIONS {
    DWORD UIRestrictionsClass;
} JOBOBJECT_BASIC_UI_RESTRICTIONS, *PJOBOBJECT_BASIC_UI_RESTRICTIONS;





typedef struct _JOBOBJECT_SECURITY_LIMIT_INFORMATION {
    DWORD SecurityLimitFlags ;
    HANDLE JobToken ;
    PTOKEN_GROUPS SidsToDisable ;
    PTOKEN_PRIVILEGES PrivilegesToDelete ;
    PTOKEN_GROUPS RestrictedSids ;
} JOBOBJECT_SECURITY_LIMIT_INFORMATION, *PJOBOBJECT_SECURITY_LIMIT_INFORMATION ;

typedef struct _JOBOBJECT_END_OF_JOB_TIME_INFORMATION {
    DWORD EndOfJobTimeAction;
} JOBOBJECT_END_OF_JOB_TIME_INFORMATION, *PJOBOBJECT_END_OF_JOB_TIME_INFORMATION;

typedef struct _JOBOBJECT_ASSOCIATE_COMPLETION_PORT {
    PVOID CompletionKey;
    HANDLE CompletionPort;
} JOBOBJECT_ASSOCIATE_COMPLETION_PORT, *PJOBOBJECT_ASSOCIATE_COMPLETION_PORT;

typedef struct _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
    JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
    IO_COUNTERS IoInfo;
} JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION, *PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

typedef struct _JOBOBJECT_JOBSET_INFORMATION {
    DWORD MemberLevel;
} JOBOBJECT_JOBSET_INFORMATION, *PJOBOBJECT_JOBSET_INFORMATION;

















































































typedef enum _JOBOBJECTINFOCLASS {
    JobObjectBasicAccountingInformation = 1,
    JobObjectBasicLimitInformation,
    JobObjectBasicProcessIdList,
    JobObjectBasicUIRestrictions,
    JobObjectSecurityLimitInformation,  
    JobObjectEndOfJobTimeInformation,
    JobObjectAssociateCompletionPortInformation,
    JobObjectBasicAndIoAccountingInformation,
    JobObjectExtendedLimitInformation,
    JobObjectJobSetInformation,
    JobObjectGroupInformation,
    MaxJobObjectInfoClass
    } JOBOBJECTINFOCLASS;





























typedef enum _LOGICAL_PROCESSOR_RELATIONSHIP {
    RelationProcessorCore,
    RelationNumaNode,
    RelationCache,
    RelationProcessorPackage,
    RelationGroup,
    RelationAll = 0xffff
} LOGICAL_PROCESSOR_RELATIONSHIP;



typedef enum _PROCESSOR_CACHE_TYPE {
    CacheUnified,
    CacheInstruction,
    CacheData,
    CacheTrace
} PROCESSOR_CACHE_TYPE;



typedef struct _CACHE_DESCRIPTOR {
    BYTE   Level;
    BYTE   Associativity;
    WORD   LineSize;
    DWORD  Size;
    PROCESSOR_CACHE_TYPE Type;
} CACHE_DESCRIPTOR, *PCACHE_DESCRIPTOR;

typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
    ULONG_PTR   ProcessorMask;
    LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
    union {
        struct {
            BYTE  Flags;
        } ProcessorCore;
        struct {
            DWORD NodeNumber;
        } NumaNode;
        CACHE_DESCRIPTOR Cache;
        ULONGLONG  Reserved[2];
    } ;
} SYSTEM_LOGICAL_PROCESSOR_INFORMATION, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

typedef struct _PROCESSOR_RELATIONSHIP {
    BYTE  Flags;
    BYTE  Reserved[21];
    WORD   GroupCount;
     GROUP_AFFINITY GroupMask[1];
} PROCESSOR_RELATIONSHIP, *PPROCESSOR_RELATIONSHIP;

typedef struct _NUMA_NODE_RELATIONSHIP {
    DWORD NodeNumber;
    BYTE  Reserved[20];
    GROUP_AFFINITY GroupMask;
} NUMA_NODE_RELATIONSHIP, *PNUMA_NODE_RELATIONSHIP;

typedef struct _CACHE_RELATIONSHIP {
    BYTE  Level;
    BYTE  Associativity;
    WORD   LineSize;
    DWORD CacheSize;
    PROCESSOR_CACHE_TYPE Type;
    BYTE  Reserved[20];
    GROUP_AFFINITY GroupMask;
} CACHE_RELATIONSHIP, *PCACHE_RELATIONSHIP;

typedef struct _PROCESSOR_GROUP_INFO {
    BYTE  MaximumProcessorCount;
    BYTE  ActiveProcessorCount;
    BYTE  Reserved[38];
    KAFFINITY ActiveProcessorMask;
} PROCESSOR_GROUP_INFO, *PPROCESSOR_GROUP_INFO;

typedef struct _GROUP_RELATIONSHIP {
    WORD   MaximumGroupCount;
    WORD   ActiveGroupCount;
    BYTE  Reserved[20];
    PROCESSOR_GROUP_INFO GroupInfo[1];
} GROUP_RELATIONSHIP, *PGROUP_RELATIONSHIP;

 struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX {
    LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
    DWORD Size;
    union {
        PROCESSOR_RELATIONSHIP Processor;
        NUMA_NODE_RELATIONSHIP NumaNode;
        CACHE_RELATIONSHIP Cache;
        GROUP_RELATIONSHIP Group;
    } ;
};

typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX;



typedef struct _SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION {
    DWORD64 CycleTime;
} SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION, *PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION;














































































typedef struct _XSTATE_FEATURE {
    DWORD Offset;
    DWORD Size;
} XSTATE_FEATURE, *PXSTATE_FEATURE;

typedef struct _XSTATE_CONFIGURATION {
    
    DWORD64 EnabledFeatures;

    
    DWORD Size;

    DWORD OptimizedSave : 1;

    
    XSTATE_FEATURE Features[64];

} XSTATE_CONFIGURATION, *PXSTATE_CONFIGURATION;


typedef struct _MEMORY_BASIC_INFORMATION {
    PVOID BaseAddress;
    PVOID AllocationBase;
    DWORD AllocationProtect;
    SIZE_T RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;

typedef struct _MEMORY_BASIC_INFORMATION32 {
    DWORD BaseAddress;
    DWORD AllocationBase;
    DWORD AllocationProtect;
    DWORD RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
} MEMORY_BASIC_INFORMATION32, *PMEMORY_BASIC_INFORMATION32;

typedef struct __declspec(align(16)) _MEMORY_BASIC_INFORMATION64 {
    ULONGLONG BaseAddress;
    ULONGLONG AllocationBase;
    DWORD     AllocationProtect;
    DWORD     __alignment1;
    ULONGLONG RegionSize;
    DWORD     State;
    DWORD     Protect;
    DWORD     Type;
    DWORD     __alignment2;
} MEMORY_BASIC_INFORMATION64, *PMEMORY_BASIC_INFORMATION64;













































































































































































typedef struct _FILE_NOTIFY_INFORMATION {
    DWORD NextEntryOffset;
    DWORD Action;
    DWORD FileNameLength;
    WCHAR FileName[1];
} FILE_NOTIFY_INFORMATION, *PFILE_NOTIFY_INFORMATION;






typedef union _FILE_SEGMENT_ELEMENT {
    PVOID64 Buffer;
    ULONGLONG Alignment;
}FILE_SEGMENT_ELEMENT, *PFILE_SEGMENT_ELEMENT;









typedef struct _REPARSE_GUID_DATA_BUFFER {
    DWORD  ReparseTag;
    WORD   ReparseDataLength;
    WORD   Reserved;
    GUID   ReparseGuid;
    struct {
        BYTE   DataBuffer[1];
    } GenericReparseBuffer;
} REPARSE_GUID_DATA_BUFFER, *PREPARSE_GUID_DATA_BUFFER;







































































































extern "C" const GUID  GUID_MAX_POWER_SAVINGS;






extern "C" const GUID  GUID_MIN_POWER_SAVINGS;






extern "C" const GUID  GUID_TYPICAL_POWER_SAVINGS;







extern "C" const GUID  NO_SUBGROUP_GUID;







extern "C" const GUID  ALL_POWERSCHEMES_GUID;




































extern "C" const GUID  GUID_POWERSCHEME_PERSONALITY;








extern "C" const GUID  GUID_ACTIVE_POWERSCHEME;













extern "C" const GUID  GUID_VIDEO_SUBGROUP;





extern "C" const GUID  GUID_VIDEO_POWERDOWN_TIMEOUT;





extern "C" const GUID  GUID_VIDEO_ANNOYANCE_TIMEOUT;





extern "C" const GUID  GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE;





extern "C" const GUID  GUID_VIDEO_DIM_TIMEOUT;





extern "C" const GUID  GUID_VIDEO_ADAPTIVE_POWERDOWN;





extern "C" const GUID  GUID_MONITOR_POWER_ON;




extern "C" const GUID  GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS;





extern "C" const GUID  GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS;




extern "C" const GUID  GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS;






extern "C" const GUID  GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS;








extern "C" const GUID  GUID_SESSION_DISPLAY_STATE;





extern "C" const GUID  GUID_CONSOLE_DISPLAY_STATE;







extern "C" const GUID  GUID_ALLOW_DISPLAY_REQUIRED;







extern "C" const GUID  GUID_DISK_SUBGROUP;





extern "C" const GUID  GUID_DISK_POWERDOWN_TIMEOUT;








extern "C" const GUID  GUID_DISK_BURST_IGNORE_THRESHOLD;





extern "C" const GUID  GUID_DISK_ADAPTIVE_POWERDOWN;








extern "C" const GUID  GUID_SLEEP_SUBGROUP;







extern "C" const GUID  GUID_SLEEP_IDLE_THRESHOLD;





extern "C" const GUID  GUID_STANDBY_TIMEOUT;








extern "C" const GUID  GUID_UNATTEND_SLEEP_TIMEOUT;





extern "C" const GUID  GUID_HIBERNATE_TIMEOUT;





extern "C" const GUID  GUID_HIBERNATE_FASTS4_POLICY;








extern "C" const GUID  GUID_CRITICAL_POWER_TRANSITION;





extern "C" const GUID  GUID_SYSTEM_AWAYMODE;





extern "C" const GUID  GUID_ALLOW_AWAYMODE;







extern "C" const GUID  GUID_ALLOW_STANDBY_STATES;






extern "C" const GUID  GUID_ALLOW_RTC_WAKE;







extern "C" const GUID  GUID_ALLOW_SYSTEM_REQUIRED;
  







extern "C" const GUID  GUID_SYSTEM_BUTTON_SUBGROUP;




extern "C" const GUID  GUID_POWERBUTTON_ACTION;
extern "C" const GUID  GUID_POWERBUTTON_ACTION_FLAGS;





extern "C" const GUID  GUID_SLEEPBUTTON_ACTION;
extern "C" const GUID  GUID_SLEEPBUTTON_ACTION_FLAGS;






extern "C" const GUID  GUID_USERINTERFACEBUTTON_ACTION;





extern "C" const GUID  GUID_LIDCLOSE_ACTION;
extern "C" const GUID  GUID_LIDCLOSE_ACTION_FLAGS;
extern "C" const GUID  GUID_LIDOPEN_POWERSTATE;








extern "C" const GUID  GUID_BATTERY_SUBGROUP;











extern "C" const GUID  GUID_BATTERY_DISCHARGE_ACTION_0;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_LEVEL_0;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_FLAGS_0;

extern "C" const GUID  GUID_BATTERY_DISCHARGE_ACTION_1;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_LEVEL_1;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_FLAGS_1;

extern "C" const GUID  GUID_BATTERY_DISCHARGE_ACTION_2;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_LEVEL_2;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_FLAGS_2;

extern "C" const GUID  GUID_BATTERY_DISCHARGE_ACTION_3;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_LEVEL_3;
extern "C" const GUID  GUID_BATTERY_DISCHARGE_FLAGS_3;








extern "C" const GUID  GUID_PROCESSOR_SETTINGS_SUBGROUP;





extern "C" const GUID  GUID_PROCESSOR_THROTTLE_POLICY;












extern "C" const GUID  GUID_PROCESSOR_THROTTLE_MAXIMUM;







extern "C" const GUID  GUID_PROCESSOR_THROTTLE_MINIMUM;







extern "C" const GUID  GUID_PROCESSOR_ALLOW_THROTTLING;





extern "C" const GUID  GUID_PROCESSOR_IDLESTATE_POLICY;





extern "C" const GUID  GUID_PROCESSOR_PERFSTATE_POLICY;







extern "C" const GUID  GUID_PROCESSOR_PERF_INCREASE_THRESHOLD;







extern "C" const GUID  GUID_PROCESSOR_PERF_DECREASE_THRESHOLD;







extern "C" const GUID  GUID_PROCESSOR_PERF_INCREASE_POLICY;







extern "C" const GUID  GUID_PROCESSOR_PERF_DECREASE_POLICY;








extern "C" const GUID  GUID_PROCESSOR_PERF_INCREASE_TIME;








extern "C" const GUID  GUID_PROCESSOR_PERF_DECREASE_TIME;







extern "C" const GUID  GUID_PROCESSOR_PERF_TIME_CHECK;







extern "C" const GUID  GUID_PROCESSOR_PERF_BOOST_POLICY;
#line 9601 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"










extern "C" const GUID  GUID_PROCESSOR_IDLE_ALLOW_SCALING;






extern "C" const GUID  GUID_PROCESSOR_IDLE_DISABLE;








extern "C" const GUID  GUID_PROCESSOR_IDLE_TIME_CHECK;








extern "C" const GUID  GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD;







extern "C" const GUID  GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY;











extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_MAX_CORES;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_MIN_CORES;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING;






extern "C" const GUID  GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD;







extern "C" const GUID  GUID_PROCESSOR_PARKING_CORE_OVERRIDE;







extern "C" const GUID  GUID_PROCESSOR_PARKING_PERF_STATE;






extern "C" const GUID  GUID_PROCESSOR_PERF_HISTORY;







extern "C" const GUID  GUID_SYSTEM_COOLING_POLICY;









extern "C" const GUID  GUID_LOCK_CONSOLE_ON_WAKE;









extern "C" const GUID  GUID_DEVICE_IDLE_POLICY;




















extern "C" const GUID  GUID_ACDC_POWER_SOURCE;















extern "C" const GUID  GUID_LIDSWITCH_STATE_CHANGE;
















extern "C" const GUID  GUID_BATTERY_PERCENTAGE_REMAINING;






extern "C" const GUID  GUID_IDLE_BACKGROUND_TASK;






extern "C" const GUID  GUID_BACKGROUND_TASK_NOTIFICATION;







extern "C" const GUID  GUID_APPLAUNCH_BUTTON;










extern "C" const GUID  GUID_PCIEXPRESS_SETTINGS_SUBGROUP;





extern "C" const GUID  GUID_PCIEXPRESS_ASPM_POLICY;











extern "C" const GUID  GUID_ENABLE_SWITCH_FORCED_SHUTDOWN;


typedef enum _SYSTEM_POWER_STATE {
    PowerSystemUnspecified = 0,
    PowerSystemWorking     = 1,
    PowerSystemSleeping1   = 2,
    PowerSystemSleeping2   = 3,
    PowerSystemSleeping3   = 4,
    PowerSystemHibernate   = 5,
    PowerSystemShutdown    = 6,
    PowerSystemMaximum     = 7
} SYSTEM_POWER_STATE, *PSYSTEM_POWER_STATE;



typedef enum {
    PowerActionNone = 0,
    PowerActionReserved,
    PowerActionSleep,
    PowerActionHibernate,
    PowerActionShutdown,
    PowerActionShutdownReset,
    PowerActionShutdownOff,
    PowerActionWarmEject
} POWER_ACTION, *PPOWER_ACTION;

typedef enum _DEVICE_POWER_STATE {
    PowerDeviceUnspecified = 0,
    PowerDeviceD0,
    PowerDeviceD1,
    PowerDeviceD2,
    PowerDeviceD3,
    PowerDeviceMaximum
} DEVICE_POWER_STATE, *PDEVICE_POWER_STATE;

typedef enum _MONITOR_DISPLAY_STATE {
    PowerMonitorOff = 0,
    PowerMonitorOn,
    PowerMonitorDim
} MONITOR_DISPLAY_STATE, *PMONITOR_DISPLAY_STATE;








typedef DWORD EXECUTION_STATE, *PEXECUTION_STATE;

typedef enum {
    LT_DONT_CARE,
    LT_LOWEST_LATENCY
} LATENCY_TIME;










#line 9976 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
















typedef enum _POWER_REQUEST_TYPE {
    PowerRequestDisplayRequired,
    PowerRequestSystemRequired,
    PowerRequestAwayModeRequired
} POWER_REQUEST_TYPE, *PPOWER_REQUEST_TYPE;






















typedef struct CM_Power_Data_s {
    DWORD               PD_Size;
    DEVICE_POWER_STATE  PD_MostRecentPowerState;
    DWORD               PD_Capabilities;
    DWORD               PD_D1Latency;
    DWORD               PD_D2Latency;
    DWORD               PD_D3Latency;
    DEVICE_POWER_STATE  PD_PowerStateMapping[7];
    SYSTEM_POWER_STATE  PD_DeepestSystemWake;
} CM_POWER_DATA, *PCM_POWER_DATA;

#line 10031 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



typedef enum {
    SystemPowerPolicyAc,
    SystemPowerPolicyDc,
    VerifySystemPolicyAc,
    VerifySystemPolicyDc,
    SystemPowerCapabilities,
    SystemBatteryState,
    SystemPowerStateHandler,
    ProcessorStateHandler,
    SystemPowerPolicyCurrent,
    AdministratorPowerPolicy,
    SystemReserveHiberFile,
    ProcessorInformation,
    SystemPowerInformation,
    ProcessorStateHandler2,
    LastWakeTime,                                   
    LastSleepTime,                                  
    SystemExecutionState,
    SystemPowerStateNotifyHandler,
    ProcessorPowerPolicyAc,
    ProcessorPowerPolicyDc,
    VerifyProcessorPowerPolicyAc,
    VerifyProcessorPowerPolicyDc,
    ProcessorPowerPolicyCurrent,
    SystemPowerStateLogging,
    SystemPowerLoggingEntry,
    SetPowerSettingValue,
    NotifyUserPowerSetting,
    PowerInformationLevelUnused0,
    PowerInformationLevelUnused1,
    SystemVideoState,
    TraceApplicationPowerMessage,
    TraceApplicationPowerMessageEnd,
    ProcessorPerfStates,
    ProcessorIdleStates,
    ProcessorCap,
    SystemWakeSource,
    SystemHiberFileInformation,
    TraceServicePowerMessage,
    ProcessorLoad,
    PowerShutdownNotification,
    MonitorCapabilities,
    SessionPowerInit,
    SessionDisplayState,
    PowerRequestCreate,
    PowerRequestAction,
    GetPowerRequestList,
    ProcessorInformationEx,
    NotifyUserModeLegacyPowerEvent,
    GroupPark,
    ProcessorIdleDomains,
    WakeTimerList,
    SystemHiberFileSize,
    PowerInformationLevelMaximum
} POWER_INFORMATION_LEVEL;





typedef enum {
    PoAc,
    PoDc,
    PoHot,
    PoConditionMaximum
} SYSTEM_POWER_CONDITION;

typedef struct {

    
    
    
    
    DWORD       Version;


    
    
    
    GUID        Guid;


    
    
    
    
    SYSTEM_POWER_CONDITION PowerCondition;

    
    
    
    DWORD       DataLength;

    
    
    
    BYTE    Data[1];
} SET_POWER_SETTING_VALUE, *PSET_POWER_SETTING_VALUE;



typedef struct {
    GUID Guid;
} NOTIFY_USER_POWER_SETTING, *PNOTIFY_USER_POWER_SETTING;






typedef struct _APPLICATIONLAUNCH_SETTING_VALUE {

    
    
    
    
    LARGE_INTEGER       ActivationTime;

    
    
    
    DWORD               Flags;

    
    
    
    DWORD               ButtonInstanceID;


} APPLICATIONLAUNCH_SETTING_VALUE, *PAPPLICATIONLAUNCH_SETTING_VALUE;





typedef enum {
    PlatformRoleUnspecified = 0,
    PlatformRoleDesktop,
    PlatformRoleMobile,
    PlatformRoleWorkstation,
    PlatformRoleEnterpriseServer,
    PlatformRoleSOHOServer,
    PlatformRoleAppliancePC,
    PlatformRolePerformanceServer,
    PlatformRoleMaximum
} POWER_PLATFORM_ROLE;






typedef struct {
    DWORD       Granularity;
    DWORD       Capacity;
} BATTERY_REPORTING_SCALE, *PBATTERY_REPORTING_SCALE;
#line 10191 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



typedef struct {
    DWORD   Frequency;
    DWORD   Flags;
    DWORD   PercentFrequency;
} PPM_WMI_LEGACY_PERFSTATE, *PPPM_WMI_LEGACY_PERFSTATE;

typedef struct {
    DWORD Latency;
    DWORD Power;
    DWORD TimeCheck;
    BYTE  PromotePercent;
    BYTE  DemotePercent;
    BYTE  StateType;
    BYTE  Reserved;
    DWORD StateFlags;
    DWORD Context;
    DWORD IdleHandler;
    DWORD Reserved1;            
} PPM_WMI_IDLE_STATE, *PPPM_WMI_IDLE_STATE;

typedef struct {
    DWORD Type;
    DWORD Count;
    DWORD TargetState;          
    DWORD OldState;             
    DWORD64 TargetProcessors;
    PPM_WMI_IDLE_STATE State[1];
} PPM_WMI_IDLE_STATES, *PPPM_WMI_IDLE_STATES;

typedef struct {
    DWORD Type;
    DWORD Count;
    DWORD TargetState;          
    DWORD OldState;             
    PVOID TargetProcessors;
    PPM_WMI_IDLE_STATE State[1];
} PPM_WMI_IDLE_STATES_EX, *PPPM_WMI_IDLE_STATES_EX;

typedef struct {
    DWORD Frequency;            
    DWORD Power;                
    BYTE  PercentFrequency;
    BYTE  IncreaseLevel;        
    BYTE  DecreaseLevel;        
    BYTE  Type;                 
    DWORD IncreaseTime;         
    DWORD DecreaseTime;         
    DWORD64 Control;            
    DWORD64 Status;             
    DWORD HitCount;
    DWORD Reserved1;            
    DWORD64 Reserved2;
    DWORD64 Reserved3;
} PPM_WMI_PERF_STATE, *PPPM_WMI_PERF_STATE;

typedef struct {
    DWORD Count;
    DWORD MaxFrequency;
    DWORD CurrentState;         
    DWORD MaxPerfState;         
    DWORD MinPerfState;         
    DWORD LowestPerfState;      
    DWORD ThermalConstraint;
    BYTE  BusyAdjThreshold;
    BYTE  PolicyType;           
    BYTE  Type;
    BYTE  Reserved;
    DWORD TimerInterval;
    DWORD64 TargetProcessors;   
    DWORD PStateHandler;
    DWORD PStateContext;
    DWORD TStateHandler;
    DWORD TStateContext;
    DWORD FeedbackHandler;
    DWORD Reserved1;
    DWORD64 Reserved2;
    PPM_WMI_PERF_STATE State[1];
} PPM_WMI_PERF_STATES, *PPPM_WMI_PERF_STATES;

typedef struct {
    DWORD Count;
    DWORD MaxFrequency;
    DWORD CurrentState;         
    DWORD MaxPerfState;         
    DWORD MinPerfState;         
    DWORD LowestPerfState;      
    DWORD ThermalConstraint;
    BYTE  BusyAdjThreshold;
    BYTE  PolicyType;           
    BYTE  Type;
    BYTE  Reserved;
    DWORD TimerInterval;
    PVOID TargetProcessors;     
    DWORD PStateHandler;
    DWORD PStateContext;
    DWORD TStateHandler;
    DWORD TStateContext;
    DWORD FeedbackHandler;
    DWORD Reserved1;
    DWORD64 Reserved2;
    PPM_WMI_PERF_STATE State[1];
} PPM_WMI_PERF_STATES_EX, *PPPM_WMI_PERF_STATES_EX;







typedef struct {
    DWORD IdleTransitions;
    DWORD FailedTransitions;
    DWORD InvalidBucketIndex;
    DWORD64 TotalTime;
    DWORD IdleTimeBuckets[6];
} PPM_IDLE_STATE_ACCOUNTING, *PPPM_IDLE_STATE_ACCOUNTING;

typedef struct {
    DWORD StateCount;
    DWORD TotalTransitions;
    DWORD ResetCount;
    DWORD64 StartTime;
    PPM_IDLE_STATE_ACCOUNTING State[1];
} PPM_IDLE_ACCOUNTING, *PPPM_IDLE_ACCOUNTING;







typedef struct {
    DWORD64 TotalTimeUs;
    DWORD MinTimeUs;
    DWORD MaxTimeUs;
    DWORD Count;
} PPM_IDLE_STATE_BUCKET_EX, *PPPM_IDLE_STATE_BUCKET_EX;

typedef struct {
    DWORD64 TotalTime;
    DWORD IdleTransitions;
    DWORD FailedTransitions;
    DWORD InvalidBucketIndex;
    DWORD MinTimeUs;
    DWORD MaxTimeUs;
    PPM_IDLE_STATE_BUCKET_EX IdleTimeBuckets[16];
} PPM_IDLE_STATE_ACCOUNTING_EX, *PPPM_IDLE_STATE_ACCOUNTING_EX;

typedef struct {
    DWORD StateCount;
    DWORD TotalTransitions;
    DWORD ResetCount;
    DWORD64 StartTime;
     PPM_IDLE_STATE_ACCOUNTING_EX State[1];
} PPM_IDLE_ACCOUNTING_EX, *PPPM_IDLE_ACCOUNTING_EX;










































extern "C" const GUID  PPM_PERFSTATE_CHANGE_GUID;
#line 10393 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_PERFSTATE_DOMAIN_CHANGE_GUID;
#line 10397 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_IDLESTATE_CHANGE_GUID;
#line 10401 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_PERFSTATES_DATA_GUID;
#line 10405 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_IDLESTATES_DATA_GUID;
#line 10409 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_IDLE_ACCOUNTING_GUID;
#line 10413 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_IDLE_ACCOUNTING_EX_GUID;
#line 10417 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_THERMALCONSTRAINT_GUID;
#line 10421 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_PERFMON_PERFSTATE_GUID;
#line 10425 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


extern "C" const GUID  PPM_THERMAL_POLICY_CHANGE_GUID;
#line 10429 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


typedef struct {
    DWORD State;
    DWORD Status;
    DWORD Latency;
    DWORD Speed;
    DWORD Processor;
} PPM_PERFSTATE_EVENT, *PPPM_PERFSTATE_EVENT;

typedef struct {
    DWORD State;
    DWORD Latency;
    DWORD Speed;
    DWORD64 Processors;
} PPM_PERFSTATE_DOMAIN_EVENT, *PPPM_PERFSTATE_DOMAIN_EVENT;

typedef struct {
    DWORD NewState;
    DWORD OldState;
    DWORD64 Processors;
} PPM_IDLESTATE_EVENT, *PPPM_IDLESTATE_EVENT;

typedef struct {
    DWORD ThermalConstraint;
    DWORD64 Processors;
} PPM_THERMALCHANGE_EVENT, *PPPM_THERMALCHANGE_EVENT;

#pragma warning(push)
#pragma warning(disable:4121)

typedef struct {
    BYTE  Mode;
    DWORD64 Processors;
} PPM_THERMAL_POLICY_EVENT, *PPPM_THERMAL_POLICY_EVENT;

#pragma warning(pop)




typedef struct {
    POWER_ACTION    Action;
    DWORD           Flags;
    DWORD           EventCode;
} POWER_ACTION_POLICY, *PPOWER_ACTION_POLICY;































typedef struct {
    BOOLEAN                 Enable;
    BYTE                    Spare[3];
    DWORD                   BatteryLevel;
    POWER_ACTION_POLICY     PowerPolicy;
    SYSTEM_POWER_STATE      MinSystemState;
} SYSTEM_POWER_LEVEL, *PSYSTEM_POWER_LEVEL;








typedef struct _SYSTEM_POWER_POLICY {
    DWORD                   Revision;       

    
    POWER_ACTION_POLICY     PowerButton;
    POWER_ACTION_POLICY     SleepButton;
    POWER_ACTION_POLICY     LidClose;
    SYSTEM_POWER_STATE      LidOpenWake;
    DWORD                   Reserved;

    
    POWER_ACTION_POLICY     Idle;
    DWORD                   IdleTimeout;
    BYTE                    IdleSensitivity;

    BYTE                    DynamicThrottle;
    BYTE                    Spare2[2];

    
    SYSTEM_POWER_STATE      MinSleep;
    SYSTEM_POWER_STATE      MaxSleep;
    SYSTEM_POWER_STATE      ReducedLatencySleep;
    DWORD                   WinLogonFlags;

    DWORD                   Spare3;

    
    
    DWORD                   DozeS4Timeout;

    
    DWORD                   BroadcastCapacityResolution;
    SYSTEM_POWER_LEVEL      DischargePolicy[4];

    
    DWORD                   VideoTimeout;
    BOOLEAN                 VideoDimDisplay;
    DWORD                   VideoReserved[3];

    
    DWORD                   SpindownTimeout;

    
    BOOLEAN                 OptimizeForPower;
    BYTE                    FanThrottleTolerance;
    BYTE                    ForcedThrottle;
    BYTE                    MinThrottle;
    POWER_ACTION_POLICY     OverThrottled;

} SYSTEM_POWER_POLICY, *PSYSTEM_POWER_POLICY;










typedef struct {
    DWORD TimeCheck;
    BYTE  DemotePercent;
    BYTE  PromotePercent;
    BYTE  Spare[2];
} PROCESSOR_IDLESTATE_INFO, *PPROCESSOR_IDLESTATE_INFO;

typedef struct {
    WORD   Revision;
    union {
        WORD   AsWORD  ;
        struct {
            WORD   AllowScaling : 1;
            WORD   Disabled : 1;
            WORD   Reserved : 14;
        } ;
    } Flags;

    DWORD PolicyCount;
    PROCESSOR_IDLESTATE_INFO Policy[0x3];
} PROCESSOR_IDLESTATE_POLICY, *PPROCESSOR_IDLESTATE_POLICY;














typedef struct _PROCESSOR_POWER_POLICY_INFO {

    
    DWORD                   TimeCheck;                      
    DWORD                   DemoteLimit;                    
    DWORD                   PromoteLimit;                   

    
    BYTE                    DemotePercent;
    BYTE                    PromotePercent;
    BYTE                    Spare[2];

    
    DWORD                   AllowDemotion:1;
    DWORD                   AllowPromotion:1;
    DWORD                   Reserved:30;

} PROCESSOR_POWER_POLICY_INFO, *PPROCESSOR_POWER_POLICY_INFO;


typedef struct _PROCESSOR_POWER_POLICY {
    DWORD                       Revision;       

    
    BYTE                        DynamicThrottle;
    BYTE                        Spare[3];

    
    DWORD                       DisableCStates:1;
    DWORD                       Reserved:31;

    
    
    
    DWORD                       PolicyCount;
    PROCESSOR_POWER_POLICY_INFO Policy[3];

} PROCESSOR_POWER_POLICY, *PPROCESSOR_POWER_POLICY;





typedef struct {
    DWORD Revision;
    BYTE  MaxThrottle;
    BYTE  MinThrottle;
    BYTE  BusyAdjThreshold;
    union {
        BYTE  Spare;
        union {
            BYTE  AsBYTE ;
            struct {
                BYTE  NoDomainAccounting : 1;
                BYTE  IncreasePolicy: 2;
                BYTE  DecreasePolicy: 2;
                BYTE  Reserved : 3;
            } ;
        } Flags;
    } ;
    
    DWORD TimeCheck;
    DWORD IncreaseTime;
    DWORD DecreaseTime;
    DWORD IncreasePercent;
    DWORD DecreasePercent;
} PROCESSOR_PERFSTATE_POLICY, *PPROCESSOR_PERFSTATE_POLICY;


typedef struct _ADMINISTRATOR_POWER_POLICY {

    
    SYSTEM_POWER_STATE      MinSleep;
    SYSTEM_POWER_STATE      MaxSleep;

    
    DWORD                   MinVideoTimeout;
    DWORD                   MaxVideoTimeout;

    
    DWORD                   MinSpindownTimeout;
    DWORD                   MaxSpindownTimeout;
} ADMINISTRATOR_POWER_POLICY, *PADMINISTRATOR_POWER_POLICY;


typedef struct {
    
    BOOLEAN             PowerButtonPresent;
    BOOLEAN             SleepButtonPresent;
    BOOLEAN             LidPresent;
    BOOLEAN             SystemS1;
    BOOLEAN             SystemS2;
    BOOLEAN             SystemS3;
    BOOLEAN             SystemS4;           
    BOOLEAN             SystemS5;           
    BOOLEAN             HiberFilePresent;
    BOOLEAN             FullWake;
    BOOLEAN             VideoDimPresent;
    BOOLEAN             ApmPresent;
    BOOLEAN             UpsPresent;

    
    BOOLEAN             ThermalControl;
    BOOLEAN             ProcessorThrottle;
    BYTE                ProcessorMinThrottle;




#line 10726 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
    BYTE                ProcessorMaxThrottle;
    BOOLEAN             FastSystemS4;
    BYTE                spare2[3];
#line 10730 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

    
    BOOLEAN             DiskSpinDown;
    BYTE                spare3[8];

    
    BOOLEAN             SystemBatteriesPresent;
    BOOLEAN             BatteriesAreShortTerm;
    BATTERY_REPORTING_SCALE BatteryScale[3];

    
    SYSTEM_POWER_STATE  AcOnLineWake;
    SYSTEM_POWER_STATE  SoftLidWake;
    SYSTEM_POWER_STATE  RtcWake;
    SYSTEM_POWER_STATE  MinDeviceWakeState; 
    SYSTEM_POWER_STATE  DefaultLowLatencyWake;
} SYSTEM_POWER_CAPABILITIES, *PSYSTEM_POWER_CAPABILITIES;

typedef struct {
    BOOLEAN             AcOnLine;
    BOOLEAN             BatteryPresent;
    BOOLEAN             Charging;
    BOOLEAN             Discharging;
    BOOLEAN             Spare1[4];

    DWORD               MaxCapacity;
    DWORD               RemainingCapacity;
    DWORD               Rate;
    DWORD               EstimatedTime;

    DWORD               DefaultAlert1;
    DWORD               DefaultAlert2;
} SYSTEM_BATTERY_STATE, *PSYSTEM_BATTERY_STATE;










#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"























#pragma warning(disable:4103)

#pragma pack(push,4)


#line 30 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"
#line 34 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack4.h"

#line 10774 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"







#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"























#pragma warning(disable:4103)

#pragma pack(push,2)


#line 30 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"
#line 34 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"

#line 10782 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"









#line 10792 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _IMAGE_DOS_HEADER {      
    WORD   e_magic;                     
    WORD   e_cblp;                      
    WORD   e_cp;                        
    WORD   e_crlc;                      
    WORD   e_cparhdr;                   
    WORD   e_minalloc;                  
    WORD   e_maxalloc;                  
    WORD   e_ss;                        
    WORD   e_sp;                        
    WORD   e_csum;                      
    WORD   e_ip;                        
    WORD   e_cs;                        
    WORD   e_lfarlc;                    
    WORD   e_ovno;                      
    WORD   e_res[4];                    
    WORD   e_oemid;                     
    WORD   e_oeminfo;                   
    WORD   e_res2[10];                  
    LONG   e_lfanew;                    
  } IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_OS2_HEADER {      
    WORD   ne_magic;                    
    CHAR   ne_ver;                      
    CHAR   ne_rev;                      
    WORD   ne_enttab;                   
    WORD   ne_cbenttab;                 
    LONG   ne_crc;                      
    WORD   ne_flags;                    
    WORD   ne_autodata;                 
    WORD   ne_heap;                     
    WORD   ne_stack;                    
    LONG   ne_csip;                     
    LONG   ne_sssp;                     
    WORD   ne_cseg;                     
    WORD   ne_cmod;                     
    WORD   ne_cbnrestab;                
    WORD   ne_segtab;                   
    WORD   ne_rsrctab;                  
    WORD   ne_restab;                   
    WORD   ne_modtab;                   
    WORD   ne_imptab;                   
    LONG   ne_nrestab;                  
    WORD   ne_cmovent;                  
    WORD   ne_align;                    
    WORD   ne_cres;                     
    BYTE   ne_exetyp;                   
    BYTE   ne_flagsothers;              
    WORD   ne_pretthunks;               
    WORD   ne_psegrefbytes;             
    WORD   ne_swaparea;                 
    WORD   ne_expver;                   
  } IMAGE_OS2_HEADER, *PIMAGE_OS2_HEADER;

typedef struct _IMAGE_VXD_HEADER {      
    WORD   e32_magic;                   
    BYTE   e32_border;                  
    BYTE   e32_worder;                  
    DWORD  e32_level;                   
    WORD   e32_cpu;                     
    WORD   e32_os;                      
    DWORD  e32_ver;                     
    DWORD  e32_mflags;                  
    DWORD  e32_mpages;                  
    DWORD  e32_startobj;                
    DWORD  e32_eip;                     
    DWORD  e32_stackobj;                
    DWORD  e32_esp;                     
    DWORD  e32_pagesize;                
    DWORD  e32_lastpagesize;            
    DWORD  e32_fixupsize;               
    DWORD  e32_fixupsum;                
    DWORD  e32_ldrsize;                 
    DWORD  e32_ldrsum;                  
    DWORD  e32_objtab;                  
    DWORD  e32_objcnt;                  
    DWORD  e32_objmap;                  
    DWORD  e32_itermap;                 
    DWORD  e32_rsrctab;                 
    DWORD  e32_rsrccnt;                 
    DWORD  e32_restab;                  
    DWORD  e32_enttab;                  
    DWORD  e32_dirtab;                  
    DWORD  e32_dircnt;                  
    DWORD  e32_fpagetab;                
    DWORD  e32_frectab;                 
    DWORD  e32_impmod;                  
    DWORD  e32_impmodcnt;               
    DWORD  e32_impproc;                 
    DWORD  e32_pagesum;                 
    DWORD  e32_datapage;                
    DWORD  e32_preload;                 
    DWORD  e32_nrestab;                 
    DWORD  e32_cbnrestab;               
    DWORD  e32_nressum;                 
    DWORD  e32_autodata;                
    DWORD  e32_debuginfo;               
    DWORD  e32_debuglen;                
    DWORD  e32_instpreload;             
    DWORD  e32_instdemand;              
    DWORD  e32_heapsize;                
    BYTE   e32_res3[12];                
    DWORD  e32_winresoff;
    DWORD  e32_winreslen;
    WORD   e32_devid;                   
    WORD   e32_ddkver;                  
  } IMAGE_VXD_HEADER, *PIMAGE_VXD_HEADER;


#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


#line 36 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"
#line 37 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"

#line 10904 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 10905 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef struct _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;





















































typedef struct _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;







typedef struct _IMAGE_OPTIONAL_HEADER {
    
    
    

    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
    DWORD   BaseOfData;

    
    
    

    DWORD   ImageBase;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    MajorOperatingSystemVersion;
    WORD    MinorOperatingSystemVersion;
    WORD    MajorImageVersion;
    WORD    MinorImageVersion;
    WORD    MajorSubsystemVersion;
    WORD    MinorSubsystemVersion;
    DWORD   Win32VersionValue;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct _IMAGE_ROM_OPTIONAL_HEADER {
    WORD   Magic;
    BYTE   MajorLinkerVersion;
    BYTE   MinorLinkerVersion;
    DWORD  SizeOfCode;
    DWORD  SizeOfInitializedData;
    DWORD  SizeOfUninitializedData;
    DWORD  AddressOfEntryPoint;
    DWORD  BaseOfCode;
    DWORD  BaseOfData;
    DWORD  BaseOfBss;
    DWORD  GprMask;
    DWORD  CprMask[4];
    DWORD  GpValue;
} IMAGE_ROM_OPTIONAL_HEADER, *PIMAGE_ROM_OPTIONAL_HEADER;

typedef struct _IMAGE_OPTIONAL_HEADER64 {
    WORD        Magic;
    BYTE        MajorLinkerVersion;
    BYTE        MinorLinkerVersion;
    DWORD       SizeOfCode;
    DWORD       SizeOfInitializedData;
    DWORD       SizeOfUninitializedData;
    DWORD       AddressOfEntryPoint;
    DWORD       BaseOfCode;
    ULONGLONG   ImageBase;
    DWORD       SectionAlignment;
    DWORD       FileAlignment;
    WORD        MajorOperatingSystemVersion;
    WORD        MinorOperatingSystemVersion;
    WORD        MajorImageVersion;
    WORD        MinorImageVersion;
    WORD        MajorSubsystemVersion;
    WORD        MinorSubsystemVersion;
    DWORD       Win32VersionValue;
    DWORD       SizeOfImage;
    DWORD       SizeOfHeaders;
    DWORD       CheckSum;
    WORD        Subsystem;
    WORD        DllCharacteristics;
    ULONGLONG   SizeOfStackReserve;
    ULONGLONG   SizeOfStackCommit;
    ULONGLONG   SizeOfHeapReserve;
    ULONGLONG   SizeOfHeapCommit;
    DWORD       LoaderFlags;
    DWORD       NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;










typedef IMAGE_OPTIONAL_HEADER32             IMAGE_OPTIONAL_HEADER;
typedef PIMAGE_OPTIONAL_HEADER32            PIMAGE_OPTIONAL_HEADER;

#line 11088 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _IMAGE_NT_HEADERS64 {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

typedef struct _IMAGE_NT_HEADERS {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

typedef struct _IMAGE_ROM_HEADERS {
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
} IMAGE_ROM_HEADERS, *PIMAGE_ROM_HEADERS;





typedef IMAGE_NT_HEADERS32                  IMAGE_NT_HEADERS;
typedef PIMAGE_NT_HEADERS32                 PIMAGE_NT_HEADERS;
#line 11113 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


































































typedef struct ANON_OBJECT_HEADER {
    WORD    Sig1;            
    WORD    Sig2;            
    WORD    Version;         
    WORD    Machine;
    DWORD   TimeDateStamp;
    CLSID   ClassID;         
    DWORD   SizeOfData;      
} ANON_OBJECT_HEADER;

typedef struct ANON_OBJECT_HEADER_V2 {
    WORD    Sig1;            
    WORD    Sig2;            
    WORD    Version;         
    WORD    Machine;
    DWORD   TimeDateStamp;
    CLSID   ClassID;         
    DWORD   SizeOfData;      
    DWORD   Flags;           
    DWORD   MetaDataSize;    
    DWORD   MetaDataOffset;  
} ANON_OBJECT_HEADER_V2;

typedef struct ANON_OBJECT_HEADER_BIGOBJ {
   
    WORD    Sig1;            
    WORD    Sig2;            
    WORD    Version;         
    WORD    Machine;         
    DWORD   TimeDateStamp;
    CLSID   ClassID;         
    DWORD   SizeOfData;      
    DWORD   Flags;           
    DWORD   MetaDataSize;    
    DWORD   MetaDataOffset;  

    
    DWORD   NumberOfSections; 
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
} ANON_OBJECT_HEADER_BIGOBJ;







typedef struct _IMAGE_SECTION_HEADER {
    BYTE    Name[8];
    union {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    NumberOfRelocations;
    WORD    NumberOfLinenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

































































#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"























#pragma warning(disable:4103)

#pragma pack(push,2)


#line 30 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"
#line 34 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack2.h"

#line 11308 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 11309 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef struct _IMAGE_SYMBOL {
    union {
        BYTE    ShortName[8];
        struct {
            DWORD   Short;     
            DWORD   Long;      
        } Name;
        DWORD   LongName[2];    
    } N;
    DWORD   Value;
    SHORT   SectionNumber;
    WORD    Type;
    BYTE    StorageClass;
    BYTE    NumberOfAuxSymbols;
} IMAGE_SYMBOL;
typedef IMAGE_SYMBOL  *PIMAGE_SYMBOL;



typedef struct _IMAGE_SYMBOL_EX {
    union {
        BYTE     ShortName[8];
        struct {
            DWORD   Short;     
            DWORD   Long;      
        } Name;
        DWORD   LongName[2];    
    } N;
    DWORD   Value;
    LONG    SectionNumber;
    WORD    Type;
    BYTE    StorageClass;
    BYTE    NumberOfAuxSymbols;
} IMAGE_SYMBOL_EX;
typedef IMAGE_SYMBOL_EX  *PIMAGE_SYMBOL_EX;
































































































#line 11446 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




#line 11451 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





#line 11457 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




#line 11462 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



#line 11466 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


#line 11469 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack2.h"























#pragma warning(disable:4103)

#pragma pack(push,2)


#line 30 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack2.h"


#line 33 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack2.h"
#line 34 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\pshpack2.h"

#line 11471 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct IMAGE_AUX_SYMBOL_TOKEN_DEF {
    BYTE  bAuxType;                  
    BYTE  bReserved;                 
    DWORD SymbolTableIndex;
    BYTE  rgbReserved[12];           
} IMAGE_AUX_SYMBOL_TOKEN_DEF;

typedef IMAGE_AUX_SYMBOL_TOKEN_DEF  *PIMAGE_AUX_SYMBOL_TOKEN_DEF;

#line 1 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"


#line 36 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"
#line 37 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\poppack.h"

#line 11482 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef union _IMAGE_AUX_SYMBOL {
    struct {
        DWORD    TagIndex;                      
        union {
            struct {
                WORD    Linenumber;             
                WORD    Size;                   
            } LnSz;
           DWORD    TotalSize;
        } Misc;
        union {
            struct {                            
                DWORD    PointerToLinenumber;
                DWORD    PointerToNextFunction;
            } Function;
            struct {                            
                WORD     Dimension[4];
            } Array;
        } FcnAry;
        WORD    TvIndex;                        
    } Sym;
    struct {
        BYTE    Name[18];
    } File;
    struct {
        DWORD   Length;                         
        WORD    NumberOfRelocations;            
        WORD    NumberOfLinenumbers;            
        DWORD   CheckSum;                       
        SHORT   Number;                         
        BYTE    Selection;                      
	BYTE    bReserved;
	SHORT   HighNumber;                     
    } Section;
    IMAGE_AUX_SYMBOL_TOKEN_DEF TokenDef;   
    struct {
        DWORD crc;
        BYTE  rgbReserved[14];
    } CRC;
} IMAGE_AUX_SYMBOL;
typedef IMAGE_AUX_SYMBOL  *PIMAGE_AUX_SYMBOL;

typedef union _IMAGE_AUX_SYMBOL_EX {
    struct {
        DWORD   WeakDefaultSymIndex;                       
        DWORD   WeakSearchType;
        BYTE    rgbReserved[12];
    } Sym;
    struct {
        BYTE    Name[sizeof(IMAGE_SYMBOL_EX)];
    } File;
    struct {
        DWORD   Length;                         
        WORD    NumberOfRelocations;            
        WORD    NumberOfLinenumbers;            
        DWORD   CheckSum;                       
        SHORT   Number;                         
        BYTE    Selection;                      
        BYTE    bReserved;
        SHORT   HighNumber;                     
        BYTE    rgbReserved[2];
    } Section;
    struct{ 
        IMAGE_AUX_SYMBOL_TOKEN_DEF TokenDef;   
        BYTE  rgbReserved[2];
    };
    struct {
        DWORD crc;
        BYTE  rgbReserved[16];
    } CRC;
} IMAGE_AUX_SYMBOL_EX;
typedef IMAGE_AUX_SYMBOL_EX  *PIMAGE_AUX_SYMBOL_EX;

typedef enum IMAGE_AUX_SYMBOL_TYPE {
    IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF = 1,
} IMAGE_AUX_SYMBOL_TYPE;






















typedef struct _IMAGE_RELOCATION {
    union {
        DWORD   VirtualAddress;
        DWORD   RelocCount;             
    } ;
    DWORD   SymbolTableIndex;
    WORD    Type;
} IMAGE_RELOCATION;
typedef IMAGE_RELOCATION  *PIMAGE_RELOCATION;




























































































































                                                
                                                
                                                
                                                










































































































































































































































typedef struct _IMAGE_LINENUMBER {
    union {
        DWORD   SymbolTableIndex;               
        DWORD   VirtualAddress;                 
    } Type;
    WORD    Linenumber;                         
} IMAGE_LINENUMBER;
typedef IMAGE_LINENUMBER  *PIMAGE_LINENUMBER;


#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


#line 36 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"
#line 37 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"

#line 11967 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
#line 11968 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef struct _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;

} IMAGE_BASE_RELOCATION;
typedef IMAGE_BASE_RELOCATION  * PIMAGE_BASE_RELOCATION;



























typedef struct _IMAGE_ARCHIVE_MEMBER_HEADER {
    BYTE     Name[16];                          
    BYTE     Date[12];                          
    BYTE     UserID[6];                         
    BYTE     GroupID[6];                        
    BYTE     Mode[8];                           
    BYTE     Size[10];                          
    BYTE     EndHeader[2];                      
} IMAGE_ARCHIVE_MEMBER_HEADER, *PIMAGE_ARCHIVE_MEMBER_HEADER;











typedef struct _IMAGE_EXPORT_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   Name;
    DWORD   Base;
    DWORD   NumberOfFunctions;
    DWORD   NumberOfNames;
    DWORD   AddressOfFunctions;     
    DWORD   AddressOfNames;         
    DWORD   AddressOfNameOrdinals;  
} IMAGE_EXPORT_DIRECTORY, *PIMAGE_EXPORT_DIRECTORY;





typedef struct _IMAGE_IMPORT_BY_NAME {
    WORD    Hint;
    BYTE    Name[1];
} IMAGE_IMPORT_BY_NAME, *PIMAGE_IMPORT_BY_NAME;

#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack8.h"























#pragma warning(disable:4103)

#pragma pack(push,8)


#line 30 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack8.h"


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack8.h"
#line 34 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\pshpack8.h"

#line 12050 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _IMAGE_THUNK_DATA64 {
    union {
        ULONGLONG ForwarderString;  
        ULONGLONG Function;         
        ULONGLONG Ordinal;
        ULONGLONG AddressOfData;    
    } u1;
} IMAGE_THUNK_DATA64;
typedef IMAGE_THUNK_DATA64 * PIMAGE_THUNK_DATA64;

#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


#line 36 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"
#line 37 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"

#line 12062 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _IMAGE_THUNK_DATA32 {
    union {
        DWORD ForwarderString;      
        DWORD Function;             
        DWORD Ordinal;
        DWORD AddressOfData;        
    } u1;
} IMAGE_THUNK_DATA32;
typedef IMAGE_THUNK_DATA32 * PIMAGE_THUNK_DATA32;












typedef void
(__stdcall *PIMAGE_TLS_CALLBACK) (
    PVOID DllHandle,
    DWORD Reason,
    PVOID Reserved
    );

typedef struct _IMAGE_TLS_DIRECTORY64 {
    ULONGLONG   StartAddressOfRawData;
    ULONGLONG   EndAddressOfRawData;
    ULONGLONG   AddressOfIndex;         
    ULONGLONG   AddressOfCallBacks;     
    DWORD   SizeOfZeroFill;
    DWORD   Characteristics;
} IMAGE_TLS_DIRECTORY64;
typedef IMAGE_TLS_DIRECTORY64 * PIMAGE_TLS_DIRECTORY64;

typedef struct _IMAGE_TLS_DIRECTORY32 {
    DWORD   StartAddressOfRawData;
    DWORD   EndAddressOfRawData;
    DWORD   AddressOfIndex;             
    DWORD   AddressOfCallBacks;         
    DWORD   SizeOfZeroFill;
    DWORD   Characteristics;
} IMAGE_TLS_DIRECTORY32;
typedef IMAGE_TLS_DIRECTORY32 * PIMAGE_TLS_DIRECTORY32;












typedef IMAGE_THUNK_DATA32              IMAGE_THUNK_DATA;
typedef PIMAGE_THUNK_DATA32             PIMAGE_THUNK_DATA;

typedef IMAGE_TLS_DIRECTORY32           IMAGE_TLS_DIRECTORY;
typedef PIMAGE_TLS_DIRECTORY32          PIMAGE_TLS_DIRECTORY;
#line 12128 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _IMAGE_IMPORT_DESCRIPTOR {
    union {
        DWORD   Characteristics;            
        DWORD   OriginalFirstThunk;         
    } ;
    DWORD   TimeDateStamp;                  
                                            
                                            
                                            

    DWORD   ForwarderChain;                 
    DWORD   Name;
    DWORD   FirstThunk;                     
} IMAGE_IMPORT_DESCRIPTOR;
typedef IMAGE_IMPORT_DESCRIPTOR  *PIMAGE_IMPORT_DESCRIPTOR;





typedef struct _IMAGE_BOUND_IMPORT_DESCRIPTOR {
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    NumberOfModuleForwarderRefs;

} IMAGE_BOUND_IMPORT_DESCRIPTOR,  *PIMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef struct _IMAGE_BOUND_FORWARDER_REF {
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    Reserved;
} IMAGE_BOUND_FORWARDER_REF, *PIMAGE_BOUND_FORWARDER_REF;



















typedef struct _IMAGE_RESOURCE_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    WORD    NumberOfNamedEntries;
    WORD    NumberOfIdEntries;

} IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;


















typedef struct _IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union {
        struct {
            DWORD NameOffset:31;
            DWORD NameIsString:1;
        } ;
        DWORD   Name;
        WORD    Id;
    } ;
    union {
        DWORD   OffsetToData;
        struct {
            DWORD   OffsetToDirectory:31;
            DWORD   DataIsDirectory:1;
        } ;
    } ;
} IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;










typedef struct _IMAGE_RESOURCE_DIRECTORY_STRING {
    WORD    Length;
    CHAR    NameString[ 1 ];
} IMAGE_RESOURCE_DIRECTORY_STRING, *PIMAGE_RESOURCE_DIRECTORY_STRING;


typedef struct _IMAGE_RESOURCE_DIR_STRING_U {
    WORD    Length;
    WCHAR   NameString[ 1 ];
} IMAGE_RESOURCE_DIR_STRING_U, *PIMAGE_RESOURCE_DIR_STRING_U;











typedef struct _IMAGE_RESOURCE_DATA_ENTRY {
    DWORD   OffsetToData;
    DWORD   Size;
    DWORD   CodePage;
    DWORD   Reserved;
} IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;





typedef struct {
    DWORD   Size;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   GlobalFlagsClear;
    DWORD   GlobalFlagsSet;
    DWORD   CriticalSectionDefaultTimeout;
    DWORD   DeCommitFreeBlockThreshold;
    DWORD   DeCommitTotalFreeThreshold;
    DWORD   LockPrefixTable;            
    DWORD   MaximumAllocationSize;
    DWORD   VirtualMemoryThreshold;
    DWORD   ProcessHeapFlags;
    DWORD   ProcessAffinityMask;
    WORD    CSDVersion;
    WORD    Reserved1;
    DWORD   EditList;                   
    DWORD   SecurityCookie;             
    DWORD   SEHandlerTable;             
    DWORD   SEHandlerCount;
} IMAGE_LOAD_CONFIG_DIRECTORY32, *PIMAGE_LOAD_CONFIG_DIRECTORY32;

typedef struct {
    DWORD      Size;
    DWORD      TimeDateStamp;
    WORD       MajorVersion;
    WORD       MinorVersion;
    DWORD      GlobalFlagsClear;
    DWORD      GlobalFlagsSet;
    DWORD      CriticalSectionDefaultTimeout;
    ULONGLONG  DeCommitFreeBlockThreshold;
    ULONGLONG  DeCommitTotalFreeThreshold;
    ULONGLONG  LockPrefixTable;         
    ULONGLONG  MaximumAllocationSize;
    ULONGLONG  VirtualMemoryThreshold;
    ULONGLONG  ProcessAffinityMask;
    DWORD      ProcessHeapFlags;
    WORD       CSDVersion;
    WORD       Reserved1;
    ULONGLONG  EditList;                
    ULONGLONG  SecurityCookie;          
    ULONGLONG  SEHandlerTable;          
    ULONGLONG  SEHandlerCount;
} IMAGE_LOAD_CONFIG_DIRECTORY64, *PIMAGE_LOAD_CONFIG_DIRECTORY64;





typedef IMAGE_LOAD_CONFIG_DIRECTORY32     IMAGE_LOAD_CONFIG_DIRECTORY;
typedef PIMAGE_LOAD_CONFIG_DIRECTORY32    PIMAGE_LOAD_CONFIG_DIRECTORY;
#line 12319 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"










typedef struct _IMAGE_CE_RUNTIME_FUNCTION_ENTRY {
    DWORD FuncStart;
    DWORD PrologLen : 8;
    DWORD FuncLen : 22;
    DWORD ThirtyTwoBit : 1;
    DWORD ExceptionFlag : 1;
} IMAGE_CE_RUNTIME_FUNCTION_ENTRY, * PIMAGE_CE_RUNTIME_FUNCTION_ENTRY;

typedef struct _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY {
    ULONGLONG BeginAddress;
    ULONGLONG EndAddress;
    ULONGLONG ExceptionHandler;
    ULONGLONG HandlerData;
    ULONGLONG PrologEndAddress;
} IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY, *PIMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;

typedef struct _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD ExceptionHandler;
    DWORD HandlerData;
    DWORD PrologEndAddress;
} IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY, *PIMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;

typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD UnwindInfoAddress;
} _IMAGE_RUNTIME_FUNCTION_ENTRY, *_PIMAGE_RUNTIME_FUNCTION_ENTRY;

typedef  _IMAGE_RUNTIME_FUNCTION_ENTRY  IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
typedef _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_IA64_RUNTIME_FUNCTION_ENTRY;








#line 12370 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




#line 12375 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef  _IMAGE_RUNTIME_FUNCTION_ENTRY  IMAGE_RUNTIME_FUNCTION_ENTRY;
typedef _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_RUNTIME_FUNCTION_ENTRY;

#line 12380 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef struct _IMAGE_DEBUG_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   Type;
    DWORD   SizeOfData;
    DWORD   AddressOfRawData;
    DWORD   PointerToRawData;
} IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;















typedef struct _IMAGE_COFF_SYMBOLS_HEADER {
    DWORD   NumberOfSymbols;
    DWORD   LvaToFirstSymbol;
    DWORD   NumberOfLinenumbers;
    DWORD   LvaToFirstLinenumber;
    DWORD   RvaToFirstByteOfCode;
    DWORD   RvaToLastByteOfCode;
    DWORD   RvaToFirstByteOfData;
    DWORD   RvaToLastByteOfData;
} IMAGE_COFF_SYMBOLS_HEADER, *PIMAGE_COFF_SYMBOLS_HEADER;






typedef struct _FPO_DATA {
    DWORD       ulOffStart;             
    DWORD       cbProcSize;             
    DWORD       cdwLocals;              
    WORD        cdwParams;              
    WORD        cbProlog : 8;           
    WORD        cbRegs   : 3;           
    WORD        fHasSEH  : 1;           
    WORD        fUseBP   : 1;           
    WORD        reserved : 1;           
    WORD        cbFrame  : 2;           
} FPO_DATA, *PFPO_DATA;





typedef struct _IMAGE_DEBUG_MISC {
    DWORD       DataType;               
    DWORD       Length;                 
                                        
    BOOLEAN     Unicode;                
    BYTE        Reserved[ 3 ];
    BYTE        Data[ 1 ];              
} IMAGE_DEBUG_MISC, *PIMAGE_DEBUG_MISC;








typedef struct _IMAGE_FUNCTION_ENTRY {
    DWORD   StartingAddress;
    DWORD   EndingAddress;
    DWORD   EndOfPrologue;
} IMAGE_FUNCTION_ENTRY, *PIMAGE_FUNCTION_ENTRY;

typedef struct _IMAGE_FUNCTION_ENTRY64 {
    ULONGLONG   StartingAddress;
    ULONGLONG   EndingAddress;
    union {
        ULONGLONG   EndOfPrologue;
        ULONGLONG   UnwindInfoAddress;
    } ;
} IMAGE_FUNCTION_ENTRY64, *PIMAGE_FUNCTION_ENTRY64;





















typedef struct _IMAGE_SEPARATE_DEBUG_HEADER {
    WORD        Signature;
    WORD        Flags;
    WORD        Machine;
    WORD        Characteristics;
    DWORD       TimeDateStamp;
    DWORD       CheckSum;
    DWORD       ImageBase;
    DWORD       SizeOfImage;
    DWORD       NumberOfSections;
    DWORD       ExportedNamesSize;
    DWORD       DebugDirectorySize;
    DWORD       SectionAlignment;
    DWORD       Reserved[2];
} IMAGE_SEPARATE_DEBUG_HEADER, *PIMAGE_SEPARATE_DEBUG_HEADER;

typedef struct _NON_PAGED_DEBUG_INFO {
    WORD        Signature;
    WORD        Flags;
    DWORD       Size;
    WORD        Machine;
    WORD        Characteristics;
    DWORD       TimeDateStamp;
    DWORD       CheckSum;
    DWORD       SizeOfImage;
    ULONGLONG   ImageBase;
    
    
} NON_PAGED_DEBUG_INFO, *PNON_PAGED_DEBUG_INFO;







#line 12531 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



                                                









typedef struct _ImageArchitectureHeader {
    unsigned int AmaskValue: 1;                 
                                                
    int :7;                                     
    unsigned int AmaskShift: 8;                 
    int :16;                                    
    DWORD FirstEntryRVA;                        
} IMAGE_ARCHITECTURE_HEADER, *PIMAGE_ARCHITECTURE_HEADER;

typedef struct _ImageArchitectureEntry {
    DWORD FixupInstRVA;                         
    DWORD NewInst;                              
} IMAGE_ARCHITECTURE_ENTRY, *PIMAGE_ARCHITECTURE_ENTRY;

#line 1 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


























#pragma warning(disable:4103)

#pragma pack(pop)


#line 33 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"


#line 36 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"
#line 37 "c:\\program files\\microsoft sdks\\windows\\v7.0a\\include\\poppack.h"

#line 12559 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"








typedef struct IMPORT_OBJECT_HEADER {
    WORD    Sig1;                       
    WORD    Sig2;                       
    WORD    Version;
    WORD    Machine;
    DWORD   TimeDateStamp;              
    DWORD   SizeOfData;                 

    union {
        WORD    Ordinal;                
        WORD    Hint;
    } ;

    WORD    Type : 2;                   
    WORD    NameType : 3;               
    WORD    Reserved : 11;              
} IMPORT_OBJECT_HEADER;

typedef enum IMPORT_OBJECT_TYPE
{
    IMPORT_OBJECT_CODE = 0,
    IMPORT_OBJECT_DATA = 1,
    IMPORT_OBJECT_CONST = 2,
} IMPORT_OBJECT_TYPE;

typedef enum IMPORT_OBJECT_NAME_TYPE
{
    IMPORT_OBJECT_ORDINAL = 0,          
    IMPORT_OBJECT_NAME = 1,             
    IMPORT_OBJECT_NAME_NO_PREFIX = 2,   
    IMPORT_OBJECT_NAME_UNDECORATE = 3,  
                                        
} IMPORT_OBJECT_NAME_TYPE;





typedef enum ReplacesCorHdrNumericDefines
{

    COMIMAGE_FLAGS_ILONLY               =0x00000001,
    COMIMAGE_FLAGS_32BITREQUIRED        =0x00000002,
    COMIMAGE_FLAGS_IL_LIBRARY           =0x00000004,
    COMIMAGE_FLAGS_STRONGNAMESIGNED     =0x00000008,
    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT    =0x00000010,
    COMIMAGE_FLAGS_TRACKDEBUGDATA       =0x00010000,


    COR_VERSION_MAJOR_V2                =2,
    COR_VERSION_MAJOR                   =COR_VERSION_MAJOR_V2,
    COR_VERSION_MINOR                   =0,
    COR_DELETED_NAME_LENGTH             =8,
    COR_VTABLEGAP_NAME_LENGTH           =8,


    NATIVE_TYPE_MAX_CB                  =1,
    COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,


    IMAGE_COR_MIH_METHODRVA             =0x01,
    IMAGE_COR_MIH_EHRVA                 =0x02,
    IMAGE_COR_MIH_BASICBLOCK            =0x08,


    COR_VTABLE_32BIT                    =0x01,          
    COR_VTABLE_64BIT                    =0x02,          
    COR_VTABLE_FROM_UNMANAGED           =0x04,          
    COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN  =0x08,  
    COR_VTABLE_CALL_MOST_DERIVED        =0x10,          


    IMAGE_COR_EATJ_THUNK_SIZE           =32,            


    
    MAX_CLASS_NAME                      =1024,
    MAX_PACKAGE_NAME                    =1024,
} ReplacesCorHdrNumericDefines;


typedef struct IMAGE_COR20_HEADER
{
    
    DWORD                   cb;
    WORD                    MajorRuntimeVersion;
    WORD                    MinorRuntimeVersion;

    
    IMAGE_DATA_DIRECTORY    MetaData;
    DWORD                   Flags;

    
    
    union {
        DWORD               EntryPointToken;
        DWORD               EntryPointRVA;
    } ;

    
    IMAGE_DATA_DIRECTORY    Resources;
    IMAGE_DATA_DIRECTORY    StrongNameSignature;

    
    IMAGE_DATA_DIRECTORY    CodeManagerTable;
    IMAGE_DATA_DIRECTORY    VTableFixups;
    IMAGE_DATA_DIRECTORY    ExportAddressTableJumps;

    
    IMAGE_DATA_DIRECTORY    ManagedNativeHeader;

} IMAGE_COR20_HEADER, *PIMAGE_COR20_HEADER;

#line 12681 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"














#line 12696 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"




























#line 12725 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





typedef SINGLE_LIST_ENTRY SLIST_ENTRY32, *PSLIST_ENTRY32;

#line 12733 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"











































#line 12777 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef union _SLIST_HEADER {
    ULONGLONG Alignment;
    struct {
        SINGLE_LIST_ENTRY Next;
        WORD   Depth;
        WORD   Sequence;
    } ;
} SLIST_HEADER, *PSLIST_HEADER;

typedef SLIST_HEADER SLIST_HEADER32, *PSLIST_HEADER32;

#line 12790 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

#line 12792 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


__declspec(dllimport)
void
__stdcall
RtlInitializeSListHead (
     PSLIST_HEADER ListHead
    );


__declspec(dllimport)
PSINGLE_LIST_ENTRY
__stdcall
RtlFirstEntrySList (
     const SLIST_HEADER *ListHead
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY
__stdcall
RtlInterlockedPopEntrySList (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY
__stdcall
RtlInterlockedPushEntrySList (
     PSLIST_HEADER ListHead,
       PSINGLE_LIST_ENTRY ListEntry
    );

__declspec(dllimport)
PSINGLE_LIST_ENTRY
__stdcall
RtlInterlockedFlushSList (
     PSLIST_HEADER ListHead
    );

__declspec(dllimport)
WORD  
__stdcall
RtlQueryDepthSList (
     PSLIST_HEADER ListHead
    );










#line 12848 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



























typedef union _RTL_RUN_ONCE {       
    PVOID Ptr;                      
} RTL_RUN_ONCE, *PRTL_RUN_ONCE;     

typedef
 
 
DWORD 
__stdcall
RTL_RUN_ONCE_INIT_FN (
     PRTL_RUN_ONCE RunOnce,
     PVOID Parameter,
     PVOID *Context
    );
typedef RTL_RUN_ONCE_INIT_FN *PRTL_RUN_ONCE_INIT_FN;

#line 12892 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



 
__declspec(dllimport)
void
__stdcall
RtlRunOnceInitialize (
     PRTL_RUN_ONCE RunOnce
    );

 
 
__declspec(dllimport)
DWORD   
__stdcall
RtlRunOnceExecuteOnce (
     PRTL_RUN_ONCE RunOnce,
      PRTL_RUN_ONCE_INIT_FN InitFn,
     PVOID Parameter,
     PVOID *Context
    );

 

__declspec(dllimport)
DWORD   
__stdcall
RtlRunOnceBeginInitialize (
     PRTL_RUN_ONCE RunOnce,
     DWORD Flags,
     PVOID *Context
    );

 
__declspec(dllimport)
DWORD   
__stdcall
RtlRunOnceComplete (
     PRTL_RUN_ONCE RunOnce,
     DWORD Flags,
     PVOID Context
    );

#line 12937 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"
















__forceinline
DWORD
HEAP_MAKE_TAG_FLAGS (
     DWORD TagBase,
     DWORD Tag
    )

{
    __pragma(warning(push)) __pragma(warning(disable : 4548)) do {__noop(TagBase);} while((0,0) __pragma(warning(pop)) );
    return ((DWORD)((TagBase) + ((Tag) << 18)));
}
#line 12965 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


__declspec(dllimport)
WORD  
__stdcall
RtlCaptureStackBackTrace(
     DWORD FramesToSkip,
     DWORD FramesToCapture,
     PVOID *BackTrace,
     PDWORD BackTraceHash
   );
#line 12977 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"


__declspec(dllimport)
void
__stdcall
RtlCaptureContext (
     PCONTEXT ContextRecord
    );
#line 12986 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





















































#line 13040 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



__declspec(dllimport)
SIZE_T
__stdcall
RtlCompareMemory (
     const void *Source1,
     const void *Source2,
     SIZE_T Length
    );

#line 13053 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"










__forceinline
PVOID
RtlSecureZeroMemory(
     PVOID ptr,
     SIZE_T cnt
    )
{
    volatile char *vptr = (volatile char *)ptr;





#line 13077 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

    while (cnt) {
        *vptr = 0;
        vptr++;
        cnt--;
    }

#line 13085 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

    return ptr;
}

#line 13090 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



















typedef struct _MESSAGE_RESOURCE_ENTRY {
    WORD   Length;
    WORD   Flags;
    BYTE  Text[ 1 ];
} MESSAGE_RESOURCE_ENTRY, *PMESSAGE_RESOURCE_ENTRY;



typedef struct _MESSAGE_RESOURCE_BLOCK {
    DWORD LowId;
    DWORD HighId;
    DWORD OffsetToEntries;
} MESSAGE_RESOURCE_BLOCK, *PMESSAGE_RESOURCE_BLOCK;

typedef struct _MESSAGE_RESOURCE_DATA {
    DWORD NumberOfBlocks;
    MESSAGE_RESOURCE_BLOCK Blocks[ 1 ];
} MESSAGE_RESOURCE_DATA, *PMESSAGE_RESOURCE_DATA;


__declspec(dllimport)
PVOID
__stdcall
RtlPcToFileHeader(
     PVOID PcValue,
     PVOID *BaseOfImage
    );

typedef struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR   szCSDVersion[ 128 ];     
} OSVERSIONINFOA, *POSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct _OSVERSIONINFOW {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    WCHAR  szCSDVersion[ 128 ];     
} OSVERSIONINFOW, *POSVERSIONINFOW, *LPOSVERSIONINFOW, RTL_OSVERSIONINFOW, *PRTL_OSVERSIONINFOW;





typedef OSVERSIONINFOA OSVERSIONINFO;
typedef POSVERSIONINFOA POSVERSIONINFO;
typedef LPOSVERSIONINFOA LPOSVERSIONINFO;
#line 13163 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"

typedef struct _OSVERSIONINFOEXA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR   szCSDVersion[ 128 ];     
    WORD   wServicePackMajor;
    WORD   wServicePackMinor;
    WORD   wSuiteMask;
    BYTE  wProductType;
    BYTE  wReserved;
} OSVERSIONINFOEXA, *POSVERSIONINFOEXA, *LPOSVERSIONINFOEXA;
typedef struct _OSVERSIONINFOEXW {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    WCHAR  szCSDVersion[ 128 ];     
    WORD   wServicePackMajor;
    WORD   wServicePackMinor;
    WORD   wSuiteMask;
    BYTE  wProductType;
    BYTE  wReserved;
} OSVERSIONINFOEXW, *POSVERSIONINFOEXW, *LPOSVERSIONINFOEXW, RTL_OSVERSIONINFOEXW, *PRTL_OSVERSIONINFOEXW;





typedef OSVERSIONINFOEXA OSVERSIONINFOEX;
typedef POSVERSIONINFOEXA POSVERSIONINFOEX;
typedef LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#line 13199 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



























































__declspec(dllimport)
ULONGLONG
__stdcall
VerSetConditionMask(
     ULONGLONG ConditionMask,
     DWORD TypeMask,
     BYTE  Condition
    );
#line 13267 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"





__declspec(dllimport)
BOOLEAN
__stdcall
RtlGetProductInfo(
      DWORD  OSMajorVersion,
      DWORD  OSMinorVersion,
      DWORD  SpMajorVersion,
      DWORD  SpMinorVersion,
     PDWORD ReturnedProductType
    );

#line 13284 "C:\\Program Files\\Microsoft SDKs\\Windows\\v7.0A\\include\\winnt.h"



typedef enum _RTL_UMS_THREAD_INFO_CLASS {
    UmsThreadInvalidInfoClass = 0,
    UmsThreadUserContext,
    UmsThreadPriority,
    UmsThreadAffinity,
    UmsThreadTeb,
    UmsThreadIsSuspended,
    UmsThreadIsTerminated,
    UmsThreadMaxInfoClass
} RTL_UMS_THREAD_INFO_CLASS, *PRTL_UMS_THREAD_INFO_CLASS;

typedef enum _RTL_UMS_SCHEDULER_REASON {
    UmsSchedulerStartup = 0,
    UmsSchedulerThreadBlocked,
    UmsSchedulerThreadYield,
} RTL_UMS_SCHEDULER_REASON, *PRTL_UMS_SCHEDULER_REASON;

typedef
 
void
__stdcall
RTL_UMS_SCHEDULER_ENTRY_POINT(
     RTL_UMS_SCHEDULER_REASON Reason,
     ULONG_PTR ActivationPayload,
     PVOID SchedulerParam
    );

typedef RTL_UMS_SCHEDULER_ENTRY_POINT *PRTL_UMS_SCHEDULER_ENTRY_POINT;





__declspec(dllimport)
DWORD   
__stdcall
RtlCopyExtendedContext (
     PCONTEXT_EX Destination,
     DWORD ContextFlags,
     PCONTEXT_EX Source
    );

__declspec(dllimport)
DWORD   
__stdcall
RtlInitializeExtendedContext (
     PVOID Context,
     DWORD ContextFlags,
     PCONTEXT_EX* ContextEx
    );

__declspec(dllimport)
DWORD64
__stdcall
RtlGetEnabledExtendedFeatures (
     DWORD64 FeatureMask
    );


__declspec(dllimport)
DWORD   
__stdcall
RtlGetExtendedContextLength (
     DWORD ContextFlags,
     PDWORD ContextLength
    );

__declspec(dllimport)
DWORD64
__stdcall
RtlGetExtendedFeaturesMask (
     PCONTEXT_EX ContextEx
    );

__declspec(dllimport)
PVOID
__stdcall
RtlLocateExtendedFeature (
     PDWORD Length