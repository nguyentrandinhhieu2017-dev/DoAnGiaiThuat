class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int counts[26] = {0};
        for (char c : s) {
            counts[c - 'a']++;
        }

        int targetFreq = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0) {
                if (targetFreq == 0) {
                    targetFreq = counts[i];
                } else if (counts[i] != targetFreq) {
                    return false;
                }
            }
        }
        return true;
    }
};