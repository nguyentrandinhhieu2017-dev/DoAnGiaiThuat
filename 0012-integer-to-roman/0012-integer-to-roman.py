class Solution:
    def intToRoman(self, num: int) -> str:
        # Bảng quy đổi từ số sang La Mã (Xếp từ lớn xuống bé)
        bang_quy_doi = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I")
        ]
        
        ket_qua = ""
        
        # Duyệt qua từng cặp giá trị trong bảng
        for gia_tri, ky_tu in bang_quy_doi:
            # Nếu số hiện tại vẫn lớn hơn hoặc bằng giá trị đang xét
            while num >= gia_tri:
                ket_qua += ky_tu    # Thêm ký tự La Mã vào kết quả
                num -= gia_tri      # Trừ bớt số đi
                
        return ket_qua

# --- Phần chạy thử (Test) ---
# Bạn có thể thay đổi số ở trong ngoặc để kiểm tra
if __name__ == "__main__":
    bai_lam = Solution()
    
    print("3749 la:", bai_lam.intToRoman(3749))
    print("58 la:", bai_lam.intToRoman(58))
    print("1994 la:", bai_lam.intToRoman(1994))