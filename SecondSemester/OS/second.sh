echo "second part of program"
echo "Enter file name"
read testfile2
if [ -f $testfile2 ]
then
set -- `ls -l $testfile2`
echo "File permission" $1
echo "link" $2
echo "USN" $3
echo "batch" $4
echo "current date" $7
else
echo "file not found"
fi
