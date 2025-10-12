#include <revolution/OS.h>
#include <revolution/TPL.h>

#define TPL_VERSION 0x0020AF30

void TPLBind(TPLPalette* pal) {
    u16 i;

    OSAssert(pal->version == TPL_VERSION, 25, "invalid version number for texture palette");

    pal->descriptors = (TPLDescriptor*)((char*)pal->descriptors + (u32)pal);

    for (i = 0; i < pal->numImages; i++) {
        if (pal->descriptors[i].texHeader != NULL) {
            // Convert header offset into pointer
            pal->descriptors[i].texHeader =
                (TPLHeader*)((char*)pal + (u32)pal->descriptors[i].texHeader);

            if (!pal->descriptors[i].texHeader->unpacked) {
                // Convert data offset into pointer
                pal->descriptors[i].texHeader->data =
                    (char*)pal + (u32)pal->descriptors[i].texHeader->data;

                pal->descriptors[i].texHeader->unpacked = TRUE;
            }
        }

        if (pal->descriptors[i].clutHeader != NULL) {
            // Convert header offset into pointer
            pal->descriptors[i].clutHeader =
                (TPLClutHeader*)((char*)pal +
                                 (u32)pal->descriptors[i].clutHeader);

            if (!pal->descriptors[i].clutHeader->unpacked) {
                // Convert data offset into pointer
                pal->descriptors[i].clutHeader->data =
                    (char*)pal + (u32)pal->descriptors[i].clutHeader->data;

                pal->descriptors[i].clutHeader->unpacked = TRUE;
            }
        }
    }
}

TPLDescriptor* TPLGet(TPLPalette* pal, u32 id) {
    id %= pal->numImages;
	return &pal->descriptors[id];
}

void TPLGetGXTexObjFromPalette(TPLPalette* pal, GXTexObj* texObj, u32 id) {
    TPLDescriptor* descriptor = TPLGet(pal, id);
    GXBool hasMipMap = descriptor->texHeader->minLod == descriptor->texHeader->maxLod ? FALSE : TRUE;
    
    GXInitTexObj(texObj,
        descriptor->texHeader->data,
        descriptor->texHeader->width, descriptor->texHeader->height,
        descriptor->texHeader->format,
        descriptor->texHeader->wrapS, descriptor->texHeader->wrapT,
        hasMipMap
    );
    GXInitTexObjLOD(texObj,
        descriptor->texHeader->minFilt, descriptor->texHeader->magFilt,
        descriptor->texHeader->minLod, descriptor->texHeader->maxLod,
        descriptor->texHeader->lodBias, FALSE, descriptor->texHeader->edgeLodEnable,
        GX_ANISO_1
    );
}
void TPLGetGXTexObjFromPaletteCI(TPLPalette* pal, GXTexObj* texObj, GXTlutObj* tlutObj, GXTlut tluts, u32 id) {
    TPLDescriptor* descriptor = TPLGet(pal, id);
    GXBool hasMipMap = (descriptor->texHeader->minLod == descriptor->texHeader->maxLod) ? FALSE : TRUE;

	GXInitTlutObj(
        tlutObj, descriptor->clutHeader->data,
	    descriptor->clutHeader->format,
	    descriptor->clutHeader->numEntries
    );

	GXInitTexObjCI(texObj,
        descriptor->texHeader->data,
        descriptor->texHeader->width, descriptor->texHeader->height,
        descriptor->texHeader->format,
        descriptor->texHeader->wrapS, descriptor->texHeader->wrapT,
        hasMipMap, tluts
    );

	GXInitTexObjLOD(texObj,
        descriptor->texHeader->minFilt, descriptor->texHeader->magFilt,
        descriptor->texHeader->minLod, descriptor->texHeader->maxLod,
        descriptor->texHeader->lodBias, FALSE, descriptor->texHeader->edgeLodEnable,
        GX_ANISO_1
    );
}
