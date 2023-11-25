def bellman_ford(edges, num_vertices, src):
    # Step 1: Initialize distances from source to all other vertices as INFINITY
    dist = [float("inf")] * num_vertices
    dist[src] = 0

    # Step 2: Relax all edges |V| - 1 times
    for _ in range(num_vertices - 1):
        for u, v, w in edges:
            if dist[u] != float("inf") and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    # Step 3: Check for negative-weight cycles
    for u, v, w in edges:
        if dist[u] != float("inf") and dist[u] + w < dist[v]:
            print("Graph contains negative weight cycle")
            return

    # Print the distances
    print_solution(dist)


def print_solution(dist):
    print("Vertex \t Distance from Source")
    for i, d in enumerate(dist):
        print(f"{i}\t\t{d}")


# Example Usage
if __name__ == "__main__":
    # Define edges as (u, v, w), where u and v are vertices, and w is the weight of the edge
    edges = [
        (0, 1, -1),
        (0, 2, 4),
        (1, 2, 3),
        (1, 3, 2),
        (1, 4, 2),
        (3, 2, 5),
        (3, 1, 1),
        (4, 3, -3),
    ]

    # Number of vertices
    num_vertices = 5

    # Run the Bellman-Ford algorithm from source vertex 0
    bellman_ford(edges, num_vertices, 0)
