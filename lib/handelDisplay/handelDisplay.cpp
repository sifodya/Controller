#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <main.h>
#include <Display.h>
#include <handelDisplay.h>

//SSH1106
//U8glib library by oliver

void blackScreen(unsigned long screenTimeout)
{
  currentTime = millis();
    if ((currentTime - elapsedTime)>screenTimeout && screenReseted == false)
    {
      display.clearDisplay();
      display.display();
      screenReseted = true;
    }
}
void initialiseScreen()
{
  // while(!Serial);
  // if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
  //   // Serial.println(F("SSD1306 allocation failed"));
  //   for(;;);
  // }
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //delay(200);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display();
  elapsedTime = millis();
  screenReseted = false;
}
void displayButtonPageTurn(int buttonPage)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.print("Button Page ");
  display.println(buttonPage);
  display.display();
  elapsedTime = millis();
  screenReseted = false;
}
