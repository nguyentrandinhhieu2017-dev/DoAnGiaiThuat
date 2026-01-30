class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res = "";
        int n = s.length();
        int cycle = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycle) {
                res += s[j + i];
                if (i != 0 && i != numRows - 1) {
                    int k = j + cycle - i;
                    if (k < n) res += s[k];
                }
            }
        }
        return res;
    }
};