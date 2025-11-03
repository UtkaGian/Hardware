#include <stdio.h>
#include "Hardware.h"
#include <unistd.h>
int main(void){
    init_pin(LED_0, OUT);
    write_pin(LED_0, HIGH);
    char status= read_pin(LED_0);
    usleep(300000);
    write_pin(LED_0, LOW);
    status= read_pin(LED_0);
    usleep(300000);
    release_pin(LED_0);
    
    return 0;
}