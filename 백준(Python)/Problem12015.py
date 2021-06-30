# --------------------------------------
# 가장 긴 증가하는 부분 수열 2
# --------------------------------------

# deque 쓰니깐 시간 초과남..

def upper_bound(dp, num):
    start = 0
    end = len(dp) -1

    while start <= end:
        mid = (start + end) // 2

        if num > dp[mid]:
            start = mid + 1
        else:
            end = mid - 1
    
    return start

x = int(input())
arr = list(map(int, input().split()))
dp = []


for num in arr:
    if not dp:
        dp.append(num)
    else:
        pos = upper_bound(dp, num)
        if pos >= len(dp):
            dp.append(num)
        else:
            dp[pos] = num


print(len(dp))