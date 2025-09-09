#ifndef RVL_FACE_LIBRARY_ICON_H
#define RVL_FACE_LIBRARY_ICON_H
#include <RVLFaceLibrary/RFL_Types.h>
#include <RVLFaceLibrary/RFL_MiddleDatabase.h>
#include <revolution/types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	RFLIconBG_Favorite = 0,
	RFLIconBG_Direct
} RFLIconBGType;

typedef struct {
	u16				width;
	u16				height;
	RFLIconBGType	bgType;
	GXColor			bgColor;
	BOOL			drawXluOnly;
} RFLIconSetting;

RFLErrcode RFLMakeIcon(void *buf, RFLDataSource source, RFLMiddleDB *middleDB, u16 index, RFLExpression expression, const RFLIconSetting *setting);

#ifdef __cplusplus
}
#endif
#endif
