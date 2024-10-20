#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Node* createList(int n) {
	struct Node *head = NULL, *temp = NULL;
	int data, i;

	for (i = 0; i < n; i++) {
    	printf("Enter data for node %d: ", i + 1);
    	scanf("%d", &data);

    	struct Node* newNode = createNode(data);

    	if (head == NULL) {
        	head = newNode;
        	temp = head;
    	} else {
        	temp->next = newNode;
        	temp = temp->next;
    	}
	}
	return head;
}

void insertAtBeginning(struct Node** head, int data) {
	struct Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
	struct Node* newNode = createNode(data);
	if (*head == NULL) {
    	*head = newNode;
    	return;
	}
	struct Node* temp = *head;
	while (temp->next != NULL) {
    	temp = temp->next;
	}
	temp->next = newNode;
}

void insertAtMiddle(struct Node** head, int data, int pos) {
	struct Node* newNode = createNode(data);
	if (pos == 1) {
    	insertAtBeginning(head, data);
    	return;
	}

	struct Node* temp = *head;
	int i;
	for (i = 1; i < pos - 1 && temp != NULL; i++) {
    	temp = temp->next;
	}

	if (temp == NULL) {
    	printf("Position out of range\n");
	} else {
    	newNode->next = temp->next;
    	temp->next = newNode;
	}
}

void deleteAtBeginning(struct Node** head) {
	if (*head == NULL) {
    	printf("List is empty\n");
    	return;
	}
	struct Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void deleteAtEnd(struct Node** head) {
	if (*head == NULL) {
    	printf("List is empty\n");
    	return;
	}
	struct Node* temp = *head;
	struct Node* prev = NULL;

	if (temp->next == NULL) {
    	*head = NULL;
    	free(temp);
    	return;
	}

	while (temp->next != NULL) {
    	prev = temp;
    	temp = temp->next;
	}
	prev->next = NULL;
	free(temp);
}

void deleteAtMiddle(struct Node** head, int pos) {
	if (*head == NULL) {
    	printf("List is empty\n");
    	return;
	}
	struct Node* temp = *head;
	struct Node* prev = NULL;
	int i;

	if (pos == 1) {
    	deleteAtBeginning(head);
    	return;
	}

	for (i = 1; i < pos && temp != NULL; i++) {
    	prev = temp;
    	temp = temp->next;
	}

	if (temp == NULL) {
    	printf("Position out of range\n");
	} else {
    	prev->next = temp->next;
    	free(temp);
	}
}

void modifyNode(struct Node* head, int pos, int newData) {
	struct Node* temp = head;
	int i;

	for (i = 1; i < pos && temp != NULL; i++) {
    	temp = temp->next;
	}

	if (temp == NULL) {
    	printf("Position out of range\n");
	} else {
    	temp->data = newData;
	}
}

void printList(struct Node* head) {
	struct Node* temp = head;
	while (temp != NULL) {
    	printf("%d -> ", temp->data);
    	temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	struct Node* head = NULL;
	int n, choice, data, pos, newData;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	head = createList(n);
	printList(head);

	while (1) {
    	printf("\nMenu:\n");
    	printf("1. Insert at Beginning\n");
    	printf("2. Insert at End\n");
    	printf("3. Insert at Middle\n");
    	printf("4. Delete at Beginning\n");
    	printf("5. Delete at End\n");
    	printf("6. Delete at Middle\n");
    	printf("7. Modify a Node\n");
    	printf("8. Print List\n");
    	printf("9. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);

    	switch (choice) {
        	case 1:
            	printf("Enter data to insert at beginning: ");
            	scanf("%d", &data);
            	insertAtBeginning(&head, data);
            	printList(head);
            	break;
        	case 2:
            	printf("Enter data to insert at end: ");
            	scanf("%d", &data);
            	insertAtEnd(&head, data);
            	printList(head);
            	break;
        	case 3:
            	printf("Enter data to insert: ");
            	scanf("%d", &data);
            	printf("Enter position to insert: ");
            	scanf("%d", &pos);
            	insertAtMiddle(&head, data, pos);
            	printList(head);
            	break;
        	case 4:
            	deleteAtBeginning(&head);
            	printList(head);
            	break;
        	case 5:
            	deleteAtEnd(&head);
            	printList(head);
            	break;
        	case 6:
            	printf("Enter position to delete: ");
            	scanf("%d", &pos);
            	deleteAtMiddle(&head, pos);
            	printList(head);
            	break;
        	case 7:
            	printf("Enter position to modify: ");
            	scanf("%d", &pos);
            	printf("Enter new data: ");
            	scanf("%d", &newData);
            	modifyNode(head, pos, newData);
            	printList(head);
            	break;
        	case 8:
            	printList(head);
            	break;
        	case 9:
            	exit(0);
        	default:
            	printf("Invalid choice\n");
    	}
	}

	return 0;
}
