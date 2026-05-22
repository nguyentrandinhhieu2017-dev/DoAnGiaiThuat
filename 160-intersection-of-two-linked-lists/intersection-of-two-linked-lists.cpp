class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        vector<ListNode*> nodesA;
        ListNode* currentA = headA;
        while (currentA != nullptr) {
            nodesA.push_back(currentA);
            currentA = currentA->next;
        }

        vector<ListNode*> nodesB;
        ListNode* currentB = headB;
        while (currentB != nullptr) {
            nodesB.push_back(currentB);
            currentB = currentB->next;
        }

        for (int i = 0; i < nodesA.size(); i++) {
            ListNode* nodeFromA = nodesA[i];
            
            for (int j = 0; j < nodesB.size(); j++) {
                ListNode* nodeFromB = nodesB[j];
                
                if (nodeFromA == nodeFromB) {
                    return nodeFromA;
                }
            }
        }

        return nullptr;
    }
};