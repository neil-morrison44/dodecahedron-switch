#include <Arduino.h>

#define VBAT_PIN A13
#define VBAT_SMOOTHING_COUNT 10
int vbatReadings[VBAT_SMOOTHING_COUNT];

int getBatteryPercentage()
{

  for (int i = 0; i < VBAT_SMOOTHING_COUNT; i++)
  {
    vbatReadings[i] = analogRead(VBAT_PIN);
    delay(10);
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

  // voltmeter adjustments
  // linear fit {3.51, 3.57} {3.52, 3.59} {3.57,3.63}{3.63, 3.70}{3.70, 3.76}{3.81,3.87}{3.885,3.94}{4.045,4.1}{4.15,4.20}
  // 0.977459 x + 0.144705

  smoothedVBAT = (0.977459 * smoothedVBAT) + 0.144705;

  Serial.print("smoothed ");
  Serial.print(smoothedVBAT);
  Serial.print("v");
  Serial.println();

  return map(smoothedVBAT * 1000, 3200, 4200, 0, 100);
}
