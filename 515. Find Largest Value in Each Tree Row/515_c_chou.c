// 2017/12/11 Peony
int* _largestValues(struct TreeNode* root, int* returnSize){

    int *largV, tail=0, cur, levelTab[100000], maxLevel;
    struct TreeNode *heap[100000];
    memset(levelTab, -1, sizeof(levelTab));
    
    if(root!=NULL){
        heap[tail] = root;
        levelTab[tail++] = 0;
        largV = (int*)malloc(1*sizeof(int));
        largV[0] = root->val;
    }else{
        return largV = (int*)malloc(0*sizeof(int));
    }
    
    for(cur=0, maxLevel=0; cur<tail; cur++){
        //printf("Current: at %d on level %d\n", heap[cur]->val, levelTab[cur]);
        if(levelTab[cur]>maxLevel){
            largV = (int*)realloc(largV, (levelTab[cur]+1)*sizeof(int));
            maxLevel = levelTab[cur];
            largV[levelTab[cur]] = heap[cur] -> val;
        }else{ // update value
            largV[levelTab[cur]] = largV[levelTab[cur]] < heap[cur]->val ? heap[cur]->val : largV[levelTab[cur]]; 
        }
        // not leaf
        if(heap[cur]->left!=NULL){
            heap[tail] = heap[cur]->left;
            levelTab[tail++] = levelTab[cur]+1;
        }
        if(heap[cur]->right!=NULL){
            heap[tail] = heap[cur]->right;
            levelTab[tail++] = levelTab[cur]+1;
        }        
    }
    *returnSize = maxLevel+1;
    return largV;
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    return _largestValues(root, returnSize);
}
