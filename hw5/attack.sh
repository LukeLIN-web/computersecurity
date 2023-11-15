#!/bin/bash

# Check if the script is running as root
if [ "$(id -u)" != "0" ]; then
   echo "This script must be run as root" 1>&2
   exit 1
fi

# Create the file and add the specified text
echo "cs230 1337 haxx0r" > /root/you_are_pwned
