# --------------------------------------
# 프린터 큐
# --------------------------------------

Test_Case = int(input())

for i in range(Test_Case):
    N, Target_pos = map(int, input().split())
    queue = list(map(int, input().split()))
    Importance = [0 for x in range(10)]

    for j in range(N):
        Importance[queue[j]] += 1
    
    count = 0
    
    while(queue):
        if queue[0] == 9:
            Importance[queue[0]] -= 1
            queue.pop(0)
            count += 1

            if Target_pos == 0:
                print(count)
                break
            else:
                Target_pos -= 1
        
        elif sum(Importance[(queue[0] + 1):]) == 0:
            Importance[queue[0]] -= 1
            queue.pop(0)
            count += 1

            if Target_pos == 0:
                print(count)
                break
            else:
                Target_pos -= 1
        
        else:
            queue.append(queue.pop(0))

            if Target_pos == 0:
                Target_pos = len(queue) - 1
                
            else:
                Target_pos -= 1
