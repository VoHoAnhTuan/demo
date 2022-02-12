#include "utils.h"

void test_bfs(){
	printf("** test bfs **\n");
	BTNode *root = NULL;
	//create Binary Tree
	insert(&root, 5);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 1);
	insert(&root, 8);
	insert(&root, 7);
	insert(&root, 15);
	
	bfs(root);


}

void test_dfs(){
	printf("** test_dfs() **\n");
	// Create Binary Tree
	BTNode *root = NULL;

	insert(&root, 10);
	insert(&root, 8);
	insert(&root, 4);
	insert(&root, 13);
	insert(&root, 1);
	insert(&root, 21);

	printf("PREORDER\n");
	dfs(root, PREORDER);
	printf("INORDER\n");
	dfs(root, INORDER);
	printf("POSTORDER\n");
	dfs(root, POSTORDER);

	release_tree(root);
}

int main(){
	test_dfs();
	test_bfs();
	return 0;
}
