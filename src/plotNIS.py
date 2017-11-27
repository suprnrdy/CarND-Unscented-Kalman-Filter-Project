import numpy as np
import matplotlib.pyplot as plt

with open("../buildxcode/Debug/nis_radar.txt") as f:
    data = f.read()
    
    data = data.split('\n')
    x = [float(i) for i in data]

    
    
    fig = plt.figure()
    ax1 = fig.add_subplot(111)
    ax1.set_title("NIS Lidar")
    ax1.set_ylabel('NIS')
    
    
    ax1.plot(x, 'b')
    plt.axhline(y=7.8, color='r', linestyle='-')
    plt.show()