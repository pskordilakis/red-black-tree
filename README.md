RED-BLACK TREE DATA STRUCTURE
=============================

Written as part of the Algorithms and Data Structures course course for my MSc.

INFO
----
Red black tree is a search-tree scheme of binary tree. Some properties are
defined that must always hold, thus giving as a balanced binary tree and
ensure O(log n) worst case time.

PROPERTIES OF RED-BLACK TREE
----------------------------
A red-black tree is a binary tree with one extra bit of info in every node, its
color. A color of a node can take one of two possible values RED or BLACK.

At every given time the following properties must be satisfied :

1. Every node is either red or black.

2. The root is black.

3. Every leaf(NIL) is black.

4. If a node is red, then both its children are black

5. For each node, all simple paths from the node to descendant leaves contain
the same number of black nodes

CODE
----

cmake build tool is used to build the project. Red-black tree is build as a
shared object library(.so), but it's not a generic data structure. The library
is composed of several header and source files, so only some of the functions
are exposed to the user, e.g. insert, search, delete. Functions that are used
in the implementation of the data structure but are not meant to be used by the
user are not exposed.