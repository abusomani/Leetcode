#define iterator vector<vector<int>>::iterator
class Solution
{
public:
    void sort_count(iterator l, iterator r, vector<int> &count)
    {
        if (r - l <= 1)
            return;
        iterator m = l + ((r - l) >> 1);
        sort_count(l, m, count);
        sort_count(m, r, count);
        for (iterator i = l, j = m; i < m; i++)
        {
            while (j < r and (*i)[0] > (*j)[0])
                j++;
            count[(*i)[1]] += j - m; // all (j-m) elements are smaller than i
        }
        inplace_merge(l, m, r);
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> count(N, 0);
        vector<vector<int>> A;
        for (int i = 0; i < N; i++)
            A.push_back({nums[i], i});
        sort_count(A.begin(), A.end(), count);
        return count;
    }
};