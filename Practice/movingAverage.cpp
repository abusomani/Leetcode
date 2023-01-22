class MovingAverage
{
private:
    queue<int> stream;
    int capacity;
    double sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        capacity = size;
        sum = 0.0;
    }

    double next(int val)
    {
        stream.push(val);
        sum += (double)val;
        if (stream.size() > capacity)
        {
            sum -= stream.front();
            stream.pop();
        }
        return sum / stream.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */