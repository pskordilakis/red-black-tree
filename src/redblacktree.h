/*
 * redblacktree.h
 *
 *  Created on: Dec 25, 2010
 *      Author: P. Skordilakis
 */

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

typedef struct rbnode {
	int key;
	int color;
	struct rbnode *p, *left, *right;
}RBNODE;

typedef struct rbtree {
	RBNODE *root, *nil;
}RBTREE;

void rbtree_to_dotfile(RBTREE *T);
bool is_rbtree_empty(RBTREE *T);
bool is_rbtnode_root(RBTREE *T, RBNODE *x);
RBNODE *init_rbnode(int key);
RBNODE *init_nil();
RBTREE *init_rbtree();
void destr_rbtree_node(RBTREE *T, int key);
void destr_rbtree(RBTREE *T);
void inorder_rbtree_walk(RBTREE *T, RBNODE *x);
void preorder_rbtree_walk(RBTREE *T, RBNODE *x);
void postorder_rbtree_walk(RBTREE *T, RBNODE *x);
RBNODE *rbtree_search(RBTREE *T, RBNODE *x, int key);
RBNODE *iterative_rbtree_search(RBTREE *T, RBNODE *x, int key);
RBNODE *rbtree_minimum(RBTREE *T, RBNODE *x);
RBNODE *rbtree_maximum(RBTREE *T, RBNODE *x);
RBNODE *rbtree_successor(RBTREE *T, RBNODE *x);
void rbtree_left_rotate(RBTREE *T, RBNODE *x);
void rbtree_right_rotate(RBTREE *T, RBNODE *y);
void rbtree_insert_fixup(RBTREE *T, RBNODE *z);
void rbtree_insert(RBTREE *T, RBNODE *z);
void rbtree_transplant(RBTREE *T, RBNODE *u, RBNODE *v);
void rbtree_delete_fixup(RBTREE *T, RBNODE *x);
void rbtree_delete(RBTREE *T, RBNODE *z);

#endif /* REDBLACKTREE_H_ */
