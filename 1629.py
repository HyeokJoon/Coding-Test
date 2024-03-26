a, b, c = map(int, input().split())


def calc(a, b, c):
    if b == 1:
        return a % c
    else:
        ret = calc(a, b//2, c)
        ret = (ret * ret) % c
        if (b % 2 == 1):
            ret = ret * a % c
        return ret


print(calc(a, b, c))
