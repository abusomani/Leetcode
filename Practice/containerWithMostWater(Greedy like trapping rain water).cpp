class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size(),  ans = 0, l = 0 , r = N - 1;
        while(l < r) {
            ans = max(min(height[l], height[r])*(r-l), ans);
            if(height[l] < height[r])l++;
            else r--;
        }
        return ans;
    }
};