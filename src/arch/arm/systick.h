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

#ifdef HAVE_SYSTICK

#include "common/mmio.h"
#include "common/types.h"

// clang-format off

#define SYST_CSR	(UINT32_C(0xE000E010))
#define SYST_RVR	(UINT32_C(0xE000E014))
#define SYST_CVR	(UINT32_C(0xE000E018))
#define SYST_CALIB	(UINT32_C(0xE000E01C))

#define SYST_CSR_COUNTFLAG_BIT	(UINT32_C(1) << 16)
#define SYST_CSR_CLKSOURCE_BIT	(UINT32_C(1) << 2)
#define SYST_CSR_TICKINT_BIT	(UINT32_C(1) << 1)
#define SYST_CSR_ENABLE_BIT	(UINT32_C(1) << 0)

#define SYST_RVR_RELOAD_SHIFT	(UINT32_C(0))
#define SYST_RVR_RELOAD_MASK	(UINT32_C(0x00FFFFFF))

#define SYST_CVR_CURRENT_SHIFT	(UINT32_C(0))
#define SYST_CVR_CURRENT_MASK	(UINT32_C(0x00FFFFFF))

#define SYST_CALIB_NOREF_BIT	(UINT32_C(1) << 31)
#define SYST_CALIB_SKEW		(UINT32_C(1) << 30)
#define SYST_CALIB_TENMS_SHIFT	(UINT32_C(0))
#define SYST_CALIB_TENMS_MASK	(UINT32_C(0x00FFFFFF))

#define ARCH_ARM_SYSTICK_USE_EXT_CLK	(UINT32_C(0))
#define ARCH_ARM_SYSTICK_USE_CPU_CLK	(SYST_CSR_CLKSOURCE_BIT)

#define ARCH_ARM_SYSTICK_INTERRUPT_ENABLE	(UINT32_C(1) << 1)
#define ARCH_ARM_SYSTICK_INTERRUPT_DISABLE	(UINT32_C(0))

// clang-format on

struct arch_arm_systick_cfg {
	u32 clksource;
	u32 reload;
	u32 tickint;
	u32 nvic_irq;
};

void arch_arm_systick_init(const struct arch_arm_systick_cfg *cfg);
void arch_arm_systick_halt(const u32 nvic_irq);

#endif // HAVE_SYSTICK
