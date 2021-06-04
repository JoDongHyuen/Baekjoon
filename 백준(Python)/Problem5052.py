# --------------------------------------
# 전화번호 목록
# --------------------------------------

class Node(object):
    def __init__(self, key):
        self.key = key
        self.children = {}

class Tire(object):
    def __init__(self):
        self.head = Node(None)

    def Insert(self, string):
        curr_node = self.head
        
        check = 0
        for char in string:
            
            if not char in curr_node.children:
                curr_node.children[char] = Node(char)
                check = 1
            
            curr_node = curr_node.children[char]
        
        return check


Test_Case = int(input())

for _ in range(Test_Case):
    Number_Num = int(input())
    List = Tire()
    result = 0

    for i in range(Number_Num):
        str = input()
        check = List.Insert(str)
        if check == 0:
            result = 1
    
    if result == 0:
        print("YES")
    else:
        print("NO")
    