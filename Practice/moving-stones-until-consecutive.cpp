class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> V = {a,b,c};
        sort(V.begin(), V.end());
        int mx = abs(V[2]-V[1]-1) + abs(V[1]-V[0]-1);
        int mn = 2;
        if(V[1] == V[0]+1 and V[2] == V[1]+1)
            mn = 0;
        // either consecutive or difference of two
        else if((V[1] == V[0]+1 or V[2] == V[1]+1) or (V[1]-V[0] == 2 or V[2]-V[1] == 2))
            mn = 1;
        return {mn, mx};
    }
};