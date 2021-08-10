# --------------------------------------
# 비밀번호 찾기
# -------------------------------------- 

import sys

N, M = map(int, sys.stdin.readline().split())

pwds = {}
for _ in range(N):
    site, pwd = sys.stdin.readline().strip().split()
    pwds[site] = pwd

for _ in range(M):
    site = sys.stdin.readline().strip()
    print(pwds[site])