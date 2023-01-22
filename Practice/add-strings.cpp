class Solution
{
public:
    string addStrings(string A, string B)
    {
        const int N = A.size(), M = B.size();
        if (N == 0 or M == 0)
            return (N == 0) ? B : A;
        int i = N - 1, j = M - 1, carry = 0, sum;
        string res;
        while (i >= 0 or j >= 0 or carry)
        {
            sum = carry;
            if (i >= 0)
                sum += (A[i--] - '0');
            if (j >= 0)
                sum += (B[j--] - '0');

            res += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};