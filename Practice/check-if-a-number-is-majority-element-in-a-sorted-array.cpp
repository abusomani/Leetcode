class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int,int> Mp;
        for(auto c: nums)Mp[c]++;
        return Mp[target] > nums.size()/2;
    }
};
class Solution
{
public:
    bool isMajorityElement(vector<int> &nums, int target)
    {
        if (!binary_search(nums.begin(), nums.end(), target))
            return false;
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return (high - low) > nums.size() / 2;
    }
};