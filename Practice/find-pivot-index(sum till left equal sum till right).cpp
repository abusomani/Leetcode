class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> prefixSum;
        prefixSum.push_back(0);
        for (auto num : nums)
            prefixSum.push_back(num + prefixSum.back());
        // left sum = prefixSum[i-1]
        // right sum = prefixSum[N] - prefixSum[i]
        //A=[1,7,3,6,5,6]
        //[0,1,8,11,17,22,28]
        for (int i = 1; i <= N; i++)
            if (prefixSum[i - 1] == (prefixSum[N] - prefixSum[i]))
                return i - 1;

        return -1;
    }
};