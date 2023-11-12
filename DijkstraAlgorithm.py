import heapq
def dijkstra():
    while priority_queue:
        node = heapq.heappop(priority_queue)
        weight , current_node = node
        if current_node-1 not in visited:
            path.append(current_node)
            visited.append(current_node-1)
            for item in graph[current_node - 1]:
                child_weight,child_node = item
                if cost[current_node - 1] + child_weight < cost[child_node - 1]:
                    cost[child_node - 1] = cost[current_node - 1] + child_weight
                    heapq.heappush(priority_queue, [cost[child_node - 1], child_node])  # Fix the item pushed to the priority queue

# Graph representation
graph = [
    [[2, 2], [4, 3]],
    [[2, 1], [1, 3], [7, 4]],
    [[4, 1], [1, 2], [2, 4]],
    [[7, 2], [2, 3]]
]

# Sample input for Dijkstra's algorithm
source_vertex = 1
path = []
visited = []
priority_queue = []
heapq.heappush(priority_queue, [0, source_vertex])
cost = [float('inf')] * 4
cost[source_vertex - 1] = 0
dijkstra()
print(path)
print(cost)
