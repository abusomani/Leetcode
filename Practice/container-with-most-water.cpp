class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size(), ans = 0;
        int l = 0, r = N-1;
        while(l <= r){
            if(height[l] <= height[r]) 
                ans = max(ans, height[l] * (r-l)), l++;
            else
                ans = max(ans, height[r] * (r-l)), r--;
        }
        return ans;
    }
};