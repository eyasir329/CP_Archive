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
        - container copy time O(n)

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

- struct vs class

```cpp
#include <iostream>
using namespace std;

// Using struct
struct Point {
    double x;
    double y;

    void display() const {
        cout << "Point(" << x << ", " << y << ")\n";
    }
};

// Using class
class Circle {
private:
    double radius;
    Point center;

public:
    Circle(double r, double cx, double cy) : radius(r), center{cx, cy} {}

    void display() const {
        cout << "Circle with radius " << radius << " at ";
        center.display();
    }
};

int main() {
    Point p1{3.5, 4.5};
    p1.display(); // Access is public by default in struct

    Circle c1(5.0, 2.0, 2.0);
    c1.display(); // Access is controlled by public methods in class

    return 0;
}

```

- operator overloading

```cpp
pair<int,int> operator + (const pair<int,int>a, const pair<int,int>b){
        return make_pair(a.first+b.first,a.second+b.second);
}
int main(){
        pair<int,int> a = {2,3};
        pair<int,int> b = {5,3};
        pair<int,int> c = a+b;
        return 0;
}
```

- others

        - boolalpha
                cout<<boolalpha<<a<<" "<<b<<endl;(a,b condidion)

        - sizeof
                cout<<sizeof(int)<<endl;(4 bytes)//special type size_t(64bit uint)
                n = sizeof(a)/sizeof(a[0]);//sizeof(a)/size_of(int)

        - size()-1
                //infinite loop(not actually)//segmentation fault
                size_t n = v.size();//every container size has type size_t
                // if don't exist any size()
                unsigned int -> 0-1 -> 2^64-1 (circular)(-1 don't exist in unsigned int range)
                solution -> (int)v.size()-1; (convert to int)

---

### Auto/Pair/Tuple

- auto is used for type interface, must be initialize with value.

```cpp
    pair<int,double>p;
    tie(a,b) = p;
    p = make_pair(a,a/5);//{a.a/5}
    cout<<p.first<<" "p.second<<endl;

    tuple<int, int, int>t = {1, 2, 3};//tuple can have more than 2 elements
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
    //p = {{4, 5}, 6};
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
 // index 2 to upto 2 char
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
- can't be m.erase(m.end()) in any container
- int cnt = m.count(x)//O(logN+K)
- if not find() any then return m.end() -> so check every time//but don't matter in value
</pre>

---

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

### Policy Based Data Structure

---

### List/Linked List

<pre>
- default list is doubly linked list
</pre>

---

### STL Array

- c_type array(not stl array) pass by referrence by default.
- pass by value need more time than pass by reference

---

### Bitset

<pre>
- bitset fixed at compile time
- must have constant size, complexity O(N/64)
- bitset<8>bs(88);//also convert binary string -> bs("0010101")
- i can randomly choose bit left to right LSB->MSB(bs[0-7]->O(1)) like array
- bs.set() -> all value 1//bs.set(index)
- bs.reset() -> all value 0//bs.reset(index);
- bs.flip()-> 0-1, 1-0//bs.flip(index)
- bs.count()-> number of 1
- bs.size();
- bs.to_ullong();//with in range of ull
- bs.to_string();
- bs.any()-> check at least one
- bs.none()-> all bit 0 or not
- bs.all()-> all bit 1 or not

binary operation on bitset 
- (bs1 | bs2) //and & ^ all operation
</pre>

---

### Others

- Standard Algorithms

![algo](https://hackingcpp.com/cpp/std/algorithms_crop.png)

- Lambda Expressions
<pre>
- [&] capture all variable by refference
- [=] capture all variable by value
- [a,&b] capture a by value, b byb refference
</pre>

![Lambda Expressions](https://hackingcpp.com/cpp/lang/lambdas_crop.png)

- Custom Comparator
<pre>
- weak ordering (a>=b) (in C++ '=' always return false)
- so don't use it('=') in comparator function
</pre>

```cpp
sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    return a.second>b.second;
});
```

example:

- [632C_The Smallest String Concatenation](./2_string/632C_The%20Smallest%20String%20Concatenation.cpp)

    <pre>We have to sort all string by lexicographical order.
  
    (a < b), (b < c) -> (a < c)</pre>
