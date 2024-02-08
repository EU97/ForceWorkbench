#include <Arduino.h>
#define LED_BUILTIN 2

void LedState (int a)
{
    for (int i = 0; i <= a; i = i + 1)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    }
}