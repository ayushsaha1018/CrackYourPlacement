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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* prev = head;
        ListNode* curr = head -> next; 
        while(curr != NULL){
            if(prev -> val == curr -> val){
                ListNode* nextNode = curr -> next;
                prev -> next = nextNode;
                curr = nextNode;
            }
            else{
                curr = curr -> next;
                prev = prev -> next;
            }
        }

        return head;
    }
};