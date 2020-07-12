class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> St;
        for (auto num : nums)
            St.insert(num);

        int ans = 0;
        for (auto num : St)
        {
            int longest = 1, x = num;
            if (St.find(x - 1) == St.end())
            { // check only in ascending direction, avoid redundant checks for 2 , 3 and 4
                while (St.find(x + 1) != St.end())
                {
                    longest++;
                    x = x + 1;
                }
                ans = max(ans, longest);
            }
        }

        return ans;
    }
};