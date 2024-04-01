# from itertools import permutations
# import sys
# def input(): return sys.stdin.readline().rstrip()


# n = int(input())
# arr = list(map(int, input().split()))
# oper_cnt = list(map(int, input().split()))
# oper_list = []

# for i in range(4):
#     for _ in range(oper_cnt[i]):
#         oper_list.append(str(i))

# opers = list(map(''.join, permutations(oper_list)))


# def calc(num, a, b):
#     if num == '0':
#         return a+b
#     if num == '1':
#         return a-b
#     if num == '2':
#         return a*b
#     if num == '3':
#         if a < 0 and b > 0:
#             return -1*(-1*a // b)
#         return a//b


# maxi = 0
# mini = 1000000000
# for l in opers:
#     result = arr[0]
#     for i in range(len(l)):
#         result = calc(l[i], result, arr[i+1])
#     if result < mini:
#         mini = result
#     if result > maxi:
#         maxi = result

# print(maxi)
# print(mini)
# 백트래킹 (Python3 통과, PyPy3도 통과)
import sys

input = sys.stdin.readline
N = int(input())
num = list(map(int, input().split()))
op = list(map(int, input().split()))  # +, -, *, //

maximum = -1e9
minimum = 1e9


def dfs(depth, total, plus, minus, multiply, divide):
    global maximum, minimum
    if depth == N:
        maximum = max(total, maximum)
        minimum = min(total, minimum)
        return

    if plus:
        dfs(depth + 1, total + num[depth], plus - 1, minus, multiply, divide)
    if minus:
        dfs(depth + 1, total - num[depth], plus, minus - 1, multiply, divide)
    if multiply:
        dfs(depth + 1, total * num[depth], plus, minus, multiply - 1, divide)
    if divide:
        dfs(depth + 1, int(total / num[depth]), plus, minus, multiply, divide - 1)


dfs(1, num[0], op[0], op[1], op[2], op[3])
print(maximum)
print(minimum)