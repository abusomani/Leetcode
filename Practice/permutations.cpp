class Solution
{
public:
    // 5 1 4 3 2
    // 5 2 (4 3 1)
    vector<vector<int>> permute(vector<int> &nums)
    {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back(nums);
        while (next_permute(nums, N))
            result.push_back(nums);

        return result;
    }
    bool next_permute(vector<int> &nums, int &N)
    {
        int k, l;
        for (k = N - 2; k >= 0; k--)
            if (nums[k] < nums[k + 1])
                break;
        if (k < 0) // descending sorted
            return false;
        for (l = N - 1; l > k; l--)
            if (nums[l] > nums[k])
                break;

        // brought to appropriate position
        swap(nums[k], nums[l]);
        // reverse after k+1
        reverse(nums.begin() + k + 1, nums.end());
        return true;
    }
};