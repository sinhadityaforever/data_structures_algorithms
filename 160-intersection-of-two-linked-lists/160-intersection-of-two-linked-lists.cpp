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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 =0;
        int l2=0;
        ListNode* tmp1=headA;
        ListNode* tmp2=headB;
        
        while(tmp1!=NULL){
            l1++;
            tmp1=tmp1->next;
        }
        while(tmp2!=NULL){
            l2++;
            tmp2=tmp2->next;
        }
        
        int diff = abs(l1-l2);
        tmp1 = headA;
        tmp2=headB;
        
        if(l1<l2){
            swap(tmp1, tmp2);
        }
        
        while(diff>0){
            tmp1=tmp1->next;
            diff--;
        }
        
        while(tmp1!=tmp2){
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return tmp1;
        
    }
};