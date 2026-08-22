class Solution {
private:
    void dfs(string s, vector<string>& res, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj) {
        while(!adj[s].empty()) {
            string st = adj[s].top();
            adj[s].pop();
            dfs(st, res, adj);
        }
        res.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto iter: tickets) {
            adj[iter[0]].push(iter[1]);
        }
        vector<string> res;
        dfs("JFK", res, adj);
        reverse(res.begin(),res.end());
        return res;
    }
};
