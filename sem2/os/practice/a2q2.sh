IFS=:

for path in $PATH
do
    echo "permission"
    echo `ls -ld $path | cut -f1 -d " "`
    echo "modification time"
    echo `ls -ld $path | awk '{print $6,$7,$8}'`

break
done
