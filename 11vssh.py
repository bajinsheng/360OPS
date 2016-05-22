#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import pexpect
for i in range(1, len(sys.argv)):
   pexpect.spawn('ssh %s' % sys.argv[i])







#设置指令别名后即可使用vssh ip1,ip2....
#alias vssh='python /home/bajinsheng/360OPS/11vssh.py'

