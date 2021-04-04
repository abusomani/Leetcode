class MyCircularQueue {
private:
    deque<int> D;
    int N;
public:
    MyCircularQueue(int k) {
          N = k;      
    }
    
    bool enQueue(int value) {
        if(D.size() < N)
        {
            D.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!D.empty()){
            D.pop_front();
            return true;
        }
        return false;
    }
    
    int Front() {
        return D.empty() ? -1 : D.front();
    }
    
    int Rear() {
        return D.empty() ? -1 : D.back();
    }
    
    bool isEmpty() {
        return D.empty();
    }
    
    bool isFull() {
        return D.size() == N;
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