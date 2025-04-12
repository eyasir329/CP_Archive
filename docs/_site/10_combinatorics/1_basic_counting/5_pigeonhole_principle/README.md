### Pigeonhole Principle

<pre>
- Suppose a flock of pigeons fly into a set of pigeonholes to roost. If there are more pigeons than pigeonholes, then there must be at least 1 pigeonhole that has more than one pigeon in it.

- If k+1 or more objects are placed into k boxes, then there is at least one box containing two or more objects.
</pre>

- <u>Generalized Pigeonhole Principle</u>
<pre>
- If N objects are placed into k boxes, then there is at least one box containing ceil(N/k) objects.
</pre>

- <u>The Pigeonhole Proof</u>

![php1](https://i.ibb.co.com/kQKrd2w/IMG-0229.jpg)
![php2](https://i.ibb.co.com/T29Zmrt/IMG-0230.jpg)

example:
![pgh1](https://i.ibb.co.com/tqNtM3V/IMG-0226.jpg)

<pre>
A. Among 50 people, what is the number of people that must be born on the same month?
-> ceil(50/12) = 4.16... => 5 

B. How many students in a class must there be to ensure that 3 students get the same grade (one of A, B, C, D, or F)?
-> ceil(N/5) = 3 =>then consider, (N-1)/5 = 2(3-1) => N = 10+1 = 11 
</pre>

![pgh2](https://i.ibb.co.com/93nkw0t/IMG-0227.jpg)
![pgh3](https://i.ibb.co.com/ChcdKNj/IMG-0228.jpg)

---
