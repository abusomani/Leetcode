class Solution {
public:
    char slowestKey(vector<int>& R, string K) {
        pair<char,int> P = {K[0], R[0]};
        for(int i=1; i<R.size(); i++)
        {
            if(R[i] - R[i-1] > P.second)
                P = {K[i], R[i] - R[i-1]};
            else if(R[i] - R[i-1] == P.second and K[i] > P.first)
                P = {K[i], R[i] - R[i-1]};
            
        }
        return P.first;
    }
};