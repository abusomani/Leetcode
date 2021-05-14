class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int N = warehouse.size();
        for(int i=1; i<N; i++)
            warehouse[i] = min(warehouse[i], warehouse[i-1]);
        int j = N-1, res = 0;
        for(auto box: boxes){
            while(j >= 0 and warehouse[j] < box)
                j--;
            if(j < 0)break;
            res++;
            j--; // assigned one
        }
        return res;
    }
};