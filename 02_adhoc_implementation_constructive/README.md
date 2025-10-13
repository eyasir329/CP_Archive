### Adhoc Problems

Adhoc problems **don't rely on specific algorithms or data structures**. They require creative, case-by-case solutions based on the problem description.

**Example**: Finding the second-largest number in a list.

example:

- [miaki-presents-kuet-iupc-onsite-2025_K-Beast]()

---

### Implementation Problems

These problems focus on **correctly implementing a sequence of steps or rules**, often based on real-world processes or detailed problem instructions.

**Example**: Simulating a traffic light system based on a set of predefined rules.

#### Implementation Tricks / Suggestion

```cpp
- use #define, auto  //to make code shorter and easier to read
- (long long) a*b <-> 1LL*a*b;
- use of function, to modularize code

- array<type,size> can be useful stl array
  vector<tuple<int,int,int,int,int>> <-> vector<array<int,5>>v;

- use lamda function//helpful in comparator and predicate function
- memset(), fill() <-> to initialize array

- unique element in vector
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end())/*first iterator that is not unique*/,v.end());

- sort in decending order
  sort(v.begin(),v.end(),greater<int>)//easier
  sort(v.rbegin(),v.rend());//easiest

- max/min of multiple value
  max({a,b,c,d,e});
- max/min in vector
  *max_element(), *min_element()
```

- https://codeforces.com/contest/1485/problem/B
- https://codeforces.com/contest/1556/problem/B

---

### Constructive Problems

Constructive problems require building a solution that satisfies a set of constraints. You develop the answer step by step rather than just determining if something is possible.

**Example**: Constructing a valid sequence of parentheses.

<pre>
- check careful about the constraints.
- mostly constructive problems have <b>multiple solutions</b>.
</pre>

- <b>Always Check for [first + last + in between] <- very important</b>

example:

- [1559C_Mocha and Hiking](./3_constructive/1559C_Mocha%20and%20Hiking.cpp)
  <pre>
  The city where Mocha lives in is called Zhijiang. There are n+1 villages and 2n−1 directed roads in this city.
  There are two kinds of roads:
  
      - n−1 roads are from village i to village i+1, for all 1≤i≤n−1
      - n roads can be described by a sequence a1,…,an. If ai=0, the i-th of these roads goes from village i to village n+1, otherwise it goes from village n+1 to village i, for all 1≤i≤n
  
  Mocha plans to go hiking with Taki this weekend. To avoid the trip being boring, they plan to go through every village exactly once. They can start and finish at any villages. Can you help them to draw up a plan?
  
  -> If a1=1, then the path [(n+1)→1→2→⋯→n] is valid.
  If an=0, then the path [1→2→⋯→n→(n+1)] is valid.
  Otherwise, since a1=0∧an=1, there must exists an integer i (1≤i< n) where ai=0∧ai+1=1, then the path [1→2→⋯→i→(n+1)→(i+1)→(i+2)→⋯n] is valid.
  
  This is a step to prove that there always exists an <b>Hamiltonian path</b> in a tournament graph.
  </pre>

- https://codeforces.com/problemset/problem/1523/B
- https://codeforces.com/problemset/problem/1455/C
<pre>
firstly, maximize their number of wins and, secondly, minimize the number of wins of their opponent.
</pre>

---

## Bruteforces

> sometimes problems look like bruteforces can't happened -> but it happened...

- https://codeforces.com/contest/1604/problem/C