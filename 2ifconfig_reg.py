#encoding=utf-8
import subprocess
tmp_file = open('/tmp/g.log','w')
subprocess.call(['ifconfig'], stdout=tmp_file)#将输出重定向到文件保存

tmp_file = open('/tmp/g.log','r')
ifaces = []#ifconfig输出处理结果
hostIP = {}#将ifaces处理成指定hash
ifaces.append([]) 
ifaces_cnt = 0
line_num = 0
for line_raw in tmp_file:#ifconfig输出处理
    line = line_raw.rstrip() 
    if len(line) > 0:
        ifaces[ifaces_cnt].append(line) 
    else:
        ifaces_cnt = ifaces_cnt +1
        ifaces.append([])

ifaces.pop()
for face in ifaces:#制作指定hash
    key = face[0].split(' ',1)
    key = key[0]
    value = face[1]
    value = value.split(' ',len(value))
    value = value[11][5:len(value)]
    hostIP[key] = value

print str(hostIP)
