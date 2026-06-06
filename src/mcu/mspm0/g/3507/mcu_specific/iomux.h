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

enum mspm0_iomux_pincm_idx {
	// clang-format off

	IOMUX_PINCM_IDX_PA0	= 0,
	IOMUX_PINCM_IDX_PA1	= 1,
	IOMUX_PINCM_IDX_PA2	= 6,
	IOMUX_PINCM_IDX_PA3	= 7

	// clang-format on
};

// clang-format off

#define IOMUX_PINCM_PF_UNCONNECTED	(0)
#define IOMUX_PINCM_PF_GPIO		(1)

#define IOMUX_PINCM_PA0_PF_UART0_TX	(2)
#define IOMUX_PINCM_PA0_I2C0_SDA	(3)
#define IOMUX_PINCM_PA0_TIMA0_C0	(4)
#define IOMUX_PINCM_PA0_TIMA_FAL1	(5)
#define IOMUX_PINCM_PA0_TIMG8_C1	(6)
#define IOMUX_PINCM_PA0_FCC_IN		(7)

#define IOMUX_PINCM_PA1_UART0_RX	(2)
#define IOMUX_PINCM_PA1_I2C0_SCL	(3)
#define IOMUX_PINCM_PA1_TIMA0_C1	(4)

// clang-format on
