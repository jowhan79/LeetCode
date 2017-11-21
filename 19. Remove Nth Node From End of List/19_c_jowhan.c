// 2017/11/21 Jowhan

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/********************** solution 1 **********************/
// time: O(n), space: O(1), 只掃一次
// 想法: 用兩個pointer，一個從頭掃到尾，另一個與其保持距離n。

inline struct ListNode* _removeNthFromEnd_sol1(struct ListNode* head, int n) {
    struct ListNode *scanner=NULL, *indicater=NULL, *temp=NULL;
    int count=0;
    
    // only scanner move
    for( scanner=head; scanner!=NULL && count<=n; scanner=scanner->next ){
        ++count;
    }
    
    // after scan n nodes, scanner and indicater move together
    for( indicater=head; scanner!=NULL; scanner=scanner->next ){
        indicater = indicater->next;
        ++count;
    }
    
    // remove only one node
    if( count==n && n==1 ){
        free(head);
        return NULL;
    }    
    
    temp = indicater->next;
    indicater->next = temp->next;
    // remove 1st node
    if(count==n){
        free(head);
        head = temp;
    }
    // remove non 1st node
    else{        
        free(temp);   
    }
    
    return head;
}
/********************************************************/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    return _removeNthFromEnd_sol1(head, n);
}
