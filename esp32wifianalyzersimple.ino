#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(1000);

  Serial.println("===== WIFI ANALYZER =====");
}

void loop() {

  Serial.println("\nScanning...\n");

  int jumlah = WiFi.scanNetworks();

  for (int i = 0; i < jumlah; i++) {

    Serial.print(i + 1);

    Serial.print(" | ");

    Serial.print(WiFi.SSID(i));

    Serial.print(" | RSSI : ");

    Serial.print(WiFi.RSSI(i));

    Serial.print(" dBm");

    Serial.print(" | CH : ");

    Serial.println(WiFi.channel(i));

  }

  delay(5000);

}