## Some Problem Categories

### Adhoc Problems

Adhoc problems **don't rely on specific algorithms or data structures**. They require creative, case-by-case solutions based on the problem description.

**Example**: Finding the second-largest number in a list.

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

---

### Constructive Problems

Constructive problems require building a solution that satisfies a set of constraints. You develop the answer step by step rather than just determining if something is possible.

**Example**: Constructing a valid sequence of parentheses.

<pre>
- check careful about the constraints.
- mostly constructive problems have multiple solutions.
</pre>

---
