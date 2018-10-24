cd tmp/
a=1;
for i in $(ls); do
	if [ $(stat --printf="%h\n" $i) -gt $a ]
	then
		b=$(pwd)
		set -- $(ls -i $i);
		echo $2
		cd ~/
		find -inum $1
		cd $b
		echo
	fi
done;
cd ../