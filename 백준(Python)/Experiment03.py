# --------------------------------------
# 리스트 생성 속도 확인
# --------------------------------------
# BOJ 11723번을 풀면서..
# 정리 : init 1번처럼 초기화하는게 엄청 빠름
# 참조 : https://stackoverflow.com/questions/20816600/best-and-or-fastest-way-to-create-lists-in-python

import dis
from timeit import timeit

Set = [False for _ in range(21)]

def init1():
    Set1 = [False] * 21

def init2():
    Set2 = [False for _ in range(21)]

def init3():
    for i in range(1, 21):
        Set[i] = False

# dis.dis(init1)
# print("-----------------------------------------------")
# dis.dis(init2)
# print("-----------------------------------------------")
# dis.dis(init3)

test = '''
Set = []
for i in range(1, 21):
        Set += [False]
'''
print(timeit(test))

test = 'Set2 = [False for _ in range(21)]'
print(timeit(test))

test = 'Set1 = [False] * 21'
print(timeit(test))
