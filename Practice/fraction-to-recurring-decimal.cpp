class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string ans;
        if (numerator < 0 ^ denominator < 0)
            ans += "-";

        long dividend = labs(numerator), divisor = labs(denominator);
        long r = dividend % divisor;
        ans += to_string(dividend / divisor);
        if (!r)
            return ans;
        ans += ".";
        unordered_map<long, int> Mp;
        while (r)
        {
            if (Mp.count(r))
            {
                ans.insert(Mp[r], "("); // insert at the index a opening bracket
                ans += ")";
                break;
            }
            Mp[r] = ans.size(); // like index
            r *= 10;
            ans += to_string(r / divisor);
            r %= divisor;
        }
        return ans;
    }
};