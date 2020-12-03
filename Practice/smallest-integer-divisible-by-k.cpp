class Solution {
public:
/*
    Due to pigeonhole principle, number of possible remainders can be K (O to K-1). So loop only K times
*/
    int smallestRepunitDivByK(int K) {
        if(K%2 == 0 or K%5 == 0)
            return -1;
        int rem = 1;
        for(int i=1; i<=K; i++)
        {
            if(rem % K == 0)
                return i;
            rem = (rem * 10 + 1)%K;
        }
        return -1;
    }
};