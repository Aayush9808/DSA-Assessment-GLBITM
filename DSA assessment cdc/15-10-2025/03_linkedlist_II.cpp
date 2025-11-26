#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void addTwoNumbers(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    int carry = 0;
    
    while(l1 || l2 || carry) {
        int sum = carry;
        if(l1) { sum += l1->data; l1 = l1->next; }
        if(l2) { sum += l2->data; l2 = l2->next; }
        
        carry = sum / 10;
        tail->next = new Node(sum % 10);
        tail = tail->next;
    }
}

Node* rotateList(Node* head, int k) {
    if(!head || k == 0) return head;
    
    int len = 1;
    Node* tail = head;
    while(tail->next) {
        tail = tail->next;
        len++;
    }
    
    k = k % len;
    if(k == 0) return head;
    
    tail->next = head;
    for(int i = 0; i < len - k; i++) {
        tail = tail->next;
    }
    
    head = tail->next;
    tail->next = nullptr;
    return head;
}

Node* removeDuplicates(Node* head) {
    Node* curr = head;
    while(curr && curr->next) {
        if(curr->data == curr->next->data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
