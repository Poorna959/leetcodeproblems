/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }   

        unordered_map<Node*,Node*>memo;

        Node * newhead = new Node(head->val);
        Node  * oldTemp = head->next;
        Node * newTemp = newhead;
        memo[head] = newhead;
        while(oldTemp!=NULL){
            Node * copynode = new Node(oldTemp->val);
            memo[oldTemp] =copynode;
            newTemp ->next = copynode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next; 
        }

        oldTemp = head;
        newTemp = newhead;
        while(oldTemp!=NULL){
            newTemp->random = memo[oldTemp->random];
            newTemp=newTemp->next;
            oldTemp = oldTemp->next;
        }
        return newhead;

    }
};