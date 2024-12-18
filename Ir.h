#ifndef IR_H
#define IR_H

#include "pico/stdlib.h"

// Pin definition for the IR sensor
#define ir_pin 17

// Function prototypes
void Irsensor_init(void);
bool Irsensor_is_detected(void);

#endif // SENSOR_H
