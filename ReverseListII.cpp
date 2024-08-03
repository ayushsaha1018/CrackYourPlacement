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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        int i;
        for(i=1; i<left; i++){
            prev = curr;
            curr = curr -> next;
        }

        ListNode* revTail = curr;
        ListNode* revHead = NULL;

        while(i<=right){
            ListNode* nextNode = curr -> next;
            curr -> next = revHead;
            revHead = curr;
            curr = nextNode;
            i++;
        }

        if(prev != NULL)
            prev -> next = revHead;
        else
            head = revHead;
        
        revTail -> next = curr;
        return head;
    }
};