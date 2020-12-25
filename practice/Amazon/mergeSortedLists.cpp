/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *trav = nullptr, *head = nullptr;
        while (l1 && l2)
        {
            ListNode *next = nullptr;
            if (l1->val < l2->val)
                next = l1, l1 = l1->next;
            else
                next = l2, l2 = l2->next;
            if (head)
                trav->next = next, trav = trav->next;
            else
                head = trav = next;
        }
        if (l1)
            trav->next = l1;
        if (l2)
            trav->next = l2;
        return head;
    }
};