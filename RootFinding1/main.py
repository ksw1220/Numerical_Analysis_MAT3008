from matplotlib import pyplot as plt
import csv

if __name__ == '__main__':
    # 2.404738, 2.404826, 2.404826,
    # 5.520187, 5.520077, 5.520078,
    # 8.653870, 8.653727, 8.653728,
    x=[1.500000,1.445642,1.367157,1.183578,1.091789,1.123108,1.119554,1.119499]
    plt.title("problem4")
    plt.xlabel("iter")
    plt.ylabel("root")
    plt.plot(x)

    plt.show()
