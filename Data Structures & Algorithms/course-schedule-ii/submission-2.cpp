class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);

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

        vector<int> list;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);

            for(auto i: adj[top]){
                indegrees[i]--;
                if(!indegrees[i]){
                    q.push(i);
                }
            }
        }

        if(list.size()==numCourses){
            return list;
        }

        return {};

    }
};
