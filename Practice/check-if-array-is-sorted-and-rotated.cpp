class Solution {
private:
    int pivot(vector<int> &nums){
        for(int i=1; i<nums.size(); i++)
            if(nums[i] < nums[i-1])
                return i;
        return -1;
    }
    bool isSorted(vector<int> &nums){
        for(int i=1; i<nums.size(); i++)
            if(nums[i] < nums[i-1])
                return false;
        return true;
    }
public:
    bool check(vector<int>& nums) {
        if(isSorted(nums))
            return true;
        int idx = pivot(nums), endIdx = nums.size()+idx;
        if(idx == -1)return false;
        for(int i=idx+1; i<endIdx; i++) {
            if(nums[i%nums.size()] < nums[(i-1+nums.size())%nums.size()])
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    bool check(vector<int> &A)
    {
        for (int i = 0, k = 0; i < A.size(); ++i)
            if (A[i] > A[(i + 1) % A.size()] && ++k > 1)
                return false;
        return true;
    }
};