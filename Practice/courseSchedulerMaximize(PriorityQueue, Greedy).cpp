//Once you make sure a course fits in, you can remove it any time later and the other courses you have added after would still fit.
//So it is always safe to remove any course in the past
class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        priority_queue<int> PQ;
        int sm = 0;

        for (auto course : courses)
        {
            int t = course[0];
            int d = course[1];

            PQ.push(t);
            sm += t;

            if (sm > d)
            {
                sm -= PQ.top();
                PQ.pop();
            }
        }

        return PQ.size();
    }
};