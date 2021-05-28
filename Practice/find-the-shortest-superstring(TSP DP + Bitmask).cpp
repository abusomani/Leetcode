class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int N = words.size();
        vector<vector<int>> cost(N, vector<int>(N));
        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                cost[i][j] = getCost(words[i], words[j]);
                cost[j][i] = getCost(words[j], words[i]);
            }
        }
        vector<vector<int>> dp (1<<N, vector<int>(N));
        vector<vector<int>> path (1<<N, vector<int>(N));
        
        int last = -1, min = INT_MAX;
        
        for(int s = 1; s <  (1 << N); s++) {
            for(int k = 0; k < N; k++) {
                dp[s][k] = INT_MAX;
            }
            for(int w = 0; w < N; w++) {
                if(s & (1 << w)) {
                    int prev = s^(1 << w);
                    if(prev == 0) {
                        dp[s][w] = words[w].size();
                    } else {
                        for(int wj = 0; wj < N; wj++) {
                            if(dp[prev][wj] < INT_MAX && dp[prev][wj] + cost[wj][w] < dp[s][w]) {
                                dp[s][w] = dp[prev][wj] + cost[wj][w];
                                path[s][w] = wj;
                            }
                        }
                    }
                }
                if (s == (1 << N) - 1 && dp[s][w] < min) {
                    min = dp[s][w];
                    last = w;
                }
            }
        }
        int s = (1 << N) - 1;
        
        stack<int> st;
        while(s != 0) {
            int min_index = 0;
            st.push(last);
            int temp = s;
            s = s ^ (1 << last);
            last = path[temp][last];
        }
        int prev = st.top();
        string res = words[prev];
        st.pop();
        while(st.size()) {
            int curr = st.top();
            st.pop();
            res = res + words[curr].substr(words[curr].size() - cost[prev][curr]);
            prev = curr;
        }
        
        return res;
    }
    
    int getCost (string &A, string &B) {
        for(int i = 0; i < A.size(); i++) {
            string _A = A.substr(i); // all possible length strings
            if (_A.size() <= B.size() && B.substr(0, _A.size()) == _A) {
                return B.size() - _A.size();
            }
        }
        return B.size();
    }
};