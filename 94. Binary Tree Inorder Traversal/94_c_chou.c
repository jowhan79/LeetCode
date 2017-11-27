//2017/11/27 Peony
int* inorder(struct TreeNode* node, int* returnSize){
    
    int *left, *right, leftNum=0, rightNum=0, *ans, i;

    if(node->left==NULL && node->right==NULL){
        ans = (int*)malloc(2*sizeof(int));
        ans[0] = node->val;
        *returnSize = 1;
        return ans;
    }
    if(node->left!=NULL){
        left = inorder(node->left, &leftNum);
    }
    if(node->right!=NULL){
        right = inorder(node->right, &rightNum);
    }
    ans = (int*)malloc((leftNum+rightNum+1)*sizeof(int));
    for(i=0; i<leftNum; i++)
        ans[i]=left[i];
    ans[leftNum]=node->val;
    for(i=0; i<rightNum; i++)
        ans[i+leftNum+1]=right[i];
    *returnSize = leftNum+rightNum+1;
    return ans;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    if(root!=NULL){return inorder(root, returnSize);}
    else{
        *returnSize = 0;
        return NULL;
    }
}
