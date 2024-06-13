while read l
do
    s=0
    for n in $l
    do
        s=`expr $s + $n`
    done
    echo "$s"
done < nums.txt