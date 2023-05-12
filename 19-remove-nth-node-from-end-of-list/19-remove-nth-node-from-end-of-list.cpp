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
        ListNode* start = new ListNode();
        start->next=head;
        ListNode* i = start;
        ListNode* j = start;
        
       while(n>0){
           j=j->next;
           n--;
       }
        while(j->next!=NULL){
            j=j->next;
            i=i->next;
        }
        i->next = i->next->next;
        return start->next;
    }
};