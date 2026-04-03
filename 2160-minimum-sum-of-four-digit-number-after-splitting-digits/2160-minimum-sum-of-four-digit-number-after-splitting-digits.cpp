class Solution {
public:
    int minimumSum(int num) {
        string numStr = to_string(num);
        vector<int> digits;
        
        for (int i = 0; i < numStr.length(); i++) {
            char c = numStr[i];
            int digitVal = (int)(c - '0');
            digits.push_back(digitVal);
        }
        
        vector<int> sortedDigits;
        for (int i = 0; i < digits.size(); i++) {
            sortedDigits.push_back(digits[i]);
        }
        
        for (int i = 0; i < sortedDigits.size(); i++) {
            for (int j = 0; j < sortedDigits.size() - 1; j++) {
                if (sortedDigits[j] > sortedDigits[j + 1]) {
                    int swapTemp = sortedDigits[j];
                    sortedDigits[j] = sortedDigits[j + 1];
                    sortedDigits[j + 1] = swapTemp;
                }
            }
        }
        
        string firstPart = "";
        firstPart = firstPart + to_string(sortedDigits[0]);
        firstPart = firstPart + to_string(sortedDigits[2]);
        
        string secondPart = "";
        secondPart = secondPart + to_string(sortedDigits[1]);
        secondPart = secondPart + to_string(sortedDigits[3]);
        
        int num1 = 0;
        for (int i = 0; i < firstPart.length(); i++) {
            int val = (int)(firstPart[i] - '0');
            if (i == 0) {
                num1 = num1 + (val * 10);
            } else {
                num1 = num1 + val;
            }
        }
        
        int num2 = 0;
        for (int i = 0; i < secondPart.length(); i++) {
            int val = (int)(secondPart[i] - '0');
            if (i == 0) {
                num2 = num2 + (val * 10);
            } else {
                num2 = num2 + val;
            }
        }
        
        int finalResult = num1 + num2;
        return finalResult;
    }
};