#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
if sys.version_info[0] < 3:
   from StringIO import StringIO
else:
   from io import StringIO

import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib import cm
import numpy as np
import pandas as pd

mpl.rcParams['axes.linewidth'] = 1.2
mpl.rcParams['font.size'] = 19
#mpl.rcParams['font.weight'] = 'bold'

markers = ['o','D','s','x']
xs = [2,4,6,8,10,12,14,16]

#Fur Communication
ys = [15.3707,  15.3803, 15.3803, 15.4996, 15.2899, 15.4007, 15.4003, 15.41]
plt.plot(xs,ys,marker=markers[2],linewidth=2,label='Fur All 1000')

#Fur without Communication
ys = [151.681, 151.68, 151.69, 151.6, 151.7, 151.71, 151.72, 151.72]
plt.plot(xs,ys,marker=markers[0],linewidth=2,label='Fur All 10000')

plt.xticks([w*2 for w in range(9)])
plt.yticks([0, 1])
plt.xlim(1.8,16.2)
plt.ylim(0,150.2)

plt.xlabel('Number of clusters')
plt.ylabel('Execution Time')
   #plt.xlim(-0.15, 2.9)
plt.grid(which='major')
#plt.tick_params(labelsize=12)
#plt.tick_params(pad=10)

plt.tick_params(labelsize=19, pad=5, width=2)
plt.legend(loc='best', fontsize = 'small', ncol=1)

plt.savefig('mppa-communicationAll.pdf')
