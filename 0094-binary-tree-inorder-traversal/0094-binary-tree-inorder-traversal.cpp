class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tempResult;
        vector<TreeNode*> customStack;
        TreeNode* currentNode = root;
        
        while (true) {
            if (currentNode != nullptr) {
                customStack.push_back(currentNode);
                currentNode = currentNode->left;
            } else {
                if (customStack.size() == 0) {
                    break;
                }
                
                TreeNode* lastNode = customStack[customStack.size() - 1];
                customStack.pop_back();
                
                tempResult.push_back(lastNode->val);
                
                currentNode = lastNode->right;
            }
        }
        
        vector<int> finalResult;
        
        for (int i = 0; i < tempResult.size(); i++) {
            finalResult.push_back(tempResult[i]);
        }
        
        return finalResult;
    }
};