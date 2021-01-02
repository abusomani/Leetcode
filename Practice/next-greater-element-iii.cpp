class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        if(next_permutation(num.begin(), num.end()))
            return stol(num) > INT_MAX ? -1 : stoi(num);
        return -1;
    }
};

class Solution1
{
public:
    int nextGreaterElement(int n)
    {
        string num = to_string(n);
        if (next(num))
            return stol(num) > INT_MAX ? -1 : stoi(num);
        return -1;
    }
    bool next(string &s)
    {
        int N = s.size(), l = N - 1, k = N - 2;
        // 5 4 3 2 1
        // 1 1 1
        for (; k >= 0; k--)
            if (s[k + 1] > s[k])
                break;
        if (k < 0) // reverse sorted
            return false;
        // 5 3 4 2 1
        for (; l > k; l--)
            if (s[l] > s[k])
                break;

        swap(s[k], s[l]);
        reverse(s.begin() + k + 1, s.end());
        cout << s << endl;
        return true;
    }
};