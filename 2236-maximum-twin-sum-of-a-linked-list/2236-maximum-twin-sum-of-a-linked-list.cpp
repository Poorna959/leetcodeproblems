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
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode *slow = head,*fast = head;
        while(fast!=NULL && fast->next!=NULL){
            s.push(slow->val);
            slow=slow->next;
            fast = fast->next->next;
        }
        int ans = 0;
        
        while(slow!=NULL && !s.empty()){
            ans = max(ans,s.top()+slow->val);
            slow = slow->next;
            s.pop();
        }
        return ans;

    }
};