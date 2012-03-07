#line 1 "..\\..\\..\\src\\mocha\\misc\\char_allocator.cc"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"














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

#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"


extern "C" {
#line 25 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"




#line 30 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"







#line 38 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"
#line 39 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string.h"







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
#line 2 "..\\..\\..\\src\\mocha\\misc\\char_allocator.cc"
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

#line 3 "..\\..\\..\\src\\mocha\\misc\\char_allocator.cc"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\climits"

#pragma once


#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\yvals.h"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































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






#line 6 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\climits"


#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\climits"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"
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

  double __cdecl _copysign (  double _Number,   double _Sign);
  double __cdecl _chgsign (  double _X);

#line 115 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\math.h"
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





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"
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





#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cstdlib"

#pragma once










 
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





#line 10 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\streambuf"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

#pragma once




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





#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"

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





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xstring"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xmemory"

#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\new"

#pragma once





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





#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\utility"

#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\iosfwd"

#pragma once





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






#line 8 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\stdexcept"

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





#line 9 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
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







#line 10 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"

#pragma once


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
#line 6 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\locale.h"













#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 20 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\locale.h"





#pragma pack(push,8)


extern "C" {
#line 30 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\locale.h"

























struct lconv {
        char *decimal_point;
        char *thousands_sep;
        char *grouping;
        char *int_curr_symbol;
        char *currency_symbol;
        char *mon_decimal_point;
        char *mon_thousands_sep;
        char *mon_grouping;
        char *positive_sign;
        char *negative_sign;
        char int_frac_digits;
        char frac_digits;
        char p_cs_precedes;
        char p_sep_by_space;
        char n_cs_precedes;
        char n_sep_by_space;
        char p_sign_posn;
        char n_sign_posn;
        wchar_t *_W_decimal_point;
        wchar_t *_W_thousands_sep;
        wchar_t *_W_int_curr_symbol;
        wchar_t *_W_currency_symbol;
        wchar_t *_W_mon_decimal_point;
        wchar_t *_W_mon_thousands_sep;
        wchar_t *_W_positive_sign;
        wchar_t *_W_negative_sign;
        };

#line 85 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\locale.h"




















#line 106 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\locale.h"

  int __cdecl _configthreadlocale(  int _Flag);
  char * __cdecl setlocale(  int _Category,    const char * _Locale);
  struct lconv * __cdecl localeconv(void);
  _locale_t __cdecl _get_current_locale(void);
  _locale_t __cdecl _create_locale(  int _Category,    const char * _Locale);
 void __cdecl _free_locale(   _locale_t _Locale);


 __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "_get_current_locale" " instead. See online help for details."))  _locale_t __cdecl __get_current_locale(void);
 __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "_create_locale" " instead. See online help for details."))  _locale_t __cdecl __create_locale(  int _Category,    const char * _Locale);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "_free_locale" " instead. See online help for details."))  void __cdecl __free_locale(   _locale_t _Locale);











}
#line 131 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\locale.h"

#pragma pack(pop)

#line 135 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\locale.h"
#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"





#pragma pack(push,8)



extern "C" {
#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"

		











		



















typedef struct _Collvec
	{	
	unsigned long _Hand;	
	unsigned int _Page;		
	} _Collvec;

typedef struct _Ctypevec
	{	
	unsigned long _Hand;	
	unsigned int _Page;		
	const short *_Table;
	int _Delfl;
	} _Ctypevec;

typedef struct _Cvtvec
	{	
	unsigned long _Hand;	
	unsigned int _Page;		
	} _Cvtvec;

		
 _Collvec __cdecl _Getcoll();
 _Ctypevec __cdecl _Getctype();

 _Cvtvec __cdecl _Getcvt();

 int __cdecl _Getdateorder();





 int __cdecl _Mbrtowc(  wchar_t *, const char *, size_t, mbstate_t *, const _Cvtvec *);
#line 85 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"

 float __cdecl _Stof(const char *,     char **, long);
 double __cdecl _Stod(const char *,     char **, long);
 long double __cdecl _Stold(const char *,     char **, 
  long);
 int __cdecl _Strcoll(const char *, const char *,
	const char *, const char *, const _Collvec *);
 size_t __cdecl _Strxfrm(
      char * _String1, 
     char * _End1, const char *, const char *, const _Collvec *);
 int __cdecl _Tolower(int, const _Ctypevec *);
 int __cdecl _Toupper(int, const _Ctypevec *);

 int __cdecl _Wcrtomb(  char *, wchar_t, mbstate_t *, const _Cvtvec *);

 int __cdecl _Wcscoll(const wchar_t *, const wchar_t *,
	const wchar_t *, const wchar_t *, const _Collvec *);
 size_t __cdecl _Wcsxfrm(
      wchar_t *_String1, 
     wchar_t *_End1, const wchar_t *, const wchar_t *, const _Collvec *);

 short __cdecl _Getwctype(wchar_t, const _Ctypevec *);
 const wchar_t * __cdecl _Getwctypes(const wchar_t *, const wchar_t *,
	short*, const _Ctypevec*);
 wchar_t __cdecl _Towlower(wchar_t, const _Ctypevec *);
 wchar_t __cdecl _Towupper(wchar_t, const _Ctypevec *);

}
#line 114 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"


extern "C" {
 void *__cdecl _Gettnames();
 char *__cdecl _Getdays();
 char *__cdecl _Getmonths();
 size_t __cdecl _Strftime(
    char *,   size_t _Maxsize, 
      const char *,   const struct tm *, void *);
}





 _locale_t __cdecl _GetLocaleForCP(unsigned int);
#line 131 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"

#pragma pack(pop)

#line 135 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo.h"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"



 #pragma pack(push,8)
 #pragma warning(push,3)
 #pragma warning(disable:4412)

namespace std {

		
class  _Timevec
	{	
public:
	 _Timevec(void *_Ptr = 0)
		: _Timeptr(_Ptr)
		{	
		}

	 _Timevec(const _Timevec& _Right)
		{	
		*this = _Right;
		}

	 ~_Timevec()
		{	
		free(_Timeptr);
		}

	_Timevec&  operator=(const _Timevec& _Right)
		{	
		_Timeptr = _Right._Timeptr;
		((_Timevec *)&_Right)->_Timeptr = 0;
		return (*this);
		}

	void * _Getptr() const
		{	
		return (_Timeptr);
		}

private:
	void *_Timeptr;	
	};

		

#pragma warning(push)
#pragma warning(disable: 4412)

class  _Locinfo
	{	
public:
	typedef ::_Collvec _Collvec;
	typedef ::_Ctypevec _Ctypevec;
	typedef ::_Cvtvec _Cvtvec;
	typedef ::std:: _Timevec _Timevec;

    static  void __cdecl _Locinfo_ctor(_Locinfo *,
		const char *);
    static  void __cdecl _Locinfo_ctor(_Locinfo *, int,
		const char *);
    static  void __cdecl _Locinfo_dtor(_Locinfo *);
    static  _Locinfo& __cdecl _Locinfo_Addcats(_Locinfo *, int,
		const char *);

	 _Locinfo(const char *_Pch = "C")

        : _Lock(0)
#line 76 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"
        {	
        if (_Pch == 0)
            throw runtime_error("bad locale name");
        _Locinfo_ctor(this, _Pch);
        }

	 _Locinfo(int _Cat, const char *_Pch)

        : _Lock(0)
#line 86 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"
        {	
        if (_Pch == 0)
            throw runtime_error("bad locale name");
        _Locinfo_ctor(this, _Cat, _Pch);
        }

	 ~_Locinfo()
        {
        _Locinfo_dtor(this);
        }


	_Locinfo&  _Addcats(int _Cat, const char *_Pch)
		{	
		if (_Pch == 0)
			throw runtime_error("bad locale name");
		return _Locinfo_Addcats(this, _Cat, _Pch);
		}


	const char * _Getname() const
		{	
		return (_Newlocname._C_str());
		}

	_Collvec  _Getcoll() const
		{	
		return (::_Getcoll());
		}

	_Ctypevec  _Getctype() const
		{	
		return (::_Getctype());
		}

	_Cvtvec  _Getcvt() const
		{	
		return (::_Getcvt());
		}

	const lconv * _Getlconv() const
		{	
		return (localeconv());
		}

	_Timevec  _Gettnames() const
		{	
		return (_Timevec(::_Gettnames()));
		}

	const char * _Getdays() const
		{	
		const char *_Ptr = ::_Getdays();
		if (_Ptr != 0)
			{	
			((_Locinfo *)this)->_Days = _Ptr;
			free((void *)_Ptr);
			}
		return (!_Days._Empty() ? _Days._C_str()
			: ":Sun:Sunday:Mon:Monday:Tue:Tuesday:Wed:Wednesday"
				":Thu:Thursday:Fri:Friday:Sat:Saturday");
		}

	const char * _Getmonths() const
		{	
		const char *_Ptr = ::_Getmonths();
		if (_Ptr != 0)
			{	
			((_Locinfo *)this)->_Months = _Ptr;
			free((void *)_Ptr);
			}
		return (!_Months._Empty() ? _Months._C_str()
			: ":Jan:January:Feb:February:Mar:March"
				":Apr:April:May:May:Jun:June"
				":Jul:July:Aug:August:Sep:September"
				":Oct:October:Nov:November:Dec:December");
		}

	const char * _Getfalse() const
		{	
		return ("false");
		}

	const char * _Gettrue() const
		{	
		return ("true");
		}

	int  _Getdateorder() const
		{	
		return ::_Getdateorder();
		}

private:









	_Lockit _Lock;	
#line 191 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"

	_Yarn<char> _Days;	
	_Yarn<char> _Months;	
	_Yarn<char> _Oldlocname;	
	_Yarn<char> _Newlocname;	
	};
#pragma warning(pop)

		
template<class _Elem> inline
	int __cdecl _LStrcoll(const _Elem *_First1, const _Elem *_Last1,
		const _Elem *_First2, const _Elem *_Last2,
			const _Locinfo::_Collvec *)
	{	
	for (; _First1 != _Last1 && _First2 != _Last2; ++_First1, ++_First2)
		if (*_First1 < *_First2)
			return (-1);	
		else if (*_First2 < *_First1)
			return (+1);	
	return (_First2 != _Last2 ? -1 : _First1 != _Last1 ? +1 : 0);
	}

template<> inline
	int __cdecl _LStrcoll(const char *_First1, const char *_Last1,
		const char *_First2, const char *_Last2,
			const _Locinfo::_Collvec *_Vector)
	{	
	return (_Strcoll(_First1, _Last1, _First2, _Last2, _Vector));
	}

template<> inline
	int __cdecl _LStrcoll(const wchar_t *_First1, const wchar_t *_Last1,
		const wchar_t *_First2, const wchar_t *_Last2,
			const _Locinfo::_Collvec *_Vector)
	{	
	return (_Wcscoll(_First1, _Last1, _First2, _Last2, _Vector));
	}

		
template<class _Elem> inline
	size_t __cdecl _LStrxfrm(_Elem *_First1, _Elem *_Last1,
		const _Elem *_First2, const _Elem *_Last2,
			const _Locinfo::_Collvec *)
	{	
	size_t _Count = _Last2 - _First2;
	if (_Count <= (size_t)(_Last1 - _First1))
		::memcpy_s((_First1), ((_Last1 - _First1) * sizeof(_Elem)), (_First2), (_Count * sizeof (_Elem)));
#line 239 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"
	return (_Count);
	}

template<> inline
	size_t __cdecl _LStrxfrm(
		    char *_First1, 
		   char *_Last1,
		const char *_First2, const char *_Last2,
			const _Locinfo::_Collvec *_Vector)
	{	
	return (_Strxfrm(_First1, _Last1, _First2, _Last2, _Vector));
	}

template<> inline
	size_t __cdecl _LStrxfrm(
		    wchar_t *_First1, 
		   wchar_t *_Last1,
		const wchar_t *_First2, const wchar_t *_Last2,
			const _Locinfo::_Collvec *_Vector)
	{	
	return (_Wcsxfrm(_First1, _Last1, _First2, _Last2, _Vector));
	}
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 267 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"
#line 268 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocinfo"





#line 11 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xdebug"

#pragma once





 #pragma pack(push,8)
 #pragma warning(push,3)

 
  
 
  

namespace std {
struct _DebugHeapTag_t
	{	
	int _Type;
	};
}

		

 










































#line 69 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xdebug"
   
   
   
  #line 73 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xdebug"

 
 

 #pragma warning(pop)
 #pragma pack(pop)


#line 82 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xdebug"
#line 83 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xdebug"





#line 12 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

 #pragma pack(push,8)
 #pragma warning(push,3)

 
 

 #pragma warning(disable: 4412)

namespace std {
		
template<class _Dummy>
	class _Locbase
	{	
public:
	 static const int collate = ((1 << (1)) >> 1);
	 static const int ctype = ((1 << (2)) >> 1);
	 static const int monetary = ((1 << (3)) >> 1);
	 static const int numeric = ((1 << (4)) >> 1);
	 static const int time = ((1 << (5)) >> 1);
	 static const int messages = ((1 << (6)) >> 1);
	 static const int all = (((1 << (7)) >> 1) - 1);
	 static const int none = 0;
	};

template<class _Dummy>
	const int _Locbase<_Dummy>::collate;
template<class _Dummy>
	const int _Locbase<_Dummy>::ctype;
template<class _Dummy>
	const int _Locbase<_Dummy>::monetary;
template<class _Dummy>
	const int _Locbase<_Dummy>::numeric;
template<class _Dummy>
	const int _Locbase<_Dummy>::time;
template<class _Dummy>
	const int _Locbase<_Dummy>::messages;
template<class _Dummy>
	const int _Locbase<_Dummy>::all;
template<class _Dummy>
	const int _Locbase<_Dummy>::none;

		
class locale;
template<class _Facet>
	const _Facet& __cdecl use_facet(const locale&);

class  locale
	: public _Locbase<int>
	{	
public:
	typedef int category;

			
	class  id
		{	
	public:
		 id(size_t _Val = 0)
			: _Id(_Val)
			{	
			}

		 operator size_t()
			{	
			if (_Id == 0)
				{	
				{ ::std:: _Lockit _Lock(0);
					if (_Id == 0)
						_Id = ++_Id_cnt;
				}
				}
			return (_Id);
			}

	private:
		size_t _Id;	

		 static int _Id_cnt;

		 id(const id&);	
		id&  operator=(const id&);	
		};

	class _Locimp;

			
	class facet
		{	
		friend class locale;
		friend class _Locimp;

	public:
		 static size_t __cdecl _Getcat(const facet ** = 0,
			const locale * = 0)
			{	
			return ((size_t)(-1));
			}

		 void  _Incref()
			{	
			{ ::std:: _Lockit _Lock(0);
				if (_Refs < (size_t)(-1))
					++_Refs;
			}
			}

		 facet * _Decref()
			{	
			{ ::std:: _Lockit _Lock(0);
				if (0 < _Refs && _Refs < (size_t)(-1))
					--_Refs;
				return (_Refs == 0 ? this : 0);
			}
			}

		void  _Register()
			{	
 


#line 133 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
			_Facet_Register(this);
 #line 135 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
			}

  






















#line 161 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"


		 virtual  ~facet()
			{	
			}

	protected:
		 explicit  facet(size_t _Initrefs = 0)
			: _Refs(_Initrefs)
			{	
			}

	private:
		size_t _Refs;	

		 facet(const facet&);	

		facet&  operator=(const facet&);	

 


#line 184 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
		static void __cdecl _Facet_Register(facet *);
 #line 186 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
		};

			
 #pragma warning(push)
 #pragma warning(disable: 4275)

	class  _Locimp
		: public facet
		{	
	protected:
		 ~_Locimp()
		{	
		_Locimp_dtor(this);
		}

	private:
		static  void __cdecl _Locimp_dtor(_Locimp *);
		static  void __cdecl _Locimp_Addfac(_Locimp *, facet *,
			size_t);	
		static void __cdecl _Locimp_ctor(_Locimp *, const _Locimp&);

		friend class locale;

		 _Locimp(bool _Transparent = false)
			: locale::facet(1), _Facetvec(0), _Facetcount(0),
				_Catmask(none), _Xparent(_Transparent),
					_Name("*")
			{	
			}

		 _Locimp(const _Locimp& _Right)
			: locale::facet(1), _Facetvec(0), _Facetcount(_Right._Facetcount),
				_Catmask(_Right._Catmask), _Xparent(_Right._Xparent),
					_Name(_Right._Name.c_str())
			{	
			_Locimp_ctor(this, _Right);
			}

		void  _Addfac(facet *_Pfacet, size_t _Id)
			{	
			_Locimp_Addfac(this, _Pfacet, _Id);
			}

		static _Locimp *__cdecl _Makeloc(const _Locinfo&,
			category, _Locimp *, const locale *);	

		static void __cdecl _Makewloc(const _Locinfo&,
			category, _Locimp *, const locale *);	

 
		static void __cdecl _Makeushloc(const _Locinfo&,
			category, _Locimp *, const locale *);	
 #line 239 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		static void __cdecl _Makexloc(const _Locinfo&,
			category, _Locimp *, const locale *);	

		facet **_Facetvec;	
		size_t _Facetcount;	
		category _Catmask;	
		bool _Xparent;	
		_Yarn<char> _Name;	

		 static _Locimp *_Clocptr;

private:
		_Locimp&  operator=(const _Locimp&);	
		};

 #pragma warning(pop)

	template<class _Elem,
		class _Traits,
		class _Alloc>
		bool operator()(const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right) const
		{	
		const ::std:: collate<_Elem>& _Coll_fac =
			::std:: use_facet<::std:: collate<_Elem> >(*this);

		return (_Coll_fac.compare(_Left.c_str(), _Left.c_str() + _Left.size(),
			_Right.c_str(), _Right.c_str() + _Right.size()) < 0);
		}

	template<class _Facet>
		locale combine(const locale& _Loc) const
		{	
		_Facet *_Facptr;

		try {
			_Facptr = (_Facet *)&::std:: use_facet<_Facet>(_Loc);
		} catch (...) {
			_Xruntime_error("locale::combine facet missing");
		}

		_Locimp *_Newimp = new _Locimp(*_Ptr);
		_Newimp->_Addfac(_Facptr, _Facet::id);
		_Newimp->_Catmask = 0;
		_Newimp->_Name = "*";
		return (locale(_Newimp));
		}

	template<class _Facet>
		locale(const locale& _Loc, const _Facet *_Facptr)
			: _Ptr(new _Locimp(*_Loc._Ptr))
		{	
		if (_Facptr != 0)
			{	
			_Ptr->_Addfac((_Facet *)_Facptr, _Facet::id);
			if (_Facet::_Getcat() != (size_t)(-1))
				{	
				_Ptr->_Catmask = 0;
				_Ptr->_Name = "*";
				}
			}
		}

	locale(_Uninitialized)
		{	
		}

	locale(const locale& _Right) throw ()
		: _Ptr(_Right._Ptr)
		{	
		_Ptr->_Incref();
		}

	locale() throw ()
		: _Ptr(_Init())
		{	
		_Getgloballocale()->_Incref();
		}

	locale(const locale& _Loc, const locale& _Other,
		category _Cat)
		: _Ptr(new _Locimp(*_Loc._Ptr))
		{	
		try {
		{ _Locinfo _Lobj(_Loc._Ptr->_Catmask, _Loc._Ptr->_Name.c_str());
			_Locimp::_Makeloc(_Lobj._Addcats(_Cat & _Other._Ptr->_Catmask,
				_Other._Ptr->_Name.c_str()), _Cat, _Ptr, &_Other);
		}
		} catch (...) {
		delete (_Ptr->_Decref());
		throw;
		}
		}

	explicit locale(const char *_Locname,
		category _Cat = all) 	
		: _Ptr(new _Locimp)
		{	
		try {
		_Init();
		{ _Locinfo _Lobj(_Cat, _Locname);
			if (_Badname(_Lobj))
				_Xruntime_error("bad locale name");
			_Locimp::_Makeloc(_Lobj, _Cat, _Ptr, 0);
		}
		} catch (...) {
		delete (_Ptr->_Decref());
		throw;
		}
		}

	locale(const locale& _Loc, const char *_Locname,
		category _Cat)
		: _Ptr(new _Locimp(*_Loc._Ptr))
		{	
		try {
		{ _Locinfo _Lobj(_Loc._Ptr->_Catmask, _Loc._Ptr->_Name.c_str());
			bool _Hadname = !_Badname(_Lobj);
			_Lobj._Addcats(_Cat, _Locname);

			if (_Hadname && _Badname(_Lobj))
				_Xruntime_error("bad locale name");
			_Locimp::_Makeloc(_Lobj, _Cat, _Ptr, 0);
		}
		} catch (...) {
		delete (_Ptr->_Decref());
		throw;
		}
		}

 
	explicit locale(const string& _Str,
		category _Cat = all)
		: _Ptr(new _Locimp)
		{	
		try {
		_Init();
		_Locinfo _Lobj(_Cat, _Str.c_str());

		if (_Badname(_Lobj))
			_Xruntime_error("bad locale name");
		_Locimp::_Makeloc(_Lobj, _Cat, _Ptr, 0);
		} catch (...) {
		delete (_Ptr->_Decref());
		throw;
		}
		}

	locale(const locale& _Loc, const string& _Str,
		category _Cat)
		: _Ptr(new _Locimp(*_Loc._Ptr))
		{	
		try {
		_Locinfo _Lobj(_Loc._Ptr->_Catmask, _Loc._Ptr->_Name.c_str());
		bool _Hadname = !_Badname(_Lobj);
		_Lobj._Addcats(_Cat, _Str.c_str());

		if (_Hadname && _Badname(_Lobj))
			_Xruntime_error("bad locale name");
		_Locimp::_Makeloc(_Lobj, _Cat, _Ptr, 0);
		} catch (...) {
		delete (_Ptr->_Decref());
		throw;
		}
		}
 #line 406 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"


	~locale() throw ()
		{	
		if (_Ptr != 0)
			delete (_Ptr->_Decref());
		}

	locale& operator=(const locale& _Right) throw ()
		{	
		if (_Ptr != _Right._Ptr)
			{	
			delete (_Ptr->_Decref());
			_Ptr = _Right._Ptr;
			_Ptr->_Incref();
			}
		return (*this);
		}

	string name() const
		{	
		return (_Ptr->_Name.c_str());
		}

	const char *c_str() const
		{	
		return (_Ptr->_Name.c_str());
		}

	const facet *_Getfacet(size_t _Id) const
		{	
		const facet *_Facptr = _Id < _Ptr->_Facetcount
			? _Ptr->_Facetvec[_Id] : 0;	
		if (_Facptr != 0 || !_Ptr->_Xparent)
			return (_Facptr);	
		else
			{	
			locale::_Locimp *_Ptr = _Getgloballocale();
			return (_Id < _Ptr->_Facetcount
				? _Ptr->_Facetvec[_Id]	
				: 0);	
			}
		}

	bool operator==(const locale& _Loc) const
		{	
		return (_Ptr == _Loc._Ptr
			|| name().compare("*") != 0 && name().compare(_Loc.name()) == 0);
		}

	bool operator!=(const locale& _Right) const
		{	
		return (!(*this == _Right));
		}

	static  const locale& __cdecl classic();	

	static  locale __cdecl global(const locale&);	

	static  locale __cdecl empty();	

private:
	locale(_Locimp *_Ptrimp)
		: _Ptr(_Ptrimp)
		{	
		}

    static  _Locimp *__cdecl _Init();	
	static  _Locimp *__cdecl _Getgloballocale();
	static  void __cdecl _Setgloballocale(void *);

	bool _Badname(const _Locinfo& _Lobj)
		{	
		return (:: strcmp(_Lobj._Getname(), "*") == 0);
		}

	_Locimp *_Ptr;	
	};

		
template<class _Facet>
	struct _Facetptr
	{	
	 static const locale::facet *_Psave;
	};

template<class _Facet>
	 const locale::facet *_Facetptr<_Facet>::
		_Psave = 0;

  

  


template<class _Facet> inline
	const _Facet& __cdecl use_facet(const locale& _Loc)

	{	
	{ ::std:: _Lockit _Lock(0);	
		const locale::facet *_Psave =
			_Facetptr<_Facet>::_Psave;	

		size_t _Id = _Facet::id;
		const locale::facet *_Pf = _Loc._Getfacet(_Id);

		if (_Pf != 0)
			;	
		else if (_Psave != 0)
			_Pf = _Psave;	
		else if (_Facet::_Getcat(&_Psave, &_Loc) == (size_t)(-1))

 

			throw bad_cast();	

 

#line 525 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		else
			{	
			_Pf = _Psave;
			_Facetptr<_Facet>::_Psave = _Psave;

			locale::facet *_Pfmod = (_Facet *)_Psave;
			_Pfmod->_Incref();
			_Pfmod->_Register();
			}

		return ((const _Facet&)(*_Pf));	
	}
	}

		
template<class _Elem,
	class _InIt> inline
	int __cdecl _Getloctxt(_InIt& _First, _InIt& _Last, size_t _Numfields,
		const _Elem *_Ptr)
	{	
	for (size_t _Off = 0; _Ptr[_Off] != (_Elem)0; ++_Off)
		if (_Ptr[_Off] == _Ptr[0])
			++_Numfields;	
	string _Str(_Numfields, '\0');	

	int _Ans = -2;	
	for (size_t _Column = 1; ; ++_Column, ++_First, _Ans = -1)
		{	
		bool _Prefix = false;	
		size_t _Off = 0;	
		size_t _Field = 0;	

		for (; _Field < _Numfields; ++_Field)
			{	
			for (; _Ptr[_Off] != (_Elem)0 && _Ptr[_Off] != _Ptr[0]; ++_Off)
				;	

			if (_Str[_Field] != '\0')
				_Off += _Str[_Field];	
			else if (_Ptr[_Off += _Column] == _Ptr[0]
				|| _Ptr[_Off] == (_Elem)0)
				{	
				_Str[_Field] = (char)(_Column < 127
					? _Column : 127);	
				_Ans = (int)_Field;	
				}
			else if (_First == _Last || _Ptr[_Off] != *_First)
				_Str[_Field] = (char)(_Column < 127
					? _Column : 127);	
			else
				_Prefix = true;	
			}

		if (!_Prefix || _First == _Last)
			break;	
		}
	return (_Ans);	
	}

		



template<class _Elem> inline
	char __cdecl _Maklocbyte(_Elem _Char,
		const _Locinfo::_Cvtvec&)
	{	
	return ((char)(unsigned char)_Char);
	}

template<> inline
	char __cdecl _Maklocbyte(wchar_t _Char,
		const _Locinfo::_Cvtvec& _Cvt)
	{	
	char _Byte = '\0';
	mbstate_t _Mbst1 = {0};
	_Wcrtomb(&_Byte, _Char, &_Mbst1, &_Cvt);
	return (_Byte);
	}

 
template<> inline
	char __cdecl _Maklocbyte(unsigned short _Char,
		const _Locinfo::_Cvtvec &_Cvt)
	{	
	char _Byte = '\0';
	mbstate_t _Mbst1 = {0};
	_Wcrtomb(&_Byte, (wchar_t)_Char, &_Mbst1, &_Cvt);
	return (_Byte);
	}
 #line 617 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		



template<class _Elem> inline
	_Elem __cdecl _Maklocchr(char _Byte, _Elem *,
		const _Locinfo::_Cvtvec&)
	{	
	return ((_Elem)(unsigned char)_Byte);
	}

template<> inline
	wchar_t __cdecl _Maklocchr(char _Byte, wchar_t *,
		const _Locinfo::_Cvtvec& _Cvt)
	{	
	wchar_t _Wc = L'\0';
	mbstate_t _Mbst1 = {0};
	_Mbrtowc(&_Wc, &_Byte, 1, &_Mbst1, &_Cvt);
	return (_Wc);
	}

 
template<> inline
	unsigned short __cdecl _Maklocchr(char _Byte, unsigned short *,
		const _Locinfo::_Cvtvec &_Cvt)
	{	
	unsigned short _Wc = (unsigned short)0;
	mbstate_t _Mbst1 = {0};
	_Mbrtowc((wchar_t *)&_Wc, &_Byte, 1, &_Mbst1, &_Cvt);
	return (_Wc);
	}
 #line 650 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		



template<class _Elem> inline
	_Elem *__cdecl _Maklocstr(const char *_Ptr, _Elem *,
		const _Locinfo::_Cvtvec&)
	{	
	size_t _Count = :: strlen(_Ptr) + 1;
	_Elem *_Ptrdest = new _Elem[_Count];

 #pragma warning(push)
 #pragma warning(disable: 6011)	
	for (_Elem *_Ptrnext = _Ptrdest; 0 < _Count; --_Count, ++_Ptrnext, ++_Ptr)
		*_Ptrnext = (_Elem)(unsigned char)*_Ptr;
 #pragma warning(pop)

	return (_Ptrdest);
	}

template<> inline
	wchar_t *__cdecl _Maklocstr(const char *_Ptr, wchar_t *,
		const _Locinfo::_Cvtvec& _Cvt)
	{	
	size_t _Count, _Count1;
	size_t _Wchars;
	const char *_Ptr1;
	int _Bytes;
	wchar_t _Wc;
	mbstate_t _Mbst1 = {0};

	_Count1 = :: strlen(_Ptr) + 1;
	for (_Count = _Count1, _Wchars = 0, _Ptr1 = _Ptr; 0 < _Count;
		_Count -= _Bytes, _Ptr1 += _Bytes, ++_Wchars)
		if ((_Bytes = _Mbrtowc(&_Wc, _Ptr1, _Count, &_Mbst1, &_Cvt)) <= 0)
			break;
	++_Wchars;	

	wchar_t *_Ptrdest = new wchar_t[_Wchars];
	wchar_t *_Ptrnext = _Ptrdest;
	mbstate_t _Mbst2 = {0};

 #pragma warning(push)
 #pragma warning(disable: 6011)	
	for (; 0 < _Wchars;
		_Count -= _Bytes, _Ptr += _Bytes, --_Wchars, ++_Ptrnext)
		if ((_Bytes = _Mbrtowc(_Ptrnext, _Ptr, _Count1, &_Mbst2, &_Cvt)) <= 0)
			break;
	*_Ptrnext = L'\0';
 #pragma warning(pop)

	return (_Ptrdest);
	}

 
template<> inline
	unsigned short *__cdecl _Maklocstr(const char *_Ptr, unsigned short *,
		const _Locinfo::_Cvtvec &_Cvt)
	{	
	size_t _Count, _Count1;
	size_t _Wchars;
	const char *_Ptr1;
	int _Bytes;
	unsigned short _Wc;
	mbstate_t _Mbst1 = {0};

	_Count1 = :: strlen(_Ptr) + 1;
	for (_Count = _Count1, _Wchars = 0, _Ptr1 = _Ptr; 0 < _Count;
		_Count -= _Bytes, _Ptr1 += _Bytes, ++_Wchars)
		if ((_Bytes =
			_Mbrtowc((wchar_t *)&_Wc, _Ptr1, _Count, &_Mbst1, &_Cvt)) <= 0)
			break;
	++_Wchars;	

	wchar_t *_Ptrdest = new wchar_t[_Wchars];
	wchar_t *_Ptrnext = _Ptrdest;
	mbstate_t _Mbst2 = {0};
	for (; 0 < _Wchars;
		_Count -= _Bytes, _Ptr += _Bytes, --_Wchars, ++_Ptrnext)
		if ((_Bytes = _Mbrtowc(_Ptrnext, _Ptr, _Count1, &_Mbst2, &_Cvt)) <= 0)
			break;
	*_Ptrnext = L'\0';
	return ((unsigned short *)_Ptrdest);
	}
 #line 736 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		
 #pragma warning(push)
 #pragma warning(disable: 4275)

class  codecvt_base
	: public locale::facet
	{	
public:
	enum
		{	
		ok, partial, error, noconv};
	typedef int result;

	 codecvt_base(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	
		}

	bool  always_noconv() const throw ()
		{	
		return (do_always_noconv());
		}

	int  max_length() const throw ()
		{	
		return (do_max_length());
		}

	int  encoding() const throw ()
		{	
		return (do_encoding());
		}

	 ~codecvt_base()
		{	
		}

protected:
	virtual bool  do_always_noconv() const throw ()
		{	
		return (true);
		}

	virtual int  do_max_length() const throw ()
		{	
		return (1);
		}

	virtual int  do_encoding() const throw ()
		{	
		return (1);	
		}
	};

 #pragma warning(pop)

		
template<class _Elem,
	class _Byte,
	class _Statype>
	class codecvt
		: public codecvt_base
	{	
public:
	typedef _Elem intern_type;
	typedef _Byte extern_type;
	typedef _Statype state_type;

	result  in(_Statype& _State,
		const _Byte *_First1, const _Byte *_Last1, const _Byte *& _Mid1,
		_Elem *_First2, _Elem *_Last2, _Elem *& _Mid2) const
		{	
		return (do_in(_State,
			_First1, _Last1, _Mid1, _First2, _Last2, _Mid2));
		}

	result  out(_Statype& _State,
		const _Elem *_First1, const _Elem *_Last1, const _Elem *& _Mid1,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		return (do_out(_State,
			_First1, _Last1, _Mid1, _First2, _Last2, _Mid2));
		}

	result  unshift(_Statype& _State,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		return (do_unshift(_State, _First2, _Last2, _Mid2));
		}

	int  length(const _Statype& _State, const _Byte *_First1,
		const _Byte *_Last1, size_t _Count) const
		{	
		return (do_length(_State, _First1, _Last1, _Count));
		}

	 static locale::id id;	

	explicit  codecvt(size_t _Refs = 0)
		: codecvt_base(_Refs)
		{	
		_Init(_Locinfo());
		}

	 codecvt(const _Locinfo& _Lobj, size_t _Refs = 0)
		: codecvt_base(_Refs)
		{	
		_Init(_Lobj);
		}

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new codecvt<_Elem, _Byte, _Statype>(
				_Locinfo(_Ploc->c_str()));
		return (2);
		}

protected:
	virtual  ~codecvt()
		{	
		}

	void  _Init(const _Locinfo&)
		{	
		}

	virtual result  do_in(_Statype&,
		const _Byte *_First1, const _Byte *, const _Byte *& _Mid1,
		_Elem *_First2, _Elem *, _Elem *& _Mid2) const
		{	
		_Mid1 = _First1, _Mid2 = _First2;
		return (noconv);	
		}

	virtual result  do_out(_Statype&,
		const _Elem *_First1, const _Elem *, const _Elem *& _Mid1,
		_Byte *_First2, _Byte *, _Byte *& _Mid2) const
		{	
		_Mid1 = _First1, _Mid2 = _First2;
		return (noconv);	
		}

	virtual result  do_unshift(_Statype&,
		_Byte *_First2, _Byte *, _Byte *&_Mid2) const
		{	
		_Mid2 = _First2;
		return (noconv);	
		}

	virtual int  do_length(const _Statype&, const _Byte *_First1,
		const _Byte *_Last1, size_t _Count) const
		{	
		return ((int)(_Count < (size_t)(_Last1 - _First1)
			? _Count : _Last1 - _First1));	
		}
	};

		
template<class _Elem,
	class _Byte,
	class _Statype>
	 locale::id codecvt<_Elem, _Byte, _Statype>::id;

 




















































































































































































































































































































































































































































































































































































































#line 1500 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		
template<>
	class  codecvt<wchar_t, char, _Mbstatet>
	: public codecvt_base
	{	
public:
	typedef wchar_t _Elem;
	typedef char _Byte;
	typedef _Mbstatet _Statype;
	typedef _Elem intern_type;
	typedef _Byte extern_type;
	typedef _Statype state_type;

	result  in(_Statype& _State,
		const _Byte *_First1, const _Byte *_Last1, const _Byte *& _Mid1,
		_Elem *_First2, _Elem *_Last2, _Elem *& _Mid2) const
		{	
		return (do_in(_State,
			_First1, _Last1, _Mid1, _First2, _Last2, _Mid2));
		}

	result  out(_Statype& _State,
		const _Elem *_First1, const _Elem *_Last1, const _Elem *& _Mid1,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		return (do_out(_State,
			_First1, _Last1, _Mid1, _First2, _Last2, _Mid2));
		}

	result  unshift(_Statype& _State,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		return (do_unshift(_State,
			_First2, _Last2, _Mid2));
		}

	int  length(const _Statype& _State, const _Byte *_First1,
		const _Byte *_Last1, size_t _Count) const
		{	
		return (do_length(_State, _First1, _Last1, _Count));
		}

	 static locale::id id;

	explicit  codecvt(size_t _Refs = 0)
		: codecvt_base(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		}

	 codecvt(const _Locinfo& _Lobj, size_t _Refs = 0)
		: codecvt_base(_Refs)
		{	
		_Init(_Lobj);
		}

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new codecvt<_Elem, _Byte, _Statype>(
				_Locinfo(_Ploc->c_str()));
		return (2);
		}

protected:
	virtual  ~codecvt()
		{	
		}

	void  _Init(const _Locinfo& _Lobj)
		{	
		_Cvt = _Lobj._Getcvt();
		}

	virtual result  do_in(_Statype& _State,
		const _Byte *_First1, const _Byte *_Last1, const _Byte *& _Mid1,
			_Elem *_First2, _Elem *_Last2, _Elem *& _Mid2) const
		{	
		;
		;
		_Mid1 = _First1, _Mid2 = _First2;
		result _Ans = _Mid1 == _Last1 ? ok : partial;
		int _Bytes;

		while (_Mid1 != _Last1 && _Mid2 != _Last2)
			switch (_Bytes = _Mbrtowc(_Mid2, _Mid1, _Last1 - _Mid1,
				&_State, &_Cvt))
			{	
			case -2:	
				_Mid1 = _Last1;
				return (_Ans);

			case -1:	
				return (error);

			case 0:	
				if (*_Mid2 == (_Elem)0)
					_Bytes = (int):: strlen(_Mid1) + 1;
				

			default:	
				if (_Bytes == -3)
					_Bytes = 0;	
				_Mid1 += _Bytes;
				++_Mid2;
				_Ans = ok;
			}
		return (_Ans);
		}

	virtual result  do_out(_Statype& _State,
		const _Elem *_First1, const _Elem *_Last1, const _Elem *& _Mid1,
			_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		;
		;
		_Mid1 = _First1, _Mid2 = _First2;
		result _Ans = _Mid1 == _Last1 ? ok : partial;
		int _Bytes;

		while (_Mid1 != _Last1 && _Mid2 != _Last2)
			if ((int)___mb_cur_max_func() <= _Last2 - _Mid2)
				if ((_Bytes = _Wcrtomb(_Mid2, *_Mid1,
					&_State, &_Cvt)) < 0)
					return (error);	
				else
					++_Mid1, _Mid2 += _Bytes, _Ans = ok;
			else
				{	
				_Byte _Buf[5];
				_Statype _Stsave = _State;

				if ((_Bytes = _Wcrtomb(_Buf, *_Mid1,
					&_State, &_Cvt)) < 0)
					return (error);	
				else if (_Last2 - _Mid2 < _Bytes)
					{	
					_State = _Stsave;
					return (_Ans);
					}
				else
					{	
					:: memcpy(_Mid2, _Buf, _Bytes);
					++_Mid1, _Mid2 += _Bytes, _Ans = ok;
					}
				}
		return (_Ans);
		}

	virtual result  do_unshift(_Statype& _State,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		;
		_Mid2 = _First2;
		result _Ans = ok;
		int _Bytes;
		_Byte _Buf[5];
		_Statype _Stsave = _State;

		if ((_Bytes = _Wcrtomb(_Buf, L'\0', &_State, &_Cvt)) <= 0)
			_Ans = error;	
		else if (_Last2 - _Mid2 < --_Bytes)
			{	
			_State = _Stsave;
			_Ans = partial;
			}
		else if (0 < _Bytes)
			{	
			:: memcpy(_Mid2, _Buf, _Bytes);
			_Mid2 += _Bytes;
			}
		return (_Ans);
		}

	virtual int  do_length(const _Statype& _State, const _Byte *_First1,
		const _Byte *_Last1, size_t _Count) const
		{	
 



#line 1686 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
		;
		int _Wchars;
		const _Byte *_Mid1;
		_Statype _Mystate = _State;

		for (_Wchars = 0, _Mid1 = _First1;
			(size_t)_Wchars < _Count && _Mid1 != _Last1; )
			{	
			int _Bytes;
			_Elem _Ch;

			switch (_Bytes = _Mbrtowc(&_Ch, _Mid1, _Last1 - _Mid1,
				&_Mystate, &_Cvt))
				{	
			case -2:	
				return (_Wchars);

			case -1:	
				return (_Wchars);

			case 0:	
				if (_Ch == (_Elem)0)
					_Bytes = (int):: strlen(_Mid1) + 1;
				

			default:	
				if (_Bytes == -3)
					_Bytes = 0;	
				_Mid1 += _Bytes;
				++_Wchars;
				}
			}
		return (_Wchars);
 #line 1720 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
		}

	virtual bool  do_always_noconv() const throw ()
		{	
		return (false);
		}

	virtual int  do_max_length() const throw ()
		{	
		return (5);
		}

private:
	_Locinfo::_Cvtvec _Cvt;	
	};

 
		
template<>
	class  codecvt<unsigned short, char, _Mbstatet>
	: public codecvt_base
	{	
public:
	typedef unsigned short _Elem;
	typedef char _Byte;
	typedef _Mbstatet _Statype;
	typedef _Elem intern_type;
	typedef _Byte extern_type;
	typedef _Statype state_type;

	result  in(_Statype& _State,
		const _Byte *_First1, const _Byte *_Last1, const _Byte *& _Mid1,
		_Elem *_First2, _Elem *_Last2, _Elem *& _Mid2) const
		{	
		return (do_in(_State,
			_First1, _Last1, _Mid1, _First2, _Last2, _Mid2));
		}

	result  out(_Statype& _State,
		const _Elem *_First1, const _Elem *_Last1, const _Elem *& _Mid1,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		return (do_out(_State,
			_First1, _Last1, _Mid1, _First2, _Last2, _Mid2));
		}

	result  unshift(_Statype& _State,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		return (do_unshift(_State,
			_First2, _Last2, _Mid2));
		}

	int  length(const _Statype& _State, const _Byte *_First1,
		const _Byte *_Last1, size_t _Count) const
		{	
		return (do_length(_State, _First1, _Last1, _Count));
		}

	 static locale::id id;

	explicit  codecvt(size_t _Refs = 0)
		: codecvt_base(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		}

	 codecvt(const _Locinfo& _Lobj, size_t _Refs = 0)
		: codecvt_base(_Refs)
		{	
		_Init(_Lobj);
		}

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new codecvt<_Elem, _Byte, _Statype>(
				_Locinfo(_Ploc->c_str()));
		return (2);
		}

protected:
	virtual  ~codecvt()
		{	
		}

	void  _Init(const _Locinfo& _Lobj)
		{	
		_Cvt = _Lobj._Getcvt();
		}

	virtual result  do_in(_Statype& _State,
		const _Byte *_First1, const _Byte *_Last1, const _Byte *& _Mid1,
			_Elem *_First2, _Elem *_Last2, _Elem *& _Mid2) const
		{	
		;
		;
		_Mid1 = _First1, _Mid2 = _First2;
		result _Ans = _Mid1 == _Last1 ? ok : partial;
		int _Bytes;

		while (_Mid1 != _Last1 && _Mid2 != _Last2)
			switch (_Bytes = _Mbrtowc((wchar_t *)_Mid2, _Mid1, _Last1 - _Mid1,
				&_State, &_Cvt))
			{	
			case -2:	
				_Mid1 = _Last1;
				return (_Ans);

			case -1:	
				return (error);

			case 0:	
				if (*_Mid2 == (_Elem)0)
					_Bytes = (int):: strlen(_Mid1) + 1;
				

			default:	
				if (_Bytes == -3)
					_Bytes = 0;	
				_Mid1 += _Bytes;
				++_Mid2;
				_Ans = ok;
			}
		return (_Ans);
		}

	virtual result  do_out(_Statype& _State,
		const _Elem *_First1, const _Elem *_Last1, const _Elem *& _Mid1,
			_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		;
		;
		_Mid1 = _First1, _Mid2 = _First2;
		result _Ans = _Mid1 == _Last1 ? ok : partial;
		int _Bytes;

		while (_Mid1 != _Last1 && _Mid2 != _Last2)
			if ((int)___mb_cur_max_func() <= _Last2 - _Mid2)
				if ((_Bytes = _Wcrtomb(_Mid2, *_Mid1,
					&_State, &_Cvt)) < 0)
					return (error);	
				else
					++_Mid1, _Mid2 += _Bytes, _Ans = ok;
			else
				{	
				_Byte _Buf[5];
				_Statype _Stsave = _State;

				if ((_Bytes = _Wcrtomb(_Buf, *_Mid1,
					&_State, &_Cvt)) < 0)
					return (error);	
				else if (_Last2 - _Mid2 < _Bytes)
					{	
					_State = _Stsave;
					return (_Ans);
					}
				else
					{	
					:: memcpy(_Mid2, _Buf, _Bytes);
					++_Mid1, _Mid2 += _Bytes, _Ans = ok;
					}
				}
		return (_Ans);
		}

	virtual result  do_unshift(_Statype& _State,
		_Byte *_First2, _Byte *_Last2, _Byte *& _Mid2) const
		{	
		;
		_Mid2 = _First2;
		result _Ans = ok;
		int _Bytes;
		_Byte _Buf[5];
		_Statype _Stsave = _State;

		if ((_Bytes = _Wcrtomb(_Buf, L'\0', &_State, &_Cvt)) <= 0)
			_Ans = error;	
		else if (_Last2 - _Mid2 < --_Bytes)
			{	
			_State = _Stsave;
			_Ans = partial;
			}
		else if (0 < _Bytes)
			{	
			:: memcpy(_Mid2, _Buf, _Bytes);
			_Mid2 += _Bytes;
			}
		return (_Ans);
		}

	virtual int  do_length(const _Statype& _State, const _Byte *_First1,
		const _Byte *_Last1, size_t _Count) const
		{	
		;
		int _Wchars;
		const _Byte *_Mid1;
		_Statype _Mystate = _State;

		for (_Wchars = 0, _Mid1 = _First1;
			(size_t)_Wchars < _Count && _Mid1 != _Last1; )
			{	
			int _Bytes;
			_Elem _Ch;

			switch (_Bytes = _Mbrtowc((wchar_t *)&_Ch, _Mid1, _Last1 - _Mid1,
				&_Mystate, &_Cvt))
				{	
			case -2:	
				return (_Wchars);

			case -1:	
				return (_Wchars);

			case 0:	
				if (_Ch == (_Elem)0)
					_Bytes = (int):: strlen(_Mid1) + 1;
				

			default:	
				if (_Bytes == -3)
					_Bytes = 0;	
				_Mid1 += _Bytes;
				++_Wchars;
				}
			}
		return (_Wchars);
		}

	virtual bool  do_always_noconv() const throw ()
		{	
		return (false);
		}

	virtual int  do_max_length() const throw ()
		{	
		return (5);
		}

private:
	_Locinfo::_Cvtvec _Cvt;	
	};
 #line 1966 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		
template<class _Elem,
	class _Byte,
	class _Statype>
	class codecvt_byname
		: public codecvt<_Elem, _Byte, _Statype>
	{	
public:
	explicit  codecvt_byname(const char *_Locname, size_t _Refs = 0)
		: codecvt<_Elem, _Byte, _Statype>(_Locinfo(_Locname), _Refs)
		{	
		}

 
	explicit  codecvt_byname(const string& _Str, size_t _Refs = 0)
		: codecvt<_Elem, _Byte, _Statype>(_Locinfo(_Str.c_str()), _Refs)
		{	
		}
 #line 1986 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

protected:
	virtual  ~codecvt_byname()
		{	
		}
	};

		
 #pragma warning(push)
 #pragma warning(disable: 4275)

struct  ctype_base
	: public locale::facet
	{	
	enum
		{	
		alnum = 0x4|0x2|0x1|0x100, alpha = 0x2|0x1|0x100,
		cntrl = 0x20, digit = 0x4, graph = 0x4|0x2|0x10|0x1|0x100,
		lower = 0x2, print = 0x4|0x2|0x10|0x40|0x1|0x100|0x80,
		punct = 0x10, space = 0x8|0x40|0x000, upper = 0x1,
		xdigit = 0x80};
	typedef short mask;	

	 ctype_base(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	
		}

	 ~ctype_base()
		{	
		}
	};

 #pragma warning(pop)

		
template<class _Elem>
	class ctype
		: public ctype_base
	{	
public:
	typedef _Elem char_type;

	bool  is(mask _Maskval, _Elem _Ch) const
		{	
		return (do_is(_Maskval, _Ch));
		}

	const _Elem * is(const _Elem *_First, const _Elem *_Last,
		mask *_Dest) const
		{	
		return (do_is(_First, _Last, _Dest));
		}

	const _Elem * scan_is(mask _Maskval, const _Elem *_First,
		const _Elem *_Last) const
		{	
		return (do_scan_is(_Maskval, _First, _Last));
		}

	const _Elem * scan_not(mask _Maskval, const _Elem *_First,
		const _Elem *_Last) const
		{	
		return (do_scan_not(_Maskval, _First, _Last));
		}

	_Elem  tolower(_Elem _Ch) const
		{	
		return (do_tolower(_Ch));
		}

	const _Elem * tolower(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_tolower(_First, _Last));
		}

	_Elem  toupper(_Elem _Ch) const
		{	
		return (do_toupper(_Ch));
		}

	const _Elem * toupper(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_toupper(_First, _Last));
		}

	_Elem  widen(char _Byte) const
		{	
		return (do_widen(_Byte));
		}

	const char * widen(const char *_First, const char *_Last,
		_Elem *_Dest) const
		{	
		return (do_widen(_First, _Last, _Dest));
		}

	char  narrow(_Elem _Ch, char _Dflt = '\0') const
		{	
		return (do_narrow(_Ch, _Dflt));
		}

	const _Elem * narrow(const _Elem *_First, const _Elem *_Last,
		char _Dflt, char *_Dest) const
		{	
		return (do_narrow(_First, _Last, _Dflt, _Dest));
		}

	 static locale::id id;

	explicit  ctype(size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		}

	 ctype(const _Locinfo& _Lobj, size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		_Init(_Lobj);
		}

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new ctype<_Elem>(
				_Locinfo(_Ploc->c_str()));
		return (2);
		}

protected:
	virtual  ~ctype()
		{	
		if (_Ctype._Delfl)
			free((void *)_Ctype._Table);
		}

	void  _Init(const _Locinfo& _Lobj)
		{	
		_Ctype = _Lobj._Getctype();
		}

	virtual bool  do_is(mask _Maskval, _Elem _Ch) const
		{	
		return ((_Ctype._Table[(unsigned char)narrow(_Ch)]
			& _Maskval) != 0);
		}

	virtual const _Elem * do_is(const _Elem *_First, const _Elem *_Last,
		mask *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Ctype._Table[(unsigned char)narrow(*_First)];
		return (_First);
		}

	virtual const _Elem * do_scan_is(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && !is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	virtual const _Elem * do_scan_not(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	virtual _Elem  do_tolower(_Elem _Ch) const
		{	
		unsigned char _Byte = (unsigned char)narrow(_Ch, '\0');
		if (_Byte == '\0')
			return (_Ch);
		else
			return (widen((char)_Tolower(_Byte, &_Ctype)));
		}

	virtual const _Elem * do_tolower(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			{	
			unsigned char _Byte = (unsigned char)narrow(*_First, '\0');
			if (_Byte != '\0')
				*_First = (widen((char)_Tolower(_Byte, &_Ctype)));
			}
		return ((const _Elem *)_First);
		}

	virtual _Elem  do_toupper(_Elem _Ch) const
		{	
		unsigned char _Byte = (unsigned char)narrow(_Ch, '\0');
		if (_Byte == '\0')
			return (_Ch);
		else
			return (widen((char)_Toupper(_Byte, &_Ctype)));
		}

	virtual const _Elem * do_toupper(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			{	
			unsigned char _Byte = (unsigned char)narrow(*_First, '\0');
			if (_Byte != '\0')
				*_First = (widen((char)_Toupper(_Byte, &_Ctype)));
			}
		return ((const _Elem *)_First);
		}

	virtual _Elem  do_widen(char _Byte) const
		{	
		return (_Maklocchr(_Byte, (_Elem *)0, _Cvt));
		}

	virtual const char * do_widen(const char *_First,
		const char *_Last, _Elem *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Maklocchr(*_First, (_Elem *)0, _Cvt);
		return (_First);
		}

	char  _Donarrow(_Elem _Ch, char _Dflt) const
		{	
		char _Byte;
		if (_Ch == (_Elem)0)
			return ('\0');
		else if ((_Byte = _Maklocbyte((_Elem)_Ch, _Cvt)) == '\0')
			return (_Dflt);
		else
			return (_Byte);
		}

	virtual char  do_narrow(_Elem _Ch, char _Dflt) const
		{	
		return (_Donarrow(_Ch, _Dflt));
		}

	virtual const _Elem * do_narrow(const _Elem *_First,
		const _Elem *_Last, char _Dflt, char *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Donarrow(*_First, _Dflt);
		return (_First);
		}

private:
	_Locinfo::_Ctypevec _Ctype;	
	_Locinfo::_Cvtvec _Cvt;		
	};

		
template<class _Elem>
	locale::id ctype<_Elem>::id;

		
template<>
	class  ctype<char>
	: public ctype_base
	{	
	typedef ctype<char> _Myt;

public:
	typedef char _Elem;
	typedef _Elem char_type;

	bool  is(mask _Maskval, _Elem _Ch) const
		{	
		return ((_Ctype._Table[(unsigned char)_Ch] & _Maskval) != 0);
		}

	const _Elem * is(const _Elem *_First,
		const _Elem *_Last, mask *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Ctype._Table[(unsigned char)*_First];
		return (_First);
		}

	const _Elem * scan_is(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && !is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	const _Elem * scan_not(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	_Elem  tolower(_Elem _Ch) const
		{	
		return (do_tolower(_Ch));
		}

	const _Elem * tolower(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_tolower(_First, _Last));
		}

	_Elem  toupper(_Elem _Ch) const
		{	
		return (do_toupper(_Ch));
		}

	const _Elem * toupper(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_toupper(_First, _Last));
		}

	_Elem  widen(char _Byte) const
		{	
		return (do_widen(_Byte));
		}

	const _Elem * widen(const char *_First, const char *_Last,
		_Elem *_Dest) const
		{	
		return (do_widen(_First, _Last, _Dest));
		}

	_Elem  narrow(_Elem _Ch, char _Dflt = '\0') const
		{	
		return (do_narrow(_Ch, _Dflt));
		}

	const _Elem * narrow(const _Elem *_First, const _Elem *_Last,
		char _Dflt, char *_Dest) const
		{	
		return (do_narrow(_First, _Last, _Dflt, _Dest));
		}

	 static locale::id id;

	explicit  ctype(const mask *_Table = 0,
		bool _Deletetable = false,
		size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		if (_Table != 0)
			{	
			_Tidy();
			_Ctype._Table = _Table;
			_Ctype._Delfl = _Deletetable ? -1 : 0;
			}
		}

	 ctype(const _Locinfo& _Lobj, size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		_Init(_Lobj);
		}

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new ctype<_Elem>(
				_Locinfo(_Ploc->c_str()));
		return (2);
		}

	const mask * table() const throw ()
		{	
		return (_Ctype._Table);
		}

	static const mask *__cdecl classic_table() throw ()
		{	
		const _Myt& _Ctype_fac = use_facet< _Myt >(locale::classic());
		return (_Ctype_fac.table());
		}

	 static const size_t table_size =
		1 << 8;	

protected:
	virtual  ~ctype()
		{	
		_Tidy();
		}

	void  _Init(const _Locinfo& _Lobj)
		{	
		_Ctype = _Lobj._Getctype();
		}

	void  _Tidy()
		{	
		if (0 < _Ctype._Delfl)
			free((void *)_Ctype._Table);
		else if (_Ctype._Delfl < 0)
			delete[] (void *)_Ctype._Table;
		}

	virtual _Elem  do_tolower(_Elem _Ch) const
		{	
		return ((_Elem)_Tolower((unsigned char)_Ch, &_Ctype));
		}

	virtual const _Elem * do_tolower(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			*_First = (_Elem)_Tolower((unsigned char)*_First, &_Ctype);
		return ((const _Elem *)_First);
		}

	virtual _Elem  do_toupper(_Elem _Ch) const
		{	
		return ((_Elem)_Toupper((unsigned char)_Ch, &_Ctype));
		}

	virtual const _Elem * do_toupper(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			*_First = (_Elem)_Toupper((unsigned char)*_First, &_Ctype);
		return ((const _Elem *)_First);
		}

	virtual _Elem  do_widen(char _Byte) const
		{	
		return (_Byte);
		}

	virtual const _Elem * do_widen(const char *_First,
		const char *_Last, _Elem *_Dest) const
		{	
		;
		;
		:: memcpy(_Dest, _First, _Last - _First);
		return (_Last);
		}

	virtual _Elem  do_narrow(_Elem _Ch, char) const
		{	
		return (_Ch);
		}

	virtual const _Elem * do_narrow(const _Elem *_First,
		const _Elem *_Last, char, char *_Dest) const
		{	
		;
		;
		:: memcpy(_Dest, _First, _Last - _First);
		return (_Last);
		}

private:
	_Locinfo::_Ctypevec _Ctype;	
	};

		
template<>
	class  ctype<wchar_t>
	: public ctype_base
	{	
	typedef ctype<wchar_t> _Myt;

public:
	typedef wchar_t _Elem;
	typedef _Elem char_type;

	bool  is(mask _Maskval, _Elem _Ch) const
		{	
		return (do_is(_Maskval, _Ch));
		}

	const _Elem * is(const _Elem *_First, const _Elem *_Last,
		mask *_Dest) const
		{	
		return (do_is(_First, _Last, _Dest));
		}

	const _Elem * scan_is(mask _Maskval, const _Elem *_First,
		const _Elem *_Last) const
		{	
		return (do_scan_is(_Maskval, _First, _Last));
		}

	const _Elem * scan_not(mask _Maskval, const _Elem *_First,
		const _Elem *_Last) const
		{	
		return (do_scan_not(_Maskval, _First, _Last));
		}

	_Elem  tolower(_Elem _Ch) const
		{	
		return (do_tolower(_Ch));
		}

	const _Elem * tolower(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_tolower(_First, _Last));
		}

	_Elem  toupper(_Elem _Ch) const
		{	
		return (do_toupper(_Ch));
		}

	const _Elem * toupper(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_toupper(_First, _Last));
		}

	_Elem  widen(char _Byte) const
		{	
		return (do_widen(_Byte));
		}

	const char * widen(const char *_First, const char *_Last,
		_Elem *_Dest) const
		{	
		return (do_widen(_First, _Last, _Dest));
		}

	char  narrow(_Elem _Ch, char _Dflt = '\0') const
		{	
		return (do_narrow(_Ch, _Dflt));
		}

	const _Elem * narrow(const _Elem *_First, const _Elem *_Last,
		char _Dflt, char *_Dest) const
		{	
		return (do_narrow(_First, _Last, _Dflt, _Dest));
		}

	 static locale::id id;

	explicit  ctype(size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		}

	 ctype(const _Locinfo& _Lobj, size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		_Init(_Lobj);
		}

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new ctype<_Elem>(
				_Locinfo(_Ploc->c_str()));
		return (2);
		}

protected:
	virtual  ~ctype()
		{	
		if (_Ctype._Delfl)
			free((void *)_Ctype._Table);
		}

	void  _Init(const _Locinfo& _Lobj)
		{	
		_Ctype = _Lobj._Getctype();
		_Cvt = _Lobj._Getcvt();
		}

	virtual bool  do_is(mask _Maskval, _Elem _Ch) const
		{	
		return ((:: _Getwctype(_Ch, &_Ctype) & _Maskval) != 0);
		}

	virtual const _Elem * do_is(const _Elem *_First,
		const _Elem *_Last, mask *_Dest) const
		{	
		;
		;
		return (:: _Getwctypes(_First, _Last, _Dest, &_Ctype));
		}

	virtual const _Elem * do_scan_is(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && !is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	virtual const _Elem * do_scan_not(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	virtual _Elem  do_tolower(_Elem _Ch) const
		{	
		return (_Towlower(_Ch, &_Ctype));
		}

	virtual const _Elem * do_tolower(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			*_First = _Towlower(*_First, &_Ctype);
		return ((const _Elem *)_First);
		}

	virtual _Elem  do_toupper(_Elem _Ch) const
		{	
		return (_Towupper(_Ch, &_Ctype));
		}

	virtual const _Elem * do_toupper(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			*_First = _Towupper(*_First, &_Ctype);
		return ((const _Elem *)_First);
		}

	_Elem  _Dowiden(char _Byte) const
		{	
		mbstate_t _Mbst = {0};
		wchar_t _Wc;
		return (_Mbrtowc(&_Wc, &_Byte, 1, &_Mbst, &_Cvt) < 0
			? (wchar_t)(wint_t)(0xFFFF) : _Wc);
		}

	virtual _Elem  do_widen(char _Byte) const
		{	
		return (_Dowiden(_Byte));
		}

	virtual const char * do_widen(const char *_First,
		const char *_Last, _Elem *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Dowiden(*_First);
		return (_First);
		}

	char  _Donarrow(_Elem _Ch, char _Dflt) const
		{	
		char _Buf[5];
		mbstate_t _Mbst = {0};
		return (_Wcrtomb(_Buf, _Ch, &_Mbst, &_Cvt) != 1
			? _Dflt : _Buf[0]);
		}

	virtual char  do_narrow(_Elem _Ch, char _Dflt) const
		{	
		return (_Donarrow(_Ch, _Dflt));
		}

	virtual const _Elem * do_narrow(const _Elem *_First,
		const _Elem *_Last, char _Dflt, char *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Donarrow(*_First, _Dflt);
		return (_First);
		}

private:
	_Locinfo::_Ctypevec _Ctype;	
	_Locinfo::_Cvtvec _Cvt;		
	};

 
		
template<>
	class  ctype<unsigned short>
	: public ctype_base
	{	
	typedef ctype<unsigned short> _Myt;

public:
	typedef unsigned short _Elem;
	typedef _Elem char_type;

	bool  is(mask _Maskval, _Elem _Ch) const
		{	
		return (do_is(_Maskval, _Ch));
		}

	const _Elem * is(const _Elem *_First, const _Elem *_Last,
		mask *_Dest) const
		{	
		return (do_is(_First, _Last, _Dest));
		}

	const _Elem * scan_is(mask _Maskval, const _Elem *_First,
		const _Elem *_Last) const
		{	
		return (do_scan_is(_Maskval, _First, _Last));
		}

	const _Elem * scan_not(mask _Maskval, const _Elem *_First,
		const _Elem *_Last) const
		{	
		return (do_scan_not(_Maskval, _First, _Last));
		}

	_Elem  tolower(_Elem _Ch) const
		{	
		return (do_tolower(_Ch));
		}

	const _Elem * tolower(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_tolower(_First, _Last));
		}

	_Elem  toupper(_Elem _Ch) const
		{	
		return (do_toupper(_Ch));
		}

	const _Elem * toupper(_Elem *_First, const _Elem *_Last) const
		{	
		return (do_toupper(_First, _Last));
		}

	_Elem  widen(char _Byte) const
		{	
		return (do_widen(_Byte));
		}

	const char * widen(const char *_First, const char *_Last,
		_Elem *_Dest) const
		{	
		return (do_widen(_First, _Last, _Dest));
		}

	char  narrow(_Elem _Ch, char _Dflt = '\0') const
		{	
		return (do_narrow(_Ch, _Dflt));
		}

	const _Elem * narrow(const _Elem *_First, const _Elem *_Last,
		char _Dflt, char *_Dest) const
		{	
		return (do_narrow(_First, _Last, _Dflt, _Dest));
		}

	 static locale::id id;

	explicit  ctype(size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		}

	 ctype(const _Locinfo& _Lobj, size_t _Refs = 0)
		: ctype_base(_Refs)
		{	
		_Init(_Lobj);
		}

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new ctype<_Elem>(
				_Locinfo(_Ploc->c_str()));
		return (2);
		}

protected:
	virtual  ~ctype()
		{	
		if (_Ctype._Delfl)
			free((void *)_Ctype._Table);
		}

	void  _Init(const _Locinfo& _Lobj)
		{	
		_Ctype = _Lobj._Getctype();
		_Cvt = _Lobj._Getcvt();
		}

	virtual bool  do_is(mask _Maskval, _Elem _Ch) const
		{	
		return ((:: _Getwctype(_Ch, &_Ctype) & _Maskval) != 0);
		}

	virtual const _Elem * do_is(const _Elem *_First,
		const _Elem *_Last, mask *_Dest) const
		{	
		;
		;
		return ((const _Elem *):: _Getwctypes((const wchar_t *)_First,
			(const wchar_t *)_Last, _Dest, &_Ctype));
		}

	virtual const _Elem * do_scan_is(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && !is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	virtual const _Elem * do_scan_not(mask _Maskval,
		const _Elem *_First, const _Elem *_Last) const
		{	
		;
		for (; _First != _Last && is(_Maskval, *_First); ++_First)
			;
		return (_First);
		}

	virtual _Elem  do_tolower(_Elem _Ch) const
		{	
		return (_Towlower(_Ch, &_Ctype));
		}

	virtual const _Elem * do_tolower(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			*_First = _Towlower(*_First, &_Ctype);
		return ((const _Elem *)_First);
		}

	virtual _Elem  do_toupper(_Elem _Ch) const
		{	
		return (_Towupper(_Ch, &_Ctype));
		}

	virtual const _Elem * do_toupper(_Elem *_First,
		const _Elem *_Last) const
		{	
		;
		for (; _First != _Last; ++_First)
			*_First = _Towupper(*_First, &_Ctype);
		return ((const _Elem *)_First);
		}

	_Elem  _Dowiden(char _Byte) const
		{	
		mbstate_t _Mbst = {0};
		unsigned short _Wc;
		return (_Mbrtowc((wchar_t *)&_Wc, &_Byte, 1, &_Mbst, &_Cvt) < 0
			? (unsigned short)(wint_t)(0xFFFF) : _Wc);
		}

	virtual _Elem  do_widen(char _Byte) const
		{	
		return (_Dowiden(_Byte));
		}

	virtual const char * do_widen(const char *_First,
		const char *_Last, _Elem *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Dowiden(*_First);
		return (_First);
		}

	char  _Donarrow(_Elem _Ch, char _Dflt) const
		{	
		char _Buf[5];
		mbstate_t _Mbst = {0};
		return (_Wcrtomb(_Buf, _Ch, &_Mbst, &_Cvt) != 1
			? _Dflt : _Buf[0]);
		}

	virtual char  do_narrow(_Elem _Ch, char _Dflt) const
		{	
		return (_Donarrow(_Ch, _Dflt));
		}

	virtual const _Elem * do_narrow(const _Elem *_First,
		const _Elem *_Last, char _Dflt, char *_Dest) const
		{	
		;
		;
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Donarrow(*_First, _Dflt);
		return (_First);
		}

private:
	_Locinfo::_Ctypevec _Ctype;	
	_Locinfo::_Cvtvec _Cvt;		
	};
 #line 2921 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

		
template<class _Elem>
	class ctype_byname
	: public ctype<_Elem>
	{	
public:
	explicit  ctype_byname(const char *_Locname, size_t _Refs = 0)
		: ctype<_Elem>(_Locinfo(_Locname), _Refs)
		{	
		}

 
	explicit  ctype_byname(const string& _Str, size_t _Refs = 0)
		: ctype<_Elem>(_Locinfo(_Str.c_str()), _Refs)
		{	
		}
 #line 2939 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

protected:
	virtual  ~ctype_byname()
		{	
		}
	};

		
template<>
	class ctype_byname<char>
	: public ctype<char>
	{	
public:
	explicit  ctype_byname(const char *_Locname, size_t _Refs = 0)
		: ctype<char>(_Locinfo(_Locname), _Refs)
		{	
		}

 
	explicit  ctype_byname(const string& _Str, size_t _Refs = 0)
		: ctype<char>(_Locinfo(_Str.c_str()), _Refs)
		{	
		}
 #line 2963 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"

protected:
	virtual  ~ctype_byname()
		{	
		}
	};

 



#line 2975 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
}

 

 #pragma warning(pop)
 #pragma pack(pop)

#line 2983 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"
#line 2984 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocale"






#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"

 
 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\system_error"

#pragma once



#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cerrno"

#pragma once











 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\errno.h"















#pragma once




#line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\crtdefs.h"














 








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\errno.h"


extern "C" {
#line 26 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\errno.h"



























































#line 86 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\errno.h"
#line 87 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\errno.h"
















































}
#line 137 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\errno.h"

#line 139 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\errno.h"
#line 15 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cerrno"
#line 16 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cerrno"





#line 22 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cerrno"
#line 23 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\cerrno"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\system_error"



 #pragma pack(push,8)
 #pragma warning(push,3)

 

 

#line 18 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\system_error"

namespace std {
		
	namespace errc {
enum errc {	
	address_family_not_supported = 102,
	address_in_use = 100,
	address_not_available = 101,
	already_connected = 113,
	argument_list_too_long = 7,
	argument_out_of_domain = 33,
	bad_address = 14,
	bad_file_descriptor = 9,
	bad_message = 104,
	broken_pipe = 32,
	connection_aborted = 106,
	connection_already_in_progress = 103,
	connection_refused = 107,
	connection_reset = 108,
	cross_device_link = 18,
	destination_address_required = 109,
	device_or_resource_busy = 16,
	directory_not_empty = 41,
	executable_format_error = 8,
	file_exists = 17,
	file_too_large = 27,
	filename_too_long = 38,
	function_not_supported = 40,
	host_unreachable = 110,
	identifier_removed = 111,
	illegal_byte_sequence = 42,
	inappropriate_io_control_operation = 25,
	interrupted = 4,
	invalid_argument = 22,
	invalid_seek = 29,
	io_error = 5,
	is_a_directory = 21,
	message_size = 115,
	network_down = 116,
	network_reset = 117,
	network_unreachable = 118,
	no_buffer_space = 119,
	no_child_process = 10,
	no_link = 121,
	no_lock_available = 39,
	no_message_available = 120,
	no_message = 122,
	no_protocol_option = 123,
	no_space_on_device = 28,
	no_stream_resources = 124,
	no_such_device_or_address = 6,
	no_such_device = 19,
	no_such_file_or_directory = 2,
	no_such_process = 3,
	not_a_directory = 20,
	not_a_socket = 128,
	not_a_stream = 125,
	not_connected = 126,
	not_enough_memory = 12,
	not_supported = 129,
	operation_canceled = 105,
	operation_in_progress = 112,
	operation_not_permitted = 1,
	operation_not_supported = 130,
	operation_would_block = 140,
	owner_dead = 133,
	permission_denied = 13,
	protocol_error = 134,
	protocol_not_supported = 135,
	read_only_file_system = 30,
	resource_deadlock_would_occur = 36,
	resource_unavailable_try_again = 11,
	result_out_of_range = 34,
	state_not_recoverable = 127,
	stream_timeout = 137,
	text_file_busy = 139,
	timed_out = 138,
	too_many_files_open_in_system = 23,
	too_many_files_open = 24,
	too_many_links = 31,
	too_many_synbolic_link_levels = 114,
	value_too_large = 132,
	wrong_protocol_type = 136
	};
	}	

typedef errc::errc generic_errno;

		
template<class _Enum>
	struct is_error_code_enum
		: public tr1::false_type
	{	
	};

		
template<class _Enum>
	struct is_error_condition_enum
		: public tr1::false_type
	{	
	};

template<>
	struct is_error_condition_enum<generic_errno>
		: public tr1::true_type
	{	
	};

		
	namespace io_errc {
enum io_errc {	
	stream = 1
	};
	}	

typedef io_errc::io_errc _Io_errc;

		
class error_code;
class error_condition;
class error_category;

 const error_category& __cdecl generic_category();
 const error_category& __cdecl iostream_category();
 const error_category& __cdecl system_category();

class error_category
	{	
public:
	typedef int value_type;

	error_category()
		{	
		}

	virtual ~error_category()
		{	
		}

	virtual const char *name() const = 0;

	virtual string message(value_type _Errval) const = 0;

	virtual error_condition default_error_condition(value_type _Errval) const;

	virtual bool equivalent(value_type _Errval,
		const error_condition& _Cond) const;

	virtual bool equivalent(const error_code& _Code,
		value_type _Errval) const;

	bool operator==(const error_category& _Right) const
		{	
		return (this == &_Right);
		}

	bool operator!=(const error_category& _Right) const
		{	
		return (!(*this == _Right));
		}

	bool operator<(const error_category& _Right) const
		{	
		return (this < &_Right);
		}

private:
	error_category(const error_category&);	

	error_category& operator=(const error_category&);	
	};

		
class error_code
	{	
public:
	typedef int value_type;

	error_code()
		: _Myval(0),
			_Mycat(&system_category())
		{	
		}

	error_code(value_type _Val, const error_category& _Cat)
		: _Myval(_Val), _Mycat(&_Cat)
		{	
		}

	template<class _Enum>
		error_code(_Enum _Errcode,
			typename tr1::enable_if<is_error_code_enum<_Enum>::value,
				error_code>::type * = 0)
		: _Myval(0), _Mycat(0)
		{	
		*this = make_error_code(_Errcode);	
		}

	void assign(value_type _Val, const error_category& _Cat)
		{	
		_Myval = _Val;
		_Mycat = &_Cat;
		}

	template<class _Enum>
		typename tr1::enable_if<is_error_code_enum<_Enum>::value,
			error_code>::type& operator=(_Enum _Errcode)
		{	
		*this = make_error_code(_Errcode);	
		return (*this);
		}

	void clear()
		{	
		_Myval = 0;
		_Mycat = &system_category();
		}

	value_type value() const
		{	
		return (_Myval);
		}

	const error_category& category() const
		{	
		return (*_Mycat);
		}

	error_condition default_error_condition() const;

	string message() const
		{	
		return (category().message(value()));
		}

	operator ::std:: _Bool_type() const
		{	
		return (value() != 0 ? (&::std:: _Bool_struct::_Member) : 0);
		}

	bool operator !() const
		{	
		return (value() == 0);
		}

	bool operator==(const error_code& _Right) const
		{	
		return (category() == _Right.category()
			&& value() == _Right.value());
		}

	bool operator!=(const error_code& _Right) const
		{	
		return (!(*this == _Right));
		}

	bool operator<(const error_code& _Right) const
		{	
		return (category() < _Right.category()
			|| category() == _Right.category()
				&& value() < _Right.value());
		}

private:
	value_type _Myval;	
	const error_category *_Mycat;	
	};

		
class error_condition
	{	
public:
	typedef int value_type;

	error_condition()
		: _Myval(0),
			_Mycat(&generic_category())
		{	
		}

	error_condition(value_type _Val, const error_category& _Cat)
		: _Myval(_Val), _Mycat(&_Cat)
		{	
		}

	template<class _Enum>
		error_condition(_Enum _Errcode,
			typename tr1::enable_if<is_error_condition_enum<_Enum>::value,
				error_condition>::type * = 0)
		: _Myval(0), _Mycat(0)
		{	
		*this = make_error_condition(_Errcode);	
		}

	void assign(value_type _Val, const error_category& _Cat)
		{	
		_Myval = _Val;
		_Mycat = &_Cat;
		}

	template<class _Enum>
		typename tr1::enable_if<is_error_condition_enum<_Enum>::value,
			error_condition>::type& operator=(_Enum _Errcode)
		{	
		*this = make_error_condition(_Errcode);	
		return (*this);
		}

	void clear()
		{	
		_Myval = 0;
		_Mycat = &generic_category();
		}

	value_type value() const
		{	
		return (_Myval);
		}

	const error_category& category() const
		{	
		return (*_Mycat);
		}

	string message() const
		{	
		return (category().message(value()));
		}

	operator ::std:: _Bool_type() const
		{	
		return (value() != 0 ? (&::std:: _Bool_struct::_Member) : 0);
		}

	bool operator !() const
		{	
		return (value() == 0);
		}

	bool operator==(const error_condition& _Right) const
		{	
		return (category() == _Right.category()
			&& value() == _Right.value());
		}

	bool operator!=(const error_condition& _Right) const
		{	
		return (!(*this == _Right));
		}

	bool operator<(const error_condition& _Right) const
		{	
		return (category() < _Right.category()
			|| category() == _Right.category()
				&& value() < _Right.value());
		}

private:
	value_type _Myval;	
	const error_category *_Mycat;	
	};

		
inline error_condition
	error_category::default_error_condition(value_type _Errval) const
	{	
	return (error_condition(_Errval, *this));
	}

inline bool
	error_category::equivalent(value_type _Errval,
		const error_condition& _Cond) const
	{	
	return (default_error_condition(_Errval) == _Cond);
	}

inline bool
	error_category::equivalent(const error_code& _Code,
		value_type _Errval) const
	{	
	return (*this == _Code.category() && _Code.value() == _Errval);
	}

		
inline error_condition error_code::default_error_condition() const
	{	
	return (category().default_error_condition(value()));
	}

		
inline bool operator==(
	const error_code& _Left,
	const error_condition& _Right)
	{	
	return (_Left.category().equivalent(_Left.value(), _Right)
		|| _Right.category().equivalent(_Left, _Right.value()));
	}

inline bool operator==(
	const error_condition& _Left,
	const error_code& _Right)
	{	
	return (_Right.category().equivalent(_Right.value(), _Left)
		|| _Left.category().equivalent(_Right, _Left.value()));
	}

		
inline bool operator!=(
	const error_code& _Left,
	const error_condition& _Right)
	{	
	return (!(_Left == _Right));
	}

inline bool operator!=(
	const error_condition& _Left,
	const error_code& _Right)
	{	
	return (!(_Left == _Right));
	}

		
inline error_code make_error_code(generic_errno _Errno)
	{	
	return (error_code(_Errno, generic_category()));
	}

inline error_code make_error_code(_Io_errc _Errno)
	{	
	return (error_code(_Errno, iostream_category()));
	}

		
inline error_condition make_error_condition(generic_errno _Errno)
	{	
	return (error_condition(_Errno, generic_category()));
	}

inline error_condition make_error_condition(_Io_errc _Errno)
	{	
	return (error_condition(_Errno, iostream_category()));
	}

		
template<class _Kty>
	class hash;

template<>
	class hash<::std:: error_code>
		: public unary_function<error_code, size_t>
	{	
public:
	typedef ::std:: error_code _Kty;

	size_t operator()(const _Kty& _Keyval) const
		{	
		ldiv_t _Qrem = :: ldiv((long)(size_t)_Keyval.value(), 127773);

		_Qrem.rem = 16807 * _Qrem.rem - 2836 * _Qrem.quot;
		if (_Qrem.rem < 0)
			_Qrem.rem += 2147483647;
		return ((size_t)_Qrem.rem);
		}
	};

template<>
	class hash<::std:: error_condition>
		: public unary_function<error_condition, size_t>
	{	
public:
	typedef ::std:: error_condition _Kty;

	size_t operator()(const _Kty& _Keyval) const
		{	
		ldiv_t _Qrem = :: ldiv((long)(size_t)_Keyval.value(), 127773);

		_Qrem.rem = 16807 * _Qrem.rem - 2836 * _Qrem.quot;
		if (_Qrem.rem < 0)
			_Qrem.rem += 2147483647;
		return ((size_t)_Qrem.rem);
		}
	};

		
class system_error
	: public runtime_error
	{	
public:
	explicit system_error(error_code _Errcode,
		const string& _Message = "")
		: runtime_error(_Message), _Mycode(_Errcode)
		{	
		_Makestr();
		}

	system_error(error_code _Errcode,
		const char *_Message)
		: runtime_error(_Message), _Mycode(_Errcode)
		{	
		_Makestr();
		}

	system_error(error_code::value_type _Errval,
		const error_category& _Errcat,
		const string& _Message = "")
		: runtime_error(_Message), _Mycode(_Errval, _Errcat)
		{	
		_Makestr();
		}

	system_error(error_code::value_type _Errval,
		const error_category& _Errcat,
		const char *_Message)
		: runtime_error(_Message), _Mycode(_Errval, _Errcat)
		{	
		_Makestr();
		}










	const error_code& code() const throw ()
		{	
		return (_Mycode);
		}

 

 





#line 559 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\system_error"

private:
	void _Makestr()
		{	




		}

	error_code _Mycode;	

	};
}
 #pragma warning(pop)
 #pragma pack(pop)

#line 577 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\system_error"
#line 578 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\system_error"





#line 10 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"
 #line 11 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"

 #line 1 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\share.h"












#pragma once






#line 21 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\share.h"














#line 36 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\share.h"

#line 38 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\share.h"
#line 13 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"

 #pragma pack(push,8)
 #pragma warning(push,3)

 #pragma warning(disable: 4412)

 

 
 

namespace std {
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 

 
 

 
 
 

		
template<class _Dummy>
	class _Iosb
	{	
public:
	enum _Dummy_enum {_Dummy_enum_val = 1};	
	enum _Fmtflags
		{	
		_Fmtmask = 0xffff, _Fmtzero = 0};

	static const _Fmtflags skipws = (_Fmtflags)0x0001;
	static const _Fmtflags unitbuf = (_Fmtflags)0x0002;
	static const _Fmtflags uppercase = (_Fmtflags)0x0004;
	static const _Fmtflags showbase = (_Fmtflags)0x0008;
	static const _Fmtflags showpoint = (_Fmtflags)0x0010;
	static const _Fmtflags showpos = (_Fmtflags)0x0020;
	static const _Fmtflags left = (_Fmtflags)0x0040;
	static const _Fmtflags right = (_Fmtflags)0x0080;
	static const _Fmtflags internal = (_Fmtflags)0x0100;
	static const _Fmtflags dec = (_Fmtflags)0x0200;
	static const _Fmtflags oct = (_Fmtflags)0x0400;
	static const _Fmtflags hex = (_Fmtflags)0x0800;
	static const _Fmtflags scientific = (_Fmtflags)0x1000;
	static const _Fmtflags fixed = (_Fmtflags)0x2000;

	static const _Fmtflags hexfloat =
		(_Fmtflags)0x3000;	

	static const _Fmtflags boolalpha = (_Fmtflags)0x4000;
	static const _Fmtflags _Stdio = (_Fmtflags)0x8000;
	static const _Fmtflags adjustfield = (_Fmtflags)(0x0040
		| 0x0080 | 0x0100);
	static const _Fmtflags basefield = (_Fmtflags)(0x0200
		| 0x0400 | 0x0800);
	static const _Fmtflags floatfield = (_Fmtflags)(0x1000
		| 0x2000);

	enum _Iostate
		{	
		_Statmask = 0x17};

	static const _Iostate goodbit = (_Iostate)0x0;
	static const _Iostate eofbit = (_Iostate)0x1;
	static const _Iostate failbit = (_Iostate)0x2;
	static const _Iostate badbit = (_Iostate)0x4;
	static const _Iostate _Hardfail = (_Iostate)0x10;

	enum _Openmode
		{	
		_Openmask = 0xff};

	static const _Openmode in = (_Openmode)0x01;
	static const _Openmode out = (_Openmode)0x02;
	static const _Openmode ate = (_Openmode)0x04;
	static const _Openmode app = (_Openmode)0x08;
	static const _Openmode trunc = (_Openmode)0x10;
	static const _Openmode _Nocreate = (_Openmode)0x40;
	static const _Openmode _Noreplace = (_Openmode)0x80;
	static const _Openmode binary = (_Openmode)0x20;

	enum _Seekdir
		{	
		_Seekmask = 0x3};

	static const _Seekdir beg = (_Seekdir)0;
	static const _Seekdir cur = (_Seekdir)1;
	static const _Seekdir end = (_Seekdir)2;

	enum
		{	
		_Openprot = 0x40};
	};

template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::skipws;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::unitbuf;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::uppercase;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::showbase;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::showpoint;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::showpos;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::left;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::right;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::internal;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::dec;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::oct;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::hex;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::scientific;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::fixed;

template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags
		_Iosb<_Dummy>::hexfloat;	

template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::boolalpha;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::_Stdio;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::adjustfield;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::basefield;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Fmtflags _Iosb<_Dummy>::floatfield;

template<class _Dummy>
	const typename _Iosb<_Dummy>::_Iostate _Iosb<_Dummy>::goodbit;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Iostate _Iosb<_Dummy>::eofbit;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Iostate _Iosb<_Dummy>::failbit;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Iostate _Iosb<_Dummy>::badbit;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Iostate _Iosb<_Dummy>::_Hardfail;

template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::in;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::out;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::ate;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::app;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::trunc;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::_Nocreate;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::_Noreplace;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Openmode _Iosb<_Dummy>::binary;

template<class _Dummy>
	const typename _Iosb<_Dummy>::_Seekdir _Iosb<_Dummy>::beg;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Seekdir _Iosb<_Dummy>::cur;
template<class _Dummy>
	const typename _Iosb<_Dummy>::_Seekdir _Iosb<_Dummy>::end;

		
class  ios_base
	: public _Iosb<int>
	{	
public:
	typedef int fmtflags;
	typedef int iostate;
	typedef int openmode;
	typedef int seekdir;

	typedef ::std:: streamoff streamoff;
	typedef ::std:: streampos streampos;

	enum event
		{	
		erase_event, imbue_event, copyfmt_event};

	typedef void (__cdecl *event_callback)(event, ios_base&, int);
	typedef unsigned int io_state, open_mode, seek_dir;

			
	class failure

 
		: public system_error
		{	
	public:
		explicit failure(const string &_Message,
			const error_code& _Errcode = make_error_code(io_errc::stream))
			: system_error(_Errcode, _Message)
			{	
			}

		explicit failure(const char *_Message,
			const error_code& _Errcode = make_error_code(io_errc::stream))
			: system_error(_Errcode, _Message)
			{	
			}

 












#line 254 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"

 

 





#line 264 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"
		};

			
	class  Init
		{	
	public:
		 Init()
			{	
			_Init_ctor(this);
			}

		 ~Init()
			{	
			_Init_dtor(this);
			}

	private:
		static  void __cdecl _Init_ctor(Init *);
		static  void __cdecl _Init_dtor(Init *);

		 static int _Init_cnt;	

		static  int& __cdecl _Init_cnt_func();
		};

	ios_base&  operator=(const ios_base& _Right)
		{	
		if (this != &_Right)
			{	
			_Mystate = _Right._Mystate;
			copyfmt(_Right);
			}
		return (*this);
		}

	 operator void *() const
		{	
		return (fail() ? 0 : (void *)this);
		}

	bool  operator!() const
		{	
		return (fail());
		}

	void  clear(iostate _State, bool _Reraise)
		{	
		_Mystate = (iostate)(_State & _Statmask);
		if ((_Mystate & _Except) == 0)
			;
		else if (_Reraise)
			throw;
		else if (_Mystate & _Except & badbit)
			throw failure("ios_base::badbit set");
		else if (_Mystate & _Except & failbit)
			throw failure("ios_base::failbit set");
		else
			throw failure("ios_base::eofbit set");
		}

	void  clear(iostate _State = goodbit)
		{	
		clear(_State, false);
		}

	void  clear(io_state _State)
		{	
		clear((iostate)_State);
		}

	iostate  rdstate() const
		{	
		return (_Mystate);
		}

	void  setstate(iostate _State, bool _Exreraise)
		{	
		if (_State != goodbit)
			clear((iostate)((int)rdstate() | (int)_State), _Exreraise);
		}

	void  setstate(iostate _State)
		{	
		if (_State != goodbit)
			clear((iostate)((int)rdstate() | (int)_State), false);
		}

	void  setstate(io_state _State)
		{	
		setstate((iostate)_State);
		}

	bool  good() const
		{	
		return (rdstate() == goodbit);
		}

	bool  eof() const
		{	
		return ((int)rdstate() & (int)eofbit);
		}

	bool  fail() const
		{	
		return (((int)rdstate()
			& ((int)badbit | (int)failbit)) != 0);
		}

	bool  bad() const
		{	
		return (((int)rdstate() & (int)badbit) != 0);
		}

	iostate  exceptions() const
		{	
		return (_Except);
		}

	void  exceptions(iostate _Newexcept)
		{	
		_Except = (iostate)((int)_Newexcept & (int)_Statmask);
		clear(_Mystate);
		}

	void  exceptions(io_state _State)
		{	
		exceptions((iostate)_State);
		}

	fmtflags  flags() const
		{	
		return (_Fmtfl);
		}

	fmtflags  flags(fmtflags _Newfmtflags)
		{	
		fmtflags _Oldfmtflags = _Fmtfl;
		_Fmtfl = (fmtflags)((int)_Newfmtflags & (int)_Fmtmask);
		return (_Oldfmtflags);
		}

	fmtflags  setf(fmtflags _Newfmtflags)
		{	
		ios_base::fmtflags _Oldfmtflags = _Fmtfl;
		_Fmtfl = (fmtflags)((int)_Fmtfl
			| (int)_Newfmtflags & (int)_Fmtmask);
		return (_Oldfmtflags);
		}

	fmtflags  setf(fmtflags _Newfmtflags, fmtflags _Mask)
		{	
		ios_base::fmtflags _Oldfmtflags = _Fmtfl;
		_Fmtfl = (fmtflags)(((int)_Fmtfl & (int)~_Mask)
			| ((int)_Newfmtflags & (int)_Mask & (int)_Fmtmask));
		return (_Oldfmtflags);
		}

	void  unsetf(fmtflags _Mask)
		{	
		_Fmtfl = (fmtflags)((int)_Fmtfl & (int)~_Mask);
		}

	streamsize  precision() const
		{	
		return (_Prec);
		}

	streamsize  precision(streamsize _Newprecision)
		{	
		streamsize _Oldprecision = _Prec;
		_Prec = _Newprecision;
		return (_Oldprecision);
		}

	streamsize  width() const
		{	
		return (_Wide);
		}

	streamsize  width(streamsize _Newwidth)
		{	
		streamsize _Oldwidth = _Wide;
		_Wide = _Newwidth;
		return (_Oldwidth);
		}

	locale  getloc() const
		{	
		return (*_Ploc);
		}

	locale  imbue(const locale& _Loc)
		{	
		locale _Oldlocale = *_Ploc;
		*_Ploc = _Loc;
		_Callfns(imbue_event);
		return (_Oldlocale);
		}

	static int __cdecl xalloc()
		{	
		{ ::std:: _Lockit _Lock(2);	
			return (_Index++);
		}
		}

	long&  iword(int _Idx)
		{	
		return (_Findarr(_Idx)._Lo);
		}

	void *&  pword(int _Idx)
		{	
		return (_Findarr(_Idx)._Vp);
		}

	void  register_callback(event_callback _Pfn,
		int _Idx)
		{	
		_Calls = new _Fnarray(_Idx, _Pfn, _Calls);
		}

	ios_base&  copyfmt(const ios_base& _Other)
		{	
		if (this != &_Other)
			{	
			_Tidy();
			*_Ploc = *_Other._Ploc;
			_Fmtfl = _Other._Fmtfl;
			_Prec = _Other._Prec;
			_Wide = _Other._Wide;
			_Iosarray *_Ptr = _Other._Arr;

			for (_Arr = 0; _Ptr != 0; _Ptr = _Ptr->_Next)
				if (_Ptr->_Lo != 0 || _Ptr->_Vp != 0)
					{	
					iword(_Ptr->_Index) = _Ptr->_Lo;
					pword(_Ptr->_Index) = _Ptr->_Vp;
					}

			for (_Fnarray *_Pfa = _Other._Calls; _Pfa != 0;
				_Pfa = _Pfa->_Next)
				register_callback(_Pfa->_Pfn, _Pfa->_Index);

			_Callfns(copyfmt_event);	
			exceptions(_Other._Except);	
			}
		return (*this);
		}

	static bool __cdecl sync_with_stdio(bool _Newsync = true)
		{	
		{ ::std:: _Lockit _Lock(2);	
			const bool _Oldsync = _Sync;
			_Sync = _Newsync;
			return (_Oldsync);
		}
		}

	void  swap(ios_base& _Right)
		{	
		if (this != &_Right)
			{	
			::std:: swap(_Mystate, _Right._Mystate);
			::std:: swap(_Except, _Right._Except);
			::std:: swap(_Fmtfl, _Right._Fmtfl);
			::std:: swap(_Prec, _Right._Prec);
			::std:: swap(_Wide, _Right._Wide);

			::std:: swap(_Arr, _Right._Arr);
			::std:: swap(_Calls, _Right._Calls);
			::std:: swap(_Ploc, _Right._Ploc);
			}
		}

	virtual  ~ios_base()	
		{	
		_Ios_base_dtor(this);
		}

	static  void __cdecl _Addstd(ios_base *);	

	size_t _Stdstr;	

protected:
	 ios_base()
		{	
		}

	void  _Init()
		{	
		_Ploc = 0;
		_Stdstr = 0;
		_Except = goodbit;
		_Fmtfl = (fmtflags)(skipws | dec);
		_Prec = 6;
		_Wide = 0;
		_Arr = 0;
		_Calls = 0;
		clear(goodbit);
		_Ploc = new locale;
		}

private:
			
	struct _Iosarray
		{	
	public:
		 _Iosarray(int _Idx, _Iosarray *_Link)
			: _Next(_Link), _Index(_Idx), _Lo(0), _Vp(0)
			{	
			}

		_Iosarray *_Next;	
		int _Index;	
		long _Lo;	
		void *_Vp;	
		};

			
	struct _Fnarray
		{	
		 _Fnarray(int _Idx, event_callback _Pnew, _Fnarray *_Link)
			: _Next(_Link), _Index(_Idx), _Pfn(_Pnew)
			{	
			}

		_Fnarray *_Next;	
		int _Index;	
		event_callback _Pfn;	
		};

	void  _Callfns(event _Ev)
		{	
		for (_Fnarray *_Pfa = _Calls; _Pfa != 0; _Pfa = _Pfa->_Next)
			(*_Pfa->_Pfn)(_Ev, *this, _Pfa->_Index);
		}

	_Iosarray&  _Findarr(int _Idx)
		{	
		_Iosarray *_Ptr1, *_Ptr2;

		for (_Ptr1 = _Arr, _Ptr2 = 0; _Ptr1 != 0; _Ptr1 = _Ptr1->_Next)
			if (_Ptr1->_Index == _Idx)
				return (*_Ptr1);	
			else if (_Ptr2 == 0 && _Ptr1->_Lo == 0 && _Ptr1->_Vp == 0)
				_Ptr2 = _Ptr1;	

		if (_Ptr2 != 0)
			{	
			_Ptr2->_Index = _Idx;
			return (*_Ptr2);
			}

		_Arr = new _Iosarray(_Idx, _Arr);	
		return (*_Arr);
		}

	void  _Tidy()
		{	
		_Callfns(erase_event);
		_Iosarray *_Ptr1, *_Ptr2;

		for (_Ptr1 = _Arr; _Ptr1 != 0; _Ptr1 = _Ptr2)
			{	
			_Ptr2 = _Ptr1->_Next;
			delete (_Ptr1);
			}
		_Arr = 0;

		_Fnarray *_Pfa1, *_Pfa2;
		for (_Pfa1 = _Calls; _Pfa1 != 0; _Pfa1 = _Pfa2)
			{	
			_Pfa2 = _Pfa1->_Next;
			delete (_Pfa1);
			}
		_Calls = 0;
		}

	iostate _Mystate;	
	iostate _Except;	
	fmtflags _Fmtfl;	
	streamsize _Prec;	
	streamsize _Wide;	
	_Iosarray *_Arr;	
	_Fnarray *_Calls;	
	locale *_Ploc;	

	 static int _Index;
	 static bool _Sync;

	static  void __cdecl _Ios_base_dtor(ios_base *);
	};





}

 

 #pragma warning(pop)
 #pragma pack(pop)

#line 670 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"
#line 671 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xiosbase"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\streambuf"

 #pragma pack(push,8)
 #pragma warning(push,3)

 
 

namespace std {
		
template<class _Elem,
	class _Traits>
	class basic_streambuf
	{	
	typedef basic_streambuf<_Elem, _Traits> _Myt;

protected:
	 basic_streambuf()
		: _Plocale(new locale)
		{	
		_Init();
		}

	 basic_streambuf(_Uninitialized)
		: _Mylock(_Noinit)
		{	
		}

	 basic_streambuf(const _Myt& _Right)
		: _Plocale(new locale(_Right.getloc()))
		{	
		_Init();
		setp(_Right.pbase(), _Right.pptr(), _Right.epptr());
		setg(_Right.eback(), _Right.gptr(), _Right.egptr());
		}

	_Myt&  operator=(const _Myt& _Right)
		{	
		if (this != &_Right)
			{	
			setp(_Right.pbase(), _Right.pptr(), _Right.epptr());
			setg(_Right.eback(), _Right.gptr(), _Right.egptr());
			pubimbue(_Right.getloc());
			}
		return (*this);
		}

	void  swap(_Myt& _Right)
		{	
		if (this != &_Right)
			{	
			_Elem *_Tfirst = pbase();
			_Elem *_Tnext = pptr();
			_Elem *_Tend = epptr();
			setp(_Right.pbase(), _Right.pptr(), _Right.epptr());
			_Right.setp(_Tfirst, _Tnext, _Tend);

			_Tfirst = eback();
			_Tnext = gptr();
			_Tend = egptr();
			setg(_Right.eback(), _Right.gptr(), _Right.egptr());
			_Right.setg(_Tfirst, _Tnext, _Tend);

			locale _Oldlocale = pubimbue(_Right.getloc());
			_Right.pubimbue(_Oldlocale);
			}
		}

public:
	typedef _Elem char_type;
	typedef _Traits traits_type;

	virtual  ~basic_streambuf()
		{	
		delete (_Plocale);
		}

	typedef typename _Traits::int_type int_type;
	typedef typename _Traits::pos_type pos_type;
	typedef typename _Traits::off_type off_type;

	pos_type  pubseekoff(off_type _Off,
		ios_base::seekdir _Way,
		ios_base::openmode _Mode = ios_base::in | ios_base::out)
		{	
		return (seekoff(_Off, _Way, _Mode));
		}

	pos_type  pubseekoff(off_type _Off,
		ios_base::seek_dir _Way,
		ios_base::open_mode _Mode)
		{	
		return (pubseekoff(_Off, (ios_base::seekdir)_Way,
			(ios_base::openmode)_Mode));
		}

	pos_type  pubseekpos(pos_type _Pos,
		ios_base::openmode _Mode = ios_base::in | ios_base::out)
		{	
		return (seekpos(_Pos, _Mode));
		}

	pos_type  pubseekpos(pos_type _Pos,
		ios_base::open_mode _Mode)
		{	
		return (seekpos(_Pos, (ios_base::openmode)_Mode));
		}

	_Myt * pubsetbuf(_Elem *_Buffer,
		streamsize _Count)
		{	
		return (setbuf(_Buffer, _Count));
		}

	locale  pubimbue(const locale &_Newlocale)
		{	
		locale _Oldlocale = *_Plocale;
		imbue(_Newlocale);
		*_Plocale = _Newlocale;
		return (_Oldlocale);
		}

	locale  getloc() const
		{	
		return (*_Plocale);
		}

	streamsize  in_avail()
		{	
		streamsize _Res = _Gnavail();
		return (0 < _Res ? _Res : showmanyc());
		}

	int  pubsync()
		{	
		return (sync());
		}

	int_type  sbumpc()
		{	
		return (0 < _Gnavail()
			? _Traits::to_int_type(*_Gninc()) : uflow());
		}

	int_type  sgetc()
		{	
		return (0 < _Gnavail()
			? _Traits::to_int_type(*gptr()) : underflow());
		}

	streamsize  sgetn(_Elem *_Ptr,
		streamsize _Count)
		{	
		return (xsgetn(_Ptr, _Count));
		}

	int_type  snextc()
		{	
		return (1 < _Gnavail()
			? _Traits::to_int_type(*_Gnpreinc())
			: _Traits::eq_int_type(_Traits::eof(), sbumpc())
				? _Traits::eof() : sgetc());
		}

	int_type  sputbackc(_Elem _Ch)
		{	
		return (gptr() != 0 && eback() < gptr()
			&& _Traits::eq(_Ch, gptr()[-1])
			? _Traits::to_int_type(*_Gndec())
			: pbackfail(_Traits::to_int_type(_Ch)));
		}

	void  stossc()
		{	
		if (0 < _Gnavail())
			_Gninc();
		else
			uflow();
		}

	int_type  sungetc()
		{	
		return (gptr() != 0 && eback() < gptr()
			? _Traits::to_int_type(*_Gndec()) : pbackfail());
		}

	int_type  sputc(_Elem _Ch)
		{	
		return (0 < _Pnavail()
			? _Traits::to_int_type(*_Pninc() = _Ch)
			: overflow(_Traits::to_int_type(_Ch)));
		}

	streamsize  sputn(const _Elem *_Ptr,
		streamsize _Count)
		{	
		return (xsputn(_Ptr, _Count));
		}

	virtual void  _Lock()
		{	
		_Mylock._Lock();
		}

	virtual void  _Unlock()
		{	
		_Mylock._Unlock();
		}

protected:
	_Elem * eback() const
		{	
		return (*_IGfirst);
		}

	_Elem * gptr() const
		{	
		return (*_IGnext);
		}

	_Elem * pbase() const
		{	
		return (*_IPfirst);
		}

	_Elem * pptr() const
		{	
		return (*_IPnext);
		}

	_Elem * egptr() const
		{	
		return (*_IGnext + *_IGcount);
		}

	void  gbump(int _Off)
		{	
		*_IGcount -= _Off;
		*_IGnext += _Off;
		}

	void  setg(_Elem *_First, _Elem *_Next, _Elem *_Last)
		{	
		*_IGfirst = _First;
		*_IGnext = _Next;
		*_IGcount = (int)(_Last - _Next);
		}

	_Elem * epptr() const
		{	
		return (*_IPnext + *_IPcount);
		}

	_Elem * _Gndec()
		{	
		++*_IGcount;
		return (--*_IGnext);
		}

	_Elem * _Gninc()
		{	
		--*_IGcount;
		return ((*_IGnext)++);
		}

	_Elem * _Gnpreinc()
		{	
		--*_IGcount;
		return (++(*_IGnext));
		}

	streamsize  _Gnavail() const
		{	
		return (*_IGnext != 0 ? *_IGcount : 0);
		}

	void  pbump(int _Off)
		{	
		*_IPcount -= _Off;
		*_IPnext += _Off;
		}

	void  setp(_Elem *_First, _Elem *_Last)
		{	
		*_IPfirst = _First;
		*_IPnext = _First;
		*_IPcount = (int)(_Last - _First);
		}

	void  setp(_Elem *_First, _Elem *_Next, _Elem *_Last)
		{	
		*_IPfirst = _First;
		*_IPnext = _Next;
		*_IPcount = (int)(_Last - _Next);
		}

	_Elem * _Pninc()
		{	
		--*_IPcount;
		return ((*_IPnext)++);
		}

	streamsize  _Pnavail() const
		{	
		return (*_IPnext != 0 ? *_IPcount : 0);
		}

	void  _Init()
		{	
		_IGfirst = &_Gfirst;
		_IPfirst = &_Pfirst;
		_IGnext = &_Gnext;
		_IPnext = &_Pnext;
		_IGcount = &_Gcount;
		_IPcount = &_Pcount;
		setp(0, 0);
		setg(0, 0, 0);
		}

	void  _Init(_Elem **_Gf, _Elem **_Gn, int *_Gc,
		_Elem **_Pf, _Elem **_Pn, int *_Pc)
		{	
		_IGfirst = _Gf;
		_IPfirst = _Pf;
		_IGnext = _Gn;
		_IPnext = _Pn;
		_IGcount = _Gc;
		_IPcount = _Pc;
		}

	virtual int_type  overflow(int_type = _Traits::eof())
		{	
		return (_Traits::eof());
		}

	virtual int_type  pbackfail(int_type = _Traits::eof())
		{	
		return (_Traits::eof());
		}

	virtual streamsize  showmanyc()
		{	
		return (0);
		}

	virtual int_type  underflow()
		{	
		return (_Traits::eof());
		}

	virtual int_type  uflow()
		{	
		return (_Traits::eq_int_type(_Traits::eof(), underflow())
			? _Traits::eof() : _Traits::to_int_type(*_Gninc()));
		}

	virtual streamsize  xsgetn(_Elem * _Ptr,
		streamsize _Count)
		{	
		int_type _Meta;
		streamsize _Size, _Copied;

		for (_Copied = 0; 0 < _Count; )
			if (0 < (_Size = _Gnavail()))
				{	
				if (_Count < _Size)
					_Size = _Count;
				_Traits::copy(_Ptr, gptr(), (size_t)_Size);
				_Ptr += _Size;
				_Copied += _Size;
				_Count -= _Size;
				gbump((int)_Size);
				}
			else if (_Traits::eq_int_type(_Traits::eof(), _Meta = uflow()))
				break;	
			else
				{	
				*_Ptr++ = _Traits::to_char_type(_Meta);
				++_Copied;
				--_Count;
				}

		return (_Copied);
		}

	virtual streamsize  xsputn(const _Elem *_Ptr,
		streamsize _Count)
		{	
		streamsize _Size, _Copied;

		for (_Copied = 0; 0 < _Count; )
			if (0 < (_Size = _Pnavail()))
				{	
				if (_Count < _Size)
					_Size = _Count;
				_Traits::copy(pptr(), _Ptr, (size_t)_Size);
				_Ptr += _Size;
				_Copied += _Size;
				_Count -= _Size;
				pbump((int)_Size);
				}
			else if (_Traits::eq_int_type(_Traits::eof(),
				overflow(_Traits::to_int_type(*_Ptr))))
				break;	
			else
				{	
				++_Ptr;
				++_Copied;
				--_Count;
				}

		return (_Copied);
		}

	virtual pos_type  seekoff(off_type,
		ios_base::seekdir,
		ios_base::openmode = ios_base::in | ios_base::out)
		{	
		return (streampos(_BADOFF));
		}

	virtual pos_type  seekpos(pos_type,
		ios_base::openmode = ios_base::in | ios_base::out)
		{	
		return (streampos(_BADOFF));
		}

	virtual _Myt * setbuf(_Elem *, streamsize)
		{	
		return (this);
		}

	virtual int  sync()
		{	
		return (0);
		}

	virtual void  imbue(const locale&)
		{	
		}

private:
	_Mutex _Mylock;	
	_Elem *_Gfirst;	
	_Elem *_Pfirst;	
	_Elem **_IGfirst;	
	_Elem **_IPfirst;	
	_Elem *_Gnext;	
	_Elem *_Pnext;	
	_Elem **_IGnext;	
	_Elem **_IPnext;	

	int _Gcount;	
	int _Pcount;	
	int *_IGcount;	
	int *_IPcount;	

	locale *_Plocale;	
	};

 





#line 473 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\streambuf"

		
template<class _Elem,
	class _Traits>
	class istreambuf_iterator
		: public iterator<input_iterator_tag,
			_Elem, typename _Traits::off_type, _Elem *, _Elem&>
	{	
	typedef istreambuf_iterator<_Elem, _Traits> _Myt;
public:
	typedef _Elem char_type;
	typedef _Traits traits_type;
	typedef basic_streambuf<_Elem, _Traits> streambuf_type;
	typedef basic_istream<_Elem, _Traits> istream_type;

	typedef typename traits_type::int_type int_type;

	istreambuf_iterator(streambuf_type *_Sb = 0) throw ()
		: _Strbuf(_Sb), _Got(_Sb == 0)
		{	
		}

	istreambuf_iterator(istream_type& _Istr) throw ()
		: _Strbuf(_Istr.rdbuf()), _Got(_Istr.rdbuf() == 0)
		{	
		}

	_Elem operator*() const
		{	
		if (!_Got)
			_Peek();

 


#line 509 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\streambuf"

		return (_Val);
		}

	_Myt& operator++()
		{	
 


#line 519 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\streambuf"

		_Inc();
		return (*this);
		}

	_Myt operator++(int)
		{	
		if (!_Got)
			_Peek();
		_Myt _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	bool equal(const _Myt& _Right) const
		{	
		if (!_Got)
			_Peek();
		if (!_Right._Got)
			_Right._Peek();
		return (_Strbuf == 0 && _Right._Strbuf == 0
			|| _Strbuf != 0 && _Right._Strbuf != 0);
		}

private:
	void _Inc()
		{	
		if (_Strbuf == 0
			|| traits_type::eq_int_type(traits_type::eof(),
				_Strbuf->sbumpc()))
			_Strbuf = 0, _Got = true;
		else
			_Got = false;
		}

	_Elem _Peek() const
		{	
		int_type _Meta;
		if (_Strbuf == 0
			|| traits_type::eq_int_type(traits_type::eof(),
				_Meta = _Strbuf->sgetc()))
			_Strbuf = 0;
		else
			_Val = traits_type::to_char_type(_Meta);
		_Got = true;
		return (_Val);
		}

	mutable streambuf_type *_Strbuf;	
	mutable bool _Got;	
	mutable _Elem _Val;	
	};

template<class _Elem,
	class _Traits>
	struct _Is_checked_helper<istreambuf_iterator<_Elem, _Traits> >
	: public ::std:: tr1::true_type
	{	
	};

		
template<class _Elem,
	class _Traits> inline
	bool  operator==(
		const istreambuf_iterator<_Elem, _Traits>& _Left,
		const istreambuf_iterator<_Elem, _Traits>& _Right)
	{	
	return (_Left.equal(_Right));
	}

template<class _Elem,
	class _Traits> inline
	bool  operator!=(
		const istreambuf_iterator<_Elem, _Traits>& _Left,
		const istreambuf_iterator<_Elem, _Traits>& _Right)
	{	
	return (!(_Left == _Right));
	}

		
template<class _Elem,
	class _Traits>
	class ostreambuf_iterator
		: public _Outit
	{	
	typedef ostreambuf_iterator<_Elem, _Traits> _Myt;
public:
	typedef _Elem char_type;
	typedef _Traits traits_type;
	typedef basic_streambuf<_Elem, _Traits> streambuf_type;
	typedef basic_ostream<_Elem, _Traits> ostream_type;

	ostreambuf_iterator(streambuf_type *_Sb) throw ()
		: _Failed(false), _Strbuf(_Sb)
		{	
		}

	ostreambuf_iterator(ostream_type& _Ostr) throw ()
		: _Failed(false), _Strbuf(_Ostr.rdbuf())
		{	
		}

	_Myt& operator=(_Elem _Right)
		{	
		if (_Strbuf == 0
			|| traits_type::eq_int_type(_Traits::eof(),
				_Strbuf->sputc(_Right)))
			_Failed = true;
		return (*this);
		}

	_Myt& operator*()
		{	
		return (*this);
		}

	_Myt& operator++()
		{	
		return (*this);
		}

	_Myt& operator++(int)
		{	
		return (*this);
		}

	bool failed() const throw ()
		{	
		return (_Failed);
		}

private:
	bool _Failed;	
	streambuf_type *_Strbuf;	
	};

template<class _Elem,
	class _Traits>
	struct _Is_checked_helper<ostreambuf_iterator<_Elem, _Traits> >
	: public ::std:: tr1::true_type
	{	
	};
}

 

 #pragma warning(pop)
 #pragma pack(pop)

#line 669 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\streambuf"
#line 670 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\streambuf"





#line 11 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

 #pragma pack(push,8)
 #pragma warning(push,3)

 
 

 #pragma warning(disable: 4189 4275)

		


 
extern "C" {
 #line 26 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

extern  float __cdecl _Stofx(const char *,
	    char **,
	long, int *);
extern  double __cdecl _Stodx(const char *,
	    char **,
	long, int *);
extern  long double __cdecl _Stoldx(const char *,
	    char **,
	long, int *);
extern  long __cdecl _Stolx(const char *,
	    char **,
	int, int *);
extern  unsigned long __cdecl _Stoulx(const char *,
	    char **,
	int, int *);
extern  __int64 __cdecl _Stollx(const char *,
	    char **,
	int, int *);
extern  unsigned __int64 __cdecl _Stoullx(const char *,
	    char **,
	int, int *);

 
}
 #line 52 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"


namespace std {
		
template<class _Elem>
	class numpunct
		: public locale::facet
	{	
public:
	typedef basic_string<_Elem, char_traits<_Elem>, allocator<_Elem> >
		string_type;
	typedef _Elem char_type;

	  static locale::id id;	

	_Elem decimal_point() const
		{	
		return (do_decimal_point());
		}

	_Elem thousands_sep() const
		{	
		return (do_thousands_sep());
		}

	string grouping() const
		{	
		return (do_grouping());
		}

	string_type falsename() const
		{	
		return (do_falsename());
		}

	string_type truename() const
		{	
		return (do_truename());
		}

	explicit numpunct(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
			if (_Kseparator == 0)
				_Kseparator =	
					_Maklocchr(',', (_Elem *)0, _Lobj._Getcvt());
		}
		}

	numpunct(const _Locinfo& _Lobj, size_t _Refs = 0, bool _Isdef = false)
		: locale::facet(_Refs)
		{	
		_Init(_Lobj, _Isdef);
		}

	static size_t _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new numpunct<_Elem>(
				_Locinfo(_Ploc->c_str()), 0, true);
		return (4);
		}

protected:
	virtual  ~numpunct()
		{	
		_Tidy();
		}

	numpunct(const char *_Locname, size_t _Refs = 0, bool _Isdef = false)
		: locale::facet(_Refs)
		{	
		{ _Locinfo _Lobj(_Locname);
			_Init(_Lobj, _Isdef);
		}
		}

	void _Init(const _Locinfo& _Lobj, bool _Isdef = false)
		{	
		const lconv *_Ptr = _Lobj._Getlconv();

		_Grouping = 0;
		_Falsename = 0;
		_Truename = 0;

		try {
		_Grouping = _Maklocstr(_Isdef ? "" : _Ptr->grouping, (char *)0, _Lobj._Getcvt());
#line 143 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"
		_Falsename = _Maklocstr(_Lobj._Getfalse(), (_Elem *)0, _Lobj._Getcvt());
		_Truename = _Maklocstr(_Lobj._Gettrue(), (_Elem *)0, _Lobj._Getcvt());
		} catch (...) {
		_Tidy();
		throw;
		}

		_Dp = _Maklocchr(_Ptr->decimal_point[0], (_Elem *)0, _Lobj._Getcvt());
		_Kseparator =
			_Maklocchr(_Ptr->thousands_sep[0], (_Elem *)0, _Lobj._Getcvt());

		if (_Isdef)
			{	

			_Dp = _Maklocchr('.', (_Elem *)0, _Lobj._Getcvt());
			_Kseparator = _Maklocchr(',', (_Elem *)0, _Lobj._Getcvt());
			}
		}

	virtual _Elem  do_decimal_point() const
		{	
		return (_Dp);
		}

	virtual _Elem  do_thousands_sep() const
		{	
		return (_Kseparator);
		}

	virtual string  do_grouping() const
		{	
		return (string(_Grouping));
		}

	virtual string_type  do_falsename() const
		{	
		return (string_type(_Falsename));
		}

	virtual string_type  do_truename() const
		{	
		return (string_type(_Truename));
		}

private:
	void _Tidy()
		{	
		delete[] ((void *)_Grouping);
		delete[] ((void *)_Falsename);
		delete[] ((void *)_Truename);
		}

	const char *_Grouping;	
	_Elem _Dp;	
	_Elem _Kseparator;	
	const _Elem *_Falsename;	
	const _Elem *_Truename;	
	};

		
template<class _Elem>
	class numpunct_byname
		: public numpunct<_Elem>
	{	
public:
	explicit numpunct_byname(const char *_Locname, size_t _Refs = 0)
		: numpunct<_Elem>(_Locname, _Refs)
		{	
		}

 
	explicit numpunct_byname(const string& _Str, size_t _Refs = 0)
		: numpunct<_Elem>(_Str.c_str(), _Refs)
		{	
		}
 #line 219 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

protected:
	virtual  ~numpunct_byname()
		{	
		}
	};

		
template<class _Elem>
	 locale::id numpunct<_Elem>::id;

		
template<class _Elem,
	class _InIt = istreambuf_iterator<_Elem, char_traits<_Elem> > >
	class num_get
		: public locale::facet
	{	
public:
	typedef numpunct<_Elem> _Mypunct;
	typedef basic_string<_Elem, char_traits<_Elem>, allocator<_Elem> >
		_Mystr;

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new num_get<_Elem, _InIt>(
				_Locinfo(_Ploc->c_str()));
		return (4);
		}

	 static locale::id id;	

protected:
	virtual  ~num_get()
		{	
		}

	void _Init(const _Locinfo& _Lobj)
		{	
		_Cvt = _Lobj._Getcvt();
		}

	_Locinfo::_Cvtvec _Cvt;		

public:
	explicit  num_get(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		}

	 num_get(const _Locinfo& _Lobj, size_t _Refs = 0)
		: locale::facet(_Refs)
		{	
		_Init(_Lobj);
		}

	typedef _Elem char_type;
	typedef _InIt iter_type;

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase,	ios_base::iostate& _State,
			_Bool& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase,	ios_base::iostate& _State,
			unsigned short& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase,	ios_base::iostate& _State,
			unsigned int& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned long& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

 
	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			__int64& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned __int64& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}
 #line 332 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			float& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			double& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long double& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

	_InIt  get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			void *& _Val) const
		{	
		return (do_get(_First, _Last, _Iosbase, _State, _Val));
		}

protected:
	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			_Bool& _Val) const
		{	
		;
		int _Ans = -1;	

		if (_Iosbase.flags() & ios_base::boolalpha)
			{	
			typedef typename _Mystr::size_type _Mystrsize;
			const _Mypunct& _Punct_fac = use_facet< _Mypunct >(_Iosbase.getloc());
			_Mystr _Str((_Mystrsize)1, (char_type)0);
			_Str += _Punct_fac.falsename();
			_Str += (char_type)0;
			_Str += _Punct_fac.truename();	
			_Ans = _Getloctxt(_First, _Last, (size_t)2, _Str.c_str());
			}
		else
			{	
			char _Ac[32], *_Ep;
			int _Errno = 0;
			const unsigned long _Ulo = :: _Stoulx(_Ac, &_Ep,
				_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
					_Iosbase.getloc()), &_Errno);
			if (_Ep != _Ac && _Errno == 0 && _Ulo <= 1)
				_Ans = _Ulo;
			}

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ans < 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans != 0;	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned short& _Val) const
		{	
		;
		char _Ac[32], *_Ep;
		int _Errno = 0;
		int _Base = _Getifld(_Ac, _First, _Last, _Iosbase.flags(),
			_Iosbase.getloc());	
		char *_Ptr = _Ac[0] == '-' ? _Ac + 1 : _Ac;	
		const unsigned long _Ans =
			:: _Stoulx(_Ptr, &_Ep, _Base, &_Errno);	

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ptr || _Errno != 0 || 0xffff < _Ans)
			_State |= ios_base::failbit;
		else
			_Val = (unsigned short)(_Ac[0] == '-'
				? 0 -_Ans : _Ans);	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned int& _Val) const
		{	
		;
		char _Ac[32], *_Ep;
		int _Errno = 0;
		int _Base = _Getifld(_Ac, _First, _Last, _Iosbase.flags(),
			_Iosbase.getloc());	
		char *_Ptr = _Ac[0] == '-' ? _Ac + 1 : _Ac;	
		const unsigned long _Ans =
			:: _Stoulx(_Ptr, &_Ep, _Base, &_Errno);	

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ptr || _Errno != 0 || 0xffffffff < _Ans)
			_State |= ios_base::failbit;
		else
			_Val = _Ac[0] == '-' ? 0 -_Ans : _Ans;	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long& _Val) const
		{	
		;
		char _Ac[32], *_Ep;
		int _Errno = 0;
		const long _Ans = :: _Stolx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned long& _Val) const
		{	
		;
		char _Ac[32], *_Ep;
		int _Errno = 0;
		const unsigned long _Ans = :: _Stoulx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	
		return (_First);
		}

 
	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			__int64& _Val) const
		{	
		;
		char _Ac[32], *_Ep;
		int _Errno = 0;
		const __int64 _Ans = :: _Stollx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			unsigned __int64& _Val) const
		{	
		;
		char _Ac[32], *_Ep;
		int _Errno = 0;
		const unsigned __int64 _Ans = :: _Stoullx(_Ac, &_Ep,
			_Getifld(_Ac, _First, _Last, _Iosbase.flags(),
				_Iosbase.getloc()), &_Errno);	

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	
		return (_First);
		}
 #line 525 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			float& _Val) const
		{	
		;
		char _Ac[8 + 36 + 16], *_Ep;
		int _Errno = 0;
		int _Hexexp = 0;
		float _Ans = :: _Stofx(_Ac, &_Ep,
			_Getffld(_Ac, _First, _Last,
				_Iosbase, &_Hexexp), &_Errno);	

		if (_Hexexp != 0)
			_Ans = :: ldexpf(_Ans, 4 * _Hexexp);

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			double& _Val) const
		{	
		;
		char _Ac[8 + 36 + 16], *_Ep;
		int _Errno = 0;
		int _Hexexp = 0;
		double _Ans = :: _Stodx(_Ac, &_Ep,
			_Getffld(_Ac, _First, _Last,
				_Iosbase, &_Hexexp), &_Errno);	

		if (_Hexexp != 0)
			_Ans = :: ldexp(_Ans, 4 * _Hexexp);

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			long double& _Val) const
		{	
		;
		char _Ac[8 + 36 + 16], *_Ep;
		int _Errno = 0;
		int _Hexexp = 0;
		long double _Ans = :: _Stoldx(_Ac, &_Ep,
			_Getffld(_Ac, _First, _Last,
				_Iosbase, &_Hexexp), &_Errno);	

		if (_Hexexp != 0)
			_Ans = :: ldexpl(_Ans, 4 * _Hexexp);

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = _Ans;	
		return (_First);
		}

	virtual _InIt  do_get(_InIt _First, _InIt _Last,
		ios_base& _Iosbase, ios_base::iostate& _State,
			void *& _Val) const
		{	
		;
		char _Ac[32], *_Ep;
		int _Errno = 0;

 
		int _Base = _Getifld(_Ac, _First, _Last, ios_base::hex,
			_Iosbase.getloc());	
		const unsigned __int64 _Ans =
			(sizeof (void *) == sizeof (unsigned long))
				? (unsigned __int64):: _Stoulx(_Ac, &_Ep, _Base, &_Errno)
				: :: _Stoullx(_Ac, &_Ep, _Base, &_Errno);

 



#line 619 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

		if (_First == _Last)
			_State |= ios_base::eofbit;
		if (_Ep == _Ac || _Errno != 0)
			_State |= ios_base::failbit;
		else
			_Val = (void *)((char *)0 + _Ans);	
		return (_First);
		}

private:
	int __cdecl _Getifld(char *_Ac,
		_InIt& _First, _InIt& _Last, ios_base::fmtflags _Basefield,
			const locale& _Loc) const
		{	
		const _Mypunct& _Punct_fac = use_facet< _Mypunct >(_Loc);
		const string _Grouping = _Punct_fac.grouping();
		const _Elem _Kseparator = _Grouping.size() == 0
			? (_Elem)0 : _Punct_fac.thousands_sep();
		const _Elem _E0 = _Maklocchr('0', (_Elem *)0, _Cvt);
		char *_Ptr = _Ac;

		if (_First == _Last)
			;	
		else if (*_First == _Maklocchr('+', (_Elem *)0, _Cvt))
			*_Ptr++ = '+', ++_First;	
		else if (*_First == _Maklocchr('-', (_Elem *)0, _Cvt))
			*_Ptr++ = '-', ++_First;	

		_Basefield &= ios_base::basefield;
		int _Base = _Basefield == ios_base::oct ? 8
			: _Basefield == ios_base::hex ? 16
			: _Basefield == ios_base::_Fmtzero ? 0 : 10;

		bool _Seendigit = false;	
		bool _Nonzero = false;	

		if (_First != _Last && *_First == _E0)
			{	
			_Seendigit = true, ++_First;
			if (_First != _Last && (*_First == _Maklocchr('x', (_Elem *)0, _Cvt)
					|| *_First == _Maklocchr('X', (_Elem *)0, _Cvt))
				&& (_Base == 0 || _Base == 16))
				_Base = 16, _Seendigit = false, ++_First;
			else if (_Base == 0)
				_Base = 8;
			}

		int _Dlen = _Base == 0 || _Base == 10 ? 10
			: _Base == 8 ? 8 : 16 + 6;
		string _Groups((size_t)1, (char)_Seendigit);
		size_t _Group = 0;

		for (char *const _Pe = &_Ac[32 - 1];
			_First != _Last; ++_First)
			if (:: memchr((const char *)"0123456789abcdefABCDEF",
				*_Ptr = _Maklocbyte((_Elem)*_First, _Cvt), _Dlen) != 0)
				{	
				if ((_Nonzero || *_Ptr != '0') && _Ptr < _Pe)
					++_Ptr, _Nonzero = true;
				_Seendigit = true;
				if (_Groups[_Group] != 127)
					++_Groups[_Group];
				}
			else if (_Groups[_Group] == '\0'
				|| _Kseparator == (_Elem)0
				|| *_First != _Kseparator)
				break;	
			else
				{	
				_Groups.append((string::size_type)1, '\0');
				++_Group;
				}

		if (_Group == 0)
			;	
		else if ('\0' < _Groups[_Group])
			++_Group;	
		else
			_Seendigit = false;	

		for (const char *_Pg = _Grouping.c_str(); _Seendigit && 0 < _Group; )
			if (*_Pg == 127)
				break;	
			else if (0 < --_Group && *_Pg != _Groups[_Group]
				|| 0 == _Group && *_Pg < _Groups[_Group])
				_Seendigit = false;	
			else if ('\0' < _Pg[1])
				++_Pg;	

		if (_Seendigit && !_Nonzero)
			*_Ptr++ = '0';	
		else if (!_Seendigit)
			_Ptr = _Ac;	
		*_Ptr = '\0';
		return (_Base);
		}

	int __cdecl _Getffld(char *_Ac,
		_InIt& _First, _InIt &_Last,
		ios_base& _Iosbase, int *_Phexexp) const
		{	
		if ((_Iosbase.flags() & ios_base::floatfield) == ios_base::hexfloat)
			return (_Getffldx(_Ac, _First, _Last,
				_Iosbase, _Phexexp));	

		const _Mypunct& _Punct_fac = use_facet< _Mypunct >(_Iosbase.getloc());
		const string _Grouping = _Punct_fac.grouping();
		const _Elem _E0 = _Maklocchr('0', (_Elem *)0, _Cvt);
		char *_Ptr = _Ac;
		bool _Bad = false;

		if (_First == _Last)
			;	
		else if (*_First == _Maklocchr('+', (_Elem *)0, _Cvt))
			*_Ptr++ = '+', ++_First;	
		else if (*_First == _Maklocchr('-', (_Elem *)0, _Cvt))
			*_Ptr++ = '-', ++_First;	

		bool _Seendigit = false;	
		int _Significant = 0;	
		int _Pten = 0;	

		if (*_Grouping.c_str() == 127 || *_Grouping.c_str() <= '\0')
			for (; _First != _Last
				&& _E0 <= *_First && *_First <= _E0 + 9;
					_Seendigit = true, ++_First)
				if (36 <= _Significant)
					++_Pten;	
				else if (*_First == _E0 && _Significant == 0)
					;	
				else
					{	
					*_Ptr++ = (char)((*_First - _E0) + '0');
					++_Significant;
					}
		else
			{	
			const _Elem _Kseparator = _Grouping.size() == 0
				? (_Elem)0 : _Punct_fac.thousands_sep();
			string _Groups((size_t)1, '\0');
			size_t _Group = 0;

			for (; _First != _Last; ++_First)
				if (_E0 <= *_First && *_First <= _E0 + 9)
					{	
					_Seendigit = true;
					if (36 <= _Significant)
						++_Pten;	
					else if (*_First == _E0 && _Significant == 0)
						;	
					else
						{	
						*_Ptr++ = (char)((*_First - _E0) + '0');
						++_Significant;
						}
					if (_Groups[_Group] != 127)
						++_Groups[_Group];
					}
				else if (_Groups[_Group] == '\0'
					|| _Kseparator == (_Elem)0
					|| *_First != _Kseparator)
					break;	
				else
					{	
					_Groups.append((size_t)1, '\0');
					++_Group;
					}
			if (_Group == 0)
				;	
			else if ('\0' < _Groups[_Group])
				++_Group;	
			else
				_Bad = true;	

			for (const char *_Pg = _Grouping.c_str();
				!_Bad && 0 < _Group; )
				if (*_Pg == 127)
					break;	
				else if (0 < --_Group && *_Pg != _Groups[_Group]
					|| 0 == _Group && *_Pg < _Groups[_Group])
					_Bad = true;	
				else if ('\0' < _Pg[1])
					++_Pg;	
			}

		if (_Seendigit && _Significant == 0)
			*_Ptr++ = '0';	

		if (_First != _Last && *_First == _Punct_fac.decimal_point())
			*_Ptr++ = localeconv()->decimal_point[0], ++_First;	

		if (_Significant == 0)
			{	
			for (; _First != _Last && *_First == _E0;
				_Seendigit = true, ++_First)
				--_Pten;	
			if (_Pten < 0)
				*_Ptr++ = '0', ++_Pten;	
			}

		for (; _First != _Last
				&& _E0 <= *_First && *_First <= _E0 + 9;
				_Seendigit = true, ++_First)
			if (_Significant < 36)
				{	
				*_Ptr++ = (char)((*_First - _E0) + '0');
				++_Significant;
				}

		if (_Seendigit && _First != _Last
			&& (*_First == _Maklocchr('e', (_Elem *)0, _Cvt)
				|| *_First == _Maklocchr('E', (_Elem *)0, _Cvt)))
			{	
			*_Ptr++ = 'e', ++_First;
			_Seendigit = false, _Significant = 0;

			if (_First == _Last)
				;	
			else if (*_First == _Maklocchr('+', (_Elem *)0, _Cvt))
				*_Ptr++ = '+', ++_First;	
			else if (*_First == _Maklocchr('-', (_Elem *)0, _Cvt))
				*_Ptr++ = '-', ++_First;	
			for (; _First != _Last && *_First == _E0; )
				_Seendigit = true, ++_First;	
			if (_Seendigit)
				*_Ptr++ = '0';	
			for (; _First != _Last
				&& _E0 <= *_First && *_First <= _E0 + 9;
				_Seendigit = true, ++_First)
				if (_Significant < 8)
					{	
					*_Ptr++ = (char)((*_First - _E0) + '0');
					++_Significant;
					}
			}

		if (_Bad || !_Seendigit)
			_Ptr = _Ac;	
		*_Ptr = '\0';
		return (_Pten);
		}

	int __cdecl _Hexdig(const _Elem _Dig, const _Elem _E0,
		const _Elem _Al, const _Elem _Au) const
		{	
		if (_E0 <= _Dig && _Dig <= _E0 + 9)
			return (_Dig - _E0);	
		else if (_Al <= _Dig && _Dig <= _Al + 5)
			return (_Dig - _Al + 10);	
		else if (_Au <= _Dig && _Dig <= _Au + 5)
			return (_Dig - _Au + 10);	
		else
			return (-1);
		}

	int __cdecl _Getffldx(char *_Ac,
		_InIt& _First, _InIt &_Last,
		ios_base& _Iosbase, int *_Phexexp) const
		{	
		const _Mypunct& _Punct_fac = use_facet< _Mypunct >(_Iosbase.getloc());
		const string _Grouping = _Punct_fac.grouping();
		const _Elem _E0 = _Maklocchr('0', (_Elem *)0, _Cvt);
		const _Elem _Al = _Maklocchr('a', (_Elem *)0, _Cvt);
		const _Elem _Au = _Maklocchr('A', (_Elem *)0, _Cvt);
		char *_Ptr = _Ac;
		bool _Bad = false;
		int _Dig;

		if (_First == _Last)
			;	
		else if (*_First == _Maklocchr('+', (_Elem *)0, _Cvt))
			*_Ptr++ = '+', ++_First;	
		else if (*_First == _Maklocchr('-', (_Elem *)0, _Cvt))
			*_Ptr++ = '-', ++_First;	

		*_Ptr++ = '0';
		*_Ptr++ = 'x';

		bool _Seendigit = false;	
		int _Significant = 0;	
		int _Phex = 0;	

		if (_First == _Last || *_First != _E0)
			;
		else if (++_First != _Last
			&& (*_First == _Maklocchr('x', (_Elem *)0, _Cvt)
				 || *_First == _Maklocchr('X', (_Elem *)0, _Cvt)))
			++_First;	
		else
			_Seendigit = true;	

		if (*_Grouping.c_str() == 127 || *_Grouping.c_str() <= '\0')
			for (; _First != _Last
				&& 0 <= (_Dig = _Hexdig(*_First, _E0, _Al, _Au));
					_Seendigit = true, ++_First)
				if (36 <= _Significant)
					++_Phex;	
				else if (*_First == _E0 && _Significant == 0)
					;	
				else
					{	
					*_Ptr++ = "0123456789abcdef"[_Dig];
					++_Significant;
					}
		else
			{	
			const _Elem _Kseparator = _Grouping.size() == 0
				? (_Elem)0 : _Punct_fac.thousands_sep();
			string _Groups((size_t)1, '\0');
			size_t _Group = 0;

			for (; _First != _Last; ++_First)
				if (0 <= (_Dig = _Hexdig(*_First, _E0, _Al, _Au)))
					{	
					_Seendigit = true;
					if (36 <= _Significant)
						++_Phex;	
					else if (*_First == _E0 && _Significant == 0)
						;	
					else
						{	
						*_Ptr++ = "0123456789abcdef"[_Dig];
						++_Significant;
						}
					if (_Groups[_Group] != 127)
						++_Groups[_Group];
					}
				else if (_Groups[_Group] == '\0'
					|| _Kseparator == (_Elem)0
					|| *_First != _Kseparator)
					break;	
				else
					{	
					_Groups.append((size_t)1, '\0');
					++_Group;
					}
			if (_Group == 0)
				;	
			else if ('\0' < _Groups[_Group])
				++_Group;	
			else
				_Bad = true;	

			for (const char *_Pg = _Grouping.c_str();
				!_Bad && 0 < _Group; )
				if (*_Pg == 127)
					break;	
				else if (0 < --_Group && *_Pg != _Groups[_Group]
					|| 0 == _Group && *_Pg < _Groups[_Group])
					_Bad = true;	
				else if ('\0' < _Pg[1])
					++_Pg;	
			}

		if (_Seendigit && _Significant == 0)
			*_Ptr++ = '0';	

		if (_First != _Last && *_First == _Punct_fac.decimal_point())
			*_Ptr++ = localeconv()->decimal_point[0], ++_First;	

		if (_Significant == 0)
			{	
			for (; _First != _Last && *_First == _E0;
				_Seendigit = true, ++_First)
				--_Phex;	
			if (_Phex < 0)
				*_Ptr++ = '0', ++_Phex;	
			}

		for (; _First != _Last
				&& 0 <= (_Dig = _Hexdig(*_First, _E0, _Al, _Au));
				_Seendigit = true, ++_First)
			if (_Significant < 36)
				{	
				*_Ptr++ = "0123456789abcdef"[_Dig];
				++_Significant;
				}

		if (_Seendigit && _First != _Last
			&& (*_First == _Maklocchr('p', (_Elem *)0, _Cvt)
				|| *_First == _Maklocchr('P', (_Elem *)0, _Cvt)))
			{	
			*_Ptr++ = 'p', ++_First;
			_Seendigit = false, _Significant = 0;

			if (_First == _Last)
				;	
			else if (*_First == _Maklocchr('+', (_Elem *)0, _Cvt))
				*_Ptr++ = '+', ++_First;	
			else if (*_First == _Maklocchr('-', (_Elem *)0, _Cvt))
				*_Ptr++ = '-', ++_First;	
			for (; _First != _Last && *_First == _E0; )
				_Seendigit = true, ++_First;	
			if (_Seendigit)
				*_Ptr++ = '0';	
			for (; _First != _Last
				&& _E0 <= *_First && *_First <= _E0 + 9;
				_Seendigit = true, ++_First)
				if (_Significant < 8)
					{	
					*_Ptr++ = (char)((*_First - _E0) + '0');
					++_Significant;
					}
			}

		if (_Bad || !_Seendigit)
			_Ptr = _Ac;	
		*_Ptr = '\0';
		*_Phexexp = _Phex;	
		return (0);	
		}
	};

		
template<class _Elem,
	class _InIt>
	 locale::id num_get<_Elem, _InIt>::id;

		
template<class _Elem,
	class _OutIt = ostreambuf_iterator<_Elem, char_traits<_Elem> > >
	class num_put
		: public locale::facet
	{	
public:
	typedef numpunct<_Elem> _Mypunct;
	typedef basic_string<_Elem, char_traits<_Elem>, allocator<_Elem> >
		_Mystr;

	static size_t __cdecl _Getcat(const locale::facet **_Ppf = 0,
		const locale *_Ploc = 0)
		{	
		if (_Ppf != 0 && *_Ppf == 0)
			*_Ppf = new num_put<_Elem, _OutIt>(
				_Locinfo(_Ploc->c_str()));
		return (4);
		}

	 static locale::id id;	

protected:
	virtual  ~num_put()
		{	
		}

	void  _Init(const _Locinfo& _Lobj)
		{	
		_Cvt = _Lobj._Getcvt();
		}

	_Locinfo::_Cvtvec _Cvt;		

public:
	explicit  num_put(size_t _Refs = 0)
		: locale::facet(_Refs)
		{	
		{ _Locinfo _Lobj;
			_Init(_Lobj);
		}
		}

	 num_put(const _Locinfo& _Lobj, size_t _Refs = 0)
		: locale::facet(_Refs)
		{	
		_Init(_Lobj);
		}

	typedef _Elem char_type;
	typedef _OutIt iter_type;

	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, _Bool _Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long _Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, unsigned long _Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

 
	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, __int64 _Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, unsigned __int64 _Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}
 #line 1121 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, double _Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long double _Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

	_OutIt  put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, const void *_Val) const
		{	
		return (do_put(_Dest, _Iosbase, _Fill, _Val));
		}

protected:
	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, _Bool _Val) const
		{	
		;
		if (!(_Iosbase.flags() & ios_base::boolalpha))
			return (do_put(_Dest, _Iosbase, _Fill, (long)_Val));
		else
			{	
			const _Mypunct& _Punct_fac = use_facet< _Mypunct >(_Iosbase.getloc());
			_Mystr _Str;
			if (_Val)
				_Str.assign(_Punct_fac.truename());
			else
				_Str.assign(_Punct_fac.falsename());

			size_t _Fillcount = _Iosbase.width() <= 0
				|| (size_t)_Iosbase.width() <= _Str.size()
					? 0 : (size_t)_Iosbase.width() - _Str.size();

			if ((_Iosbase.flags() & ios_base::adjustfield) != ios_base::left)
				{	
				_Dest = _Rep(_Dest, _Fill, _Fillcount);
				_Fillcount = 0;
				}
			_Dest = _Put(_Dest, _Str.c_str(), _Str.size());	
			_Iosbase.width(0);
			return (_Rep(_Dest, _Fill, _Fillcount));	
			}
		}

	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long _Val) const
		{	
		char _Buf[2 * 32], _Fmt[6];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			:: sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "ld",
				_Iosbase.flags()), _Val)));
		}

	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, unsigned long _Val) const
		{	
		char _Buf[2 * 32], _Fmt[6];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			:: sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "lu",
				_Iosbase.flags()), _Val)));
		}

 
	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, __int64 _Val) const
		{	
		char _Buf[2 * 32], _Fmt[8];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			:: sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "Ld",
				_Iosbase.flags()), _Val)));
		}

	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, unsigned __int64 _Val) const
		{	
		char _Buf[2 * 32], _Fmt[8];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			:: sprintf_s(_Buf, sizeof (_Buf), _Ifmt(_Fmt, "Lu",
				_Iosbase.flags()), _Val)));
		}
 #line 1212 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, double _Val) const
		{	
		char _Buf[8 + 36 + 64], _Fmt[8];
		streamsize _Precision = _Iosbase.precision() <= 0
			&& !(_Iosbase.flags() & ios_base::fixed)
				? 6 : _Iosbase.precision();	
		int _Significance = 36 < _Precision
			? 36 : (int)_Precision;	
		_Precision -= _Significance;
		size_t _Beforepoint = 0;	
		size_t _Afterpoint = 0;	

		if ((_Iosbase.flags() & ios_base::floatfield) == ios_base::fixed
			&& _Val * 0.5 != _Val)	
			{	
			bool _Signed = _Val < 0;
			if (_Signed)
				_Val = -_Val;

			for (; 1e35 <= _Val && _Beforepoint < 5000; _Beforepoint += 10)
				_Val /= 1e10;	

			if (0 < _Val)
				for (; 10 <= _Precision && _Val <= 1e-35
					&& _Afterpoint < 5000; _Afterpoint += 10)
					{	
					_Val *= 1e10;
					_Precision -= 10;
					}

			if (_Signed)
				_Val = -_Val;
			}

		return (_Fput(_Dest, _Iosbase, _Fill, _Buf,
			_Beforepoint, _Afterpoint, (size_t)_Precision,
				:: sprintf_s(_Buf, sizeof (_Buf),
					_Ffmt(_Fmt, 0, _Iosbase.flags()),
					_Significance, _Val)));	
		}

	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, long double _Val) const
		{	
		char _Buf[8 + 36 + 64], _Fmt[8];
		streamsize _Precision = _Iosbase.precision() <= 0
			&& !(_Iosbase.flags() & ios_base::fixed)
				? 6 : _Iosbase.precision();	
		int _Significance = 36 < _Precision
			? 36 : (int)_Precision;	
		_Precision -= _Significance;
		size_t _Beforepoint = 0;	
		size_t _Afterpoint = 0;	

		if ((_Iosbase.flags() & ios_base::floatfield) == ios_base::fixed)
			{	
			bool _Signed = _Val < 0;
			if (_Signed)
				_Val = -_Val;

			for (; 1e35 <= _Val && _Beforepoint < 5000; _Beforepoint += 10)
				_Val /= 1e10;	

			if (0 < _Val)
				for (; 10 <= _Precision && _Val <= 1e-35
					&& _Afterpoint < 5000; _Afterpoint += 10)
					{	
					_Val *= 1e10;
					_Precision -= 10;
					}

			if (_Signed)
				_Val = -_Val;
			}

		return (_Fput(_Dest, _Iosbase, _Fill, _Buf,
			_Beforepoint, _Afterpoint, (size_t)_Precision,
				:: sprintf_s(_Buf, sizeof (_Buf),
					_Ffmt(_Fmt, 'L', _Iosbase.flags()),
					_Significance, _Val)));	
		}

	virtual _OutIt  do_put(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, const void *_Val) const
		{	
		char _Buf[2 * 32];

		return (_Iput(_Dest, _Iosbase, _Fill, _Buf,
			:: sprintf_s(_Buf, sizeof (_Buf), "%p", _Val)));
		}

private:
	char *__cdecl _Ffmt(char *_Fmt,
		char _Spec, ios_base::fmtflags _Flags) const
		{	
		char *_Ptr = _Fmt;
		*_Ptr++ = '%';

		if (_Flags & ios_base::showpos)
			*_Ptr++ = '+';
		if (_Flags & ios_base::showpoint)
			*_Ptr++ = '#';
		*_Ptr++ = '.';
		*_Ptr++ = '*';	
		if (_Spec != '\0')
			*_Ptr++ = _Spec;	

		ios_base::fmtflags _Ffl = _Flags & ios_base::floatfield;
		*_Ptr++ = _Ffl == ios_base::fixed ? 'f'
			: _Ffl == ios_base::hexfloat ? 'a'	
			: _Ffl == ios_base::scientific ? 'e' : 'g';	
		*_Ptr = '\0';
		return (_Fmt);
		}

	_OutIt __cdecl _Fput(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, const char *_Buf,
			size_t _Beforepoint, size_t _Afterpoint,
				size_t _Trailing, size_t _Count) const
		{	
		;
		const _Mypunct& _Punct_fac = use_facet< _Mypunct >(_Iosbase.getloc());
		const string _Grouping = _Punct_fac.grouping();
		const _Elem _Kseparator = _Punct_fac.thousands_sep();
		string _Groupstring;
		const _Elem _E0 = _Maklocchr('0', (_Elem *)0, _Cvt);
		size_t _Prefix = _Buf[0] == '+' || _Buf[0] == '-' ? 1 : 0;

		char _Enders[3];
		_Enders[0] = :: localeconv()->decimal_point[0];
		_Enders[1] = 'e';
		_Enders[2] = '\0';

		const char *_Eptr = (const char *):: memchr(_Buf,
			'e', _Count);	
		const char *_Pointptr = (const char *):: memchr(_Buf,
			_Enders[0], _Count);	
		if (_Pointptr == 0)
			_Trailing = 0;

		if (*_Grouping.c_str() != 127 && '\0' < *_Grouping.c_str())
			{	
			_Groupstring.append(_Buf, _Count);	
			if (_Eptr == 0)
				_Groupstring.append(_Trailing, '0');
			else
				{	
				if (_Pointptr == 0)
					{	
					_Groupstring.append(_Beforepoint, '0');
					_Beforepoint = 0;
					}
				_Groupstring.insert(_Eptr - _Buf, _Trailing, '0');
				}
			_Trailing = 0;

			if (_Pointptr == 0)
				_Groupstring.append(_Beforepoint, '0');
			else
				{	
				_Groupstring.insert(_Pointptr - _Buf + 1, _Afterpoint, '0');
				_Groupstring.insert(_Pointptr - _Buf, _Beforepoint, '0');
				_Afterpoint = 0;
				}
			_Beforepoint = 0;

			const char *_Pg = _Grouping.c_str();
			size_t _Off = :: strcspn(&_Groupstring[0], &_Enders[0]);
			while (*_Pg != 127 && '\0' < *_Pg
				&& (size_t)*_Pg < _Off - _Prefix)
				{	
				_Groupstring.insert(_Off -= *_Pg, (size_t)1, '\0');
				if ('\0' < _Pg[1])
					++_Pg;	
				}

			_Buf = &_Groupstring[0];
			_Trailing = 0;
			_Count = _Groupstring.size();
			}

		size_t _Fillcount = _Beforepoint + _Afterpoint + _Trailing + _Count;
		_Fillcount = _Iosbase.width() <= 0
			|| (size_t)_Iosbase.width() <= _Fillcount
				? 0 : (size_t)_Iosbase.width() - _Fillcount;
		ios_base::fmtflags _Adjustfield =
			_Iosbase.flags() & ios_base::adjustfield;
		if (_Adjustfield != ios_base::left
			&& _Adjustfield != ios_base::internal)
			{	
			_Dest = _Rep(_Dest, _Fill, _Fillcount);
			_Fillcount = 0;
			}
		else if (_Adjustfield == ios_base::internal)
			{	
			if (0 < _Prefix)
				{	
				_Dest = _Putc(_Dest, _Buf, 1);
				++_Buf, --_Count;
				}
			_Dest = _Rep(_Dest, _Fill, _Fillcount);
			_Fillcount = 0;
			}

		_Pointptr = (const char *):: memchr(_Buf,
			_Enders[0], _Count);	
		if (_Pointptr != 0)
			{	
			size_t _Fracoffset = _Pointptr - _Buf + 1;
			_Dest = _Putgrouped(_Dest, _Buf, _Fracoffset - 1, _Kseparator);
			_Dest = _Rep(_Dest, _E0, _Beforepoint);
			_Dest = _Rep(_Dest, _Punct_fac.decimal_point(), 1);
			_Dest = _Rep(_Dest, _E0, _Afterpoint);
			_Buf += _Fracoffset, _Count -= _Fracoffset;
			}

		_Eptr = (const char *):: memchr(_Buf,
			'e', _Count);	
		if (_Eptr != 0)
			{	
			size_t _Expoffset = _Eptr - _Buf + 1;
			_Dest = _Putgrouped(_Dest, _Buf, _Expoffset - 1, _Kseparator);
			_Dest = _Rep(_Dest, _E0, _Trailing), _Trailing = 0;
			_Dest = _Putc(_Dest, _Iosbase.flags() & ios_base::uppercase
				? "E" : "e", 1);
			_Buf += _Expoffset, _Count -= _Expoffset;
			}

		_Dest = _Putgrouped(_Dest, _Buf, _Count,
			_Kseparator);	
		_Dest = _Rep(_Dest, _E0, _Trailing);	
		_Iosbase.width(0);
		return (_Rep(_Dest, _Fill, _Fillcount));	
		}

	char *__cdecl _Ifmt(char *_Fmt,
		const char *_Spec, ios_base::fmtflags _Flags) const
		{	
		char *_Ptr = _Fmt;
		*_Ptr++ = '%';

		if (_Flags & ios_base::showpos)
			*_Ptr++ = '+';
		if (_Flags & ios_base::showbase)
			*_Ptr++ = '#';
		if (_Spec[0] != 'L')
			*_Ptr++ = _Spec[0];	
		else

			{	
			*_Ptr++ = 'I';
			*_Ptr++ = '6';
			*_Ptr++ = '4';
			}

		ios_base::fmtflags _Basefield = _Flags & ios_base::basefield;
		*_Ptr++ = _Basefield == ios_base::oct ? 'o'
			: _Basefield != ios_base::hex ? _Spec[1]	
			: _Flags & ios_base::uppercase ? 'X' : 'x';
		*_Ptr = '\0';
		return (_Fmt);
		}

	_OutIt __cdecl _Iput(_OutIt _Dest,
		ios_base& _Iosbase, _Elem _Fill, char *_Buf, size_t _Count) const
		{	
		;
		const _Mypunct& _Punct_fac = use_facet< _Mypunct >(_Iosbase.getloc());
		const string _Grouping = _Punct_fac.grouping();
		const size_t _Prefix = *_Buf == '+' || *_Buf == '-' ? 1
			: *_Buf == '0' && (_Buf[1] == 'x' || _Buf[1] == 'X') ? 2
			: 0;

		if (*_Grouping.c_str() != 127 && '\0' < *_Grouping.c_str())
			{	
			const char *_Pg = _Grouping.c_str();
			size_t _Off = _Count;
			while (*_Pg != 127 && '\0' < *_Pg
				&& (size_t)*_Pg < _Off - _Prefix)
				{	
				_Off -= *_Pg;

				;
				::memmove_s((&_Buf[_Off + 1]), (_Count + 1 - _Off), (&_Buf[_Off]), (_Count + 1 - _Off));
#line 1499 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"

				_Buf[_Off] = '\0', ++_Count;
				if ('\0' < _Pg[1])
					++_Pg;	
				}
			}

		size_t _Fillcount = _Iosbase.width() <= 0
			|| (size_t)_Iosbase.width() <= _Count
				? 0 : (size_t)_Iosbase.width() - _Count;

		ios_base::fmtflags _Adjustfield =
			_Iosbase.flags() & ios_base::adjustfield;
		if (_Adjustfield != ios_base::left
			&& _Adjustfield != ios_base::internal)
			{	
			_Dest = _Rep(_Dest, _Fill, _Fillcount);
			_Fillcount = 0;
			}
		else if (_Adjustfield == ios_base::internal)
			{	
			_Dest = _Putc(_Dest, _Buf, _Prefix);	
			_Buf += _Prefix, _Count -= _Prefix;
			_Dest = _Rep(_Dest, _Fill, _Fillcount), _Fillcount = 0;
			}

		_Dest = _Putgrouped(_Dest, _Buf, _Count,
			_Punct_fac.thousands_sep());	
		_Iosbase.width(0);
		return (_Rep(_Dest, _Fill, _Fillcount));	
		}

	_OutIt __cdecl _Put(_OutIt _Dest,
		const _Elem *_Ptr, size_t _Count) const
		{	
		for (; 0 < _Count; --_Count, ++_Dest, ++_Ptr)
			*_Dest = *_Ptr;
		return (_Dest);
		}

	_OutIt __cdecl _Putc(_OutIt _Dest,
		const char *_Ptr, size_t _Count) const
		{	
		for (; 0 < _Count; --_Count, ++_Dest, ++_Ptr)
			*_Dest = _Maklocchr(*_Ptr, (_Elem *)0, _Cvt);
		return (_Dest);
		}

	_OutIt __cdecl _Putgrouped(_OutIt _Dest,
		const char *_Ptr, size_t _Count, _Elem _Kseparator) const
		{	
		for (; ; ++_Ptr, --_Count)
			{	
			const char *_Pend =
				(const char *):: memchr(_Ptr, '\0', _Count);
			size_t _Groupsize = _Pend != 0 ? _Pend - _Ptr : _Count;

			_Dest = _Putc(_Dest, _Ptr, _Groupsize);
			_Ptr += _Groupsize, _Count -= _Groupsize;
			if (_Count == 0)
				break;
			if (_Kseparator != (_Elem)0)
				_Dest = _Rep(_Dest, _Kseparator, 1);
			}
		return (_Dest);
		}

	_OutIt __cdecl _Rep(_OutIt _Dest,
		_Elem _Ch, size_t _Count) const
		{	
		for (; 0 < _Count; --_Count, ++_Dest)
			*_Dest = _Ch;
		return (_Dest);
		}
	};

		
template<class _Elem,
	class _OutIt>
	 locale::id num_put<_Elem, _OutIt>::id;

 

















#line 1599 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"
}

 

 #pragma warning(pop)
 #pragma pack(pop)

#line 1607 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"
#line 1608 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\xlocnum"






#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"

 #pragma pack(push,8)
 #pragma warning(push,3)

 #pragma warning(disable: 4189)

namespace std {
		
template<class _Elem,
	class _Traits>
	class basic_ios
		: public ios_base
	{	
public:
	typedef basic_ios<_Elem, _Traits> _Myt;
	typedef basic_ostream<_Elem, _Traits> _Myos;
	typedef basic_streambuf<_Elem, _Traits> _Mysb;
	typedef ctype<_Elem> _Ctype;
	typedef _Elem char_type;
	typedef _Traits traits_type;
	typedef typename _Traits::int_type int_type;
	typedef typename _Traits::pos_type pos_type;
	typedef typename _Traits::off_type off_type;

	explicit  basic_ios(_Mysb *_Strbuf)
		{	
		init(_Strbuf);
		}

	virtual  ~basic_ios()
		{	
		}

	void  clear(iostate _State = goodbit,
		bool _Reraise = false)
		{	
		ios_base::clear((iostate)(_Mystrbuf == 0
			? (int)_State | (int)badbit : (int)_State), _Reraise);
		}

	void  clear(io_state _State)
		{	
		clear((iostate)_State);
		}

	void  setstate(iostate _State,
		bool _Reraise = false)
		{	
		if (_State != goodbit)
			clear((iostate)((int)rdstate() | (int)_State), _Reraise);
		}

	void  setstate(io_state _State)
		{	
		setstate((iostate)_State);
		}

	_Myt&  copyfmt(const _Myt& _Right)
		{	
		_Tiestr = _Right.tie();
		_Fillch = _Right.fill();
		ios_base::copyfmt(_Right);
		return (*this);
		}

	_Myos * tie() const
		{	
		return (_Tiestr);
		}

	_Myos * tie(_Myos *_Newtie)
		{	
		_Myos *_Oldtie = _Tiestr;
		_Tiestr = _Newtie;
		return (_Oldtie);
		}

	_Mysb * rdbuf() const
		{	
		return (_Mystrbuf);
		}

	_Mysb * rdbuf(_Mysb *_Strbuf)
		{	
		_Mysb *_Oldstrbuf = _Mystrbuf;
		_Mystrbuf = _Strbuf;
		clear();
		return (_Oldstrbuf);
		}

	locale  imbue(const locale& _Loc)
		{	
		locale _Oldlocale = ios_base::imbue(_Loc);
		if (rdbuf() != 0)
			rdbuf()->pubimbue(_Loc);
		return (_Oldlocale);
		}

	_Elem  fill() const
		{	
		return (_Fillch);
		}

	_Elem  fill(_Elem _Newfill)
		{	
		_Elem _Oldfill = _Fillch;
		_Fillch = _Newfill;
		return (_Oldfill);
		}

	char  narrow(_Elem _Ch, char _Dflt = '\0') const
		{	
		const _Ctype& _Ctype_fac = use_facet< _Ctype >(getloc());
		return (_Ctype_fac.narrow(_Ch, _Dflt));
		}

	_Elem  widen(char _Byte) const
		{	
		const _Ctype& _Ctype_fac = use_facet< _Ctype >(getloc());
		return (_Ctype_fac.widen(_Byte));
		}

	void  move(_Myt&& _Right)
		{	
		if (this != &_Right)
			{	
			_Mystrbuf = 0;
			_Tiestr = 0;
			this->swap(_Right);
			}
		}

	void  swap(_Myt& _Right)
		{	
		ios_base::swap(_Right);
		::std:: swap(_Fillch, _Right._Fillch);
		::std:: swap(_Tiestr, _Right._Tiestr);
		}

	void  set_rdbuf(_Mysb *_Strbuf)
		{	
		_Mystrbuf = _Strbuf;
		}

protected:
	void  init(_Mysb *_Strbuf = 0,
		bool _Isstd = false)
		{	
		_Init();	
		_Mystrbuf = _Strbuf;
		_Tiestr = 0;
		_Fillch = widen(' ');

		if (_Mystrbuf == 0)
			setstate(badbit);

		if (_Isstd)
			_Addstd(this);	
		}

	 basic_ios()
		{	
		}

private:
	_Mysb *_Mystrbuf;	
	_Myos *_Tiestr;	
	_Elem _Fillch;	

	 basic_ios(const _Myt&);	
	_Myt&  operator=(const _Myt&);	
	};

 








#line 190 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"

		
inline ios_base& __cdecl boolalpha(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::boolalpha);
	return (_Iosbase);
	}

inline ios_base& __cdecl dec(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::dec, ios_base::basefield);
	return (_Iosbase);
	}

 
inline ios_base& __cdecl defaultfloat(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::floatfield);
	return (_Iosbase);
	}
 #line 211 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"

inline ios_base& __cdecl fixed(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::fixed, ios_base::floatfield);
	return (_Iosbase);
	}

inline ios_base& __cdecl hex(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::hex, ios_base::basefield);
	return (_Iosbase);
	}

 
	namespace tr1 {	
inline ::std:: ios_base& __cdecl hexfloat(::std:: ios_base& _Iosbase)
	{	
	_Iosbase.setf(::std:: ios_base::hexfloat, ::std:: ios_base::floatfield);
	return (_Iosbase);
	}
	}	
 #line 233 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"

 

using tr1::hexfloat;

 #line 239 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"

inline ios_base& __cdecl internal(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::internal, ios_base::adjustfield);
	return (_Iosbase);
	}

inline ios_base& __cdecl left(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::left, ios_base::adjustfield);
	return (_Iosbase);
	}

inline ios_base& __cdecl noboolalpha(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::boolalpha);
	return (_Iosbase);
	}

inline ios_base& __cdecl noshowbase(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::showbase);
	return (_Iosbase);
	}

inline ios_base& __cdecl noshowpoint(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::showpoint);
	return (_Iosbase);
	}

inline ios_base& __cdecl noshowpos(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::showpos);
	return (_Iosbase);
	}

inline ios_base& __cdecl noskipws(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::skipws);
	return (_Iosbase);
	}

inline ios_base& __cdecl nounitbuf(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::unitbuf);
	return (_Iosbase);
	}

inline ios_base& __cdecl nouppercase(ios_base& _Iosbase)
	{	
	_Iosbase.unsetf(ios_base::uppercase);
	return (_Iosbase);
	}

inline ios_base& __cdecl oct(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::oct, ios_base::basefield);
	return (_Iosbase);
	}

inline ios_base& __cdecl right(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::right, ios_base::adjustfield);
	return (_Iosbase);
	}

inline ios_base& __cdecl scientific(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::scientific, ios_base::floatfield);
	return (_Iosbase);
	}

inline ios_base& __cdecl showbase(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::showbase);
	return (_Iosbase);
	}

inline ios_base& __cdecl showpoint(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::showpoint);
	return (_Iosbase);
	}

inline ios_base& __cdecl showpos(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::showpos);
	return (_Iosbase);
	}

inline ios_base& __cdecl skipws(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::skipws);
	return (_Iosbase);
	}

inline ios_base& __cdecl unitbuf(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::unitbuf);
	return (_Iosbase);
	}

inline ios_base& __cdecl uppercase(ios_base& _Iosbase)
	{	
	_Iosbase.setf(ios_base::uppercase);
	return (_Iosbase);
	}
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 353 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"
#line 354 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ios"





#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

 #pragma pack(push,8)
 #pragma warning(push,3)

 #pragma warning(disable: 4189 4390)

namespace std {
		

 
 

 



 



 



#line 32 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

		
template<class _Elem,
	class _Traits>
	class basic_ostream
		: virtual public basic_ios<_Elem, _Traits>
	{	
public:
	typedef basic_ostream<_Elem, _Traits> _Myt;
	typedef basic_ios<_Elem, _Traits> _Myios;
	typedef basic_streambuf<_Elem, _Traits> _Mysb;
	typedef ostreambuf_iterator<_Elem, _Traits> _Iter;
	typedef num_put<_Elem, _Iter> _Nput;

	explicit  basic_ostream(
		basic_streambuf<_Elem, _Traits> *_Strbuf,

		bool _Isstd = false)
		{	
		_Myios::init(_Strbuf, _Isstd);
		}

	 basic_ostream(_Uninitialized, bool _Addit = true)
		{	
		if (_Addit)
			ios_base::_Addstd(this);	
		}

	 basic_ostream(_Myt&& _Right)
		{	
		_Myios::init();
		_Myios::move(::std:: move(_Right));
		}

	_Myt&  operator=(_Myt&& _Right)
		{	
		this->swap(_Right);
		return (*this);
		}

	void  swap(_Myt& _Right)
		{	
		if (this != &_Right)
			_Myios::swap(_Right);
		}

	virtual  ~basic_ostream()
		{	
		}

	typedef typename _Traits::int_type int_type;
	typedef typename _Traits::pos_type pos_type;
	typedef typename _Traits::off_type off_type;

	class _Sentry_base
		{	
	public:
		 _Sentry_base(_Myt& _Ostr)
			: _Myostr(_Ostr)
			{	
			if (_Myostr.rdbuf() != 0)
				_Myostr.rdbuf()->_Lock();
			}

		 ~_Sentry_base()
			{	
			if (_Myostr.rdbuf() != 0)
				_Myostr.rdbuf()->_Unlock();
			}

		_Myt& _Myostr;	

	private:
		_Sentry_base& operator=(const _Sentry_base&);
		};

	class sentry
		: public _Sentry_base
		{	
	public:
		explicit  sentry(_Myt& _Ostr)
			: _Sentry_base(_Ostr)
			{	
			if (_Ostr.good() && _Ostr.tie() != 0)
				_Ostr.tie()->flush();
			_Ok = _Ostr.good();	
			}

		 ~sentry()
			{	
 
			if (!uncaught_exception())
				this->_Myostr._Osfx();

 

#line 129 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"
			}

		 operator ::std:: _Bool_type() const
			{	
			return (_Ok ? (&::std:: _Bool_struct::_Member) : 0);
			}

	private:
		bool _Ok;	

		 sentry(const sentry&);	
		sentry&  operator=(const sentry&);	
		};

	bool  opfx()
		{	
		if (ios_base::good() && _Myios::tie() != 0)
			_Myios::tie()->flush();
		return (ios_base::good());
		}

	void  osfx()
		{	
		_Osfx();
		}

	void  _Osfx()
		{	
		try {
		if (ios_base::flags() & ios_base::unitbuf)
			flush();	
		} catch (...) {
		}
		}

  





















	_Myt&  operator<<(_Myt& (__cdecl *_Pfn)(_Myt&))
		{	
		;
		return ((*_Pfn)(*this));
		}

	_Myt&  operator<<(_Myios& (__cdecl *_Pfn)(_Myios&))
		{	
		;
		(*_Pfn)(*(_Myios *)this);
		return (*this);
		}

	_Myt&  operator<<(ios_base& (__cdecl *_Pfn)(ios_base&))
		{	
		;
		(*_Pfn)(*(ios_base *)this);
		return (*this);
		}

	_Myt&  operator<<(_Bool _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(short _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());
			ios_base::fmtflags _Bfl =
				ios_base::flags() & ios_base::basefield;
			long _Tmp = (_Bfl == ios_base::oct
				|| _Bfl == ios_base::hex)
				? (long)(unsigned short)_Val : (long)_Val;

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Tmp).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}










	_Myt&  operator<<(unsigned short _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), (unsigned long)_Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(int _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());
			ios_base::fmtflags _Bfl =
				ios_base::flags() & ios_base::basefield;
			long _Tmp = (_Bfl == ios_base::oct
				|| _Bfl == ios_base::hex)
				? (long)(unsigned int)_Val : (long)_Val;

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Tmp).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(unsigned int _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), (unsigned long)_Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(long _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(unsigned long _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

 
	_Myt&  operator<<(__int64 _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(unsigned __int64 _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}
 #line 406 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

	_Myt&  operator<<(float _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), (double)_Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(double _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(long double _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(const void *_Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nput& _Nput_fac = use_facet< _Nput >(ios_base::getloc());

			try {
			if (_Nput_fac.put(_Iter(_Myios::rdbuf()), *this,
				_Myios::fill(), _Val).failed())
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator<<(_Mysb *_Strbuf)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		bool _Copied = false;
		const sentry _Ok(*this);

		if (_Ok && _Strbuf != 0)
			for (int_type _Meta = _Traits::eof(); ; _Copied = true)
				{	
				try {
				_Meta = _Traits::eq_int_type(_Traits::eof(), _Meta)
					? _Strbuf->sgetc() : _Strbuf->snextc();
				} catch (...) {
					_Myios::setstate(ios_base::failbit);
					throw;
				}

				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					break;	

				try {
					if (_Traits::eq_int_type(_Traits::eof(),
						_Myios::rdbuf()->sputc(
							_Traits::to_char_type(_Meta))))
						{	
						_State |= ios_base::badbit;
						break;
						}
				} catch (...) { _Myios::setstate(ios_base::badbit, true); }
				}

		ios_base::width(0);
		_Myios::setstate(_Strbuf == 0 ? ios_base::badbit
			: !_Copied ? _State | ios_base::failbit : _State);
		return (*this);
		}

	_Myt&  put(_Elem _Ch)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (!_Ok)
			_State |= ios_base::badbit;
		else
			{	
			try {
			if (_Traits::eq_int_type(_Traits::eof(),
				_Myios::rdbuf()->sputc(_Ch)))
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  write(const _Elem *_Str,
		streamsize _Count)
		{	
 


#line 551 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (!_Ok)
			_State |= ios_base::badbit;
		else
			{	
			try {
			if (_Myios::rdbuf()->sputn(_Str, _Count) != _Count)
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  flush()
		{	
		ios_base::iostate _State = ios_base::goodbit;
		if (!ios_base::fail() && _Myios::rdbuf()->pubsync() == -1)
			_State |= ios_base::badbit;	
		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  seekp(pos_type _Pos)
		{	
		if (!ios_base::fail()
			&& (off_type)_Myios::rdbuf()->pubseekpos(_Pos,
				ios_base::out) == _BADOFF)
			_Myios::setstate(ios_base::failbit);
		return (*this);
		}

	_Myt&  seekp(off_type _Off, ios_base::seekdir _Way)
		{	
		if (!ios_base::fail()
			&& (off_type)_Myios::rdbuf()->pubseekoff(_Off, _Way,
				ios_base::out) == _BADOFF)
			_Myios::setstate(ios_base::failbit);
		return (*this);
		}

	pos_type  tellp()
		{	
		if (!ios_base::fail())
			return (_Myios::rdbuf()->pubseekoff(0,
				ios_base::cur, ios_base::out));
		else
			return (pos_type(_BADOFF));
		}
	};

	
template<class _Elem,
	class _Traits> inline
	void swap(basic_ostream<_Elem, _Traits>& _Left,
		basic_ostream<_Elem, _Traits>& _Right)
	{	
	_Left.swap(_Right);
	}

  

















































 







#line 674 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

		

template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>& operator<<(
		basic_ostream<_Elem, _Traits>& _Ostr, const char *_Val)
	{	
	ios_base::iostate _State = ios_base::goodbit;
	streamsize _Count = (streamsize):: strlen(_Val);	
	streamsize _Pad = _Ostr.width() <= 0 || _Ostr.width() <= _Count
		? 0 : _Ostr.width() - _Count;
	const typename basic_ostream<_Elem, _Traits>::sentry _Ok(_Ostr);

	if (!_Ok)
		_State |= ios_base::badbit;
	else
		{	
		try {
		const ctype<_Elem>& _Ctype_fac = use_facet< ctype<_Elem> >(_Ostr.getloc());
		if ((_Ostr.flags() & ios_base::adjustfield) != ios_base::left)
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}

		for (; _State == ios_base::goodbit && 0 < _Count; --_Count, ++_Val)
			if (_Traits::eq_int_type(_Traits::eof(),
				_Ostr.rdbuf()->sputc(_Ctype_fac.widen(*_Val))))
					_State |= ios_base::badbit;

		if (_State == ios_base::goodbit)
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}
		_Ostr.width(0);
		} catch (...) { (_Ostr).setstate(ios_base::badbit, true); }
		}

	_Ostr.setstate(_State);
	return (_Ostr);
	}

template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>& operator<<(
		basic_ostream<_Elem, _Traits>& _Ostr, char _Ch)
	{	
	ios_base::iostate _State = ios_base::goodbit;
	const typename basic_ostream<_Elem, _Traits>::sentry _Ok(_Ostr);

	if (_Ok)
		{	
		const ctype<_Elem>& _Ctype_fac = use_facet< ctype<_Elem> >(_Ostr.getloc());
		streamsize _Pad = _Ostr.width() <= 1 ? 0 : _Ostr.width() - 1;

		try {
		if ((_Ostr.flags() & ios_base::adjustfield) != ios_base::left)
			for (; _State == ios_base::goodbit && 0 < _Pad;
				--_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					_State |= ios_base::badbit;

		if (_State == ios_base::goodbit
			&& _Traits::eq_int_type(_Traits::eof(),
				_Ostr.rdbuf()->sputc(_Ctype_fac.widen(_Ch))))
			_State |= ios_base::badbit;

		for (; _State == ios_base::goodbit && 0 < _Pad;
			--_Pad)	
			if (_Traits::eq_int_type(_Traits::eof(),
				_Ostr.rdbuf()->sputc(_Ostr.fill())))
				_State |= ios_base::badbit;
		} catch (...) { (_Ostr).setstate(ios_base::badbit, true); }
		}

	_Ostr.width(0);
	_Ostr.setstate(_State);
	return (_Ostr);
	}

template<class _Traits> inline
	basic_ostream<char, _Traits>& operator<<(
		basic_ostream<char, _Traits>& _Ostr,
		const char *_Val)
	{	
	typedef char _Elem;
	typedef basic_ostream<_Elem, _Traits> _Myos;
	ios_base::iostate _State = ios_base::goodbit;
	streamsize _Count = (streamsize)_Traits::length(_Val);	
	streamsize _Pad = _Ostr.width() <= 0 || _Ostr.width() <= _Count
		? 0 : _Ostr.width() - _Count;
	const typename _Myos::sentry _Ok(_Ostr);

	if (!_Ok)
		_State |= ios_base::badbit;
	else
		{	
		try {
		if ((_Ostr.flags() & ios_base::adjustfield) != ios_base::left)
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}

		if (_State == ios_base::goodbit
			&& _Ostr.rdbuf()->sputn(_Val, _Count) != _Count)
			_State |= ios_base::badbit;

		if (_State == ios_base::goodbit)
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}
		_Ostr.width(0);
		} catch (...) { (_Ostr).setstate(ios_base::badbit, true); }
		}

	_Ostr.setstate(_State);
	return (_Ostr);
	}

template<class _Traits> inline
	basic_ostream<char, _Traits>& operator<<(
		basic_ostream<char, _Traits>& _Ostr, char _Ch)
	{	
	typedef char _Elem;
	typedef basic_ostream<_Elem, _Traits> _Myos;
	ios_base::iostate _State = ios_base::goodbit;
	const typename _Myos::sentry _Ok(_Ostr);

	if (_Ok)
		{	
		streamsize _Pad = _Ostr.width() <= 1 ? 0 : _Ostr.width() - 1;

		try {
		if ((_Ostr.flags() & ios_base::adjustfield) != ios_base::left)
			for (; _State == ios_base::goodbit && 0 < _Pad;
				--_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					_State |= ios_base::badbit;

		if (_State == ios_base::goodbit
			&& _Traits::eq_int_type(_Traits::eof(),
				_Ostr.rdbuf()->sputc(_Ch)))
			_State |= ios_base::badbit;

		for (; _State == ios_base::goodbit && 0 < _Pad;
			--_Pad)	
			if (_Traits::eq_int_type(_Traits::eof(),
				_Ostr.rdbuf()->sputc(_Ostr.fill())))
				_State |= ios_base::badbit;
		} catch (...) { (_Ostr).setstate(ios_base::badbit, true); }
		}

	_Ostr.width(0);
	_Ostr.setstate(_State);
	return (_Ostr);
	}

template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>& operator<<(
		basic_ostream<_Elem, _Traits>& _Ostr, const _Elem *_Val)
	{	
	typedef basic_ostream<_Elem, _Traits> _Myos;

	ios_base::iostate _State = ios_base::goodbit;
	streamsize _Count = (streamsize)_Traits::length(_Val);	
	streamsize _Pad = _Ostr.width() <= 0 || _Ostr.width() <= _Count
		? 0 : _Ostr.width() - _Count;
	const typename _Myos::sentry _Ok(_Ostr);

	if (!_Ok)
		_State |= ios_base::badbit;
	else
		{	
		try {
		if ((_Ostr.flags() & ios_base::adjustfield) != ios_base::left)
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}

		if (_State == ios_base::goodbit
			&& _Ostr.rdbuf()->sputn(_Val, _Count) != _Count)
			_State |= ios_base::badbit;

		if (_State == ios_base::goodbit)
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}
		_Ostr.width(0);
		} catch (...) { (_Ostr).setstate(ios_base::badbit, true); }
		}

	_Ostr.setstate(_State);
	return (_Ostr);
	}

template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>& operator<<(
		basic_ostream<_Elem, _Traits>& _Ostr, _Elem _Ch)
	{	
	typedef basic_ostream<_Elem, _Traits> _Myos;

	ios_base::iostate _State = ios_base::goodbit;
	const typename _Myos::sentry _Ok(_Ostr);

	if (_Ok)
		{	
		streamsize _Pad = _Ostr.width() <= 1 ? 0 : _Ostr.width() - 1;

		try {
		if ((_Ostr.flags() & ios_base::adjustfield) != ios_base::left)
			for (; _State == ios_base::goodbit && 0 < _Pad;
				--_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					_State |= ios_base::badbit;

		if (_State == ios_base::goodbit
			&& _Traits::eq_int_type(_Traits::eof(),
				_Ostr.rdbuf()->sputc(_Ch)))
			_State |= ios_base::badbit;

		for (; _State == ios_base::goodbit && 0 < _Pad;
			--_Pad)	
			if (_Traits::eq_int_type(_Traits::eof(),
				_Ostr.rdbuf()->sputc(_Ostr.fill())))
				_State |= ios_base::badbit;
		} catch (...) { (_Ostr).setstate(ios_base::badbit, true); }
		}

	_Ostr.width(0);
	_Ostr.setstate(_State);
	return (_Ostr);
	}

template<class _Traits> inline
	basic_ostream<char, _Traits>& operator<<(
		basic_ostream<char, _Traits>& _Ostr, const signed char *_Val)
	{	
	return (_Ostr << (const char *)_Val);
	}

template<class _Traits> inline
	basic_ostream<char, _Traits>& operator<<(
		basic_ostream<char, _Traits>& _Ostr, signed char _Ch)
	{	
	return (_Ostr << (char)_Ch);
	}

template<class _Traits> inline
	basic_ostream<char, _Traits>& operator<<(
		basic_ostream<char, _Traits>& _Ostr, const unsigned char *_Val)
	{	
	return (_Ostr << (const char *)_Val);
	}

template<class _Traits> inline
	basic_ostream<char, _Traits>& operator<<(
		basic_ostream<char, _Traits>& _Ostr, unsigned char _Ch)
	{	
	return (_Ostr << (char)_Ch);
	}

template<class _Elem,
	class _Traits,
	class _Ty> inline
	basic_ostream<_Elem, _Traits>&
		operator<<(basic_ostream<_Elem, _Traits>&& _Ostr, _Ty _Val)
	{	
	return (_Ostr << _Val);
	}

		
template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>&
		__cdecl endl(basic_ostream<_Elem, _Traits>& _Ostr)
	{	
	_Ostr.put(_Ostr.widen('\n'));
	_Ostr.flush();
	return (_Ostr);
	}

template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>&
		__cdecl ends(basic_ostream<_Elem, _Traits>& _Ostr)
	{	
	_Ostr.put(_Elem());
	return (_Ostr);
	}

template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>&
		__cdecl flush(basic_ostream<_Elem, _Traits>& _Ostr)
	{	
	_Ostr.flush();
	return (_Ostr);
	}

 inline basic_ostream<char, char_traits<char> >&
	__cdecl endl(basic_ostream<char, char_traits<char> >& _Ostr)
	{	
	_Ostr.put('\n');
	_Ostr.flush();
	return (_Ostr);
	}

 inline basic_ostream<wchar_t, char_traits<wchar_t> >&
	__cdecl endl(basic_ostream<wchar_t,
		char_traits<wchar_t> >& _Ostr)
	{	
	_Ostr.put('\n');
	_Ostr.flush();
	return (_Ostr);
	}

 
 inline basic_ostream<unsigned short, char_traits<unsigned short> >&
	__cdecl endl(basic_ostream<unsigned short,
		char_traits<unsigned short> >& _Ostr)
	{	
	_Ostr.put('\n');
	_Ostr.flush();
	return (_Ostr);
	}
 #line 1029 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

 inline basic_ostream<char, char_traits<char> >&
	__cdecl ends(basic_ostream<char, char_traits<char> >& _Ostr)
	{	
	_Ostr.put('\0');
	return (_Ostr);
	}

 inline basic_ostream<wchar_t, char_traits<wchar_t> >&
	__cdecl ends(basic_ostream<wchar_t,
		char_traits<wchar_t> >& _Ostr)
	{	
	_Ostr.put('\0');
	return (_Ostr);
	}

 
 inline basic_ostream<unsigned short, char_traits<unsigned short> >&
	__cdecl ends(basic_ostream<unsigned short,
		char_traits<unsigned short> >& _Ostr)
	{	
	_Ostr.put('\0');
	return (_Ostr);
	}
 #line 1054 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

 inline basic_ostream<char, char_traits<char> >&
	__cdecl flush(basic_ostream<char, char_traits<char> >& _Ostr)
	{	
	_Ostr.flush();
	return (_Ostr);
	}

 inline basic_ostream<wchar_t, char_traits<wchar_t> >&
	__cdecl flush(basic_ostream<wchar_t,
		char_traits<wchar_t> >& _Ostr)
	{	
	_Ostr.flush();
	return (_Ostr);
	}

 
 inline basic_ostream<unsigned short, char_traits<unsigned short> >&
	__cdecl flush(basic_ostream<unsigned short,
		char_traits<unsigned short> >& _Ostr)
	{	
	_Ostr.flush();
	return (_Ostr);
	}
 #line 1079 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"

 
		
template<class _Elem,
	class _Traits> inline
	basic_ostream<_Elem, _Traits>&
		operator<<(basic_ostream<_Elem, _Traits>& _Ostr,
			const error_code& _Errcode)
	{	
	return (_Ostr << _Errcode.category().name() << ':' << _Errcode.value());
	}
 #line 1091 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 1097 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"
#line 1098 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\ostream"






#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"

 #pragma pack(push,8)
 #pragma warning(push,3)

 #pragma warning(disable: 4189)

namespace std {
		
template<class _Elem,
	class _Traits>
	class basic_istream
		: virtual public basic_ios<_Elem, _Traits>
	{	
public:
	typedef basic_istream<_Elem, _Traits> _Myt;
	typedef basic_ios<_Elem, _Traits> _Myios;
	typedef basic_streambuf<_Elem, _Traits> _Mysb;
	typedef istreambuf_iterator<_Elem, _Traits> _Iter;
	typedef ctype<_Elem> _Ctype;
	typedef num_get<_Elem, _Iter> _Nget;


	explicit  basic_istream(_Mysb *_Strbuf,
		bool _Isstd = false)

		: _Chcount(0)
		{	
		_Myios::init(_Strbuf, _Isstd);
		}

	 basic_istream(_Uninitialized)
		{	
		ios_base::_Addstd(this);
		}

	 basic_istream(_Myt&& _Right)
		: _Chcount(_Right._Chcount)
		{	
		_Myios::init();
		_Myios::move(::std:: move(_Right));
		_Right._Chcount = 0;
		}

	_Myt&  operator=(_Myt&& _Right)
		{	
		this->swap(_Right);
		return (*this);
		}

	void  swap(_Myt& _Right)
		{	
		_Myios::swap(_Right);
		::std:: swap(_Chcount, _Right._Chcount);
		}

	virtual  ~basic_istream()
		{	
		}

	typedef typename _Traits::int_type int_type;
	typedef typename _Traits::pos_type pos_type;
	typedef typename _Traits::off_type off_type;

		
	class _Sentry_base
		{	
	public:
		 _Sentry_base(_Myt& _Istr)
			: _Myistr(_Istr)
			{	
			if (_Myistr.rdbuf() != 0)
				_Myistr.rdbuf()->_Lock();
			}

		 ~_Sentry_base()
			{	
			if (_Myistr.rdbuf() != 0)
				_Myistr.rdbuf()->_Unlock();
			}

		_Myt& _Myistr;	

	private:
		_Sentry_base& operator=(const _Sentry_base&);
		};

	class sentry
		: public _Sentry_base
		{	
	public:
		explicit  sentry(_Myt& _Istr, bool _Noskip = false)
			: _Sentry_base(_Istr)
			{	
			_Ok = this->_Myistr._Ipfx(_Noskip);
			}

		 operator ::std:: _Bool_type() const
			{	
			return (_Ok ? (&::std:: _Bool_struct::_Member) : 0);
			}

	private:
		bool _Ok;	

		 sentry(const sentry&);	
		sentry&  operator=(const sentry&);	
		};

	bool  _Ipfx(bool _Noskip = false)
		{	
		if (ios_base::good())
			{	
			if (_Myios::tie() != 0)
				_Myios::tie()->flush();

			if (!_Noskip && ios_base::flags() & ios_base::skipws)
				{	
				const _Ctype& _Ctype_fac = use_facet< _Ctype >(ios_base::getloc());

				try {
				int_type _Meta = _Myios::rdbuf()->sgetc();

				for (; ; _Meta = _Myios::rdbuf()->snextc())
					if (_Traits::eq_int_type(_Traits::eof(), _Meta))
						{	
						_Myios::setstate(ios_base::eofbit);
						break;
						}
					else if (!_Ctype_fac.is(_Ctype::space,
						_Traits::to_char_type(_Meta)))
						break;	
				} catch (...) { _Myios::setstate(ios_base::badbit, true); }
				}

			if (ios_base::good())
				return (true);
			}
		_Myios::setstate(ios_base::failbit);
		return (false);
		}

	bool  ipfx(bool _Noskip = false)
		{	
		return (_Ipfx(_Noskip));
		}

	void  isfx()
		{	
		}

  





















	_Myt&  operator>>(_Myt& (__cdecl *_Pfn)(_Myt&))
		{	
		;
		return ((*_Pfn)(*this));
		}

	_Myt&  operator>>(_Myios& (__cdecl *_Pfn)(_Myios&))
		{	
		;
		(*_Pfn)(*(_Myios *)this);
		return (*this);
		}

	_Myt&  operator>>(ios_base& (__cdecl *_Pfn)(ios_base&))
		{	
		;
		(*_Pfn)(*(ios_base *)this);
		return (*this);
		}

	_Myt&  operator>>(_Bool& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(short& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			long _Tmp = 0;
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Tmp);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }

			if (_State & ios_base::failbit
				|| _Tmp < (-32768) || 32767 < _Tmp)
				_State |= ios_base::failbit;
			else
				_Val = (short)_Tmp;
			}

		_Myios::setstate(_State);
		return (*this);
		}










	_Myt&  operator>>(unsigned short& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(int& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			long _Tmp = 0;
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Tmp);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }

			if (_State & ios_base::failbit
				|| _Tmp < (-2147483647 - 1) || 2147483647 < _Tmp)
				_State |= ios_base::failbit;
			else
				_Val = _Tmp;
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(unsigned int& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(long& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());
			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(unsigned long& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

 
	_Myt&  operator>>(__int64& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(unsigned __int64& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}
 #line 391 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"

	_Myt&  operator>>(float& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(double& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);
		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(long double& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());
			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(void *& _Val)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const sentry _Ok(*this);

		if (_Ok)
			{	
			const _Nget& _Nget_fac = use_facet< _Nget >(ios_base::getloc());

			try {
			_Nget_fac.get(_Iter(_Myios::rdbuf()), _Iter(0),
				*this, _State, _Val);
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  operator>>(_Mysb *_Strbuf)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		bool _Copied = false;
		const sentry _Ok(*this);

		if (_Ok && _Strbuf != 0)
			{	
			try {
			int_type _Meta = _Myios::rdbuf()->sgetc();

			for (; ; _Meta = _Myios::rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else
					{	
					try {
						if (_Traits::eq_int_type(_Traits::eof(),
							_Strbuf->sputc(_Traits::to_char_type(_Meta))))
							break;
					} catch (...) {
						break;
					}
					_Copied = true;
					}
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(!_Copied ? _State | ios_base::failbit : _State);
		return (*this);
		}

	int_type  get()
		{	
		int_type _Meta = 0;
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (!_Ok)
			_Meta = _Traits::eof();	
		else
			{	
			try {
			_Meta = _Myios::rdbuf()->sgetc();

			if (_Traits::eq_int_type(_Traits::eof(), _Meta))
				_State |= ios_base::eofbit | ios_base::failbit;	
			else
				{	
				_Myios::rdbuf()->sbumpc();
				++_Chcount;
				}
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (_Meta);
		}

	_Myt&  get(_Elem *_Str, streamsize _Count)
		{	
		return (get(_Str, _Count, _Myios::widen('\n')));
		}

	_Myt&  get(_Elem *_Str,
		streamsize _Count, _Elem _Delim)
		{	
		;
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (_Ok && 0 < _Count)
			{	
			try {
			int_type _Meta = _Myios::rdbuf()->sgetc();

			for (; 0 < --_Count; _Meta = _Myios::rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else if (_Traits::to_char_type(_Meta) == _Delim)
					break;	
				else
					{	
					*_Str++ = _Traits::to_char_type(_Meta);
					++_Chcount;
					}
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_Chcount == 0
			? _State | ios_base::failbit : _State);
		*_Str = _Elem();	
		return (*this);
		}

	_Myt&  get(_Elem& _Ch)
		{	
		int_type _Meta = get();
		if (!_Traits::eq_int_type(_Traits::eof(), _Meta))
			_Ch = _Traits::to_char_type(_Meta);
		return (*this);
		}

	_Myt&  get(_Mysb& _Strbuf)
		{	
		return (get(_Strbuf, _Myios::widen('\n')));
		}

	_Myt&  get(_Mysb& _Strbuf, _Elem _Delim)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (_Ok)
			{	
			try {
			int_type _Meta = _Myios::rdbuf()->sgetc();

			for (; ; _Meta = _Myios::rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else
					{	
					try {
						_Elem _Ch = _Traits::to_char_type(_Meta);
						if (_Ch == _Delim
							|| _Traits::eq_int_type(_Traits::eof(),
								_Strbuf.sputc(_Ch)))
							break;
					} catch (...) {
						break;
					}
					++_Chcount;
					}
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		if (_Chcount == 0)
			_State |= ios_base::failbit;
		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  getline(_Elem *_Str, streamsize _Count)
		{	
		return (getline(_Str, _Count, _Myios::widen('\n')));
		}

	_Myt&  getline(_Elem *_Str,
		streamsize _Count, _Elem _Delim)
		{	
		;
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (_Ok && 0 < _Count)
			{	
			int_type _Metadelim = _Traits::to_int_type(_Delim);

			try {
			int_type _Meta = _Myios::rdbuf()->sgetc();

			for (; ; _Meta = _Myios::rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else if (_Meta == _Metadelim)
					{	
					++_Chcount;
					_Myios::rdbuf()->sbumpc();
					break;
					}
				else if (--_Count <= 0)
					{	
					_State |= ios_base::failbit;
					break;
					}
				else
					{	
					++_Chcount;
					*_Str++ = _Traits::to_char_type(_Meta);
					}
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		*_Str = _Elem();	
		_Myios::setstate(_Chcount == 0 ? _State | ios_base::failbit : _State);
		return (*this);
		}

	_Myt&  ignore(streamsize _Count = 1,
		int_type _Metadelim = _Traits::eof())
		{	
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (_Ok && 0 < _Count)
			{	
			try {
			for (; ; )
				{	
				int_type _Meta;
				if (_Count != 2147483647 && --_Count < 0)
					break;	
				else if (_Traits::eq_int_type(_Traits::eof(),
					_Meta = _Myios::rdbuf()->sbumpc()))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else
					{	
					++_Chcount;
					if (_Meta == _Metadelim)
						break;	
					}
				}
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  read(_Elem *_Str, streamsize _Count)
		{	
		;
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (_Ok)
			{	
			try {
			const streamsize _Num = _Myios::rdbuf()->sgetn(_Str, _Count);
			_Chcount += _Num;
			if (_Num != _Count)
				_State |= ios_base::eofbit | ios_base::failbit;	
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	streamsize  readsome(_Elem *_Str,
		streamsize _Count)
		{	
		;
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);
		streamsize _Num;

		if (!_Ok)
			_State |= ios_base::failbit;	
		else if ((_Num = _Myios::rdbuf()->in_avail()) < 0)
			_State |= ios_base::eofbit;	
		else if (0 < _Num)
			read(_Str, _Num < _Count ? _Num : _Count);	

		_Myios::setstate(_State);
		return (gcount());
		}

	int_type  peek()
		{	
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		int_type _Meta = 0;
		const sentry _Ok(*this, true);

		if (!_Ok)
			_Meta = _Traits::eof();	
		else
			{	
			try {
			if (_Traits::eq_int_type(_Traits::eof(),
				_Meta = _Myios::rdbuf()->sgetc()))
				_State |= ios_base::eofbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (_Meta);
		}

	_Myt&  putback(_Elem _Ch)
		{	
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (_Ok)
			{	
			try {
			if (_Traits::eq_int_type(_Traits::eof(),
				_Myios::rdbuf()->sputbackc(_Ch)))
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	_Myt&  unget()
		{	
		ios_base::iostate _State = ios_base::goodbit;
		_Chcount = 0;
		const sentry _Ok(*this, true);

		if (_Ok)
			{	
			try {
			if (_Traits::eq_int_type(_Traits::eof(),
				_Myios::rdbuf()->sungetc()))
				_State |= ios_base::badbit;
			} catch (...) { _Myios::setstate(ios_base::badbit, true); }
			}

		_Myios::setstate(_State);
		return (*this);
		}

	streamsize  gcount() const
		{	
		return (_Chcount);
		}

	int  sync()
		{	
		ios_base::iostate _State = ios_base::goodbit;
		int _Ans;

		if (_Myios::rdbuf() == 0)
			_Ans = -1;	
		else if (_Myios::rdbuf()->pubsync() == -1)
			{	
			_State |= ios_base::badbit;
			_Ans = -1;
			}
		else
			_Ans = 0;	

		_Myios::setstate(_State);
		return (_Ans);
		}

	_Myt&  seekg(pos_type _Pos)
		{	
		if (!ios_base::fail()
			&& (off_type)_Myios::rdbuf()->pubseekpos(_Pos,
				ios_base::in) == _BADOFF)
			_Myios::setstate(ios_base::failbit);
		return (*this);
		}

	_Myt&  seekg(off_type _Off, ios_base::seekdir _Way)
		{	
		if (!ios_base::fail()
			&& (off_type)_Myios::rdbuf()->pubseekoff(_Off, _Way,
				ios_base::in) == _BADOFF)
			_Myios::setstate(ios_base::failbit);
		return (*this);
		}

	pos_type  tellg()
		{	
		if (!ios_base::fail())
			return (_Myios::rdbuf()->pubseekoff(0,
				ios_base::cur, ios_base::in));
		else
			return (pos_type(_BADOFF));
		}

private:
	streamsize _Chcount;	
	};

	
template<class _Elem,
	class _Traits> inline
	void swap(basic_istream<_Elem, _Traits>& _Left,
		basic_istream<_Elem, _Traits>& _Right)
	{	
	_Left.swap(_Right);
	}

  




































 







#line 917 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"

		
template<class _Elem,
	class _Traits>
	class basic_iostream
	: public basic_istream<_Elem, _Traits>,
		public basic_ostream<_Elem, _Traits>
	{	
public:
	typedef basic_iostream<_Elem, _Traits> _Myt;
	typedef basic_istream<_Elem, _Traits> _Myis;
	typedef basic_ostream<_Elem, _Traits> _Myos;
	typedef basic_ios<_Elem, _Traits> _Myios;
	typedef _Elem char_type;
	typedef _Traits traits_type;
	typedef typename _Traits::int_type int_type;
	typedef typename _Traits::pos_type pos_type;
	typedef typename _Traits::off_type off_type;

	explicit  basic_iostream(basic_streambuf<_Elem, _Traits> *_Strbuf)
		: _Myis(_Strbuf, false),
			_Myos(_Noinit, false)
		{	
		}

	 basic_iostream(_Myt&& _Right)
		: _Myis(_Right.rdbuf(), false),
			_Myos(_Noinit, false)
		{	
		_Myios::init();
		_Myios::move(::std:: forward<_Myt>(_Right));
		}

	_Myt&  operator=(_Myt&& _Right)
		{	
		this->swap(_Right);
		return (*this);
		}

	void  swap(_Myt& _Right)
		{	
		if (this != &_Right)
			_Myios::swap(_Right);
		}

	virtual  ~basic_iostream()
		{	
		}
	};

	
template<class _Elem,
	class _Traits> inline
	void swap(basic_iostream<_Elem, _Traits>& _Left,
		basic_iostream<_Elem, _Traits>& _Right)
	{	
	_Left.swap(_Right);
	}

 





#line 983 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"

		
template<class _Elem,
	class _Traits> inline
	basic_istream<_Elem, _Traits>& operator>>(
		basic_istream<_Elem, _Traits> && _Istr, _Elem *_Str)
	{	
	;
	typedef basic_istream<_Elem, _Traits> _Myis;
	typedef ctype<_Elem> _Ctype;
	ios_base::iostate _State = ios_base::goodbit;
	_Elem *_Str0 = _Str;
	const typename _Myis::sentry _Ok(_Istr);

	if (_Ok)
		{	
		const _Ctype& _Ctype_fac = use_facet< _Ctype >(_Istr.getloc());

		try {
		streamsize _Count = 0 < _Istr.width() ? _Istr.width() : 2147483647;
		typename _Myis::int_type _Meta = _Istr.rdbuf()->sgetc();
		_Elem _Ch;
		for (; 0 < --_Count; _Meta = _Istr.rdbuf()->snextc())
			if (_Traits::eq_int_type(_Traits::eof(), _Meta))
				{	
				_State |= ios_base::eofbit;
				break;
				}
			else if (_Ctype_fac.is(_Ctype::space,
				_Ch = _Traits::to_char_type(_Meta))
					|| _Ch == _Elem())
				break;	
			else
				*_Str++ = _Traits::to_char_type(_Meta);	
		} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
		}

	*_Str = _Elem();	
	_Istr.width(0);
	_Istr.setstate(_Str == _Str0 ? _State | ios_base::failbit : _State);
	return (_Istr);
	}

template<class _Elem,
	class _Traits> inline
	basic_istream<_Elem, _Traits>& operator>>(
		basic_istream<_Elem, _Traits> && _Istr, _Elem& _Ch)
	{	
	typedef basic_istream<_Elem, _Traits> _Myis;

	typename _Myis::int_type _Meta;
	ios_base::iostate _State = ios_base::goodbit;
	const typename _Myis::sentry _Ok(_Istr);

	if (_Ok)
		{	
		try {
		_Meta = _Istr.rdbuf()->sbumpc();
		if (_Traits::eq_int_type(_Traits::eof(), _Meta))
			_State |= ios_base::eofbit | ios_base::failbit;	
		else
			_Ch = _Traits::to_char_type(_Meta);	
		} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
		}

	_Istr.setstate(_State);
	return (_Istr);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits> && _Istr, signed char *_Str)
	{	
	return (_Istr >> (char *)_Str);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits> && _Istr, signed char& _Ch)
	{	
	return (_Istr >> (char&)_Ch);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits> && _Istr, unsigned char *_Str)
	{	
	return (_Istr >> (char *)_Str);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits> && _Istr, unsigned char& _Ch)
	{	
	return (_Istr >> (char&)_Ch);
	}

template<class _Elem,
	class _Traits> inline
	basic_istream<_Elem, _Traits>& operator>>(
		basic_istream<_Elem, _Traits>& _Istr, _Elem *_Str)
	{	
	return (::std:: move(_Istr) >> _Str);
	}

template<class _Elem,
	class _Traits> inline
	basic_istream<_Elem, _Traits>& operator>>(
		basic_istream<_Elem, _Traits>& _Istr, _Elem& _Ch)
	{	
	return (::std:: move(_Istr) >> _Ch);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits>& _Istr, signed char *_Str)
	{	
	return (::std:: move(_Istr) >> (char *)_Str);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits>& _Istr, signed char& _Ch)
	{	
	return (::std:: move(_Istr) >> (char&)_Ch);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits>& _Istr, unsigned char *_Str)
	{	
	return (::std:: move(_Istr) >> (char *)_Str);
	}

template<class _Traits> inline
	basic_istream<char, _Traits>& operator>>(
		basic_istream<char, _Traits>& _Istr, unsigned char& _Ch)
	{	
	return (::std:: move(_Istr) >> (char&)_Ch);
	}

template<class _Elem,
	class _Traits,
	class _Ty> inline
	basic_istream<_Elem, _Traits>&
		operator>>(basic_istream<_Elem, _Traits>&& _Istr, _Ty& _Val)
	{	
	return (_Istr >> _Val);
	}

		
template<class _Elem,
	class _Traits> inline
	basic_istream<_Elem, _Traits>&
		__cdecl ws(basic_istream<_Elem, _Traits>& _Istr)
	{	
	typedef basic_istream<_Elem, _Traits> _Myis;
	typedef ctype<_Elem> _Ctype;

	if (!_Istr.eof())
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const typename _Myis::sentry _Ok(_Istr, true);

		if (_Ok)
			{	
			const _Ctype& _Ctype_fac = use_facet< _Ctype >(_Istr.getloc());

			try {
			for (typename _Traits::int_type _Meta = _Istr.rdbuf()->sgetc(); ;
				_Meta = _Istr.rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else if (!_Ctype_fac.is(_Ctype::space,
					_Traits::to_char_type(_Meta)))
					break;	
			} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
			}

		_Istr.setstate(_State);
		}
	return (_Istr);
	}

 inline basic_istream<char, char_traits<char> >&
	__cdecl ws(basic_istream<char, char_traits<char> >& _Istr)
	{	
	typedef char _Elem;
	typedef char_traits<_Elem> _Traits;

	if (!_Istr.eof())
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const basic_istream<_Elem, _Traits>::sentry _Ok(_Istr, true);

		if (_Ok)
			{	
			const ctype<_Elem>& _Ctype_fac =
				use_facet< ctype<_Elem> >(_Istr.getloc());

			try {
			for (_Traits::int_type _Meta = _Istr.rdbuf()->sgetc(); ;
				_Meta = _Istr.rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else if (!_Ctype_fac.is(ctype<_Elem>::space,
					_Traits::to_char_type(_Meta)))
					break;	
			} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
			}

		_Istr.setstate(_State);
		}
	return (_Istr);
	}

 inline basic_istream<wchar_t, char_traits<wchar_t> >&
	__cdecl ws(basic_istream<wchar_t, char_traits<wchar_t> >& _Istr)
	{	
	typedef wchar_t _Elem;
	typedef char_traits<_Elem> _Traits;

	if (!_Istr.eof())
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const basic_istream<_Elem, _Traits>::sentry _Ok(_Istr, true);

		if (_Ok)
			{	
			const ctype<_Elem>& _Ctype_fac =
				use_facet< ctype<_Elem> >(_Istr.getloc());

			try {
			for (_Traits::int_type _Meta = _Istr.rdbuf()->sgetc(); ;
				_Meta = _Istr.rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else if (!_Ctype_fac.is(ctype<_Elem>::space,
					_Traits::to_char_type(_Meta)))
					break;	
			} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
			}

		_Istr.setstate(_State);
		}
	return (_Istr);
	}

 
 inline basic_istream<unsigned short, char_traits<unsigned short> >&
	__cdecl ws(basic_istream<unsigned short, char_traits<unsigned short> >& _Istr)
	{	
	typedef unsigned short _Elem;
	typedef char_traits<_Elem> _Traits;

	if (!_Istr.eof())
		{	
		ios_base::iostate _State = ios_base::goodbit;
		const basic_istream<_Elem, _Traits>::sentry _Ok(_Istr, true);

		if (_Ok)
			{	
			const ctype<_Elem>& _Ctype_fac =
				use_facet< ctype<_Elem> >(_Istr.getloc());

			try {
			for (_Traits::int_type _Meta = _Istr.rdbuf()->sgetc(); ;
				_Meta = _Istr.rdbuf()->snextc())
				if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{	
					_State |= ios_base::eofbit;
					break;
					}
				else if (!_Ctype_fac.is(ctype<_Elem>::space,
					_Traits::to_char_type(_Meta)))
					break;	
		} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
			}

		_Istr.setstate(_State);
		}
	return (_Istr);
	}
 #line 1276 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 1282 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"
#line 1283 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\istream"






#line 7 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string"

 #pragma pack(push,8)
 #pragma warning(push,3)

 #pragma warning(disable: 4189)
 #pragma warning(disable: 4172)

namespace std {
		
template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	basic_string<_Elem, _Traits, _Alloc> _Ans;
	_Ans.reserve(_Left.size() + _Right.size());
	_Ans += _Left;
	_Ans += _Right;
	return (_Ans);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const _Elem *_Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	basic_string<_Elem, _Traits, _Alloc> _Ans;
	_Ans.reserve(_Traits::length(_Left) + _Right.size());
	_Ans += _Left;
	_Ans += _Right;
	return (_Ans);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const _Elem _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	basic_string<_Elem, _Traits, _Alloc> _Ans;
	_Ans.reserve(1 + _Right.size());
	_Ans += _Left;
	_Ans += _Right;
	return (_Ans);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem *_Right)
	{	
	basic_string<_Elem, _Traits, _Alloc> _Ans;
	_Ans.reserve(_Left.size() + _Traits::length(_Right));
	_Ans += _Left;
	_Ans += _Right;
	return (_Ans);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem _Right)
	{	
	basic_string<_Elem, _Traits, _Alloc> _Ans;
	_Ans.reserve(_Left.size() + 1);
	_Ans += _Left;
	_Ans += _Right;
	return (_Ans);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{	
	return (::std:: move(_Right.insert(0, _Left)));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		basic_string<_Elem, _Traits, _Alloc>&& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (::std:: move(_Left.append(_Right)));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		basic_string<_Elem, _Traits, _Alloc>&& _Left,
		basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{	
	if (_Right.size() <= _Left.capacity() - _Left.size()
		|| _Right.capacity() - _Right.size() < _Left.size())
		return (::std:: move(_Left.append(_Right)));
	else
		return (::std:: move(_Right.insert(0, _Left)));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const _Elem *_Left,
		basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{	
	return (::std:: move(_Right.insert(0, _Left)));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		const _Elem _Left,
		basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{	
	return (::std:: move(_Right.insert(0, 1, _Left)));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		basic_string<_Elem, _Traits, _Alloc>&& _Left,
		const _Elem *_Right)
	{	
	return (::std:: move(_Left.append(_Right)));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_string<_Elem, _Traits, _Alloc> operator+(
		basic_string<_Elem, _Traits, _Alloc>&& _Left,
		const _Elem _Right)
	{	
	return (::std:: move(_Left.append(1, _Right)));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator==(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (_Left.compare(_Right) == 0);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator==(
		const _Elem * _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (_Right.compare(_Left) == 0);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator==(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem *_Right)
	{	
	return (_Left.compare(_Right) == 0);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator!=(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator!=(
		const _Elem *_Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (!(_Left == _Right));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator!=(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem *_Right)
	{	
	return (!(_Left == _Right));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator<(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (_Left.compare(_Right) < 0);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator<(
		const _Elem * _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (_Right.compare(_Left) > 0);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator<(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem *_Right)
	{	
	return (_Left.compare(_Right) < 0);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator>(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (_Right < _Left);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator>(
		const _Elem * _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (_Right < _Left);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator>(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem *_Right)
	{	
	return (_Right < _Left);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator<=(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (!(_Right < _Left));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator<=(
		const _Elem * _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (!(_Right < _Left));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator<=(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem *_Right)
	{	
	return (!(_Right < _Left));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator>=(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (!(_Left < _Right));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator>=(
		const _Elem * _Left,
		const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	
	return (!(_Left < _Right));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	bool operator>=(
		const basic_string<_Elem, _Traits, _Alloc>& _Left,
		const _Elem *_Right)
	{	
	return (!(_Left < _Right));
	}

		
template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_istream<_Elem, _Traits>& operator>>(
		basic_istream<_Elem, _Traits> && _Istr,
		basic_string<_Elem, _Traits, _Alloc>& _Str)
	{	
	typedef ctype<_Elem> _Ctype;
	typedef basic_istream<_Elem, _Traits> _Myis;
	typedef basic_string<_Elem, _Traits, _Alloc> _Mystr;
	typedef typename _Mystr::size_type _Mysizt;

	ios_base::iostate _State = ios_base::goodbit;
	bool _Changed = false;
	const typename _Myis::sentry _Ok(_Istr);

	if (_Ok)
		{	
		const _Ctype& _Ctype_fac = use_facet< _Ctype >(_Istr.getloc());
		_Str.erase();

		try {
		_Mysizt _Size = 0 < _Istr.width()
			&& (_Mysizt)_Istr.width() < _Str.max_size()
				? (_Mysizt)_Istr.width() : _Str.max_size();
		typename _Traits::int_type _Meta = _Istr.rdbuf()->sgetc();

		for (; 0 < _Size; --_Size, _Meta = _Istr.rdbuf()->snextc())
			if(_Traits::eq_int_type(_Traits::eof(), _Meta))
				{	
				_State |= ios_base::eofbit;
				break;
				}
			else if (_Ctype_fac.is(_Ctype::space,
				_Traits::to_char_type(_Meta)))
				break;	
			else
				{	
				_Str.append(1, _Traits::to_char_type(_Meta));
				_Changed = true;
				}
		} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
		}

	_Istr.width(0);
	if (!_Changed)
		_State |= ios_base::failbit;
	_Istr.setstate(_State);
	return (_Istr);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_istream<_Elem, _Traits>& getline(
		basic_istream<_Elem, _Traits> && _Istr,
		basic_string<_Elem, _Traits, _Alloc>& _Str,
		const _Elem _Delim)
	{	
	typedef basic_istream<_Elem, _Traits> _Myis;

	ios_base::iostate _State = ios_base::goodbit;
	bool _Changed = false;
	const typename _Myis::sentry _Ok(_Istr, true);

	if (_Ok)
		{	
		try {
		_Str.erase();
		const typename _Traits::int_type _Metadelim =
			_Traits::to_int_type(_Delim);
		typename _Traits::int_type _Meta = _Istr.rdbuf()->sgetc();

		for (; ; _Meta = _Istr.rdbuf()->snextc())
			if (_Traits::eq_int_type(_Traits::eof(), _Meta))
				{	
				_State |= ios_base::eofbit;
				break;
				}
			else if (_Traits::eq_int_type(_Meta, _Metadelim))
				{	
				_Changed = true;
				_Istr.rdbuf()->sbumpc();
				break;
				}
			else if (_Str.max_size() <= _Str.size())
				{	
				_State |= ios_base::failbit;
				break;
				}
			else
				{	
				_Str += _Traits::to_char_type(_Meta);
				_Changed = true;
				}
		} catch (...) { (_Istr).setstate(ios_base::badbit, true); }
		}

	if (!_Changed)
		_State |= ios_base::failbit;
	_Istr.setstate(_State);
	return (_Istr);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_istream<_Elem, _Traits>& getline(
		basic_istream<_Elem, _Traits> && _Istr,
		basic_string<_Elem, _Traits, _Alloc>& _Str)
	{	
	return (getline(_Istr, _Str, _Istr.widen('\n')));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_istream<_Elem, _Traits>& operator>>(
		basic_istream<_Elem, _Traits>& _Istr,
		basic_string<_Elem, _Traits, _Alloc>& _Str)
	{	
	return (::std:: move(_Istr) >> _Str);
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_istream<_Elem, _Traits>& getline(
		basic_istream<_Elem, _Traits>& _Istr,
		basic_string<_Elem, _Traits, _Alloc>& _Str,
		const _Elem _Delim)
	{	
	return (getline(::std:: move(_Istr), _Str, _Delim));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_istream<_Elem, _Traits>& getline(
		basic_istream<_Elem, _Traits>& _Istr,
		basic_string<_Elem, _Traits, _Alloc>& _Str)
	{	
	return (getline(::std:: move(_Istr), _Str, _Istr.widen('\n')));
	}

template<class _Elem,
	class _Traits,
	class _Alloc> inline
	basic_ostream<_Elem, _Traits>& operator<<(
		basic_ostream<_Elem, _Traits>& _Ostr,
		const basic_string<_Elem, _Traits, _Alloc>& _Str)
	{	
	typedef basic_ostream<_Elem, _Traits> _Myos;
	typedef basic_string<_Elem, _Traits, _Alloc> _Mystr;
	typedef typename _Mystr::size_type _Mysizt;

	ios_base::iostate _State = ios_base::goodbit;
	_Mysizt _Size = _Str.size();
	_Mysizt _Pad = _Ostr.width() <= 0 || (_Mysizt)_Ostr.width() <= _Size
		? 0 : (_Mysizt)_Ostr.width() - _Size;
	const typename _Myos::sentry _Ok(_Ostr);

	if (!_Ok)
		_State |= ios_base::badbit;
	else
		{	
	try {
		if ((_Ostr.flags() & ios_base::adjustfield) != ios_base::left)
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}

		if (_State == ios_base::goodbit
			&& _Ostr.rdbuf()->sputn(_Str.c_str(), _Size) != (streamsize)_Size)
				_State |= ios_base::badbit;
		else
			for (; 0 < _Pad; --_Pad)	
				if (_Traits::eq_int_type(_Traits::eof(),
					_Ostr.rdbuf()->sputc(_Ostr.fill())))
					{	
					_State |= ios_base::badbit;
					break;
					}
		_Ostr.width(0);
		} catch (...) { (_Ostr).setstate(ios_base::badbit, true); }
		}

	_Ostr.setstate(_State);
	return (_Ostr);
	}

 
inline int stoi(const string& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	const char *_Ptr = _Str.c_str();
	char *_Eptr;
	int _Errno = 0;
	long _Ans = :: _Stolx(_Ptr, &_Eptr, _Base, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stoi argument");
	if (_Errno || _Ans < (-2147483647 - 1) != 2147483647 < _Ans)
		_Xout_of_range("stoi argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return ((int)_Ans);
	}

inline long stol(const string& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	const char *_Ptr = _Str.c_str();
	char *_Eptr;
	int _Errno = 0;
	long _Ans = :: _Stoulx(_Ptr, &_Eptr, _Base, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stol argument");
	if (_Errno)
		_Xout_of_range("stol argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
	}

inline unsigned long stoul(const string& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	const char *_Ptr = _Str.c_str();
	char *_Eptr;
	int _Errno = 0;
	unsigned long _Ans = :: _Stoulx(_Ptr, &_Eptr, _Base, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stoul argument");
	if (_Errno)
		_Xout_of_range("stoul argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
	}

inline _Longlong stoll(const string& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	const char *_Ptr = _Str.c_str();
	char *_Eptr;
	int _Errno = 0;
	_Longlong _Ans = :: _Stollx(_Ptr, &_Eptr, _Base, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stoll argument");
	if (_Errno)
		_Xout_of_range("stoll argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
	}

inline _ULonglong stoull(const string& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	const char *_Ptr = _Str.c_str();
	int _Errno = 0;
	char *_Eptr;
	_ULonglong _Ans = :: _Stoullx(_Ptr, &_Eptr, _Base, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stoull argument");
	if (_Errno)
		_Xout_of_range("stoull argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
	}

inline float stof(const string& _Str, size_t *_Idx = 0)
	{	
	const char *_Ptr = _Str.c_str();
	int _Errno = 0;
	char *_Eptr;
	float _Ans = :: _Stofx(_Ptr, &_Eptr, 0, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stof argument");
	if (_Errno)
		_Xout_of_range("stof argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
	}

inline double stod(const string& _Str, size_t *_Idx = 0)
	{	
	const char *_Ptr = _Str.c_str();
	int _Errno = 0;
	char *_Eptr;
	double _Ans = :: _Stodx(_Ptr, &_Eptr, 0, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stod argument");
	if (_Errno)
		_Xout_of_range("stod argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
	}

inline long double stold(const string& _Str, size_t *_Idx = 0)
	{	
	const char *_Ptr = _Str.c_str();
	int _Errno = 0;
	char *_Eptr;
	long double _Ans = :: _Stoldx(_Ptr, &_Eptr, 0, &_Errno);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stold argument");
	if (_Errno)
		_Xout_of_range("stold argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
	}

 

inline string to_string(_Longlong _Val)
	{	
	char _Buf[2 * 32];

	:: sprintf_s(_Buf, sizeof (_Buf), "%I64" "d", _Val);
	return (string(_Buf));
	}

inline string to_string(_ULonglong _Val)
	{	
	char _Buf[2 * 32];

	:: sprintf_s(_Buf, sizeof (_Buf), "%I64" "u", _Val);
	return (string(_Buf));
	}

inline string to_string(long double _Val)
	{	
	char _Buf[8 + 36 + 64];

	:: sprintf_s(_Buf, sizeof (_Buf), "%Lg", _Val);
	return (string(_Buf));
	}

	
inline string _Narrow_str(wstring _Str)
	{	
	string _Ans;

	for (const wchar_t *_Ptr = _Str.c_str(); *_Ptr != 0; ++_Ptr)
		_Ans.push_back((char):: wctob(*_Ptr));
	return (_Ans);
	}

inline int stoi(const wstring& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	return (stoi(_Narrow_str(_Str), _Idx, _Base));
	}

inline long stol(const wstring& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	return (stol(_Narrow_str(_Str), _Idx, _Base));
	}

inline unsigned long stoul(const wstring& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	return (stoul(_Narrow_str(_Str), _Idx, _Base));
	}

inline _Longlong stoll(const wstring& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	return (stoll(_Narrow_str(_Str), _Idx, _Base));
	}

inline _ULonglong stoull(const wstring& _Str, size_t *_Idx = 0,
	int _Base = 10)
	{	
	return (stoull(_Narrow_str(_Str), _Idx, _Base));
	}

inline float stof(const wstring& _Str, size_t *_Idx = 0)
	{	
	return (stof(_Narrow_str(_Str), _Idx));
	}

inline double stod(const wstring& _Str, size_t *_Idx = 0)
	{	
	return (stod(_Narrow_str(_Str), _Idx));
	}

inline long double stold(const wstring& _Str, size_t *_Idx = 0)
	{	
	return (stold(_Narrow_str(_Str), _Idx));
	}

 

inline wstring to_wstring(_Longlong _Val)
	{	
	wchar_t _Buf[2 * 32];

	:: swprintf(_Buf, sizeof (_Buf) / sizeof (_Buf[0]),
		L"%I64" L"d", _Val);
	return (wstring(_Buf));
	}

inline wstring to_wstring(_ULonglong _Val)
	{	
	wchar_t _Buf[2 * 32];

	:: swprintf(_Buf, sizeof (_Buf) / sizeof (_Buf[0]),
		L"%I64" L"u", _Val);
	return (wstring(_Buf));
	}

inline wstring to_wstring(long double _Val)
	{	
	wchar_t _Buf[8 + 36 + 64];

	:: swprintf(_Buf,sizeof (_Buf) / sizeof (_Buf[0]),
		L"%Lg", _Val);
	return (wstring(_Buf));
	}
 #line 780 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string"
}

 #pragma warning(pop)
 #pragma pack(pop)

#line 786 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string"
#line 787 "C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\include\\string"





#line 4 "..\\..\\..\\src\\mocha\\misc\\char_allocator.cc"
#line 1 "Y:\\mocha\\src\\mocha/misc/char_allocator.h"



namespace mocha {
namespace utils {
char* CharAlloc(const char* path, size_t length = 0);
}
}

#line 11 "Y:\\mocha\\src\\mocha/misc/char_allocator.h"
#line 5 "..\\..\\..\\src\\mocha\\misc\\char_allocator.cc"

namespace mocha {
namespace utils {
char* CharAlloc(const char* target, size_t length) {
  char *buf = new char[ strlen(target) + 1 ];
  strcpy(buf , target);
  return buf;
}
}
}
