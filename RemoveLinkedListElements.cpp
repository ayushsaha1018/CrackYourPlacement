// TC : O(n), SC : O(1)

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = head;
        ListNode* curr = head;
        while(curr != NULL){
            if(curr -> val == val && curr == head){
                prev = curr;
                curr = curr -> next;
                head = head -> next;
            }
            else if(curr -> val == val){
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }

        return head;
    }
};