#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int button1 = 2;
const int button2 = 3;

// game vars
int targetTime;

float player1Time;
float player2Time;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  //rand seed
  randomSeed(analogRead(A0));

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(15, 20);
  display.println("TIMER GAME");

  display.display();

  delay(2000);
}

void loop(){
  
}

void waitForPress(int button) {
  while (digitalRead(button) == HIGH) {
    delay(10);
  }

  //deb
  delay(50);
  while (digitalRead(button) == LOW) {
      delay(10);
    }
  delay(50);
}


void showScreen(String line1, String line2, String line3) {
  display.clearDisplay();
  
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(line1);
  
  display.setTextSize(1);
  display.setCursor(0, 28);
  display.println(line2);

  display.setCursor(0, 48);
  display.println(line3);

  display.display();
}
