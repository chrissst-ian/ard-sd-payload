#include <SPI.h>
#include <Keyboard.h>
#include <SD.h>

const int CS = 10;
const int BUTTON_PIN = 2;
const int BOARD_LED = 13;
bool start = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BOARD_LED, OUTPUT);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW && !start) {
    start = true;
    startTyping();
    delay(1000);
  }

  if (digitalRead(BUTTON_PIN) == HIGH && start) {
    start = false;
  }

  delay(20);
}

void startTyping() {
  digitalWrite(BOARD_LED, HIGH);
  if (!SD.begin(CS)) {
    Keyboard.print("SD card init failed");
    return;
  }

  File f = SD.open("payload.txt");
  if (f) {
    String line = "";
    while (f.available()) {
      Keyboard.write(f.read());
      delay(30);
    }
    f.close();
  } else {
    Keyboard.print("Missing payload");
  }

  Keyboard.end();
  digitalWrite(BOARD_LED, LOW);
}
