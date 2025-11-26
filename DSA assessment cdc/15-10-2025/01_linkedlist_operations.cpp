#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtPosition(Node*& head, int pos, int data) {
    Node* newNode = new Node(data);
    if(pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for(int i = 0; i < pos-1 && temp; i++) {
        temp = temp->next;
    }
    if(temp) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtPosition(Node*& head, int pos) {
    if(!head) return;
    if(pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for(int i = 0; i < pos-1 && temp; i++) {
        temp = temp->next;
    }
    if(temp && temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

Node* search(Node* head, int key) {
    while(head) {
        if(head->data == key) return head;
        head = head->next;
    }
    return nullptr;
}

int countNodes(Node* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}
