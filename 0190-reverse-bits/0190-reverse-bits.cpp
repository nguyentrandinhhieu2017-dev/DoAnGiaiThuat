class Solution {
public:
    int reverseBits(int n) {
        unsigned int unsignedN = (unsigned int)n;
        vector<int> originalBits;
        
        for (int i = 0; i < 32; i++) {
            int bitValue = unsignedN % 2;
            originalBits.push_back(bitValue);
            unsignedN = unsignedN / 2;
        }
        
        vector<unsigned int> powersOfTwo;
        unsigned int currentPower = 1;
        
        for (int i = 0; i < 32; i++) {
            powersOfTwo.push_back(currentPower);
            currentPower = currentPower * 2;
        }
        
        unsigned int reversedResult = 0;
        
        for (int i = 0; i < 32; i++) {
            if (originalBits[i] == 1) {
                int reversedPosition = 31 - i;
                unsigned int valueToAdd = powersOfTwo[reversedPosition];
                reversedResult = reversedResult + valueToAdd;
            }
        }
        
        return (int)reversedResult;
    }
};