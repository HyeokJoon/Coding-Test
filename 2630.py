n = int(input())
cnt = [0, 0]
_map = [[0]*n for _ in range(n)]
for i in range(n):
    _map[i] = list(map(int, input().split()))


def clean(startRow, startCol, length):
    flag = _map[startRow][startCol]
    for i in range(length):
        for j in range(length):
            if _map[startRow+i][startCol+j] != flag:
                return False
    return True


def solution(startRow, startCol, length):
    if clean(startRow, startCol, length):
        cnt[_map[startRow][startCol]] += 1
        return
    else:
        nleng = length//2
        solution(startRow, startCol, nleng)
        solution(startRow+nleng, startCol, nleng)
        solution(startRow, startCol+nleng, nleng)
        solution(startRow+nleng, startCol+nleng, nleng)


solution(0, 0, n)
print(cnt[0])
print(cnt[1])
