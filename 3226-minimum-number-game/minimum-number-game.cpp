class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> currentNums;
        for (int i = 0; i < nums.size(); i++) {
            currentNums.push_back(nums[i]);
        }
        
        vector<int> finalResult;
        
        while (currentNums.size() > 0) {
            int minAlice = currentNums[0];
            int minIndexAlice = 0;
            
            for (int i = 1; i < currentNums.size(); i++) {
                if (currentNums[i] < minAlice) {
                    minAlice = currentNums[i];
                    minIndexAlice = i;
                }
            }
            
            vector<int> arrayAfterAlice;
            bool isAliceRemoved = false;
            
            for (int i = 0; i < currentNums.size(); i++) {
                if (i == minIndexAlice && isAliceRemoved == false) {
                    isAliceRemoved = true;
                } else {
                    arrayAfterAlice.push_back(currentNums[i]);
                }
            }
            
            currentNums = arrayAfterAlice;
            
            int minBob = currentNums[0];
            int minIndexBob = 0;
            
            for (int i = 1; i < currentNums.size(); i++) {
                if (currentNums[i] < minBob) {
                    minBob = currentNums[i];
                    minIndexBob = i;
                }
            }
            
            vector<int> arrayAfterBob;
            bool isBobRemoved = false;
            
            for (int i = 0; i < currentNums.size(); i++) {
                if (i == minIndexBob && isBobRemoved == false) {
                    isBobRemoved = true;
                } else {
                    arrayAfterBob.push_back(currentNums[i]);
                }
            }
            
            currentNums = arrayAfterBob;
            
            finalResult.push_back(minBob);
            finalResult.push_back(minAlice);
        }
        
        vector<int> returnedArray;
        for (int i = 0; i < finalResult.size(); i++) {
            returnedArray.push_back(finalResult[i]);
        }
        
        return returnedArray;
    }
};