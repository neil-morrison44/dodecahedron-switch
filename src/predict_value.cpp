#include <EloquentTinyML.h>
#include "model.h"

#define NUMBER_OF_INPUTS 6
#define NUMBER_OF_OUTPUTS 12
// in future projects you may need to tweek this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 2 * 1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setupModel()
{
  ml.begin(model_data);
}

int predict(float accel_x, float accel_y, float accel_z, float gyro_x, float gyro_y, float gyro_z)
{
  float input[6] = {accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z};
  float prediction[12] = {0};
  ml.predict(input, prediction);

  // Serial.println("Predicted proba are: ");

  // for (int i = 0; i < NUMBER_OF_OUTPUTS; i++)
  // {
  //   Serial.println(prediction[i]);
  // }

  int mostLikely = 0;
  for (int i = 0; i < NUMBER_OF_OUTPUTS; i++)
  {
    if (prediction[i] > prediction[mostLikely])
    {
      mostLikely = i;
    }
  }
  return mostLikely;
}
