/*
Logic:
    if n > m, implies last bit wont match, hence problem reduces to (m/2 , n/2) i.e. shifting all bits by 1 to right.
    Here we need to also left shift the final result of the divided subproblem by 1, for getting final result 
    whenever n == m , all the numbers would be same hence return m

Consider the bits from low to high. if n > m, the lowest bit will be 0, and then we could transfer the problem to sub-problem: rangeBitwiseAnd(m>>1, n>>1).
*/
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        return (n > m) ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    }
};