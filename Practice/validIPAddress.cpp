class Solution
{
public:
    string validIPAddress(string IP)
    {
        return validIpv4(IP) ? "IPv4" : validIpv6(IP) ? "IPv6" : "Neither";
    }
    bool validIpv4(string IP)
    {
        if (count(IP.begin(), IP.end(), '.') != 3)
            return false;

        vector<string> parts = split(IP, '.');

        if (parts.size() != 4)
            return false;

        for (auto part : parts)
        {
            if (part.empty() or part.size() > 3 or (part.size() > 1 and part[0] == '0'))
                return false;

            int idx = 0;
            while (idx < part.size())
            {
                if (!isdigit(part[idx++]))
                    return false;
            }

            if (stoi(part) > 255)
                return false;
        }

        return true;
    }
    bool validIpv6(string IP)
    {
        if (count(IP.begin(), IP.end(), ':') != 7)
            return false;

        vector<string> parts = split(IP, ':');

        if (parts.size() != 8)
            return false;

        for (auto part : parts)
        {
            if (part.empty() or part.size() > 4)
                return false;

            int idx = 0;
            while (idx < part.size())
            {
                if (!isalnum(part[idx]))
                    return false;
                if (isalnum(part[idx]) and toupper(part[idx]) > 'F')
                    return false;
                idx++;
            }
        }
        return true;
    }
    vector<string> split(string IP, char delim)
    {
        vector<string> res;
        stringstream ss(IP);
        string tmp;
        while (getline(ss, tmp, delim))
            res.push_back(tmp);

        return res;
    }
};