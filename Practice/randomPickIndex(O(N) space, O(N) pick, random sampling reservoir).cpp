class Solution {
public:
    vector<int> n;
    Solution(vector<int> nums) 
    {
        n = nums;
    }
    
    int pick(int target) 
    {
        int count = 0, res = -1, N = n.size();
        for (int i = 0; i < N; ++i)
        {
            if(n[i] != target) continue;
            if(++count == 1) res = i;
            else
                if(!(rand()%count)) res = i;
        }
        return res;
    }
};
