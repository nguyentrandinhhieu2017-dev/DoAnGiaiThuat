class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int currentNumberToCheck = 1;
        
        while (currentNumberToCheck <= 500) {
            int appearanceCount = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == currentNumberToCheck) {
                    appearanceCount = appearanceCount + 1;
                }
            }
            
            int tempCount = appearanceCount;
            while (tempCount >= 2) {
                tempCount = tempCount - 2;
            }
            
            if (tempCount != 0) {
                return false;
            }
            
            currentNumberToCheck = currentNumberToCheck + 1;
        }
        
        return true;
    }
};