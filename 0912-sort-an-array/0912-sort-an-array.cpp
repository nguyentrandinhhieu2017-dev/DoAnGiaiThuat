class Solution {
public:
    // Hàm vun đống (heapify) để duy trì cấu trúc Max Heap
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i; 
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 

        // Nếu con trái lớn hơn nút gốc
        if (left < n && nums[left] > nums[largest])
            largest = left;

        // Nếu con phải lớn hơn nút lớn nhất hiện tại
        if (right < n && nums[right] > nums[largest])
            largest = right;

        // Nếu nút lớn nhất không phải là gốc
        if (largest != i) {
            swap(nums[i], nums[largest]);
            // Tiếp tục heapify các cây con bị ảnh hưởng
            heapify(nums, n, largest);
        }
    }

    vector<int>& sortArray(vector<int>& nums) {
        int n = nums.size();

        // Bước 1: Xây dựng Max Heap (sắp xếp lại mảng)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // Bước 2: Trích xuất từng phần tử từ heap
        for (int i = n - 1; i > 0; i--) {
            // Đưa phần tử lớn nhất (gốc) về cuối mảng
            swap(nums[0], nums[i]);
            // Gọi heapify trên heap đã giảm kích thước
            heapify(nums, i, 0);
        }

        return nums;
    }
};