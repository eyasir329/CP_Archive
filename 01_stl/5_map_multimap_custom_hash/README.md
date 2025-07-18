### Map

<pre>
- key, value pair (key must be unique)
- map always sorted by key
- access random using key (O(logN))->m[key]->value;
- auto it = m.find(key); (have if it!=m.end())
- m.erase(it);//m.erase(key);
</pre>

- std::map<KeyType,MappedType,KeyCompare>

## ![map](https://hackingcpp.com/cpp/std/map_crop.png)

https://codeforces.com/problemset/problem/920/B

### Unordered Map/HashTable/HashMap

<pre>
- isn't sort using key. 
- accessing in average case O(1) worst case O(N) -> but in map always O(logN) 
</pre>

```cpp
//if key is int or ll //otherwise not work custom hash
//https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
```

- std::unordered_map<KeyType,MappedType,Hash,KeyEqual>

![unordered map](https://hackingcpp.com/cpp/std/unordered_map_crop.png)

---

### Multimap

---
