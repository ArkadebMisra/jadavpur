# echo "$*"
for i in $*
do



	# du -hm $i
	echo "Disk Space occupied by the directory $i size in bytes"
	echo "";
	bytes=`du -hb $i`
	echo "$bytes"; echo "";

	echo "Disk Space occupied by the directory $i size in kilobytes"
	echo "";
	bytes=`du -hk $i`
	echo "$bytes"; echo "";


	echo "Disk Space occupied by the directory $i size in megabytes"
	echo "";
	bytes=`du -hm $i`
	echo "$bytes"; echo "";

	# kilobytes=`du -hk $i | cut -f1`
	# echo "Size in kilobyte $kilobytes KB"
	# megabytes=`du -hm $i | cut -f1`
	# echo "Size in megabyte $megabytes MB"


	# du -hm $i
	# echo "Disk Space occupied by the directory $i"
	# bytes=`du -hb $i | cut -f1`
	# echo "Size in byte $bytes"
	# kilobytes=`du -hk $i | cut -f1`
	# echo "Size in kilobyte $kilobytes KB"
	# megabytes=`du -hm $i | cut -f1`
	# echo "Size in megabyte $megabytes MB"
done 
