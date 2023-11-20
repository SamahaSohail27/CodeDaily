# Connected Components
- To find connected components start applying DFS on 0 node.
- Then mark all nodes visited connected to it. Then apply DFS on node 2 .
- If it is already visited then we will      not apply DFS on this node and move forward.
- Whenever we will find any non-visited node then increment the count and apply DFS on it.
- So the number of times DFS will run will be the number on connected components

