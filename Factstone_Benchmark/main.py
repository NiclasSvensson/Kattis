import math as m

log2_sum = [0]

def factstone(N):
    while N > len(log2_sum) - 1:
        log2_sum.append(log2_sum[-1] + m.log2(len(log2_sum)+1))
    return log2_sum[N]

def compare(K):
    N = 1
    while K > factstone(N):
        N += 1
    return N

def get_bits(year):
    return 2**(m.floor(year/10) - 194)

def main():
    year = int(input())
    while year != 0:
        bits = int(get_bits(year))
        N = compare(bits)
        print(N)
        year = int(input())

main()