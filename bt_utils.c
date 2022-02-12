#include "utils.h"

BTNode *add_btnode(int key){
	BTNode *node = calloc(1, sizeof(BTNode));
	node->key = key;
	return node;
}

void dfs(BTNode *root, traverse_type t){
	if (root == NULL){
		return;
	}

	if (t == PREORDER){
		printf("%d\n", root->key);
	}

	dfs(root->left, t);

	if (t == INORDER){
		printf("%d\n", root->key);
	}

	dfs(root->right, t);

	if (t == POSTORDER){
		printf("%d\n", root->key);
	}
}

void enqueue(Node **queue, void *data){
	if (*queue == NULL){
		*queue = calloc(1, sizeof(Node));
		(*queue)->data = data;

		return;
	}

	Node *temp = *queue;

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = calloc(1, sizeof(Node));
	temp->next->data = data;
}

Node *dequeue(Node **queue){
	Node *n = *queue;
	*queue = (*queue)->next;

	return n;
}

void bfs(BTNode *root){
	//We have some queue
	BTNode *temp = root;
	Node *queue = NULL;
	Node *n = NULL;

	enqueue(&queue, temp);
	//loop for as long as there are items in the queue
	while (queue != NULL){
		//dequeue item
		n = dequeue(&queue);
		temp = n->data;
		printf("%d\n", temp->key);
		//queue the left and righth children 
		if (templeft != NULL){
			enqueue(&queue, temp->left);
		}

		if (temp->right != NULL){
			enqueue(&queue, temp->right);
		}
		//release memory
		free(n);
	}

}

void insert(BTNode **root, int key){
	BTNode **temp = root;
	while (*temp != NULL){
		//Do we go to the right or the left subtree?
		if (key >= (*temp)->key){
			temp = &(*temp)->right;
		} else{
			temp = &(*temp)->left;
		}
	}

	*temp = add_btnode(key);
}

BTNode *search(BTNode *root, int key){
	
}

void release_tree(BTNode *root){
	if (root != NULL){
		release_tree(root->left);
		release_tree(root->right);
		free(root);
	}
	//release left
	//release right

}
