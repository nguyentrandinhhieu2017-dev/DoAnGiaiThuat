class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int r = 0; r < n; r++) {
            vector<int> currentRow;
            for (int c = 0; c < n; c++) {
                currentRow.push_back(matrix[r][c]);
            }
            
            for (int i = 0; i < currentRow.size(); i++) {
                for (int j = 0; j < currentRow.size() - 1; j++) {
                    if (currentRow[j] > currentRow[j + 1]) {
                        int temp = currentRow[j];
                        currentRow[j] = currentRow[j + 1];
                        currentRow[j + 1] = temp;
                    }
                }
            }
            
            for (int i = 0; i < currentRow.size(); i++) {
                int expectedValue = i + 1;
                if (currentRow[i] != expectedValue) {
                    return false;
                }
            }
        }
        
        for (int c = 0; c < n; c++) {
            vector<int> currentCol;
            for (int r = 0; r < n; r++) {
                currentCol.push_back(matrix[r][c]);
            }
            
            for (int i = 0; i < currentCol.size(); i++) {
                for (int j = 0; j < currentCol.size() - 1; j++) {
                    if (currentCol[j] > currentCol[j + 1]) {
                        int temp = currentCol[j];
                        currentCol[j] = currentCol[j + 1];
                        currentCol[j + 1] = temp;
                    }
                }
            }
            
            for (int i = 0; i < currentCol.size(); i++) {
                int expectedValue = i + 1;
                if (currentCol[i] != expectedValue) {
                    return false;
                }
            }
        }
        
        return true;
    }
};