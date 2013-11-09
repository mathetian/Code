#!/usr/bin/expect
set password PASSWORD 
spawn ssh -p 22 USERNAME@IP
expect "*password:"
send "$password\r"
expect "*password:"
send "$password\r"
expect "*password:"
send "$password\r"
interact
