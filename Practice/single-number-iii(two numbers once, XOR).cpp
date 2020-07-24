/*
011
101
V=110
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int V = 0, i;
        for(auto &num : nums)V ^= num;
        
        for(i=0;i<32;i++)
            if(V & (1 << i))
                break;
        
        for(auto &num : nums)
        {
            if(num & (1 << i))
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};