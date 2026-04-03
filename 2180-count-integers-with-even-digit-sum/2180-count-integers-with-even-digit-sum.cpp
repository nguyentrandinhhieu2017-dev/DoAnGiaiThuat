class Solution {
public:
    int countEven(int num) {
        vector<int> allNumbers;
        for (int i = 1; i <= num; i++) {
            allNumbers.push_back(i);
        }

        vector<string> numberStrings;
        for (int i = 0; i < allNumbers.size(); i++) {
            string s = to_string(allNumbers[i]);
            numberStrings.push_back(s);
        }

        vector<vector<int>> digitsList;
        for (int i = 0; i < numberStrings.size(); i++) {
            string currentStr = numberStrings[i];
            vector<int> digits;
            for (int j = 0; j < currentStr.length(); j++) {
                char c = currentStr[j];
                int digit = (int)(c - '0');
                digits.push_back(digit);
            }
            digitsList.push_back(digits);
        }

        vector<int> sums;
        for (int i = 0; i < digitsList.size(); i++) {
            vector<int> currentDigits = digitsList[i];
            int currentSum = 0;
            for (int j = 0; j < currentDigits.size(); j++) {
                currentSum = currentSum + currentDigits[j];
            }
            sums.push_back(currentSum);
        }

        vector<int> evens;
        for (int i = 0; i < sums.size(); i++) {
            int tempSum = sums[i];
            while (tempSum >= 2) {
                tempSum = tempSum - 2;
            }
            if (tempSum == 0) {
                evens.push_back(1);
            }
        }

        int finalCount = 0;
        for (int i = 0; i < evens.size(); i++) {
            finalCount = finalCount + 1;
        }

        return finalCount;
    }
};