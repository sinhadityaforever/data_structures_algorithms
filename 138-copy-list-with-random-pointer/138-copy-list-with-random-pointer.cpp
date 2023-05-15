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
        unordered_map<Node*, Node*>mp;
        Node* tmpHead=head;
        while(tmpHead!=NULL){
            int val = tmpHead->val;
            Node* tmp = new Node(val);
            mp[tmpHead]=tmp;
            tmpHead=tmpHead->next;
        }
        
        tmpHead=head;
        while(tmpHead!=NULL){
            mp[tmpHead]->next=mp[tmpHead->next];
            mp[tmpHead]->random=mp[tmpHead->random];
            tmpHead=tmpHead->next;
        }
        tmpHead= head;
        return mp[tmpHead];
        
        
    }
};