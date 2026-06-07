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

enum {
	// clang-format off

	EXC_SP_MAIN	= 0,
	EXC_RESET	= 1,
	EXC_NMI		= 2,
	EXC_HARDFAULT	= 3,
	EXC_SVCALL	= 11,
	EXC_PENDSV	= 14,
	EXC_SYSTICK	= 15,
	EXC_EXT_INT	= 16,
	EXC_INT_GROUP0	= EXC_EXT_INT + 0,
	EXC_INT_GROUP1	= EXC_EXT_INT + 1,
	EXC_TIMG8	= EXC_EXT_INT + 2,
	EXC_UART3	= EXC_EXT_INT + 3,
	EXC_ADC0	= EXC_EXT_INT + 4,
	EXC_ADC1	= EXC_EXT_INT + 5,
	EXC_CAN_FD	= EXC_EXT_INT + 6,
	EXC_DAC_OUT	= EXC_EXT_INT + 7,
	EXC_SPI0	= EXC_EXT_INT + 9,
	EXC_SPI1	= EXC_EXT_INT + 10,
	EXC_UART1	= EXC_EXT_INT + 13,
	EXC_UART2	= EXC_EXT_INT + 14,
	EXC_UART0	= EXC_EXT_INT + 15,
	EXC_TIMG0	= EXC_EXT_INT + 16,
	EXC_TIMG6	= EXC_EXT_INT + 17,
	EXC_TIMA0	= EXC_EXT_INT + 18,
	EXC_TIMA1	= EXC_EXT_INT + 19,
	EXC_TIMG7	= EXC_EXT_INT + 20,
	EXC_TIMG12	= EXC_EXT_INT + 21,
	EXC_I2C0	= EXC_EXT_INT + 24,
	EXC_I2C1	= EXC_EXT_INT + 25,
	EXC_AES		= EXC_EXT_INT + 28,
	EXC_RTC		= EXC_EXT_INT + 30,
	EXC_DMA		= EXC_EXT_INT + 31

	// clang-format on
};
