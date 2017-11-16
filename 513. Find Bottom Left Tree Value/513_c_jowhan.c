// 2017/11/16 Jowhan

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/********************** solution 1 **********************/
// BFS approach: time: O(n), space: O(n)
// 想法: 利用queue實現BFS，由右至左拜訪，回傳最後一個拜訪的值即可。

#define QUEUE_MAX_SIZE 15000

inline int _findBottomLeftValue_solution1(struct TreeNode* root) {
    struct TreeNode *queue[QUEUE_MAX_SIZE], *ptr_right=NULL, *ptr_left=NULL;
    int tail=0, result=root->val, i;
    
    // init queue
    memset(queue,0,sizeof(int*)*QUEUE_MAX_SIZE);
    queue[tail++] = root;
    
    // scan BST and enqueue
    for( i=0 ; queue[i]!=NULL ; ++i){
        //printf("Now at queue[%d]: %d\n",i,queue[i]->val);
        ptr_right = queue[i]->right;
        if( ptr_right!=NULL ){
            queue[tail++] = ptr_right;
            result = ptr_right->val;
            //printf("record right child %d at queue[%d]\n",queue[i]->right->val,i);
        }
        ptr_left = queue[i]->left;
        if( ptr_left!=NULL ){
            queue[tail++] = ptr_left;
            result = ptr_left->val;
            //printf("record left child %d at queue[%d]\n",queue[i]->left->val,i);
        }
    }
    
    return result;    
}
/********************************************************/

int findBottomLeftValue(struct TreeNode* root) {
    return _findBottomLeftValue_solution1(root);
}
