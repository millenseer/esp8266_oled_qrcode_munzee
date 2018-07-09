# esp8266_oled_qrcode_munzee
Display Personal Munzee QR-codes on small OLED display

The idea was to display a large list of QR codes containing Personal Munzees from attendees of a Munzee Event.
Simply display! The program does not check if the user already has scanned the displayed QR!

Makes use of the QRCode-Library for ESP8266
https://github.com/anunpanya/ESP8266_QRcode

which uses the QRcode-library for Arduino:
https://github.com/tz1/qrduino


Installation:
- You need to install the qrcode library in your Arduino IDE:
  Sketch -> Include Library -> Library Manager -> search for qrcode -> ESP8266 Generate QRCode for SSD1306 oled displays 128x64 pixel -> Install
- Add more Personal Munzee Codes (including the Secret Code!) in the codes array.
  Thats a task for the Munzee Players to send you their codes!
- Change the amount of codes in the #define numCodes (better static array then dynamically requested memory)
- Compile and upload

Configuration:
- The buttons D12 (up) and D13 (down) are used to scroll forward and backbward
- Attach OLED-display as usually done

Pro:
- Funny dedicated hardware to scan the QR-codes
- Can be used to scan Social Munzee as well

Contra:
- OLED display do not perform well in Mobile Cameras in daylight! The display flickers awfully. It does work in dark environments.
- The WLAN-feature of the ESP is NOT in use at all
- Hence should work on Arduino boards as well.

Todo:
- Change the ECC factor to enlarge the pixels (but reduce redundancy)

Whishlist:
- Include Webserver as in "Social Munzee Capper" from RUJA which can talk to the Munzee-API 