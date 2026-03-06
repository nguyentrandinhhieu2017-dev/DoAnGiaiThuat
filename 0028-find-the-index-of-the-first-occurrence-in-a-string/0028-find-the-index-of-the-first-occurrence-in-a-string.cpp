class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHaystack = haystack.length();
        int lenNeedle = needle.length();
        
        if (lenHaystack < lenNeedle) {
            return -1;
        }
        
        for (int i = 0; i <= lenHaystack - lenNeedle; i++) {
            int j = 0;
            
            while (j < lenNeedle) {
                if (haystack[i + j] == needle[j]) {
                    j++;
                } else {
                    break;
                }
            }
            
            if (j == lenNeedle) {
                return i;
            }
        }
        
        return -1;
    }
};