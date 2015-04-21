/*
 * redblackree.c
 *
 *  Created on: Dec 25, 2010
 *      Author: P. Skordilakis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <malloc.h>
#include "redblacktree.h"

#define BLACK 1
#define RED 2

/*
 * This functions are not necessary for the tree to work
 * properly but for our convinience
 */

/*
 * Check if a red black tree is empty
 */
bool is_rbtree_empty(RBTREE *T) {
	if(T->root == T->nil) {
		return true;
	}
	return false;
}

/*
 * Check if a node is the root of
 * a red black tree
 */
bool is_rbtnode_root(RBTREE *T, RBNODE *x) {
	if (x->p == T->nil) {
		return true;
	}
	return false;
}

/*
 * Constructor of a red black tree node
 */
RBNODE *init_rbnode(int key) {
	RBNODE *node = malloc(sizeof(RBNODE));
	node->key = key;
	node->p = node->left = node->right = NULL;
	return node;
}

/*
 * Constructor of the red black tree node T.nil
 */
RBNODE *init_nil() {
	RBNODE *nil = malloc(sizeof(RBNODE));
	nil->key = 0;
	nil->color = BLACK;
	nil->p = nil->left = nil->right = NULL;
	return nil;
}

/*
 * Constructor of a red black tree
 */
RBTREE *init_rbtree() {
	RBTREE *T = malloc(sizeof(RBTREE));
	T->nil = init_nil();
	T->root = T->nil;
	return T;
}

/*
 * Destractor of a red black tree node
 */
void destr_rbtree_node(RBTREE *T, int key) {
	RBNODE *delNode = rbtree_search(T, T->root, key);
	rbtree_delete(T, delNode);
	free(delNode);
}

/*
 * Destractor of a red black tree
 */
void destr_rbtree(RBTREE *T) {
	while(not is_rbtree_empty(T)) {
		destr_rbtree_node(T, T->root->key);
	}
	free(T);
}
/*
 * functions tha are part of the algorithm
 */

/*
 * Print in order the nodes of a red black tree
 */
void inorder_rbtree_walk(RBTREE *T, RBNODE *x) {
	if(x not_eq T->nil) {
		inorder_rbtree_walk(T, x->left);
		printf("%d-", x->key);
		inorder_rbtree_walk(T, x->right);
	}
}

/*
 * Print preorder the nodes of a red black tree
 */
void preorder_rbtree_walk(RBTREE *T, RBNODE *x) {
	if(x not_eq T->nil) {
		printf("%d-", x->key);
		preorder_rbtree_walk(T, x->left);
		preorder_rbtree_walk(T, x->right);
	}
}

/*
 * Print post order the nodes of a red black tree
 */
void postorder_rbtree_walk(RBTREE *T, RBNODE *x) {
	if(x not_eq T->nil) {
		postorder_rbtree_walk(T, x->left);
		postorder_rbtree_walk(T, x->right);
		printf("%d-", x->key);
	}
}

/*
 * Search a tree(T) for a specific node(key)
 * starting from x(in most cases T->root).
 * Recursive
 */
RBNODE *rbtree_search(RBTREE *T, RBNODE *x, int key) {
	if(x == T->nil or key == x->key) {
		return x;
	}
	if(key < x->key) {
		return rbtree_search(T, x->left, key);
	}
	return rbtree_search(T, x->right, key);
}

/*
 * Search a tree(T) for a specific node(key)
 * starting from x(in most cases T->root).
 * Iterative
 */
RBNODE *iterative_rbtree_search(RBTREE *T, RBNODE *x, int key) {
	while(x not_eq T->nil and key not_eq x->key) {
		if(key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

/*
 * Find the minimum node of a red black tree(T)
 * starting from a node(x).
 * The result is not allways the minimum
 * node of the tree
 */
RBNODE *rbtree_minimum(RBTREE *T, RBNODE *x) {
	while(x->left not_eq T->nil) {
		x = x->left;
	}
	return x;
}

/*
 * Find the maximum node of a red black tree(T)
 * starting from a node(x).
 * The result is not allways the maximum
 * node of the tree
 */
RBNODE *rbtree_maximum(RBTREE *T, RBNODE *x) {
	while(x->right not_eq T->nil) {
		x = x->right;
	}
	return x;
}

/*
 * Find a node that can replace another node(x)
 * before it is deleted from tha tree(T)
 */
RBNODE *rbtree_successor(RBTREE *T, RBNODE *x) {
	if(x->right not_eq T->nil) {
		return rbtree_minimum(T, x->right);
	}

	RBNODE *y = x->p;

	while(y not_eq T->nil and x == y->right) {
		x = y;
		y = y->p;
	}

	return y;
}

/*
 * Left rotation of a node(x)
 * in a red black tree
 */
void rbtree_left_rotate(RBTREE *T, RBNODE *x) {
	RBNODE *y = x->right;
	x->right = y->left;
	if(y->left not_eq T->nil) {
		y->left->p = x;
	}
	y->p = x->p;
	if(x->p == T->nil) {
		T->root = y;
	}
	else if(x == x->p->left) {
		x->p->left = y;
	}
	else {
		x->p->right = y;
	}
	y->left = x;
	x->p = y;
}

/*
 *Right rotation of a node(y)
 *in a red black tree(T)
 */
void rbtree_right_rotate(RBTREE *T, RBNODE *y) {
	RBNODE *x = y->left;
	y->left = x->right;
	if(x->right not_eq T->nil) {
		x->right->p = y;
	}
	x->p = y->p;
	if(y->p == T->nil) {
		T->root = x;
	}
	else if(y == y->p->right) {
		y->p->right = x;
	}
	else{
		y->p->left = y;
	}
	x->right = y;
	y->p = x;
}

/*
 * Funtion to preserve the red black properties
 * of a tree(T) after the insertion of a node
 */
void rbtree_insert_fixup(RBTREE *T, RBNODE *z) {
	RBNODE *y;
	while(z->p->color == RED) {
		if(z->p == z->p->p->left) {
			y = z->p->p->right;
			if(y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if(z == z->p->right) {
					z = z->p;
					rbtree_left_rotate(T, z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rbtree_right_rotate(T, z->p->p);
			}
		}
		else {
			y = z->p->p->left;
			if(y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if(z == z->p->left) {
					z = z->p;
					rbtree_right_rotate(T, z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rbtree_left_rotate(T, z->p->p);
			}
		}
	}
	T->root->color = BLACK;
}

/*
 * Insert a node in a red black tree
 */
void rbtree_insert(RBTREE *T, RBNODE *z) {
	RBNODE *y = T->nil;
	RBNODE *x = T->root;
	while(x not_eq T->nil) {//Find the node that will be parent of z
		y = x;
		if(z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->p = y;
	if(y == T->nil) {//If y == T.nil the tree is empty and z becomes root
		T->root = z;
	}
	else if(z->key < y->key) {//If key of z is smaller than key of y then z becomes left child of y
		y->left = z;
	}
	else {//If key of z is bigger than key of y then z becomes right child of y
		y->right = z;
	}
	z->left = T->nil;
	z->right = T->nil;
	z->color = RED;//Make z red
	rbtree_insert_fixup(T, z);//Call insert fixup to fix the tree if any of the red black properties are violeted
}

/*
 * Move a sub tree(parent node v)
 * in the place o a node(u)
 * in a red black tree
 */
void rbtree_transplant(RBTREE *T, RBNODE *u, RBNODE *v) {
	if(u->p == T->nil) {
		T->root = v;
	}
	else if(u == u->p->left)	{
		u->p->left = v;
	}
	else {
		u->p->right = v;
	}
	v->p = u->p;
}

/*
 * Funtion to preserve the red black properties
 * of a tree(T) after the deletion of a node
 */
void rbtree_delete_fixup(RBTREE *T, RBNODE *x) {
	RBNODE *w;
	while(x not_eq T->root and x->color == BLACK) {
		if(x == x->p->left) {
			w = x->p->right;
			if(w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				rbtree_left_rotate(T, x->p);
				w = x->p->right;
			}
			if(w->left->color == BLACK and w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if(w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rbtree_right_rotate(T, w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				rbtree_left_rotate(T, x->p);
				x = T->root;
			}
		}
		else {
			w = x->p->left;
			if(w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				rbtree_right_rotate(T, x->p);
				w = x->p->left;
			}
			if(w->right->color == BLACK and w->left->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if(w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					rbtree_left_rotate(T, w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				rbtree_right_rotate(T, x->p);
				x = T->root;
			}
		}
	}
	x->color = BLACK;
}

/*
 * Deletion of a node(z) in
 * a red black tree
 */
void rbtree_delete(RBTREE *T, RBNODE *z) {
	RBNODE *x, *y = z;
	int y_original_color = y->color;
	if(z->left == T->nil) {
		x = z->right;
		rbtree_transplant(T, z, z->right);
	}
	else if(z->right == T->nil) {
		x = z->left;
		rbtree_transplant(T, z, z->left);
	}
	else {
		y_original_color = y->color;
		x = y->right;
		if(y->p == z) {
			x->p = y;
		}
		else {
			rbtree_transplant(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		rbtree_transplant(T, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}
	if(y_original_color == BLACK) {
		rbtree_delete_fixup(T, x);
	}
}
