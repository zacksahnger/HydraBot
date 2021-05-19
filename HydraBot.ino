
#include <Hydra.h> //robot driver library

#include <SPI.h> //library for oled display
#include <Wire.h> //library for oled display
#include <Adafruit_GFX.h> //library for oled display
#include <Adafruit_SSD1306.h> //library for oled display

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;
const int ENA = 3;
const int ENB = 10 ;
int global_power = 0;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

  //timekeeping variables
  unsigned long currentMillis;
  unsigned long elapsedMillis;
  unsigned long initialMillis = millis();

}


void loop() {

  Hydra hydra(IN1, IN2, IN3, IN4, ENA, ENB); //create Hydra (robot) object

  //driving sample
  hydra.drive_forward_timed(150,800); //params: int power, unsigned long time
  delay(500);
  hydra.turn_left(150, 600); //params: int power, unsigned long time
  
  char buffer[50]; //used to store message being displayed 
  sprintf(buffer, "elapsed time: %lu\n", millis());
  Serial.print(buffer);
  
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  //display.println(F("hello world"));
  display.print(buffer);
  display.display();
  delay(2000);
}
