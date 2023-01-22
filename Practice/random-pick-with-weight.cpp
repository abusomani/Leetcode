class Solution
{
private:
    vector<int> prefixSum;
    int totalSum = 0;

public:
    Solution(vector<int> &w)
    {
        prefixSum.clear();
        prefixSum.push_back(0);
        for (auto &i : w)
            totalSum += i, prefixSum.push_back(prefixSum.back() + i);
    }

    int pickIndex()
    {
        int idx = upper_bound(prefixSum.begin(), prefixSum.end(), rand() % totalSum) - prefixSum.begin();
        return idx - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */