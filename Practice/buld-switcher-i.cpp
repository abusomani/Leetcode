class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;
        for(int i=1; i*i<=n; i++)
            res++;
        return res;
    }
};