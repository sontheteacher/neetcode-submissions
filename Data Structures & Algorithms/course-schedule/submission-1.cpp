class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto& pairs : prerequisites) {
            int a = pairs[0], b = pairs[1];
            indegree[a]++;
            adj[b].push_back(a);
        }

        queue<int> starts;
        int courseFound = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                starts.push(i);
                courseFound++;
            }
        }

        while (!starts.empty()) {
            int curr = starts.front(); starts.pop();
            for (int nei : adj[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    starts.push(nei);
                    courseFound++;
                }
            }
        }

        return courseFound == numCourses;
    }
};
