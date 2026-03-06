class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        vector<TreeNode*> queueNodes;
        vector<int> queueDepths;
        
        queueNodes.push_back(root);
        queueDepths.push_back(1);
        
        int head = 0;
        int maxDepthFound = 0;
        
        while (head < queueNodes.size()) {
            TreeNode* currentNode = queueNodes[head];
            int currentDepth = queueDepths[head];
            
            head = head + 1;
            
            if (currentDepth > maxDepthFound) {
                maxDepthFound = currentDepth;
            }
            
            if (currentNode->left != nullptr) {
                queueNodes.push_back(currentNode->left);
                queueDepths.push_back(currentDepth + 1);
            }
            
            if (currentNode->right != nullptr) {
                queueNodes.push_back(currentNode->right);
                queueDepths.push_back(currentDepth + 1);
            }
        }
        
        return maxDepthFound;
    }
};