# -------------------------------------
# 제로
# -------------------------------------

Cog = []

Test_Case = int(input())

for i in range(Test_Case):
    num = int(input())
    if num == 0:
        Cog.pop()
    else:
        Cog.append(num)
        
print(sum(Cog))