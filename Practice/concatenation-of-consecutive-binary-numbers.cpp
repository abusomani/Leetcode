int MOD = 1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        int res = 0;
        for(int i=1; i<=n; i++) {
            // only after first 1, you start multiplying 2.
            bool first = false;
            for(int j=31; j>=0; j--) {
                if(i & (1 << j))
                    first = true, res = (res*2 + 1)%MOD;
                else if(first)
                    res = (res * 2)%MOD;
            }
        }
        return res;
    }
};