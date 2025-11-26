#include <queue>
#include <vector>
using namespace std;

class QueueUsingArray {
    vector<int> arr;
    int front, rear, size, capacity;
public:
    QueueUsingArray(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        arr.resize(cap);
    }
    
    void enqueue(int x) {
        if(size < capacity) {
            rear = (rear + 1) % capacity;
            arr[rear] = x;
            size++;
        }
    }
    
    int dequeue() {
        if(size > 0) {
            int val = arr[front];
            front = (front + 1) % capacity;
            size--;
            return val;
        }
        return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};

class CircularQueue {
    vector<int> data;
    int front, rear, size, capacity;
public:
    CircularQueue(int k) : capacity(k), front(0), rear(-1), size(0) {
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(size == capacity) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
};
