## Recursion, Backtracking, Memoizations and Basic DP

### Recursion

- 1+2+3+4...n //O(N)

      int sum(int n){
        if(n==0)return 0;//base case
        return sum(n-1)+n;
      }

- n!

      int factorial(int n){
        if(n==0)return 1;
        return factorial(n-1)*n;
      }

- fibonacci

      int fibonacci(int n){
        if(n==0)return 0;
        if(n==1)return 1;
        return fibonacci(n-1)+fibonacci(n-2);
      }

Visualizer Tool

- [recursion tree](https://recursion.vercel.app/)
- [recursion stck](https://www.cs.usfca.edu/~galles/visualization/RecFact.html)

Time Complexity in Recursion

    the number of nodes in the recursion tree.
    (time complexity in each node * number of nodes)

Space complexity = (maximum dept \* each node )

#

#### Notices:

- a stack overflow occurs when the call stack exceeds it's maximum capacity. -Runtime Error/Segmentation Fault

- if it make cycle, then recursion will never end.<br>
  ex. f(n) = f(n-1)+f(n+1)

#

### Memoization / DP

O(2^N)->O(N)

called only number of unique state.

- Power of two

  <pre>
    vector< int> memo(100,-1);
    int power_of_two(int n){
      if(n==0)return 1;
      if(memo[n]!=-1)return memo[n];
      memo[n]=power_of_two(n-1)+power_of_two(n-1);
      return memo[n];
    }
  </pre>

### BackTracking

#### Genereting all subsequence

```
int n,a[20];
bool isTaken[20];
void recursion(int pos){
    if(pos>n){
        for(int i=1;i<=n;i++){
            if (isTaken[i]){
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    isTaken[pos] = false;//not take
    recursion(pos+1);
    isTaken[pos]=true;//take
    recursion(pos+1);
}
recursion(1);
```

    a[3] = {1,2,3}
    {},{3},{2},{2,3},{1},{1,3},{1,2},{1,2,3}

<pre>
                                  {}
                                 /   \
                        Not Pick 1   Pick 1
                             /            \
                           {}             {1}
                         /    \         /     \
              Not Pick 2  Pick 2      Not Pick 2  Pick 2
                  /          \          /          \
               {}          {2}         {1}        {1, 2}
             /   \        /    \      /   \        /      \
  Not Pick 3  Pick 3  Not Pick 3 Pick 3    Not Pick 3 Pick 3 Not Pick 3  Pick 3
        /         \      /          \         /        \         /            \
      {}        {3}     {2}      {2, 3}      {1}   {1, 3}  {1, 2}   {1, 2, 3}

</pre>
