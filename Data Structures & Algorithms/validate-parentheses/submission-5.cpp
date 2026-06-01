class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == '}' || s[0]==']') return false;
        stack<char> st;
        for(char c: s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            if(c == ')' || c == '}' || c==']') {
                if(st.empty()) return false;
                else if(c == ')' && st.top() != '(') return false;
                else if(c == '}' && st.top() != '{') return false;
                else if(c == ']' && st.top() != '[') return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
