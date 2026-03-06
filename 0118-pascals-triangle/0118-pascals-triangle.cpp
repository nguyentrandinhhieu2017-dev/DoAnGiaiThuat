class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        if (numRows >= 1) {
            vector<int> row1;
            row1.push_back(1);
            result.push_back(row1);
        }
        
        if (numRows >= 2) {
            vector<int> row2;
            row2.push_back(1);
            row2.push_back(1);
            result.push_back(row2);
        }
        
        int currentRowIndex = 3;
        
        while (currentRowIndex <= numRows) {
            vector<int> previousRow;
            int prevIndex = currentRowIndex - 1 - 1;
            
            for (int i = 0; i < result[prevIndex].size(); i++) {
                previousRow.push_back(result[prevIndex][i]);
            }
            
            vector<int> newRow;
            newRow.push_back(1);
            
            for (int i = 0; i < previousRow.size() - 1; i++) {
                int leftValue = previousRow[i];
                int rightValue = previousRow[i + 1];
                int sumValue = leftValue + rightValue;
                newRow.push_back(sumValue);
            }
            
            newRow.push_back(1);
            
            result.push_back(newRow);
            
            currentRowIndex = currentRowIndex + 1;
        }
        
        return result;
    }
};