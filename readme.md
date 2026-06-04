# tempest - an embedded development playground

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Introduction

tempest is an embedded development playground for my personal use. With a few
exceptions, it does not make use of vendor code or external libraries. I use
this repository as a stable foundation from which I can quickly spin something
up to write a device driver, experiment with a new board or architecture, or
explore an idea in general.

I try to write the device drivers with portability in mind. They are designed to
be self-contained and, where practical, can be dropped into other projects with
little to no modification. Typically, this requires only that platform-specific
functionality be provided through function pointers or compile-time definitions,
with configuration handled through preprocessor options. The actual details vary
depending on the device driver, though.

Although this repository primarily serves as my personal playground, you're
welcome to use code from this project in your own work under the terms of the
MIT license. However, you do so at your own risk. I work on tempest in my spare
time and may not be able to provide support if you encounter issues, though bug
reports are always welcome.

None of the code in this repository is intended, tested, or qualified for use in
safety-critical systems or in applications where failure could result in injury
or loss of life.
