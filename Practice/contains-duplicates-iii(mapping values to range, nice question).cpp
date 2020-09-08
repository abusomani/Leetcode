#define ll long long
class Solution {
public:
    ll getId(int val, int &t)
    {
        return (1LL * val - INT_MIN) / (1LL * t + 1);
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int N = nums.size();
        if(k < 0 or t < 0) return false;
        unordered_map<ll, ll> bucket;
        for(int i=0; i<N; i++)
        {
            if(i > k)
                bucket.erase(getId(nums[i-k-1], t));
            ll id = getId(nums[i], t);
            if(bucket.count(id) or
              (bucket.count(id-1) and abs(bucket[id-1] - nums[i]) <= t) or
              (bucket.count(id+1) and abs(bucket[id+1] - nums[i]) <= t))
                return true;
            
            bucket[id] = nums[i];
        }
        return false;
    }
};