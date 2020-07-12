//Time complexity => O(N^k)
class Solution
{
public:
    int partitionSum;
    bool canPartition(vector<int> &nums)
    {
        int ans = 0, N = nums.size(), k = 2;

        for (auto num : nums)
            ans += num;

        if (ans & 1)
            return false;

        partitionSum = ans / k;
        sort(nums.begin(), nums.end());
        if (nums[N - 1] > partitionSum)
            return false;

        vector<int> visited(N, 0);
        return canPartitionIntoKSubs(nums, k, N - 1, partitionSum, visited);
    }

    bool canPartitionIntoKSubs(vector<int> &nums, int k, int pos, int remSum, vector<int> &visited)
    {
        if (k == 1)
            return true;
        if (remSum == 0)
            return canPartitionIntoKSubs(nums, k - 1, nums.size() - 1, partitionSum, visited);

        for (int i = pos; i >= 0; i--)
        {
            if (visited[i])
                continue;
            if (remSum - nums[i] < 0)
                continue;
            visited[i] = 1;
            if (canPartitionIntoKSubs(nums, k, i - 1, remSum - nums[i], visited))
                return true;
            visited[i] = 0;
        }

        return false;
    }
};