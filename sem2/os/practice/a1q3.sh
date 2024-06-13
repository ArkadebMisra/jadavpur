#!/bin/bash

while true
do
    echo "Enter a five digit number"
    read num
    len=`expr length $num`
    if [ ${#num} -ne 5 ]
    then
        echo "please enter 5 digit number only"
    else
        t=$num
        s=0
        while [ $t -ne 0 ]
        do
            d=`expr $t % 10`
            s=`expr $s + $d`
            t=`expr $t / 10`
        done
        echo "the sum is $s"

    fi

done
