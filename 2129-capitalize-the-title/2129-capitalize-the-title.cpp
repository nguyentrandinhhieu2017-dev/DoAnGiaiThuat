class Solution {
public:
    string capitalizeTitle(string title) {
        vector<vector<char>> allWords;
        vector<char> currentWord;
        
        for (int i = 0; i < title.length(); i++) {
            if (title[i] == ' ') {
                allWords.push_back(currentWord);
                vector<char> emptyWord;
                currentWord = emptyWord;
            } else {
                currentWord.push_back(title[i]);
            }
        }
        allWords.push_back(currentWord);
        
        vector<vector<char>> processedWords;
        
        for (int i = 0; i < allWords.size(); i++) {
            vector<char> w = allWords[i];
            vector<char> modifiedWord;
            
            for (int j = 0; j < w.size(); j++) {
                char c = w[j];
                if (c >= 'A' && c <= 'Z') {
                    char lowerC = (char)((int)c + 32);
                    modifiedWord.push_back(lowerC);
                } else {
                    modifiedWord.push_back(c);
                }
            }
            
            if (modifiedWord.size() > 2) {
                char firstChar = modifiedWord[0];
                if (firstChar >= 'a' && firstChar <= 'z') {
                    char upperChar = (char)((int)firstChar - 32);
                    modifiedWord[0] = upperChar;
                }
            }
            
            processedWords.push_back(modifiedWord);
        }
        
        vector<char> finalChars;
        for (int i = 0; i < processedWords.size(); i++) {
            vector<char> w = processedWords[i];
            for (int j = 0; j < w.size(); j++) {
                finalChars.push_back(w[j]);
            }
            if (i < processedWords.size() - 1) {
                finalChars.push_back(' ');
            }
        }
        
        string finalResult = "";
        for (int i = 0; i < finalChars.size(); i++) {
            finalResult = finalResult + finalChars[i];
        }
        
        return finalResult;
    }
};