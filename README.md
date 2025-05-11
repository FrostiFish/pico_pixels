# pico_pixels
Pico SDK C library to interface with WS2812
Based on [WS2812 example](https://github.com/raspberrypi/pico-examples/tree/master/pio/ws2812)

To add this library to your Pico SDK project, clone this library anywhere into your project directory.
In `CMakeLists.txt` of your project add the library path as a subdirectory, for example:
`add_subdirectory(pico_pixels)`
If you have a more expanive list of libraries I recommend create a lib directories with all the libraries as subdirectories.
Include the pico_pixels library with: `add_subdirectory(lib/pico_pixels)`
In `CMakeLists.txt`, add `pico_pixeks` to `target_link_libraries`. This is the same as with any of the Pico SDK hardware libraries.
Add `#include "pico_pixels.h"` to project source file to use library functions.

For reference, see the included example code