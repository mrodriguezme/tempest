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

#ifndef DRV_BLINKY_H
#define DRV_BLINKY_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdbool.h>
#include <stdint.h>

#ifndef DRV_BLINKY_TICK_TYPE
#define DRV_BLINKY_TICK_TYPE uint32_t
#endif // DRV_BLINKY_TICK_TYPE

typedef DRV_BLINKY_TICK_TYPE drv_blinky_tick_type;

enum drv_blinky_state {
	DRV_BLINKY_IDLE,
	DRV_BLINKY_WAITING_FOR_OFF,
	DRV_BLINKY_WAITING_FOR_ON,
	DRV_BLINKY_WAITING_FOR_DELAY
};

enum drv_blinky_repeat_mode {
	DRV_BLINKY_REPEAT_ENABLED,
	DRV_BLINKY_REPEAT_DISABLED
};

struct drv_blinky_ops {
	void (*on)(void);
	void (*off)(void);
	drv_blinky_tick_type (*ticks)(void);
};

struct drv_blinky_timing {
	unsigned int num_blinks;
	drv_blinky_tick_type period_ticks;
	drv_blinky_tick_type delay_ticks;
	enum drv_blinky_repeat_mode repeat;
};

struct drv_blinky {
	struct {
		enum drv_blinky_state state;
		drv_blinky_tick_type prev_ticks;
		unsigned int blinks_left;
		drv_blinky_tick_type period_ticks;
		drv_blinky_tick_type timeout_ticks;
	} run;

	struct drv_blinky_timing timing;
	struct drv_blinky_ops ops;
};

void drv_blinky_init(struct drv_blinky *const drv,
		     const struct drv_blinky_ops *const ops);

void drv_blinky_start(struct drv_blinky *drv);

void drv_blinky_stop(struct drv_blinky *drv);

void drv_blinky_timing_set(struct drv_blinky *drv,
			   const struct drv_blinky_timing *cfg);

void drv_blinky_update(struct drv_blinky *drv);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // DRV_BLINKY_H
