#include <AsyncDelay.h>

AsyncDelay delay_1s;

int count_value = 0;
volatile int count = 0;

void setup(void)
{
  Serial.begin(9600);
  while(!Serial); // Pause program till serial opens
  Serial.println("Starting timers");

  // Start counting
  delay_1s.start(1000, AsyncDelay::MILLIS);
}

void loop(void)
{
  if (delay_1s.isExpired()) {
    Serial.print("3s delay millis=");
    Serial.println(++count);
    delay_1s.repeat(); // Count from when the delay expired, not now
  }
}