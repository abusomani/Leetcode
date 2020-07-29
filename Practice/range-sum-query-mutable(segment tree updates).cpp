class NumArray
{
private:
    int N;
    vector<int> tree;
    void build(int si, int ss, int se, vector<int> &nums)
    {
        if (ss == se)
            tree[si] = nums[ss];
        else
        {
            int mid = ss + ((se - ss) >> 1);
            build(2 * si + 1, ss, mid, nums);
            build(2 * si + 2, mid + 1, se, nums);
            tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
        }
    }
    int query(int si, int ss, int se, int qs, int qe)
    {
        if (qe < ss or qs > se)
            return 0;
        if (ss >= qs and se <= qe) // segement completely inside the query range
            return tree[si];
        int mid = ss + ((se - ss) >> 1);
        return query(2 * si + 1, ss, mid, qs, qe) +
               query(2 * si + 2, mid + 1, se, qs, qe);
    }
    void update(int si, int ss, int se, int idx, int val)
    {
        if (idx < ss or idx > se)
            return;
        if (ss == se and ss == idx)
            tree[si] = val;
        else
        {
            int mid = ss + ((se - ss) >> 1);
            update(2 * si + 1, ss, mid, idx, val);
            update(2 * si + 2, mid + 1, se, idx, val);
            tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
        }
    }

public:
    NumArray(vector<int> &V)
    {
        N = V.size();
        tree.resize(4 * N);
        if (N != 0)
            build(0, 0, N - 1, V);
    }

    void update(int idx, int val)
    {
        update(0, 0, N - 1, idx, val);
    }

    int sumRange(int i, int j)
    {
        return query(0, 0, N - 1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */