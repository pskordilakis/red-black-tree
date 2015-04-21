/*
 * redblacktree.h
 *
 *  Created on: Dec 25, 2010
 *      Author: P. Skordilakis
 */

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <malloc.h>

#include "rbnode.h"
#include "utils.h"

typedef struct rbtree {
	RBNODE *root, *nil;
}RBTREE;

void rbt_to_dotfile(RBTREE *T);
bool rbt_is_empty(RBTREE *T);
bool rbt_is_root(RBTREE *T, RBNODE *x);

RBNODE *rbt_init_node(int key);
void rbt_destroy_node(RBTREE *T, int key);

RBNODE *rbt_init_nil(void);
RBTREE *rbt_init(void);
void rbt_destroy(RBTREE *T);

RBNODE *rbt_search(RBTREE *T, RBNODE *x, int key);
void rbt_inorder(RBTREE *T, RBNODE *x);
void rbt_preorder(RBTREE *T, RBNODE *x);
void rbt_postorder(RBTREE *T, RBNODE *x);

RBNODE *rbt_minimum(RBTREE *T, RBNODE *x);
RBNODE *rbt_maximum(RBTREE *T, RBNODE *x);
RBNODE *rbt_successor(RBTREE *T, RBNODE *x);

void rbt_insert(RBTREE *T, RBNODE *z);
void rbt_delete(RBTREE *T, RBNODE *z);

#endif /* REDBLACKTREE_H_ */
