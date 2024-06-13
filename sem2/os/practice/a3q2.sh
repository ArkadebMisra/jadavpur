files=`ls`
c=0
for f in $files
do
    if [ -f $f ]
    then
        echo "$f is a file" 
    elif [ -d $f ]
    then
        echo "$f is a directory"
    fi
    c=`expr $c + 1`     
done
echo "$c"