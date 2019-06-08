#!/bin/bash

if [[ "$EUID" -ne 0 ]]
	then echo "Please run as root"
	exit
fi

apt-get install openssh-server --assume-yes

systemctl status ssh

cp /etc/ssh/sshd_config sshd_config_backup

sed -i 's/^.*Port 22/Port 45000/' /etc/ssh/sshd_config

service sshd restart

exit
