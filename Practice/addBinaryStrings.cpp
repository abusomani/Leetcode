class Solution
{
public:
    int toDigit(char c)
    {
        return (c - '0');
    }
    string addBinary(string a, string b)
    {
        int N = a.size(), M = b.size();
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
            carry = sum / 2;

            result += to_string(sum % 2);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};