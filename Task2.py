def countWays(self, n):       
        s=n+1
        dp=[-1]*s       
        def funct(n):
            if n<=1:
                return 1
            if dp[n] == -1:
                dp[n]= funct(n-1)+funct(n-2)
            return dp[n]        
        return funct(n)
#4->5
#5->8
#8->34
#0->0
#6->13
#3->3
