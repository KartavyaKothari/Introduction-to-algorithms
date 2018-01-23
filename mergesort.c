#include<stdio.h>

void merge(int arr[], int p, int m, int q) {
    int l[m-p+1];
    int r[q-m+1];

    for(int i = 0 ; i <= m-p ; i++){
        l[i] = arr[p+i];
    }

    for(int i = 0 ; i <= m-p ; i++){
        r[i] = arr[m+1+i];
    }

    int ri = 0;
    int li = 0;
    int i = 0;

    while(ri<q-m+1&&li<m-p+1){
        if(l[li]<r[ri]){
            arr[i++] = l[li++];
        }else arr[i++] = r[ri++];
    }

    while(ri<q-m+1){
        arr[i++] = r[ri++];
    }

    while(li<m-p+1){
        arr[i++] = l[li++];
    }
}

void mergesort(int arr[], int p, int q) {
    if(q-p>1){
        int m = (p+q)/2;
        mergesort(arr,p,m);
        mergesort(arr,m+1,q);
        merge(arr,p,m,q);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {710,841,491,833,740,491,502,251,864,377,719,682,245,425,851,961,69,990,290,265};

    for(int i = 0 ; i < 20 ; i++)
        printf("%d ", arr[i]);

    mergesort(arr,0,19);

    putchar('\n');

    for(int i = 0 ; i < 20 ; i++)
        printf("%d ", arr[i]);

    return 0;
}
