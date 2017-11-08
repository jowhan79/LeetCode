// Peony
void merge(int* nums1, int m, int* nums2, int n) {
    
    int list[m+n];
    int cur, i1, i2;
    
    for(i1=0, i2=0, cur=0; i1<m&&i2<n ; ++cur){
        if(nums1[i1]>=nums2[i2]) list[cur]=nums2[i2++];
        else list[cur]=nums1[i1++];
    }
    while(i1<m) list[cur++]=nums1[i1++];
    while(i2<n) list[cur++]=nums2[i2++];
    
    for(cur=0; cur<m+n; ++cur) nums1[cur]=list[cur];
    //for(cur=0; cur<m+n; ++cur) printf("%d ", list[cur]); printf("\n");
}
