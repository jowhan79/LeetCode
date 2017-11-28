// 2017/11/28 Jowhan

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/********************** solution 1 **********************/
// recursive

int* __inorderTraversal_sol1_r(struct TreeNode* ptr, int* returnArray, int* returnSize){
    
    // stop condition
    if( ptr==NULL ) return returnArray;
    
    // recursive: left
    returnArray = __inorderTraversal_sol1_r(ptr->left, returnArray, returnSize);
    
    // record value
    returnArray = realloc(returnArray,sizeof(int)*(++*returnSize));
    returnArray[*returnSize-1] = ptr->val;
        
    // recursive: right
    returnArray = __inorderTraversal_sol1_r(ptr->right, returnArray, returnSize);
    
    return returnArray;
}

inline int* _inorderTraversal_sol1(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    
    return __inorderTraversal_sol1_r(root, NULL, returnSize);
}
/********************************************************/


/********************** solution 2 **********************/
// iteratively
// use stack to record traveled nodes

inline void __pushStack(struct TreeNode ***nodeStack, int *nodeStackSize, struct TreeNode *ptr){
    *nodeStack = realloc(*nodeStack,sizeof(struct TreeNode*)*(++*nodeStackSize));
    (*nodeStack)[*nodeStackSize-1] = ptr;
}

inline struct TreeNode* __popStack(struct TreeNode ***nodeStack, int *nodeStackSize){
    struct TreeNode* temp=(*nodeStack)[*nodeStackSize-1];
    *nodeStack = realloc(*nodeStack,sizeof(struct TreeNode*)*(--*nodeStackSize));
    return temp;
}

inline int* _inorderTraversal_sol2(struct TreeNode* root, int* returnSize){
    struct TreeNode **nodeStack=NULL;
    struct TreeNode *ptr=root;
    int nodeStackSize=0;
    int *returnArray=NULL;
    
    *returnSize = 0;    
    
    do{
        // travel left node, push node into stack
        while( ptr!=NULL ){            
            __pushStack(&nodeStack, &nodeStackSize, ptr);
            
            ptr = ptr->left;
        }

        // end of left node, start pop node from stack
        if( nodeStackSize>0 ){            
            ptr = __popStack(&nodeStack, &nodeStackSize);
            
            returnArray = realloc(returnArray,sizeof(int)*(++*returnSize));
            returnArray[*returnSize-1] = ptr->val;
            ptr = ptr->right;
        }
    }while(nodeStackSize>0 || ptr!=NULL);

    return returnArray;
}
/********************************************************/

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    return _inorderTraversal_sol2(root, returnSize);
}
