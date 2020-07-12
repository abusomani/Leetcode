class Solution
{
private:
    struct Log
    {
        int id;
        string status;
        int timestamp;
    };

public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> res(n, 0);
        stack<Log> St;

        for (auto log : logs)
        {
            stringstream ss(log);
            string temp1, temp2, temp3;
            getline(ss, temp1, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');
            Log item = {stoi(temp1), temp2, stoi(temp3)};
            if (item.status == "start")
                St.push(item);
            else
            {
                assert(St.top().id == item.id); // start and end should be of top item

                int time_added = item.timestamp - St.top().timestamp + 1; // time needed to be added
                res[item.id] += time_added;
                St.pop();

                if (!St.empty())
                {
                    assert(St.top().status == "start");
                    res[St.top().id] -= time_added; // remove this time from top
                }
            }
        }

        return res;
    }
};