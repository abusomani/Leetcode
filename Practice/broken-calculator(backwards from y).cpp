class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y)
            return X-Y;
        return 1 + (Y&1 ? brokenCalc(X, Y+1) : brokenCalc(X, Y>>1));
    }
};