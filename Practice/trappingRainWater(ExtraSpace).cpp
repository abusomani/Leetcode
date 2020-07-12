class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if(N == 0)return 0;
        
        vector<int> left(N), right(N);
        left[0] = height[0];right[N-1]=height[N-1];
        int ans = 0;
        for(int i=1;i<N;i++)
            left[i] = max(left[i-1],height[i]);
        
        for(int i=N-2;i>=0;i--)
            right[i] = max(right[i+1],height[i]);
        
        
        for(int i=0;i<N;i++)
            ans += (min(left[i],right[i]) - height[i]);
        
        return ans;
    }
};