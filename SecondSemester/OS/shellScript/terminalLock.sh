clear
stty -g
echo "print all current settings in a stty-readable form"
stty -a
echo "print all current settings in human-readable form"
stty --version
echo " output version information and exit"
stty -echo
echo "Enter the password"
read pass1
echo "Re enter the password"
read pass2
if [ $pass1 = $pass2 ]
then
	echo "Terminal locked"
	echo "To unlock enter the password"
	trap " " 20 30 15 9 2 1 3
	while true
	do
		read pass3
		if [ "$pass1" = "$pass3" ]
			then echo "Terminal Unlocked"
			stty echo
			exit
		else
			echo "password not matched... Retype password"
		fi
	done
	else
		echo "Password mismatch"
		stty echo
	fi

