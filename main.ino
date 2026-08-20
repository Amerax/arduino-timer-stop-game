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
  targetTime = random(1, 6);

  showScreen(
    "PLAYER 1",
    "TARGET: " + String(targetTime) + " SEC",
    "PRESS TO START"
  );

  waitForPress(button1);

  showScreen(
    "PLAYER 1",
    "GO!",
    "PRESS TO STOP"
  );

  unsigned long startTime = millis();
  waitForPress(button1);
  unsigned long endTime = millis();
  player1Time = (endTime - startTime) / 1000.0;

  showScreen(
    "PLAYER 1",
    String(player1Time, 2) + " SEC",
    "DONE!"
  );

  delay(2000);

  showScreen(
    "PLAYER 2",
    "TARGET: " + String(targetTime) + " SEC",
    "PRESS TO START"
  );

  waitForPress(button2);

  showScreen(
    "PLAYER 2",
    "GO!",
    "PRESS TO STOP"
  );

  startTime = millis();
  waitForPress(button2);
  endTime = millis();
  player2Time = (endTime - startTime) / 1000.0;

  showScreen("PLAYER 2",String(player2Time, 2) + " SEC","DONE!" );
  delay(2000);

  float difference1 = abs(player1Time - targetTime);
  float difference2 = abs(player2Time - targetTime);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.print("TARGET: ");
  display.print(targetTime);
  display.println(" SEC");

  display.setCursor(0, 15);
  display.print("P1: ");
  display.print(player1Time, 2);
  display.println(" SEC");

  display.setCursor(0, 28);
  display.print("P2: ");
  display.print(player2Time, 2);
  display.println(" SEC");


  display.setTextSize(2);
  display.setCursor(0, 45);

  if (difference1 < difference2) {

    display.println("P1 WINS!");

  } 
  else if (difference2 < difference1) {

    display.println("P2 WINS!");
  } 
  else {

    display.println("TIE!");
  }

  display.display();

  delay(5000);
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
