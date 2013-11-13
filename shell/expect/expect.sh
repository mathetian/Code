#!/usr/bin/expect

spawn git push 

expect "Username for 'https://github.com': "
send "xxxx\r"

expect "Password for 'https://xxx@gmail.com@github.com': "
send "xxx\r"

expect eof
