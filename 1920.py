import sys


def input():
    return sys.stdin.readline().rstrip()


n = int(input())
arr = list(map(int, input().split()))
m = int(input())
targets = list(map(int, input().split()))


def binarySearch(left, right, target):

    while (left <= right):

        mid = (left+right) // 2

        if arr[mid] == target:
            return 1
        if arr[mid] > target:
            right = mid-1
            continue
        if arr[mid] < target:
            left = mid+1
    return 0


arr.sort()
for i in targets:
    if binarySearch(0, n-1, i) == 1:
        print(1)
    else:
        print(0)
