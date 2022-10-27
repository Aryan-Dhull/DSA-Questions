/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode*p=head;
    int c=0;
    while(p!=NULL){
        c+=1;
        p=p->next;
    }
    struct ListNode*ptr=head;
    for(int i=0;i<c/2;i++){
        ptr=ptr->next;
    }
    return ptr;
}