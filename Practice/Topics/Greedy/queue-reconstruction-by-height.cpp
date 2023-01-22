class Solution
{
public:
    // descending sort by heights, then using the second as index to insert makes no harm to existing sequence
    // because whatever we inserted is always having larger height than present
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [&](vector<int> &a, vector<int> &b) {
            return (a[0] > b[0]) or (a[0] == b[0] and a[1] < b[1]);
        });
        vector<vector<int>> ans;
        for (auto &p : people)
            ans.insert(ans.begin() + p[1], p);

        return ans;
    }
};