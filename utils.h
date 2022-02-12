#ifndef BT_UTILS_H_
#define BT_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode BTNode;
struct BTNode {
	int key;
	BTNode *left;
	BTNode *right;
};

typedef struct Node Node;
struct Node {
	void *data;
	Node *next;
};

typedef enum {
	PREORDER,
	INORDER,
	POSTORDER
} traverse_type;

BTNode *add_btnode(int);
void bfs(BTNode *); //breath first search
void dfs(BTNode *, traverse_type); //depth first search
void insert(BTNode **, int);
BTNode *search(BTNode *, int);
void release_tree(BTNode *);
void enqueue(Node **, void *);
Node *dequeue(Node **);

#endif // BT_UTILS_H_