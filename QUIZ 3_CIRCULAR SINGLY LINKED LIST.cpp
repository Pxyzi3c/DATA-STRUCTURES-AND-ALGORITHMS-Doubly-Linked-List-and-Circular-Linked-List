#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

struct Node *addToEmpty(struct Node *tail, int new_data) {
    if(tail != NULL){
        return tail;
    }

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    tail = new_node;
    new_node->next = tail;
    return tail;
}

struct Node *insertToBegin(struct Node *tail, int new_data){
    if(tail == NULL){
        return addToEmpty(tail, new_data);
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = tail->next;
    tail->next = new_node;
    return tail;
}

struct Node *insertToEnd(struct Node *tail, int new_data) {
    if(tail == NULL){
        return addToEmpty(tail, new_data);
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
    return tail;
}

struct Node *insertAfter(struct Node *tail, struct Node* item, int new_data){
    if(tail == NULL){
        return NULL;
    }

    struct Node *new_node, *temp;
    temp = tail->next;

    do{
        if(temp == item){
            new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = new_data;
            new_node->next = temp->next;
            temp->next = new_node;

            if(temp == tail)
                tail = new_node;

            return tail;
        }
        temp = temp->next;
    }while(temp != tail->next);

    cout << item << " is not present in the list." << endl;
    return tail;
}

struct Node *deleteNode(struct Node *tail, struct Node *del){
    if(tail == NULL || del == NULL){
        return tail;
    }

    struct Node *temp;
    temp = tail->next;

    if(del == temp) {
        tail->next = del->next;
        free(temp);
        temp = NULL;
        return tail;
    }

    if(del == tail){
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = tail->next;
        free(tail);
        tail = temp;
        return tail;
    }

    struct Node *temp2;
    temp2 = temp->next;

    while(temp2 != del){
        temp = temp->next;
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    free(temp2);
    temp2 = NULL;
    return tail;
}

void reverse(struct Node *tail){
    struct Node *prev, *curr, *nextNode;
    curr = tail->next;
    nextNode = curr->next;

    if(tail==NULL){
        cout << "List is empty." << endl;
        return;
    }

    while(curr != tail) {
        prev = curr;
        curr = nextNode;
        nextNode = curr->next;
        curr->next = prev;
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

int main() {
    struct Node *tail = NULL;

    tail = insertToBegin(tail,4);
    tail = insertToBegin(tail,8);
    tail = insertAfter(tail,tail->next,3); //head is tail-next
    tail = insertToEnd(tail,2);
    tail = insertToBegin(tail,7);
    tail = insertAfter(tail,tail->next->next,5); //head is tail->next

    cout << "Created Double Linked List is: \n\t";
    printLinkList(tail);
    cout<<endl;

    tail = deleteNode(tail, tail->next->next->next); //head is tail->next
    cout << "Double Linked List after deletion in reverse order: \n\t";
    reverse(tail);
}
