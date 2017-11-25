#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]

#Put your test case here

expect "What is the operation?" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "SUM\r"
send "5\r"
send "4.0\r"
expect "Result: 9.0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

expect "What is the operation?" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "SUbtract\r"
send "5\r"
send "4.0\r"
expect "Result: 1.0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

expect "What is the operation?" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "DIV\r"
send "20\r"
send "4.0\r"
expect "Result: 5.0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

expect "What is the operation?" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "FINISH\r"


//to run ./integration.tcl ./students.exe

//chmod 755 integrationtest.tcl
