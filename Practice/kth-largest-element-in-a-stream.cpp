class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> PQ; // Min heap
    int K;

public:
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto &num : nums)
        {
            PQ.push(num);
            if (PQ.size() > K)
                PQ.pop();
        }
    }

    int add(int num)
    {
        PQ.push(num);
        if (PQ.size() > K)
            PQ.pop();
        return PQ.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */