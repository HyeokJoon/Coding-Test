import sys
def input(): return sys.stdin.readline().rstrip()


k = int(input())

for _ in range(k):
    v, e = map(int, input().split())
    colors = [-1]*(v+1)
    queue = []
    vector = [[] for _ in range(v+1)]
    for _ in range(e):
        v1, v2 = map(int, input().split())
        vector[v1].append(v2)
        vector[v2].append(v1)

    flag = True
    for i in range(1, v+1):
        if colors[i] == -1:
            queue.append(i)
            colors[i] = 1
            while queue and flag:

                top = queue.pop(0)
                color = colors[top]

                for vertex in vector[top]:
                    if colors[vertex] == -1:
                        colors[vertex] = (color+1) % 2
                        queue.append(vertex)
                    elif colors[vertex] == color:
                        print("NO")
                        flag = False
                        break
                    else:
                        continue
    if flag:
        print("YES")
