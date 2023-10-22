def fib(n):
    dp = [-1] * (n + 1)

    def helper(n):
        if n <= 1:
            return n
        if dp[n - 1] == -1:
            dp[n - 1] = helper(n - 1)
        if dp[n - 2] == -1:
            dp[n - 2] = helper(n - 2)
        dp[n]=dp[n-1]+dp[n-2]
        return dp[n - 1] + dp[n - 2]

    return helper(n)

# Example usage:
n = 10
result = fib(n)
print(result)
