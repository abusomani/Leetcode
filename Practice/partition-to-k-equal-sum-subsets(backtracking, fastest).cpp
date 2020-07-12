// Time complexity => O(N ^ k)
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int ans = 0, N = nums.size();
        for (auto num : nums)
            ans += num;

        if (ans % k != 0)
            return false;

        int partitionSum = ans / k, sum = 0;
        sort(nums.begin(), nums.end());
        if (nums[N - 1] > partitionSum)
            return false;

        vector<bool> visited(N, false);
        return canPartition(nums, k, partitionSum, N - 1, visited, partitionSum);
    }

    bool canPartition(vector<int> &nums, int k, int remSum, int pos, vector<bool> &visited, int partitionSum)
    {
        if (k == 1) // till here all were true
            return true;
        if (remSum == 0)
            return canPartition(nums, k - 1, partitionSum, nums.size() - 1, visited, partitionSum);
        for (int i = pos; i >= 0; i--)
        {
            if (visited[i])
                continue;
            if (remSum - nums[i] < 0)
                continue;
            visited[i] = true;
            if (canPartition(nums, k, remSum - nums[i], i - 1, visited, partitionSum))
                return true;
            visited[i] = false;
        }

        return false;
    }
};