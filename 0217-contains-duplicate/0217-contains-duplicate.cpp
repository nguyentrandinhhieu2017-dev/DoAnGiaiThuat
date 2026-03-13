class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }

        vector<int> sortedNums;
        for (int i = 0; i < nums.size(); i++) {
            int currentValue = nums[i];
            sortedNums.push_back(currentValue);
        }

        sort(sortedNums.begin(), sortedNums.end());

        vector<long long> differences;
        for (int i = 1; i < sortedNums.size(); i++) {
            long long prevValue = sortedNums[i - 1];
            long long currValue = sortedNums[i];
            long long diff = currValue - prevValue;
            differences.push_back(diff);
        }

        bool hasDuplicate = false;
        for (int i = 0; i < differences.size(); i++) {
            if (differences[i] == 0) {
                hasDuplicate = true;
                break;
            }
        }

        return hasDuplicate;
    }
};