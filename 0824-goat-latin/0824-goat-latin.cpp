class Solution {
public:
    string toGoatLatin(string sentence) {
        string res = "";
        int n = sentence.length();
        int wordCount = 1;
        
        for (int i = 0; i < n; i++) {
            int start = i;
            while (i < n && sentence[i] != ' ') {
                i++;
            }
            
            char first = sentence[start];
            bool isVowel = (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u' ||
                            first == 'A' || first == 'E' || first == 'I' || first == 'O' || first == 'U');
            
            if (isVowel) {
                for (int j = start; j < i; j++) {
                    res += sentence[j];
                }
            } else {
                for (int j = start + 1; j < i; j++) {
                    res += sentence[j];
                }
                res += first;
            }
            
            res += "ma";
            for (int j = 0; j < wordCount; j++) {
                res += 'a';
            }
            
            if (i < n) {
                res += " ";
            }
            wordCount++;
        }
        
        return res;
    }
};