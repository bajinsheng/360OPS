#!/bin/bash

#设置日志文件存放目录
logs_path="/usr/local/nginx/logs/"
#设置pid文件
pid_path="/usr/local/nginx/nginx.pid"

#重命名日志文件
mv ${logs_path}access.log ${logs_path}access_$(date -d "yesterday" +"%Y%m%d").log

#向nginx主进程发信号重新打开日志，会重新创建原来文件名的空日志文件，旧的日志就得以保存下来
kill -USR1 `cat ${pid_path}

#crontab设置每天0点自动切割
#0 0 × × × bash /home/bajinsheng/Documents/4log_cutting.sh

#缺点：文件大小不一。日志的可靠性不能保证，有可能丢失。
