class Solution {
public:
    int countElements(vector<int>& nums) {
        vector<int> validElements;
        
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            
            vector<int> smallerNumbers;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < currentNumber) {
                    smallerNumbers.push_back(nums[j]);
                }
            }
            
            vector<int> greaterNumbers;
            for (int k = 0; k < nums.size(); k++) {
                if (nums[k] > currentNumber) {
                    greaterNumbers.push_back(nums[k]);
                }
            }
            
            if (smallerNumbers.size() > 0) {
                if (greaterNumbers.size() > 0) {
                    validElements.push_back(1);
                }
            }
        }
        
        int finalCount = 0;
        for (int i = 0; i < validElements.size(); i++) {
            finalCount = finalCount + 1;
        }
        
        return finalCount;
    }
};