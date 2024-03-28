n = int(input())

cur = -1
cnt = 0
while (cur != n):
    if cur == -1:       # 초기 값
        cur = n
    if cur // 10 == 0:  # 10보다 작을 때
        left = 0
        right = cur % 10
    else:               # 10보다 클 때
        left = cur // 10
        right = cur % 10
    cur = right * 10 + (left+right) % 10  # 다음 수
    cnt += 1

print(cnt)
