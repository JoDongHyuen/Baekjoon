# --------------------------------------
# 별 찍기 - 11
# --------------------------------------

from math import ceil
import sys

N = int(sys.stdin.readline())

star = [[" " for _ in range(N * 2)] for _ in range(N)]

def hew(x, y, length):
    if length == 3:
        star[x + 1][y] = "*"
        star[x - 1][y] = "*"
        star[x][y + 1] = "*"
        star[x][y - 1] = "*"
        star[x + 1][y - 2] = "*"
        star[x + 1][y - 1] = "*"
        star[x + 1][y + 1] = "*"
        star[x + 1][y + 2] = "*"
    else:
        side = length // 2
        up = ceil(side / 2)
        down = side // 2
        hew(x - up, y, length // 2)
        hew(x + down, y + side, length // 2)
        hew(x + down, y - side, length // 2)

hew(N // 2, N - 1, N)

for row in star:
    print("".join(row))


#                        *                        
#                       * *                       
#                      *****                      
#                     *     *                     
#                    * *   * *                    
#                   ***** *****                   
#                  *     !     *                  
#                 * *         * *                 
#                *****       *****                
#               *  !  *     *     *               
#              * *   * *   * *   * *              
#             ***** ***** ***** *****             
#            *           a           *            
#           * *                     * *           
#          *****                   *****          
#         *     *                 *     *         
#        * *   * *               * *   * *        
#       ***** *****             ***** *****       
#      *     a     *           *           *      
#     * *         * *         * *         * *     
#    *****       *****       *****       *****    
#   *     *     *     *     *     *     *     *   
#  * *   * *   * *   * *   * *   * *   * *   * *  
# ***** ***** ***** ***** ***** ***** ***** *****