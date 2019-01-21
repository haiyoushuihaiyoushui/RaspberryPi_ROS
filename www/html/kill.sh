#!/bin/sh

for i in $(ps -ax | grep node | grep -v grep)
do
     if echo "$i" | grep -q '^[0-9]\+$';
     then
     #echo $i
     kill -9 $i
fi
done
sleep 1
for i in $(ps -ax | grep ffmpeg | grep -v grep)
do
     if echo "$i" | grep -q '^[0-9]\+$';
     then
     #echo $i
     kill -9 $i
fi
done
sleep 1
for i in $(ps -ax | grep ros | grep -v grep)
do
     if echo "$i" | grep -q '^[0-9]\+$';
     then
     #echo $i
     kill -9 $i
fi
done
