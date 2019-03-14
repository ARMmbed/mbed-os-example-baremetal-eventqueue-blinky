/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define SLEEP_TIME  500 // (msec)

DigitalOut led1(LED1);
EventQueue queue;

void blink_led(void) {
    led1 = !led1;
}

int main()
{
    // Post callback event to toggle the device LED
    queue.call_every(SLEEP_TIME, &blink_led);

    // Dispatch events in the queue. This must be called
    // by the application in Bare-Metal builds. With the RTOS
    // there is a dispatch thread allocated to handle this
    queue.dispatch();
}
