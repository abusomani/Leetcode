int MAX = 5005;
class Solution {
private:
    vector<int> BIT;
    void update(int idx, int val){
        for(int i=idx; i<MAX; i+=i&-i)
            BIT[i] += val;
    }
    int query(int idx){
        int res = 0;
        for(int i=idx; i>0; i-=i&-i)
            res += BIT[i];
        return res;
    }
public:
    bool isIdealPermutation(vector<int>& A) {
        BIT.resize(MAX, 0);
        int N = A.size(), global = 0, local = 0;
        for(auto &n: A)
        {
            n++;
            global += (query(MAX-1) - query(n));
            update(n, 1);
        }
        for(int i=0;i<N-1; i++)
            local += A[i] > A[i+1] ? 1 : 0;
        return global == local;
    }
};