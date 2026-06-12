class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for(auto i : prerequisites) {
            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int c = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            c++;

            for(int neigh : adj[u]) {
                indegree[neigh]--;

                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return c == numCourses;
    }
};