class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> St;
        for (auto num : nums)
        {
            if (St.count(num))
                return true;
            St.insert(num);
        }
        return false;
    }
};