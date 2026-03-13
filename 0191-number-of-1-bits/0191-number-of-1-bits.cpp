class Solution {
public:
    int hammingWeight(int n) {
        unsigned int unsignedN = (unsigned int)n;
        vector<int> binaryRepresentation;
        
        for (int i = 0; i < 32; i++) {
            int remainder = unsignedN % 2;
            binaryRepresentation.push_back(remainder);
            unsignedN = unsignedN / 2;
        }
        
        vector<int> justTheOnes;
        
        for (int i = 0; i < binaryRepresentation.size(); i++) {
            if (binaryRepresentation[i] == 1) {
                justTheOnes.push_back(1);
            }
        }
        
        int finalCount = 0;
        
        for (int i = 0; i < justTheOnes.size(); i++) {
            finalCount = finalCount + 1;
        }
        
        return finalCount;
    }
};