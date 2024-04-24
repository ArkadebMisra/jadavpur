# echo "$*"
for i in $*
do
	du -hm $i
	echo "Disk Space occupied by the directory $i"
	bytes=`du -hb $i | cut -f1`
	echo "Size in byte $bytes"
	kilobytes=`du -hk $i | cut -f1`
	echo "Size in kilobyte $kilobytes KB"
	megabytes=`du -hm $i | cut -f1`
	echo "Size in megabyte $megabytes MB"
done 
