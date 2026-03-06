class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        vector<TreeNode*> nodesQueue;
        vector<int> depthQueue;
        vector<int> leafDepths;
        
        nodesQueue.push_back(root);
        depthQueue.push_back(1);
        
        int head = 0;
        
        while (head < nodesQueue.size()) {
            TreeNode* currentNode = nodesQueue[head];
            int currentDepth = depthQueue[head];
            
            head = head + 1;
            
            bool isLeaf = true;
            
            if (currentNode->left != nullptr) {
                nodesQueue.push_back(currentNode->left);
                depthQueue.push_back(currentDepth + 1);
                isLeaf = false;
            }
            
            if (currentNode->right != nullptr) {
                nodesQueue.push_back(currentNode->right);
                depthQueue.push_back(currentDepth + 1);
                isLeaf = false;
            }
            
            if (isLeaf == true) {
                leafDepths.push_back(currentDepth);
            }
        }
        
        int minimumDepthValue = leafDepths[0];
        
        for (int i = 1; i < leafDepths.size(); i++) {
            if (leafDepths[i] < minimumDepthValue) {
                minimumDepthValue = leafDepths[i];
            }
        }
        
        return minimumDepthValue;
    }
};