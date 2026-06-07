// SPDX-License-Identifier: MIT
//
// Copyright 2026 Michael Rodriguez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "common/mmio.h"

// clang-format off

#define NVIC_ISER	(UINT32_C(0xE000E100))
#define NVIC_ICER	(UINT32_C(0xE000E180))
#define NVIC_ISPR	(UINT32_C(0xE000E200))
#define NVIC_ICPR	(UINT32_C(0xE000E280))
#define NVIC_IPRN	(UINT32_C(0xE000E400))

// clang-format on

STATIC_ALWAYS_INLINE void arch_arm_nvic_irq_enable(const u32 irq)
{
	mmio_write32(NVIC_ISER, irq);
}

STATIC_ALWAYS_INLINE void arch_arm_nvic_irq_disable(const u32 irq)
{
	mmio_write32(NVIC_ICER, irq);
}

STATIC_ALWAYS_INLINE void arch_arm_nvic_irq_clear_pending(const u32 irq)
{
	mmio_write32(NVIC_ICPR, irq);
}
