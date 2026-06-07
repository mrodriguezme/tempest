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

#include <stdlib.h>
#include <stdbool.h>

#include "board/board.h"
#include "board/blinky_led.h"
#include "drivers/blinky.h"

int main(void)
{
	const struct drv_blinky_ops ops = {
		// clang-format off

		.off		= board_blinky_led_turn_off,
		.on		= board_blinky_led_turn_on,
		.ticks		= board_ticks_get

		// clang-format on
	};

	struct drv_blinky blinky;
	drv_blinky_init(&blinky, &ops);
	drv_blinky_timing_set(&blinky,
			      &(const struct drv_blinky_timing){
				      .num_blinks = 1,
				      .period_ticks = 1000,
				      .repeat = DRV_BLINKY_REPEAT_ENABLED,
				      .delay_ticks = 0 });

	drv_blinky_start(&blinky);

	for (;;)
		drv_blinky_update(&blinky);

	return EXIT_FAILURE;
}
