class Solution
{
public:
    bool static compare(const string &a, const string &b)
    {
        string AB = a + b, BA = b + a;
        // custom sorting uses comparator that whether we should make AB or BA
        return (AB < BA);
    }
    void remove_trailing_zeroes(string &res)
    {
        if (res[0] != '0')
            return;
        res = "0";
    }
    string largestNumber(vector<int> &nums)
    {
        if (nums.empty())
            return "";
        vector<vector<string>> buckets(10);
        for (auto &num : nums)
        {
            string number = to_string(num);
            buckets[number[0] - '0'].push_back(number);
        }
        for (int i = 0; i < 10; i++)
            sort(buckets[i].begin(), buckets[i].end(), compare);

        string res;
        for (int i = 9; i >= 0; i--)
        {
            for (int j = buckets[i].size() - 1; j >= 0; j--)
                res += buckets[i][j];
        }
        remove_trailing_zeroes(res);
        return res;
    }
};