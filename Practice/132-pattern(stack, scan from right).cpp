class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s2 = INT_MIN;
        stack<int> St;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] < s2)return true;
            while(!St.empty() and St.top() < nums[i])
            {
                s2 = max(s2, St.top());
                St.pop();
            }
            St.push(nums[i]);
        }
        
        return false;
    }
};