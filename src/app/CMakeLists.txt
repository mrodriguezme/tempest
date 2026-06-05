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

message(STATUS "Selected application \"${TEMPEST_APP}\"")

add_executable(tempest_app)

set_target_properties(
	tempest_app PROPERTIES
	OUTPUT_NAME ${TEMPEST_APP}
)

target_compile_options(
	tempest_app PRIVATE
	-ffunction-sections
	-fdata-sections
	-Wall
	-Wextra
)

target_link_options(
	tempest_app PRIVATE
	-Wl,--gc-sections
	-Wl,-Map=${TEMPEST_APP}.map
	-specs=picolibc.specs
)

add_subdirectory(${TEMPEST_APP})
target_link_libraries(tempest_app PRIVATE tempest_board)

get_property(
	LINKER_SCRIPT
	TARGET tempest_app
	PROPERTY CUSTOM_LINKER_SCRIPT
)

if (NOT LINKER_SCRIPT)
	get_property(
		LINKER_SCRIPT
		TARGET tempest_mcu
		PROPERTY DEFAULT_LINKER_SCRIPT
	)
endif()

get_property(
	STARTUP_FILE
	TARGET tempest_app
	PROPERTY CUSTOM_STARTUP_FILE
)

if (NOT STARTUP_FILE)
	get_property(
		STARTUP_FILE
		TARGET tempest_mcu
		PROPERTY DEFAULT_STARTUP_FILE
	)
endif()

target_sources(tempest_app PRIVATE ${STARTUP_FILE})
tempest_linker_script_set(tempest_app ${LINKER_SCRIPT})

message(STATUS "Using linker script: ${LINKER_SCRIPT}")
message(STATUS "Using startup file: ${STARTUP_FILE}")

tempest_target_size_print(tempest_app)
