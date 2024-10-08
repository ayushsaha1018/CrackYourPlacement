// TC : O(n), SC : O(1)

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;

            slow = slow->next;
        }

        return slow;
    }
};