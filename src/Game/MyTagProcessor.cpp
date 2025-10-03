#include "MyTagProcessor.hpp"

CMyTagProcessor::CMyTagProcessor(void) {
    mRubyScale = 0.5f;
}

CMyTagProcessor::~CMyTagProcessor(void) {}

CMyTagProcessor::Operation CMyTagProcessor::Process(u16 code, ContextType *ctx) {
    /*
    if (code != 0x001A) {
        return TagProcessorBase::Process(code, ctx);
    }
    */

    const u8 *strBytes = reinterpret_cast<const u8 *>(ctx->str);
    if (strBytes[1] == 0x03) {
        switch (((u16 *)strBytes)[1]) {
        case 0x0000: {
            mTextColorStart = ctx->writer->GetTextColorStart();
            mTextColorEnd = ctx->writer->GetTextColorEnd();

            mColorMappingMin = ctx->writer->GetColorMappingMin();
            mColorMappingMax = ctx->writer->GetColorMappingMax();

            ctx->str += ((strBytes[0] / 2) - 1);
        } return OPERATION_DEFAULT;

        case 0x0001: {
            ctx->writer->SetColorMapping(mColorMappingMin, mColorMappingMax);
            ctx->writer->SetTextColor(mTextColorStart, mTextColorEnd);
            ctx->writer->SetupGX();

            ctx->str += ((strBytes[0] / 2) - 1);
        } return OPERATION_DEFAULT;
        }
    }

    if (strBytes[1] == 0xFF) {
        switch (((u16 *)strBytes)[1]) {
        case 0x0000: {
            GXColor myColor;

            GXColor origColor = ctx->writer->GetTextColor();
            u8 alpha = origColor.a;

            if (strBytes[4] == 0) {
                myColor = origColor;
            }
            else if (strBytes[4] == 1) {
                myColor = (GXColor) { 0xFF,0x00,0x00,alpha };
            }
            else if (strBytes[4] == 2) {
                myColor = (GXColor) { 0x00,0xFF,0x00,alpha };
            }
            else if (strBytes[4] == 3) {
                myColor = (GXColor) { 0x00,0x00,0xFF,alpha };
            }
            else if (strBytes[4] == 4) {
                myColor = (GXColor) { 0xF2,0x0D,0x7A,alpha };
            }
            else if (strBytes[4] == 5) {
                myColor = (GXColor) { 0xFA,0xFF,0x00,alpha };
            }
            else if (strBytes[4] == 6) {
                myColor = (GXColor) { 0x00,0x96,0xA0,alpha };
            }
            else if (strBytes[4] == 7) {
                myColor = (GXColor) { 0xFF,0x8C,0x00,alpha };
            }

            ctx->writer->ResetColorMapping();
            ctx->writer->SetTextColor(myColor, myColor);

            ctx->writer->SetupGX();

            ctx->str += ((strBytes[0] / 2) - 1);
        } return OPERATION_DEFAULT;

        case 0x001: {
            f64 scale = ((u16 *)strBytes)[2];
            ctx->writer->SetScale(scale / 100.0);
            
            ctx->str += ((strBytes[0] / 2) - 1);
        } return OPERATION_DEFAULT;

        case 0x002: {
            
            
            ctx->str += ((strBytes[0] / 2) - 1);
        } return OPERATION_DEFAULT;
            
        default:
            break;
        }
    }
    else {
        ctx->str += ((strBytes[0] / 2) - 1);
        return OPERATION_DEFAULT;
    }

}
