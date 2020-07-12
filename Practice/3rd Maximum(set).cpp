class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> St;
        for (auto num : nums)
        {
            St.insert(num);
            if (St.size() > 3)
                St.erase(St.begin());
        }

        return St.size() >= 3 ? *St.begin() : *St.rbegin();
    }
};