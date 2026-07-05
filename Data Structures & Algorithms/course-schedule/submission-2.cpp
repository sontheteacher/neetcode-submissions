class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> indegree(numCourses, 0);
       vector<vector<int>> adjList(numCourses);
       for (const auto& pairs : prerequisites) {
            ++indegree[pairs[0]];
            adjList[pairs[1]].push_back(pairs[0]);
       }

       queue<int> q;
       int courseFound = 0;

       for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                courseFound++;
            }
       }

       while (!q.empty()) {
            int curr = q.front(); q.pop();
            
            for (int nei : adjList[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                    courseFound++;
                }
            }
       }

       return courseFound == numCourses;
    }
};
