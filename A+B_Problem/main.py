import sys

m = dict()

def calculate_ways(l):
    result = 0
    count = 0
    for x in l:
        for y in l[count:len(l)]:
            if x + y in m:
                if x == 0 and y == 0:
                    result += (0 if m[x] < 3 else m[x]* (m[x] - 1) * (m[x] - 2))
                elif x == 0 or y == 0:
                    if x == 0 and m[y] > 1:
                        result += 2*(m[x] * m[y] * (m[y] - 1))
                    elif y == 0 and m[x] > 1:
                        result += 2*(m[y] * m[x] * (m[x] - 1))
                elif x == y:
                    result += (m[x] * (m[x] - 1) * m[x + y])
                else:
                    result += 2*(m[x] * m[y] * m[x + y])
        count += 1
    return result

def main():
    number = input()
    l = input()
    l = l.split()
    l = [int(x) for x in l]
    #l.sort()
    for i in range(int(number)):
        if l[i] in m:
            m[l[i]] += 1
        else:
            m[l[i]] = 1
    print(calculate_ways(list(m.keys())))

main()