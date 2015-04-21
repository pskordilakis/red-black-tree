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

#include "rbnode.h"
    
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
 * Insert fixup operation restores red black tree properties in case they are
 * violated after an insert operation
 * @param T
 * @param z
 */
void rbt_insert_fixup(RBTREE *T, RBNODE *z);

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

