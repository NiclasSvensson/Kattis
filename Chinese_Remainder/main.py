def ee_algorithm(a, n, b, m):
    K = m*n
    old_r, r, old_s, s, old_t, t = n, m, 1, 0, 0, 1
    while r != 0:
        q = old_r // r

        prov = r
        r = old_r - q*prov
        old_r = prov

        prov = s
        s = old_s - q*prov
        old_s = prov

        prov = t
        t = old_t - q*prov
        old_t = prov

    x = (b*n*old_s) + (a*m*old_t)
    x = x % K
    print(str(x) + " " + str(K))

def main():
    T = int(input())
    for i in range(T):
        lst = input().split()
        ee_algorithm(int(lst[0]), int(lst[1]), int(lst[2]), int(lst[3]))

main()