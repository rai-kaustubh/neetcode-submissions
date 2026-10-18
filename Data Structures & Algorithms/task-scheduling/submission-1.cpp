class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        freq.clear();
        for(char task : tasks){
            freq[task]++;
        }

        priority_queue<int> pq;
        int time=0;
        queue<pair<int,int>> q; //freq, time

        for (const auto& [key, val] : freq) {
            pq.push(val);
        }

        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                time = q.front().second;
                pq.push(q.front().first);
                q.pop();
                continue;
            } else{
                int count = pq.top();
                pq.pop();
                count--;
                if(count>0)
                    q.push({count, time+n});
            }

            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
/*
tasks = ["A","A","A","B","C"], n = 3
a-0,5
time=9
minHeap -> 2:1,1:2,1:3

*/
