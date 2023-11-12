# CodeDaily
- Single source Shortest path.
- Work if all costs/weights are positive.
- Lecture Link
  https://youtu.be/F3PNsWE6_hM?si=gXfLjWaDtgP7fnli
-  Problem Solved
  https://leetcode.com/problems/network-delay-time/submissions/1096535492/
- The Dijkstra Algorithm is almost like breadth-first search and depth-first search. Put the source node in the priority queue instead of the queue. Then pop it and explore its child. If the cost of the child is reduced using this node then push that child into the priority queue with reduced cost. On the next iteration pop the child who has minimum distance.
