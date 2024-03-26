from __future__ import annotations

n, k = map(int, input().split())


class Node:
    def __init__(self, value: int, next: Node):
        self.value = value
        self.next = next


linkedList = [Node]
cnt = 0

for i in range(1, n+1):
    if cnt == 0:
        linkedList[0] = Node(i, None)
        cnt += 1
    else:
        tmp = Node(i, linkedList[0])
        linkedList.append(tmp)
        linkedList[cnt-1].next = tmp
        cnt += 1


p = Node(0, linkedList[0])
prev = Node(0, p)
answer = "<"
while linkedList:
    if cnt == 1:
        answer += str(p.next.value)
        break
    for _ in range(k):
        prev = p
        p = p.next
    answer += str(p.value) + ', '
    prev.next = p.next
    cnt -= 1
answer += '>'
print(answer)
