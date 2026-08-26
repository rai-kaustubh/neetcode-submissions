class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // indegrees vector, vector<vector<int>> adj(numcourses)
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        // convert preqs to adj list; while doing so do indegree[preq[0]]++;

        for(auto vec: prerequisites){
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }
        
        queue<int> q;
        // iterate over indegree and add course with indegree==0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int finish=0;
        vector<int> list;
        while(!q.empty()){
            int top = q.front();
            list.push_back(top);
            finish++;
            q.pop();

            for(auto course: adj[top]){
                indegree[course]--;
                if(indegree[course]==0){
                    q.push(course);
                }
            }
        }

        if(finish==numCourses){
            return list;
        }

        return {};
        
    }
};
