class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count[101] = {0};
        for (int i = 0; i < heights.size(); i++) {
            count[heights[i]]++;
        }
        
        int diff = 0;
        int currentHeight = 1;
        
        for (int i = 0; i < heights.size(); i++) {
            while (count[currentHeight] == 0) {
                currentHeight++;
            }
            if (heights[i] != currentHeight) {
                diff++;
            }
            count[currentHeight]--;
        }
        
        return diff;
    }
};