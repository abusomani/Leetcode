//O(sqrt(N)logN)
class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> St;
        for(int i=1; i<=sqrt(n); i++)
        {
            if(n%i == 0) {
                St.insert(i);
                St.insert(n/i);
            }
        }
        k--;
        vector<int> factors(St.begin(), St.end());
        return k >= factors.size() ? -1 : factors[k];
    }
};
//O(sqrt(N))
class Solution1 {
public:
    int kthFactor(int n, int k) {
        float N = sqrt(n);
        for(int i=1; i<N; i++)
            if(n%i == 0 and --k == 0) 
                return i;
        for(int i=N; i>0; i--)
            if(n%i == 0 and --k == 0) 
                return n/i;
        return -1;
    }
};