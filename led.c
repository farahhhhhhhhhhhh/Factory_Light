#include "led.h"
#include "pico/stdlib.h"
#include "Ir.h"
#include "sensor.h"
void init_pins(void) {
    // Initialize LED pin as an output
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(LED_PIN2);
    gpio_set_dir(LED_PIN2,GPIO_OUT);

}

void control_led_based_on_sensor(void) {
    // Read the sensor value and control the LED accordingly
        gpio_put(LED_PIN, 1);  // Turn LED off

}

void control_led_based_on_ldr(void){
    gpio_put(LED_PIN2,1);
}