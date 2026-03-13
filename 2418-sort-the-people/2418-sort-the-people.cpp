class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> remainingNames;
        for (int i = 0; i < names.size(); i++) {
            remainingNames.push_back(names[i]);
        }
        
        vector<int> remainingHeights;
        for (int i = 0; i < heights.size(); i++) {
            remainingHeights.push_back(heights[i]);
        }
        
        vector<string> finalSortedNames;
        
        while (remainingHeights.size() > 0) {
            int maxHeight = -1;
            int maxIndex = -1;
            
            for (int i = 0; i < remainingHeights.size(); i++) {
                if (remainingHeights[i] > maxHeight) {
                    maxHeight = remainingHeights[i];
                    maxIndex = i;
                }
            }
            
            string currentTallestName = remainingNames[maxIndex];
            finalSortedNames.push_back(currentTallestName);
            
            vector<string> nextNames;
            vector<int> nextHeights;
            bool isRemoved = false;
            
            for (int i = 0; i < remainingHeights.size(); i++) {
                if (i == maxIndex && isRemoved == false) {
                    isRemoved = true;
                } else {
                    nextNames.push_back(remainingNames[i]);
                    nextHeights.push_back(remainingHeights[i]);
                }
            }
            
            remainingNames = nextNames;
            remainingHeights = nextHeights;
        }
        
        vector<string> resultToReturn;
        for (int i = 0; i < finalSortedNames.size(); i++) {
            resultToReturn.push_back(finalSortedNames[i]);
        }
        
        return resultToReturn;
    }
};