class Twitter {
public:
    unordered_map<int, vector<vector<int>>> tweets; // userId -> {time, tweetId}
    unordered_map<int, unordered_set<int>> followees;
    int time =1;

    Twitter() {
        tweets.clear();
        followees.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans = {};
        priority_queue<vector<int>, vector<vector<int>>> pq; //time, tweetId, index, userId

        if(tweets[userId].size()>0)
            pq.push({tweets[userId].back()[0], tweets[userId].back()[1], (int)tweets[userId].size()-1, userId});
        
        for(auto followee: followees[userId]){
            if(tweets[followee].size()>0)
                pq.push({tweets[followee].back()[0], tweets[followee].back()[1], (int)tweets[followee].size()-1, followee});
        }

        while(ans.size()<10 && !pq.empty()){
            auto top = pq.top();
            int time = top[0]; 
            int tweetId = top[1]; 
            int index = top[2]; 
            int userId = top[3];
            pq.pop();

            ans.push_back(tweetId);
            if(index>0){
                pq.push({tweets[userId][index-1][0], tweets[userId][index-1][1], index-1, userId});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
/*
    followerMap followeeID -> followerId[]
    tweets-> map[userId]-> pair<tweetId, time>

    1->(10,1)
    2->(20,2)

    1->2





*/