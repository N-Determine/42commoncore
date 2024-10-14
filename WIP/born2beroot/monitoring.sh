#!/bin/bash

# Make variables for later use here
architec=$(uname -vps)
physical=$(lscpu | grep "Socket(s):" | awk '{print $2}')
virtual=$(nproc)
mem=$(free | grep Mem | awk '{printf "%s/%sMB	(%.2f%%)", $3, $2, $3/$2 * 100}')
disk=$(df -H | grep /dev/sda | awk '{printf "%s/%s		(%.2f%%)", $4, $3, $3/$4*100.0}')
cpu=$(top -bn1 | grep Cpu | awk '{printf "%.2f%%", 100 - $8}')
boot=$(who -b | awk '{print $3" "$4}')

tcp=$(netstat -ant | grep ESTABLISHED | wc -l)
users=$(who | wc -l)


mac=$(ifconfig -a | grep ether | sed -n '2p' | awk '{print $2}')
ipv4=$(ifconfig -a | grep "inet " | sed -n '2p' | awk '{print $2}')



# This is the layout of the message using the variables we have created
echo "#Architecture:		$architec"
echo "#CPU Physical:		$physical"
echo "#vCPU:			$virtual"
echo "#Memory Usage:		$mem"
echo "#Disk Usage:		$disk"
echo "#CPU Load:		$cpu"
echo "#Last Boot:		$boot"
echo "#LVM Use:			"
echo "#Connections TCP:	$tcp"
echo "#User Log:		$users"
echo "#Network:		IP $ipv4 ($mac)"
echo "#Sudo:			"
