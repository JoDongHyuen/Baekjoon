# -------------------------------------
# 친구 네트워크
# --------------------------------------



Test_Case = int(input())

def Find(x, Parent):
    if x == Parent[x]["parent"]:
        return x
    else:
        Parent[x]["parent"] = Find(Parent[x]["parent"], Parent)
        return Parent[x]["parent"]

def Union(x, y, Parent):
    x = Find(x, Parent)
    y = Find(y , Parent)

    if x == y:
        return Parent[x]["Friend"]

    if (x < y):
        Parent[y]["parent"] = x
        Parent[x]["Friend"] += Parent[y]["Friend"]
        return Parent[x]["Friend"]
    else:
        Parent[x]["parent"] = y
        Parent[y]["Friend"] += Parent[x]["Friend"]
        return Parent[y]["Friend"]

for _ in range(Test_Case):
    Table = {}
    index = 0

    Net_Num = int(input())
    Parent = [{"parent" : x, "Friend" : 1} for x in range(Net_Num * 2)]

    for __ in range(Net_Num):
        Human1, Human2 = input().split()

        if not Human1 in Table:
            Table[Human1] = index
            index += 1
        
        if not Human2 in Table:
            Table[Human2] = index
            index += 1
        

        print(Union(Table[Human1], Table[Human2], Parent))

