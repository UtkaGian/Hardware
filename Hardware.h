#ifndef __HARDWARE



void release_pin(const char *pin);
void write_pin(const char *pin, const char*state);
char read_pin(const char *pin);
void init_pin(const char *pin, const char *dir);

#define LED_0 "17"
#define LED_1 "4"
#define LED_2 "18"
#define LED_3 "23"
#define LED_4 "24"
#define LED_5 "25"
#define LED_6 "22"
#define LED_7 "27"
#define IN "in"
#define OUT "out"
#define HIGH "1"
#define LOW "0"

#define __HARDWARE
#endif