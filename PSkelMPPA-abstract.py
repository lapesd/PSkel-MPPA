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
ys = [14.8198,  14.8204, 14.8302, 14.8302, 14.8302, 14.93, 14.8305, 14.8301]
plt.plot(xs,ys,marker=markers[2],linewidth=2,label='Fur Abstraction 1000')

#Fur without Communication
ys = [146.17, 146.18, 146.18, 146.3, 146.29, 146.09, 146.2, 146.18]
plt.plot(xs,ys,marker=markers[0],linewidth=2,label='Fur Abstraction 10000')

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

plt.savefig('mppa-communicationAbstract.pdf')
