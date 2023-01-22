class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> St(nums.begin(), nums.end());
        int ans = 0;
        for (auto &num : nums)
        {
            // if already processed for num - 1, then no need for processing for num
            if (!St.count(num - 1))
            {
                int count = 0, next = num;
                while (St.count(next))
                {
                    count++;
                    next++;
                }
                ans = max(ans, count);
            }
        }

        return ans;
    }
};