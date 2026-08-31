#!/bin/bash
echo Hello
uname -r

num1=2
num2=5
if [[ "$num1" -lt "$num2" ]]; then
	echo "$num1 is less than $num2"	
	exit 0
elif [[ "$num1" -gt "$num2" ]]; then
	echo "$num1 is greater than $num2"
	exit 0
else
	echo "$num1 is the same as $num2"
	exit 0
fi

