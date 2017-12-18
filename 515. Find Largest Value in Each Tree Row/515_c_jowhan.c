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
// time: O(n), space: O(n)
// 想法: 使用BFS走訪tree，並另外記錄這些node的層數

# define MAX_QUEUE_SIZE 10000
# define MAX(X,Y) (((X)>(Y)) ? (X) : (Y))

int* _largestValues_sol1(struct TreeNode* root, int* returnSize) {    
    
    // initialize
    struct TreeNode *node_queue[MAX_QUEUE_SIZE];    
    int layer_queue[MAX_QUEUE_SIZE], queue_begin=0, queue_end=1, pre_layer=0, layer_begin=0;
    int max_val=INT_MIN, i;
    int *result;
    result = malloc(MAX_QUEUE_SIZE*sizeof(int));
    
    memset(node_queue,0,sizeof(node_queue));
    memset(layer_queue,0,sizeof(layer_queue));
    memset(result,0,sizeof(result));    
    
    node_queue[0] = root;
    layer_queue[0] = 0;
    pre_layer = 0;
    
    // travel tree    
    while( queue_begin!=queue_end ){  
        // reach new layer: insert max to result
        if( layer_queue[queue_begin]!=pre_layer ){
            result[(*returnSize)++] = max_val;
            max_val = INT_MIN;
            ++pre_layer;            
        }
        
        // compute max
        max_val = MAX(max_val,node_queue[queue_begin]->val);
        
        // insert node to queue
        if( node_queue[queue_begin]->left!=NULL ){
            node_queue[queue_end] = node_queue[queue_begin]->left;
            layer_queue[queue_end++] = layer_queue[queue_begin]+1;
        }
        if( node_queue[queue_begin]->right!=NULL ){
            node_queue[queue_end] = node_queue[queue_begin]->right;
            layer_queue[queue_end++] = layer_queue[queue_begin]+1;
        }        
        ++queue_begin;
    }
    
    // record last layer max
    result[(*returnSize)++] = max_val;
    
    return result;
}
/********************************************************/

int* largestValues(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if( root==NULL ) return NULL;
    return _largestValues_sol1(root, returnSize);
}
