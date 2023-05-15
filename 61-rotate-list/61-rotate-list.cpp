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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode* tmpHead=head;
        ListNode* tail = head;
        ListNode* prev = head;
        int len =1;
        while(tail->next!=NULL){
            prev=tail;
            tail=tail->next;
            len++;
        }
        
        if(k>=len){
            k=k%len;
        }
        while(k>0){
            prev->next=NULL;
            tail->next=tmpHead;
            tmpHead=tail;
            tail=prev;
            prev=tmpHead;
            while(prev->next!=tail){
                prev=prev->next;
            }
            k--;
        }
        
        return tmpHead;
        
    }
};