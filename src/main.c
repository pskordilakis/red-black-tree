/*
 * main.c
 *
 *  Created on: Dec 25, 2010
 *      Author: P. Skordilakis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include "redblacktree.h"

int main(int argc, char *argv[]) {

	RBTREE *T = init_rbtree();//Dhmiourgia Red Black Tree

	int choice = -1;

	while(choice not_eq 0) {
		puts("1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n0. Exit");
		scanf("%d", &choice);
		getchar();
		switch(choice) {
			case 1 : {
				int key;
				puts("Type key");
				scanf("%d", &key);
				getchar();
				RBNODE *newNode = init_rbnode(key);//Create a red black tree  node with specific key
				rbtree_insert(T, newNode);//Insert the node into red black tree
				break;
			}
			case 2 : {
				//Delete a red black tree node with specific key
				int key;
				puts("Type key");
				scanf("%d", &key);
				getchar();
				destr_rbtree_node(T, key);
				break;
			}
			case 3 : {
				//Search a node in the red black tree
				int key;
				puts("Type key");
				scanf("%d", &key);
				getchar();
				RBNODE *searchNode = rbtree_search(T, T->root, key);
				if(searchNode == T->nil) {
					puts("The node does not exist");
				}
				else {
					printf("key : %d", searchNode->key);
					//if nodes contain other attributes, print them here
				}
				break;
			}
			case 4 : {
				inorder_rbtree_walk(T, T->root);//Print all the nodes in ascending order
				puts("");
				break;
			}
			case 5 : {
				preorder_rbtree_walk(T, T->root);//Print all the nodes preorder
				puts("");
				break;
			}
			case 6 : {
				postorder_rbtree_walk(T, T->root);//Print all the nodes postorder
				puts("");
				break;
			}
		}
	}
	destr_rbtree(T);
	return EXIT_SUCCESS;
}
