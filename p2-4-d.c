#include<stdio.h>

int count = 0;

void merge(int arr[], int p, int m, int q) {
    int l[m-p+1];
    int r[q-m];

    for(int i = 0 ; i <= m-p ; i++){
        l[i] = arr[p+i];
    }

    for(int i = 0 ; i < q-m ; i++){
        r[i] = arr[m+1+i];
    }

    int ri = 0;
    int li = 0;
    int i = 0;

    while(ri<q-m&&li<m-p+1){
        if(l[li]<r[ri]){
            arr[p+i++] = l[li++];
        }else{
            arr[p+i++] = r[ri++];
            count++;
        }
    }

    while(ri<q-m){
        arr[p+i++] = r[ri++];
    }

    while(li<m-p+1){
        arr[p+i++] = l[li++];
        count++;
    }
}

void mergesort(int arr[], int p, int q) {
    if(p<q){
        int m = (p+q)/2;
        mergesort(arr,p,m);
        mergesort(arr,m+1,q);
        merge(arr,p,m,q);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {2,3,6,8,1};
    int n = 5;

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    mergesort(arr,0,n-1);

    putchar('\n');

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    printf("%d\n", count);

    return 0;
}
