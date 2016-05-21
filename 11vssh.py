#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import pexpect
for i in range(1, len(sys.argv)):
    pexpect.spawn('ssh %s' % sys.argv[i])

