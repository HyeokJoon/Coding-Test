

stack = []
cnt = 0
flag = True
inputs = input()

for i in inputs:
    if i == ")":
        # "(" 가 나올때까지
        mid = 0
        while True:
            if cnt == 0:
                flag = False
                break
            top = stack.pop(cnt-1)
            # 다른 문자가 나오면 잘못된 괄호열
            if top == "]" or top == "[" or top == ")":
                flag = False
                break
            # 여는 괄호가 나오면
            if top == "(":
                if mid == 0:
                    stack.append(2)
                    break
                else:
                    stack.append(2*mid)
                    break
            # 숫자가 나오면
            else:
                mid += top
                cnt -= 1

    elif i == "]":
        # "[" 가 나올때까지
        mid = 0
        while True:
            if cnt == 0:
                flag = False
                break
            top = stack.pop(cnt-1)
            # 다른 문자가 나오면 잘못된 괄호열
            if top == "]" or top == "(" or top == ")":
                flag = False
                break
            # 여는 괄호가 나오면
            if top == "[":
                if mid == 0:
                    stack.append(3)
                    break
                else:
                    stack.append(3*mid)
                    break
            # 숫자가 나오면
            else:
                mid += top
                cnt -= 1
    else:
        stack.append(i)
        cnt += 1

    if flag == False:
        break

ret = 0
while cnt > 0:
    if flag == False:
        break
    t = stack.pop(cnt-1)
    cnt -= 1
    if t == "[" or t == "]" or t == "(" or t == ")":
        flag = False
    else:
        ret += t

if flag:
    print(ret)
else:
    print(0)
