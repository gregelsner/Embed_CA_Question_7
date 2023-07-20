// Embed_CA_Question_7 Write an mbed OS program to toggle the LEDs with the intervals specified below.
// LED1 - every 2 seconds
// LED2 - every 5 seconds 
//////The solution to toggle two LEDs simultaneously and independently at different time frequencies is to apply the Ticker . 
//It's used to set up a recurring interrupt to repeatedly call a designated function at a specified rate.

#include "mbed.h"


Ticker flipper_1; //Defining ticker flipper_1
Ticker flipper_2; //Defining ticker flipper_2
DigitalOut led1(LED1); //Setting D/O to on board LED1
DigitalOut led2(LED2); //Setting D/O to on board LED2

void flip_1() { // flip 1 function toggles led1 on & off
 led1 = !led1;
}
void flip_2() { // flip 2 function toggles led2 on & off
 led2 = !led2;
}
int main() { //Runs in its own thread in the OS

 led1=0;
 led2=0;
 
 flipper_1.attach(&flip_1, 2000ms); // Calls flip_1 function for 2 sec. interval 

 flipper_2.attach(&flip_2, 5000ms); // Calls flip_2 function for 5 sec. interval
 
 }
