# Cycle Detection
- We can use simple DFS . Mark the visited nodes. If during DFS we came accross the visited node again it means Cycle exist.
- The main point is we are also coming from parent and parent is also child neighbour.
-  When we will traverse Child neighbours then we will also traverse parent and mark it as cycle .
-  This is wrong , going back to parent is not a cycle. So we will keep track of parent node.
-  So if we get visited node again bu it is parent we will not makr it as cycle.
-  Lecture Link:
   https://youtu.be/zBbRgLpeZus?si=IpMS-sh-J8D22CND
