class Solution
{
private:
    int MAXN;
    vector<vector<int>> tree;
    void init()
    {
        tree.resize(MAXN);
    }
    void merge(int si, int l, int r)
    {
        int i = 0, j = 0;
        while (i < tree[l].size() and j < tree[r].size())
        {
            if (tree[l][i] <= tree[r][j])
                tree[si].push_back(tree[l][i++]);
            else
                tree[si].push_back(tree[r][j++]);
        }
        while (i < tree[l].size())
            tree[si].push_back(tree[l][i++]);
        while (j < tree[r].size())
            tree[si].push_back(tree[r][j++]);
    }
    void build(int si, int ss, int se, vector<int> &nums)
    {
        if (ss == se) // leaf node
            tree[si].push_back(nums[ss]);
        else
        {
            int mid = ss + ((se - ss) >> 1);
            int l = 2 * si + 1, r = 2 * si + 2;
            build(l, ss, mid, nums);
            build(r, mid + 1, se, nums);
            merge(si, l, r);
        }
    }
    int query(int si, int ss, int se, int qs, int qe, int val)
    {
        if (qs > se or qe < ss)
            return 0;
        if (ss >= qs and se <= qe)
        {
            // upper bound to X - 1 is equal to lower bound to X
            //int small = upper_bound(tree[si].begin(), tree[si].end(), val - 1) - tree[si].begin();
            int small = lower_bound(tree[si].begin(), tree[si].end(), val) - tree[si].begin();
            return small;
        }
        int mid = ss + ((se - ss) >> 1);
        int l = query(2 * si + 1, ss, mid, qs, qe, val);
        int r = query(2 * si + 2, mid + 1, se, qs, qe, val);
        return l + r;
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
            return {};
        MAXN = (N << 2);
        init();
        build(0, 0, N - 1, nums);
        vector<int> res(N);
        for (int i = 0; i < N; i++)
            res[i] = query(0, 0, N - 1, i, N - 1, nums[i]);
        return res;
    }
};

// To remove the dependency on MAXN and resizing its better to use undordered_map<int, vector<int>> as Segement tree
class Solution1
{
public:
    unordered_map<int, vector<int>> tree;
    vector<int> a;

    vector<int> merge(vector<int> v1, vector<int> v2)
    {
        int i = 0, j = 0;
        vector<int> res;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] < v2[j])
            {
                res.push_back(v1[i++]);
            }
            else
                res.push_back(v2[j++]);
        }
        while (i < v1.size())
            res.push_back(v1[i++]);
        while (j < v2.size())
            res.push_back(v2[j++]);
        return res;
    }

    vector<int> build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node].push_back(a[start]);
            return tree[node];
        }
        vector<int> v1 = build(2 * node, start, (start + end) / 2);
        vector<int> v2 = build(2 * node + 1, (start + end) / 2 + 1, end);
        tree[node] = merge(v1, v2);
        return tree[node];
    }

    int query(int node, int start, int end, int l, int r, int val)
    {
        if (end < l || start > r)
            return 0;
        if (start >= l && end <= r)
        {
            return (int)((lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin()));
        }
        return query(2 * node, start, (start + end) / 2, l, r, val) + query(2 * node + 1, (start + end) / 2 + 1, end, l, r, val);
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        a = nums;
        vector<int> res;
        if (nums.size() == 0)
            return res;
        build(1, 0, (int)nums.size() - 1);
        for (int i = 0; i < nums.size(); i++)
        {
            int ans = query(1, 0, nums.size() - 1, i + 1, nums.size(), a[i]);
            res.push_back(ans);
        }
        return res;
    }
};