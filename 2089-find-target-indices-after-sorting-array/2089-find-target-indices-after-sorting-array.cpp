class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> copiedNums;
        for (int i = 0; i < nums.size(); i++) {
            copiedNums.push_back(nums[i]);
        }
        
        for (int i = 0; i < copiedNums.size(); i++) {
            for (int j = 0; j < copiedNums.size() - 1; j++) {
                if (copiedNums[j] > copiedNums[j + 1]) {
                    int temp = copiedNums[j];
                    copiedNums[j] = copiedNums[j + 1];
                    copiedNums[j + 1] = temp;
                }
            }
        }
        
        vector<int> foundIndices;
        for (int i = 0; i < copiedNums.size(); i++) {
            int currentNumber = copiedNums[i];
            if (currentNumber == target) {
                foundIndices.push_back(i);
            }
        }
        
        vector<int> finalResult;
        for (int i = 0; i < foundIndices.size(); i++) {
            finalResult.push_back(foundIndices[i]);
        }
        
        return finalResult;
    }
};