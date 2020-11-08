class Solution {
private:
    int dividing(vector<int> &nums, int X) {
        int sm = 0;
        for(auto &num : nums)
            sm += (int)ceil((double)num/ X);
        return sm;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = -1, ans = -1;
        for(auto &n : nums)r = max(r, n);
        while(l <= r) {
            int mid = l + (r-l)/2;
            int val = dividing(nums, mid);
            if(val <= threshold)
                ans = mid, r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};