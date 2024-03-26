n, m = map(int, input().split())
trees = list(map(int, input().split()))

maxi = max(trees)


def binarySearch(left, right, target):

    while (left <= right):

        mid = (left+right) // 2
        sum = 0
        for t in trees:
            if t >= mid:
                sum += t-mid

        if sum == target:
            print(mid)
            return
        if sum < target:
            right = mid-1
            continue
        if sum > target:
            left = mid+1
    print(right)


binarySearch(0, maxi, m)
