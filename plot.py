import numpy as np
import matplotlib.pyplot as plt
import os, math

"""
    Abgabe Blatt 10 Cache Messen
    Niklas Rausch, Anne Schulte-Kroll und Wolf Weber
"""

data = np.loadtxt("output.csv", delimiter=";",comments="#")
data = np.transpose(data)

##### Plot Speedup
fig = plt.figure() # figsize=(11,6)
ax = plt.gca()

ax.plot(data[0],data[1], c="C0")
ax.set_xscale("log")
ax.scatter(data[0],data[1], c="C0")
ax.set_xscale("log")

plt.grid(True)
plt.xlabel("N   (Arraylength in Bytes)")
plt.ylabel("t (GBytes/sec)\n(Read/Write Time from Cache/RAM)")
plt.title("Memory Read/Write Access Speed")
# plt.legend(legend)
fig.show()

##### Plot Speedup
fig = plt.figure() # figsize=(11,6)
ax = plt.gca()

ax.plot(data[0],data[1], c="C0")
#ax.set_xscale("log")
ax.scatter(data[0],data[1], c="C0")
#ax.set_xscale("log")

plt.grid(True)
plt.xlabel("N   (Arraylength in Bytes)")
plt.ylabel("t (GBytes/sec)\n(Read/Write Time from Cache/RAM)")
plt.title("Memory Read/Write Access Speed")
# plt.legend(legend)
fig.show()


# hold program open
input()