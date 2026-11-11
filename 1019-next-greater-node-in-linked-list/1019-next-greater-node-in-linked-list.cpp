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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *temp  = head;
        vector<int> num;
        while(temp!=nullptr){
            num.push_back(temp->val);
            temp = temp->next;
        }
        stack<int>s;
        int n = num.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=num[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=s.top();
            }
            s.push(num[i]);
        }
        return ans;
    }
};