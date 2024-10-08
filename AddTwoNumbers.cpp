// TC : O(n), SC : O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempHead = new ListNode(-1);
        ListNode* temp = tempHead;

        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1  = 0;
            if(l1 != NULL)
                val1 = l1 -> val;
            
            int val2 = 0;
            if(l2 != NULL)
                val2 = l2 -> val;
            
            int sum = val1 + val2 + carry;
            int d = sum % 10;
            ListNode* newNode = new ListNode(d);
            temp -> next = newNode;
            temp = newNode;
            carry = sum/10;

            if(l1 != NULL)
                l1 = l1 -> next;
            if(l2 != NULL)
                l2 = l2 -> next;
        }

        return tempHead -> next;
    }
};