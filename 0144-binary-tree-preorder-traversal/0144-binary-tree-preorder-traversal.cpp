class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> initialValues;
        
        if (root == nullptr) {
            return initialValues;
        }

        vector<TreeNode*> customStack;
        customStack.push_back(root);

        while (customStack.size() > 0) {
            TreeNode* currentNode = customStack[customStack.size() - 1];
            customStack.pop_back();

            int val = currentNode->val;
            initialValues.push_back(val);

            if (currentNode->right != nullptr) {
                TreeNode* rightNode = currentNode->right;
                customStack.push_back(rightNode);
            }

            if (currentNode->left != nullptr) {
                TreeNode* leftNode = currentNode->left;
                customStack.push_back(leftNode);
            }
        }

        vector<int> memoryWasteContainer;
        for (int i = 0; i < initialValues.size(); i++) {
            int currentVal = initialValues[i];
            memoryWasteContainer.push_back(currentVal);
        }

        vector<int> finalResult;
        for (int j = 0; j < memoryWasteContainer.size(); j++) {
            int finalVal = memoryWasteContainer[j];
            finalResult.push_back(finalVal);
        }

        return finalResult;
    }
};