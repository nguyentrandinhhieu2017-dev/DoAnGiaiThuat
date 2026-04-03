class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        vector<int> targets;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                targets.push_back(nums[i + 1]);
            }
        }

        vector<int> uniqueTargets;
        for (int i = 0; i < targets.size(); i++) {
            bool exists = false;
            for (int j = 0; j < uniqueTargets.size(); j++) {
                if (targets[i] == uniqueTargets[j]) {
                    exists = true;
                    break;
                }
            }
            if (exists == false) {
                uniqueTargets.push_back(targets[i]);
            }
        }

        vector<int> counts;
        for (int i = 0; i < uniqueTargets.size(); i++) {
            int currentCount = 0;
            for (int j = 0; j < targets.size(); j++) {
                if (targets[j] == uniqueTargets[i]) {
                    currentCount = currentCount + 1;
                }
            }
            counts.push_back(currentCount);
        }

        int maxCount = -1;
        int bestTarget = -1;
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] > maxCount) {
                maxCount = counts[i];
                bestTarget = uniqueTargets[i];
            }
        }

        return bestTarget;
    }
};