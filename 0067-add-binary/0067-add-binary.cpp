class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> arrA;
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a[i] == '1') {
                arrA.push_back(1);
            } else {
                arrA.push_back(0);
            }
        }
        
        vector<int> arrB;
        for (int i = b.length() - 1; i >= 0; i--) {
            if (b[i] == '1') {
                arrB.push_back(1);
            } else {
                arrB.push_back(0);
            }
        }
        
        while (arrA.size() < arrB.size()) {
            arrA.push_back(0);
        }
        
        while (arrB.size() < arrA.size()) {
            arrB.push_back(0);
        }
        
        vector<int> resultArr;
        int carry = 0;
        
        for (int i = 0; i < arrA.size(); i++) {
            int sum = arrA[i] + arrB[i] + carry;
            
            if (sum == 0) {
                resultArr.push_back(0);
                carry = 0;
            } else if (sum == 1) {
                resultArr.push_back(1);
                carry = 0;
            } else if (sum == 2) {
                resultArr.push_back(0);
                carry = 1;
            } else if (sum == 3) {
                resultArr.push_back(1);
                carry = 1;
            }
        }
        
        if (carry == 1) {
            resultArr.push_back(1);
        }
        
        string resultStr = "";
        for (int i = resultArr.size() - 1; i >= 0; i--) {
            if (resultArr[i] == 1) {
                resultStr += "1";
            } else {
                resultStr += "0";
            }
        }
        
        return resultStr;
    }
};