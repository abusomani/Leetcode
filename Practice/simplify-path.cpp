class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> unix;
        unix.push_back("/");
        string tmp;
        stringstream ss(path);
        while (getline(ss, tmp, '/'))
        {
            if (tmp.size() == 0 or tmp == ".")
                continue;
            if (tmp == "..")
            {
                if (unix.size() > 1)
                    unix.pop_back();
            }
            // push with terminating "/" for separation
            else
                unix.push_back(tmp + "/");
        }

        string res;
        for (auto &p : unix)
            res += p;

        // if res size is greater than one means atleast one char is there with "/", so pop it
        if (res.size() > 1)
            res.pop_back();
        return res;
    }
};