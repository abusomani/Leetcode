/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
private:
    unordered_map<int, pair<int, vector<int>>> graph;

public:
    int dfs(int id)
    {
        int sum = graph[id].first;
        for (auto &next : graph[id].second)
            sum += dfs(next);
        return sum;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto &employee : employees)
        {
            int id = employee->id;
            graph[id] = {employee->importance, employee->subordinates};
        }

        return dfs(id);
    }
};