class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        vector<int> leftTreeValues;
        vector<TreeNode*> leftQueue;
        
        if (root->left != nullptr) {
            leftQueue.push_back(root->left);
        } else {
            leftTreeValues.push_back(-20000);
        }
        
        int headLeft = 0;
        while (headLeft < leftQueue.size()) {
            TreeNode* current = leftQueue[headLeft];
            headLeft = headLeft + 1;
            
            if (current != nullptr) {
                leftTreeValues.push_back(current->val);
                
                if (current->left != nullptr) {
                    leftQueue.push_back(current->left);
                } else {
                    leftQueue.push_back(nullptr);
                }
                
                if (current->right != nullptr) {
                    leftQueue.push_back(current->right);
                } else {
                    leftQueue.push_back(nullptr);
                }
            } else {
                leftTreeValues.push_back(-20000);
            }
        }
        
        vector<int> rightTreeValues;
        vector<TreeNode*> rightQueue;
        
        if (root->right != nullptr) {
            rightQueue.push_back(root->right);
        } else {
            rightTreeValues.push_back(-20000);
        }
        
        int headRight = 0;
        while (headRight < rightQueue.size()) {
            TreeNode* current = rightQueue[headRight];
            headRight = headRight + 1;
            
            if (current != nullptr) {
                rightTreeValues.push_back(current->val);
                
                if (current->right != nullptr) {
                    rightQueue.push_back(current->right);
                } else {
                    rightQueue.push_back(nullptr);
                }
                
                if (current->left != nullptr) {
                    rightQueue.push_back(current->left);
                } else {
                    rightQueue.push_back(nullptr);
                }
            } else {
                rightTreeValues.push_back(-20000);
            }
        }
        
        if (leftTreeValues.size() != rightTreeValues.size()) {
            return false;
        }
        
        for (int i = 0; i < leftTreeValues.size(); i++) {
            if (leftTreeValues[i] != rightTreeValues[i]) {
                return false;
            }
        }
        
        return true;
    }
};