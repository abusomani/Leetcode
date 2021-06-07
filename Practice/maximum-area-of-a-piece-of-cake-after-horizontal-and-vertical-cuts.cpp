const int MOD = 1e9+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        sort(H.begin(), H.end());
        H.push_back(h);
        sort(V.begin(), V.end());
        V.push_back(w);
        long long mxL = 0, mxW = 0, prev = 0;
        for(auto h: H){
            mxL = max(mxL, h-prev);
            prev = h;
        }
        prev = 0;
        for(auto w: V){
            mxW = max(mxW, w-prev);
            prev = w;
        }
        return (mxL * mxW) % MOD;
    }
};