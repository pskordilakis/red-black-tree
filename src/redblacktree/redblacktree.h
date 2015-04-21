/*
 * redblacktree.h
 *
 *  Created on: Dec 25, 2010
 *      Author: P. Skordilakis
 */

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "rbtree.h"
#include "rbnode.h"
#include "utils.h"

void rbt_to_dotfile(RBTREE *T);
bool rbt_is_empty(RBTREE *T);
bool rbt_is_root(RBTREE *T, RBNODE *x);

RBNODE *rbt_init_node(int key);
void rbt_destroy_node(RBTREE *T, int key);

RBTREE *rbt_init(void);
void rbt_destroy(RBTREE *T);

RBNODE *rbt_search(RBTREE *T, RBNODE *x, int key);
void rbt_inorder(RBTREE *T, RBNODE *x);
void rbt_preorder(RBTREE *T, RBNODE *x);
void rbt_postorder(RBTREE *T, RBNODE *x);

void rbt_insert(RBTREE *T, RBNODE *z);
void rbt_delete(RBTREE *T, RBNODE *z);

#ifdef	__cplusplus
}
#endif

#endif /* REDBLACKTREE_H */
