lockfile=./file.lock
rm $lockfile
while [ 1 ]
do
if ln ./file $lockfile ; then
    a=$(grep -Eo '^[0-9]+$' file | tail -1)
	a=`expr $a + 1`
	echo >>file $a
    rm $lockfile # after you're done
else 
    sleep 1
fi
done