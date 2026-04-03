class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<int> copiedNums;
        for (int i = 0; i < nums.size(); i++) {
            copiedNums.push_back(nums[i]);
        }

        vector<int> products;
        for (int i = 0; i < copiedNums.size(); i++) {
            for (int j = i + 1; j < copiedNums.size(); j++) {
                if (copiedNums[i] == copiedNums[j]) {
                    int product = i * j;
                    products.push_back(product);
                }
            }
        }

        vector<int> validPairs;
        for (int i = 0; i < products.size(); i++) {
            int currentProduct = products[i];
            
            int remainder = currentProduct;
            while (remainder >= k) {
                remainder = remainder - k;
            }
            
            if (remainder == 0) {
                validPairs.push_back(1);
            }
        }

        int finalCount = 0;
        for (int i = 0; i < validPairs.size(); i++) {
            finalCount = finalCount + 1;
        }

        return finalCount;
    }
};