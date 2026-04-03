class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evens;
        vector<int> odds;

        for (int i = 0; i < nums.size(); i++) {
            int tempIndex = i;
            while (tempIndex >= 2) {
                tempIndex = tempIndex - 2;
            }
            if (tempIndex == 0) {
                evens.push_back(nums[i]);
            } else {
                odds.push_back(nums[i]);
            }
        }

        for (int i = 0; i < evens.size(); i++) {
            for (int j = 0; j < evens.size() - 1; j++) {
                if (evens[j] > evens[j + 1]) {
                    int swapTemp = evens[j];
                    evens[j] = evens[j + 1];
                    evens[j + 1] = swapTemp;
                }
            }
        }

        for (int i = 0; i < odds.size(); i++) {
            for (int j = 0; j < odds.size() - 1; j++) {
                if (odds[j] < odds[j + 1]) {
                    int swapTemp = odds[j];
                    odds[j] = odds[j + 1];
                    odds[j + 1] = swapTemp;
                }
            }
        }

        vector<int> finalSortedArray;
        int currentEvenIndex = 0;
        int currentOddIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            int tempIndex = i;
            while (tempIndex >= 2) {
                tempIndex = tempIndex - 2;
            }
            if (tempIndex == 0) {
                finalSortedArray.push_back(evens[currentEvenIndex]);
                currentEvenIndex = currentEvenIndex + 1;
            } else {
                finalSortedArray.push_back(odds[currentOddIndex]);
                currentOddIndex = currentOddIndex + 1;
            }
        }

        return finalSortedArray;
    }
};