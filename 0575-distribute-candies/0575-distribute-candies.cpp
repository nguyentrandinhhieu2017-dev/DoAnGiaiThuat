class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        bool seen[200001] = {false};
        int uniqueCount = 0;
        int limit = candyType.size() / 2;
        
        for (int i = 0; i < candyType.size(); i++) {
            int index = candyType[i] + 100000;
            if (!seen[index]) {
                seen[index] = true;
                uniqueCount++;
                
                if (uniqueCount == limit) {
                    return limit;
                }
            }
        }
        
        return uniqueCount;
    }
};