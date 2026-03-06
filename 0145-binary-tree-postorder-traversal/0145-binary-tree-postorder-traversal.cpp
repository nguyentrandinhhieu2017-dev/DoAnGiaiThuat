class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> intermediateValues;
        
        if (root == nullptr) {
            return intermediateValues;
        }

        vector<TreeNode*> customStack;
        customStack.push_back(root);

        while (customStack.size() > 0) {
            TreeNode* currentNode = customStack[customStack.size() - 1];
            customStack.pop_back();

            intermediateValues.push_back(currentNode->val);

            if (currentNode->left != nullptr) {
                customStack.push_back(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                customStack.push_back(currentNode->right);
            }
        }

        vector<int> finalResult;
        int totalElements = intermediateValues.size();
        
        for (int i = totalElements - 1; i >= 0; i--) {
            int val = intermediateValues[i];
            finalResult.push_back(val);
        }

        return finalResult;
    }
};