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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;

        ListNode* leftHead = new ListNode(-1);
        ListNode* rightHead = new ListNode(-1);
        ListNode* left = leftHead;
        ListNode* right = rightHead;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> val < x){
                left -> next = temp;
                left = left -> next;
            }
            else{
                right -> next = temp;
                right =  right -> next;
            }
            temp = temp -> next;
        }

        left -> next = rightHead -> next;
        right -> next = NULL;
        return leftHead -> next;
    }
};