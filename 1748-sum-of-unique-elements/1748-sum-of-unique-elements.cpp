class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int count[101] = {0};
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        
        for (int i = 1; i <= 100; i++) {
            if (count[i] == 1) {
                sum += i;
            }
        }
        
        return sum;
    }
};