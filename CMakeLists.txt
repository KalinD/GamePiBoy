# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(GamePiBoy C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(
    GamePiBoy
    ${CMAKE_CURRENT_LIST_DIR}/GamePiBoy.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GC9A01_drivers/GC9A01.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GameBoyEmulator/src/memory.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GameBoyEmulator/src/cpu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GameBoyEmulator/src/ppu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GB_PPU_GC9A01.cpp
    ${CMAKE_CURRENT_LIST_DIR}/GameBoyEmulator/src/GB.cpp
)


pico_set_program_name(GamePiBoy "GamePiBoy")
pico_set_program_version(GamePiBoy "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_usb(GamePiBoy 1)
pico_enable_stdio_uart(GamePiBoy 0)

# Add the standard library to the build
target_link_libraries(GamePiBoy
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(GamePiBoy PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/GC9A01_drivers/
        ${CMAKE_CURRENT_LIST_DIR}/GameBoyEmulator/includes/
)

# Add any user requested libraries
target_link_libraries(GamePiBoy 
        hardware_spi
        pico_time
)

pico_add_extra_outputs(GamePiBoy)

