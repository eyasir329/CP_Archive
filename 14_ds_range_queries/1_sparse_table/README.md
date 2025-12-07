- https://codeforces.com/problemset/problem/1602/B

![st](st1.png)

- idempotent operators -> sparse table
- sparse table work like prefix sum

## Sparse Table

- precalculation

![st](st2.png)

- query

![st](st3.png)

- [2^0, 2^1, 2^2....2^n].lowerbound(r-l+1), max(a,b)

![st](st4.png)

- first x, last x

![st](st5.png)

- only (gcd, lcm)-> O(logn), otherwise O(1) for answering each query

![st](st6.png)


ex.

![st](st7.png)

> only middles point don't have any bigger than first one


- limitations

![st](st8.png)
