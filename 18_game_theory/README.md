
![g](gm1.png)

- majority -> combinatorial game
(no score or ponit)

- impartial -> every player can move every item

- setting -> intelligence player -> know all move (optimal play by every player)

![g](gm2.png)

## Strategy Define

- strategy define -> nothing to code... we have to understand that problem deeply... generally harder 

ex:
### Unlucky 13

> a player can keep 1,2 or 3 sticks at a time... who keep 13th stick will loose the game.  (2nd player is better -> it can enforce first play to optain 13th stick)

![g](gm3.png)

- in game theory -> always can have some mirroring
- in here 2nd player only reacting to first player move

#### Unlucky 14
> first player is best -> first player reduced to unlucky 13 

![g](gm4.png)

#### Unlucky 15
> first player is best also

#### Unlucky 16
> first player is best also

![g](gm5.png)
#### Unlucky 17
> 2nd player is best

---

- two main principle of a game theory

> 1. wining player reacts to losing player

> 2. Wining player enforces the game to a losing state


---
### Coin on a Table

> no coin overlap but can touch each other... who not place coin on a table will loose the game (first player is best)

![g](gm6.png)

> no reflextion on the center <br>
> wining player's react to losing player (first principle) after place one in the center
---

- 2 Queen (Alice and Bob who attack other queens wins)

![g](gm7.png)


---

## Game DP

- use when can't define strategy


ex.
> n pile of stone, A,B can choose P or Q stones (variable size) at a time (who can't move stones lose the game)

> analyze the game of a every no. of stone...<br>
> dp[n] => (for first palyer) losing portion -> n stone keep game is lose, winning portion -> n stone keep game is win

![g](gm8.png)
![g](gm9.png)

- subtraction game

![g](gm10.png)

- another game

![g](gm11.png)

```markdown
dp[A-x][B-x][C]
dp[A][B-y][C-y]
dp[A-z][B][C-z]
```
inteligently play... 

- random play (we have nothing to do)

![g](gm12.png)

- halving game

![g](gm13.png)

> bob is wining
---

## Nim

- any no. of stone from any pile

![g](gm14.png)

![g](gm15.png)
![g](gm16.png)
![g](gm17.png)

ex.

![g](gm18.png)

- if alice have xor of non zero -> he can reduce it to xor of zero
- bob reduce random in second step
- winner enforce to loser to zero state, then loser don't have to do anything
- reduce the highest number bit
- no change to increase

ex.
- https://codeforces.com/problemset/problem/1382/B

---

![g](gm19.png)

- nim variations

![g](gm20.png)
![g](gm21.png)
![g](gm22.png)

> normal nim upto all 1

![g](gm23.png)

- condition to win or loss

![g](gm24.png)

- wikipedia nim variations

---

## Grundy

- generalization of nim game

![g](gm25.png)
![g](gm26.png)

- any combinatorial impartial game can be converted to nim using grundy value

![g](gm27.png)
![g](gm28.png)
![g](gm29.png)
![g](gm30.png)
![g](gm31.png)
![g](gm32.png)
![g](gm33.png)

> sometimes grundy value can be find from pattern


ex.
- cses math nim game 1, 2, grundy'd game

---
## Partial Game

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
