class MedianFinder
{
private:
    priority_queue<int> small;                            // max heap for smaller part
    priority_queue<int, vector<int>, greater<int>> large; // min heap for larger part
public:
    MedianFinder()
    {
    }

    // size of small >= large always
    void addNum(int num)
    {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (small.size() < large.size())
        {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        return small.size() > large.size() ? small.top() : (small.top() + large.top()) / 2.0;
    }
};
