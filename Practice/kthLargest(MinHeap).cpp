class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> MnHp; // min heap
    int kth ;
    KthLargest(int K, vector<int>& nums) {
        kth = K;
        
        int N = nums.size();
        for(int i=0;i<N;i++){
            MnHp.push(nums[i]);
            if(MnHp.size() > K)
                MnHp.pop();
        }
    }
    
    int add(int val) {
        MnHp.push(val);  
        if(MnHp.size() > kth)
            MnHp.pop();
        return MnHp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */