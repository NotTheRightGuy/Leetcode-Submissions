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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *curr = head;
        int totalNodes = 0;
        while (head != NULL)
        {
            totalNodes++;
            head = head->next;
        }
        for (int i = 0; i < ceil(totalNodes / 2); i++)
        {
            curr = curr->next;
        }
        return curr;
    }
};