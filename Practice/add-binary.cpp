class Solution
{
public:
    string addBinary(string a, string b)
    {
        const int N = a.size(), M = b.size();
        string res;
        int sum = 0, carry, i = N - 1, j = M - 1;
        while (i >= 0 or j >= 0 or carry)
        {
            sum = carry;
            if (i >= 0)
                sum += (a[i--] - '0');
            if (j >= 0)
                sum += (b[j--] - '0');

            res += to_string(sum % 2);
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};