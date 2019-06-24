while :
do
echo "first"
echo "second"
echo "third"
echo "forth"
echo "enter choice"
read choice

case $choice in
1)
	touch f1 f2
	chmod 444 f1
	chmod 444 f2
	ls -l|grep r--r--r-- -c
	;;
2)
	echo "enter file name"
	read t1
	if [ -f "$t1" ]
	then
		set -- `ls -l $t1`
		echo "permission" $1
		echo "link" $2
		echo "user" $3
		echo "batch" $4
		echo "date" $7
	else
		echo "File not found"
	fi
	echo;;
3)
	set `date`
	ncal -h|grep $3|sed "s|$3|"*"|"
	echo;;
4)
	echo "enter source file"
	read source
	echo "enter destination file"
	read dest
	cat $source|head -4|tr '[a-z]' '[A-Z]' >> $dest
	cat $dest
	echo;;
*)
	echo "invalid"
	;;
esac
done

