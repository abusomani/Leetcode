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
            build(2 * si + 1, ss, mid, nums);     // left
            build(2 * si + 2, mid + 1, se, nums); // right
            tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
        }
    }
    int query(int si, int ss, int se, int qs, int qe)
    {
        if (qs > se or qe < ss)
            return 0;
        if (ss >= qs and se <= qe)
            return tree[si];
        int mid = ss + ((se - ss) >> 1);
        return query(2 * si + 1, ss, mid, qs, qe) + query(2 * si + 2, mid + 1, se, qs, qe);
    }

public:
    NumArray(vector<int> &nums)
    {
        N = nums.size();
        tree.resize(4 * N);
        if (N != 0)
            build(0, 0, N - 1, nums);
    }

    int sumRange(int i, int j)
    {
        return query(0, 0, N - 1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */