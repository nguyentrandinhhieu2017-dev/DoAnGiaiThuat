class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> uniqueNums;
        
        for (int i = 0; i < nums.size(); i++) {
            if (uniqueNums.size() == 0) {
                uniqueNums.push_back(nums[i]);
            } else {
                int lastAddedIndex = uniqueNums.size() - 1;
                int lastAddedValue = uniqueNums[lastAddedIndex];
                if (nums[i] != lastAddedValue) {
                    uniqueNums.push_back(nums[i]);
                }
            }
        }

        vector<int> hills;
        for (int i = 1; i < uniqueNums.size() - 1; i++) {
            int leftNeighbor = uniqueNums[i - 1];
            int currentVal = uniqueNums[i];
            int rightNeighbor = uniqueNums[i + 1];

            if (currentVal > leftNeighbor) {
                if (currentVal > rightNeighbor) {
                    hills.push_back(1);
                } else {
                    hills.push_back(0);
                }
            } else {
                hills.push_back(0);
            }
        }

        vector<int> valleys;
        for (int i = 1; i < uniqueNums.size() - 1; i++) {
            int leftNeighbor = uniqueNums[i - 1];
            int currentVal = uniqueNums[i];
            int rightNeighbor = uniqueNums[i + 1];

            if (currentVal < leftNeighbor) {
                if (currentVal < rightNeighbor) {
                    valleys.push_back(1);
                } else {
                    valleys.push_back(0);
                }
            } else {
                valleys.push_back(0);
            }
        }

        int totalHills = 0;
        for (int i = 0; i < hills.size(); i++) {
            if (hills[i] == 1) {
                totalHills = totalHills + 1;
            }
        }

        int totalValleys = 0;
        for (int i = 0; i < valleys.size(); i++) {
            if (valleys[i] == 1) {
                totalValleys = totalValleys + 1;
            }
        }

        int finalResult = totalHills + totalValleys;
        return finalResult;
    }
};