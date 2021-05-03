class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        // Priority Queue by default sorted in MAX HEAP ORDER
        priority_queue<int> q;
        
        int sum = 0;
        for (auto& c : courses)
        {
            int t = c[0]; //Course time
            int d = c[1]; //Max day before which course has to be completed
            
            q.push(t);
            sum += t;
            
            if (sum > d)
            {
                sum -= q.top(); //This can be some other long course
                q.pop();
            }

        }
        return q.size();
    }
};