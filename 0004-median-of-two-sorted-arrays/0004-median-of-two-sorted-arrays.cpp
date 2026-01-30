class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        while (low <= high) {
            int px = (low + high) / 2;
            int py = (m + n + 1) / 2 - px;
            long maxLx = (px == 0) ? -2147483648L : nums1[px - 1];
            long minRx = (px == m) ? 2147483647L : nums1[px];
            long maxLy = (py == 0) ? -2147483648L : nums2[py - 1];
            long minRy = (py == n) ? 2147483647L : nums2[py];
            if (maxLx <= minRy && maxLy <= minRx) {
                long maxL = (maxLx > maxLy) ? maxLx : maxLy;
                long minR = (minRx < minRy) ? minRx : minRy;
                if ((m + n) % 2 == 0) return (double)(maxL + minR) / 2.0;
                else return (double)maxL;
            } else if (maxLx > minRy) high = px - 1;
            else low = px + 1;
        }
        return 0.0;
    }
};