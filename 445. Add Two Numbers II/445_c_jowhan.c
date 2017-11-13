// 2017/11/13 Jowhan

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/********************** solution 1 **********************/
// greedy solution: time: O(n+m), space: O(n+m)
// 想法: 將原本序列反序即可直接同位數相加。
// 另創新的兩個串列，從最高位元串起，較低位元用insert方式插至最前方。

inline struct ListNode* insertListNode(struct ListNode* list, struct ListNode* parentPtr, int val, int isHead){
    // add dummy node to record list length
    // insert after parent node: parentNode->node2 ==> parentNode->newNode->node2
    // return list head
    
    struct ListNode* newNodePtr = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    newNodePtr->val = val;
    if( list==NULL || isHead ){  // empty list or insert at head
        newNodePtr->next = list;
        return newNodePtr;
    }    
    newNodePtr->next = parentPtr->next;
    parentPtr->next = newNodePtr;    
    return list;
}

inline struct ListNode* reverseList(struct ListNode* list, bool needNewList){
    // if newList==1, return reversed list as new melloc list
    // if newList==0, return reversed list as original list   
    // dummy node no need to reverse
    
    struct ListNode *newList=NULL, *ptr=NULL, *ptr2=NULL, *ptr3=NULL;
    int val;    
        
    // no need to reverse cases
    if( list==NULL || list->next==NULL ) return list;
        
    if( needNewList ){     
        for( ptr=list; ; ptr=ptr->next ){
            // read list val
            val = ptr->val;            
            // insert node
            newList = insertListNode(newList, newList, val, 1);
            if( ptr->next==NULL ) break;
        }
    }
    else{
        for( ptr=NULL, ptr2=list, ptr3=list->next; ; ptr=ptr2, ptr2=ptr3, ptr3=ptr3->next ){
            ptr2->next = ptr;
            if( ptr3==NULL ) break;
        }
        return ptr2;
    }
    
    return newList;
}

inline struct ListNode* _addTwoNumbers_solution1(struct ListNode* l1, struct ListNode* l2) {    
    struct ListNode *reversed_l1=NULL, *reversed_l2=NULL, *ptr1=NULL, *ptr2=NULL;
    int carry=0, sum;
    
    // reverse l1
    reversed_l1 = reverseList(l1, 1);
    // reverse l2
    reversed_l2 = reverseList(l2, 1);
    
    // add
    for( ptr1=reversed_l1, ptr2=reversed_l2 ; ; ptr1=ptr1->next, ptr2=ptr2->next ){
        sum = ptr1->val + ptr2->val + carry;
        ptr1->val = sum % 10;
        carry = sum / 10;
        if( ptr2->next==NULL || ptr1->next==NULL ) break;
    }    
    // append remain list2 to list1     
    if( ptr2->next!=NULL ){
        ptr1->next = ptr2->next;
    }    
    // add carry to remain digits
    if( ptr1->next!=NULL ){
        for( ptr1=ptr1->next ; carry>0; ptr1=ptr1->next ){
            sum = ptr1->val + carry;
            ptr1->val = sum % 10;
            carry = sum / 10;  
            if( ptr1->next==NULL ) break;
        }
    }
        
    // insert new highest digit if carry==1
    if( carry>0 ) insertListNode(reversed_l1, ptr1, carry, 0);
    
    // reverse to original form
    reversed_l1 = reverseList(reversed_l1, 0);
    
    return reversed_l1;
}
/********************************************************/

/********************** solution 2 **********************/
// greedy solution: time: O(n+m), space: O(n+m)
// 想法: 第一次掃list將值存入stack，之後每次pop值出來相加。
// 結果可存入另一個stack，最後再將這個stack之值轉成list即可。

// define stack
# define MAX_STACK_SIZE 1000
typedef struct {
    int val[MAX_STACK_SIZE];
    int top;
} Stack;

inline bool isEmptyStack( Stack s ){
    return s.top==0;
}

inline bool isFullStack( Stack s ){
    return s.top==MAX_STACK_SIZE-1;
}

inline int popStack( Stack *s ){
    if( isEmptyStack(*s) ){
        printf(" Stack empty while pop.\n");
        exit(-1);
    }
    return s->val[s->top--];
}

inline void pushStack( Stack *s, int val ){
    if( isFullStack(*s) ){
        printf(" Stack full while push.\n");
        exit(-1);
    }
    s->val[++s->top] = val;
}

inline struct ListNode* _addTwoNumbers_solution2(struct ListNode* l1, struct ListNode* l2) {
    Stack s1, s2, s3;
    struct ListNode *ptr=NULL, *l3=NULL;
    int val1=0, val2=0, sum=0, carry=0;
    
    memset(&s1,0,sizeof(Stack));
    memset(&s2,0,sizeof(Stack));
    memset(&s3,0,sizeof(Stack));

    // first scan: put list value into stack
    for( ptr=l1; ptr!=NULL; ptr=ptr->next ){
        pushStack(&s1,ptr->val);
    }
    for( ptr=l2; ptr!=NULL; ptr=ptr->next ){
        pushStack(&s2,ptr->val);
    }
    
    // pop stacks and add, insert results into list
    for( ; !isEmptyStack(s1) || !isEmptyStack(s2) ; ){
        val1 = isEmptyStack(s1) ? 0 : popStack(&s1);
        val2 = isEmptyStack(s2) ? 0 : popStack(&s2);
        sum = val1 + val2 + carry;
        l3 = insertListNode(l3, l3, sum%10, 1);
        carry = sum/10;
    }    

    // both empty but still have carry case: insert carry to head
    if( carry )  l3 = insertListNode(l3, l3, carry, 1);

    return l3;
}

/********************************************************/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return _addTwoNumbers_solution2(l1, l2);
}
