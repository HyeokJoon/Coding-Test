n = int(input())
dic = [0]*100
dic[1] = 1


def fibo(n):
    if dic[n] or n == 0:
        return dic[n]
    dic[n] = fibo(n-2) + fibo(n-1)
    return dic[n]


print(fibo(n))
