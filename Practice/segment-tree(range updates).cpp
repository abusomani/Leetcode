#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<long> tree, lazy;

void update(int si, long ss, long se, int rs, int re, int val)
{
    if (lazy[si] != 0)
    {
        long dx = lazy[si];
        lazy[si] = 0;
        tree[si] += dx; // because maximum value would only get incremented by dx

        if (ss != se)
            lazy[2 * si + 1] += dx, lazy[2 * si + 2] += dx;
    }

    if (ss > re or se < rs)
        return;
    if (ss >= rs and se <= re) // segment fully in range, update this node and lazy for children
    {
        tree[si] += val;
        if (ss != se)
        {
            lazy[2 * si + 1] += val;
            lazy[2 * si + 2] += val;
        }
    }
    else
    {
        int mid = ss + ((se - ss) >> 1);
        update(2 * si + 1, ss, mid, rs, re, val);
        update(2 * si + 2, mid + 1, se, rs, re, val);
        tree[si] = max(tree[2 * si + 1], tree[2 * si + 2]);
    }
}

long query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si] != 0)
    {
        long dx = lazy[si];
        lazy[si] = 0;
        tree[si] += dx;

        if (ss != se)
            lazy[2 * si + 1] += dx, lazy[2 * si + 2] += dx;
    }
    if (ss > qe or se < qs)
        return LONG_MIN;
    if (ss >= qs and se <= qe) // segment inside query range
        return tree[si];
    else
    {
        int mid = ss + ((se - ss) >> 1);
        long l = query(2 * si + 1, ss, mid, qs, qe);
        long r = query(2 * si + 2, mid + 1, se, qs, qe);
        return max(l, r);
    }
}

long arrayManipulation(int n, vector<vector<int>> queries)
{
    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    for (auto &query : queries)
        update(0, 0, n - 1, query[0] - 1, query[1] - 1, query[2]);

    return query(0, 0, n - 1, 0, n - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++)
    {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
