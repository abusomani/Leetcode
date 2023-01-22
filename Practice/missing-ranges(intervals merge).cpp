class Solution
{
private:
    string rangeToString(int low, int high)
    {
        return (low == high) ? to_string(low) : to_string(min(low, high)) + "->" + to_string(max(low, high));
    }

public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<string> res;

        int start = lower, N = nums.size();
        for (int i = 0; i < N; i++)
        {
            if (nums[i] > upper)
            {
                start = upper + 1;
                res.push_back(rangeToString(start, upper));
                break;
            }
            else if (nums[i] < lower)
                continue;
            else
            {
                if (nums[i] != start)
                {
                    res.push_back(rangeToString(start, nums[i] - 1));
                }
                start = nums[i] + 1;
            }
        }
        if (start <= upper)
            res.push_back(rangeToString(start, upper));
        return res;
    }
};