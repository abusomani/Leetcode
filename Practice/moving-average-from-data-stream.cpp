class MovingAverage
{
private:
    deque<int> Dq;
    int sz;
    double sum = 0;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        sz = size;
    }

    double next(int val)
    {
        Dq.push_back(val);
        sum += val;
        while (Dq.size() > sz)
        {
            sum -= Dq.front();
            Dq.pop_front();
        }

        return sum / Dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */