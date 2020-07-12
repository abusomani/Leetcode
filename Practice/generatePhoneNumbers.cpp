class Solution {
public:
    vector<string> alphabets = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        int N = digits.size();
        vector<string> result;
        if(N == 0)return result;
        
        queue<string> Q;
        for(int i=0;i<alphabets[digits[0]-'0'].size();i++) {
            Q.push(string(1, alphabets[digits[0]-'0'][i]));
        }        
        for(int i=1;i<N;i++){
            string str = alphabets[digits[i]-'0'];
            int sz = Q.size();
            for(int j=0;j<sz;j++) {
                string x = Q.front();
                Q.pop();
                for(auto c : str) {
                    Q.push(x + string(1,c));
                }
            }
        }
        while(!Q.empty()){
            result.push_back(Q.front());
            Q.pop();
        }
        
        return result;
    }
};