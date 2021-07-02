# --------------------------------------
# deque와 list 접근 속도
# --------------------------------------
# BOJ 12015번을 풀며 겪은 시행착오
# deque가 list 보다 무조건 빠르다는 착각을 했음
# byte code 상 별 차이는 찾아볼 수 없었지만 속도 실험을 해봤을 때 어마어마하게 차이가 남
# 즉 deque 쓸 때, index를 이용해 access 하지 말자!!!
# 참고 사이트 : https://dev.to/v_it_aly/python-deque-vs-listwh-25i9

from collections import deque
import dis

def deque_test():
    de = deque(range(100))
    num = de[100]

def list_test():
    li = list(range(100))
    num = li[100]


dis.dis(deque_test)
print("-----------------------------------------------")
dis.dis(list_test)

# byte code 상 차이점은 별로 보이지 않음


import time

de = deque(range(100000000))
li = list(range(100000000))

start = time.time()
de[10000000]
duration = time.time() - start
print(duration)

start = time.time()
li[10000000]
duration = time.time() - start
print(duration)

# result
# 0.9983298778533936
# 0.0