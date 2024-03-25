n = int(input())

list = [input() for _ in range(n)]

list.sort(key=lambda x: (len(x), x))

result = dict.fromkeys(list)

for key in result:
    print(key)
