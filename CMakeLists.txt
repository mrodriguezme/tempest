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

# The FATAL_ERROR option is accepted but ignored by CMake 2.6 and higher. It
# should be specified so CMake versions 2.4 and lower fail with an error instead
# of just a warning.
cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

set(
	TEMPEST_BOARD ""
	CACHE STRING "Board to select (e.g., lp_mspm0g3507)"
)

project(
	tempest
	VERSION 0.1.0
	DESCRIPTION "an embedded development playground"
	HOMEPAGE_URL "https://github.com/mrodriguezme/tempest"
	LANGUAGES C
)

function(tempest_check_vars_specified)
	foreach (var IN LISTS ARGN)
		if (NOT DEFINED ${var} OR "${${var}}" STREQUAL "")
			message(
				FATAL_ERROR
				"-D${var} not specified; this message should "
				"not appear. Please report this as a bug on "
				"the issue tracker."
			)
		endif()
	endforeach()
endfunction()

if (NOT TEMPEST_USING_CMAKE_PRESET)
	message(
		FATAL_ERROR
		"You must use a CMake preset to configure tempest; please view "
		"available presets via the \"cmake --list-presets\" command, "
		"and select one via \"cmake --preset <preset here>\"."
	)
endif()

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
	message(
		FATAL_ERROR
		"In-tree builds are forbidden; this message should not appear."
		"Please report this as a bug on the issue tracker."
	)
endif()

tempest_check_vars_specified(
	CMAKE_TOOLCHAIN_FILE
	TEMPEST_BOARD
	TEMPEST_APP
	TEMPEST_ARCH
)

add_subdirectory(src)
