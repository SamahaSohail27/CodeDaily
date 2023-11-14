n = int(input())  # Number of vertices in the graph

# Check for the case when n=1
if n == 1:
    print(0)
else:
    # Rest of the code remains unchanged
    new_dis = [[0] * n for _ in range(n)]
    result = []
    dis = [[] for _ in range(n)]

    for i in range(n):
        lst = list(map(int, input().split()))
        for item in lst:
            dis[i].append(item)

    deleted_node = list(map(int, input().split()))
    deleted_node.reverse()
    current_nodes = []

    for k in deleted_node:
        k = k - 1
        current_nodes.append(k)

        for i in current_nodes:
            for j in current_nodes:
                new_dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])

        row_sums = [sum(new_dis[i]) for i in range(n)]
        Sum = sum(row_sums)
        result.append(Sum)

    result.reverse()

    for i in result:
        print(i)
