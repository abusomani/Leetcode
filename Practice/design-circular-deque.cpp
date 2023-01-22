class MyCircularDeque
{
private:
    vector<int> V;
    int i, j, len, maxSize;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        V.resize(k);
        i = k - 1; // front
        j = 0;     // rear
        len = 0;
        maxSize = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        V[i] = value;
        i = (i - 1 + maxSize) % maxSize;
        len++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        V[j] = value;
        j = (j + 1) % maxSize;
        len++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        i = (i + 1) % maxSize;
        len--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;

        j = (j - 1 + maxSize) % maxSize;
        len--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
            return -1;
        return V[(i + 1) % maxSize];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
            return -1;
        return V[(j - 1 + maxSize) % maxSize];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return len == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return len == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */