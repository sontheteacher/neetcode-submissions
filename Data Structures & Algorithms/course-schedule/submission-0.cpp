class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto pair : prerequisites) {
            indegree[pair[0]] += 1;
            adj[pair[1]].push_back(pair[0]);
        }

        queue<int> starts;
        int courseFound = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0){
                starts.push(i);
                ++courseFound;
            }
        }
        while(!starts.empty()) {
            int curr = starts.front(); starts.pop();
            for (int neighbor : adj[curr]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0) {
                    starts.push(neighbor);
                    ++courseFound;
                }
            }
        }
        return courseFound == numCourses;
    }
};
