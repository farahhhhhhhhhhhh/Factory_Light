#include "sensor.h"
#include "led.h"
#include "ldr.h"
#include "Ir.h"
#include "buzzer.h"
#include "motor.h"

#include "ultrasonic.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <stdio.h>

#define MOTOR_THRESHOLD_DISTANCE 5 // Example threshold in cm
#define MOTOR_SPEED 250

int main() {
    // Initialize standard library
    stdio_init_all();

    // Initialize the sensor and LED
    sensor_init();
    Ldrsensor_init();
    Irsensor_init();
    
    init_pins();
    init_pins2();
    gpio_put(LED_PIN,0);
    gpio_put(buzzer_pin,0);
    motor_init();
    Ultrasonic_init();

    while (true) {
        //motor 
        unsigned short distance = Ultrasonic_readDistance();

        if (distance <= MOTOR_THRESHOLD_DISTANCE) {
            // Start the motor with forward motiona
            motor_drive(MOTOR_SPEED, true);
            sleep_ms(3000); // Run for 5 seconds
            motor_drive(0, true); // Stop motor
            sleep_ms(2000); // Pause for 2 seconds
            //motor_drive(MOTOR_SPEED,false);
            //sleep_ms(3000);
            //motor_drive(0,true);
            //sleep_ms(2000);
   
        } 

        // Small delay to prevent rapid logging or unnecessary polling
        //sleep_ms(100);




         // Check if an object is detected by the sensor
        //gpio_put(buzzer_pin,1);
        if(!Ldrsensor_is_detected()){
            gpio_put(buzzer_pin,0);
            gpio_put(LED_PIN2,0);
        }
        else
        if(Ldrsensor_is_detected()){
            control_led_based_on_ldr();
            for(int i=0;i<3;i++){
                gpio_put(buzzer_pin,1);
                sleep_ms(200);
                gpio_put(buzzer_pin,0);
                sleep_ms(200);
            }

        }
        // Small delay to prevent rapid logging
        //sleep_ms(100);


        //  if(!sensor_is_detected()){
        //     gpio_put(LED_PIN2,1);
        // }
        // else
        // if(sensor_is_detected()){
        //     gpio_put(LED_PIN2,0);

        // }
        // // Small delay to prevent rapid logging
        // sleep_ms(100);

        //gpio_put(LED_PIN,0);

        if(!Irsensor_is_detected()){
            gpio_put(LED_PIN,1);
        }
        else
        if(Irsensor_is_detected()){
            gpio_put(LED_PIN,0);

        }
        //Small delay to prevent rapid logging
        sleep_ms(100);
    }
        // unsigned short ldr_value = LDR_getLightIntensity(); // Read the LDR value
        // printf("LDR Value: %d\n", ldr_value);

        // if (ldr_value > THRESHOLD) {
        //     gpio_put(LED_PIN, 1); // Turn on LED
        // } else {
        //     gpio_put(LED_PIN, 0); // Turn off LED
        // }

        // sleep_ms(100); // Wait for 100 milliseconds
    
       
    
    return 0;
}