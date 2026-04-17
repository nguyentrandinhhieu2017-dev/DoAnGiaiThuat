class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int counts[20001] = {0};
        for (int x : nums) {
            counts[x + 10000]++;
        }
        
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (int i = 0; i <= 20000; i++) {
            if (counts[i] > 0) {
                buckets[counts[i]].push_back(i - 10000);
            }
        }
        
        vector<int> res;
        for (int i = n; i >= 0; i--) {
            for (int x : buckets[i]) {
                res.push_back(x);
                if (res.size() == k) return res;
            }
        }
        
        return res;
    }
};