class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i = 0; i < position.size(); i++) {
            arr.push_back(make_pair(position[i], speed[i]));
        }
        sort(arr.begin(), arr.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });
        stack<double> st;
        vector<double> times;
        for(int i = 0; i < position.size(); i++) {
            double time = (double)(target - arr[i].first)/arr[i].second;
            times.push_back(time);
            if(st.empty() || time > st.top()) 
                st.push(time);
        }
        return st.size();
    }
};
