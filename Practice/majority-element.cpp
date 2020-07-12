class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0], cnt = 1, N = nums.size();
        for (int i = 1; i < N; i++)
        {
            cnt = (nums[i] == candidate) ? cnt + 1 : cnt - 1;
            if (cnt == 0)
            {
                candidate = nums[i];
                cnt = 1;
            }
        }
        int count = 0;
        for (int i = 0; i < N; i++)
            if (nums[i] == candidate)
                count++;

        if (2 * count > N)
            return candidate;

        return 0;
    }
};