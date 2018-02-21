#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

String NetworkSSID = "AD94F3";
String NetworkPassword = "286485850";

const char* host = "api.github.com";
const int httpsPort = 443;

// Use web browser to view and copy SHA1 fingerprint of the certificate
const char* fingerprint = "1B D2 A9 72 7A DA 9E AC 63 F6 F2 95 D7 2F 23 AA 74 49 1B FD 0C F5 BB C0 89 17 07 9A 7B 9B B6 DE 10 F7 25 7B F6 58 F8 B5 04 27 DF FA 7F 5E 88 4F B4 F0 3C 59 7D 18 B7 6A 52 BE B9 87 C4 E7 60 AE 3F E9 79 3E D3 9A 57 40 4C 0D F0 56 71 39 39 6E F6 57 F6 C1 62 7D C5 87 9F BC 0F EC B4 72 89 2E 6E 35 A9 1F 9C 40 FD 52 74 65 CA EC EA F5 C9 CF AA 27 09 FA 36 A0 13 F0 24 AF AF C5 F2 FF C6 E4 EF D7 C7 81 2B 54 69 78 DF 5F 94 51 01 BA F3 19 DD E6 93 59 6B FA DE A6 B8 D5 4F B1 BA 38 82 1A B0 6D 9B 4C F9 4D 25 CB 65 EF 10 01 A5 0B 68 11 90 4D FA 6A 18 E7 6B 10 EE A2 25 1F F5 FB E9 2D 42 46 4A 92 90 42 29 EA 93 D2 F0 89 89 9B B1 4D A5 1C 78 1E 7D 19 60 24 BB 35 F8 0A E4 4D F1 6F 4A 20 27 EA AB 28 DE 88 52 30 C3 F0 FC 1F 58 D1 C4 93 98 73 B6 0F 29 BE 42 44 BC 6D E2 DA 57 4F";



void setup() {
  Serial.begin(115200);
  Serial.println();
  
  WiFi.mode(WIFI_STA); // 'station' mode
  WiFi.begin("AD94F3", "286485850");
  
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("-----------------------------------");

  // declare a secure wifi client to contact the host server / API (create TLS connection)
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);

  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }


  if (client.verify(fingerprint, host)) {
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate does not match");
  }

  String url = "/repos/esp8266/Arduino/commits/master/status";
  Serial.print("requesting URL: ");
  Serial.println(url);

  // REQUEST
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");
  
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }

  String line = client.readStringUntil('\n');
  
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}

void loop() {
  
}
