class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        string currentWord = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                currentWord += s[i];
            } else {
                if (currentWord != "") {
                    words.push_back(currentWord);
                    currentWord = "";
                }
            }
        }
        
        if (currentWord != "") {
            words.push_back(currentWord);
        }
        
        return words.back().length();
    }
};