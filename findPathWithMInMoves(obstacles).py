import copy         
def findPath(matrix,m,n,pr,pc,r,c,moves,gr,gc):
    matrix[r][c]='X'
    matrix_copy = copy.deepcopy(matrix)
  
    x1=x2=x3=x4=10000
    if r==gr and c==gc:
        return moves
    if c+1<n and not(matrix[r][c+1]=='X'):
        if  r!=pr :
            x1= findPath(matrix_copy,m,n,r,c,r,c+1,moves+1,gr,gc)
        elif c+1==n-1 and c+1==gc and r==gr:
            x1=findPath(matrix,m,n,r,c+1,r,c+1,moves,gr,gc)
        elif c+1==n-1:
            x1=findPath(matrix_copy,m,n,r,c+1,r,c+1,moves+1,gr,gc)
        else:
            x1=findPath(matrix_copy,m,n,pr,pc,r,c+1,moves,gr,gc)
    if r+1<m and not(matrix[r+1][c]=='X'):
        if  c!=pc :
            x2=findPath(matrix_copy,m,n,r,c,r+1,c,moves+1,gr,gc)
        elif r+1==m-1 and r+1==gr  and c==gc:
            x2=findPath(matrix_copy,m,n,r+1,c,r+1,c,moves,gr,gc)
        elif r+1==m-1:
            x2=findPath(matrix_copy,m,n,r+1,c,r+1,c,moves+1,gr,gc)
        else:
            x2=findPath(matrix_copy,m,n,pr,pc,r+1,c,moves,gr,gc)
    if r-1>=0 and not(matrix[r-1][c]=='X'):
        if  c!=pc :
            x3=findPath(matrix,m,n,r,c,r-1,c,moves+1,gr,gc)
        elif r-1==0 and r-1==gr and c==gc:
            x3=findPath(matrix_copy,m,n,r-1,c,r-1,c,moves,gr,gc)
        elif r-1==0 :
            x3=findPath(matrix_copy,m,n,r-1,c,r-1,c,moves+1,gr,gc)
        else:
            x3=findPath(matrix_copy,m,n,pr,pc,r-1,c,moves,gr,gc)    
    if c-1>=0 and not(matrix[r][c-1]=='X'):
        if  r!=pr :
            x4=findPath(matrix_copy,m,n,r,c,r,c-1,moves+1,gr,gc)
        elif c-1==0 and c-1==gc and r==gr:
            x4=findPath(matrix_copy,m,n,r,c-1,r,c-1,moves,gr,gc)
        elif c-1==0:
            x4=findPath(matrix_copy,m,n,r,c-1,r,c-1,moves+1,gr,gc)
        else:
            x4=findPath(matrix_copy,m,n,pr,pc,r,c-1,moves,gr,gc)
    
    return min(x1,x2,x3,x4)

# arr=[
#     ['.','X','.','.'],
#     ['.','X','.','X'],
#     ['.','.','.','.'],
#     ['.','.','X','X']
#     ]
# arr=[
#     ['.','X','X','.'],
#     ['.','X','X','.'],
#     ['.','X',',','.'],
#     ['.','.','.','X']
#     ]
# m=3
# arr=[
#     ['.','X','.'],
#     ['.','X','.'],
#     ['.','.','.']
    
#     ]
m=4
n=6
r=0
c=5
gr=3
gc=0


arr=[
    ['X','X','X','X','X','.'],
    ['X','X','X','.','.','.'],
    ['.','.','.','.','x','.'],
    ['.','.','.','.','.','.'],
    ]

# arr=[]
# m=int(input())
# r=int(input())
# c=int(input())
# gr=int(input())
# gc=int(input())
# for i in range(m):
#     row=[]
#     for j in range(m):
#         v=input()
#         row.append(v) 
#     arr.append(row)
if r==gr and c==gc:
    print(0)
else:
    print(findPath(arr,m,n,r,c,r,c,1,gr,gc))
           