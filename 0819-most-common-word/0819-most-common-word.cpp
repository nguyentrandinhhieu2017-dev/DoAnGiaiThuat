class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string uniqueWords[1000];
        int wordCounts[1000] = {0};
        int uniqueCount = 0;
        
        string currentWord = "";
        int n = paragraph.length();
        
        for (int i = 0; i <= n; i++) {
            char c = i < n ? paragraph[i] : ' ';
            
            if (c >= 'A' && c <= 'Z') {
                currentWord += (c - 'A' + 'a');
            } else if (c >= 'a' && c <= 'z') {
                currentWord += c;
            } else {
                if (currentWord.length() > 0) {
                    bool isBanned = false;
                    for (int j = 0; j < banned.size(); j++) {
                        if (currentWord == banned[j]) {
                            isBanned = true;
                            break;
                        }
                    }
                    
                    if (!isBanned) {
                        bool found = false;
                        for (int j = 0; j < uniqueCount; j++) {
                            if (uniqueWords[j] == currentWord) {
                                wordCounts[j]++;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            uniqueWords[uniqueCount] = currentWord;
                            wordCounts[uniqueCount] = 1;
                            uniqueCount++;
                        }
                    }
                    currentWord = "";
                }
            }
        }
        
        int maxCount = 0;
        string result = "";
        for (int i = 0; i < uniqueCount; i++) {
            if (wordCounts[i] > maxCount) {
                maxCount = wordCounts[i];
                result = uniqueWords[i];
            }
        }
        
        return result;
    }
};