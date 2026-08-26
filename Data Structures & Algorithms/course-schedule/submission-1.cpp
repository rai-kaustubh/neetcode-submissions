class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        // make an adj list
        //count indegrees for all the vertices
        vector<vector<int>> adj(numCourses);
        for(auto vec: prerequisites){
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }

        //iterate over the indegrees vec and push to q if indegree[i]==0
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int finish=0;
        while(!q.empty()){
            finish++;
            int top = q.front();
            q.pop();
            for(int nbor:adj[top]){
                indegree[nbor]--;
                if(indegree[nbor]==0){
                    q.push(nbor);
                }
            }
        }

        return finish==numCourses;

    }
};
