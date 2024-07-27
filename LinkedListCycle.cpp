// TC : O(n), SC : O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL){
            if(slow == fast)
                return true;
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL)
                fast = fast -> next;
        }

        return false;
    }
};