// 2017/11/07 Peony
int rmNode(struct ListNode* cur, int n){
    int num;
    if(cur->next==NULL) return 1;
    else num=rmNode(cur->next, n);
    if(num==n){ //remove
        cur->next = cur->next->next;
    }
    return num+1;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    int num = rmNode(head, n);
    if(num==n){
        return head->next;
    }else{
        return head;
    }
}
