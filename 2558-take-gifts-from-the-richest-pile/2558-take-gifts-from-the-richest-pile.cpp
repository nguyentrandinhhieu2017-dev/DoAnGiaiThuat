class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        vector<int> currentPiles;
        for (int i = 0; i < gifts.size(); i++) {
            currentPiles.push_back(gifts[i]);
        }
        
        int currentSecond = 0;
        while (currentSecond < k) {
            int maxGiftValue = -1;
            int maxGiftIndex = -1;
            
            for (int i = 0; i < currentPiles.size(); i++) {
                if (currentPiles[i] > maxGiftValue) {
                    maxGiftValue = currentPiles[i];
                    maxGiftIndex = i;
                }
            }
            
            vector<int> nextPiles;
            for (int i = 0; i < currentPiles.size(); i++) {
                if (i == maxGiftIndex) {
                    double doubleValue = (double)currentPiles[i];
                    double rootValue = sqrt(doubleValue);
                    int floorValue = (int)floor(rootValue);
                    nextPiles.push_back(floorValue);
                } else {
                    nextPiles.push_back(currentPiles[i]);
                }
            }
            
            currentPiles = nextPiles;
            currentSecond = currentSecond + 1;
        }
        
        vector<int> finalPiles;
        for (int i = 0; i < currentPiles.size(); i++) {
            finalPiles.push_back(currentPiles[i]);
        }
        
        long long totalRemainingGifts = 0;
        for (int i = 0; i < finalPiles.size(); i++) {
            long long giftCount = (long long)finalPiles[i];
            totalRemainingGifts = totalRemainingGifts + giftCount;
        }
        
        return totalRemainingGifts;
    }
};