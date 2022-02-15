// Copyright (c) 2019-2020 Intel Corporation
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

#pragma once

#include "mfx_common.h"
#if defined(MFX_ENABLE_AV1_VIDEO_ENCODE)

#include "av1ehw_base.h"
#include "av1ehw_base_data.h"
#include "ehw_resources_pool.h"

namespace AV1EHW
{
namespace Base
{

class Allocator
    : public FeatureBase
{
public:
#define DECL_BLOCK_LIST\
    DECL_BLOCK(Init)
#define DECL_FEATURE_NAME "Base_Allocator"
#include "av1ehw_decl_blocks.h"

    Allocator(mfxU32 FeatureId)
        : FeatureBase(FeatureId)
    {}

protected:
    virtual void InitAlloc(const FeatureBlocks& blocks, TPushIA Push) override;

    static IAllocation* MakeAlloc(std::unique_ptr<MfxEncodeHW::ResPool>&&);
};

} //Base
} //namespace AV1EHW

#endif
