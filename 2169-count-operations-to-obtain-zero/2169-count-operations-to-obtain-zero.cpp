class Solution {
public:
    int countOperations(int num1, int num2) {
        vector<int> history1;
        vector<int> history2;
        
        int current1 = num1;
        int current2 = num2;
        
        while (current1 > 0 && current2 > 0) {
            history1.push_back(current1);
            history2.push_back(current2);
            
            if (current1 >= current2) {
                int next1 = current1 - current2;
                current1 = next1;
            } else {
                int next2 = current2 - current1;
                current2 = next2;
            }
        }
        
        vector<int> operationCounts;
        for (int i = 0; i < history1.size(); i++) {
            operationCounts.push_back(1);
        }
        
        int totalOperations = 0;
        for (int i = 0; i < operationCounts.size(); i++) {
            totalOperations = totalOperations + operationCounts[i];
        }
        
        return totalOperations;
    }
};