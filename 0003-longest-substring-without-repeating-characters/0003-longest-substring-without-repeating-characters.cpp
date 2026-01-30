class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIndex[256]; // Mảng tĩnh thay cho hash map
        
        // Khởi tạo mảng bằng tay (tránh dùng hàm memset của thư viện)
        for(int k = 0; k < 256; k++) {
            lastIndex[k] = -1;
        }
        
        int maxLen = 0;
        int start = 0;
        
        // Duyệt chuỗi như duyệt mảng thông thường
        // s.length() là thuộc tính cơ bản, không cần thư viện xử lý chuỗi phức tạp
        for (int i = 0; i < s.length(); i++) {
            // Tự động ép kiểu char sang int để làm chỉ số mảng
            int charCode = s[i]; 
            
            // Logic cửa sổ trượt
            if (lastIndex[charCode] >= start) {
                start = lastIndex[charCode] + 1;
            }
            
            lastIndex[charCode] = i;
            
            int currentLen = i - start + 1;
            
            // Tự viết logic thay thế hàm max()
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }
        
        return maxLen;
    }
};