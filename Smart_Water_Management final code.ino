#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>

const int TdsSensorPin = 34;
const int oneWireBus = 4;
const int sensorPin = 35;
const int SensorPin = 32;
#define VREF 5.0
#define SCOUNT 30
float volt;
float ntu;
unsigned long int avgValue;
float b;
int buf[10], temp;
int analogBuffer[SCOUNT];
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0, copyIndex = 0;
float averageVoltage = 0, tdsValue = 0, temperature = 25;

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
WiFiClient client;

String apiWritekey = "7H3WMWDXLOCPPBKF";
const char* ssid = "DXMJ";
const char* password = "dxmdjaffer";
const char* server = "api.thingspeak.com";

void setup() {
  Serial.begin(115200);
  sensors.begin();
  delay(1000);

  // WiFi setup
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  pinMode(TdsSensorPin, INPUT);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  // TDS Sensor
  static unsigned long analogSampleTimepoint = millis();
  if (millis() - analogSampleTimepoint > 40U) {
    analogSampleTimepoint = millis();
    analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);
    analogBufferIndex++;
    if (analogBufferIndex == SCOUNT)
      analogBufferIndex = 0;
  }

  static unsigned long printTimepoint = millis();
  if (millis() - printTimepoint > 800U) {
    printTimepoint = millis();
    for (copyIndex = 0; copyIndex < SCOUNT; copyIndex++)
      analogBufferTemp[copyIndex] = analogBuffer[copyIndex];
    averageVoltage = getMedianNum(analogBufferTemp, SCOUNT) * (float)VREF / 4095.0;
    float compensationCoefficient = 1.0 + 0.02 * (temperature - 25.0);
    float compensationVolatge = averageVoltage / compensationCoefficient;

    tdsValue = (133.42 * compensationVolatge * compensationVolatge * compensationVolatge - 255.86 * compensationVolatge * compensationVolatge + 857.39 * compensationVolatge) * 0.5;

    Serial.print("TDS: ");
    Serial.print(tdsValue, 0);
    Serial.println("ppm");
  }

  // Temperature Sensor
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print("Temp: ");
  Serial.print(temperatureC);
  Serial.print("ºC ---> ");
  Serial.print(temperatureF);
  Serial.println("ºF");

  // Turbidity Sensor
  volt = 0;
  for (int i = 0; i < 800; i++) {
    volt += ((float)analogRead(sensorPin) / 4095) * 3.3;
  }
  volt = volt / 800;
  volt = round_to_dp(volt, 1);
  volt = volt + 2.85;

  if (volt < 2.5) {
    ntu = 3000;
  } else {
    ntu = -1120.4 * (volt * volt) + 5742.3 * volt - 4353.8;
    ntu = ntu + 580.56;
  }

  Serial.println("Turbidity = " + String(ntu) + " NTU");

  // pH Sensor
  for (int i = 0; i < 10; i++) {
    buf[i] = analogRead(SensorPin);
    delay(10);
  }
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buf[i] > buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (int i = 2; i < 8; i++)
    avgValue += buf[i];
  float phValue = (float)avgValue * 3.3 / 4095 / 6;
  phValue = 5 + phValue;

  Serial.print("pH: ");
  Serial.print(phValue, 2);
  Serial.println(" ");

  // Upload data to ThingSpeak
  uploadToThingSpeak();
}

int getMedianNum(int bArray[], int iFilterLen) {
  int bTab[iFilterLen];
  for (byte i = 0; i < iFilterLen; i++)
    bTab[i] = bArray[i];
  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++) {
    for (i = 0; i < iFilterLen - j - 1; i++) {
      if (bTab[i] > bTab[i + 1]) {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0)
    bTemp = bTab[(iFilterLen - 1) / 2];
  else
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
  return bTemp;
}

float round_to_dp(float in_value, int decimal_place) {
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}

void uploadToThingSpeak() {
  String url = "/update";

  String headers = "X-THINGSPEAKAPIKEY: " + apiWritekey + "\r\n";
  String dataPayload = "field1=" + String(123) + "&field2=" + String(7.2)
                      + "&field4=" + String(25.5) + "&field5=" + String(150);

  int contentLength = dataPayload.length();

  String request = "POST " + url + " HTTP/1.1\r\n" +
                   "Host: " + server + "\r\n" +
                   "Connection: close\r\n" +
                   "Content-Type: application/x-www-form-urlencoded\r\n" +
                   "Content-Length: " + String(contentLength) + "\r\n" +
                   headers +
                   "\r\n" + dataPayload + "\r\n\r\n";

  client.print(request);
  
  while (client.available()) {
    String line = client.readStringUntil('\r\n');
    Serial.println(line);
  }

  // Close the connection
  client.stop();
}
    // TDS, temperature, turbidity, pH, and ThingSpeak upload 
