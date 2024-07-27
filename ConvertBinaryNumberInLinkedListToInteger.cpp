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
    int getDecimalValue(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp -> next;
        }

        int ans = 0;
        temp = head;
        int i = 1;
        while(temp != NULL){
            if(temp -> val == 1)
                ans += pow(2, n - i);
            i++;
            temp = temp -> next;
        }

        return ans;
    }
};