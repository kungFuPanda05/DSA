class MyCircularQueue {
public:
    vector <int> arr;
    int i, j, k;
    int count;

    MyCircularQueue(int K) {
        k = K;
        arr = vector <int> (k, -1);
        i=0;
        j=0;
        count=0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        arr[j] = value;
        count++;
        j = (j+1)%k;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        arr[i] = -1;
        i = (i+1)%k;
        count--;
        return true;
    }
    
    int Front() {
        return arr[i];
    }
    
    int Rear() {
        int prevJ = (j-1+k)%k;
        return arr[prevJ];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */