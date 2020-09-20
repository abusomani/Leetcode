class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<string> Q;
        for(char c='1'; c<='9';c++)
            Q.push(string(1, c));
        
        while(!Q.empty())
        {
            int sz = Q.size();
            while(sz--)
            {
                string curr = Q.front();
                Q.pop();
                long val = stol(curr);
                if(val >= 1L*low and val <= 1L*high)
                    res.push_back(val);
                
                char ch = curr.back();
                ch++;
                if(ch >= '1' and ch <= '9')
                    curr += ch, Q.push(curr);
            }
        }
        return res;
    }
};