class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        vector<string> copiedWords;
        for (int i = 0; i < words.size(); i++) {
            copiedWords.push_back(words[i]);
        }

        vector<char> prefixChars;
        for (int i = 0; i < pref.length(); i++) {
            prefixChars.push_back(pref[i]);
        }

        vector<int> matchResults;

        for (int i = 0; i < copiedWords.size(); i++) {
            string currentWord = copiedWords[i];
            vector<char> wordChars;
            
            for (int j = 0; j < currentWord.length(); j++) {
                wordChars.push_back(currentWord[j]);
            }

            if (wordChars.size() < prefixChars.size()) {
                matchResults.push_back(0);
            } else {
                bool isMatch = true;
                for (int k = 0; k < prefixChars.size(); k++) {
                    if (wordChars[k] != prefixChars[k]) {
                        isMatch = false;
                    }
                }
                
                if (isMatch == true) {
                    matchResults.push_back(1);
                } else {
                    matchResults.push_back(0);
                }
            }
        }

        int finalCount = 0;
        for (int i = 0; i < matchResults.size(); i++) {
            if (matchResults[i] == 1) {
                finalCount = finalCount + 1;
            }
        }

        return finalCount;
    }
};