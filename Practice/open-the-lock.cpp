class Solution {
public:
    vector<string> newKey(string word)
    {
        vector<string> res;
        for(int i=0; i< word.size(); i++)
        {
            string key = word;
            key[i] = (word[i] - '0' + 1) %10 + '0';
            res.push_back(key);
            key[i] = (word[i] - '0' + 9) %10 + '0';
            res.push_back(key);
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> A, B, visited;
        string start = "0000";
        if(dead.count(target) or dead.count(start))
            return -1;
        if(start == target)return 0;
        A.insert(start);
        visited.insert(start);
        B.insert(target);
        int ans = 0;
        while(!A.empty() and !B.empty())
        {
            if(A.size() > B.size())
               swap(A, B);

            unordered_set<string> newS;
            for(auto node : A)
            {
                for(auto child : newKey(node))
                {
                    if(B.count(child))
                        return ans + 1;
                    
                    if(visited.count(child))continue;
                    
                    if(!dead.count(child))
                    {
                        newS.insert(child);
                        visited.insert(child);
                    }
                }
            }
            A = newS;
            ans++;
        }
        
        return -1;
    }
};