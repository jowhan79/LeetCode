/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/********************** solution 1 **********************/
// hash table: time: O(n^2), space: O(n)
// 紀錄陣列之所有數字到hash table。可避免掉O(n^3)複雜度。
// 排序原本陣列。此步確保最後結果不重複。
// 第一個數字: 第一層迴圈決定。
// 第二個數字: 第二層迴圈決定。
// 第三個數字: 查hash table中是否有-([1]+[2])。還要判斷此數字出現次數。
// ...最後TLE QQQQQQQQQ

#define HASH_BUCKET_BITS 18
#define HASH_BUCKET_SIZE (1<<HASH_BUCKET_BITS)
#define HASH_BUCKET_MASK (HASH_BUCKET_SIZE-1)

typedef struct slot{
    int value;
    int count;
    struct slot* next;
} Slot;

typedef struct{
    Slot* bucket[HASH_BUCKET_SIZE];
} Hash_Table;

inline int get_bucket_ID(int value){ return value&HASH_BUCKET_MASK; }

inline void increment_count(Hash_Table *ht, int value){
    int bucket_ID = get_bucket_ID(value);
    Slot *ptr, *pre_ptr, *temp;
    
    // find value and increment count
    for( pre_ptr=ptr=ht->bucket[bucket_ID]; ptr!=NULL; pre_ptr=ptr, ptr=ptr->next ){
        if( ptr->value==value ){
            ++ptr->count;
            return;
        }
    }
    
    // not found, create new slot
    temp = malloc(sizeof(Slot));
    temp->value = value;
    temp->count = 1;
    temp->next = NULL;
    
    // append
    if( ht->bucket[bucket_ID]==NULL ) ht->bucket[bucket_ID] = temp;
    else pre_ptr->next = temp;    
}

inline int get_count(Hash_Table *ht, int value){
    int bucket_ID = get_bucket_ID(value);
    Slot *ptr;
    
    // find value
    for( ptr=ht->bucket[bucket_ID]; ptr!=NULL; ptr=ptr->next ){
        if( ptr->value==value ){
            return ptr->count;
        }
    }
    
    // not found
    return 0;  
}

inline void print_hash_table(Hash_Table *ht){
    int i;
    Slot* ptr;
    
    for( i=0; i<HASH_BUCKET_SIZE; ++i ){
        for( ptr=ht->bucket[i]; ptr!=NULL; ptr=ptr->next ){
            if( ptr==ht->bucket[i] ) printf("[%d]",i);
            printf("->(%d,%d)",ptr->value,ptr->count);
        }
        if( ptr!=ht->bucket[i] ) printf("\n");
    }
}

inline bool is_repeated_sol(int** ans, int ansSize, int a, int b){
    int i;
    
    for( i=0; i<ansSize; ++i ){
        if( ans[i][0]==a && ans[i][1]==b ) return 1;
    }
    
    return 0;
}

int compare(const void* p1, const void* p2){
    return *((int*)p1)-*((int*)p2);
}

int** _threeSum_sol1(int* nums, int numsSize, int* returnSize) {
    Hash_Table nums_count;
    int i, j, sum, count;
    int **ptr=NULL;
    
    memset(&nums_count,0,sizeof(nums_count));
    *returnSize = 0;
    
    // record in hash table
    for( i=0; i<numsSize; ++i ){
        increment_count(&nums_count, nums[i]);
    }
    
    //print_hash_table(&nums_count);
    
    // sort
    qsort(nums,numsSize,sizeof(int), compare);

    // find 3rd number in hash table
    for( i=0; i<numsSize-2; ++i ){
        for( j=i+1; j<numsSize-1; ++j ){
            if(is_repeated_sol(ptr, *returnSize, nums[i], nums[j])) continue;
            sum = nums[i]+nums[j];
            if( -sum<nums[i] || -sum<nums[j] ) continue;            
            count = get_count(&nums_count,-sum);
            
            // check numbers are enough for 3rd number
            if( count==0 ) continue;
            else if( count==1 && (nums[i]==-sum || nums[j]==-sum) ) continue;
            else if( count==2 && (nums[i]==-sum && nums[j]==-sum) ) continue;
            
            // append new solution set
            ptr = realloc(ptr,sizeof(int*)*(++*returnSize));
            ptr[*returnSize-1] = malloc(sizeof(int)*3);
            ptr[*returnSize-1][0] = nums[i];
            ptr[*returnSize-1][1] = nums[j];
            ptr[*returnSize-1][2] = -sum;
        }
    }
    
    /*printf("total %d solutions:\n",*returnSize);
    for( i=0; i<*returnSize; ++i ){
        for( j=0; j<3; ++j ){
            printf("%d ",ptr[i][j]);
        }
        printf("\n");
    }*/
    
    return ptr;
}
/********************************************************/


/********************** solution 2 **********************/
// time: O(n^2), space: O(1)
// 首先sort array。第一層迴圈抓第一個數(不重複)，
// 二從此數後一位開始，三從尾開始，二往後三往前掃。
// 然後C有內建quick sort耶!!!

inline int** _threeSum_sol2(int* nums, int numsSize, int* returnSize) {
    int i, j, k;
    int **ans=NULL;
    *returnSize = 0;
    
    // sort
    qsort(nums,numsSize,sizeof(int), compare);
    
    // scan
    for( i=0; i<numsSize; ++i ){       
        
        // skip same number
        if( i>0 && nums[i]==nums[i-1] ) continue; 
        
        // start scan
        for( j=i+1, k=numsSize-1; j<k; ){
            if( nums[i]+nums[j]+nums[k]==0 ){
                ans = realloc(ans,sizeof(int*)*(++*returnSize));
                ans[*returnSize-1] = malloc(sizeof(int)*3);
                ans[*returnSize-1][0] = nums[i];
                ans[*returnSize-1][1] = nums[j];
                ans[*returnSize-1][2] = nums[k];
                // skip same nums[j] and nums[k]
                for( ; j<k && nums[j]==nums[j+1]; ++j);
                for( ; j<k && nums[k]==nums[k-1]; --k);
                ++j; --k;
            }
            else if( nums[i]+nums[j]+nums[k]>0 ) --k;
            else ++j;
        }
    }
    return ans;
}
/********************************************************/

int** threeSum(int* nums, int numsSize, int* returnSize) {
    return _threeSum_sol2(nums, numsSize, returnSize);
}
