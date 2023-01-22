class MedianFinder
{
private:
    priority_queue<int> Smaller;
    priority_queue<int, vector<int>, greater<int>> Larger;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        Larger.push(num);
        Smaller.push(Larger.top());
        Larger.pop();
        if (Larger.size() < Smaller.size())
        {
            Larger.push(Smaller.top());
            Smaller.pop();
        }
    }

    double findMedian()
    {
        return Larger.size() > Smaller.size() ? Larger.top() : (Larger.top() + Smaller.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */