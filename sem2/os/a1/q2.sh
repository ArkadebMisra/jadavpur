#!/bin/sh
 
echo "enter basic salary: "
read basic
 
da=.10
rental_allowance=10000
tiffin_allowance=7000
 
total_salary=$( echo "basic + ($basic * $da ) + $rental_allowance + $tiffin_allowance"|bc)
da_allowance=$(echo "$basic * $da"|bc)
echo "basic salarry: $basic"
echo "da : $da_allowance"
echo "rental allowance : $rental_allowance" 
echo "tiffin_allowance: $tiffin_allowance" 
echo "total salary: $total_salary"