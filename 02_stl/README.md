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

---

### Pair/Tuple

---

### Vector

---

### String

---

### Multidimentional Arrays and Strings

example:

- 2033B_Sakurako and Water

---

### Stack

---

### Queue

---

### Deque

---

### Priority Queue/Heap

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

---

### Bitset

---

### Others
