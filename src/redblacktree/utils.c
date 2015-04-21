#include "utils.h"

/*
 * Constructor of the red black tree node T.nil
 */
RBNODE *rbt_init_nil(void) {
	RBNODE *nil = malloc(sizeof(RBNODE));
	nil->key = 0;
	nil->color = BLACK;
	nil->p = nil->left = nil->right = NULL;
	return nil;
}

/*
 * Left rotation of a node(x)
 * in a red black tree
 */
void rbt_left_rotate(RBTREE *T, RBNODE *x) {
	RBNODE *y = x->right;
	x->right = y->left;
	if(y->left != T->nil) {
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
void rbt_right_rotate(RBTREE *T, RBNODE *y) {
	RBNODE *x = y->left;
	y->left = x->right;
	if(x->right != T->nil) {
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
 * Function to preserve the red black properties
 * of a tree(T) after the insertion of a node
 */
void rbt_insert_fixup(RBTREE *T, RBNODE *z) {
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
					rbt_left_rotate(T, z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rbt_right_rotate(T, z->p->p);
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
					rbt_right_rotate(T, z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rbt_left_rotate(T, z->p->p);
			}
		}
	}
	T->root->color = BLACK;
}

/*
 * Find the minimum node of a red black tree(T)
 * starting from a node(x).
 * The result is not always the minimum
 * node of the tree
 */
RBNODE *rbt_minimum(RBTREE *T, RBNODE *x) {
	while(x->left != T->nil) {
		x = x->left;
	}
	return x;
}

/*
 * Find the maximum node of a red black tree(T)
 * starting from a node(x).
 * The result is not always the maximum
 * node of the tree
 */
RBNODE *rbt_maximum(RBTREE *T, RBNODE *x) {
	while(x->right != T->nil) {
		x = x->right;
	}
	return x;
}

/*
 * Find a node that can replace another node(x)
 * before it is deleted from that tree(T)
 */
RBNODE *rbt_successor(RBTREE *T, RBNODE *x) {
	if(x->right != T->nil) {
		return rbt_minimum(T, x->right);
	}

	RBNODE *y = x->p;

	while(y != T->nil && x == y->right) {
		x = y;
		y = y->p;
	}

	return y;
}

/*
 * Move a sub tree(parent node v)
 * in the place o a node(u)
 * in a red black tree
 */
void rbt_transplant(RBTREE *T, RBNODE *u, RBNODE *v) {
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
 * Function to preserve the red black properties
 * of a tree(T) after the deletion of a node
 */
void rbt_delete_fixup(RBTREE *T, RBNODE *x) {
	RBNODE *w;
	while(x != T->root && x->color == BLACK) {
		if(x == x->p->left) {
			w = x->p->right;
			if(w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				rbt_left_rotate(T, x->p);
				w = x->p->right;
			}
			if(w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if(w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rbt_right_rotate(T, w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				rbt_left_rotate(T, x->p);
				x = T->root;
			}
		}
		else {
			w = x->p->left;
			if(w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				rbt_right_rotate(T, x->p);
				w = x->p->left;
			}
			if(w->right->color == BLACK && w->left->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if(w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					rbt_left_rotate(T, w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				rbt_right_rotate(T, x->p);
				x = T->root;
			}
		}
	}
	x->color = BLACK;
}
