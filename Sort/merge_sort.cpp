#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

const int N=1e5+10;
int n;
int q[N],f[N];


void merge_sort(int i,int j){
    if(i>=j) return;
    
    int mid=i+j>>1;
    
    merge_sort(i,mid),merge_sort(mid+1,j);
    int l=i,r=mid+1,k=0;
    while(l<=mid&&r<=j){
        if(q[l]<=q[r]) f[k++]=q[l++];
        else f[k++]=q[r++];
        
    }
    while(l<=mid) f[k++]=q[l++];
    while(r<=j) f[k++]=q[r++];
    
    for(l=i,r=0;l<=j;l++,r++) q[l]=f[r];
    
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    
    merge_sort(0,n-1);
    
    for(int i=0;i<n;i++) printf("%d ",q[i]);
    return 0;
    
}
