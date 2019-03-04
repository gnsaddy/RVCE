echo "third part of program"
set -- `date`
ncal -h | grep $3 | sed "s|$3|"*"|"

