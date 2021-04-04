class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if(N <= 1)
            return N;
        vector<int> up(N, 0), down(N, 0);
        up[0] = down[0] = 1;
        for(int i=1; i<N; i++){
            if(nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if(nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            } else {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(up[N-1], down[N-1]);
    }
};

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int N = nums.size();
        if (N <= 1)
            return N;
        int up = 1, down = 1;
        for (int i = 1; i < N; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                up = down + 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};