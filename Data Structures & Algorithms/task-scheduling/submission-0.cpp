class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        for(auto task: tasks){
            count[task]++;
        }

        priority_queue<int> pq ;//maxHeap;

        for(auto task: count){
            pq.push(task.second);
        }

        int time =0;
        queue<pair<int, int>> q;//#left, time
        
        while(!q.empty() || !pq.empty()){
            time++;
            
            //if pq is empty and q has elelments, set time to q.front.time
            if(pq.empty() && !q.empty()){
                time = q.front().second;
            }

            // check if any element in q can be executed
            if(!q.empty() && q.front().second<=time){
                pq.push(q.front().first);
                q.pop();
            }

            //if pq is non empty, execute the pq.front
               // insert (non zero) pq.front into q with time of next execution
            
            if(!pq.empty()){
                int top = pq.top();
                pq.pop();
                
                top--;
                if(top>0){
                    q.push({top, time+n+1});
                }

            }
        }

        return time;
    }
};
