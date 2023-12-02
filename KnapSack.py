import heapq
def Knapsack(profit,weight,capacity,max_heap):
    maxProfit = 0
    while max_heap:
        x, i = heapq.heappop(max_heap)
        if capacity > 0 and weight[i] <= capacity:
            maxProfit = maxProfit + profit[i]
            capacity -= weight[i]
        else:
            if capacity > 0:
                maxProfit = maxProfit + (capacity * (profit[i] / weight[i]))
                break
    return maxProfit


capacity = 64
weight = [8, 16, 32, 40]
profit = [50, 100, 150, 200]
n = 4
max_heap = []
for i in range(n):
    heapq.heappush(max_heap, [-(float(profit[i]) / float(weight[i])), i])

result = Knapsack(profit,weight,capacity,max_heap)
print("Maximum Profit:", result)
