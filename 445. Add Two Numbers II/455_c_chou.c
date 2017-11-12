// 2017/11/12 Peony

struct ListNode* addZeroNode(struct ListNode* l, int addlen){
    int i;
    struct ListNode* node; 
    for(i=0; i<addlen; i++){
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node -> val = 0;
        node -> next = l;
        l = node;
    }
    return l;
}

struct ListNode* addTwoNode(struct ListNode* l1, struct ListNode* l2, int *carry){
    struct ListNode *backbits, *node;
    int car;
    if( l1->next!=NULL && l2->next!=NULL){
        backbits = addTwoNode(l1->next, l2->next, &car);
        node = (struct ListNode*) malloc (sizeof(struct ListNode));
        node->val = (l1->val + l2->val + car)%10;
        *carry = (l1->val + l2->val + car)/10;
        node->next = backbits;
        return node;
    }else{
        node = (struct ListNode*) malloc (sizeof(struct ListNode));
        node->val = (l1->val + l2->val)%10;
        *carry = (l1->val + l2->val)/10;
        node->next = NULL;
        return node;
    }
}

struct ListNode* addTwoNumbers_v1(struct ListNode* l1, struct ListNode* l2){
    
    int len1, len2, carry;
    struct ListNode* cur;
    // Find length
    for(len1=0, cur=l1; cur->next!=NULL; cur=cur->next) len1++;
    for(len2=0, cur=l2; cur->next!=NULL; cur=cur->next) len2++;
    // Let two list in same length
    if( len1>len2 ){
        l2 = addZeroNode(l2, len1-len2);
    }else if( len1<len2 ){
        l1 = addZeroNode(l1, len2-len1);
    }
        
    // add two node
    struct ListNode *result = addTwoNode(l1, l2, &carry);
    if(carry == 1){
        cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur -> val = carry;
        cur -> next = result;
        result = cur;
    }
    return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwoNumbers_v1(l1, l2);
}
