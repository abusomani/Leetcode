class Solution {
private:
    bool isLCS(string s, string w){
        int i=0, j =0, N = s.size(), M=w.size();
        while(i<N and j<M){
            if(s[i]==w[j])
                j++;
            i++;
        }
        return j >= M;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        pair<int,string> res = {0, ""};
        for(auto &word: d)
            if(isLCS(s, word))
            {
                if(res.first < word.size() or (res.first == word.size() and res.second > word))
                    res.first = word.size(), res.second = word;
            }
        return res.second;
    }
};