class Solution {
private:
    int closestIndex(vector<int> &V, int idx) {
        int N = V.size(), l = 0, r = N-1;
        int lower = V[l], upper = V[r];
        // index lesser than first occurence
        if(idx < lower)
            return lower;
        // index greater than last occurence
        if(idx > upper)
            return upper;
        // index between occurences
        else {
            // find first index greater than current.
            // previous one is one index less
            int R = upper_bound(V.begin(), V.end(), idx) - V.begin(), L = R-1;
            // if previous index is valid then have a comparison
            if(L >= 0) {
                return abs(V[R]-idx) <= abs(V[L]-idx) ? V[R] : V[L];
            }
            return V[R];
        }
    }
public:
    vector<int> shortestToChar(string s, char c) {
        int N = s.size();
        vector<int> indices, res(N, 0);
        for(int i=0; i<N; i++)
            if(s[i] == c)
                indices.push_back(i);
        
        for(int i=0; i<N; i++) 
            if(s[i] != c) 
                res[i] = abs(closestIndex(indices, i) - i);
            
        return res;
    }
};