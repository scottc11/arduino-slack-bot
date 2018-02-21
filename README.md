## Parts
- [ESP8266](https://www.sparkfun.com/products/13678)
- [Arduino Uno]()
- [FTDI USB](https://www.amazon.ca/dp/B00HSX3CXE?tag=openhomeauto-20)

### Arduino Libraries
- [LedControl](http://wayoda.github.io/LedControl/)
  - for Dot Matrix MAX chip


##### Download the Arduino IDE

https://www.arduino.cc/en/Main/Software


##### Set the Arduino IDE to program your Microcontroller

Tools --> Board --> select your Microcontroller (in his case, `Arduino/Genuino UNO`)

Tools --> Port --> select whatever has `usbmodem` in it

### What is an SoC (System on a Chip)?
"A system on a chip or system on chip (SoC or SOC) is an integrated circuit (also known as an "IC" or "chip") that integrates all components of a computer or other electronic systems. It may contain digital, analog, mixed-signal, and often radio-frequency functions—all on a single substrate. SoCs are very common in the mobile computing market because of their low power consumption.[1] A typical application is in the area of embedded systems."
# Additional Resources

### [Fritzing](http://fritzing.org/home/)
- a virtual arduino prototyping tool

### Programming the ESP8266
Setting up the Arduino IDE --> [Sparkfun tutorial](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon)


#### Basic ESP8266 Arduino IDE Documentation:
- `WifiClientSecure` Class
  - The Client class creates clients that can access services provided by servers in order to send, receive and process data.
  - tutorial [here](https://arduino-esp8266.readthedocs.io/en/2.4.0/esp8266wifi/client-examples.html)
  - Example Sketch [here](https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/examples/HTTPSRequest/HTTPSRequest.ino)
  - to send a 'GET' request, you literally 'print' to the `WifiClient` object like so `client.print("GET / HTTP/1.1\r\n" + "other stuff")`
  - fingerprints obtained like [this](https://github.com/esp8266/Arduino/blob/master/doc/esp8266wifi/client-secure-examples.rst#get-the-fingerprint)

#### Notes:
- GPI0 pin:
  - "GPIO0 – while perfectly capable as a digital I/O – serves a secondary purpose as a bootload/run-mode controller. When the ESP8266 boots up, it looks at GPIO0’s value to either enter the bootloader or start running the current program" - [Sparkfun](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/all#programming-the-thing)
- "if connection is established, and then lost for some reason, ESP will automatically reconnect to last used access point once it is again back on-line. This will be done automatically by Wi-Fi library, without any user intervention." - [Docs](https://arduino-esp8266.readthedocs.io/en/2.4.0/esp8266wifi/readme.html)
