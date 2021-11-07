from matplotlib import pyplot as plt
import csv

if __name__ == '__main__':

    f = open('random_number.csv', 'r')
    rdr = csv.reader(f)
    data = []
    line_cnt=1
    for line in rdr:
        data=[]
        str = line
        for j in range(len(line)-1):
            data.append(float(line[j]))
        # plt.xlim([-3.0, 2.0])
        plt.hist(data, bins=101)
        plt.show()
        line_cnt=line_cnt+1
        
    f.close()
