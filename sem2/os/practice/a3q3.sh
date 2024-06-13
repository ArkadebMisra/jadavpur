# size=0
# for l in `ls -l`
# do
    
#     s=$(echo "$l" | cut -f 5)
#     echo "$s"
#     size=`expr $s + $size`
#     break
# done
# echo "Size: $size"

exp=`ls -l | awk '{print $5}'`
total=0
for i in $exp
do 
    echo "$i"
	total=`expr $total + $i`
done
echo "Total space occupied by the current directory is "$total" Byte"
