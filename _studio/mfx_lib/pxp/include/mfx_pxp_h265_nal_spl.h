// Copyright (c) 2022 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __MFX_PXP_H265_NAL_SPL_H
#define __MFX_PXP_H265_NAL_SPL_H

#include "mfx_common.h"

#if defined(MFX_ENABLE_PXP)

#include "umc_h265_nal_spl.h"
#include "mfx_pxp_video_accelerator.h"

#include "mfx_pxp_video_accelerator_vaapi.h"

namespace UMC_HEVC_DECODER
{
    class PXPNALUnitSplitter_H265 : public NALUnitSplitter_H265
    {
    public:
        virtual UMC::MediaDataEx* GetNalUnits(UMC::MediaData* pSource) override;
        UMC::Status MergeEncryptedNalUnit(UMC::MediaDataEx* nalUnit, UMC::MediaData* pSource);
        void SetVA(UMC::VideoAccelerator* va) { m_va = va; }
    private:
        UMC::VideoAccelerator* m_va;
    };

}
#endif // MFX_ENABLE_PXP
#endif // __MFX_PXP_H265_NAL_SPL_H