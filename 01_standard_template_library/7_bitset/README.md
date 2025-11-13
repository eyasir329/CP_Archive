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
