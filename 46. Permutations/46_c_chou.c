//2017/11/28 Peony

int count, *visited, *tmpList;

inline int nfactorial(int n){
    int i, ans;
    for(i=1, ans=1; i<=n; i++){
        ans *= i;
    }return ans;
}

void dfs(int **ans, int *nums, int numsSize, int visitID, int visitN){
    
    int i;
    if(numsSize==visitN){
        for(i=0; i<numsSize; i++){
            ans[count][i]=tmpList[i];
        }
        ++count;
        return;
    }
    for(i=0; i<numsSize; i++){
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
    int *visited, *tmpList;
    // Initialization
    count = 0;
    pairSize = nfactorial(numsSize);
    ans = (int**)malloc(pairSize*sizeof(int*));
    for(i=0; i<pairSize; i++){
        ans[i] = (int*)malloc(numsSize*sizeof(int));
    }
    visited = (int*)malloc(numsSize*sizeof(int*));
    memset(visited, 0, sizeof(visited));
    tmpList = (int*)malloc(numsSize*sizeof(int*));
    // Set value
    dfs(ans, nums, numsSize, 0, 0);
    *returnSize = pairSize;
    return ans;
}
