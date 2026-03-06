class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> sortedNums;
        for (int i = 0; i < n; i++) {
            sortedNums.push_back(nums[i]);
        }

        sort(sortedNums.begin(), sortedNums.end());

        vector<bool> hasPair(n, false);

        for (int i = 0; i < n; i++) {
            if (hasPair[i] == true) {
                continue;
            }

            bool found = false;
            for (int j = i + 1; j < n; j++) {
                if (hasPair[j] == false && sortedNums[i] == sortedNums[j]) {
                    hasPair[i] = true;
                    hasPair[j] = true;
                    found = true;
                    break;
                }
            }

            if (found == false) {
                return sortedNums[i];
            }
        }

        return -1;
    }
};