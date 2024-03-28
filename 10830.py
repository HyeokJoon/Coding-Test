global n, b
n, b = map(int, input().split())

matrix = [[0]*n for _ in range(n)]

for i in range(n):
    matrix[i] = list(map(int, input().split()))


def mul(m1, m2):
    sum = 0
    tmp = [[0]*n for _ in range(n)]
    for i in range(n):
        tmp[0][0] += m1[i][0] * m2[0][i]
        tmp[0][]


def calc(n, b, matrix):
    if b == 2:
        mul(matrix, matrix)
