#include <Arduino.h>

#define VBAT_PIN A13
#define VBAT_SMOOTHING_COUNT 10
int vbatReadings[VBAT_SMOOTHING_COUNT];

int readingCount = 0;

bool isSmoothed()
{
  return (readingCount >= VBAT_SMOOTHING_COUNT);
}

int getBatteryPercentage()
{
  int measuredvbat = analogRead(VBAT_PIN);
  if (isSmoothed())
  {
    memcpy(vbatReadings, &vbatReadings[1], sizeof(vbatReadings) - sizeof(int));
    vbatReadings[VBAT_SMOOTHING_COUNT - 1] = measuredvbat;
  }
  else
  {
    vbatReadings[readingCount] = measuredvbat;
    readingCount++;
  }

  float sum = 0;
  for (int i = 0; i < VBAT_SMOOTHING_COUNT; i++)
  {
    sum += vbatReadings[i];
  }

  float smoothedVBAT = (sum / VBAT_SMOOTHING_COUNT);

  smoothedVBAT *= 2;     // we divided by 2, so multiply back
  smoothedVBAT *= 3.318; // 3.3v reference voltage
  smoothedVBAT /= 4095;  // convert to voltage

  return map(smoothedVBAT * 1000, 3200, 4200, 0, 100);
}
