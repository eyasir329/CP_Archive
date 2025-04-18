---
title: "14 ds tree range queries"
nav_order: 1
---


https://medium.com/basecs/a-gentle-introduction-to-graph-theory-77969829ead8
https://darrenyao.com/usacobook/cpp.pdf#page=41

<pre>
- Tree is a subset of graphs.
- tree need at least one root node in order to be considered a “tree”

Trees, start with a root node, and might connect to other nodes, which means that could contain subtrees within them. Trees are defined by a certain set of rules: one root node may or may not connect to others, but ultimately, it all stems (ডালপালা) from one specific place. Some trees have even more specific rules, like binary search trees, which can only ever have two links to two nodes at any given time. 

- A tree can also only have one-way connections — a child node can only have one parent, and a tree can’t have any loops, or cyclical (চক্রাকার) links.

- A tree is an <b>undirected graph</b> in which any <i>"two vertices are connected by only one path"</i>. A tree is an <b>acyclic graph</b> and has N - 1 edges where N is the number of vertices. Each node in a graph may have one or multiple parent nodes. However, in a tree, each node (except the root node) comprises exactly <b>one parent node</b>.

Note: A root node has no parent.

A tree cannot contain any cycles or self loops, however, the same does not apply to graphs. 
</pre>

<code>Trees are nothing more than restricted types of graphs, just with many more rules to follow . A tree will always be a graph, but not all graphs will be trees.</code>

<img src="https://miro.medium.com/v2/resize:fit:1100/format:webp/1*rguQ2Y2Z920IYGkO0cHHtQ.jpeg" alt="tree_vs_graph" height="300">

<pre>
- A tree is a connected graph that consists of n nodes and n − 1 edges. There is a unique path between any two nodes of a tree.
</pre>
