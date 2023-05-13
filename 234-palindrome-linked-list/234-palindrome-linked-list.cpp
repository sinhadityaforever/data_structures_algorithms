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
        if(head==NULL||head->next==NULL){
            return head;
        }
        
        ListNode* rev = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return rev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        int len =0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        
        int cnt = (len+1)/2;
        ListNode* tmpHead = head;
        while(cnt>0){
            tmpHead=tmpHead->next;
            cnt--;
        }
        tmpHead = reverse(tmpHead);
        while(head!=NULL && tmpHead!=NULL){
            if(head->val != tmpHead->val){
                return false;
            }
            head=head->next;
            tmpHead=tmpHead->next;
        }
        return true;
        
    }
};