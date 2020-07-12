bool repeatedSubstringPattern(string str) {
    int n = str.length();
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0 && str.substr(i) == str.substr(0, n - i))
            return true;
    return false;
}