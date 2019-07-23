#!/bin/bash

PFT_ROOT=$(dirname $0)
CONFIG_FILE=$PFT_ROOT"/options-config.ini"

FORCE_TEST_LOG=$(grep -e "^FORCE_TEST_LOG" $CONFIG_FILE | cut -d '=' -f 2 | tr -d " \t")
if ! [[ $FORCE_TEST_LOG -eq 1 ]]
then
	echo "This script must be run with FORCE_TEST_LOG=1 set in options-config.ini (Make sure to re-make pft)"
	exit 0
fi

for i in {1..2759}
do
	echo "Checking Test # $i"
	./test -L $i > tmp.txt
	RET1=$(head -n 8 results.txt 2>/dev/null | grep "expected return value" 2>/dev/null) # | grep -o "\\-?[0-9]*" 2>/dev/null)
	rm results.txt
	./test -L $i $(($i + 1)) > /dev/null
	RET2=$(head -n 13 results.txt 2>/dev/null | grep "expected return value" 2>/dev/null) # | grep -o "\\-?[0-9]*" 2>/dev/null)
	if ! [ "$RET1" == "$RET2" ] ; then
		SHOULD=$(echo $RET1 | grep -o "[-0-9]\+")
		BUT_IS=$(echo $RET2 | grep -o "[-0-9]\+")
		echo "Test # $i has issue 11 pipe error: Return value should be $SHOULD but is reported as $BUT_IS."
	fi
done


