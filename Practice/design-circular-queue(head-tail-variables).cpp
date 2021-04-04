class MyCircularQueue
{
private:
    vector<int> Q;
    int N, tail, head;
    bool empty;

public:
    MyCircularQueue(int k)
    {
        N = k;
        empty = true;
        head = 0;
        tail = 0;
        Q = vector<int>(k);
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        empty = false;
        Q[tail] = value;
        tail = (tail + 1) % N;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        Q[head] = 0;
        head = (head + 1) % N;
        empty = head == tail;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : Q[head];
    }

    int Rear()
    {
        return isEmpty() ? -1 : Q[(tail - 1 + N) % N];
    }

    bool isEmpty()
    {
        return empty;
    }

    bool isFull()
    {
        return empty ? false : head == tail;
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