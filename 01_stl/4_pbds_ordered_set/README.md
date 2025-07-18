### Policy Based Data Structure
https://codeforces.com/problemset/problem/1566/D1

## https://codeforces.com/contest/2051/problem/D

### Ordered Set / PBDS

<pre>
- order_of_key (k) : Number of items strictly smaller than k .
- find_by_order(k) : K-th element in a set (counting from zero).
</pre>

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

//or
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

//for multiset
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
```
