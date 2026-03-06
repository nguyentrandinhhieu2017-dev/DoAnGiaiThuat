class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        vector<TreeNode*> allNodes;
        int headAll = 0;
        
        allNodes.push_back(root);
        
        while (headAll < allNodes.size()) {
            TreeNode* current = allNodes[headAll];
            headAll = headAll + 1;
            
            if (current->left != nullptr) {
                allNodes.push_back(current->left);
            }
            
            if (current->right != nullptr) {
                allNodes.push_back(current->right);
            }
        }
        
        for (int i = 0; i < allNodes.size(); i++) {
            TreeNode* currentNode = allNodes[i];
            
            int leftHeight = 0;
            if (currentNode->left != nullptr) {
                vector<TreeNode*> queueNodes;
                vector<int> queueDepths;
                
                queueNodes.push_back(currentNode->left);
                queueDepths.push_back(1);
                
                int headLeft = 0;
                while (headLeft < queueNodes.size()) {
                    TreeNode* tempNode = queueNodes[headLeft];
                    int tempDepth = queueDepths[headLeft];
                    headLeft = headLeft + 1;
                    
                    if (tempDepth > leftHeight) {
                        leftHeight = tempDepth;
                    }
                    
                    if (tempNode->left != nullptr) {
                        queueNodes.push_back(tempNode->left);
                        queueDepths.push_back(tempDepth + 1);
                    }
                    
                    if (tempNode->right != nullptr) {
                        queueNodes.push_back(tempNode->right);
                        queueDepths.push_back(tempDepth + 1);
                    }
                }
            }
            
            int rightHeight = 0;
            if (currentNode->right != nullptr) {
                vector<TreeNode*> queueNodesRight;
                vector<int> queueDepthsRight;
                
                queueNodesRight.push_back(currentNode->right);
                queueDepthsRight.push_back(1);
                
                int headRight = 0;
                while (headRight < queueNodesRight.size()) {
                    TreeNode* tempNodeRight = queueNodesRight[headRight];
                    int tempDepthRight = queueDepthsRight[headRight];
                    headRight = headRight + 1;
                    
                    if (tempDepthRight > rightHeight) {
                        rightHeight = tempDepthRight;
                    }
                    
                    if (tempNodeRight->left != nullptr) {
                        queueNodesRight.push_back(tempNodeRight->left);
                        queueDepthsRight.push_back(tempDepthRight + 1);
                    }
                    
                    if (tempNodeRight->right != nullptr) {
                        queueNodesRight.push_back(tempNodeRight->right);
                        queueDepthsRight.push_back(tempDepthRight + 1);
                    }
                }
            }
            
            int difference = leftHeight - rightHeight;
            if (difference < 0) {
                difference = -difference;
            }
            
            if (difference > 1) {
                return false;
            }
        }
        
        return true;
    }
};