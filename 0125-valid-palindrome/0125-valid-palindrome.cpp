class Solution {
public:
    bool isPalindrome(string s) {
        string lowercaseS = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c >= 'A' && c <= 'Z') {
                lowercaseS += (c + 32);
            } else {
                lowercaseS += c;
            }
        }

        string filteredS = "";
        for (int i = 0; i < lowercaseS.length(); i++) {
            char c = lowercaseS[i];
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                filteredS += c;
            }
        }

        string reversedS = "";
        for (int i = filteredS.length() - 1; i >= 0; i--) {
            reversedS += filteredS[i];
        }

        if (filteredS.length() != reversedS.length()) {
            return false;
        }

        for (int i = 0; i < filteredS.length(); i++) {
            if (filteredS[i] != reversedS[i]) {
                return false;
            }
        }

        return true;
    }
};