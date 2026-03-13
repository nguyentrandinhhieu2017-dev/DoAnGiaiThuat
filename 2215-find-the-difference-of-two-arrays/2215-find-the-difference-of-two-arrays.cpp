class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> uniqueNums1;
        for (int i = 0; i < nums1.size(); i++) {
            bool alreadyExists = false;
            for (int j = 0; j < uniqueNums1.size(); j++) {
                if (nums1[i] == uniqueNums1[j]) {
                    alreadyExists = true;
                    break;
                }
            }
            if (alreadyExists == false) {
                uniqueNums1.push_back(nums1[i]);
            }
        }

        vector<int> uniqueNums2;
        for (int i = 0; i < nums2.size(); i++) {
            bool alreadyExists = false;
            for (int j = 0; j < uniqueNums2.size(); j++) {
                if (nums2[i] == uniqueNums2[j]) {
                    alreadyExists = true;
                    break;
                }
            }
            if (alreadyExists == false) {
                uniqueNums2.push_back(nums2[i]);
            }
        }

        vector<int> answer0;
        for (int i = 0; i < uniqueNums1.size(); i++) {
            bool foundInNums2 = false;
            for (int j = 0; j < nums2.size(); j++) {
                if (uniqueNums1[i] == nums2[j]) {
                    foundInNums2 = true;
                    break;
                }
            }
            if (foundInNums2 == false) {
                answer0.push_back(uniqueNums1[i]);
            }
        }

        vector<int> answer1;
        for (int i = 0; i < uniqueNums2.size(); i++) {
            bool foundInNums1 = false;
            for (int j = 0; j < nums1.size(); j++) {
                if (uniqueNums2[i] == nums1[j]) {
                    foundInNums1 = true;
                    break;
                }
            }
            if (foundInNums1 == false) {
                answer1.push_back(uniqueNums2[i]);
            }
        }

        vector<vector<int>> finalResult;
        finalResult.push_back(answer0);
        finalResult.push_back(answer1);

        return finalResult;
    }
};