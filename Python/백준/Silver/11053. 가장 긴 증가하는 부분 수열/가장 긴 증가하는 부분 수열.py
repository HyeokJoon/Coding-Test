n = int(input())
arr = map(int, input().split())

answer = []
answer_cnt = 0


def binarySearch(left, right, target):

    while left <= right:
        mid = (left+right)//2
        if answer[mid] == target:
            return mid
        elif answer[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return right+1


for value in arr:
    if answer_cnt == 0:
        answer.append(value)
        answer_cnt += 1
    elif answer[answer_cnt-1] < value:
        answer.append(value)
        answer_cnt += 1 
    else:
        idx = binarySearch(0, answer_cnt, value)
        answer[idx] = value

print(answer_cnt)
