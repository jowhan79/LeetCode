// 2017/12/19 Peony
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode *ans, *cur, *tmp;
    
    if(head==NULL) return ans;
    
    ans = head; 
    cur = head->next;
    ans -> next = NULL;
    while(cur!=NULL){
        tmp = cur;
        cur = cur -> next;
        tmp -> next = ans;
        ans = tmp;
    }
    
    return ans;
    
}
