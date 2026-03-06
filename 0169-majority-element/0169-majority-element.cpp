class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> sortedCopy;
        for (int i = 0; i < n; i++) {
            sortedCopy.push_back(nums[i]);
        }

        sort(sortedCopy.begin(), sortedCopy.end());

        vector<int> distinctElements;
        vector<int> elementCounts;

        if (sortedCopy.size() > 0) {
            distinctElements.push_back(sortedCopy[0]);
            elementCounts.push_back(1);
        }

        for (int i = 1; i < sortedCopy.size(); i++) {
            if (sortedCopy[i] == sortedCopy[i - 1]) {
                int lastIndex = elementCounts.size() - 1;
                elementCounts[lastIndex] = elementCounts[lastIndex] + 1;
            } else {
                distinctElements.push_back(sortedCopy[i]);
                elementCounts.push_back(1);
            }
        }

        int majorityThreshold = n / 2;
        int resultCandidate = 0;

        for (int i = 0; i < elementCounts.size(); i++) {
            int currentCount = elementCounts[i];
            if (currentCount > majorityThreshold) {
                resultCandidate = distinctElements[i];
                break;
            }
        }

        return resultCandidate;
    }
};