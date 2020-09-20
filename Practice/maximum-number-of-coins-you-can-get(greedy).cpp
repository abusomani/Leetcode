class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int N = piles.size(), ans = 0;
        sort(piles.begin(), piles.end());
        int i = 0, j = N-1;
        while(j > i)
        {
            ans += piles[j-1];
            j -= 2;
            i++;
        }
        return ans;
    }
};