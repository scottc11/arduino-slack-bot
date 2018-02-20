// make sure 'generic ESP8266 Module' is selected in Tools --> Boards


String network = "";
String password = "";

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is active low on the ESP-01)
  delay(500);                      // Wait for a second
  digitalWrite(2, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);                      // Wait for two seconds (to demonstrate the active low LED)
}
