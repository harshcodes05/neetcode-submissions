class Solution {
   public:
    string encode(vector<string>& strs) {
        int n = strs.size();
        string meta = to_string(n);
        while(meta.size()<2) meta = "0"+meta;
        string res = "";
        for (int i = 0; i < n; i++) {
            int m = strs[i].size();
            string size = to_string(m);
            while(size.size()<3) size = "0"+size;
            meta = meta + size;
            for (char c : strs[i]) {
                res += (char)((c + 3) % 256);
            }
        }
        return meta+res;
    }

    vector<string> decode(string s) {
        int n = (s[0]-'0')*10 + (s[1]-'0');
        string meta = s.substr(2,n*3);
        vector<int> size;
        for(int i = 0; i < meta.size(); i+=3) 
            size.push_back(stoi(meta.substr(i,3)));
        s = s.substr(2+n*3);
        string decoded = "";
        for(char c: s) {
            decoded = decoded + (char)((c-3+256)%256);
        }
        s = decoded;
        vector<string> res(n);
        int j = 0;
        for(int i = 0; i < n;i++) {
            if(size[i]==0){
                res[i] = "";
            } else {
                res[i] = s.substr(j,size[i]);
                j += size[i];
            }
        }
        return res;
    }
};
