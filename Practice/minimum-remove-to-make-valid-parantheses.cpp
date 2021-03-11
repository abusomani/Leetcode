class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int N = s.size();
        vector<int> toAdd(N,1);
        vector<pair<char,int>> V;
        for(int i=0;i<N;i++){
            if(s[i] == '(')
                V.push_back({'(', i});
            else if(s[i] == ')')
            {
                if(V.empty())
                    toAdd[i] = 0;
                else if(V.back().first == '(')
                    V.pop_back();
            }
        }
        while(!V.empty())
            toAdd[V.back().second]=0, V.pop_back();
        string res;
        for(int i=0; i<N; i++)
            if(toAdd[i])
                res += s[i];
        return res;
    }
};