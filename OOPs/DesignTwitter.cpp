// https://leetcode.com/problems/design-twitter/


class Twitter {
private:
     unordered_map<int, unordered_set<int>> fo;
     unordered_map<int, vector<pair<int,int>>> t;
     long long time;
    
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap;
        vector<int> res;
        for(auto it = t[userId].begin(); it != t[userId].end(); it++)
            maxHeap.push(*it);
        for(auto it = fo[userId].begin(); it != fo[userId].end(); it++) {
            int user = *it;
            for(auto it2 = t[user].begin(); it2 != t[user].end(); it2++)
                maxHeap.push(*it2);
        }
        while(maxHeap.size() > 0) {
            res.push_back(maxHeap.top().second);
            if(res.size() == 10) break;
            maxHeap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(fo[followerId].find(followeeId) != fo[followerId].end())
            fo[followerId].erase(followeeId);
    }
};

//  https://www.youtube.com/watch?v=6je5osXSwOU

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
