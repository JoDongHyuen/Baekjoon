# --------------------------------------
# 거짓말
# --------------------------------------
# 유니온 파인드를 학습하기 위해 다른 사람 코드를 따라 작성하고 디버깅함
# 출처 https://itholic.github.io/kata-1043/

import sys

cnt_party = int(sys.stdin.readline().rstrip().split()[1])
witness_set = set(sys.stdin.readline().rstrip().split()[1:])

party_list = []
possible_list = []

for _ in range(cnt_party):
    party_list.append(set(sys.stdin.readline().rstrip().split()[1:]))
    possible_list.append(1)

for _ in range(cnt_party):
    for i, party in enumerate(party_list):
        if witness_set.intersection(party):
            possible_list[i] = 0
            witness_set = witness_set.union(party)

print(sum(possible_list))