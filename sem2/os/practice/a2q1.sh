for f in *
do
    if [ -f $f ]
    then
        echo "$f is a file"
    elif [ -d $f ]
    then
        echo "$f is a directory"
    fi
done
