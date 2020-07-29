class Solution
{
public:
    /*
    1,2,3,4,5,6,7,8,9,10 |6
    5,6,7,8,9,10,1,2,3,4
    */
    void rotate(vector<int> &nums, int k)
    {
        int N = nums.size();
        if (N <= 1)
            return;
        k = k % N;
        vector<int> tmp(nums.begin() + (N - k), nums.end());
        for (int i = 0; i < N - k; i++)
            tmp.push_back(nums[i]);
        for (int i = 0; i < N; i++)
            nums[i] = tmp[i];
    }
};

class Solution1
{
public:
    /*
    1,2,3,4,5,6,7,8,9,10 |6
    5,6,7,8,9,10,1,2,3,4
    */
    void rotate(vector<int> &nums, int k)
    {
        int N = nums.size();
        if (N <= 1)
            return;
        k = k % N;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};