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
    void reorderList(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;

        while(fast) {
            slow=slow->next;
            if(!fast->next)break;
            fast=fast->next->next;
        }
        ListNode* lnode = NULL;

        while(slow) {
            ListNode* next=slow->next;
            slow->next=lnode;
            lnode=slow;
            slow=next;
        }

        ListNode* temp=head;
        while(temp && lnode) {
            ListNode* next=temp->next;
            ListNode* lnext=lnode->next;
            temp->next=lnode;
            lnode->next=next;
            temp=next;
            lnode=lnext;
        }
        if(temp)temp->next=NULL;

    }
};
