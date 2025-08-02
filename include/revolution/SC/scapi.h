#ifndef RVL_SDK_SC_SCAPI_H
#define RVL_SDK_SC_SCAPI_H
#include <revolution/types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum { 
    SC_ASPECT_STD, 
    SC_ASPECT_WIDE 
} SCAspectRatio;

typedef enum {
    SC_LANG_JP,
    SC_LANG_EN,
    SC_LANG_DE,
    SC_LANG_FR,
    SC_LANG_SP,
    SC_LANG_IT,
    SC_LANG_NL,
    SC_LANG_ZH_S,
    SC_LANG_ZH_T,
    SC_LANG_KR,
} SCLanguage;

u8 SCGetAspectRatio(void);

u8 SCGetLanguage(void);

#ifdef __cplusplus
}
#endif
#endif
