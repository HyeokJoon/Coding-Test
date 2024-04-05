str1 = '0' + input()
str2 = '0' + input()
n = len(str1)
m = len(str2)
_map = [[0] * n for _ in range(m)]

for i in range(1, m):
    for j in range(1, n):
        _map[i][j] = max(_map[i-1][j], _map[i][j-1])
        if str1[j] == str2[i]:
            _map[i][j] = _map[i-1][j-1] + 1

print(_map[m-1][n-1])
