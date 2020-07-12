class Solution
{
public:
    string simplifyPath(string path)
    {
        string res, tmp;
        vector<string> St;
        stringstream ss(path);
        while (getline(ss, tmp, '/'))
        { // getline is like split of JAVA
            if (tmp == "" or tmp == ".")
                continue;
            if (tmp != "..")
                St.push_back(tmp);
            else if (!stk.empty())
                St.pop_back();
        }

        for (auto str : St)
            res += "/" + str;
        return res.size() == 0 ? "/" : res;
    }
};