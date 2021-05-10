# --------------------------------------
# 클레어와 물약
# -------------------------------------- 

portion_num, recipe_num = map(int, input().split())
dic = {}

for _ in range(recipe_num):
    recipe = list(map(int, input().split()))
    dic[recipe[-1]] = set(recipe[1:-1])


clare_know = input()
clare_portion = set(map(int, input().split()))

for _ in range(recipe_num):
    flag = 0
    
    for i, rec in list(dic.items()):
        if clare_portion.intersection(rec) == rec:
            clare_portion.add(i)
            del(dic[i])
            flag = 1

    if flag == 0:
        break

result = list(clare_portion)
print(len(result))
print(result)