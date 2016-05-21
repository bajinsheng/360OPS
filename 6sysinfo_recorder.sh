#!/bin/bash
time=5
num=10
filename=`date +%H%M%S`
echo $filename
echo "#######################CPU 使用情况################################">>/home/bajinsheng/cpu_$(date -d "yesterday" +"%Y%m%d").log
sar -u $time $num >>/home/bajinsheng/cpu_$(date -d "yesterday" +"%Y%m%d").log
echo "#####################cup load###################################">>/home/bajinsheng/cpu_$(date -d "yesterday" +"%Y%m%d").log
uptime>>/home/bajinsheng/cpu_$(date -d "yesterday" +"%Y%m%d").log


#crontab设置每天0点自动记录
#0 0 × × × bash /home/bajinsheng/Documents/6sysinfo_recorder.sh
#每5秒统计一次，统计10存入文件，每天的文件名为cpu_当天日期.log

