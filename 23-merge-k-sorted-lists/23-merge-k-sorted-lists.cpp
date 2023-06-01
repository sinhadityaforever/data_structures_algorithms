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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: lists){
            while(i!=NULL){
                pq.push(i->val);
                i=i->next;
            }
        }
        
        ListNode* newHead = new ListNode;
        ListNode* tmp = newHead;
        while(!pq.empty()){
            int value = pq.top();
            pq.pop();
            ListNode* dummy = new ListNode(value);
            tmp->next = dummy;
            tmp = tmp->next;
        }
        return newHead->next;
    }
};