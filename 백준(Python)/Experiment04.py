# --------------------------------------
# 변수의 유효 범위
# --------------------------------------
# C언어처럼 생각하면서 파이썬 쓰다가 문득 이게 될까 싶어서 해봤는데 정상 작동해서 찾아본 부분
# 정리 : 파이썬 범수의 scope는 innermost function, class, module 이라고 함, 근데 if 나 while은 여기에 count되지 않는다고 한다
# 참조 : https://stackoverflow.com/questions/2829528/whats-the-scope-of-a-variable-initialized-in-an-if-statement

# C에서 저렇게 짜면 컴파일 안됨
# #include <stdio.h>
# int main()
# # {
#     int A = 100;
#     if (A == 100)
#         int B = 100;
    
#     printf("%d\n", B);
# }

A = 100

if A == 100:
    B = 100

print(B)