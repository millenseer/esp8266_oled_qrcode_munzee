#include <Wire.h>
#include "SSD1306.h"
#include <qrcode.h>

String MUNZEE = "https://www.munzee.com/m/";
#define numCodes 525
String codes[numCodes] = { 
"ill/1544/F9W2S4/"
// add more codes here
};
int counter = 0;

const int buttonPinUp = 12;
const int buttonPinDown = 13;

// variables will change:
int buttonStateUp = 0;         // variable for reading the pushbutton status
int buttonStateDown = 0;         // variable for reading the pushbutton status


SSD1306 display(0x3c, D1, D2);
QRcode qrcode (&display);

void delayDisplay(String text) {
  int firstSlash = 0;
  int secondSlash = 0;
  firstSlash = text.indexOf('/');
  secondSlash = text.indexOf('/', firstSlash + 1);
  //out = text.substring(0, firstSlash) + ": " + text.substring(firstSlash +1, secondSlash);
  display.setColor(BLACK);
  display.drawString(0, 0, text.substring(0, firstSlash));
  display.drawString(0, 10, text.substring(firstSlash + 1, secondSlash));
  display.drawString(0, 64 - 10, String(counter + 1) + "/" + String(numCodes));
  display.display();

  // 1000 * 10 = 10s
  for (int i = 0; i <= 1000; i++) {
    delay(10);
    // read the state of the pushbutton value:
    buttonStateUp = digitalRead(buttonPinUp);
    buttonStateDown = digitalRead(buttonPinDown);

    if (buttonStateDown == 0) {
      // turn LED on:
      digitalWrite(LED_BUILTIN, LOW);
      counter--;
      counter--;
      delay(100);
      digitalWrite(LED_BUILTIN, HIGH);
      return;
    }

    if (buttonStateUp == 0) {
      // turn LED on:
      digitalWrite(LED_BUILTIN, LOW);
      //counter++;
      delay(100);
      digitalWrite(LED_BUILTIN, HIGH);
      return;
    }
  }

}

void setup()
{
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinUp, INPUT_PULLUP);
  pinMode(buttonPinDown, INPUT_PULLUP);
  digitalWrite(LED_BUILTIN, LOW);
  // initialize dispaly
  display.init();
  display.clear();
  display.display();

  display.flipScreenVertically();
  display.setColor(WHITE);
  display.fillRect(0, 0, 128, 64);
  display.setColor(BLACK);
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setContrast(255);
  display.drawString(0, 0, "Anzahl Codes: " + String(numCodes));
  display.display();
  delay(2000);
  qrcode.init();


}

void loop() {

  qrcode.create(MUNZEE + codes[counter]);
  delayDisplay(codes[counter]);

  counter++;
  if (counter >= numCodes) {
    counter = 0;
  } 

  if (counter <0 ) {
    counter = numCodes-1;
  } 
  
}

