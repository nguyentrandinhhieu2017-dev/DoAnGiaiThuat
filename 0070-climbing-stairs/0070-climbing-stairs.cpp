class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        if (n == 2) {
            return 2;
        }
        
        if (n == 3) {
            return 3;
        }
        
        vector<int> waysToClimb;
        
        waysToClimb.push_back(0); 
        waysToClimb.push_back(1); 
        waysToClimb.push_back(2); 
        waysToClimb.push_back(3); 
        
        int currentStep = 4;
        
        while (currentStep <= n) {
            int waysFromOneStepBehind = waysToClimb[currentStep - 1];
            int waysFromTwoStepsBehind = waysToClimb[currentStep - 2];
            
            int totalWaysForCurrentStep = waysFromOneStepBehind + waysFromTwoStepsBehind;
            
            waysToClimb.push_back(totalWaysForCurrentStep);
            
            currentStep = currentStep + 1;
        }
        
        return waysToClimb[n];
    }
};