## Standard Template librery (STL)

### Basics

- pointers

        - memory address of variable x -> &x

        - pointer variable-> int* ptr(used to store memory address) like, ptr = &n;
        (dereference operator *) used to access a value that stored at the memory location pointed by a pointer.
        - *ptr -> value(value of stored address)
        - update that value -> *ptr = num
        - null pointers -> int *ptr = nullptr..or..NULL ->ptr = 0

        - ith element in array -> x+4*(i-1) ...(x initial address),
        accessing any element in O(1)-> ptr+(i-1)
                                        a+(i-1) //in array
        - *ptr = *ptr+2 //value of ptr+2 replace in that original ptr value

- references (call by value & call by reference)

        - int x=5; int y = x; (x and y have differenct address)
        - int x=5; int &y = x; (x and y have same address and value)
        (int &y; y = x;->wrong approach)
        y+=5 -> x=10
        - call by reference is most faster than call by value
        - in cpp array is pass by reference by default (array always work in pointer), we can't pass array by value.

- iterators

        - iterators are used to access and traverse the elements of a container (act like a pointer)
        - vector<int>::iterator it = v.begin();// auto it = v.begin();//(it - container specific)
        - *it (output value shown)
        - it++;(it = next(it)) it--;(it = prev(it)) it+=x;(it = next(it,x)) it-=x;(it = prev(it,x))
        - begin()-> pointing to first element, end()-> pointing to last+1 element
        - it = v.end(); it--; (*it)->last element

        - r.begin()->last element , r.end()->first - 1
        - vector<int>::reverse_iterator it = v.rbegin();
        - normal - , reverse +

        - v.end()-v.begin() -> n//index
        - range = distance(v.begin()+2,v.begin()+5);//(2,3,5)//end-of-range iterator q points one behind
        - after changing in container - previous all declare iterator is invalid//we have to declare new

        - random iterator(vector, deque, array, string)//it+=x; it-=x;
        - bidirectional iterator(list, set, map)//it+=1; it-=1;
        - forward iterator(forward_list, unordered_set, unordered_map)//it+=1

        - accesing vector of pair-> (*it).first

---

### Auto/Pair/Tuple

- auto is used for type interface, must be initialize with value.

```cpp
    pair<int,double>p;
    tie(a,b) = p;
    p = make_pair(a,a/5);//{a.a/5}
    cout<<p.first<<" "p.second<<endl;

    tuple<int, int, int>t = {1, 2, 3};
    auto [a, b, c] = t;//c++17* //structured binding
    cout << a << " " << b << " " << c << endl;
    t = make_tuple(a,b,c);
    cout<<get<0>(t)<<get<1>t<<get<2>t<<endl;
    get<0>(get<2>t)// last to first
    int x,y,z;
    tie(x,y,z) = t;// if already declare x,y,z

    pair<int,int>points[10]//array of points
    pair<pair<int, int>, int>p;
    p = make_pair(make_pair(1, 2), 3);
    p = {{4, 5}, 6};
    cout << p.first.first << " " << p.first.second << " " << p.second << endl;
```

---

### Vector

```cpp
//some functions in vector
v.clear()->O(N)
v.assign(10,1) //upto 10th element assign by 1
v.sort(v.begin()+1,v.end()-1)//{8, 1, 2, 3, 1}//right exclusive
v.insert(v.begin()+i,x);//immediade pos go to next
v.erase(v.begin()+i);//next go this pos
// range always right exclusive
reverse(range) or sort(v.rbegin(),v.rend());

swap(u,v) or u.swap(v)//swap two vectors element
auto it = find(v.begin(),v.end(),x);//first occurance
if(it==v.end())//not occur x
index = it - v.begin();
auto it = find(v.rbegin(),v.rend(),x);//last occurance
if(it==v.rend())//not occur x

count(v.begin(),v.end(),x);
accumulate(v.begin(),v.end(),0LL);//0LL initial sum
*min_element(v.begin(),v.end());
*max_element(v.begin(),v.end());

partial_sum(v.begin(),v.end(),pre.begin());

```

<code>right exclusive -> (v.begin(),v.end())</code>
<br>

- std::vector< ValueType >

## ![vector_cheetsheet](https://hackingcpp.com/cpp/std/vector_crop.png)

### String

```cpp
 string sub = s.substr(2,2);//char of index 2-3 [cautions its not range like]
 int pos = s.find("kk");//first occurance -> O(N*N)
 int pos = s.rfind('1');//last occurance -> O(N)
 if(pos==string::npos)//not found (-1)
 else //found at pos (starting index)
 s.replace(11,5,"abcde");
 s.append("abc");
 s.compare("abc");
 std::getline(std::cin, str);//line input

 s+='a';//O(1)
 s = s+'a';//O(N)
 //works in both index based and iterator based
 s.insert();
 s.erase();

 string s = string(c_string);
 char c_string[] = s.c_str();
```

- std::string Interface & Utilities Overview

## ![string cheatsheet](https://hackingcpp.com/cpp/std/string_crop.png)

### Multidimentional Arrays and Strings

example:

- 2033B_Sakurako and Water

---

### Stack (LIFO)

<pre>
- empty() -> Test whether container is empty (public member function)
- size() -> Return size (public member function)
- top() -> Access next element (public member function)
- push() -> Insert element (public member function)
- emplace() -> Construct and insert element (public member function)
- pop() -> Remove top element (public member function)
- swap() -> Swap contents (public member function)
</pre>

---

### Queue (FIFO)

<pre>
- empty(): Checks if the queue is empty.
- size(): Returns the number of elements in the queue.
- push(): Adds an element to the back of the queue.
- front(): Accesses the front element.
- **back(): Accesses the back element.
- pop(): Removes the front element.
- swap(): Exchanges the contents of two queues.
</pre>

---

### Deque

<pre>
empty(): Checks if the deque is empty.
push_back(): Adds an element to the end.

**push_front(): Adds an element to the front.

size(): Returns the number of elements.
front(): Accesses the front element.
back(): Accesses the back element.
pop_back(): Removes the back element.

**pop_front(): Removes the front element.

emplace_back(): Constructs and inserts an element at the back.
emplace_front(): Constructs and inserts an element at the front.
insert(): Inserts an element at a specific position.
erase(): Removes an element at a specific position.
swap(): Exchanges the contents with another deque.
clear(): Removes all elements.

- access any index[]
- vector is more memory efficient than deque
</pre>

- std::deque< ValueType >

![deque cheatsheet](https://hackingcpp.com/cpp/std/deque_crop.png)

---

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

---

### Set

---

### Unordered Set

---

### Multiset

#### Erase in multiset

    m.erase(m.find(a));

---

### Map

---

### Unordered Map/HashTable/HashMap

---

### Policy Based Data Structure

---

### List/Linked List

---

### STL Array

- cpp array pass by referrence by default.
- pass by value need more time than pass by reference

---

### Bitset

---

### Others

- Standard Algorithms
  ![algo](https://hackingcpp.com/cpp/std/algorithms_crop.png)
