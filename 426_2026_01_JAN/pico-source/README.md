# Circuit Cellar Example Build

## Getting started

See [Getting started with Raspberry Pi Pico-series](https://rptl.io/pico-get-started) and the README in the [pico-sdk](https://github.com/raspberrypi/pico-sdk) for information
on getting up and running.

##### Notes on different boards and platforms (RP2040 / RP2350)

The majority of examples are applicable to both RP2040 and RP2350 based boards,
however certain examples that use chip-specific functionality will only build on that platform.
Similarly, Wi-Fi and Bluetooth examples will only build on a board that includes Wi-Fi and Bluetooth support.

Platform and board information are passed to the CMake build via the `PICO_PLATFORM` and `PICO_BOARD` variables.

By default, the Pico SDK targets builds for RP2040 (`PICO_PLATFORM=rp2040`). To build for RP2350 instead, pass
`-DPICO_PLATFORM=rp2350` to CMake (or `-DPICO_PLATFORM=rp2350-riscv` for RISC-V). Alternatively, in many cases, you can rely
on the board configuration to set the platform for you. For example, passing `-DPICO_BOARD=pico2` will automatically select `PICO_PLATFORM=rp2350`.

For more information see the "Platform and Board Configuration" chapter of
the [Raspberry Pi Pico-series C/C++ SDK](https://rptl.io/pico-c-sdk) book.

## Build Quickstart

