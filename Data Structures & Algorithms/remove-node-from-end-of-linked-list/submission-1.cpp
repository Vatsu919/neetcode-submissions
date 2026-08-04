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
        // if(!head || !head->next)return NULL;
        int sz=0;
        ListNode* temp=head;
        while(temp) {
            sz++;
            temp=temp->next;
        }
        temp=head;

        int fn = sz-n+1;

        int ci = 1;
        ListNode* prev=NULL;

        while(ci<fn && temp) {
            prev=temp;
            temp=temp->next;
            ci++;
        }
        if(ci!=fn)return head;
        if(!temp) {
            return head;
        }
        if(!prev) {
            return head->next;
        }
        ListNode* nnode= prev->next;
        prev->next = prev->next->next;
        delete(nnode);
        return head;
    }
};
