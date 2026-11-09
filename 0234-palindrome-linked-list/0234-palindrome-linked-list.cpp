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
        ListNode * curr = head;
        
        stack<int> s;
        while(curr!=NULL){
            s.push(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
            if(curr->val!=s.top()){
                return false;
            }
            curr=curr->next;
            s.pop();
        }
        return true;
    }
};