/* 
 * File:   rbnode.h
 * Author: panos
 *
 * Created on April 21, 2015, 3:28 PM
 */

#ifndef RBNODE_H
#define	RBNODE_H

#ifdef	__cplusplus
extern "C" {
#endif

#define BLACK 1
#define RED 2
    
typedef struct rbnode {
	int key;
	int color;
	struct rbnode *p, *left, *right;
}RBNODE;

#ifdef	__cplusplus
}
#endif

#endif	/* RBNODE_H */

