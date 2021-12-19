#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node *addToEmpty(int new_data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->prev = temp;
    temp->data = new_data;
    temp->next = temp;
    return temp;
}

struct Node *insertToBegin(struct Node *tail, int new_data){
    struct Node *new_node = addToEmpty(new_data);
    if(tail == NULL){
        return new_node;
    }

    else{
        struct Node *temp = tail->next;
        new_node->next = temp;
        new_node->prev = tail;
        temp->prev = new_node;
        tail->next = new_node;
        return tail;
    }
}

struct Node *insertToEnd(struct Node *tail, int new_data) {
    struct Node *new_node = addToEmpty(new_data);
    if(tail == NULL){
        return new_node;
    }

    else{
        struct Node *start = tail->next;
        new_node->next = start;
        new_node->prev = tail;
        tail->next = new_node;
        start->prev = new_node;
        tail = new_node;
        return tail;
    }
}

struct Node *insertAfter(struct Node *tail,struct Node *item, int new_data){
    if(tail == NULL){
        return NULL;
    }

    struct Node *temp, *new_node;
    temp = tail->next;
    new_node = addToEmpty(new_data);

    do{
        if(temp == item){
            new_node->prev = temp;
            new_node->next = temp->next;
            temp->next->prev = new_node;
            temp->next = new_node;
            if(temp == tail){
                tail = tail->next;
            }
            return tail;
        }
        temp = temp->next;
    }while(temp != tail->next);

}

struct Node *deleteNode(struct Node *tail, struct Node *del){
    if(tail == NULL || del == NULL){
        return tail;
    }

    struct Node *temp;
    temp = tail->next;

    if(del == temp) {
        tail->next = del->next;
        del->next->prev = tail;
        free(temp);
        temp = NULL;
        return tail;
    }

    else if(del == tail){
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = tail->next;
        tail->next->prev = temp;
        free(tail);
        tail = temp;
        return tail;
    }

    while(temp != del){
        temp = temp->next;
    }

    struct Node *temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    return tail;
}

void reverse(struct Node *tail){
    struct Node *curr, *nextNode;
    curr = tail->next;
    nextNode = curr->next;

    if(tail==NULL){
        cout << "List is empty." << endl;
        return;
    }

    while(curr != tail) {
        curr->prev = curr;
        curr = nextNode;
        nextNode = curr->next;
        curr->next = curr->prev;
    }

    nextNode->next = tail;
    tail = nextNode;

    struct Node *temp;
    if(tail == NULL){
        cout << "List is empty." << endl;
        return;
    }

    temp = tail->next;
    do{
        cout << temp->data << " ";
        temp = temp -> next;
    }while(temp != tail->next);
}

void printLinkList(struct Node *tail) {
    if(tail == NULL){
        cout << "No element in the list";
    }
    else{
        struct Node* temp = tail->next;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != tail->next);
    }
    cout << "\n";
}

int main() {
    struct Node *tail = NULL;

    tail = insertToEnd(tail, 5);
    tail = insertToBegin(tail, 1);
    tail = insertAfter(tail, tail->next->next, 3); //head is tail->next
    tail = insertToEnd(tail, 8);
    tail = insertToBegin(tail, 4);
    tail = insertAfter(tail, tail->next, 9); //head is tail->next

    cout << "Created Doubly Linked List is:\n\t";
    printLinkList(tail);

    cout << "After deleting a node in reverse order:\n\t";
    tail = deleteNode(tail, tail->prev->prev);
    reverse(tail);
}
