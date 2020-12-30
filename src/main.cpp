// Basic demo for accelerometer/gyro readings from Adafruit LSM6DS33
#include <WiFi.h>
#include <Adafruit_LSM6DS33.h>
#include <PubSubClient.h>
#include <secrets.h>
#include <battery.h>
#include <predict_value.h>

#define VIBRATION_SWITCH_PIN 25
#define VBAT_PIN A13

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (128)
char msg[MSG_BUFFER_SIZE];
int value = 0;

Adafruit_LSM6DS33 lsm6ds33;

void WiFiEvent(WiFiEvent_t event)
{
  Serial.printf("[WiFi-event] event: %d\n", event);
  switch (event)
  {
  case SYSTEM_EVENT_STA_START:
    WiFi.setHostname(HOSTNAME);
    break;
  case SYSTEM_EVENT_STA_GOT_IP:
    Serial.println("Connected to Wi-Fi.");

    Serial.print("ESP32 hostname: ");
    Serial.println(String(WiFi.getHostname()));
    Serial.print("ESP32 MAC: ");
    Serial.println(WiFi.macAddress());
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("Wi-Fi signal level: ");
    Serial.println(WiFi.RSSI());

    // connectToMqtt();
    client.setServer(MQTT_HOST, MQTT_PORT);
    client.connect("dodec");
    client.publish(MQTT_ROOT_TOPIC, "connected");
    break;
  case SYSTEM_EVENT_STA_DISCONNECTED:
    Serial.println("Disconnected from Wi-Fi.");
    // mqttReconnectTimer.detach(); // ensure we don't reconnect to MQTT while reconnecting to Wi-Fi
    // wifiReconnectTimer.once(2, connectToWifi);
    break;
  }
}

void connectToWifi()
{
  Serial.println("Connecting to Wi-Fi...");
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(SSID, PASSWORD);
}

void setup(void)
{

  pinMode(VIBRATION_SWITCH_PIN, INPUT);
  pinMode(VBAT_PIN, INPUT);

  Serial.begin(9600);
  delay(1000);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  connectToWifi();

  Serial.println("Adafruit LSM6DS33 test!");

  if (!lsm6ds33.begin_I2C())
  {
    Serial.println("Failed to find LSM6DS33 chip");
    while (1)
    {
      delay(10);
    }
  }

  Serial.println("LSM6DS33 Found!");

  lsm6ds33.configInt1(false, false, true); // accelerometer DRDY on INT1
  lsm6ds33.configInt2(false, true, false); // gyro DRDY on INT2

  setupModel();
}

void loop()
{
  client.loop();
  int vibration = digitalRead(VIBRATION_SWITCH_PIN);

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  lsm6ds33.getEvent(&accel, &gyro, &temp);

  int batteryPercentage = getBatteryPercentage();

  sprintf(msg, "Battery: %d%%", batteryPercentage);
  client.publish("test/battery", msg);
  sprintf(msg, "%f,%f,%f,%f,%f,%f", accel.acceleration.x, accel.acceleration.y, accel.acceleration.z, gyro.gyro.x, gyro.gyro.y, gyro.gyro.z);
  client.publish("test/raw", msg);

  int prediction = predict(accel.acceleration.x, accel.acceleration.y, accel.acceleration.z, gyro.gyro.x, gyro.gyro.y, gyro.gyro.z);

  sprintf(msg, "prediction: %d", prediction);
  client.publish("test/predict", msg);

  delay(5000);
}

// Number to Accel
// 0 : -9.57,0.23,0.39
// 1 : -4.09,-9.16,-0.50
// 2 : -4.41,-1.99,-8.27
// 3 : -3.63,7.83,-4.06
// 4 : -3.95,6.73,6.10
// 5 : -4.25,-3.32,8.46
