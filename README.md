# Jhonson's Algorithm
- Combination of Bellman-Ford and Dijkstra Algorithm
- Lecture Link
  - https://youtu.be/MV7EAD9zL64?si=ubhhLOKUNrrV6ksk
  - https://www.youtube.com/watch?v=x5hm5dPv1Ig
- Step 1:
  -
  - Add extra source vertex in the graph. Connect every Vertex with this new vertex with 0 weight. We are adding the virtual source vertex because if we use any other vertex as the source vertex then it might be possible that we do not reach any vertex through this source vertex.
- Step 2 and 3:
  - 
  - Apply Bellman-Ford's algo and update the cost of reaching vertices. As in Bellman-Ford, we are dealing with edges, not vertexes. If we run Bellman-Ford one time we can update all the vertices connected to negative edges.
  - So when we run the Dijkstra Algorithm, there are possibilities we will skip the negative edge but if we skip we do not need to worry because we have already found the shortest path to that vertex through Bellman-Ford. If we will find any path shorter than this then we will update the vertices otherwise not.

