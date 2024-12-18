#include "Ldr.h"
#include "pico/stdlib.h"
// Initialize the IR sensor pin as input
void Ldrsensor_init(void) {
    gpio_init(ldr_pin);
    gpio_set_dir(ldr_pin, GPIO_IN);
}

// Check if the IR sensor detects an object
// Returns true if an object is detected (HIGH), false if not detected (LOW)
bool Ldrsensor_is_detected(void) {
    return gpio_get(ldr_pin);
}
