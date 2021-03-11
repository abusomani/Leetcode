int MAX = 1e5+5;
class Solution {
private:
    vector<int> BIT;
    void update(int idx, int x) {
        for(int i=idx; i<MAX; i += i&-i)
            BIT[i] += x;
    }
    int query(int idx) {
        int sm = 0;
        for(int i=idx; i>0; i -= i&-i)
            sm += BIT[i];
        return sm;
    }
public:
/* All the numbers towards left should be one.
Problem reduces to prefix sum of maximum number should be equal to maximum number itself.
*/
    int numTimesAllBlue(vector<int>& light) {
        BIT.resize(MAX);
        for(auto &i: BIT)i = 0;
        int res = 0, cnt = 1, mx = 0;
        for(auto &l: light) {
            mx = max(mx, l);
            update(l, 1);
            res += query(mx) == mx;
            cnt++;
        }
        return res;
    }
};