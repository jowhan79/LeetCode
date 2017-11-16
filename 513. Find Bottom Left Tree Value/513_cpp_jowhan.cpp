// 2017/11/16 Jowhan

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        return _findBottomLeftValue_solution1(root);
    }
    
private:
    inline int _findBottomLeftValue_solution1(TreeNode* root) {
        queue<TreeNode*> treeNodePtr_queue;
        TreeNode* ptr;
        
        treeNodePtr_queue.push(root);
        
        for( ; !treeNodePtr_queue.empty() ; treeNodePtr_queue.pop() ){
            ptr = treeNodePtr_queue.front();
            if( ptr->right!=NULL ){
                treeNodePtr_queue.push(ptr->right);
            }
            if( ptr->left!=NULL ){
                treeNodePtr_queue.push(ptr->left);
            }
        }
        
        return ptr->val;
    }
};
