#!/bin/bash
# filename: test_all.sh
# description: test all sorting-algorithm, code with python,
# make sure you have python3.x in your system

COUNT=50
OK_COUNT=0
FAIL_COUNT=0
for NAME in *.py
do
    echo "----> test $NAME, range: 1 to $COUNT"
    time for NUM in `seq 1 $COUNT`
    do
        echo $NUM |python3 $NAME |grep -i -A 1 'Is the' |grep -qi 'true'
        if [ `echo $?` -eq 0 ]
        then
            let OK_COUNT++
        else
            let FAIL_COUNT++
        fi
    done
    echo
    echo "OK times: $OK_COUNT"
    echo "FAIL times: $FAIL_COUNT"
    OK_COUNT=0
    FAIL_COUNT=0
done
exit 0
