class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, ans = 0, lmax= 0;
        while(l < r) {
            int val = height[height[l] < height[r] ? l++ : r--];
            lmax = max(lmax, val);
            ans += lmax - val;
        }
        return ans;
    }
};