class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> reversedDigits;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            reversedDigits.push_back(digits[i]);
        }
        
        int carry = 1;
        for (int i = 0; i < reversedDigits.size(); i++) {
            int sum = reversedDigits[i] + carry;
            reversedDigits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if (carry > 0) {
            reversedDigits.push_back(carry);
        }
        
        vector<int> result;
        
        for (int i = reversedDigits.size() - 1; i >= 0; i--) {
            result.push_back(reversedDigits[i]);
        }
        
        return result;
    }
};