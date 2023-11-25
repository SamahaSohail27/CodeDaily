# Bellman Ford Algorithm
- Single Source Shortest Path Algorithm
- Dijisktra does not work on negative cycle
- If after n-1 cycles our answer is sill changing means our graph contains negative cycle
- Lecture Link
  https://youtu.be/0sxWUPYFX1s?si=bSsaSQdAwtUU6fzS
- You have to relax every edge in Bellman Ford v(no of vetices)-1 times.
- Bellman-Ford and Dijkstra are both algorithms used to find the shortest paths in a graph, but they differ in their approach. Dijkstra's algorithm, starting from a source node, greedily selects the closest unvisited node at each step, updating the distances accordingly. It works well with non-negative edge weights and is more efficient in such cases. On the other hand, Bellman-Ford can handle graphs with negative edge weights but is less efficient. It iteratively relaxes all edges in each iteration, potentially discovering shorter paths.

- To illustrate, imagine a road network where cities are connected by highways, and the distance between cities represents the edge weights. If all highways have positive lengths, Dijkstra's algorithm is like planning the shortest route by always choosing the nearest city at each step. Bellman-Ford, however, could handle situations where some highways have tolls (negative weights) and others don't, exploring different routes to find the most cost-effective path despite the tolls.
