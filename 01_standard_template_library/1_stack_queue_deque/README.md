
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