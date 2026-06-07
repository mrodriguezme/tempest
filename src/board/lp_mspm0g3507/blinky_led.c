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

#include "board/blinky_led.h"

#include "mcu/mspm0/gpio.h"
#include "mcu/mspm0/iomux.h"

// clang-format off

#define PIN_LED1_GPIO_INST	(GPIO0_BASE)
#define PIN_LED1_GPIO_PIN	(GPIO_PIN_PA0)
#define PIN_LED1_IOMUX_PINCM	(IOMUX_PINCM_IDX_PA0)

// clang-format on

void board_blinky_led_init(void)
{
	const struct mspm0_iomux_pincm_cfg cfg = {
		// clang-format off

		.wcomp	= IOMUX_PINCM_WAKEUP_ON_UNUSED,
		.wuen	= IOMUX_PINCM_WAKEUP_DISABLED,
		.inv	= IOMUX_PINCM_DATA_INVERSION_DISABLED,
		.hiz1	= IOMUX_PINCM_OPEN_DRAIN_DISABLED,
		.drv	= IOMUX_PINCM_DRIVE_STRENGTH_LOW,
		.hysten	= IOMUX_PINCM_HYSTERESIS_DISABLED,
		.inena	= IOMUX_PINCM_INPUT_DISABLED,
		.pipu	= IOMUX_PINCM_PULL_UP_RESISTOR_DISABLED,
		.pipd	= IOMUX_PINCM_PULL_DOWN_RESISTOR_DISABLED,
		.pf	= IOMUX_PINCM_PF_GPIO

		// clang-format on
	};
	mspm0_iomux_pincm_init(PIN_LED1_IOMUX_PINCM, &cfg);

	board_blinky_led_turn_off();
	mspm0_gpio_pins_output_enable(PIN_LED1_GPIO_INST, PIN_LED1_GPIO_PIN);
}

void board_blinky_led_turn_on(void)
{
	mspm0_gpio_pins_clr(PIN_LED1_GPIO_INST, PIN_LED1_GPIO_PIN);
}

void board_blinky_led_turn_off(void)
{
	mspm0_gpio_pins_set(PIN_LED1_GPIO_INST, PIN_LED1_GPIO_PIN);
}

void board_blinky_led_toggle(void)
{
	mspm0_gpio_pins_toggle(PIN_LED1_GPIO_INST, PIN_LED1_GPIO_PIN);
}
