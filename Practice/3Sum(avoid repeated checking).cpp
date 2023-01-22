class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int N = nums.size();
        if (N <= 2)
            return res;
        int i = 0;
        while (i < N - 2)
        {
            if (i and nums[i] == nums[i - 1])
            {
                i++;
                continue;
            }

            int j = i + 1, k = N - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else
                {
                    vector<int> t{nums[i], nums[j], nums[k]};
                    res.push_back(t);
                    j++;
                    k--;
                    while (j < k and nums[j] == nums[j - 1])
                        j++;
                    while (j < k and nums[k] == nums[k + 1])
                        k--;
                }
            }
            i++;
        }
        return res;
    }
};