class Solution {
public:
    string reformatNumber(string number) {
        string digits = "";
        for (char c : number) {
            if (c >= '0' && c <= '9') {
                digits += c;
            }
        }
        
        string res = "";
        int n = digits.length();
        int i = 0;
        
        while (n - i > 4) {
            res += digits.substr(i, 3) + "-";
            i += 3;
        }
        
        if (n - i == 4) {
            res += digits.substr(i, 2) + "-" + digits.substr(i + 2, 2);
        } else {
            res += digits.substr(i);
        }
        
        return res;
    }
}