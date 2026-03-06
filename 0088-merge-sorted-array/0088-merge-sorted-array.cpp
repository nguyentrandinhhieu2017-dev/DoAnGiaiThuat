class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1;
        for (int i = 0; i < m; i++) {
            temp1.push_back(nums1[i]);
        }
        
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            temp2.push_back(nums2[i]);
        }
        
        vector<int> mergedArray;
        int ptr1 = 0;
        int ptr2 = 0;
        
        while (ptr1 < m && ptr2 < n) {
            if (temp1[ptr1] <= temp2[ptr2]) {
                mergedArray.push_back(temp1[ptr1]);
                ptr1 = ptr1 + 1;
            } else {
                mergedArray.push_back(temp2[ptr2]);
                ptr2 = ptr2 + 1;
            }
        }
        
        while (ptr1 < m) {
            mergedArray.push_back(temp1[ptr1]);
            ptr1 = ptr1 + 1;
        }
        
        while (ptr2 < n) {
            mergedArray.push_back(temp2[ptr2]);
            ptr2 = ptr2 + 1;
        }
        
        for (int i = 0; i < mergedArray.size(); i++) {
            nums1[i] = mergedArray[i];
        }
    }
};