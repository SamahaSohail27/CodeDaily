from collections import defaultdict
MAX_INT = float('Inf')
def minDistance(dist, visited):
    (minimum, minVertex) = (MAX_INT, 0)
    for vertex in range(len(dist)):
        if minimum > dist[vertex] and not visited[vertex]:
            (minimum, minVertex) = (dist[vertex], vertex)
    return minVertex

def Dijkstra(graph, modifiedGraph, src):
    num_vertices = len(graph)
    sptSet = defaultdict(lambda: False)
    dist = [MAX_INT] * num_vertices
    dist[src] = 0

    for count in range(num_vertices):
        curVertex = minDistance(dist, sptSet)
        sptSet[curVertex] = True

        for vertex in range(num_vertices):
            if (not sptSet[vertex] and
                    dist[vertex] > (dist[curVertex] +
                                    modifiedGraph[curVertex][vertex]) and
                    (graph[curVertex][vertex] != 0)):
                dist[vertex] = (dist[curVertex] +
                                modifiedGraph[curVertex][vertex])

    for vertex in range(num_vertices):
        print('Vertex ' + str(vertex) + ': ' + str(dist[vertex]))

def BellmanFord(edges, num_vertices):
    dist = [MAX_INT] * (num_vertices + 1)
    dist[num_vertices] = 0
   ## Add edges from the virtual source to every other vertex
    for i in range(num_vertices):
        edges.append([num_vertices, i, 0])

    for i in range(num_vertices):
        for (src, des, weight) in edges:
            if (dist[src] != MAX_INT and  dist[src] + weight < dist[des]):
                dist[des] = dist[src] + weight

    return dist[0:num_vertices]

def JohnsonAlgorithm(edges, num_vertices):
    modifyWeights = BellmanFord(edges, num_vertices)

    modifiedGraph = [[0 for x in range(num_vertices)] for y in range(num_vertices)]

    for src, des, weight in edges:
        modifiedGraph[src][des] = (weight + modifyWeights[src] - modifyWeights[des])

    print('Modified Graph: ' + str(modifiedGraph))

    for src in range(num_vertices):
        print('\nShortest Distance with vertex ' +
              str(src) + ' as the source:\n')
        Dijkstra(graph, modifiedGraph, src)

# Example input for edges
edges = [
    [0, 1, -5],
    [0, 2, 2],
    [0, 3, 3],
    [1, 2, 4],
    [2, 3, 1]
]

# Example number of vertices
num_vertices = 4

JohnsonAlgorithm(edges, num_vertices)
