# 이차원 리스트 정렬할 때 방법 자꾸 까먹어서 만듦

list1 = []
a = [1, 2, 3]
b = [2, 3, 1]
c = [3, 1, 2]

list1.append(a)
list1.append(b)
list1.append(c)

print("오름차순")
list1.sort(key=lambda x: x[0])
print(list1)
list1.sort(key=lambda x: x[1])
print(list1)
list1.sort(key=lambda x: x[2])
print(list1)

print("내림차순")
list1.sort(key=lambda x: x[0], reverse=True)
print(list1)
list1.sort(key=lambda x: x[1], reverse=True)
print(list1)
list1.sort(key=lambda x: x[2], reverse=True)
print(list1)