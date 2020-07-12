/*
Here j is used for middle cut, i for left cut and k for right cut.
Iterate middle cuts and then find left cuts which divides the first half into two equal quarters
Store that quarter sums in the hashset. 
Then find right cuts which divides the second half into two equal quarters and check if quarter sum is present in the hashset. 
If yes return true.
*/
class Solution
{
public:
    bool splitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sums(n, nums[0]);
        for (int i = 1; i < n; i++)
            sums[i] = sums[i - 1] + nums[i];

        for (int j = 3; j < n - 3; j++)
        {
            unordered_set<int> st;
            for (int i = 1; i < j - 1; i++)
                if (sums[i - 1] == sums[j - 1] - sums[i])
                    st.insert(sums[i - 1]);

            for (int k = j + 2; k < n - 1; k++)
                if (sums[n - 1] - sums[k] == sums[k - 1] - sums[j] and st.count(sums[k - 1] - sums[j]))
                    return true;
        }
        return false;
    }
};