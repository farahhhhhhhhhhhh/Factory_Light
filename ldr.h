#ifndef LDR_H
#define LDR_H

#include "pico/stdlib.h"

// Pin definition for the IR sensor
#define ldr_pin 11

// Function prototypes
void Ldrsensor_init(void);
bool Ldrsensor_is_detected(void);

#endif // SENSOR_H
