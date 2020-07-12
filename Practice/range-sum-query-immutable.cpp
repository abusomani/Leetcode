class NumArray
{
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int> &nums)
    {
        prefixSum.push_back(0);
        for (auto num : nums)
            prefixSum.push_back(num + prefixSum.back());
    }

    int sumRange(int i, int j)
    {
        return prefixSum[j + 1] - prefixSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */