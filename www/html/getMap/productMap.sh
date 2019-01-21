#!/bin/bash

while true
do
    rosrun map_server map_saver -f hello
    ffmpeg -i hello.pgm -s 544x544 hello.jpg -y
done
