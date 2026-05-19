class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<=j) {
            while(!isalnum(s[i]) && i<s.size()) i++;
            while(!isalnum(s[j]) && j>i) j--;
            if(i<s.size() && i <= j && tolower(s[i]) != tolower(s[j])) return false;
            i++,j--;            
        }
        return true;
    }
};
