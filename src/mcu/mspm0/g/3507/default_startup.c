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

#include <stdint.h>

#include "common/compiler.h"
#include "common/types.h"

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

extern void _start(void);
extern void board_init(void);

extern u32 __stack;

#define ISR WEAK_SYMBOL ALIAS("isr_unhandled")

ISR void isr_nmi(void);
ISR void isr_hardfault(void);
ISR void isr_svcall(void);
ISR void isr_pendsv(void);
ISR void isr_systick(void);
ISR void isr_int_group0(void);
ISR void isr_int_group1(void);
ISR void isr_timg8(void);
ISR void isr_uart3(void);
ISR void isr_adc0(void);
ISR void isr_adc1(void);
ISR void isr_can_fd(void);
ISR void isr_dac_out(void);
ISR void isr_spi0(void);
ISR void isr_spi1(void);
ISR void isr_uart1(void);
ISR void isr_uart2(void);
ISR void isr_uart0(void);
ISR void isr_timg0(void);
ISR void isr_timg6(void);
ISR void isr_tima0(void);
ISR void isr_tima1(void);
ISR void isr_timg7(void);
ISR void isr_timg12(void);
ISR void isr_i2c0(void);
ISR void isr_i2c1(void);
ISR void isr_aes(void);
ISR void isr_rtc(void);
ISR void isr_dma(void);

#undef ISR

void isr_reset(void)
{
	//board_init();
	_start();
}

/*
 * @brief Called when an interrupt fires and the appropriate interrupt handler
 * has not been overridden by board code.
 */
void isr_unhandled(void)
{
	for (;;);
}

PLACE_IN_SECTION(".init")
const void *const __interrupt_vector[] = {
	// clang-format off

	[EXC_SP_MAIN]		= &__stack,
	[EXC_RESET]		= isr_reset,
	[EXC_NMI]		= isr_nmi,
	[EXC_HARDFAULT]		= isr_hardfault,
	[EXC_SVCALL]		= isr_svcall,
	[EXC_PENDSV]		= isr_pendsv,
	[EXC_SYSTICK]		= isr_systick,
	[EXC_INT_GROUP0]	= isr_int_group0,
	[EXC_INT_GROUP1]	= isr_int_group1,
	[EXC_TIMG8]		= isr_timg8,
	[EXC_UART3]		= isr_uart3,
	[EXC_ADC0]		= isr_adc0,
	[EXC_ADC1]		= isr_adc1,
	[EXC_CAN_FD]		= isr_can_fd,
	[EXC_DAC_OUT]		= isr_dac_out,
	[EXC_SPI0]		= isr_spi0,
	[EXC_SPI1]		= isr_spi1,
	[EXC_UART1]		= isr_uart1,
	[EXC_UART2]		= isr_uart2,
	[EXC_UART0]		= isr_uart0,
	[EXC_TIMG0]		= isr_timg0,
	[EXC_TIMG6]		= isr_timg6,
	[EXC_TIMA0]		= isr_tima0,
	[EXC_TIMA1]		= isr_tima1,
	[EXC_TIMG7]		= isr_timg7,
	[EXC_TIMG12]		= isr_timg12,
	[EXC_I2C0]		= isr_i2c0,
	[EXC_I2C1]		= isr_i2c1,
	[EXC_AES]		= isr_aes,
	[EXC_RTC]		= isr_rtc,
	[EXC_DMA]		= isr_dma

	// clang-format on
};
