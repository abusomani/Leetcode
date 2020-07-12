class Solution
{
public:
    int toDigit(char c)
    {
        return (c - '0');
    }

    string addStrings(string a, string b)
    {
        int N = a.size(), M = b.size();

        if (N == 0)
            return b;
        if (M == 0)
            return a;

        int i = N - 1, j = M - 1, carry = 0;
        string result = "";
        while (i >= 0 or j >= 0 or carry)
        {
            int sum = 0;
            if (i >= 0)
                sum += toDigit(a[i--]);
            if (j >= 0)
                sum += toDigit(b[j--]);

            sum += carry;
            carry = sum / 10;

            result += to_string(sum % 10);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};