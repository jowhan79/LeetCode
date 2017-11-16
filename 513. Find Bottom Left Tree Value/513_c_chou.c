// 2017/11/16 Peony
int searchTree(struct TreeNode* node, int *maxV){
    
    int left=0, right=0, lval=0, rval=0;
    
    if( node->left == NULL && node->right == NULL){
        *maxV = node->val;
        return 1;
    }else{
        if(node->left != NULL) left = searchTree(node->left, &lval);
        if(node->right != NULL) right = searchTree(node->right, &rval);
        *maxV = left>=right? lval: rval;
        return left>=right? left+1: right+1;
    } 
    
}

int findBottomLeftValue(struct TreeNode* root) {
    int maxVal=-1, level;
    level = searchTree(root, &maxVal);
    return maxVal;
}
