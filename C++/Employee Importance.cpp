/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
        for(auto x: employees) map[x->id] = x;
        
        int import = 0;
        queue<int> q;
        q.push(id);
        
        while(q.size()){
            id = q.front(); q.pop();
            
            import += map[id]->importance;
            for(auto x: map[id]->subordinates) {
                q.push(x);
            }
        }
        
        return import;
    }
};
