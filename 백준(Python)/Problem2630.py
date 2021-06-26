# --------------------------------------
# 색종이 만들기
# --------------------------------------

import sys

paper = []
blue = 0
white = 0


def paper_split(row, col, size):

    global white, blue

    same_color = True
    cut_size = size // 2
    for i in range(cut_size):
        for j in range(cut_size):
            if paper[row][col] == paper[row + i][col + j] and \
               paper[row + i][col + j] == paper[row + i][col + cut_size + j] and \
               paper[row + i][col + j] == paper[row + cut_size + i][col + j] and \
               paper[row + i][col + j] == paper[row + cut_size + i][col + cut_size + j]: continue
            else:
                same_color = False
                break
        
        if not same_color:
            break
    
    if same_color:
        if paper[row][col] == 0:
            white += 1
        else:
            blue += 1
    
    else:
        paper_split(row, col, cut_size)
        paper_split(row + cut_size, col, cut_size)
        paper_split(row, col + cut_size, cut_size)
        paper_split(row + cut_size, col + cut_size, cut_size)

N = int(sys.stdin.readline())
for _ in range(N):
    paper.append(list(map(int, sys.stdin.readline().split())))

paper_split(0, 0, N)

print(white)
print(blue)
