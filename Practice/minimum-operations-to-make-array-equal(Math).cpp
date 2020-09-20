/*
    For odd [1,3,5,7,9] => Its an AP of sum 2+4 and so on, sum of it is = X * (X+1) where X = N/2
    For even [1,3,5,7] => Its an AP of sum 1 + 3 and so on, sum of it is X * X where X = N/2
*/
class Solution
{
public:
    int minOperations(int n)
    {
        int X = n / 2;
        if (n & 1)
            return X * (X + 1);
        return X * X;
    }
};