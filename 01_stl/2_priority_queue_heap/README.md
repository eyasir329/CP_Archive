### Priority Queue/Heap

<pre>
- priority_queue< int> pq; //default maxHeap//max at top//pop that max
- no way to access random or bottom element
- priority_queue< int, vector< int>, greater<int>> minHeap;//min at top

push(): Inserts an element. In a max-heap (default), the largest element has the highest priority; in a min-heap, the smallest element has the highest priority.
size(): Returns the number of elements in the priority queue.
top(): Accesses the top element, which is the largest (or smallest, if a min-heap) based on the heap type.
pop(): Removes the top element.
empty(): Checks if the priority queue is empty.
swap()
</pre>

```cpp
class Compare {
public:
    bool operator()(pair<int, int> below, pair<int, int> above)
    {
        auto [l1, r1] = below;
        auto [l2, r2] = above;
        return abs(l1 - r1) < abs(l2 - r2);
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
```

---
