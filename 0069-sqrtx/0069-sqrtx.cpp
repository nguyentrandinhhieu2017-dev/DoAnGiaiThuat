class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        
        if (x == 1) {
            return 1;
        }
        
        vector<long long> sumHistory;
        long long currentSum = 0;
        long long oddNumber = 1;
        int rootValue = 0;
        
        while (true) {
            currentSum = currentSum + oddNumber;
            sumHistory.push_back(currentSum);
            
            if (currentSum == x) {
                rootValue = rootValue + 1;
                break;
            } else if (currentSum > x) {
                break;
            } else {
                oddNumber = oddNumber + 2;
                rootValue = rootValue + 1;
            }
        }
        
        return rootValue;
    }
};