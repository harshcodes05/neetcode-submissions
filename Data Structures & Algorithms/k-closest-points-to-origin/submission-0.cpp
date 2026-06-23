class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxH;
        for(int i = 0; i < points.size(); i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxH.push(make_pair(dist, i));
            if(maxH.size() > k) maxH.pop();
        }
        vector<vector<int>> ans;
        while(!maxH.empty()) {
            ans.push_back(points[maxH.top().second]);
            maxH.pop();
        }
        return ans;
    }
};
