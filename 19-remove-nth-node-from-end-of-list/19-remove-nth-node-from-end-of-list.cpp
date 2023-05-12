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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        
        int length =0;
        ListNode* tempHead=head;
        
        while(tempHead!=NULL){
            tempHead= tempHead->next;
            length++;
        }
        if(n==length){
            return head->next;
        }
        int count = length - n-1;
        
        tempHead=head;
        while(count>0){
            tempHead=tempHead->next;
            count--;
        }
        tempHead->next=tempHead->next->next;
        return head;
        
        
        
    }
};