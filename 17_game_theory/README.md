### Chess

<pre>
- 8*8 board -> place 8 rook that doesnot attack each other? (8!)
- 8*8 board -> place 5 rook that doesnot attack each other? 
  => C(8,5)*(8*7*6*5*4) = C(8,5)*P(8,5) = C(8,5)*C(8,5)*5!

- 
</pre>

example:

- https://lightoj.com/problem/rooks
- [cses1072_Two Knights]()

  <pre>
  Your task is to count for k=1,2,...,n the number of ways two knights can be placed on a k * k chessboard so that they do not attack each other.
  
  total no. of ways two knight can place - no. of ways they can place(attack) 
  C(n*n, 2) - (how much 2x3 or 3x2 exist)*2
  </pre>

- [1957C. How Does the Rook Move?](1957C_How_Does_the_Rook_Move.cpp)
  <pre>
  We are given an n x n chessboard where a player and a computer alternately place rooks (white and black respectively) under the constraint that no two rooks attack each other (i.e., no two rooks share the same row or column). The player starts first, and each move by the player at (r, c) is mirrored by the computer at (c, r), unless r == c, in which case the computer skips its turn.
  
  After k initial moves (which are valid and already processed), we need to determine the number of possible final configurations of the board when the game is played to completion (i.e., no more valid moves are left). The answer should be computed modulo 1e9+7
  </pre>

---

### Card

example:

- [spoj_HC12_Card_Game](spoj_HC12_Card_Game.cpp)

  <pre>
  The game's rules are as follows: There is deck of N cards from which each person is dealt a hand of K cards. Each card has an integer value representing its strength. A hand's strength is determined by the value of the highest card in the hand. The person with the strongest hand wins the round. Bets are placed before each player reveals the strength of their hand.
  
  John needs your help to decide when to bet. He decides he wants to bet when the strength of his hand is higher than the average hand strength. Hence John wants to calculate the average strength of ALL possible sets of hands.
  
  You are given an array a with N ≤ 10 000 different integer numbers and a number, K, where 1 ≤ K ≤ N. For all possible subsets of a of size K find the sum of their maximal elements modulo 1 000 000 007.
  
  total subset 2^n-1
  fixed_length_subset nCr
  fixed_value_subset = *C(n-1,k-1) like
  </pre>

### Nim

- https://codeforces.com/problemset/problem/1382/B

---

### Others

- https://codeforces.com/problemset/problem/1627/B

### 🧩 Problem Statement

You're given an `n × m` classroom grid. Two students, **Tina** and **Rahul**, make moves in the following order:

1. **Tina** uses exactly `k` buckets of pink paint to paint `k` different seats.
2. **Rahul** chooses an **unpainted** seat to sit in.
3. **Tina** then chooses a **different** seat (can be painted) to sit in.

- Rahul wants to sit **as close as possible** to Tina.
- Tina wants to sit **as far as possible** from Rahul.

Your task is to compute, for all `k = 0` to `n·m−1`, the **minimum possible distance** Rahul can get to Tina if both play **optimally**.

---

To solve **this kind of problem** — where two players act **strategically** in a grid or space with competing goals — you need to master a **topic cluster** involving:

---

## 🎯 Core Topics to Learn

| Topic                                   | Why It's Relevant                                                             |
| --------------------------------------- | ----------------------------------------------------------------------------- |
| **Game Theory (2-player optimal play)** | Models interactions where players make sequential, opposing decisions.        |
| **Greedy Algorithms**                   | Helps simulate "optimal" choices when players act selfishly.                  |
| **Distance Geometry**                   | Often used when positions and distances matter (like Manhattan or Euclidean). |
| **Sorting and Preprocessing**           | Allows you to precompute optimal cell choices efficiently.                    |
| **Minimax Strategy**                    | Classic in 2-player games: One minimizes a value, the other maximizes it.     |
| **Simulation on Grids**                 | Fundamental to handle seating plans, movement, coloring, etc.                 |

---

## 🧠 How to Approach These Problems

### 1. **Understand Player Goals**

Ask:

- Who plays first?
- What does each player want to **optimize** (maximize/minimize)?
- Are there any **restrictions** (e.g., painted cells)?

### 2. **Model the Grid**

- Is it a 1D line, 2D grid, or graph?
- Use coordinates `(i, j)` for grid cells.
- Use a suitable distance function (Manhattan, Euclidean, etc).

### 3. **Extract the Core Metric**

In this problem:

- The key metric is: **distance between Rahul and Tina**
- Precompute how far each seat is from "important places" (e.g., corners)

### 4. **Preprocess or Sort Efficiently**

When choices depend on "best or worst seats":

- Precompute metrics (distances, values, scores)
- Sort them to simulate removing best seats

### 5. **Simulate Optimal Strategy**

Use sorted data to model:

- What happens if player A blocks top-k best options?
- What’s the best counterplay by player B?

This is **min-max**:

- Rahul: _minimize_ distance
- Tina: _maximize_ distance
- So simulate like: `min ( max(...possible responses...) )`

---

## 🧩 Other Examples of This Pattern

- **[Codeforces 1285D - Dr. Evil Underscores](https://codeforces.com/problemset/problem/1285/D)**
  ⇒ Minimize XOR when opponent picks worst-case value.

- **[Leetcode 286 - Walls and Gates](https://leetcode.com/problems/walls-and-gates/)**
  ⇒ BFS distance from multiple sources in a grid.

- **Chess-like games (e.g., knights, kings)**
  ⇒ Move strategically to maximize or minimize opponent’s options.

---

## 📚 What to Study (with Topics & Practice)

| Topic                              | Resources                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------- |
| 🔁 **Minimax / Game Theory**       | [CP Algorithms – Game Theory](https://cp-algorithms.com/game_theory/basic.html) |
| 🧮 **Manhattan Distance**          | Any geometry textbook or Khan Academy                                           |
| 📐 **Grid Problems & BFS**         | [Leetcode Grid Tag](https://leetcode.com/tag/grid/)                             |
| 🔀 **Greedy + Sorting**            | [A2OJ Greedy Sheet](https://a2oj.com/ladder?ID=15)                              |
| 📊 **2D Preprocessing Techniques** | Prefix sums, distance maps, center-extreme cell computations                    |

---

## 🔑 Takeaway

To solve **strategic 2-player grid problems**, combine:

- **Game theory logic** (who moves when, optimal choice)
- **Grid modeling** (how to represent space and measure distance)
- **Sorting / Greedy** (to simulate blocking, removing options)
- **Min-Max or Max-Min** thinking (one player blocks the other’s best moves)

---

## Sudoku

- https://codeforces.com/problemset/problem/1335/D
