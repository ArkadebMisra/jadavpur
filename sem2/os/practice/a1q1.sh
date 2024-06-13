#!/bin/bash

echo "enter the length of a rectangle"
read l

echo "enter the bredth of the rectangle"
read b

area=$(echo " $l * $b"|bc)

echo "area : $area"

perimeter=$(echo " 2 * ($b + $l)"|bc)
echo "perimeter: $perimeter"