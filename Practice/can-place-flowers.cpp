class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size(), ans = 0;
        for(int i=0; i<N; i++) {
            if(flowerbed[i] == 1) {
                if(i-1 >= 0)flowerbed[i-1]=2;
                if(i+1 < N)flowerbed[i+1]=2;
            }
        }
        int idx = 0, cnt = 0;
        while(idx < N) {
            if(flowerbed[idx++] == 0)
                cnt++;
            else {
                ans += (cnt+1)/2;
                cnt = 0;
            }
        }
        ans += (cnt + 1)/2;
        return ans >= n;
    }
};