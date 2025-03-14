### Chess

example:

- [cses1072_Two Knights]()

  <pre>
  Your task is to count for k=1,2,...,n the number of ways two knights can be placed on a k * k chessboard so that they do not attack each other.
  
  total no. of ways two knight can place - no. of ways they can place(attack) 
  C(n*n, 2) - (how much 2x3 or 3x2 exist)*2
  </pre>

- https://codeforces.com/problemset/problem/1957/C

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
