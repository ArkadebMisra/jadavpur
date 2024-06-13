#!/bin/bash

echo "Enter username"
read username

count=0
while read line
do
    uname=`echo $line | cut -d ":" -f 1`
    # echo "$uname"
    if [ "$uname" = "$username" ]
    then
        echo "uname $uname"
        passwd=`echo $line | cut -d ":" -f 2`
        uid=`echo $line | cut -d ":" -f 3`
        grid=`echo $line | cut -d ":" -f 4`
        uidi=`echo $line | cut -d ":" -f 5`
        hd=`echo $line | cut -d ":" -f 6`
        lsh=`echo $line | cut -d ":" -f 7`
        
        echo "passwd $passwd"
        echo "uid $uid"
        echo "grid $grid"
        echo "uidi $uidi"
        echo "hd $hd"
        echo "lsh $lsh"
        echo "passwd $passwd"

    fi
done < /etc/passwd