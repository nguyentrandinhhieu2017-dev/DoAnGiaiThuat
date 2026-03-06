class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> currentRow;
            
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    currentRow.push_back(1);
                } else if (j == i) {
                    currentRow.push_back(1);
                } else {
                    vector<int> previousRow = triangle[i - 1];
                    int value1 = previousRow[j - 1];
                    int value2 = previousRow[j];
                    int sumValue = value1 + value2;
                    currentRow.push_back(sumValue);
                }
            }
            
            triangle.push_back(currentRow);
        }
        
        vector<int> finalResult;
        vector<int> targetRow = triangle[rowIndex];
        
        for (int i = 0; i < targetRow.size(); i++) {
            int val = targetRow[i];
            finalResult.push_back(val);
        }
        
        return finalResult;
    }
};