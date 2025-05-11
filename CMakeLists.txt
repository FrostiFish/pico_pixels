add_library(pico_pixels INTERFACE)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(pico_pixels ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_sources(pico_pixels INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/pico_pixels.c
        ${CMAKE_CURRENT_LIST_DIR}/color_order.c
)

target_include_directories(pico_pixels INTERFACE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/generated)

# Add the used pico libraries to the library
target_link_libraries(pico_pixels INTERFACE
        pico_stdlib
        hardware_pio)