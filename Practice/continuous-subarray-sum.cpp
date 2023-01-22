class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> Mp; // sum and last index
        int sum = 0, N = nums.size();
        if (N == 0)
            return false;
        Mp[0] = -1;
        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
            sum = k == 0 ? sum : sum % k;
            if (Mp.count(sum))
            {
                if (i - Mp[sum] > 1)
                    return true;
            }
            else
                Mp[sum] = i;
        }
        return false;
    }
};