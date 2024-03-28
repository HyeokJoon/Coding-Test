
left = [0]*27
right = [0]*27

n = int(input())
for _ in range(n):
    inputs = input().split()
    if inputs[1] != ".":
        left[ord(inputs[0]) - ord("A")] = ord(inputs[1]) - ord("A")
    if inputs[2] != ".":
        right[ord(inputs[0]) - ord("A")] = ord(inputs[2]) - ord("A")


def preorder(x):
    print(chr(x+ord("A")), end='')
    if left[x]:
        preorder(left[x])
    if right[x]:
        preorder(right[x])


def inorder(x):
    if left[x]:
        inorder(left[x])
    print(chr(x+ord("A")), end='')
    if right[x]:
        inorder(right[x])


def postorder(x):
    if left[x]:
        postorder(left[x])
    if right[x]:
        postorder(right[x])
    print(chr(x+ord("A")), end='')


preorder(0)
print()
inorder(0)
print()
postorder(0)
