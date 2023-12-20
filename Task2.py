def countNumOfWays(current_stair,n):
    if current_stair==n:
        return 1
    if current_stair>n:
        return 0
    return countNumOfWays(current_stair+1,n)+countNumOfWays(current_stair+2,n)

print(countNumOfWays(0,8))
#4->5
#5->8
#8->34
#0->0
#6->13
#3->3
