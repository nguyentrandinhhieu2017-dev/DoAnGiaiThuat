class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int sums[40000];
        int idx = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sums[idx++] = nums1[i] + nums2[j];
            }
        }
        
        sort(sums, sums + idx);
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int target = -(nums3[i] + nums4[j]);
                
                int l = 0, r = idx;
                while (l < r) {
                    int m = l + (r - l) / 2;
                    if (sums[m] < target) l = m + 1;
                    else r = m;
                }
                
                int start = l;
                if (start < idx && sums[start] == target) {
                    l = start;
                    r = idx;
                    while (l < r) {
                        int m = l + (r - l) / 2;
                        if (sums[m] <= target) l = m + 1;
                        else r = m;
                    }
                    count += (l - start);
                }
            }
        }
        
        return count;
    }
};