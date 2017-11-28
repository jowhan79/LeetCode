//2017/11/28 Peony

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int count, *visited, *tmpList;

inline int nfactorial(int n){
    int i, ans;
    for(i=1, ans=1; i<=n; i++){
        ans *= i;
    }return ans;
}

void dfs(int **ans, int *nums, int numsSize, int visitID, int visitN){
    //printf("(nums[%d], %d)->N=%d, C=%d\n", visitID, nums[visitID], visitN, count);
    int i;
    if(numsSize==visitN){
        for(i=0; i<numsSize; i++){
            ans[count][i]=tmpList[i];
        }
        ++count;
        return;
    }
    for(i=0; i<numsSize; i++){
        //printf("check %d, %d\n", nums[i], visited[i]);
        if(visited[i]==0){
            tmpList[visitN] = nums[i];
            visited[i]=1;
            dfs(ans, nums, numsSize, i, visitN+1);
            visited[i]=0;
        }
    }
    
}

int** permute(int* nums, int numsSize, int* returnSize) {

    int **ans, pairSize, i, j;
    //int *visited, *tmpList;
    // Initialization
    count = 0;
    pairSize = nfactorial(numsSize);
    ans = (int**)malloc(pairSize*sizeof(int*));
    for(i=0; i<pairSize; i++){
        ans[i] = (int*)malloc(numsSize*sizeof(int));
    }
    visited = (int*)malloc(numsSize*sizeof(int));
    memset(visited, 0, numsSize*sizeof(int));
    tmpList = (int*)malloc(numsSize*sizeof(int));
    memset(tmpList, 0, numsSize*sizeof(int));
    // Set value
    dfs(ans, nums, numsSize, 0, 0);
    free(visited);
    free(tmpList);
    visited = NULL;
    tmpList = NULL;
    *returnSize = pairSize;
    return ans;
}
