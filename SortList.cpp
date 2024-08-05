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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return slow;
    }

    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        ListNode* tempHead = new ListNode(-1);
        ListNode* temp = tempHead;

        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                temp -> next = l1;
                l1 = l1 -> next;
            }
            else{
                temp -> next = l2;
                l2 = l2 -> next;
            }
            temp = temp -> next;
        }

        if(l1)
            temp -> next = l1;
        if(l2)
            temp -> next = l2;
        
        return tempHead -> next;
    }

    ListNode* sortLL(ListNode* head){
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle -> next;
        middle -> next = NULL;

        left = sortLL(left);
        right = sortLL(right);

        return mergeTwoList(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};