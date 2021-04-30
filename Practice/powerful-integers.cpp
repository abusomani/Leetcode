class Solution {
private:
    int limit(int num, int base){
        if(base == 1)
            return 1;
        int res = 0;
        long tmp = 1;
        while(tmp <= num)
            res++, tmp *= base;
        return res;
    }
    long power(long a, long b){
        long ans = 1, x = a;
        while(b){
            if(b&1)
                ans *= x;
            x *= x;
            b >>= 1;
        }
        return ans;
    }
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound <= 1)
            return {};
        
        long X = x, Y = y, tmp = 1;
        int limX = limit(bound, x), limY = limit(bound, y);
        unordered_set<int> St;
        for(int i=0; i<limX; i++)
            for(int j=0; j<limY; j++)
            {
                long ans = power(X, i) + power(Y, j);
                if(ans <= bound)
                    St.insert((int)ans);
            }
        
        vector<int> res;
        for(auto c: St)res.push_back(c);
        return res;
    }
};