#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head;

struct Node* getNewNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insertToBegin(int new_data){
    struct Node* new_node = getNewNode(new_data);
    if(head == NULL){
        head = new_node;
        return;
    }

    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void insertToEnd(int new_data) {
    struct Node* new_node = getNewNode(new_data);

    Node* last = head;

    if(head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    while(last->next != NULL)
    last = last->next;

    last->next = new_node;

    new_node->prev = last;

    return;
}

void insertAfter(Node* prev_node, int new_data){
    if(prev_node == NULL){
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    struct Node* new_node = getNewNode(new_data);

    new_node->data = new_data;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if(new_node->next != NULL)
        new_node->next->prev = new_node;
}

void deleteNode(Node* del){
    if(head == NULL || del == NULL){
        return;
    }

    if(head == del){
        head = del->next;
    }

    if(del->next != NULL){
        del->prev->next = del->next;
    }

    free(del);
    return;
}

void printLinkList() {
    struct Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    head = NULL;

    insertToEnd(9);
    insertToBegin(3);
    insertAfter(head->next, 6);
    insertToEnd(2);
    insertToBegin(5);
    insertAfter(head->next->next, 4);

    cout << "Created Double Linked List is: \n\t";
    printLinkList();

    cout<<endl;

    deleteNode(head->next->next);
    cout << "Double Linked List after deletion: \n\t";
    printLinkList();

    cout<<endl;
}
