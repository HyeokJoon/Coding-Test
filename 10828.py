n = int(input())
stack = [0]*10010
stack_cnt = 0
sentence = ""

for _ in range(n):
    order = list(input().split())
    op = order[0]

    if (op == "push"):
        operand = order[1]
        stack[stack_cnt] = operand
        stack_cnt += 1
    elif (op == "pop"):
        if stack_cnt == 0:
            sentence += '-1\n'
        else:
            sentence += str(stack[stack_cnt-1]) + '\n'
            stack_cnt -= 1
    elif (op == "size"):
        sentence += str(stack_cnt) + '\n'
    elif (op == "empty"):
        if stack_cnt == 0:
            sentence += '1\n'
        else:
            sentence += '0\n'
    elif (op == "top"):
        if stack_cnt == 0:
            sentence += '-1\n'
        else:
            sentence += str(stack[stack_cnt-1]) + '\n'

print(sentence)
