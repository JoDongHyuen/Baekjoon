# --------------------------------------
# list 와 tuple의 생성, 접근 속도 차이
# --------------------------------------
# BOJ 11003번을 풀며 겪은 시행착오
# 아래 결과를 보면 tuple을 생성이 O(1)이지만 리스트는 생성이 O(N)인 걸 볼 수 있음
# 접근도 tuple이 과정이 좀 더 간략한 것을 볼 수 있다
# 참고 사이트 : https://stackoverflow.com/questions/68630/are-tuples-more-efficient-than-lists-in-python

import dis

def list_test():
    x = [1,2,3,4,5]
    y = x[1]

def tuple_test():
    x = (1,2,3,4,5)
    y = [1]


dis.dis(list_test)
print("-----------------------------------------------")
dis.dis(tuple_test)


# result
#   9           0 LOAD_CONST               1 (1)
#               2 LOAD_CONST               2 (2)
#               4 LOAD_CONST               3 (3)
#               6 LOAD_CONST               4 (4)
#               8 LOAD_CONST               5 (5)
#              10 BUILD_LIST               5
#              12 STORE_FAST               0 (x)

#  10          14 LOAD_FAST                0 (x)
#              16 LOAD_CONST               1 (1)
#              18 BINARY_SUBSCR
#              20 STORE_FAST               1 (y)
#              22 LOAD_CONST               0 (None)
#              24 RETURN_VALUE
# -----------------------------------------------
#  13           0 LOAD_CONST               1 ((1, 2, 3, 4, 5))
#               2 STORE_FAST               0 (x)

#  14           4 LOAD_CONST               2 (1)
#               6 BUILD_LIST               1
#               8 STORE_FAST               1 (y)
#              10 LOAD_CONST               0 (None)
#              12 RETURN_VALUE