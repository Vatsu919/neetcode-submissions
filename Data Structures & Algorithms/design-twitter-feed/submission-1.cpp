class Twitter {
public:
    unordered_map<int, set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> post;
    int count;
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        post[userId].push_back({count, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int it:followers[userId]) {
            for(pair<int,int> pr:post[it]) {
                pq.push({pr.first, pr.second});
                if(pq.size()>10)pq.pop();
            }
        }
        if(followers[userId].find(userId)==followers[userId].end()) {
            for(pair<int,int> pr:post[userId]) {
            pq.push({pr.first,pr.second});
            if(pq.size()>10)pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
