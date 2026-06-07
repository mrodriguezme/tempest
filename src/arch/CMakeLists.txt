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

foreach(FEATURE IN LISTS TEMPEST_ARCH_FEATURES)
	string(TOUPPER "${FEATURE}" FEATURE_UPPER)
	message(STATUS "MCU is enabling feature \"${FEATURE}\"")

	target_compile_definitions(
		tempest_arch
		INTERFACE
		HAVE_${FEATURE_UPPER}=1
	)
endforeach()

add_subdirectory(${TEMPEST_ARCH})
target_link_libraries(tempest_board INTERFACE tempest_arch)

target_compile_options(tempest_arch INTERFACE -mcpu=${TEMPEST_ARCH_CORE})
target_link_options(tempest_arch INTERFACE -mcpu=${TEMPEST_ARCH_CORE})
