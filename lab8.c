#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = newNode->prev = newNode;
	return newNode;
}

void insertFront(int value) {
	struct Node* newNode = createNode(value);
	if (head == NULL) {
    	head = newNode;
	} else {
    	struct Node* last = head->prev;
    	newNode->next = head;
    	newNode->prev = last;
    	last->next = head->prev = newNode;
    	head = newNode;
	}
}

void insertEnd(int value) {
	struct Node* newNode = createNode(value);
	if (head == NULL) {
    	head = newNode;
	} else {
    	struct Node* last = head->prev;
    	newNode->next = head;
    	newNode->prev = last;
    	last->next = head->prev = newNode;
	}
}

void deleteNode(int value) {
	if (head == NULL) return;
	struct Node* curr = head, *prevNode = NULL;
	while (curr->data != value) {
    	if (curr->next == head) return;
    	prevNode = curr;
    	curr = curr->next;
	}
	if (curr->next == head && curr->prev == head) {
    	free(curr);
    	head = NULL;
    	return;
	}
	if (curr == head) {
    	struct Node* last = head->prev;
    	head = curr->next;
    	last->next = head;
    	head->prev = last;
    	free(curr);
	} else if (curr->next == head) {
    	prevNode->next = head;
    	head->prev = prevNode;
    	free(curr);
	} else {
    	struct Node* temp = curr->next;
    	prevNode->next = temp;
    	temp->prev = prevNode;
    	free(curr);
	}
}

void display() {
	if (head == NULL) return;
	struct Node* temp = head;
	do {
    	printf("%d ", temp->data);
    	temp = temp->next;
	} while (temp != head);
	printf("\n");
}

int main() {
	insertFront(10);
	insertEnd(20);
	insertEnd(30);
	insertFront(5);
	printf("Circular Doubly Linked List: ");
	display();
	deleteNode(20);
	printf("After Deletion: ");
	display();
	return 0;
}
