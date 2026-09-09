class Twitter {
public:
    Twitter(): timer(0) {}
    
    void postTweet(int userId, int tweetId) {
        timer++;
        this->tweets[userId].push_back({timer, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap; // (time, tweetId)

        // Function
        auto addUser = [&](int uid) {
            if (!tweets.count(uid)) return;
            auto& v = tweets[uid];
            int start = max(0, (int)v.size() - 10);
            for (int i = start; i < (int)v.size(); i++)
                maxHeap.push(v[i]);
        };

        addUser(userId);
        if (following.count(userId))
        for (int f : following[userId]) addUser(f);

        vector<int> result;
        while (!maxHeap.empty() && result.size() < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            this->following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (this->following.count(followerId))
            this->following[followerId].erase(followeeId);
    }
private:
    int timer;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, set<int>> following;
};
