echo "part first program"
chmod 444  testFile

ls -l | grep r--r--r-- -c
