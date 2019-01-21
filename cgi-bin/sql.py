#!/usr/bin/python
# -*- coding: UTF-8 -*-

import cgi, cgitb 
import sqlite3

conn = sqlite3.connect('record.db')
cursor = conn.cursor()
cursor.execute("SELECT * from TEM_HUM")

print "Content-type:text/html"
print
print "<!DOCTYPE html>"
print "<html>"
print "<head>"
print """<meta charset="utf-8">"""
print """<meta name="viewport" content="width=device-width, initial-scale=1.0">"""
print "<title>温湿度数据记录</title>"
print """<script src="/plugs/jquery/dist/jquery.min.js"></script>
	<script type="text/javascript" src="/plugs/tableExport.jquery.plugin/libs/js-xlsx/xlsx.core.min.js"></script>
  	<script type="text/javascript" src="/plugs/tableExport.jquery.plugin/tableExport.min.js"></script>"""
print "</head>"
print "<body>"
print """<div class="container" align="center">"""
print """<table id="backViewTable" border="1">"""
print "<tr>"
print "<th>ID</th>"
print "<th>时间</th>"
print "<th>温度</th>"
print "<th>湿度</th>"
print "<th>距离障碍物</th>"
print "<th>机器人时速</th>"
print "</tr>"
for row in cursor:
    print "<tr>"
    print "<th>%d</th>" % row[0]
    print "<td>%s</td>" % row[1]
    print "<td>%s*C</td>" % row[2]
    print "<td>%s%%</td>" % row[3]
    print "<td>%scm</td>" % row[4]
    print "<td>%sm/s</td>" % row[5]
    print "</tr>"
           
print "</table>"
print """<input id="Button1" type="button" value="导出EXCEL" onClick ="$('#backViewTable').tableExport({type:'excel'});"/> """
print "</div>"
print "</body>"
print "</html>"
cursor.close()
conn.close()

