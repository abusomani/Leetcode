/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    unordered_map<int, Employee*> Employee_Graph;
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importance = 0;
        for(auto employee: employees)
            Employee_Graph[employee->id] = employee;
        
        queue<int> Q;
        Q.push(id);
        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                int id = Q.front(); Q.pop();
                if(!Employee_Graph.count(id))
                    continue;
                importance += Employee_Graph[id]->importance;
                for(auto &i: Employee_Graph[id]->subordinates)
                    Q.push(i);
            }
        }
        return importance;
    }
};