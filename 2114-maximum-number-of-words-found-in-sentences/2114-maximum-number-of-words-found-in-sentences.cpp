class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        vector<int> wordCounts;

        for (int i = 0; i < sentences.size(); i++) {
            string currentSentence = sentences[i];
            vector<vector<char>> wordsInSentence;
            vector<char> currentWord;

            for (int j = 0; j < currentSentence.length(); j++) {
                if (currentSentence[j] == ' ') {
                    wordsInSentence.push_back(currentWord);
                    vector<char> emptyWord;
                    currentWord = emptyWord;
                } else {
                    currentWord.push_back(currentSentence[j]);
                }
            }
            wordsInSentence.push_back(currentWord);

            int currentCount = 0;
            for (int k = 0; k < wordsInSentence.size(); k++) {
                currentCount = currentCount + 1;
            }
            
            wordCounts.push_back(currentCount);
        }

        int maxWords = -1;
        for (int i = 0; i < wordCounts.size(); i++) {
            if (wordCounts[i] > maxWords) {
                maxWords = wordCounts[i];
            }
        }

        return maxWords;
    }
};