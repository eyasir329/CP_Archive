### Set

<pre>
bool cmp(int x,int y){
        return x>y;
}
- set< int,decltype(&cmp)>s(cmp);//reversee order

- unique and sorted
all operation in logn
- s.insert(x);
- s.erase(s.find(x));  // s.erase(velue);//both valid
- int cnt = s.count(x);
- can't find index like vector because it's use bidirectional iterator

- auto it = s.lower_bound(x);(*it>=x)(first encounder which value at least x)
- auto it = s.upper_bound(x);(*it>x)(which value strictly > x)
- if not exist then (lower_bound==upper_bound)
- only increase or decrease by one (except next(),prev()) 

- lower_bound(s.begin(),s.end()) -> work but O(N), s.lower_bound(x) -> O(logN), same as upper_bound 

- set < int>se(v.begin(),v.end())//vector input in set
</pre>

- std::set<KeyType,Compare>

![set cheatmap](https://hackingcpp.com/cpp/std/set_crop.png)
https://www.spoj.com/problems/ADAFIELD/en/

---

### Unordered Set

<pre>
- don't care order but unique
</pre>

- std::unordered_set<KeyType,Hash,KeyEqual>

![unordered set](https://hackingcpp.com/cpp/std/unordered_set_crop.png)

---

### Multiset

<pre>
- sorted but not unique
- m.erase(m.find(a));//remove first occurrance -> O(logN)
- m.erase(a);//remove all occurrences of a -> O(logN+K)
- erase not work in for-each loop

- can't be m.erase(m.end()) in any container
- int cnt = m.count(x)//O(logN+K)
- if not find() any then return m.end() -> so check every time//but don't matter in value
</pre>
