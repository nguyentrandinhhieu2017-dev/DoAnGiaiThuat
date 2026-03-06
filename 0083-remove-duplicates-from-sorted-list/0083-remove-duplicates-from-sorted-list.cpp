class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        if (head->next == nullptr) {
            return head;
        }
        
        vector<int> allValues;
        ListNode* currentNode = head;
        
        while (currentNode != nullptr) {
            allValues.push_back(currentNode->val);
            currentNode = currentNode->next;
        }
        
        vector<int> uniqueValues;
        uniqueValues.push_back(allValues[0]);
        
        for (int i = 1; i < allValues.size(); i++) {
            if (allValues[i] != allValues[i - 1]) {
                uniqueValues.push_back(allValues[i]);
            }
        }
        
        ListNode* newHead = new ListNode(uniqueValues[0]);
        ListNode* tailNode = newHead;
        
        for (int i = 1; i < uniqueValues.size(); i++) {
            ListNode* newNode = new ListNode(uniqueValues[i]);
            tailNode->next = newNode;
            tailNode = newNode;
        }
        
        return newHead;
    }
};