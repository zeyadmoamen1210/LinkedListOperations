
#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* prev;
	struct node* next;
}*head, *tail;

node* createDLL() {
	struct node *newNode = NULL;
	int choice = 1;
	
	while (choice) {
		newNode = (struct node*)malloc(sizeof(struct node)); // malloc return the first address located (wild pointer)
		cout << "Enter Data " << endl;
		cin >> newNode->data;
		newNode->prev = newNode->next = NULL;

		if (head == NULL) {
			// Thats First Node
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}

		// for add many nodes
		cout << "Do You Want Continue Press 1 " << endl;
		cin >> choice;
	}
	return head;
}


void printDoubleLinkedList() {
	struct node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	cout << endl;

}

void insertInBegin(int data){

	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;

}

void insertInEnd(int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->prev = tail;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}


void insertAtPos(int data, int pos) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	struct node* temp = head; int i = 1;
	while (i < pos - 1) {
		i++;
		temp = temp->next;
	}

	newNode->next = temp->next;
	temp->next->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;

}


void deleteFromBegin() {
	struct node* temp = head;
	head = head->next;
	head->prev = NULL; temp->next = NULL;
	free(temp);
}

void deleteFromEnd() {
	struct node* temp = tail;
	tail = tail->prev;
	tail->next = temp->prev = NULL;
	free(temp);
}


void deleteFromPos(int pos){
	int i = 1;
	struct node* temp = head;
	while (i < pos) {
		i++;
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}


void reverseDLL() {
	struct node* currentNode = head, * nextNode = head;
	struct node* prevNode = NULL;

	while (currentNode != NULL) {
		nextNode = currentNode->next;
		currentNode->prev = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	currentNode = tail;
	tail = head;
	head = currentNode;
}


int main()
{
	createDLL();
	cout << "----------------------------" << endl;
	cout << "Create Double Linked List  " << endl;
	cout << "----------------------------" << endl;
	printDoubleLinkedList();
	cout << "----------------------------" << endl;
	cout << "Insert At Begin  " << endl;
	cout << "----------------------------" << endl;
	insertInBegin(100);

	printDoubleLinkedList();
	cout << "----------------------------" << endl;
	cout << "Insert At End  " << endl;
	cout << "----------------------------" << endl;
	insertInEnd(200);

	printDoubleLinkedList();
	cout << "----------------------------" << endl;
	cout << "Insert At Position 3  " << endl;
	cout << "----------------------------" << endl;
	insertAtPos(55, 3);

	printDoubleLinkedList();

	cout << "----------------------------" << endl;
	cout << "Delete From Begin  " << endl;
	cout << "----------------------------" << endl;
	deleteFromBegin();

	printDoubleLinkedList();
	cout << "----------------------------" << endl;
	cout << "Delete From End  " << endl;
	cout << "----------------------------" << endl;
	deleteFromEnd();

	printDoubleLinkedList();
	cout << "----------------------------" << endl;
	cout << "Delete From Position 3  " << endl;
	cout << "----------------------------" << endl;
	deleteFromPos(3);

	printDoubleLinkedList();
	cout << "----------------------------" << endl;
	cout << "Reverse Double Linked List " << endl;
	cout << "----------------------------" << endl;
	reverseDLL();
	printDoubleLinkedList();

}



