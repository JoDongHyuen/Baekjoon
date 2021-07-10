# --------------------------------------
# IQ Test
# --------------------------------------

import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))


if N == 1:
    print("A")
elif N == 2:
    if arr[0] == arr[1]:
        print(arr[1])
    else:
        print("A")
else:

    check = True

    if arr[0] == arr[1]:
        a = 1
    else:
        a = (arr[2] - arr[1]) // (arr[1]-arr[0])

    b = arr[1] - a * arr[0]

    for i in range(1, N):
        if arr[i] != a * arr[i-1] + b:
            check = False
            break
    
    if check == True:
        print(a * arr[-1] + b)
    else:
        print("B")