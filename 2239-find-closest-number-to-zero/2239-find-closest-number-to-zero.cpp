class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        vector<int> distances;
        
        for (int i = 0; i < nums.size(); i++) {
            int currentValue = nums[i];
            if (currentValue < 0) {
                int positiveValue = -currentValue;
                distances.push_back(positiveValue);
            } else {
                distances.push_back(currentValue);
            }
        }
        
        int minDistance = distances[0];
        for (int i = 1; i < distances.size(); i++) {
            if (distances[i] < minDistance) {
                minDistance = distances[i];
            }
        }
        
        vector<int> candidates;
        for (int i = 0; i < nums.size(); i++) {
            int originalValue = nums[i];
            int absoluteValue = originalValue;
            
            if (absoluteValue < 0) {
                absoluteValue = -absoluteValue;
            }
            
            if (absoluteValue == minDistance) {
                candidates.push_back(originalValue);
            }
        }
        
        int bestResult = candidates[0];
        for (int i = 1; i < candidates.size(); i++) {
            if (candidates[i] > bestResult) {
                bestResult = candidates[i];
            }
        }
        
        return bestResult;
    }
};