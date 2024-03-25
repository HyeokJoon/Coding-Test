
def calc_hanoi(n):
    if n == 1:
        return 1
    return calc_hanoi(n-1) * 2 + 1


def move(n, a, b, c):
    if n == 1:
        print(a, c)
    else:
        move((n-1)//2, a, c, b)
        print(a, c)
        move((n-1)//2, b, a, c)


n = int(input())
cnt = calc_hanoi(n)
print(cnt)
if n <= 20:
    move(cnt, 1, 2, 3)

