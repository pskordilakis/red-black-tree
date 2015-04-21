/*
 * redblackree.c
 *
 *  Created on: Dec 25, 2010
 *      Author: P. Skordilakis
 */

#include "redblacktree.h"

/*
 * This functions are not necessary for the tree to work
 * properly but for our convenience
 */

/*
 * Check if a red black tree is empty
 */
bool rbt_is_empty(RBTREE *T) {
	if(T->root == T->nil) {
		return true;
	}
	return false;
}

/*
 * Check if a node is the root of
 * a red black tree
 */
bool rbt_is_root(RBTREE *T, RBNODE *x) {
	if (x->p == T->nil) {
		return true;
	}
	return false;
}

/*
 * Constructor of a red black tree node
 */
RBNODE *rbt_init_node(int key) {
	RBNODE *node = malloc(sizeof(RBNODE));
	node->key = key;
	node->p = node->left = node->right = NULL;
	return node;
}

/*
 * Destructor of a red black tree node
 */
void rbt_destroy_node(RBTREE *T, int key) {
	RBNODE *delNode = rbt_search(T, T->root, key);
	rbt_delete(T, delNode);
	free(delNode);
}



/*
 * Constructor of a red black tree
 */
RBTREE *rbt_init(void) {
	RBTREE *T = malloc(sizeof(RBTREE));
	T->nil = rbt_init_nil();
	T->root = T->nil;
	return T;
}

/*
 * Destructor of a red black tree
 */
void rbt_destroy(RBTREE *T) {
	while(!rbt_is_empty(T)) {
		rbt_destroy_node(T, T->root->key);
	}
	free(T);
}
/*
 * functions that are part of the algorithm
 */

/*
 * Search a tree(T) for a specific node(key)
 * starting from x(in most cases T->root).
 * Recursive
 */
RBNODE *rbt_search(RBTREE *T, RBNODE *x, int key) {
	if(x == T->nil || key == x->key) {
		return x;
	}
	if(key < x->key) {
		return rbt_search(T, x->left, key);
	}
	return rbt_search(T, x->right, key);
}

/*
 * Print in-order the nodes of a red black tree
 */
void rbt_inorder(RBTREE *T, RBNODE *x) {
	if(x != T->nil) {
		rbt_inorder(T, x->left);
		printf("%d-", x->key);
		rbt_inorder(T, x->right);
	}
}

/*
 * Print pre-order the nodes of a red black tree
 */
void rbt_preorder(RBTREE *T, RBNODE *x) {
	if(x != T->nil) {
		printf("%d-", x->key);
		rbt_preorder(T, x->left);
		rbt_preorder(T, x->right);
	}
}

/*
 * Print post-order the nodes of a red black tree
 */
void rbt_postorder(RBTREE *T, RBNODE *x) {
	if(x != T->nil) {
		rbt_postorder(T, x->left);
		rbt_postorder(T, x->right);
		printf("%d-", x->key);
	}
}

/*
 * Insert a node in a red black tree
 */
void rbtree_insert(RBTREE *T, RBNODE *z) {
	RBNODE *y = T->nil;
	RBNODE *x = T->root;
	//Find the node that will be parent of z
        while(x != T->nil) {
		y = x;
		if(z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->p = y;
	if(y == T->nil) {
		T->root = z;      //If y == T.nil the tree is empty 
	}                         //and z becomes root
	else if(z->key < y->key) {//If key of z is smaller than key of y then
		y->left = z;      //z becomes left child of y
	}
	else {                   //If key of z is bigger than key of y 
		y->right = z;    //then z becomes right child of y
	}
	z->left = T->nil;
	z->right = T->nil;
	z->color = RED;          //Make z red
	rbt_insert_fixup(T, z);  //Call insert fix-up to fix the tree if any 
}                                //of the red black properties are violated

/*
 * Deletion of a node(z) in
 * a red black tree
 */
void rbt_delete(RBTREE *T, RBNODE *z) {
	RBNODE *x, *y = z;
	int y_original_color = y->color;
	if(z->left == T->nil) {
		x = z->right;
		rbt_transplant(T, z, z->right);
	}
	else if(z->right == T->nil) {
		x = z->left;
		rbt_transplant(T, z, z->left);
	}
	else {
		y_original_color = y->color;
		x = y->right;
		if(y->p == z) {
			x->p = y;
		}
		else {
			rbt_transplant(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		rbt_transplant(T, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}
	if(y_original_color == BLACK) {
		rbt_delete_fixup(T, x);
	}
}
