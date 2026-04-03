class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        // Tạo 2 Hash Map để lưu tần số xuất hiện của các từ trong 2 mảng
        unordered_map<string, int> freq1;
        unordered_map<string, int> freq2;
        
        // Đếm số lần xuất hiện của mỗi từ trong words1
        for (const string& word : words1) {
            freq1[word]++;
        }
        
        // Đếm số lần xuất hiện của mỗi từ trong words2
        for (const string& word : words2) {
            freq2[word]++;
        }
        
        int result = 0;
        
        // Duyệt qua map thứ nhất để tìm kết quả
        for (const auto& pair : freq1) {
            // pair.first là từ, pair.second là số lần xuất hiện của từ đó trong words1
            // Nếu từ này xuất hiện đúng 1 lần ở words1 VÀ đúng 1 lần ở words2
            if (pair.second == 1 && freq2[pair.first] == 1) {
                result++;
            }
        }
        
        return result;
    }
};