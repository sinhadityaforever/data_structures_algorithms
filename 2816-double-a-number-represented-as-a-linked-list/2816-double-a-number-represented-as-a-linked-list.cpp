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
    
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* add(ListNode* head){
        ListNode* revHead = reverse(head);
        ListNode* temp = revHead;
        int carry=0;
        while(temp!=NULL){
            int data = temp->val;
            int sum = data*2+carry;
            int prod = sum%10;
            carry = sum/10;
            temp->val =prod;
            temp=temp->next;
        }
        
        ListNode* ans = reverse(revHead);
        
        
        if(carry==0){
            return ans;
        }
        else{
            ListNode* tmpNode = new ListNode(carry);
            tmpNode->next = ans;
            return tmpNode;
        }
        
    }
    
    
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL) return head;
        return add(head);
    }
};