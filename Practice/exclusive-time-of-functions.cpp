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
        stack<Log> St;
        vector<int> res(n, 0);

        for (auto log : logs)
        {
            string temp1, temp2, temp3;
            stringstream ss(log);
            getline(ss, temp1, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');
            Log item = {stoi(temp1), temp2, stoi(temp3)};
            if (item.status == "start")
                St.push(item);
            else
            {
                assert(St.top().id == item.id);
                int timeTaken = item.timestamp - St.top().timestamp + 1;
                res[item.id] += timeTaken;
                St.pop();
                if (!St.empty())
                    res[St.top().id] -= timeTaken;
            }
        }

        return res;
    }
};