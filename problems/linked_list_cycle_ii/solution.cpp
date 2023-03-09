/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *hare = head;
        ListNode *turtle = head;
        while(!(hare == NULL) && !(hare->next == NULL)){
            turtle = turtle->next;
            hare = (hare->next)->next;
            if(hare == turtle){
                turtle = head;
                int count = 0;
                while(turtle != hare){
                    turtle = turtle->next;
                    hare = hare->next;
                    count++;
                }
                return hare;
            }
        }
        return NULL;
    }
};