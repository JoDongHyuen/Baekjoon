# --------------------------------------
# AC
# --------------------------------------

from collections import deque
import sys

Test_Case = int(sys.stdin.readline())

for _ in range(Test_Case):
    Ist = str(sys.stdin.readline().strip())

    element_num = int(sys.stdin.readline())
    input = str(sys.stdin.readline().strip())
    arr = deque(input[1:-1].split(","))

    reverse = False
    error = False
    for i in Ist:
        if i == 'R':
            reverse = not reverse
        else:
            if arr:
                if reverse:
                    arr.pop()
                else:
                    arr.popleft()
            else:                
                error = True
                break

    if error:
        print('error')
    else:
        if reverse:
            arr.reverse()
        print(f"[{','.join(arr)}]")