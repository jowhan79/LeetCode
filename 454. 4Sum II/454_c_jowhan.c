// 2017/11/20 Jowhan

/********************** solution 1 **********************/
// 暴力法: time:O(n^4)
// 想半天想不到好的解法QQ
// ...慢到會TLE  崩╰(〒皿〒)╯潰

inline int _fourSumCount_sol1(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
    int i, j, k, m, count=0;
    
    for( i=0; i<ASize; ++i ){
        for( j=0; j<BSize; ++j ){
            for( k=0; k<CSize; ++k ){
                for( m=0; m<DSize; ++m ){
                    if( A[i]+B[j]+C[k]+D[m]==0 ) ++count;
                }
            }
        }
    }

    return count;
}

/********************************************************/

/********************** solution 2 **********************/
// 建hash table: time: O(n^2), space: O(n^2)
// 首先使用hash紀錄A+B的所有可能數值及其發生次數。
// 接下來計算C+D時，從表中尋找補數(-C+D)之次數，即為方法數。
// 將所有C+D計算完畢，所有方法數的總和即為所求。

// 註:此題除了用hash之外的方法都會TLE
// 就算用了hash還是有可能TLE
// 在傳hash table進function時，建議用指標傳，否則call by value
// 會耗費太多時間導致TLE (複製整個hash table很耗時因為table太大)

// 註2: hash function是類似mod運算，為了加速才設計成位元運算
// 根據研究，mod一個質數較能使結果均勻(忘記在哪學到的)。

#define HASH_BUCKET_BITS 18
#define HASH_BUCKET_SIZE (1<<HASH_BUCKET_BITS)
#define HASH_BUCKET_MASK (HASH_BUCKET_SIZE-1)

inline int map_hash_table(int value){ return value&HASH_BUCKET_MASK; }

typedef struct slot{
    int value;
    int count;
    struct slot* next;
} Slot;

typedef struct{
    Slot* bucket[HASH_BUCKET_SIZE];
} hash_table;

inline void increment_count(hash_table *ht, int value){
    Slot *ptr, *pre_ptr;
    int bucketID=map_hash_table(value);
    
    // find slot
    for( pre_ptr=ptr=ht->bucket[bucketID]; ptr!=NULL ; pre_ptr=ptr, ptr=ptr->next){
        if( ptr->value==value ){
            ++ptr->count;
            return;
        }
    }
    
    // not found, create new slot
    ptr = malloc(sizeof(Slot));
    ptr->value = value;
    ptr->count = 1;
    ptr->next = NULL;    
    
    // append
    if( pre_ptr==NULL ) ht->bucket[bucketID] = ptr;
    else pre_ptr->next = ptr;
}

inline int get_count(hash_table *ht, int value){
    Slot *ptr;
    int bucketID=map_hash_table(value);
    
    // find bucket
    for( ptr=ht->bucket[bucketID]; ptr!=NULL ; ptr=ptr->next){
        if( ptr->value==value ){
            return ptr->count;
        }
    }
    
    return 0;
}

inline void print_hash_table(hash_table ht){
    int i;
    Slot* ptr;
    
    for( i=0; i<HASH_BUCKET_SIZE; ++i ){
        for( ptr=ht.bucket[i]; ptr!=NULL; ptr=ptr->next ){
            if( ptr==ht.bucket[i] ) printf("[%d]",i);
            printf("->(%d,%d)",ptr->value,ptr->count);
        }
        if( ptr!=ht.bucket[i] ) printf("\n");
    }
}

inline int _fourSumCount_sol2(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
    int i, j, count=0;
    hash_table ABcount_table;
    
    memset(&ABcount_table,0,sizeof(hash_table));
    
    // record all A+B values count
    for( i=0; i<ASize; ++i ){
        for( j=0; j<BSize; ++j ){
            increment_count(&ABcount_table, A[i]+B[j]);            
        }
    }
    
    //print_hash_table(ABcount_table);
    
    // calculate C+D, find values in AB that -C+D==A+B
    for( i=0; i<CSize; ++i ){
        for( j=0; j<DSize; ++j ){
            count = count + get_count(&ABcount_table, -(C[i]+D[j]));
        }
    }
    
    return count;
}

/********************************************************/

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
    return _fourSumCount_sol2(A, ASize, B, BSize, C, CSize, D, DSize);
}
