

#include <iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
};

node* createLinkedList() {
    
    struct node* head = NULL, *newNode = NULL, *temp = NULL;
    int choice = 1;
    
    while (choice) {
        newNode = new node;
        cout << "Enter Node Value " << endl;
        cin >> (newNode->data);
        if (head == NULL) {
            newNode->next = NULL;
            head = temp = newNode;
        }
        else {
            temp->next = newNode;
            newNode->next = NULL;
            temp = newNode;
        }
        cout << "Enter 1 To Continue And 0 To End" << endl;
        cin >> choice;
    }
    return head;
}

void printLinkedList(struct node*head) {
    struct node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}

node* reverseLinkedList(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head, *next = head;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

node*insertInBegin(int data, node*head) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

node* insertAtEnd(int data, node* head) {
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

node* insertAtPos(int data, int pos, node* head) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if (pos < 1) {
        cout << "Invalid Position" << endl;
        return head;
    }
    int count = 1; struct node* temp = head , *curr = NULL;
    while (count < pos - 1) {
        temp = temp->next;
        count += 1;
    }
    curr = temp;
    temp = temp->next;
    curr->next = newNode;
    newNode->next = temp;
    return head;
}


node* deleteFromBegin(node* head) {
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


node* deleteFromEnd(node* head) {
    struct node* temp = head, *curr = NULL;
    while (temp->next != NULL) {
        curr = temp;
        temp = temp->next;
    }
    if (temp == head) {
        head = NULL;
        free(temp);
    }
    else {
        free(temp);
        curr->next = NULL;
    }
    
    return head;
}


node* deleteFromPos(int pos, node* head) {
    int counter = 1;
    struct node* temp = head, *prev = NULL;
    while (counter < pos) {
        prev = temp;
        temp = temp->next;
        counter++;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

int main()
{
    struct node* head = createLinkedList();
    cout << "======= Print Linked List =======" << endl;
    printLinkedList(head);
    cout << endl;

    cout << "======= Reverse Linked List =======" << endl;
    head = reverseLinkedList(head);
    printLinkedList(head);
    cout << endl;

    cout << "======= Insert 5 In Begin =======" << endl;
    head = insertInBegin(5, head);
    printLinkedList(head);
    cout << endl;
    cout << "======= Insert 100 At End =======" << endl;
    head = insertAtEnd(100, head);
    printLinkedList(head);

    cout << endl;
    cout << "======= Insert At Position 3 =======" << endl;
    head = insertAtPos(100, 3 ,head);
    printLinkedList(head);

    cout << endl;
    cout << "======= Delete From Begin =======" << endl;
    head = deleteFromBegin(head);
    printLinkedList(head);


    cout << endl;
    cout << "======= Delete From End =======" << endl;
    head = deleteFromEnd(head);
    printLinkedList(head);


    cout << endl;
    cout << "======= Delete From Pos 3 =======" << endl;
    head = deleteFromPos(3, head);
    printLinkedList(head);

}

