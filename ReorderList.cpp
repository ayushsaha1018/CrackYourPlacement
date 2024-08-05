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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while(curr != NULL){
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* rev = reverse(slow);
        ListNode* curr = head;

        while(rev -> next != NULL){
            ListNode* tempCurr = curr -> next;
            curr -> next = rev;

            ListNode* tempRev = rev -> next;
            rev -> next = tempCurr;

            curr = tempCurr;
            rev = tempRev;
        }
    }
};