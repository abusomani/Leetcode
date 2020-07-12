class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        unordered_set<int> St(nums1.begin(), nums1.end());
        for (int x : nums2)
            if (St.erase(x)) // if value was removed then it exists
                result.push_back(x);
        return result;
    }
};