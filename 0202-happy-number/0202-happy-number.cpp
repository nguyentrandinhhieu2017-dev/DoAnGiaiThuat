class Solution {
public:
    bool isHappy(int n) {
        vector<int> seenNumbers;
        int currentNumber = n;
        
        while (true) {
            if (currentNumber == 1) {
                return true;
            }
            
            vector<int> digits;
            int temp = currentNumber;
            
            while (temp > 0) {
                int remainder = temp % 10;
                digits.push_back(remainder);
                temp = temp / 10;
            }
            
            int newSum = 0;
            for (int i = 0; i < digits.size(); i++) {
                int digitValue = digits[i];
                int squaredValue = digitValue * digitValue;
                newSum = newSum + squaredValue;
            }
            
            bool isCycleDetected = false;
            for (int i = 0; i < seenNumbers.size(); i++) {
                if (seenNumbers[i] == newSum) {
                    isCycleDetected = true;
                    break;
                }
            }
            
            if (isCycleDetected == true) {
                return false;
            } else {
                seenNumbers.push_back(newSum);
                currentNumber = newSum;
            }
        }
        
        return false;
    }
};