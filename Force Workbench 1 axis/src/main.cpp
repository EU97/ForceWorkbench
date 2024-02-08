#include <Arduino.h>
#include <LoadCell.h>
#include <State.h>

void setup() {
  Serial.begin(115200);
  LoadCell1_ini();
}
void setup1()
{
    pinMode(LED_BUILTIN, OUTPUT);
    LedState(10);
}

void loop() {
  Serial.println(LoadCell1_data());
  delay(1000);
}
void loop1()
{
    LedState(5);
}