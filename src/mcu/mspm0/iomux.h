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

#include "common/compiler.h"
#include "common/mmio.h"

#include "registers/iomux.h"

// clang-format off

#define IOMUX_PINCM_WCOMP_BIT		(UINT32_C(1) << 28)
#define IOMUX_PINCM_WUEN_BIT		(UINT32_C(1) << 27)
#define IOMUX_PINCM_INV_BIT		(UINT32_C(1) << 26)
#define IOMUX_PINCM_HIZ1_BIT		(UINT32_C(1) << 25)
#define IOMUX_PINCM_DRV_BIT		(UINT32_C(1) << 20)
#define IOMUX_PINCM_HYSTEN_BIT		(UINT32_C(1) << 19)
#define IOMUX_PINCM_INENA_BIT		(UINT32_C(1) << 18)
#define IOMUX_PINCM_PIPU_BIT		(UINT32_C(1) << 17)
#define IOMUX_PINCM_PIPD_BIT		(UINT32_C(1) << 16)
#define IOMUX_PINCM_WAKESTAT_BIT	(UINT32_C(1) << 13)
#define IOMUX_PINCM_PC_BIT		(UINT32_C(1) << 7)
#define IOMUX_PINCM_PF_SHIFT		(UINT32_C(0))
#define IOMUX_PINCM_PF_MASK		(UINT32_C(0x0000003F))

#define IOMUX_PINCM_WAKEUP_ON_RISING_EDGE	(IOMUX_PINCM_WCOMP_BIT)
#define IOMUX_PINCM_WAKEUP_ON_FALLING_EDGE	(UINT32_C(0))
#define IOMUX_PINCM_WAKEUP_ON_UNUSED		(UINT32_C(0))

#define IOMUX_PINCM_WAKEUP_ENABLED		(IOMUX_PINCM_WUEN_BIT)
#define IOMUX_PINCM_WAKEUP_DISABLED		(UINT32_C(0))

#define IOMUX_PINCM_DATA_INVERSION_ENABLED	(IOMUX_PINCM_INV_BIT)
#define IOMUX_PINCM_DATA_INVERSION_DISABLED	(UINT32_C(0))

#define IOMUX_PINCM_OPEN_DRAIN_ENABLED		(IOMUX_PINCM_HIZ1_BIT)
#define IOMUX_PINCM_OPEN_DRAIN_DISABLED		(UINT32_C(0))

#define IOMUX_PINCM_DRIVE_STRENGTH_HIGH		(IOMUX_PINCM_DRV_BIT)
#define IOMUX_PINCM_DRIVE_STRENGTH_LOW		(UINT32_C(0))

#define IOMUX_PINCM_HYSTERESIS_ENABLED		(IOMUX_PINCM_HYSTEN_BIT)
#define IOMUX_PINCM_HYSTERESIS_DISABLED		(UINT32_C(0))

#define IOMUX_PINCM_INPUT_ENABLED		(IOMUX_PINCM_INENA_BIT)
#define IOMUX_PINCM_INPUT_DISABLED		(UINT32_C(0))

#define IOMUX_PINCM_PULL_UP_RESISTOR_ENABLED	(IOMUX_PINCM_PIPU_BIT)
#define IOMUX_PINCM_PULL_UP_RESISTOR_DISABLED	(UINT32_C(0))

#define IOMUX_PINCM_PULL_DOWN_RESISTOR_ENABLED	(IOMUX_PINCM_PIPD_BIT)
#define IOMUX_PINCM_PULL_DOWN_RESISTOR_DISABLED	(UINT32_C(0))

// clang-format on

struct mspm0_iomux_pincm_cfg {
	u32 wcomp;
	u32 wuen;
	u32 inv;
	u32 hiz1;
	u32 drv;
	u32 hysten;
	u32 inena;
	u32 pipu;
	u32 pipd;
	u32 pf;
};

STATIC_ALWAYS_INLINE NODISCARD uintptr mspm0_iomux_pincm_from_pin(const u32 pin)
{
	return (IOMUX_BASE + IOMUX_PINCM) + (sizeof(u32) * pin);
}

STATIC_ALWAYS_INLINE void
mspm0_iomux_pincm_init(const u32 pin,
		       const struct mspm0_iomux_pincm_cfg *const cfg)
{
	mmio_write32(mspm0_iomux_pincm_from_pin(pin),
		     cfg->wcomp | cfg->wuen | cfg->inv | cfg->hiz1 | cfg->drv |
			     cfg->hysten | cfg->inena | cfg->pipu | cfg->pipd |
			     cfg->pf | IOMUX_PINCM_PC_BIT);
}
