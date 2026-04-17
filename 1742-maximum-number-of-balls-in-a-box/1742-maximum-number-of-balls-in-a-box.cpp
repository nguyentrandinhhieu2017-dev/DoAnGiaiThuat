class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int box[46] = {0}; 
        int maxBalls = 0;
        
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0;
            int temp = i;
            
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            
            box[sum]++;
            if (box[sum] > maxBalls) {
                maxBalls = box[sum];
            }
        }
        
        return maxBalls;
    }
};