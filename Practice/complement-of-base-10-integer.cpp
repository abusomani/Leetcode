class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0)return 1;
        int temp = N, bit = 1;
        while(temp != 0) {
            N = N ^ bit;
            bit <<= 1;
            temp >>= 1;
        }
        return N;
    }
};