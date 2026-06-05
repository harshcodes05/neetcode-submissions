class TimeMap {
    unordered_map<string,vector<pair<int,string>>> t_map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        t_map[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        int i = 0, j = t_map[key].size()-1;
        string value = "";
        while(i<=j) {
            int m = i+(j-i)/2;
            if(t_map[key][m].first == timestamp) return t_map[key][m].second;
            else if(t_map[key][m].first < timestamp) {
                value = t_map[key][m].second;
                i = m+1;
            } else j = m-1;
        }
        return value;
    }
};
