class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int begin = 0, end = 0, N = nums.size(), counter = 0, K = 1, ans = 0;
        while (end < N)
        {
            if (nums[end++] == 0)
            {
                counter++;
                while (counter > K)
                {
                    while (nums[begin] != 0)
                        begin++;
                    begin++;
                    counter--;
                }
            }
            ans = max(ans, end - begin);
        }
        return ans;
    }
};