# Designing Efficient Algorithms - Project #1
Solving Asymmetric Traveling Salesman Problem
This project explores the implementation of algorithms to solve the Asymmetric Traveling Salesman Problem (ATSP). The ATSP is a classic optimization problem where the objective is to find the most efficient route that visits a set of cities exactly once and returns to the starting city, with the added complexity of asymmetric distances between cities.

Implemented Algorithms:  

- **Brute Force**:  
The Brute Force algorithm exhaustively searches all possible permutations of cities to find the optimal solution. While not the most efficient for large datasets, it serves as a baseline for comparison. This algorithm employs Depth-First Search (DFS) as its core traversal strategy.
> Time complexity: O(n²)  
> Space complexity: O(n)

- **Dynamic Programming**:  
The Dynamic Programming approach optimally solves the ATSP by breaking down the problem into subproblems and memoizing the solutions. This algorithm is more efficient than Brute Force and is particularly useful for larger instances of the problem.
> Time complexity: O(n²·2ⁿ)   
> Space complexity: O(n·2ⁿ)
