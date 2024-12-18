#include "Ir.h"
#include "pico/stdlib.h"
// Initialize the IR sensor pin as input
void Irsensor_init(void) {
    gpio_init(ir_pin);
    gpio_set_dir(ir_pin, GPIO_IN);
}

// Check if the IR sensor detects an object
// Returns true if an object is detected (HIGH), false if not detected (LOW)
bool Irsensor_is_detected(void) {
    return gpio_get(ir_pin);
}
