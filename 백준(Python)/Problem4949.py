# --------------------------------------
# 균형잡힌 세상
# --------------------------------------



while True:

    stack = []
    string = input()
    Check_Bal = 0

    if len(string) == 1 and string[0] == '.':
        break

    for i in range(len(string)):
        if string[i] == "(":
            stack.append("(")

        elif string[i] == ")":
            if len(stack) == 0:
                Check_Bal = 1
                break

            if stack.pop() !="(":
                Check_Bal = 1
                break

        elif string[i] == "[":
            stack.append("[")

        elif string[i] == "]":
            if len(stack) == 0:
                Check_Bal = 1
                break

            if stack.pop() != "[":
                Check_Bal = 1
                break
        Check_Bal = 2

    if Check_Bal == 2 and len(stack) == 0:
        print("yes")
    else:
        print("no")
    

