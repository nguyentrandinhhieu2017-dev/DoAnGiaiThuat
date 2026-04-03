class Solution {
public:
    int secondHighest(string s) {
        int firstMax = -1;
        int secondMax = -1;

        for (char c : s) {
            if (isdigit(c)) {
                int d = c - '0';
                if (d > firstMax) {
                    secondMax = firstMax;
                    firstMax = d;
                } else if (d > secondMax && d < firstMax) {
                    secondMax = d;
                }
            }
        }

        return secondMax;
    }
};