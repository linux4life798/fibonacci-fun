#!/bin/bash
# Author: Craig Hesling
# A messy implementation of fibonacci to get sh working a bit

USAGE_MSG="Usage: fib.sh <number>"

# default to false is the environemtn variable USE_EXTENDED is unset
USE_EXTENDED=${USE_EXTENDED:-false}

# grab argument
number=$1

fib() {
	local x=$1;

	if [ $x -le 2 ]; then
		echo 1
	else
		local two=$((x-2)) one=$((x-1))
		echo $(( `fib $two` + `fib $one` ))
	fi
}

fib_extended() {
	local x=$1;

	if [ $x -le 2 ]; then
		echo 1
	else
		local two=$(echo "$x - 2"|bc) one=$(echo "$x - 1"|bc)
		local ftwo=`fib $two` fone=`fib $one`
		echo "$ftwo + $fone" | bc
	fi
}

if [ $# -ne 1 ]; then
	echo "Find the n'th fibonacci number." >&2
	echo "$USAGE_MSG" >&2
	exit 1
fi

time {
[ $USE_EXTENDED = "true" ] && fib_extended $number || fib $number ;
echo; echo -n "Time Stats:";
}
