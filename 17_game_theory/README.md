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
