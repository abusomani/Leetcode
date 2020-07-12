class Solution
{
public:
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> mp;

    string getRandom()
    {
        srand((unsigned)time(NULL));
        string str = "";
        for (int i = 0; i < 6; i++)
            str += alphabet[rand() % 62];
        return str;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string key = longUrl;
        while (mp.find(key) != mp.end())
            key = getRandom();
        mp[longUrl] = key;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));