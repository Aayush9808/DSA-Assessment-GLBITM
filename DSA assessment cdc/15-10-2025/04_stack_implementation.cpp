#include <vector>
#include <stack>
using namespace std;

class StackUsingArray {
    vector<int> arr;
    int top;
    int capacity;
public:
    StackUsingArray(int size) : capacity(size), top(-1) {
        arr.resize(size);
    }
    
    void push(int x) {
        if(top < capacity - 1) {
            arr[++top] = x;
        }
    }
    
    int pop() {
        if(top >= 0) {
            return arr[top--];
        }
        return -1;
    }
    
    int peek() {
        if(top >= 0) return arr[top];
        return -1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
};

int nextGreaterElement(vector<int>& nums, int x) {
    stack<int> st;
    for(int num : nums) {
        if(num > x) return num;
    }
    return -1;
}
