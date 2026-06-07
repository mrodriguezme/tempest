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

#include "board/board.h"
#include "board/blinky_led.h"

#include "mspm0/gpio.h"
#include "arch/arm/systick.h"
#include "mcu_specific/intvecs.h"

static board_tick_type board_ticks = 0;

void isr_systick(void)
{
	board_ticks++;
}

board_tick_type board_ticks_get(void)
{
	return board_ticks;
}

void board_init(void)
{
	mspm0_gpio_reset(GPIO0_BASE);
	mspm0_gpio_power_enable(GPIO0_BASE);

	mspm0_gpio_reset(GPIO1_BASE);
	mspm0_gpio_power_enable(GPIO1_BASE);

	board_blinky_led_init();

	const struct arch_arm_systick_cfg cfg = {
		// clang-format off

		.clksource	= ARCH_ARM_SYSTICK_USE_CPU_CLK,
		.reload		= (BOARD_CONFIG_CPUCLK_FREQ /
				   BOARD_CONFIG_TICK_RATE_MS) - 1,
		.tickint	= ARCH_ARM_SYSTICK_INTERRUPT_ENABLE,
		.nvic_irq	= EXC_SYSTICK

		// clang-format on
	};
	arch_arm_systick_init(&cfg);
}
