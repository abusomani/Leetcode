class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int N = digits.size(), i = N - 1, sum = 0, carry = 1;
        while (i >= 0)
        {
            sum = digits[i] + carry;
            digits[i--] = sum % 10;
            carry = sum / 10;
        }
        if (carry)
            digits.insert(digits.begin(), carry);

        return digits;
    }
};