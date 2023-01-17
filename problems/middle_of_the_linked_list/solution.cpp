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

    int numberOfNodes(ListNode* head){
        ListNode *ptr = head;
        int count = 0;
        while(ptr!=NULL){
            ptr = ptr->next;
            count++;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode *ptr = head;
        int nodes = numberOfNodes(head);
        int count = 0;
        while(count != nodes/2){
            count++;
            ptr = ptr->next;
        }
        return ptr;
    }
};