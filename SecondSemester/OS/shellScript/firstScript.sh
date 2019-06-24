while :
do
echo "1.Count the files with read only"
echo "2.Display the properties"
echo "3.Display current date"
echo "4.Convert lines of files into toggle case"
echo "5.Exit"
echo "Enter choice:"
read num
case $num in
1)

        chmod 444 file
        ls -l|grep r--r--r-- -c
        ;;      
2)

        echo "Enter file name"
        read file
        if [ -f "$file" ]
        then
                set -- `ls -l $file`
                echo "File permission"$1
                echo "Link"$2
                echo "User name"$3
                echo "Batch"$4
                echo "Current date"$7
        else
                echo "File not exist"
        fi
                echo;;
3)
        set -- `date`
        ncal -h|grep $3|sed "s| $3|"*"|"
        echo;;
4)
        echo "Enter the source file"
        read source
        echo "Destination "
        read dest

        cat $source |head -4 |tr '[a-z]' '[A-Z]' >> $dest
        cat $dest
        echo;;
5)
exit;;
*)
echo "Invalid choice"
;;
esac
done
