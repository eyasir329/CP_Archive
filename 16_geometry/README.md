# Geometry

Online Graph Generator -> https://www.desmos.com/calculator

### Points

example:

- https://www.codechef.com/CFUS2020/problems/CFS2005

  <pre>
  You are given a grid with dimension n x m and two points with coordinates X(x1,y1) and Y(x2,y2) . Your task is to find the number of ways in which one can go from point A(0,0)to point B(n,m) using the shortest possible path such that the shortest path neither passes through X nor through Y.
  
  n!/(r1!*r2!)
  
  S(A ∪ B ∪ C) = S(A) + S(B) + S(C) − S(A ∩ B) − S(A ∩ C) − S(B ∩ C) + S(A ∩ B ∩ C)
  -> ans = S(A ∩ B ∩ C)
  </pre>

- [codechef_LTIME24_NWAYS](codechef_LTIME24_NWAYS.cpp)

  <pre>
  Devu has two sets of points. Set A contains points having X co-ordinate 0 and Y co-ordinates varying from 1 to N(both inclusive). Set B contains points having X co-ordinate K and Y co-ordinates varying from 1 to N(both inclusive). Both sets contains N number of integral points. He wants to calculate the sum of number of ways to going to the each point of set B from the each point of set A . 
  
  bruteforce->ans = ans + fact[y2 + x2 - y1 - x1] * ifact[x2 - x1] * ifact[y2 - y1];
  
  </pre>

---

### Lines

---

### Circles

- https://codeforces.com/contest/2074/problem/D

### Triangles

#### Non-Degenerate Triangle

https://codeforces.com/problemset/problem/2053/A

https://codeforces.com/problemset/problem/2009/D

#### Area

https://www.youtube.com/watch?v=y9zRZYnSf2Y&list=PLpRww_DKmkSYiodL6xsSQyzjhJ8VPtq1K&index=15
https://codeforces.com/problemset/problem/1620/B

---

### Trapezoids

#### Isosceles Trapezoids

https://codeforces.com/contest/2061/problem/B

https://www.youtube.com/watch?v=AlyWS8bG3kE

---

### Quadrilaterals
