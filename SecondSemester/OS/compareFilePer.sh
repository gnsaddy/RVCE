!#/bin/bash
echo "Enter the first file name: "
read FILE1
echo "Enter the second file name: "
read FILE2
fileperm=$(stat -c '%A' "$FILE1")
filepermi=$(stat -c '%A' "$FILE2")

if [ "$fileperm" = "$filepermi" ]; then
        echo $(stat -c '%A' "$fileperm") 
fi



        