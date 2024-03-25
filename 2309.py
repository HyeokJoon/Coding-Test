list = [int(input()) for _ in range(9)]

gap = sum(list) - 100


def printResult(l):
    l.sort()
    for ll in l:
        print(ll)


for i in range(8):
    for j in range(i+1, 9):
        if (list[i] + list[j]) == gap:
            del list[j]
            del list[i]
            printResult(list)
            break
    if len(list) == 7:
        break
