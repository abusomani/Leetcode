class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        seats.insert(seats.begin(), 1); // Add 1 to starting of array as left end
        seats.push_back(1); //  Add 1 to ending of array as right end
        int ans = 0, N = seats.size(), left = 0;
        for(int i=0; i<N; i++) 
        {
            if(seats[i] == 1) 
            {
                if(left == 0 or i == N-1) // in these cases we can put the person farthest
                    ans = max(ans, i-left-1);
                else
                    ans = max(ans, (i-left)/2); // the optimal would be placing in center of the limit
                left = i;
            }
        }
        return ans;
    }
};