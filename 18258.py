import sys


def input():
    return sys.stdin.readline().rstrip()


n = int(input())
queue = []
start = 0
cnt = 0
answer = []
for i in range(n):
    inputs = input().split()
    op = inputs[0]

    if op == "push":
        queue.append(inputs[1])
        cnt += 1
    elif op == "pop":
        if cnt == start:
            answer.append(-1)
        else:
            answer.append(queue[start])
            start += 1
    elif op == "size":
        answer.append(cnt-start)
    elif op == "empty":
        if cnt == start:
            answer.append(1)
        else:
            answer.append(0)
    elif op == "front":
        if cnt == start:
            answer.append(-1)
        else:
            answer.append(queue[start])
    elif op == "back":
        if cnt == start:
            answer.append(-1)
        else:
            answer.append(queue[len(queue)-1])

for a in answer:
    print(a)
