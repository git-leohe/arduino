#include "Arduino.h"

#define LEDPIN LED_BUILTIN /* pin 13 */

static void taskLoop(void *arg);
static void pinIsrSetup(void);

#if defined(__STDIO_FDEVOPEN_COMPAT_12)
int serial_console_putc(char c)
#else
int serial_console_putc(char c, FILE* file)
#endif
{
    static int init = 0;
    if (!init) {
        Serial.begin(115200); init = 0xFF;
    }
    Serial.write(c);
    return 0;
}

int main(void)
{
    init();
    fdevopen(&serial_console_putc, NULL);

    pinIsrSetup();
    taskLoop(NULL);

    return 0;
}

static void taskLoop(void *arg)
{

    pinMode(LEDPIN, OUTPUT);
    for(;;)
    {
        digitalWrite(LEDPIN, HIGH);
        delay(1000);
        digitalWrite(LEDPIN, LOW);
        delay(1000);
    }
}

static void pinIsrSetup(void)
{
    bitSet(PCICR, PCIE0);   // enable pin change interrupt bank 0
    bitSet(PCMSK0, PCINT5); // enable pin change interrupt on PCINT5/D13
}

ISR(PCINT0_vect)
{
    int ledState = digitalRead(LEDPIN);
    printf("LED: %s\r\n", (ledState ? "On" : "Off"));
}

