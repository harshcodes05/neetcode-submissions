class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> Follows;
    unordered_map<int, vector<pair<int,int>>> Tweets;
public:
    Twitter() : time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
       Tweets[userId].push_back(make_pair(time++, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxH;
        for(auto& tweet: Tweets[userId]) maxH.push(tweet);
        for(auto& follower: Follows[userId]) {
            for(auto& tweet: Tweets[follower])
                maxH.push(tweet);
        }
        vector<int> res;
        while(!maxH.empty() && res.size()<10)  {
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        Follows[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if(Follows[followerId].count(followeeId))
            Follows[followerId].erase(followeeId);
    }
};