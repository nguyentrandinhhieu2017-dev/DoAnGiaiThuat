class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        vector<ListNode*> visitedNodes;
        ListNode* currentNode = head;

        while (currentNode != nullptr) {
            bool foundMatch = false;
            
            for (int i = 0; i < visitedNodes.size(); i++) {
                ListNode* storedNode = visitedNodes[i];
                if (currentNode == storedNode) {
                    foundMatch = true;
                    break;
                }
            }

            if (foundMatch == true) {
                return true;
            }

            visitedNodes.push_back(currentNode);
            currentNode = currentNode->next;
        }

        return false;
    }
};