#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	char *type;
	int hp;
	int ac;
	int speed;
} Creature;

typedef struct BTNode BTNode;
struct BTNode {
	Creature *creatures; //pointer arrays
	BTNode *left;
	BTNode *right;
};


typedef enum {
	PREORDER,
	INORDER,
	POSTORDER
} traverse_dfs_type;


BTNode *add_btnode(Creature *creature) {
    BTNode *node = calloc(1, sizeof(BTNode));
    node->creatures = creature;
    return node;
}

// int i = 0;

void insert(BTNode **root, Creature *creature) {
    BTNode **temp = root;
    while (*temp != NULL) {
        // Do we go to the right subtree or left subtree?
        if ((creature->ac) >= ((*temp)->creatures->ac)){ //indirection before dereference 
            temp = &(*temp)->right;
        } else {
            temp = &(*temp)->left;
        }
    }

    *temp = add_btnode(creature);
}

BTNode *search(BTNode *root, char *name) {
    if ((root == NULL) || (!strcmp(root->creatures->name, name))) {
        return root;
    } else if (strcmp(root->creatures->name, name) < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

void dfs(BTNode *root, traverse_dfs_type t) {
    if (root == NULL) {
        return;
    }

    if (t == PREORDER) {
        printf("%d\n", root->creatures->ac);
    }

    dfs(root->left, t);

    if (t == INORDER) {
        printf("%d\n", root->creatures->ac);
    }

    dfs(root->right, t);

    if (t == POSTORDER) {
        printf("%d\n", root->creatures->ac);
    }
}

void dfs_type(BTNode *root, char *type){
	if (root == NULL){
		return;
	}
	
	dfs_type(root->left, type);

    if (!strcmp(root->creatures->type, type)) {
        printf("%s %2d %2d %2d %2s\n", root->creatures->name, root->creatures->hp, root->creatures->ac, root->creatures->speed, type);
    }

    dfs_type(root->right, type);
}

typedef struct Node Node;
struct Node {
    void *data;
    Node *next;
};

void enqueue(Node **queue, void *data) {
    if (*queue == NULL) {
        *queue = calloc(1, sizeof(Node));
        (*queue)->data = data;

        return;
    }

    Node *temp = *queue;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = calloc(1, sizeof(Node));
    temp->next->data = data;
}

Node *dequeue(Node **queue) {
    Node *n = *queue;
    *queue = (*queue)->next;

    return n;
}

void bfs(BTNode *root) {
    BTNode *temp = root;
    Node *queue = NULL;
    Node *n = NULL;

    // queue up the root
    enqueue(&queue, temp);

    // loop for as long as there are items in the queue
    while (queue != NULL) {
        // dequeue item
        n = dequeue(&queue);
        temp = n->data;
        printf("%d\n", temp->creatures->ac);

        // queue the left and right children
        if (temp->left != NULL) {
            enqueue(&queue, temp->left);
        }

        if (temp->right != NULL) {
            enqueue(&queue, temp->right);
        }
}
}

void release_tree(BTNode *root) {
    if (root != NULL) {
        release_tree(root->left);
        release_tree(root->right);
        free(root);
    }
}

int option1 = 0;
int option2 = 0;

void menu(){
	do {
		printf("1. Traverse Tree\n");
		printf("2. Search\n");
		printf("3. Traverse by Type\n");
		printf("4. Exit\n");
		printf("> ");
		scanf("%d", &option1);
		getchar();
	} while (option1 >= 5 || option1 <= 0);

	if (option1 == 1){
		printf("1.Preorder DFS\n");
		printf("2.Inorder DFS\n");
		printf("3.Postorder DFS\n");
		printf("4.BFS\n");
		printf("> ");
		scanf("%d", &option2);
		getchar();
	}
}


int main(int argc, char **argv) {
	if (argc != 2){
		printf("Input wrong!\n");
		exit(1);
	}


	BTNode *root = NULL;
	char filename[20];
	char *buffer_type;
	char *buffer_name;
	strcpy(filename, argv[1]);
	FILE *fp = fopen(filename, "r");


	char line[150];
	int totalEntries = 0;
	//first count all the entries, keep counting until line fgets return NULL
	 while(fgets(line, 150, fp)){
	 	totalEntries++;
	 }
	 //set file pointer back to the beginning
	 rewind(fp);

	 //make struct arrays
	 Creature *creature = malloc(sizeof(Creature) * totalEntries);

	 int columnNumber = 0;
	 int structNumber = 0;

	 while (fgets(line, sizeof(line), fp))
	{
		columnNumber = 0;
		//To take name
	char *token = strtok(line, ",");

	while (token)
	{
		//Load CSV name to struct
		if (columnNumber == 0){
			int length = strlen(token);
			buffer_name = malloc((length + 1) * sizeof(char));
			strcpy(buffer_name, token);
			(creature + structNumber)->name = buffer_name;
		}

		//Load CSV hp to struct
		if (columnNumber == 1){
			(creature + structNumber)->hp = atoi(token);
		}

		//Load CSV ac to struct
		if (columnNumber == 2){
			(creature + structNumber)->ac = atoi(token);
		}

		//Load CSV speed to struct
		if (columnNumber == 3){
			(creature + structNumber)->speed = atoi(token);
		}

		//Load CSV type to struct
		if (columnNumber == 4) {   
			int length = strlen(token);
			buffer_type = malloc((length + 1) * sizeof(char));
			strcpy(buffer_type, token);
			(creature + structNumber)->type = buffer_type;
		}

		//update token and column number
		token = strtok(NULL, ",");
		columnNumber++;
	}
		//update struct number to access next struct
		structNumber++;
	}

	//Create binary tree based on insert() by ac elements
	for (int i = 0; i < totalEntries; i++){
		insert(&root, (creature + i));
	}

	menu();
	fclose(fp); //close file

	//to find search name
	if (option1 == 2){
	    printf("Enter the name to search: \n");
	    char buffer[128];
	    fgets(buffer, 128, stdin);
	    buffer[strlen(buffer) - 1] = '\0';
	    //search returns a BTNode
	    BTNode *s1 = search(root, buffer);
	    //If not NULL, we found the name
	    if (s1) {
	        printf("Found %s\n", buffer);
	    } else {
	        printf("Cannot find %s\n", buffer);
	    }
	    free(s1);
	}
	

	//DFS and BFS
	if (option1 == 1){
		if (option2 == 1){
			dfs(root, PREORDER);
		} else if (option2 == 2){
			dfs(root, INORDER);
		} else if (option2 == 3){
			dfs(root, POSTORDER);
		} else {
			bfs(root);
		}
	}
		

	if (option1 == 3){
		char buffer[128];
		printf("Enter type: ");
		fgets(buffer, 128, stdin);
		buffer[strlen(buffer) - 1] = '\0';
		dfs_type(root, buffer);
	}

	if (option1 == 4){
		exit(0);
	}

	free(creature);

	release_tree(root);
	return 0;
}
