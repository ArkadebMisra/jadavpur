#!/bin/bash

echo "Enter the length of the rectangle"
read l

echo "Enter the bredth of the rectangle"
read b

echo "the area of the rectangle is(caculated using expr)"
area=`expr $l \* $b`
echo "area $area"

echo "the perimeter of the rectangle is(caculated using expr)"
perimeter=`expr 2 \* \( $l + $b \)`
echo "peremeter $perimeter"

echo "the area of the rectangle is(caculated using bc)"
area=$(echo "$l * $b" | bc)
echo "area $area"

echo "the peremeter of the rectangle is(caculated using bc)"
area=$(echo "2*($l + $b)" | bc)
echo "perimeter $area"