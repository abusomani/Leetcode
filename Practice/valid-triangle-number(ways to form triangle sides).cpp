//Time complexity => O(N^2 log N)
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int cnt = 0, N = nums.size();
        if (N < 3)
            return 0;

        for (int i = 0; i <= N - 3; i++)
        {
            for (int j = i + 1; j <= N - 2; j++)
            {
                // first number <= (a + b), all numbers before that index and greater than (j+1) are valid
                int inc = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin() - (j + 1);
                if (inc > 0) // if possible
                    cnt += inc;
            }
        }

        return cnt;
    }
};

//Time complexity => O(N^2)
class Solution1
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int cnt = 0, N = nums.size();
        if (N < 3)
            return 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i <= N - 3; i++)
        {
            int k = i + 2;                                        // for each
            for (int j = i + 1; j <= N - 2 and nums[i] != 0; j++) // side cannot be zero
            {
                while (k < N and nums[i] + nums[j] > nums[k]) // increase till valid
                    k++;
                cnt += (k - j - 1);
            }
        }

        return cnt;
    }
};