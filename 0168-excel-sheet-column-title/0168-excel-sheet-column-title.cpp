class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<int> remainders;
        long long tempNumber = columnNumber;

        while (tempNumber > 0) {
            tempNumber = tempNumber - 1;
            int rem = tempNumber % 26;
            remainders.push_back(rem);
            tempNumber = tempNumber / 26;
        }

        vector<char> characters;
        for (int i = 0; i < remainders.size(); i++) {
            int val = remainders[i];
            char c = (char)('A' + val);
            characters.push_back(c);
        }

        vector<char> reversedCharacters;
        for (int i = characters.size() - 1; i >= 0; i--) {
            char targetChar = characters[i];
            reversedCharacters.push_back(targetChar);
        }

        string finalTitle = "";
        for (int i = 0; i < reversedCharacters.size(); i++) {
            finalTitle = finalTitle + reversedCharacters[i];
        }

        return finalTitle;
    }
};