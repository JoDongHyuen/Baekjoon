# --------------------------------------
# 저항
# --------------------------------------

standard = {"black": 0, "brown" : 1, "red": 2,
    "orange": 3, "yellow": 4, "green": 5,
    "blue": 6, "violet": 7, "grey": 8, "white": 9}
    

sum = 0

check = input()
sum = sum + standard[check] * 10

check = input()
sum = sum + standard[check]

check = input()
sum = sum * pow(10, standard[check])

print(sum)
