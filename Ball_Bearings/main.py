import math as m

def cal_max_balls(D, d, s):
    return m.floor(m.pi/m.asin((d+s)/(D-d)))

def main():
    n = int(input())
    for i in range(n):
        lst = input().split()
        print(cal_max_balls(float(lst[0]), float(lst[1]), float(lst[2])))

main()