#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	int height;
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

int height(struct Node* N) {
	if (N == NULL)
    	return 0;
	return N->height;
}

struct Node* createNode(int data) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	node->height = 1;
	return node;
}

struct Node* rightRotate(struct Node* y) {
	struct Node* x = y->left;
	struct Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

struct Node* leftRotate(struct Node* x) {
	struct Node* y = x->right;
	struct Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

int getBalance(struct Node* N) {
	if (N == NULL)
    	return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data) {
	if (node == NULL)
    	return createNode(data);
	if (data < node->data)
    	node->left = insert(node->left, data);
	else if (data > node->data)
    	node->right = insert(node->right, data);
	else
    	return node;

	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);

	if (balance > 1 && data < node->left->data)
    	return rightRotate(node);
	if (balance < -1 && data > node->right->data)
    	return leftRotate(node);
	if (balance > 1 && data > node->left->data) {
    	node->left = leftRotate(node->left);
    	return rightRotate(node);
	}
	if (balance < -1 && data < node->right->data) {
    	node->right = rightRotate(node->right);
    	return leftRotate(node);
	}
	return node;
}

struct Node* minValueNode(struct Node* node) {
	struct Node* current = node;
	while (current->left != NULL)
    	current = current->left;
	return current;
}

struct Node* deleteNode(struct Node* root, int data) {
	if (root == NULL)
    	return root;

	if (data < root->data)
    	root->left = deleteNode(root->left, data);
	else if (data > root->data)
    	root->right = deleteNode(root->right, data);
	else {
    	if ((root->left == NULL) || (root->right == NULL)) {
        	struct Node* temp = root->left ? root->left : root->right;
        	if (temp == NULL) {
            	temp = root;
            	root = NULL;
        	} else
            	*root = *temp;
        	free(temp);
    	} else {
        	struct Node* temp = minValueNode(root->right);
        	root->data = temp->data;
        	root->right = deleteNode(root->right, temp->data);
    	}
	}

	if (root == NULL)
    	return root;

	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
    	return rightRotate(root);
	if (balance < -1 && getBalance(root->right) <= 0)
    	return leftRotate(root);
	if (balance > 1 && getBalance(root->left) < 0) {
    	root->left = leftRotate(root->left);
    	return rightRotate(root);
	}
	if (balance < -1 && getBalance(root->right) > 0) {
    	root->right = rightRotate(root->right);
    	return leftRotate(root);
	}
	return root;
}

void inorder(struct Node* root) {
	if (root != NULL) {
    	inorder(root->left);
    	printf("%d ", root->data);
    	inorder(root->right);
	}
}

void preorder(struct Node* root) {
	if (root != NULL) {
    	printf("%d ", root->data);
    	preorder(root->left);
    	preorder(root->right);
	}
}

void postorder(struct Node* root) {
	if (root != NULL) {
    	postorder(root->left);
    	postorder(root->right);
    	printf("%d ", root->data);
	}
}

int main() {
	struct Node* root = NULL;
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
    
	printf("Inorder Traversal: ");
	inorder(root);
	printf("\n");

	printf("Preorder Traversal: ");
	preorder(root);
	printf("\n");

	printf("Postorder Traversal: ");
	postorder(root);
	printf("\n");

	root = deleteNode(root, 10);
	printf("After deleting 10 (Inorder): ");
	inorder(root);
	printf("\n");

	root = deleteNode(root, 20);
	printf("After deleting 20 (Inorder): ");
	inorder(root);
	printf("\n");

	root = deleteNode(root, 30);
	printf("After deleting 30 (Inorder): ");
	inorder(root);
	printf("\n");

	return 0;
}
