#!/usr/bin/python
import os
import sqlite3
import datetime
import Adafruit_DHT
import time
import rospy
from std_msgs.msg import String

MAX = 51
pin = 5
i = 1
sensor = Adafruit_DHT.DHT11
flag = True  
distance = 0
speed = 0
def callback(data):
    global distance
    global speed
    my_str = data.data.split(' ')
    distance = my_str[0]
    speed = my_str[1]
conn = sqlite3.connect('record.db')
c = conn.cursor()
try:
    c.execute('''CREATE TABLE TEM_HUM
        (ID INT PRIMARY KEY     NOT NULL,
        DATE           TEXT    NOT NULL,
        TEMPERATURE    DOUBLE     NOT NULL,
        HUMIDITY	DOUBLE     NOT NULL,
        DISTANCE    TEXT      NOT NULL,
        SPEED       TEXT      NOT NULL);''')
    conn.commit()
except:
    print "can't create table"

pub = rospy.Publisher('record', String, queue_size=10)
rospy.init_node('dht11', anonymous=True)
rospy.Subscriber('listener', String, callback)
rate = rospy.Rate(10)
while not rospy.is_shutdown():
    try:
	humidity,temperature = Adafruit_DHT.read_retry(sensor, pin)
	nowTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
	if distance == 0 or humidity > 100:
	    continue
        print humidity
        print temperature
	sql_insert = "INSERT INTO TEM_HUM (ID,DATE,TEMPERATURE,HUMIDITY,DISTANCE,SPEED) \
	  VALUES(%d,'%s',%f,%f,'%s','%s');" % (i,nowTime, temperature, humidity, distance,speed)
	sql_update = "UPDATE TEM_HUM SET DATE='%s', TEMPERATURE=%f, \
	  HUMIDITY=%f, DISTANCE='%s', SPEED='%s' WHERE ID=%d;" % (nowTime, temperature, humidity, distance, speed, i)
	sql_select = "SELECT * FROM TEM_HUM WHERE ID=%d;" % (i)
	record_str = "%s*C; %s%%" % (temperature, humidity)
	
	flag = False
	for row in c.execute(sql_select):
	    if row[0]:
	        flag = True
	if flag:
	    c.execute(sql_update)
	else:
	    c.execute(sql_insert)
	conn.commit();
	i+=1;
	if i == MAX:
      	    i = 1
    except:
        print "wrong"
        continue
    pub.publish(record_str)
    rate.sleep()
conn.close()
