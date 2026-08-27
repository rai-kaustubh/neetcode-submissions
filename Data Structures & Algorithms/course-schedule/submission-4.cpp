class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses,0);
        for(auto vec: prerequisites){
            adj[vec[1]].push_back(vec[0]);
            indegrees[vec[0]]++;
        }

        queue<int> q;
        for(auto i=0;i<numCourses;i++){
            if(!indegrees[i]){
                q.push(i);
            }
        }

        int finish=0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            finish++;
            
            for(auto i: adj[top]){
                indegrees[i]--;
                if(!indegrees[i])
                    q.push(i);
            }
        }

        return finish==numCourses;
    }
};
