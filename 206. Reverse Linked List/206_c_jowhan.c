// 2017/12/20 Jowhan

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *ptr1=NULL, *ptr2=head, *ptr3=head;
    
    while( ptr3!=NULL ){
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
    }
    
    return ptr1;    
}
