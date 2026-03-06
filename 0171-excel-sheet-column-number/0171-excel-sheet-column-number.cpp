class Solution {
public:
    int titleToNumber(string columnTitle) {
        vector<int> charValues;
        
        for (int i = 0; i < columnTitle.length(); i++) {
            char c = columnTitle[i];
            int val = (int)(c - 'A' + 1);
            charValues.push_back(val);
        }
        
        vector<long long> positionalValues;
        int n = charValues.size();
        
        for (int i = 0; i < n; i++) {
            int exponent = n - 1 - i;
            long long powerOf26 = 1;
            
            for (int j = 0; j < exponent; j++) {
                powerOf26 = powerOf26 * 26;
            }
            
            long long currentPosValue = (long long)charValues[i] * powerOf26;
            positionalValues.push_back(currentPosValue);
        }
        
        long long totalSum = 0;
        for (int k = 0; k < positionalValues.size(); k++) {
            totalSum = totalSum + positionalValues[k];
        }
        
        int finalResult = (int)totalSum;
        return finalResult;
    }
};