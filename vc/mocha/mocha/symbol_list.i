#line 1 "..\\..\\..\\src\\mocha\\roaster\\tokens\\symbol_list.cc"
#line 1 "Y:\\mocha\\src\\mocha/roaster/tokens/symbol_list.h"


#line 1 "Y:\\mocha\\src\\mocha/roaster/misc/class_traits/static.h"




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstddef"

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






#line 6 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstddef"







 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"














#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"


extern "C" {
#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"







#line 33 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"
#line 34 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"




namespace std { typedef decltype(__nullptr) nullptr_t; }
using ::std::nullptr_t;
#line 41 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"
#line 42 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"





 extern int * __cdecl _errno(void);


errno_t __cdecl _set_errno(  int _Value);
errno_t __cdecl _get_errno(  int * _Value);
#line 53 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stddef.h"








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





#line 6 "Y:\\mocha\\src\\mocha/roaster/misc/class_traits/static.h"

namespace mocha {

  class Static{
    inline Static (){};
    inline Static (const Static&){};
    inline void operator = (const Static&){};
    inline void operator delete [] (void*) {};
  };
  
}

#line 19 "Y:\\mocha\\src\\mocha/roaster/misc/class_traits/static.h"

#line 4 "Y:\\mocha\\src\\mocha/roaster/tokens/symbol_list.h"
namespace mocha {

class SymbolList : private Static {
 public :
  typedef enum {
    kGlobalExport,
    kGlobalAlias,
    kLocalExport,
    kLocalTmp,
    kPrivateHolder,
    kToArray,
    kRuntime,
    kCreateUnenumProp,
    kTypeId,
    kConstant,
    kPrivateField,
    kExtendClass,
    kExtendPrototype,
    kScopeModule,
    kFile,
    kLine,
    kYieldState,
    kYieldNext,
    kYieldSend,
    kExceptionHandler,
    kYieldResult,
    kYieldSendFlag,
    kYieldSafeFlag,
    kGenerator,
    kIsNewBorn,
    kStopIteration,
    kThrowException,
    kClose,
    kFinallyCache,
    kCatchCache,
    kException,
    kCreateGenerator,
    kNoThrow,
    kExtend,
    kAssert,
    kIteratorKey,
    kThrowStopIteration,
    kHasIterator,
    kGetIterator,
    kTypeid,
    kGetUid,
    kCreatePrivateRecord,
    kGetPrivateRecord,
    kSuper,
    kGetSuper,
    kClassMark,
    kTraitPrivate,
    kTraitPublic,
    kTraitMark,
    kMixin,
    kRequires,
    kClassMixin,
    kCheckRequirements,
    kCreateTuple,
    kCreateRecord,
    kInitializeClass
  } RuntimeSymbol;

  typedef enum {
    kArguments,
    kUndefined,
    kConstructor,
    kThis,
    kApply,
    kCall,
    kPrototype,
    kLength,
    kTrue,
    kFalse,
    kBind,
    kPush,
    kTrait,
    kFrom,
    kOf,
    kNaN,
    kFunctionConstructor,
    kArrayConstructor,
    kObjectConstructor,
    kStringConstructor,
    kNumberConstructor
  } BuiltinSymbol;
  
  static const char* symbol(RuntimeSymbol runtime_symbol);
  static const char* symbol(BuiltinSymbol builtin_symbol);
};

}

#line 98 "Y:\\mocha\\src\\mocha/roaster/tokens/symbol_list.h"
#line 2 "..\\..\\..\\src\\mocha\\roaster\\tokens\\symbol_list.cc"

namespace mocha {

static const char runtime[][50] = {
  "_mochaGlobalExport",
  "_mochaGlobalAlias",
  "_mochaLocalExport",
  "_mochaLocalTmp",
  "_mochaPrivateHolder",
  "toArray",
  "Runtime",
  "createUnenumProp",
  "__typeid__",
  "constant",
  "__private__",
  "extendClass",
  "extendPrototype",
  "__MODULE__",
  "__FILE__",
  "__LINE__",
  "_yieldState",
  "next",
  "send",
  "exceptionHandler",
  "_yieldResult",
  "_isYieldSend",
  "_isYieldSafe",
  "_mochaGenerator",
  "_mochaIsNewBorn",
  "StopIteration",
  "throwException",
  "close",
  "_mochaFinallyCache",
  "_mochaCatchCache",
  "_mochaException",
  "createGenerator",
  "__nothrowNext__",
  "extend",
  "assert",
  "__ref_iterator__",
  "throwStopIteration",
  "hasIterator",
  "getIterator",
  "__typeid__",
  "getUid",
  "createPrivateRecord",
  "getPrivateRecord",
  "_mochaSuper",
  "getSuper",
  "__harmony_class__",
  "_mochaTraitPrivate",
  "_mochaTraitPublic",
  "_mochaTraitMark",
  "traitMixin",
  "_mochaRequires",
  "classMixin",
  "checkRequirements",
  "createTuple",
  "createRecord",
  "initializeClass"
};

static const char builtin[][50] = {
  "arguments",
  "undefined",
  "constructor",
  "this",
  "apply",
  "call",
  "prototype",
  "length",
  "true",
  "false",
  "bind",
  "push",
  "trait",
  "from",
  "of",
  "NaN",
  "Function",
  "Array",
  "Object",
  "String",
  "Number"
};


const char* SymbolList::symbol(RuntimeSymbol runtime_symbol) {
  return runtime[ runtime_symbol ];
}
const char* SymbolList::symbol(BuiltinSymbol builtin_symbol) {
  return builtin[ builtin_symbol ];
}

}