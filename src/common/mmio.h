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

#include "compiler.h"
#include "types.h"
#include "util.h"

#define DEFINE_MMIO_HELPERS(bitwidth)                                         \
	STATIC_ALWAYS_INLINE u##bitwidth mmio_read##bitwidth(                 \
		const uintptr addr)                                           \
	{                                                                     \
		return *((volatile u##bitwidth *const)addr);                  \
	}                                                                     \
                                                                              \
	STATIC_ALWAYS_INLINE void mmio_write##bitwidth(const uintptr addr,    \
						       const u##bitwidth val) \
	{                                                                     \
		*((volatile u##bitwidth *const)addr) = val;                   \
	}                                                                     \
                                                                              \
	STATIC_ALWAYS_INLINE void mmio_set##bitwidth(const uintptr addr,      \
						     const u##bitwidth bits)  \
	{                                                                     \
		const u##bitwidth val = mmio_read##bitwidth(addr);            \
		mmio_write##bitwidth(addr, val | bits);                       \
	}                                                                     \
                                                                              \
	STATIC_ALWAYS_INLINE void mmio_clr##bitwidth(const uintptr addr,      \
						     const u##bitwidth bits)  \
	{                                                                     \
		const u##bitwidth val = mmio_read##bitwidth(addr);            \
		mmio_write##bitwidth(addr, val & ~bits);                      \
	}                                                                     \
                                                                              \
	STATIC_ALWAYS_INLINE void mmio_rmw_mask##bitwidth(                    \
		const uintptr addr, const u##bitwidth mask,                   \
		const u##bitwidth shift, const u##bitwidth val)               \
	{                                                                     \
		u##bitwidth dst = mmio_read##bitwidth(addr);                  \
		set_val_by_mask(dst, mask, shift, val);                       \
		mmio_write##bitwidth(addr, dst);                              \
	}

DEFINE_MMIO_HELPERS(64);
DEFINE_MMIO_HELPERS(32);
DEFINE_MMIO_HELPERS(16);
DEFINE_MMIO_HELPERS(8);

#undef DEFINE_MMIO_HELPERS
