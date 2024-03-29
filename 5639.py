import sys
sys.setrecursionlimit(10**9)


def input():
    return sys.stdin.readline().rstrip()


stack = []

while True:
    try:
        n = int(input())
        stack.append(n)
    except:
        break


def print_stack(s, e):
    if e < s:
        return
    if e == s:
        print(stack[e])
    else:
        mid = stack[s]
        flag = 0
        for i in range(s+1, e+1):
            if stack[i] > mid:
                flag = 1
                break
        if flag == 0:
            print_stack(s+1, e)
            print(mid)
        else:
            print_stack(s+1, i-1)
            print_stack(i, e)
            print(mid)


print_stack(0, len(stack)-1)
