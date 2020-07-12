class Solution
{
public:
    string multiply(string A, string B)
    {
        int N = A.size(), M = B.size();
        string ans(N + M, '0');
        for (int i = N - 1; i >= 0; i--) // key is that ith and jth contributes to (i+j) and (i+j+1)
        {
            int carry = 0;
            for (int j = M - 1; j >= 0; j--)
            {
                int sum = (ans[i + j + 1] - '0') + (A[i] - '0') * (B[j] - '0') + carry;
                ans[i + j + 1] = (sum % 10 + '0');
                carry = sum / 10;
            }
            ans[i] += carry;
        }
        size_t pos = ans.find_first_not_of('0');
        if (pos != string::npos)
            return ans.substr(pos);

        return "0";
    }
};