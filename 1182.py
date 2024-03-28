n, s = map(int, input().split())

x = list(map(int, input().split()))
global cnt
cnt = 0

array = []

def combi(n, i, array, idx):
    if i == n:
        sum = 0
        for a in array:
            sum += a
        if sum == s:
            cnt += 1
    else:
        for k in range(idx+1, len(x)):
            array.append(x[k])
            combi(n, i+1, array, k)
            array.pop(i)


for i in range(1, n):
    combi(i, 0, array, -1)

print(cnt)
