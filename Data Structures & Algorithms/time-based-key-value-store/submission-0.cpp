class TimeMap {
    unordered_map<string,vector<pair<int,string>>> t_map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        t_map[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> v(t_map[key].begin(),t_map[key].end());
        int i = 0, j = v.size()-1;
        string value = "";
        while(i<=j) {
            int m = i+(j-i)/2;
            if(v[m].first == timestamp) return v[m].second;
            else if(v[m].first < timestamp) {
                value = v[m].second;
                i = m+1;
            } else j = m-1;
        }
        return value;
    }
};
