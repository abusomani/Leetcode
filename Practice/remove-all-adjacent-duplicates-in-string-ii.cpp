class Solution {
public:
    string removeDuplicates(string s, int k) {
        int N = s.size();
        vector<pair<char,int>> V;
        for(int i=0; i<N; i++){
            if(V.empty() or (V.back().first != s[i])){
                V.push_back({s[i],1});
            } else {
                V.push_back({s[i], V.back().second + 1});
            }
            
            if(V.back().second >= k){
                char c = V.back().first;
                while(!V.empty() and V.back().first == c)
                    V.pop_back();
            }
        }
        string res;
        for(auto p : V)
            res += p.first;
        return res;
    }
};