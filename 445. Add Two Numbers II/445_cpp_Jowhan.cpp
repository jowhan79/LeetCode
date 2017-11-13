// 2017/11/13 Jowhan

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack_l1, stack_l2;
        ListNode *ptr=NULL, *l3=NULL;
        int sum=0, carry=0, val1=0, val2=0;
        
        // push list into stack
        for( ptr=l1; ptr!=NULL; ptr=ptr->next ) stack_l1.push(ptr->val);
        for( ptr=l2; ptr!=NULL; ptr=ptr->next ) stack_l2.push(ptr->val);
        
        // pop and add, insert results to list
        while( !stack_l1.empty() || !stack_l2.empty() ){
            if( stack_l1.empty() ) val1 = 0;
            else{
                val1 = stack_l1.top();
                stack_l1.pop();
            }
            if( stack_l2.empty() ) val2 = 0;
            else{
                val2 = stack_l2.top();
                stack_l2.pop();
            }
            sum = val1 + val2 + carry;
            l3 = insertListNode(l3, l3, sum%10, 1);
            carry = sum/10;
        }
        
        // 2 stacks are empty but still has carry case
        if( carry ) l3 = insertListNode(l3, l3, carry, 1);
        
        return l3;        
    }
    
private:
    inline ListNode* insertListNode(ListNode* list, ListNode* parentPtr, int val, bool isHead=0){        
        ListNode* newNodePtr = new ListNode(val);

        if( list==NULL || isHead ){
            newNodePtr->next = list;
            return newNodePtr;
        }
        newNodePtr->next = parentPtr->next;
        parentPtr->next = newNodePtr;        
        return list;
    }
    
};
