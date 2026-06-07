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

#include "common/types.h"

// clang-format off

#ifndef BOARD_CONFIG_TICK_TYPE
typedef u32 board_tick_type;
#else
typedef BOARD_CONFIG_TICK_TYPE board_tick_type;
#endif // BOARD_CONFIG_TICK_TYPE

#ifndef BOARD_CONFIG_TICK_RATE_MS
#define BOARD_CONFIG_TICK_RATE_MS	(sec_to_ms(1))
#endif // BOARD_CONFIG_TICK_RATE_MS

#ifndef BOARD_CONFIG_CPUCLK_FREQ
#define BOARD_CONFIG_CPUCLK_FREQ	(mhz_to_hz(32))
#endif // BOARD_CONFIG_CPUCLK_FREQ

#ifndef BOARD_CONFIG_BLINKY_LED
#define BOARD_CONFIG_BLINKY_LED		(1)
#endif // BOARD_CONFIG_BLINKY_LED

// clang-format on
