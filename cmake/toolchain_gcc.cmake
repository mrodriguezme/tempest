# SPDX-License-Identifier: MIT
#
# Copyright 2026 Michael Rodriguez
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the “Software”), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

include("${CMAKE_CURRENT_LIST_DIR}/toolchain_base.cmake")

set(CMAKE_SYSTEM_NAME Generic-ELF)

set(
	TEMPEST_TOOLCHAIN_TRIPLET
	"${TEMPEST_TOOLCHAIN_TRIPLET}"
	CACHE STRING "Cross compiler triplet"
)

find_program(
	CMAKE_C_COMPILER
	NAMES ${TEMPEST_TOOLCHAIN_TRIPLET}-gcc
	HINTS ${TEMPEST_TOOLCHAIN_PATH}
	REQUIRED
)

find_program(
	CMAKE_ASM_COMPILER
	NAMES ${TEMPEST_TOOLCHAIN_TRIPLET}-gcc
	HINTS ${TEMPEST_TOOLCHAIN_PATH}
	REQUIRED
)

find_program(
	CMAKE_AR
	NAMES ${TEMPEST_TOOLCHAIN_TRIPLET}-ar
	HINTS ${TEMPEST_TOOLCHAIN_PATH}
	REQUIRED
)

find_program(
	CMAKE_RANLIB
	NAMES ${TEMPEST_TOOLCHAIN_TRIPLET}-ranlib
	HINTS ${TEMPEST_TOOLCHAIN_PATH}
	REQUIRED
)

find_program(
	CMAKE_OBJCOPY
	NAMES ${TEMPEST_TOOLCHAIN_TRIPLET}-objcopy
	HINTS ${TEMPEST_TOOLCHAIN_PATH}
	REQUIRED
)

find_program(
	CMAKE_SIZE_UTIL
	NAMES ${TEMPEST_TOOLCHAIN_TRIPLET}-size
	HINTS ${TEMPEST_TOOLCHAIN_PATH}
	REQUIRED
)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

execute_process(
        COMMAND ${CMAKE_C_COMPILER} -print-sysroot
        OUTPUT_VARIABLE TOOLCHAIN_SYSROOT
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

if (TOOLCHAIN_SYSROOT AND NOT TOOLCHAIN_SYSROOT STREQUAL "/")
	set(CMAKE_SYSROOT ${TOOLCHAIN_SYSROOT})
    	set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_SYSROOT})
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
endif()
