class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        string res = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && (s.length() - i) % 3 == 0) {
                res += ".";
            }
            res += s[i];
        }
        
        return res;
    }
};