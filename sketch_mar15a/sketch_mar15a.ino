/**
 * Made with Duckuino, an open-source project.
 * Check the license at 'https://github.com/Dukweeno/Duckuino/blob/master/LICENSE'
 */

#include "Keyboard.h"

int BUTTON_PIN = 3;
void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  
  String message;
  if (digitalRead(BUTTON_PIN) == HIGH)  {
    message = "BUTTON" ;
  } else {
    message = "Hello world";
  }
  
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(3000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  delay(500);
  Keyboard.print(F("notes"));

  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('n');
  Keyboard.releaseAll();

  delay(750);
  Keyboard.print(message);

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {
}
