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
ys = [0.12009, 0.120218, 0.119932, 0.119858, 0.120162, 0.120196, 0.13052, 0.130118]
plt.plot(xs,ys,marker=markers[2],linewidth=2,label='Fur Communication')

# #Fur without Communication
# ys = [94.6803, 47.4601, 35.5, 23.8396, 23.6799, 23.61, 23.5501, 12.0402]
# plt.plot(xs,ys,marker=markers[0],linewidth=2,label='Fur without Communication')

plt.xticks([w*2 for w in range(9)])
plt.yticks([0, 1])
plt.xlim(1.8,16.2)
plt.ylim(0,1.2)

plt.xlabel('Number of clusters')
plt.ylabel('Execution Time')
   #plt.xlim(-0.15, 2.9)
plt.grid(which='major')
#plt.tick_params(labelsize=12)
#plt.tick_params(pad=10)

plt.tick_params(labelsize=19, pad=5, width=2)
plt.legend(loc='best', fontsize = 'small', ncol=1)

plt.savefig('mppa-communicationNoabstract.pdf')
