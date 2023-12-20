# Task 1: 
Write a method printSquares that has an integer parameter n, and prints the squares of the integers from 1 to n, separated by commas. It should print the squares of the odd integers in descending order first and then following with the squares of the even integers in ascending order. It does not print a newline character.
For example, printSquares(4) should print 9, 1, 4, 16 printSquares(1) should print 1 printSquares(7) should print 49, 25, 9, 1, 4, 16, 36
You may NOT use helper methods to solve this problem; write a single method.


# Task 2: 
You're standing at the base of a staircase and are heading to the top. A small stride will move up one stair, a large stride advances two. You want to count the number of ways to climb the entire staircase based on different combinations of large and small strides. For example, a staircase of three steps can be climbed in three different ways: via three small strides or one small stride followed by one large stride or one large followed by one small. A staircase of four steps can be climbed in five different ways (enumerating them is an exercise left to reader :-).
Write the recursive function int countWays(int numStairs) that takes a positive numStairs value and returns the number of different ways to climb a staircase of that height taking strides of one or two stairs at a time.
Here's a hint about the recursive structure of the problem: consider the options you have at each stair. You must either take a small stride or a large stride; either will take you closer to the goal and therefore represents a simpler instance of the same problem that can be handled recursively. What is the simplest possible situation and how is it handled?
int CountWays(int numStairs)
