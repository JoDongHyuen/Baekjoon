# --------------------------------------
# 전화번호 목록
# --------------------------------------

import sys

class Node(object):
    def __init__(self, key, valid):
        self.key = key
        self.valid = valid
        self.children = {}

class Tire(object):
    def __init__(self):
        self.head = Node(None, False)

    def Insert(self, string):
        curr_node = self.head
        
        check = 0
        for char in string:
            
            if not char in curr_node.children:
                curr_node.children[char] = Node(char, False)
                if check == 0:
                    check = 1
            
            curr_node = curr_node.children[char]
            
            if curr_node.valid == True:
                check = -1

        curr_node.valid = True

        return check


Test_Case = int(input())

for _ in range(Test_Case):
    Number_Num = int(input())
    List = Tire()
    result = True

    for i in range(Number_Num):
        #str = input()
        str = sys.stdin.readline().strip()
        check = List.Insert(str)
        if check != 1:
            result = False
    
    if result == True:
        print("YES")
    else:
        print("NO")