# --------------------------------------
# 리스트 생성 속도 확인
# --------------------------------------
# BOJ 11723번을 풀면서..
# 참조 : https://stackoverflow.com/questions/20816600/best-and-or-fastest-way-to-create-lists-in-python

import dis

Set = [False for _ in range(21)]

def init1():
    Set1 = [False] * 21

def init2():
    Set2 = [False for _ in range(21)]

def init3():
    for i in range(1, 21):
        Set[i] = False

dis.dis(init1)
print("-----------------------------------------------")
dis.dis(init2)
print("-----------------------------------------------")
dis.dis(init3)
