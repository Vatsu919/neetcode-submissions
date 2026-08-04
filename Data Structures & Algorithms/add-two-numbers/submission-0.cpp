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
        ListNode* res=new ListNode(0);

        ListNode* temp=res;
        int c=0;

        while(l1 && l2) {
            int s=l1->val+l2->val+c;
            int as=s%10;
            c=s/10;
            ListNode* nnode = new ListNode(as);
            temp->next=nnode;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1) {
            int s=l1->val+c;
            int as=s%10;
            c=s/10;
            ListNode* nnode = new ListNode(as);
            temp->next=nnode;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2) {
            int s=l2->val+c;
            int as=s%10;
            c=s/10;
            ListNode* nnode = new ListNode(as);
            temp->next=nnode;
            temp=temp->next;
            l2=l2->next;
        }
        if(c) {
            ListNode* nnode = new ListNode(c);
            temp->next=nnode;
            temp=temp->next;
        }
        return res->next;
    }
};
