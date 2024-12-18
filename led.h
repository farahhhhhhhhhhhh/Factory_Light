#ifndef LED_H   // Updated header guard to match the new file name
#define LED_H


// Pin definitions
#define LED_PIN 0
#define LED_PIN2 5

// Function prototypes
void init_pins(void);
void control_led_based_on_sensor(void);
void control_led_based_on_ldr(void);


#endif // LED_H

