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
#include "registers/gpio.h"

// clang-format off

#define MSPM0_GPIO_PWREN_KEY	(UINT32_C(0x26))
#define MSPM0_GPIO_RSTCTL_KEY	(UINT32_C(0xB1))

// clang-format on

STATIC_ALWAYS_INLINE void mspm0_gpio_power_enable(const uintptr gpio)
{
	mmio_write32(gpio + GPIO_REG_PWREN,
		     (MSPM0_GPIO_PWREN_KEY << GPIO_REG_PWREN_KEY_SHIFT) |
			     GPIO_REG_PWREN_ENABLE_BIT);
}

STATIC_ALWAYS_INLINE void mspm0_gpio_power_disable(const uintptr gpio)
{
	mmio_write32(gpio + GPIO_REG_PWREN,
		     MSPM0_GPIO_PWREN_KEY << GPIO_REG_PWREN_KEY_SHIFT);
}

STATIC_ALWAYS_INLINE void mspm0_gpio_reset(const uintptr gpio)
{
	mmio_write32(gpio + GPIO_REG_RSTCTL,
		     (MSPM0_GPIO_RSTCTL_KEY
		      << GPIO_REG_PWREN_RSTCTL_KEY_SHIFT) |
			     GPIO_REG_PWREN_RSTCTL_RESETSTKYCLR_BIT |
			     GPIO_REG_PWREN_RSTCTL_RESETASSERT_BIT);
}

STATIC_ALWAYS_INLINE void mspm0_gpio_pin_clr(const uintptr gpio, const u32 pins)
{
	mmio_write32(gpio + GPIO_REG_DOUTCLR31_0, pins);
}

STATIC_ALWAYS_INLINE void mspm0_gpio_pin_set(const uintptr gpio, const u32 pins)
{
	mmio_write32(gpio + GPIO_REG_DOUTSET31_0, pins);
}

STATIC_ALWAYS_INLINE void mspm0_gpio_pin_toggle(const uintptr gpio,
						const u32 pins)
{
	mmio_write32(gpio + GPIO_REG_DOUTTGL31_0, pins);
}
