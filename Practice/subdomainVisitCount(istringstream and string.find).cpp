class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> res;
        for (string s : cpdomains)
        {
            istringstream iss(s);
            int cnt;
            string domain;
            iss >> cnt;
            iss >> domain;

            while (true)
            {
                res[domain] += cnt;
                if (domain.find('.') != string::npos)
                    domain = domain.substr((int)domain.find('.') + 1);
                else
                    break;
            }
        }

        vector<string> ans;
        for (auto p : res)
        {
            ans.push_back(to_string(p.second) + " " + p.first);
        }
        return ans;
    }
};