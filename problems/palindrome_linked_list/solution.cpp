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
    bool isPalindrome(ListNode* head) {
        string str = "";
        while(head!=NULL){
            str += to_string(head->val);
            head = head->next;
        }
        string temp = str;
        reverse(temp.begin(),temp.end());
        if(str == temp) return true;
        return false;
    }
};