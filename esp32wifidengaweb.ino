#include <WiFi.h>

const char* ssid = "Ayam Kate";
const char* password = "supangat10";

WiFiServer server(80);

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Menghubungkan ke WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Terhubung!");

  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  server.begin();

  Serial.println("Web Server Aktif");
}

void loop() {

  WiFiClient client = server.available();

  if (client) {

    Serial.println("Browser Terhubung");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head>");
    client.println("<title>ESP32 WiFi Analyzer by Julius </title>");
    client.println("</head>");
    client.println("<body>");

    client.println("<h1>ESP32 WiFi Analyzer by Julius</h1>");
    client.println("<h2>Version 1</h2>");
    client.println("<p>ESP32 berhasil menjadi Web Server cihuyyy!</p>");

    client.println("</body>");
    client.println("</html>");

    client.stop();

    Serial.println("Halaman Dikirim");
  }

}