/* 
 * File:   rbtree.h
 * Author: panos
 *
 * Created on April 21, 2015, 4:45 PM
 */

#ifndef RBTREE_H
#define	RBTREE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "rbnode.h"
    
typedef struct rbtree {
	RBNODE *root, *nil;
}RBTREE;


#ifdef	__cplusplus
}
#endif

#endif	/* RBTREE_H */

