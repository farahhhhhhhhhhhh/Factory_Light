#include "buzzer.h"
#include "pico/stdlib.h"
#include "sensor.h"
void init_pins2(void) {
    // Initialize LED pin as an output
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);

    // Initialize sensor pin as an input
    gpio_init(SENSOR_PIN);
    gpio_set_dir(SENSOR_PIN, GPIO_IN);
}

void control_buzzer_based_on_sensor(void) {
    // Read the sensor value and control the LED accordingly
        gpio_put(buzzer_pin, 1);  // Turn LED off

}