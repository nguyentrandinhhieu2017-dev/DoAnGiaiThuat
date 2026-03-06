class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> tree1;
        vector<TreeNode*> queue1;
        
        if (p != nullptr) {
            queue1.push_back(p);
        } else {
            tree1.push_back(-20000);
        }
        
        int head1 = 0;
        while (head1 < queue1.size()) {
            TreeNode* current = queue1[head1];
            head1 = head1 + 1;
            
            if (current != nullptr) {
                tree1.push_back(current->val);
                
                if (current->left != nullptr) {
                    queue1.push_back(current->left);
                } else {
                    queue1.push_back(nullptr);
                }
                
                if (current->right != nullptr) {
                    queue1.push_back(current->right);
                } else {
                    queue1.push_back(nullptr);
                }
            } else {
                tree1.push_back(-20000);
            }
        }
        
        vector<int> tree2;
        vector<TreeNode*> queue2;
        
        if (q != nullptr) {
            queue2.push_back(q);
        } else {
            tree2.push_back(-20000);
        }
        
        int head2 = 0;
        while (head2 < queue2.size()) {
            TreeNode* current = queue2[head2];
            head2 = head2 + 1;
            
            if (current != nullptr) {
                tree2.push_back(current->val);
                
                if (current->left != nullptr) {
                    queue2.push_back(current->left);
                } else {
                    queue2.push_back(nullptr);
                }
                
                if (current->right != nullptr) {
                    queue2.push_back(current->right);
                } else {
                    queue2.push_back(nullptr);
                }
            } else {
                tree2.push_back(-20000);
            }
        }
        
        if (tree1.size() != tree2.size()) {
            return false;
        }
        
        for (int i = 0; i < tree1.size(); i++) {
            if (tree1[i] != tree2[i]) {
                return false;
            }
        }
        
        return true;
    }
};