class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int currentOnes = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentOnes++;
                if (currentOnes > maxOnes) {
                    maxOnes = currentOnes;
                }
            } else {
                currentOnes = 0;
            }
        }
        
        return maxOnes;
    }
};