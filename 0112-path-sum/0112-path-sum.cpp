class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
        vector<TreeNode*> nodesQueue;
        vector<int> sumsQueue;
        vector<int> leafSums;
        
        nodesQueue.push_back(root);
        sumsQueue.push_back(root->val);
        
        int head = 0;
        
        while (head < nodesQueue.size()) {
            TreeNode* currentNode = nodesQueue[head];
            int currentSum = sumsQueue[head];
            
            head = head + 1;
            
            bool isLeaf = true;
            
            if (currentNode->left != nullptr) {
                nodesQueue.push_back(currentNode->left);
                sumsQueue.push_back(currentSum + currentNode->left->val);
                isLeaf = false;
            }
            
            if (currentNode->right != nullptr) {
                nodesQueue.push_back(currentNode->right);
                sumsQueue.push_back(currentSum + currentNode->right->val);
                isLeaf = false;
            }
            
            if (isLeaf == true) {
                leafSums.push_back(currentSum);
            }
        }
        
        for (int i = 0; i < leafSums.size(); i++) {
            if (leafSums[i] == targetSum) {
                return true;
            }
        }
        
        return false;
    }
};