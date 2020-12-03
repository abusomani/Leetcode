class Solution {
private:
    int lim_N;
public:
    int bfs(vector<string> &V, long limit) {
        int cnt = 0;
        queue<long> Q;
        for(auto &i : V)
            Q.push(stol(i));
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                long num = Q.front();
                Q.pop();
                if(num <= limit)
                    cnt++;
                for(auto &i : V) {
                    long new_num = num * 10 + stol(i);
                    if(new_num <= limit)
                        Q.push(new_num);
                }
            }
        }
        return cnt;
    }
    int atMostNGivenDigitSet(vector<string>& V, int n) {
        lim_N = to_string(n).size();
        long limit = n;
        sort(V.begin(), V.end());
        return bfs(V, limit);
    }
};