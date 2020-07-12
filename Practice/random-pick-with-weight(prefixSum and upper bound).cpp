class Solution
{
private:
    vector<int> prefixSum;
    int totalSum;

public:
    Solution(vector<int> &w)
    {
        prefixSum.push_back(0);
        for (auto i : w)
            prefixSum.push_back(prefixSum.back() + i);
        totalSum = prefixSum.back();
    }

    int pickIndex()
    {
        int range = rand() % totalSum;
        int idx = upper_bound(prefixSum.begin(), prefixSum.end(), range) - prefixSum.begin();
        return idx - 1;
    }
};
