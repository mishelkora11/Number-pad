# Macropad

![Macropad](https://i.imgur.com/B5WKXxF.png)

A custom handwired 10-key macropad running QMK firmware on a Seeed Studio XIAO RP2040 development board. [More info on qmk.fm](https://qmk.fm/)

* Keyboard Maintainer: [mishelkora11](https://github.com/mishelkora11)
* Hardware Supported: Seeed Studio XIAO RP2040
* Hardware Availability: [GitHub Repository](https://github.com/mishelkora11/Number-pad)

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb handwired/mishel_pad -km default

Flashing example for this keyboard:

    qmk flash -kb handwired/mishel_pad -km default

See the [build environment setup](getting_started_build_tools) and the [make instructions](getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical Reset / Boot Button**: Hold down the **BOOT** button on the XIAO RP2040, press/release the **RESET** button (or plug in the USB cable while holding BOOT), then release BOOT. The board will mount as a drive named `RPI-RP2`.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.