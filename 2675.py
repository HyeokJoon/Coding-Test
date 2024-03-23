t = int(input())
for i in range(t):
    a, s = input().split()
    for j in range(len(s)):
        print(s[j]*int(a), end="")
    print()
