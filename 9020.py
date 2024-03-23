
def isPrime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True


def eratos(num):
    sieve = [True]*num
    m = int(num**0.5)
    for i in range(2, m+1):
        if sieve[i] == True:
            for j in range(i+i, num, i):
                sieve[j] = False
    return [i for i in range(2, num) if sieve[i] == True]


for i in range(int(input())):
    num = int(input())
    half = int(num/2)+1
    list = eratos(half)

    for i in range(len(list)):
        num1 = list[-i]
        if (isPrime(num-num1)):
            print(num1, num-num1)
            break
