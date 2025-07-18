### XOR Tricks

https://codeforces.com/contest/2048/problem/C

https://florian.github.io//xor-trick/

- a^a = 0

(xor of even number of same type = 0, otherwise(odd) only one have that type)

- a^0 = a
- a^b = 0 (a==b)

Don't matter order of operations.

- a^b^a = 0^b = b
- a^b = c => a = b^c (vise-versa)

- https://codeforces.com/problemset/problem/1547/D
<pre>
if we have a sequence of xor operations... we can remove pair of douplicate value.
</pre>

#### Duplicate number finding

<pre>
we have 1 to n all numbers and a extra one number<=n, we have to find that extra number.
</pre>

```
(1^2^3^....^n)^(xor of given all numbers) = extra one
```

#### Missing number finding

<pre>
we have 1 to n-1, we have to find missing number.
</pre>

```
(1^2^3^....^n)^(xor of given all numbers) = missing one
```

#### Prefix XOR (Subarray XOR)

[cses1650_Range Xor Queries](./3_xor_tricks/cses1650_Range%20Xor%20Queries.cpp)

<pre>
Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?

hint: same as prefix sum
</pre>

- https://codeforces.com/problemset/problem/2039/C1
* [Codeforces Blog – Maximum XOR Subarray](https://codeforces.com/blog/entry/123404)
---