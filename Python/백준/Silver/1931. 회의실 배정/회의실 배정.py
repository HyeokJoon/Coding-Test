import sys
def input(): return sys.stdin.readline().rstrip()


n = int(input())
meetings = [tuple(map(int, input().split())) for _ in range(n)]

meetings.sort(key=lambda x: (x[1], x[0]))

# print(meetings)
cnt = 0
end = 0
for i in range(n):
    if meetings[i][0] < end:
        continue
    cnt += 1
    end = meetings[i][1]

print(cnt)
