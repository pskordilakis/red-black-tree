/* 
 * File:   utils.h
 * Author: panos
 *
 * Created on April 21, 2015, 3:03 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>
    
#include "rbnode.h"

/**
 * Create tree node T.nil 
 * @return 
 */
RBNODE *rbt_init_nil(void);
    
/**
 * Left rotate operation of tree nodes
 * @param T
 * @param x
 */
void rbt_left_rotate(RBTREE *T, RBNODE *x);

/**
 * Right rotate operation of tree nodes
 * @param T
 * @param y
 */
void rbt_right_rotate(RBTREE *T, RBNODE *y);

/**
 * Insert fix-up operation restores red black tree properties in case they are
 * violated after an insert operation
 * @param T
 * @param z
 */
void rbt_insert_fixup(RBTREE *T, RBNODE *z);

/**
 * Find the minimum node of a red black tree(T)
 * starting from a node(x).
 * The result is not always the minimum
 * node of the tree
 * @param T
 * @param x
 * @return 
 */
RBNODE *rbt_minimum(RBTREE *T, RBNODE *x);

/**
 * Find the maximum node of a red black tree(T)
 * starting from a node(x).
 * The result is not always the maximum
 * node of the tree
 * @param T
 * @param x
 * @return 
 */
RBNODE *rbt_maximum(RBTREE *T, RBNODE *x);

/**
 * Find a node that can replace another node(x)
 * before it is deleted from that tree(T)
 * @param T
 * @param x
 * @return 
 */
RBNODE *rbt_successor(RBTREE *T, RBNODE *x);

/**
 * Transplant operation used in delete operations
 * @param T
 * @param u
 * @param v
 */
void rbt_transplant(RBTREE *T, RBNODE *u, RBNODE *v);

/**
 * Delete fixup operation restores red black tree properties in case they are
 * violated after an insert operation
 * @param T
 * @param x
 */
void rbt_delete_fixup(RBTREE *T, RBNODE *x);


#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

