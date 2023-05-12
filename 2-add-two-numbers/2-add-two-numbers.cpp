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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* tmpAns = ans;
        int carry =0;
        while(l1!=NULL || l2!=NULL){
                int val1 =0;
                int val2=0;
                if(l1!=NULL)
                    val1=l1->val;
            
                if(l2!=NULL)
                    val2=l2->val;
                int sum = (val1+val2+carry)%10;
                carry = (val1+val2+carry)/10;
                ListNode* tmp = new ListNode(sum);
                ans->next=tmp;
                ans=ans->next;
                if(l1!=NULL)
                    l1=l1->next;
            
                if(l2!=NULL)
                    l2=l2->next;
                
            
        }
        if(carry!=0){
            ListNode* tmp = new ListNode(carry);
            ans->next=tmp;
        }
        return tmpAns->next;
    }
};