// Basic demo for accelerometer/gyro readings from Adafruit LSM6DS33
#include <WiFi.h>
#include <Adafruit_LSM6DS33.h>
#include <PubSubClient.h>
#include <secrets.h>
#include <battery.h>
#include <predict_value.h>

#define VIBRATION_SWITCH_PIN 25
#define VBAT_PIN A13
#define WIFI_TIMEOUT_MS 30000

#define TIME_TO_SLEEP 60 * 60 * 24
#define uS_TO_S_FACTOR 1000000LL

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (128)
char msg[MSG_BUFFER_SIZE];
int value = 0;

Adafruit_LSM6DS33 lsm6ds33;

RTC_DATA_ATTR int bootCount = 0;
// RTC_DATA_ATTR int lastPrediction = -1;

bool wifiConnected = false;
bool messagesSent = false;

void connectToMQTT()
{
  Serial.println("connecting to MQTT");
  client.setServer(MQTT_HOST, MQTT_PORT);
  client.connect("dodec");
}

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

    wifiConnected = true;
    connectToMQTT();
    break;
  case SYSTEM_EVENT_STA_DISCONNECTED:
    wifiConnected = false;
    Serial.println("Disconnected from Wi-Fi.");
    break;
  }
}

void setupWakeEvents()
{
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, HIGH);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
}

void connectToWifi()
{
  Serial.println("Connecting to Wi-Fi...");
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(SSID, PASSWORD);
}

void registerDevice()
{
  Serial.println("Registering device...");

  // sprintf(msg, "{\"name\": \"dodecahedron\"}");
  // client.publish("homebridge/to/remove", msg);

  sprintf(msg, "{\"name\": \"dodecahedron\",\"service_name\": \"face 0\", \"service\": \"Switch\" }");
  client.publish("homebridge/to/add", msg);

  for (int i = 1; i < 12; i++)
  {
    sprintf(msg, "{\"name\": \"dodecahedron\",  \"service_name\": \"face %d\", \"service\": \"Switch\" }", i);
    client.publish("homebridge/to/add/service", msg);
  }

  sprintf(msg, "{\"name\": \"dodecahedron\",  \"service_name\": \"battery\", \"service\": \"BatteryService\" }");
  client.publish("homebridge/to/add/service", msg);

  // delay(100);
}

void sendMessage()
{
  Serial.println("Sending message");

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  lsm6ds33.getEvent(&accel, &gyro, &temp);

  int prediction = predict(accel.acceleration.x, accel.acceleration.y, accel.acceleration.z, gyro.gyro.x, gyro.gyro.y, gyro.gyro.z);
  // if (prediction == lastPrediction)
  // {
  //   Serial.println("No change in prediction");
  //   return;
  // }
  for (int i = 0; i < 12; i++)
  {
    sprintf(msg, "{\"name\": \"dodecahedron\",  \"service_name\": \"face %d\", \"characteristic\": \"On\", \"value\": %d }", i, (i == prediction));
    client.publish("homebridge/to/set", msg);
  }

  // lastPrediction = prediction;
}

void sendBatteryMessage()
{
  Serial.println("Sending battery message");
  int batteryPercentage = getBatteryPercentage();

  // sprintf(msg, "Battery: %d%%", batteryPercentage);
  // client.publish("test/battery", msg);

  // topic: homebridge/to/set
  // payload: {"name": "dodecahedron", "service_name": "battery", "characteristic": "BatteryLevel", "value": true}

  sprintf(msg, "{\"name\": \"dodecahedron\",  \"service_name\": \"battery\", \"characteristic\": \"BatteryLevel\", \"value\": %d }", batteryPercentage);
  client.publish("homebridge/to/set", msg);

  sprintf(msg, "{\"name\": \"dodecahedron\",  \"service_name\": \"battery\", \"characteristic\": \"StatusLowBattery\", \"value\": %d }", batteryPercentage < 20);
  client.publish("homebridge/to/set", msg);
}

void disconnectEverything()
{
  Serial.println("Disconnecting Everything...");
  client.disconnect();
  delay(20);
  WiFi.disconnect();
  delay(80);
}

void gotoSleep()
{
  client.loop();
  Serial.println("Going to sleep...");
  disconnectEverything();
  esp_deep_sleep_start();
}

void onWake()
{
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();

  switch (wakeup_reason)
  {
  case ESP_SLEEP_WAKEUP_EXT0:
    Serial.println("Wakeup caused by external signal using RTC_IO");
    sendMessage();
    sendBatteryMessage();
    gotoSleep();
    break;
  case ESP_SLEEP_WAKEUP_TIMER:
    Serial.println("Wakeup caused by timer");
    sendBatteryMessage();
    gotoSleep();
    break;
  default:
    Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason);
    registerDevice();
    delay(1000);
    gotoSleep();
    break;
  }
}

void setup(void)
{

  // pinMode(VIBRATION_SWITCH_PIN, INPUT);
  pinMode(VBAT_PIN, INPUT);

  setupWakeEvents();

  Serial.begin(9600);
  delay(100);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  connectToWifi();

  Serial.println("Adafruit LSM6DS33 test!");

  if (!lsm6ds33.begin_I2C())
  {
    Serial.println("Failed to find LSM6DS33 chip");
    gotoSleep();
  }

  Serial.println("LSM6DS33 Found!");

  lsm6ds33.configInt1(false, false, true); // accelerometer DRDY on INT1
  lsm6ds33.configInt2(false, true, false); // gyro DRDY on INT2

  setupModel();

  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));
}

void loop()
{
  if ((millis() > WIFI_TIMEOUT_MS) && !client.connected())
  {
    Serial.println("WiFI connection timedout");
    gotoSleep();
    return;
  }

  client.loop();

  if (wifiConnected && client.connected())
  {
    onWake();
  }
}
