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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL ){
            return head;
        }
        ListNode*temp=head;
        ListNode*dummynode=new ListNode(-1);
        ListNode*dummytemp=dummynode;
        while(temp!=NULL){
            if(temp->val!=val){
                dummytemp->next=new ListNode(temp->val);
                dummytemp=dummytemp->next;
                
            }
            temp=temp->next;
            
        }
        return dummynode->next;
    }
};