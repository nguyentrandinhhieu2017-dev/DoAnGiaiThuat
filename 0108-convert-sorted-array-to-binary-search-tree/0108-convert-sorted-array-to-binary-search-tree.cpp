class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        
        if (nums.size() == 1) {
            TreeNode* singleNode = new TreeNode(nums[0]);
            return singleNode;
        }
        
        int midIndex = nums.size() / 2;
        TreeNode* rootNode = new TreeNode(nums[midIndex]);
        
        vector<int> leftHalf;
        for (int i = 0; i < midIndex; i++) {
            leftHalf.push_back(nums[i]);
        }
        
        vector<int> rightHalf;
        for (int i = midIndex + 1; i < nums.size(); i++) {
            rightHalf.push_back(nums[i]);
        }
        
        if (leftHalf.size() > 0) {
            rootNode->left = sortedArrayToBST(leftHalf);
        } else {
            rootNode->left = nullptr;
        }
        
        if (rightHalf.size() > 0) {
            rootNode->right = sortedArrayToBST(rightHalf);
        } else {
            rootNode->right = nullptr;
        }
        
        return rootNode;
    }
};