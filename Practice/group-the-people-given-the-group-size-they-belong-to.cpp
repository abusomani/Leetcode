/*
Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
*/
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int N = groupSizes.size();
        vector<vector<int>> result;
        unordered_map<int, vector<int>> Mp;

        for (int i = 0; i < N; i++)
        {
            int sz = groupSizes[i];
            if (Mp.count(sz) == 0 or Mp[sz].size() < sz)
            {
                Mp[sz].push_back(i);
            }
            else
            {
                result.push_back(Mp[sz]);
                Mp[sz].clear();
                Mp[sz].push_back(i);
            }
        }

        for (auto grp : Mp)
            result.push_back(grp.second);

        return result;
    }
};