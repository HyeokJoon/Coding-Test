import sys


def input():
    return sys.stdin.readline().rstrip()


m, n, l = map(int, input().split())


m_list = list(map(int, input().split()))
m_list = sorted(m_list)
# print(m_list)


def binarySearch(left, right, l_t, r_t):
    while left <= right:
        mid = (left + right) // 2
        tmp = m_list[mid]
        if tmp >= l_t and tmp <= r_t:
            return True
        if tmp > r_t:
            right = mid - 1
        if tmp < l_t:
            left = mid + 1
    return False


ret = 0
for _ in range(n):
    x, y = map(int, input().split())
    if (y > l):
        continue
    else:
        r_target = x + l-y
        l_target = x - l+y
        if binarySearch(0, m-1, l_target, r_target):
            ret += 1
            continue


print(ret)
