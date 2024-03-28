n = int(input())

arr = [[0]*n for _ in range(n)]
for i in range(n):
    line = input()
    for j in range(len(line)):
        arr[i][j] = line[j]


def isMixed(_n, startx, starty):
    first = arr[startx][starty]
    for i in range(startx, startx+_n):
        for j in range(starty, starty+_n):
            if arr[i][j] != first:
                return True
    return False


answer = []


def QuadTree(n, startx, starty):
    if isMixed(n, startx, starty):
        answer.append("(")
        next_n = n//2
        QuadTree(next_n, startx, starty)  # 왼쪽 위
        QuadTree(next_n, startx, starty+next_n)  # 오른쪽 위
        QuadTree(next_n, startx+next_n, starty)  # 왼쪽 아래
        QuadTree(next_n, startx+next_n, starty+next_n)  # 오른쪽 아래
        answer.append(")")
    else:
        answer.append(arr[startx][starty])


QuadTree(n, 0, 0)
for a in answer:
    print(a, end='')
