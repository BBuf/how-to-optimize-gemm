import matplotlib.pyplot as plt
import numpy as np

def solve(filename):
    f = open(filename)
    sizes = [40]
    times = [0.0]
    title = 'conv1x1'
    while True:
        line = f.readline()
        if line:
            slices = line.split(" ")
            if len(slices) <= 2:
                break
            size = int(slices[0])
            time = float(slices[1])
            sizes.append(size)
            times.append(time)
    return title, sizes, times

if __name__ == '__main__':
    plt.xlabel('size')
    plt.ylabel('gflops')
    t, x, y = solve('now.txt')
    plt.plot(x, y, label=t)
    plt.legend()
    plt.savefig('conv1x1.png')
    plt.show()