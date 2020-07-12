typedef long long ll;
class Solution {
public:
    
    // Merge till <= high is the key step as high must be included too
    void merge(vector<int>&nums, int low,int mid, int high){
        vector<int> A;
        int i = low, j = mid+1, k = 0;
        
        while(i <= mid and j <= high) {
            if(nums[i] <= nums[j])
                A.push_back(nums[i++]);
            else 
                A.push_back(nums[j++]);
        }
        
        while(i<=mid)A.push_back(nums[i++]);
        while(j<=high)A.push_back(nums[j++]);
        
        for(int i=0;i<A.size();i++)
            nums[low+i]=A[i];
       
    }
    
    void mergeSort(vector<int> & nums, int low, int high) {
        // 1 element is already sorted
        if(low < high) {
            int mid = low + ((high-low)/2);
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
   
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1)return nums;
        
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};