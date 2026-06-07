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

#include <string.h>
#include "blinky.h"

enum {
	// one transition for low, one transition for high
	NUM_TRANSITIONS = 2,
};

static void fsm_reset(struct drv_blinky *const drv)
{
	drv->run.blinks_left = drv->timing.num_blinks * NUM_TRANSITIONS;
	drv->run.period_ticks = drv->timing.period_ticks / drv->run.blinks_left;

	drv->run.timeout_ticks = drv->run.period_ticks;
	drv->run.state = DRV_BLINKY_WAITING_FOR_ON;
}

static void waiting_for_on_done(struct drv_blinky *const drv)
{
	drv->ops.on();
	drv->run.blinks_left--;
	drv->run.state = DRV_BLINKY_WAITING_FOR_OFF;
}

static void waiting_for_off_done(struct drv_blinky *const drv)
{
	drv->ops.off();
	drv->run.blinks_left--;

	if (drv->run.blinks_left) {
		drv->run.state = DRV_BLINKY_WAITING_FOR_ON;
		return;
	}

	if (drv->timing.repeat == DRV_BLINKY_REPEAT_DISABLED) {
		drv->run.state = DRV_BLINKY_IDLE;
		return;
	}

	if (drv->timing.delay_ticks) {
		drv->run.timeout_ticks = drv->timing.delay_ticks;
		drv->run.state = DRV_BLINKY_WAITING_FOR_DELAY;
	} else
		fsm_reset(drv);
}

static void waiting_for_delay_done(struct drv_blinky *const drv)
{
	fsm_reset(drv);
}

void drv_blinky_init(struct drv_blinky *const drv,
		     const struct drv_blinky_ops *const ops)
{
	drv->ops = *ops;
	memset(&drv->timing, 0, sizeof(drv->timing));

	drv_blinky_stop(drv);
}

void drv_blinky_start(struct drv_blinky *const drv)
{
	drv->run.prev_ticks = drv->ops.ticks();
	fsm_reset(drv);
}

void drv_blinky_stop(struct drv_blinky *const drv)
{
	drv->ops.off();
	memset(&drv->run, 0, sizeof(drv->run));
}

void drv_blinky_timing_set(struct drv_blinky *const drv,
			   const struct drv_blinky_timing *const cfg)
{
	drv->timing = *cfg;
}

void drv_blinky_update(struct drv_blinky *const drv)
{
	if (drv->run.state == DRV_BLINKY_IDLE)
		return;

	const drv_blinky_tick_type curr_ticks = drv->ops.ticks();

	if ((curr_ticks - drv->run.prev_ticks) < drv->run.timeout_ticks)
		return;

	drv->run.prev_ticks = curr_ticks;

	switch (drv->run.state) {
	case DRV_BLINKY_WAITING_FOR_ON:
		waiting_for_on_done(drv);
		return;

	case DRV_BLINKY_WAITING_FOR_OFF:
		waiting_for_off_done(drv);
		return;

	case DRV_BLINKY_WAITING_FOR_DELAY:
		waiting_for_delay_done(drv);
		return;

	default:
		// Unhandled state!
		return;
	}
}
