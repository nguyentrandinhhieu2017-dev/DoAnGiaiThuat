class Solution {
public:
    int minimumCost(vector<int>& cost) {
        vector<int> currentCandies;
        for (int i = 0; i < cost.size(); i++) {
            currentCandies.push_back(cost[i]);
        }
        
        int totalPaid = 0;
        
        while (currentCandies.size() > 0) {
            int maxPrice1 = -1;
            int maxIndex1 = -1;
            for (int i = 0; i < currentCandies.size(); i++) {
                if (currentCandies[i] > maxPrice1) {
                    maxPrice1 = currentCandies[i];
                    maxIndex1 = i;
                }
            }
            
            totalPaid = totalPaid + maxPrice1;
            
            vector<int> temp1;
            for (int i = 0; i < currentCandies.size(); i++) {
                if (i != maxIndex1) {
                    temp1.push_back(currentCandies[i]);
                }
            }
            currentCandies = temp1;
            
            if (currentCandies.size() == 0) {
                break;
            }
            
            int maxPrice2 = -1;
            int maxIndex2 = -1;
            for (int i = 0; i < currentCandies.size(); i++) {
                if (currentCandies[i] > maxPrice2) {
                    maxPrice2 = currentCandies[i];
                    maxIndex2 = i;
                }
            }
            
            totalPaid = totalPaid + maxPrice2;
            
            vector<int> temp2;
            for (int i = 0; i < currentCandies.size(); i++) {
                if (i != maxIndex2) {
                    temp2.push_back(currentCandies[i]);
                }
            }
            currentCandies = temp2;
            
            if (currentCandies.size() == 0) {
                break;
            }
            
            int maxPrice3 = -1;
            int maxIndex3 = -1;
            for (int i = 0; i < currentCandies.size(); i++) {
                if (currentCandies[i] > maxPrice3) {
                    maxPrice3 = currentCandies[i];
                    maxIndex3 = i;
                }
            }
            
            vector<int> temp3;
            for (int i = 0; i < currentCandies.size(); i++) {
                if (i != maxIndex3) {
                    temp3.push_back(currentCandies[i]);
                }
            }
            currentCandies = temp3;
        }
        
        return totalPaid;
    }
};