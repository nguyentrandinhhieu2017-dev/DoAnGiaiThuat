class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int currentTarget = original;
        
        while (true) {
            vector<int> currentSearchSpace;
            for (int i = 0; i < nums.size(); i++) {
                currentSearchSpace.push_back(nums[i]);
            }
            
            bool isTargetFound = false;
            for (int i = 0; i < currentSearchSpace.size(); i++) {
                if (currentSearchSpace[i] == currentTarget) {
                    isTargetFound = true;
                    break;
                }
            }
            
            if (isTargetFound == true) {
                int nextTarget = 0;
                for (int j = 0; j < 2; j++) {
                    nextTarget = nextTarget + currentTarget;
                }
                currentTarget = nextTarget;
            } else {
                break;
            }
        }
        
        return currentTarget;
    }
};