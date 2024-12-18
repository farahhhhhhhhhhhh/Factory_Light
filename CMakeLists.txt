# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Factory_Light C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Include all necessary source files
add_executable(Factory_Light 
    Factory_Light.c 
    led.c 
    sensor.c 
    motor.c  # Include motor.c
    ldr.c
    ultrasonic.c
    buzzer.c
    Ir.c
   
)

pico_set_program_name(Factory_Light "Factory_Light")
pico_set_program_version(Factory_Light "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Factory_Light 0)
pico_enable_stdio_usb(Factory_Light 1)

# Add the standard library to the build
target_link_libraries(Factory_Light
    pico_stdlib
    hardware_pwm  # Link the PWM library
    hardware_adc
)

# Add the standard include files to the build
target_include_directories(Factory_Light PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

# Generate extra outputs (UF2, BIN, HEX) as needed
pico_add_extra_outputs(Factory_Light)
