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

#include "systick.h"
#include "nvic.h"

void arch_arm_systick_init(const struct arch_arm_systick_cfg *const cfg)
{
	arch_arm_systick_halt(cfg->nvic_irq);

	mmio_write32(SYST_CVR, 0);
	mmio_write32(SYST_RVR, cfg->reload & SYST_RVR_RELOAD_MASK);

	if (cfg->clksource == ARCH_ARM_SYSTICK_INTERRUPT_ENABLE) {
		arch_arm_nvic_irq_clear_pending(cfg->nvic_irq);
		arch_arm_nvic_irq_enable(cfg->nvic_irq);
	}

	mmio_write32(SYST_CSR,
		     cfg->clksource | cfg->tickint | SYST_CSR_ENABLE_BIT);
}

void arch_arm_systick_halt(const u32 nvic_irq)
{
	mmio_clr32(SYST_CSR, SYST_CSR_ENABLE_BIT);
	arch_arm_nvic_irq_disable(nvic_irq);
}
