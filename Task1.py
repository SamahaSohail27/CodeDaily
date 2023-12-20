def printSquares(n):
    #base case
    if n<1:
        return 
    if not(n%2==0):
        print(n*n,end=',')
        printSquares(n-2)
        if n==1:
            return
        print((n-1) * (n-1), end=',')
    
  
n=10 
if n%2==0:
    printSquares(n-1)
    print(n*n)
else:
   printSquares(n) 
